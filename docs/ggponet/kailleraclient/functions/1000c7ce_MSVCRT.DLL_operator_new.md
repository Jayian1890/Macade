# 1000c7ce `MSVCRT.DLL::operator_new`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000c7ce |
| `name` | MSVCRT.DLL::operator_new |
| `namespace` | MSVCRT.DLL |
| `signature` | void * __cdecl operator_new(uint param_1) |
| `size_bytes` | 6 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
                    /* WARNING: Could not recover jumptable at 0x1000c7ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar1 = operator_new(param_1);
  return pvVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000583f` | kailleraInit |
| `100092d6` | FUN_10008f30 |
| `10009606` | FUN_10008f30 |
| `1000ac08` | FUN_1000ab90 |
| `1000395c` | FUN_10003610 |
| `10002a70` | FUN_10002a40 |
| `1000b14a` | FUN_1000ab90 |
| `10005147` | FUN_10005000 |
| `10005499` | FUN_10005000 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000c7ce` | `ff 25 74 d0 00 10` | `JMP dword ptr [0x1000d074]` |
