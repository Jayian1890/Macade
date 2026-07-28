# 1001dc2d `___lock_fhandle`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001dc2d |
| `name` | ___lock_fhandle |
| `namespace` | Global |
| `signature` | int __cdecl ___lock_fhandle(int _Filehandle) |
| `size_bytes` | 146 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___lock_fhandle |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___lock_fhandle
   
   Library: Visual Studio 2008 Release */

int __cdecl ___lock_fhandle(int _Filehandle)

{
  int iVar1;
  int iVar2;
  uint local_20;
  
  iVar2 = (_Filehandle & 0x1fU) * 0x40 + (&DAT_13439540)[_Filehandle >> 5];
  local_20 = 1;
  if (*(int *)(iVar2 + 8) == 0) {
    __lock(10);
    if (*(int *)(iVar2 + 8) == 0) {
      iVar1 = ___crtInitCritSecAndSpinCount(iVar2 + 0xc,4000);
      local_20 = (uint)(iVar1 != 0);
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    }
    FUN_1001dcc4();
  }
  if (local_20 != 0) {
    EnterCriticalSection
              ((LPCRITICAL_SECTION)
               ((&DAT_13439540)[_Filehandle >> 5] + 0xc + (_Filehandle & 0x1fU) * 0x40));
  }
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001dc34` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001dc60` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001dc77` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `1001dc8f` | `1001dcc4` | `UNCONDITIONAL_CALL` | FUN_1001dcc4 | `1001dcc4` |
| `1001dcb0` | `EXTERNAL:00000043` | `COMPUTED_CALL` | KERNEL32.DLL::EnterCriticalSection | `` |
| `1001dcb9` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001a391` | __write |
| `1001ba60` | __lseeki64 |
| `1001de62` | __alloc_osfhnd |
| `1001a45e` | __commit |
| `10018be8` | __read |
| `10018d92` | __close |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001dc2f` | `10034290` | `DATA` | DAT_10034290 |
| `1001dc49` | `13439540` | `DATA` | DAT_13439540 |
| `1001dca4` | `13439540` | `DATA` | DAT_13439540 |
| `1001dcb0` | `1002e0c4` | `READ` | PTR_EnterCriticalSection_1002e0c4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001dc2d` | `6a 0c` | `PUSH 0xc` |
| `1001dc2f` | `68 90 42 03 10` | `PUSH 0x10034290` |
| `1001dc34` | `e8 c3 90 ff ff` | `CALL 0x10016cfc` |
| `1001dc39` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001dc3c` | `8b c7` | `MOV EAX,EDI` |
| `1001dc3e` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001dc41` | `8b f7` | `MOV ESI,EDI` |
| `1001dc43` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001dc46` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001dc49` | `03 34 85 40 95 43 13` | `ADD ESI,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001dc50` | `c7 45 e4 01 00 00 00` | `MOV dword ptr [EBP + -0x1c],0x1` |
| `1001dc57` | `33 db` | `XOR EBX,EBX` |
| `1001dc59` | `39 5e 08` | `CMP dword ptr [ESI + 0x8],EBX` |
| `1001dc5c` | `75 36` | `JNZ 0x1001dc94` |
| `1001dc5e` | `6a 0a` | `PUSH 0xa` |
| `1001dc60` | `e8 9e 85 ff ff` | `CALL 0x10016203` |
| `1001dc65` | `59` | `POP ECX` |
| `1001dc66` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001dc69` | `39 5e 08` | `CMP dword ptr [ESI + 0x8],EBX` |
| `1001dc6c` | `75 1a` | `JNZ 0x1001dc88` |
| `1001dc6e` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `1001dc73` | `8d 46 0c` | `LEA EAX,[ESI + 0xc]` |
| `1001dc76` | `50` | `PUSH EAX` |
| `1001dc77` | `e8 77 bc ff ff` | `CALL 0x100198f3` |
| `1001dc7c` | `59` | `POP ECX` |
| `1001dc7d` | `59` | `POP ECX` |
| `1001dc7e` | `85 c0` | `TEST EAX,EAX` |
| `1001dc80` | `75 03` | `JNZ 0x1001dc85` |
| `1001dc82` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1001dc85` | `ff 46 08` | `INC dword ptr [ESI + 0x8]` |
| `1001dc88` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001dc8f` | `e8 30 00 00 00` | `CALL 0x1001dcc4` |
| `1001dc94` | `39 5d e4` | `CMP dword ptr [EBP + -0x1c],EBX` |
| `1001dc97` | `74 1d` | `JZ 0x1001dcb6` |
| `1001dc99` | `8b c7` | `MOV EAX,EDI` |
| `1001dc9b` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001dc9e` | `83 e7 1f` | `AND EDI,0x1f` |
| `1001dca1` | `c1 e7 06` | `SHL EDI,0x6` |
| `1001dca4` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001dcab` | `8d 44 38 0c` | `LEA EAX,[EAX + EDI*0x1 + 0xc]` |
| `1001dcaf` | `50` | `PUSH EAX` |
| `1001dcb0` | `ff 15 c4 e0 02 10` | `CALL dword ptr [0x1002e0c4]` |
| `1001dcb6` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001dcb9` | `e8 83 90 ff ff` | `CALL 0x10016d41` |
| `1001dcbe` | `c3` | `RET` |
