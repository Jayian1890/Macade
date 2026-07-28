# 1001abfc `FUN_1001abfc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001abfc |
| `name` | FUN_1001abfc |
| `namespace` | Global |
| `signature` | undefined FUN_1001abfc(void) |
| `size_bytes` | 9 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void FUN_1001abfc(void)

{
  FUN_10016129(4);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001abfe` | `10016129` | `UNCONDITIONAL_CALL` | FUN_10016129 | `10016129` |

## Callers

| From | Function |
| --- | --- |
| `1001ab98` | __calloc_impl |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001abfc` | `6a 04` | `PUSH 0x4` |
| `1001abfe` | `e8 26 b5 ff ff` | `CALL 0x10016129` |
| `1001ac03` | `59` | `POP ECX` |
| `1001ac04` | `c3` | `RET` |
