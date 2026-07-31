# 1002d6ff `Unwind@1002d6ff`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d6ff |
| `name` | Unwind@1002d6ff |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d6ff(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d6ff |

## Decompiled C

```c

void Unwind_1002d6ff(void)

{
  FUN_10002940();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d708` | `10002940` | `UNCONDITIONAL_CALL` | FUN_10002940 | `10002940` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d6ff` | `8b 4d cc` | `MOV ECX,dword ptr [EBP + -0x34]` |
| `1002d702` | `81 c1 e8 05 00 00` | `ADD ECX,0x5e8` |
| `1002d708` | `e9 33 52 fd ff` | `JMP 0x10002940` |
