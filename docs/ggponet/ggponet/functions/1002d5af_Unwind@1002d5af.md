# 1002d5af `Unwind@1002d5af`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d5af |
| `name` | Unwind@1002d5af |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d5af(void) |
| `size_bytes` | 11 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d5af |

## Decompiled C

```c

void Unwind_1002d5af(void)

{
  FUN_10026a50();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d5b5` | `10026a50` | `UNCONDITIONAL_CALL` | FUN_10026a50 | `10026a50` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d5af` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002d5b2` | `83 c1 04` | `ADD ECX,0x4` |
| `1002d5b5` | `e9 96 94 ff ff` | `JMP 0x10026a50` |
