import Compression
import Foundation

struct FightcadeZipArchive {
    let data: Data

    func jsonFiles() throws -> [(name: String, data: Data)] {
        try files(matching: { $0.lowercased().hasSuffix(".json") })
    }

    func fileData(named fileName: String) throws -> Data {
        let matches = try files { name in
            name == fileName || name.caseInsensitiveCompare(fileName) == .orderedSame
        }

        guard let match = matches.first else {
            throw FightcadeROMDownloadError.archiveEntryMissing(fileName)
        }

        return match.data
    }

    private func files(matching shouldRead: (String) -> Bool) throws -> [(name: String, data: Data)] {
        let centralDirectory = try centralDirectoryRange()
        var offset = centralDirectory.offset
        var files: [(String, Data)] = []

        while offset < centralDirectory.offset + centralDirectory.size {
            guard uint32(at: offset) == 0x02014b50 else { break }

            let method = uint16(at: offset + 10)
            let compressedSize = Int(uint32(at: offset + 20))
            let uncompressedSize = Int(uint32(at: offset + 24))
            let nameLength = Int(uint16(at: offset + 28))
            let extraLength = Int(uint16(at: offset + 30))
            let commentLength = Int(uint16(at: offset + 32))
            let localHeaderOffset = Int(uint32(at: offset + 42))
            let nameStart = offset + 46
            let name = String(data: data[nameStart..<(nameStart + nameLength)], encoding: .utf8) ?? ""

            if shouldRead(name) {
                let extracted = try fileData(
                    localHeaderOffset: localHeaderOffset,
                    method: method,
                    compressedSize: compressedSize,
                    uncompressedSize: uncompressedSize
                )
                files.append((name, extracted))
            }

            offset += 46 + nameLength + extraLength + commentLength
        }

        return files
    }

    private func centralDirectoryRange() throws -> (offset: Int, size: Int) {
        let minimumOffset = max(0, data.count - 66_000)
        for offset in stride(from: data.count - 22, through: minimumOffset, by: -1) where uint32(at: offset) == 0x06054b50 {
            return (Int(uint32(at: offset + 16)), Int(uint32(at: offset + 12)))
        }

        throw FightcadeROMDownloadError.indexUnavailable
    }

    private func fileData(
        localHeaderOffset: Int,
        method: UInt16,
        compressedSize: Int,
        uncompressedSize: Int
    ) throws -> Data {
        guard uint32(at: localHeaderOffset) == 0x04034b50 else {
            throw FightcadeROMDownloadError.indexUnavailable
        }

        let nameLength = Int(uint16(at: localHeaderOffset + 26))
        let extraLength = Int(uint16(at: localHeaderOffset + 28))
        let start = localHeaderOffset + 30 + nameLength + extraLength
        let compressed = data[start..<(start + compressedSize)]

        if method == 0 {
            return Data(compressed)
        }

        guard method == 8 else {
            throw FightcadeROMDownloadError.indexUnavailable
        }

        var destination = [UInt8](repeating: 0, count: uncompressedSize)
        let decoded = compressed.withUnsafeBytes { source in
            compression_decode_buffer(
                &destination,
                uncompressedSize,
                source.bindMemory(to: UInt8.self).baseAddress!,
                compressedSize,
                nil,
                COMPRESSION_ZLIB
            )
        }

        guard decoded == uncompressedSize else {
            throw FightcadeROMDownloadError.indexUnavailable
        }

        return Data(destination)
    }

    private func uint16(at offset: Int) -> UInt16 {
        UInt16(data[offset]) | (UInt16(data[offset + 1]) << 8)
    }

    private func uint32(at offset: Int) -> UInt32 {
        UInt32(uint16(at: offset)) | (UInt32(uint16(at: offset + 2)) << 16)
    }
}
