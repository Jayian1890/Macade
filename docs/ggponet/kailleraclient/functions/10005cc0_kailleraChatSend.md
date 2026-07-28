# 10005cc0 `kailleraChatSend`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005cc0 |
| `name` | kailleraChatSend |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraChatSend(char * param_1) |
| `size_bytes` | 14 |
| `stack_frame_size` | 8 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_1, _kailleraChatSend@4, kailleraChatSend |

## Decompiled C

```c

/* __stdcall kailleraChatSend,4 */

void kailleraChatSend(char *param_1)

{
                    /* 0x5cc0  1  _kailleraChatSend@4 */
  FUN_10008e90(param_1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10005cc5` | `10008e90` | `UNCONDITIONAL_CALL` | FUN_10008e90 | `10008e90` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005cc0` | `8b 44 24 04` | `MOV EAX,dword ptr [ESP + 0x4]` |
| `10005cc4` | `50` | `PUSH EAX` |
| `10005cc5` | `e8 c6 31 00 00` | `CALL 0x10008e90` |
| `10005cca` | `59` | `POP ECX` |
| `10005ccb` | `c2 04 00` | `RET 0x4` |
