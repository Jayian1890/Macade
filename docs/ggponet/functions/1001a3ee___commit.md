# 1001a3ee `__commit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a3ee |
| `name` | __commit |
| `namespace` | Global |
| `signature` | int __cdecl __commit(int _FileHandle) |
| `size_bytes` | 215 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __commit |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 2008 Release */

int __cdecl __commit(int _FileHandle)

{
  int *piVar1;
  HANDLE hFile;
  BOOL BVar2;
  ulong *puVar3;
  int iVar4;
  DWORD local_20;
  
  if (_FileHandle == -2) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_13439530)) {
      iVar4 = (_FileHandle & 0x1fU) * 0x40;
      if ((*(byte *)(iVar4 + 4 + (&DAT_13439540)[_FileHandle >> 5]) & 1) != 0) {
        ___lock_fhandle(_FileHandle);
        if ((*(byte *)(iVar4 + 4 + (&DAT_13439540)[_FileHandle >> 5]) & 1) != 0) {
          hFile = (HANDLE)__get_osfhandle(_FileHandle);
          BVar2 = FlushFileBuffers(hFile);
          if (BVar2 == 0) {
            local_20 = GetLastError();
          }
          else {
            local_20 = 0;
          }
          if (local_20 == 0) goto LAB_1001a4b0;
          puVar3 = ___doserrno();
          *puVar3 = local_20;
        }
        piVar1 = __errno();
        *piVar1 = 9;
        local_20 = 0xffffffff;
LAB_1001a4b0:
        FUN_1001a4c5();
        return local_20;
      }
    }
    piVar1 = __errno();
    *piVar1 = 9;
    __invalid_parameter(0,0,0,0,0);
  }
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a3f5` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001a402` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001a423` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001a433` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001a45e` | `1001dc2d` | `UNCONDITIONAL_CALL` | ___lock_fhandle | `1001dc2d` |
| `1001a473` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `1001a47a` | `EXTERNAL:00000057` | `COMPUTED_CALL` | KERNEL32.DLL::FlushFileBuffers | `` |
| `1001a484` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001a497` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001a4a1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001a4b7` | `1001a4c5` | `UNCONDITIONAL_CALL` | FUN_1001a4c5 | `1001a4c5` |
| `1001a4bf` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10014527` | __fflush_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a3f0` | `10034030` | `DATA` | DAT_10034030 |
| `1001a41b` | `13439530` | `READ` | DAT_13439530 |
| `1001a442` | `13439540` | `DATA` | DAT_13439540 |
| `1001a451` | `13439540` | `DATA` | DAT_13439540 |
| `1001a467` | `13439540` | `DATA` | DAT_13439540 |
| `1001a47a` | `1002e114` | `READ` | PTR_FlushFileBuffers_1002e114 |
| `1001a484` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a3ee` | `6a 10` | `PUSH 0x10` |
| `1001a3f0` | `68 30 40 03 10` | `PUSH 0x10034030` |
| `1001a3f5` | `e8 02 c9 ff ff` | `CALL 0x10016cfc` |
| `1001a3fa` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001a3fd` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001a400` | `75 13` | `JNZ 0x1001a415` |
| `1001a402` | `e8 02 ad ff ff` | `CALL 0x10015109` |
| `1001a407` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001a40d` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a410` | `e9 aa 00 00 00` | `JMP 0x1001a4bf` |
| `1001a415` | `33 db` | `XOR EBX,EBX` |
| `1001a417` | `3b c3` | `CMP EAX,EBX` |
| `1001a419` | `7c 08` | `JL 0x1001a423` |
| `1001a41b` | `3b 05 30 95 43 13` | `CMP EAX,dword ptr [0x13439530]` |
| `1001a421` | `72 1a` | `JC 0x1001a43d` |
| `1001a423` | `e8 e1 ac ff ff` | `CALL 0x10015109` |
| `1001a428` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001a42e` | `53` | `PUSH EBX` |
| `1001a42f` | `53` | `PUSH EBX` |
| `1001a430` | `53` | `PUSH EBX` |
| `1001a431` | `53` | `PUSH EBX` |
| `1001a432` | `53` | `PUSH EBX` |
| `1001a433` | `e8 77 72 ff ff` | `CALL 0x100116af` |
| `1001a438` | `83 c4 14` | `ADD ESP,0x14` |
| `1001a43b` | `eb d0` | `JMP 0x1001a40d` |
| `1001a43d` | `8b c8` | `MOV ECX,EAX` |
| `1001a43f` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001a442` | `8d 3c 8d 40 95 43 13` | `LEA EDI,[ECX*0x4 + 0x13439540]` |
| `1001a449` | `8b f0` | `MOV ESI,EAX` |
| `1001a44b` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001a44e` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001a451` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001a453` | `0f be 4c 0e 04` | `MOVSX ECX,byte ptr [ESI + ECX*0x1 + 0x4]` |
| `1001a458` | `83 e1 01` | `AND ECX,0x1` |
| `1001a45b` | `74 c6` | `JZ 0x1001a423` |
| `1001a45d` | `50` | `PUSH EAX` |
| `1001a45e` | `e8 ca 37 00 00` | `CALL 0x1001dc2d` |
| `1001a463` | `59` | `POP ECX` |
| `1001a464` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001a467` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001a469` | `f6 44 06 04 01` | `TEST byte ptr [ESI + EAX*0x1 + 0x4],0x1` |
| `1001a46e` | `74 31` | `JZ 0x1001a4a1` |
| `1001a470` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001a473` | `e8 3e 37 00 00` | `CALL 0x1001dbb6` |
| `1001a478` | `59` | `POP ECX` |
| `1001a479` | `50` | `PUSH EAX` |
| `1001a47a` | `ff 15 14 e1 02 10` | `CALL dword ptr [0x1002e114]` |
| `1001a480` | `85 c0` | `TEST EAX,EAX` |
| `1001a482` | `75 0b` | `JNZ 0x1001a48f` |
| `1001a484` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001a48a` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001a48d` | `eb 03` | `JMP 0x1001a492` |
| `1001a48f` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1001a492` | `39 5d e4` | `CMP dword ptr [EBP + -0x1c],EBX` |
| `1001a495` | `74 19` | `JZ 0x1001a4b0` |
| `1001a497` | `e8 80 ac ff ff` | `CALL 0x1001511c` |
| `1001a49c` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1001a49f` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1001a4a1` | `e8 63 ac ff ff` | `CALL 0x10015109` |
| `1001a4a6` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001a4ac` | `83 4d e4 ff` | `OR dword ptr [EBP + -0x1c],0xffffffff` |
| `1001a4b0` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001a4b7` | `e8 09 00 00 00` | `CALL 0x1001a4c5` |
| `1001a4bc` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001a4bf` | `e8 7d c8 ff ff` | `CALL 0x10016d41` |
| `1001a4c4` | `c3` | `RET` |
