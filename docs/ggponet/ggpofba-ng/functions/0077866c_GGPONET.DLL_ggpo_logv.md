# 0077866c `GGPONET.DLL::ggpo_logv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077866c |
| `name` | GGPONET.DLL::ggpo_logv |
| `namespace` | GGPONET.DLL |
| `signature` | undefined ggpo_logv(void) |
| `size_bytes` | 6 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void ggpo_logv(void)

{
                    /* WARNING: Could not recover jumptable at 0x0077866c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ggpo_logv();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `0062df15` | FUN_0062ded0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077866c` | `ff 25 6c 94 79 00` | `JMP dword ptr [0x0079946c]` |
