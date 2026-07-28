# 1002d4ef `Unwind@1002d4ef`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d4ef |
| `name` | Unwind@1002d4ef |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d4ef(void) |
| `size_bytes` | 11 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d4ef |

## Decompiled C

```c

void Unwind_1002d4ef(void)

{
  FUN_10024a30();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d4f5` | `10024a30` | `UNCONDITIONAL_CALL` | FUN_10024a30 | `10024a30` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d4ef` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `1002d4f2` | `83 c1 08` | `ADD ECX,0x8` |
| `1002d4f5` | `e9 36 75 ff ff` | `JMP 0x10024a30` |
