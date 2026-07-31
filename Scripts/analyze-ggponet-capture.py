#!/usr/bin/env python3
import argparse
import json
import os
import socket
import struct
from collections import Counter, defaultdict


def u32be(data, offset=0):
    return struct.unpack_from(">I", data, offset)[0]


def i32be(data, offset=0):
    return struct.unpack_from(">i", data, offset)[0]


def i32le(data, offset=0):
    return struct.unpack_from("<i", data, offset)[0]


def u16le(data, offset=0):
    return struct.unpack_from("<H", data, offset)[0]


def ip_text(value):
    return socket.inet_ntoa(struct.pack("!I", value))


def read_pcapng(path):
    data = open(path, "rb").read()
    offset = 0
    endian = "<"
    links = {}
    packets = []
    while offset + 12 <= len(data):
        block_type_le = struct.unpack_from("<I", data, offset)[0]
        block_type_be = struct.unpack_from(">I", data, offset)[0]
        block_type = block_type_le if endian == "<" else block_type_be
        if block_type_le == 0x0A0D0D0A or block_type_be == 0x0A0D0D0A:
            magic = data[offset + 8:offset + 12]
            if magic == b"\x4d\x3c\x2b\x1a":
                endian = "<"
            elif magic == b"\x1a\x2b\x3c\x4d":
                endian = ">"
            block_type = 0x0A0D0D0A
        total_len = struct.unpack_from(endian + "I", data, offset + 4)[0]
        if total_len < 12 or offset + total_len > len(data):
            break
        body = data[offset + 8:offset + total_len - 4]
        if block_type == 1 and len(body) >= 8:
            linktype = struct.unpack_from(endian + "H", body, 0)[0]
            links[len(links)] = linktype
        elif block_type == 6 and len(body) >= 20:
            iface, tsh, tsl, caplen = struct.unpack_from(endian + "IIII", body, 0)
            if len(body) >= 20 + caplen:
                packets.append({
                    "ts": (tsh << 32) + tsl,
                    "linktype": links.get(iface, 1),
                    "data": body[20:20 + caplen],
                })
        elif block_type == 3 and len(body) >= 4:
            caplen = struct.unpack_from(endian + "I", body, 0)[0]
            if len(body) >= 4 + caplen:
                packets.append({"ts": 0, "linktype": 1, "data": body[4:4 + caplen]})
        offset += total_len
    return packets


def ipv4_payload(linktype, frame):
    if linktype == 1:
        if len(frame) < 14:
            return None
        eth_type = struct.unpack_from("!H", frame, 12)[0]
        pos = 14
        while eth_type in (0x8100, 0x88A8) and len(frame) >= pos + 4:
            eth_type = struct.unpack_from("!H", frame, pos + 2)[0]
            pos += 4
        if eth_type != 0x0800:
            return None
        packet = frame[pos:]
    elif linktype == 101:
        packet = frame
    elif linktype == 127:
        if len(frame) < 4:
            return None
        packet = frame[4:]
    else:
        return None
    if len(packet) < 20 or packet[0] >> 4 != 4:
        return None
    ihl = (packet[0] & 0x0F) * 4
    total = struct.unpack_from("!H", packet, 2)[0]
    if ihl < 20 or len(packet) < ihl:
        return None
    total = min(total, len(packet)) if total > 0 else len(packet)
    proto = packet[9]
    src = socket.inet_ntoa(packet[12:16])
    dst = socket.inet_ntoa(packet[16:20])
    return proto, src, dst, packet[ihl:total]


def transport_records(packets):
    tcp = []
    udp = []
    for index, packet in enumerate(packets):
        parsed = ipv4_payload(packet["linktype"], packet["data"])
        if not parsed:
            continue
        proto, src, dst, payload = parsed
        if proto == 6 and len(payload) >= 20:
            src_port, dst_port, seq = struct.unpack_from("!HHI", payload, 0)
            header_len = (payload[12] >> 4) * 4
            if header_len >= 20 and len(payload) >= header_len:
                app = payload[header_len:]
                if app:
                    tcp.append({"ts": packet["ts"], "index": index, "src": src, "dst": dst, "sport": src_port, "dport": dst_port, "seq": seq, "data": app})
        elif proto == 17 and len(payload) >= 8:
            src_port, dst_port, length = struct.unpack_from("!HHH", payload, 0)
            app = payload[8:min(len(payload), length)]
            if app:
                udp.append({"ts": packet["ts"], "index": index, "src": src, "dst": dst, "sport": src_port, "dport": dst_port, "data": app})
    return tcp, udp


def append_stream(streams, packet, server_ip):
    if server_ip and packet["src"] == server_ip:
        role = "server"
    elif server_ip and packet["dst"] == server_ip:
        role = "client"
    elif packet["sport"] in (7000, 7001, 7002):
        role = "server"
    elif packet["dport"] in (7000, 7001, 7002):
        role = "client"
    else:
        role = "unknown"
    peer = tuple(sorted(((packet["src"], packet["sport"]), (packet["dst"], packet["dport"]))))
    streams[(peer, role)].append((packet["seq"], packet["data"]))


def assemble(chunks):
    out = bytearray()
    end = None
    for seq, data in sorted(chunks, key=lambda item: item[0]):
        if end is None:
            out.extend(data)
            end = seq + len(data)
            continue
        if seq < end:
            overlap = end - seq
            if overlap < len(data):
                out.extend(data[overlap:])
                end += len(data) - overlap
        elif seq == end:
            out.extend(data)
            end += len(data)
        else:
            # Keep capture analysis bounded if packets are missing or a flow is not fully reassembled.
            out.extend(data)
            end = seq + len(data)
    return bytes(out)


def read_string(data, offset):
    if offset + 4 > len(data):
        return None, offset
    size = u32be(data, offset)
    offset += 4
    if size > 4096 or offset + size > len(data):
        return None, offset
    return data[offset:offset + size].decode("utf-8", "replace"), offset + size


def parse_client_payload(command, payload):
    result = {}
    quark, offset = read_string(payload, 0)
    if quark:
        result["quark"] = quark
    if command == 15 and quark:
        text, _ = read_string(payload, offset)
        if text is not None:
            result["text"] = text
    elif command == 17 and quark and offset + 8 <= len(payload):
        count = u32be(payload, offset)
        size = u32be(payload, offset + 4)
        result.update({"frameCount": count, "inputSize": size, "inputBytes": len(payload) - offset - 8})
    elif command in (11, 12, 20) and quark:
        if command == 11 and offset + 4 <= len(payload):
            result["localPort"] = u32be(payload, offset)
    return result


def scan_tcp_stream(data, role):
    records = []
    offset = 0
    while offset + 8 <= len(data):
        length = u32be(data, offset)
        if length < 4 or length > 2_000_000 or offset + 4 + length > len(data):
            offset += 1
            continue
        if role == "client" and length >= 8:
            seq = u32be(data, offset + 4)
            command = u32be(data, offset + 8)
            payload = data[offset + 12:offset + 4 + length]
            record = {"role": role, "sequence": seq, "command": command, "payloadBytes": len(payload)}
            record.update(parse_client_payload(command, payload))
        else:
            code = i32be(data, offset + 4)
            record = {"role": role, "code": code, "payloadBytes": length - 4}
            if code in (14, -13) and length >= 12:
                payload = data[offset + 8:offset + 4 + length]
                record["frameSize"] = u32be(payload, 0)
                record["frameCount"] = u32be(payload, 4)
        records.append(record)
        offset += 4 + length
    return records


def summarize_udp(udp, server_ip, peer_ip):
    summary = {"packets": len(udp), "types": Counter(), "type3": [], "ascii": []}
    for packet in udp:
        data = packet["data"]
        direction = "other"
        if server_ip and (packet["src"] == server_ip or packet["dst"] == server_ip):
            direction = "server"
        elif not server_ip and (packet["sport"] in (7000, 7001, 7002) or packet["dport"] in (7000, 7001, 7002)):
            direction = "server"
        elif peer_ip and packet["src"] == peer_ip:
            direction = "fromPeer"
        elif peer_ip and packet["dst"] == peer_ip:
            direction = "toPeer"
        if data[:1] in (b"1", b"0") or b"useports" in data:
            text = data[:200].decode("utf-8", "replace")
            if "useports" in text or text.startswith("ok") or "/7001" in text or text.startswith("0."):
                summary["ascii"].append({"direction": direction, "src": packet["src"], "sport": packet["sport"], "dst": packet["dst"], "dport": packet["dport"], "text": text})
        if data[0] in (1, 2, 3, 4, 5):
            summary["types"][str(data[0])] += 1
            if data[0] == 3 and len(data) >= 12:
                summary["type3"].append({
                    "direction": direction,
                    "src": packet["src"], "sport": packet["sport"],
                    "dst": packet["dst"], "dport": packet["dport"],
                    "startFrame": i32le(data, 1),
                    "ackFrame": i32le(data, 5),
                    "bitCount": u16le(data, 9),
                    "inputSize": data[11],
                    "payloadBytes": len(data),
                })
    summary["types"] = dict(summary["types"])
    return summary


def write_outputs(out_dir, summary):
    os.makedirs(out_dir, exist_ok=True)
    with open(os.path.join(out_dir, "summary.json"), "w") as handle:
        json.dump(summary, handle, indent=2, sort_keys=True)
    lines = ["# GGPO Capture Summary", "", f"Packets: {summary['packets']}", f"TCP payload packets: {summary['tcpPayloadPackets']}", f"UDP payload packets: {summary['udp']['packets']}", ""]
    lines.append(f"UDP types: {summary['udp']['types']}")
    useports = [item for item in summary["udp"]["ascii"] if "useports" in item["text"]]
    lines.append(f"useports records: {len(useports)}")
    lines.append("")
    lines.append("## TCP Client Commands")
    for record in summary["tcpRecords"]:
        if record.get("role") == "client":
            extra = ""
            if record.get("command") == 17:
                extra = f" frameCount={record.get('frameCount')} inputSize={record.get('inputSize')}"
            elif record.get("command") == 15:
                extra = f" text={record.get('text', '')}"
            lines.append(f"- seq={record.get('sequence')} command={record.get('command')} payload={record.get('payloadBytes')}{extra}")
    lines.append("")
    lines.append("## UDP Type 3 Sizes")
    counts = Counter((item["direction"], item["inputSize"]) for item in summary["udp"]["type3"])
    for (direction, size), count in sorted(counts.items()):
        lines.append(f"- {direction} inputSize={size}: {count}")
    with open(os.path.join(out_dir, "summary.md"), "w") as handle:
        handle.write("\n".join(lines) + "\n")


def main():
    parser = argparse.ArgumentParser(description="Analyze Fightcade GGPO pcapng captures.")
    parser.add_argument("capture")
    parser.add_argument("--server-ip", default="")
    parser.add_argument("--peer-ip", default="")
    parser.add_argument("--out-dir", default="capture-summary")
    args = parser.parse_args()
    packets = read_pcapng(args.capture)
    tcp, udp = transport_records(packets)
    streams = defaultdict(list)
    for packet in tcp:
        append_stream(streams, packet, args.server_ip)
    tcp_records = []
    for (_, role), chunks in streams.items():
        tcp_records.extend(scan_tcp_stream(assemble(chunks), role))
    summary = {
        "capture": args.capture,
        "packets": len(packets),
        "tcpPayloadPackets": len(tcp),
        "tcpRecords": tcp_records,
        "udp": summarize_udp(udp, args.server_ip, args.peer_ip),
    }
    write_outputs(args.out_dir, summary)
    print(os.path.join(args.out_dir, "summary.md"))


if __name__ == "__main__":
    main()
