# 1002d4fa `Unwind@1002d4fa`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d4fa |
| `name` | Unwind@1002d4fa |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d4fa(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d4fa |

## Decompiled C

```c

void Unwind_1002d4fa(void)

{
  FUN_10001660();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d503` | `10001660` | `UNCONDITIONAL_CALL` | FUN_10001660 | `10001660` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d4fa` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `1002d4fd` | `81 c1 a8 10 00 00` | `ADD ECX,0x10a8` |
| `1002d503` | `e9 58 41 fd ff` | `JMP 0x10001660` |
