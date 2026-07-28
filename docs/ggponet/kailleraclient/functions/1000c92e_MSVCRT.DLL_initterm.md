# 1000c92e `MSVCRT.DLL::initterm`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000c92e |
| `name` | MSVCRT.DLL::initterm |
| `namespace` | MSVCRT.DLL |
| `signature` | undefined __cdecl initterm(void) |
| `size_bytes` | 6 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void __cdecl initterm(void)

{
                    /* WARNING: Could not recover jumptable at 0x1000c92e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  initterm();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000c839` | FUN_1000c7e0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000c92e` | `ff 25 8c d0 00 10` | `JMP dword ptr [0x1000d08c]` |
