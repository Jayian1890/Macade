# 1002d6bd `Unwind@1002d6bd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d6bd |
| `name` | Unwind@1002d6bd |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d6bd(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d6bd |

## Decompiled C

```c

void Unwind_1002d6bd(void)

{
  FUN_10002d80();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d6c6` | `10002d80` | `UNCONDITIONAL_CALL` | FUN_10002d80 | `10002d80` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d6bd` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1002d6c0` | `81 c1 70 0b 00 00` | `ADD ECX,0xb70` |
| `1002d6c6` | `e9 b5 56 fd ff` | `JMP 0x10002d80` |
