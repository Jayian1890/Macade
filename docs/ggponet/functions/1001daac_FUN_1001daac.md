# 1001daac `FUN_1001daac`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001daac |
| `name` | FUN_1001daac |
| `namespace` | Global |
| `signature` | undefined FUN_1001daac(void) |
| `size_bytes` | 3 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void FUN_1001daac(void)

{
  code *in_EAX;
  
  (*in_EAX)();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10018383` | __local_unwind4 |
| `1001da48` | __local_unwind2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001daac` | `ff d0` | `CALL EAX` |
| `1001daae` | `c3` | `RET` |
