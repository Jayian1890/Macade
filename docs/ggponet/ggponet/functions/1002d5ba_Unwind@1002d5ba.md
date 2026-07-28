# 1002d5ba `Unwind@1002d5ba`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d5ba |
| `name` | Unwind@1002d5ba |
| `namespace` | Global |
| `signature` | undefined Unwind@1002d5ba(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | Unwind@1002d5ba |

## Decompiled C

```c

void Unwind_1002d5ba(void)

{
  FUN_10002980();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d5c3` | `10002980` | `UNCONDITIONAL_CALL` | FUN_10002980 | `10002980` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d5ba` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002d5bd` | `81 c1 a8 00 00 00` | `ADD ECX,0xa8` |
| `1002d5c3` | `e9 b8 53 fd ff` | `JMP 0x10002980` |
