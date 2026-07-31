# 0077865a `GGPONET.DLL::ggpo_start_streaming`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077865a |
| `name` | GGPONET.DLL::ggpo_start_streaming |
| `namespace` | GGPONET.DLL |
| `signature` | undefined ggpo_start_streaming(void) |
| `size_bytes` | 6 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void ggpo_start_streaming(void)

{
                    /* WARNING: Could not recover jumptable at 0x0077865a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ggpo_start_streaming();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `0062de4f` | FUN_0062dc50 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077865a` | `ff 25 78 94 79 00` | `JMP dword ptr [0x00799478]` |
