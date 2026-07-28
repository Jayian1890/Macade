# 1002d6af `Unwind@1002d6af`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d6af |
| `name` | Unwind@1002d6af |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d6af(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d6af |

## Decompiled C

```c

void Unwind_1002d6af(void)

{
  FUN_10002900();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d6b8` | `10002900` | `UNCONDITIONAL_CALL` | FUN_10002900 | `10002900` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d6af` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1002d6b2` | `81 c1 1c 01 00 00` | `ADD ECX,0x11c` |
| `1002d6b8` | `e9 43 52 fd ff` | `JMP 0x10002900` |
