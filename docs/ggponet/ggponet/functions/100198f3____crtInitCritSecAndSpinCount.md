# 100198f3 `___crtInitCritSecAndSpinCount`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100198f3 |
| `name` | ___crtInitCritSecAndSpinCount |
| `namespace` | Global |
| `signature` | undefined ___crtInitCritSecAndSpinCount(void) |
| `size_bytes` | 49 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___crtInitCritSecAndSpinCount |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___crtInitCritSecAndSpinCount
   
   Library: Visual Studio 2008 Release */

BOOL ___crtInitCritSecAndSpinCount(LPCRITICAL_SECTION param_1,DWORD param_2)

{
  BOOL BVar1;
  
  BVar1 = InitializeCriticalSectionAndSpinCount(param_1,param_2);
  return BVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100198fa` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10019909` | `EXTERNAL:00000054` | `COMPUTED_CALL` | KERNEL32.DLL::InitializeCriticalSectionAndSpinCount | `` |
| `1001994d` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `100161b8` | __mtinitlocknum |
| `1001828d` | __getstream |
| `1001dc77` | ___lock_fhandle |
| `1001dd83` | __alloc_osfhnd |
| `100160af` | __mtinitlocks |
| `10019054` | __ioinit |
| `100190ea` | __ioinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100198f5` | `10033ff0` | `DATA` | DAT_10033ff0 |
| `10019909` | `1002e108` | `READ` | PTR_InitializeCriticalSectionAndSpinCount_1002e108 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100198f3` | `6a 10` | `PUSH 0x10` |
| `100198f5` | `68 f0 3f 03 10` | `PUSH 0x10033ff0` |
| `100198fa` | `e8 fd d3 ff ff` | `CALL 0x10016cfc` |
| `100198ff` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10019903` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10019906` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019909` | `ff 15 08 e1 02 10` | `CALL dword ptr [0x1002e108]` |
| `1001990f` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10019912` | `eb 2f` | `JMP 0x10019943` |
| `10019943` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001994a` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001994d` | `e8 ef d3 ff ff` | `CALL 0x10016d41` |
| `10019952` | `c3` | `RET` |
