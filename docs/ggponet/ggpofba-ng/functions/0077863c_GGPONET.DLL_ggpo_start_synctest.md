# 0077863c `GGPONET.DLL::ggpo_start_synctest`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077863c |
| `name` | GGPONET.DLL::ggpo_start_synctest |
| `namespace` | GGPONET.DLL |
| `signature` | undefined ggpo_start_synctest(void) |
| `size_bytes` | 6 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void ggpo_start_synctest(void)

{
                    /* WARNING: Could not recover jumptable at 0x0077863c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ggpo_start_synctest();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `0062ddfd` | FUN_0062dc50 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077863c` | `ff 25 8c 94 79 00` | `JMP dword ptr [0x0079948c]` |
