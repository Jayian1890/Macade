# 0077864e `GGPONET.DLL::ggpo_synchronize_input`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077864e |
| `name` | GGPONET.DLL::ggpo_synchronize_input |
| `namespace` | GGPONET.DLL |
| `signature` | undefined ggpo_synchronize_input(void) |
| `size_bytes` | 6 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void ggpo_synchronize_input(void)

{
                    /* WARNING: Could not recover jumptable at 0x0077864e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ggpo_synchronize_input();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `00472529` | FUN_004722f0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077864e` | `ff 25 80 94 79 00` | `JMP dword ptr [0x00799480]` |
