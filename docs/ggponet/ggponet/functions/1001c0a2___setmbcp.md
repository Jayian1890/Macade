# 1001c0a2 `__setmbcp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c0a2 |
| `name` | __setmbcp |
| `namespace` | Global |
| `signature` | int __cdecl __setmbcp(int _CodePage) |
| `size_bytes` | 399 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __setmbcp |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setmbcp
   
   Library: Visual Studio 2008 Release */

int __cdecl __setmbcp(int _CodePage)

{
  _ptiddata p_Var1;
  int iVar2;
  pthreadmbcinfo ptVar3;
  LONG LVar4;
  int *piVar5;
  int iVar6;
  pthreadmbcinfo ptVar7;
  pthreadmbcinfo ptVar8;
  int in_stack_ffffffc8;
  int local_24;
  
  local_24 = -1;
  p_Var1 = __getptd();
  ___updatetmbcinfo();
  ptVar3 = p_Var1->ptmbcinfo;
  iVar2 = getSystemCP(in_stack_ffffffc8);
  if (iVar2 == ptVar3->mbcodepage) {
    local_24 = 0;
  }
  else {
    ptVar3 = __malloc_crt(0x220);
    if (ptVar3 != (pthreadmbcinfo)0x0) {
      ptVar7 = p_Var1->ptmbcinfo;
      ptVar8 = ptVar3;
      for (iVar6 = 0x88; iVar6 != 0; iVar6 = iVar6 + -1) {
        ptVar8->refcount = ptVar7->refcount;
        ptVar7 = (pthreadmbcinfo)&ptVar7->mbcodepage;
        ptVar8 = (pthreadmbcinfo)&ptVar8->mbcodepage;
      }
      ptVar3->refcount = 0;
      local_24 = __setmbcp_nolock(iVar2,ptVar3);
      if (local_24 == 0) {
        LVar4 = InterlockedDecrement(&p_Var1->ptmbcinfo->refcount);
        if ((LVar4 == 0) && (p_Var1->ptmbcinfo != (pthreadmbcinfo)&DAT_10037c20)) {
          _free(p_Var1->ptmbcinfo);
        }
        p_Var1->ptmbcinfo = ptVar3;
        InterlockedIncrement(&ptVar3->refcount);
        if (((p_Var1->_ownlocale & 2) == 0) && (((byte)DAT_10038144 & 1) == 0)) {
          __lock(0xd);
          _DAT_10039394 = ptVar3->mbcodepage;
          _DAT_10039398 = ptVar3->ismbcodepage;
          _DAT_1003939c = *(undefined4 *)ptVar3->mbulinfo;
          for (iVar2 = 0; iVar2 < 5; iVar2 = iVar2 + 1) {
            (&DAT_10039388)[iVar2] = ptVar3->mbulinfo[iVar2 + 2];
          }
          for (iVar2 = 0; iVar2 < 0x101; iVar2 = iVar2 + 1) {
            (&DAT_10037e40)[iVar2] = ptVar3->mbctype[iVar2 + 4];
          }
          for (iVar2 = 0; iVar2 < 0x100; iVar2 = iVar2 + 1) {
            (&DAT_10037f48)[iVar2] = ptVar3->mbcasemap[iVar2 + 4];
          }
          LVar4 = InterlockedDecrement((LONG *)PTR_DAT_10038048);
          if ((LVar4 == 0) && (PTR_DAT_10038048 != &DAT_10037c20)) {
            _free(PTR_DAT_10038048);
          }
          PTR_DAT_10038048 = (undefined *)ptVar3;
          InterlockedIncrement(&ptVar3->refcount);
          FUN_1001c203();
        }
      }
      else if (local_24 == -1) {
        if (ptVar3 != (pthreadmbcinfo)&DAT_10037c20) {
          _free(ptVar3);
        }
        piVar5 = __errno();
        *piVar5 = 0x16;
      }
    }
  }
  return local_24;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c0a9` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001c0b2` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001c0bc` | `1001bd9d` | `UNCONDITIONAL_CALL` | ___updatetmbcinfo | `1001bd9d` |
| `1001c0c7` | `1001be41` | `UNCONDITIONAL_CALL` | getSystemCP | `1001be41` |
| `1001c0dd` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001c100` | `1001bebd` | `UNCONDITIONAL_CALL` | __setmbcp_nolock | `1001bebd` |
| `1001c118` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c12d` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c13d` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c158` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001c1cf` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c1e6` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c1f3` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c1fc` | `1001c203` | `UNCONDITIONAL_CALL` | FUN_1001c203 | `1001c203` |
| `1001c21c` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c222` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c236` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001c247` | ___initmbctable |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c0a4` | `100341f0` | `DATA` | DAT_100341f0 |
| `1001c118` | `1002e0f0` | `READ` | PTR_InterlockedDecrement_1002e0f0 |
| `1001c125` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001c137` | `1002e0e8` | `READ` | PTR_InterlockedIncrement_1002e0e8 |
| `1001c149` | `10038144` | `READ` | DAT_10038144 |
| `1001c165` | `10039394` | `WRITE` | DAT_10039394 |
| `1001c16d` | `10039398` | `WRITE` | DAT_10039398 |
| `1001c175` | `1003939c` | `WRITE` | DAT_1003939c |
| `1001c189` | `10039388` | `WRITE` | DAT_10039388 |
| `1001c189` | `1003938a` | `WRITE` | DAT_1003938a |
| `1001c1a4` | `10037e40` | `WRITE` | DAT_10037e40 |
| `1001c1a4` | `10037e41` | `WRITE` | DAT_10037e41 |
| `1001c1c0` | `10037f48` | `WRITE` | DAT_10037f48 |
| `1001c1c0` | `10037f49` | `WRITE` | DAT_10037f49 |
| `1001c1c9` | `10038048` | `READ` | PTR_DAT_10038048 |
| `1001c1c9` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001c1cf` | `1002e0f0` | `READ` | PTR_InterlockedDecrement_1002e0f0 |
| `1001c1d9` | `10038048` | `READ` | PTR_DAT_10038048 |
| `1001c1de` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001c1e5` | `10037c20` | `DATA` | DAT_10037c20 |
| `1001c1ec` | `10038048` | `WRITE` | PTR_DAT_10038048 |
| `1001c213` | `10037c20` | `DATA` | DAT_10037c20 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c0a2` | `6a 14` | `PUSH 0x14` |
| `1001c0a4` | `68 f0 41 03 10` | `PUSH 0x100341f0` |
| `1001c0a9` | `e8 4e ac ff ff` | `CALL 0x10016cfc` |
| `1001c0ae` | `83 4d e0 ff` | `OR dword ptr [EBP + -0x20],0xffffffff` |
| `1001c0b2` | `e8 1f b3 ff ff` | `CALL 0x100173d6` |
| `1001c0b7` | `8b f8` | `MOV EDI,EAX` |
| `1001c0b9` | `89 7d dc` | `MOV dword ptr [EBP + -0x24],EDI` |
| `1001c0bc` | `e8 dc fc ff ff` | `CALL 0x1001bd9d` |
| `1001c0c1` | `8b 5f 68` | `MOV EBX,dword ptr [EDI + 0x68]` |
| `1001c0c4` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001c0c7` | `e8 75 fd ff ff` | `CALL 0x1001be41` |
| `1001c0cc` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `1001c0cf` | `3b 43 04` | `CMP EAX,dword ptr [EBX + 0x4]` |
| `1001c0d2` | `0f 84 57 01 00 00` | `JZ 0x1001c22f` |
| `1001c0d8` | `68 20 02 00 00` | `PUSH 0x220` |
| `1001c0dd` | `e8 ed e3 ff ff` | `CALL 0x1001a4cf` |
| `1001c0e2` | `59` | `POP ECX` |
| `1001c0e3` | `8b d8` | `MOV EBX,EAX` |
| `1001c0e5` | `85 db` | `TEST EBX,EBX` |
| `1001c0e7` | `0f 84 46 01 00 00` | `JZ 0x1001c233` |
| `1001c0ed` | `b9 88 00 00 00` | `MOV ECX,0x88` |
| `1001c0f2` | `8b 77 68` | `MOV ESI,dword ptr [EDI + 0x68]` |
| `1001c0f5` | `8b fb` | `MOV EDI,EBX` |
| `1001c0f7` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `1001c0f9` | `83 23 00` | `AND dword ptr [EBX],0x0` |
| `1001c0fc` | `53` | `PUSH EBX` |
| `1001c0fd` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001c100` | `e8 b8 fd ff ff` | `CALL 0x1001bebd` |
| `1001c105` | `59` | `POP ECX` |
| `1001c106` | `59` | `POP ECX` |
| `1001c107` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001c10a` | `85 c0` | `TEST EAX,EAX` |
| `1001c10c` | `0f 85 fc 00 00 00` | `JNZ 0x1001c20e` |
| `1001c112` | `8b 75 dc` | `MOV ESI,dword ptr [EBP + -0x24]` |
| `1001c115` | `ff 76 68` | `PUSH dword ptr [ESI + 0x68]` |
| `1001c118` | `ff 15 f0 e0 02 10` | `CALL dword ptr [0x1002e0f0]` |
| `1001c11e` | `85 c0` | `TEST EAX,EAX` |
| `1001c120` | `75 11` | `JNZ 0x1001c133` |
| `1001c122` | `8b 46 68` | `MOV EAX,dword ptr [ESI + 0x68]` |
| `1001c125` | `3d 20 7c 03 10` | `CMP EAX,0x10037c20` |
| `1001c12a` | `74 07` | `JZ 0x1001c133` |
| `1001c12c` | `50` | `PUSH EAX` |
| `1001c12d` | `e8 0f 51 ff ff` | `CALL 0x10011241` |
| `1001c132` | `59` | `POP ECX` |
| `1001c133` | `89 5e 68` | `MOV dword ptr [ESI + 0x68],EBX` |
| `1001c136` | `53` | `PUSH EBX` |
| `1001c137` | `8b 3d e8 e0 02 10` | `MOV EDI,dword ptr [0x1002e0e8]` |
| `1001c13d` | `ff d7` | `CALL EDI` |
| `1001c13f` | `f6 46 70 02` | `TEST byte ptr [ESI + 0x70],0x2` |
| `1001c143` | `0f 85 ea 00 00 00` | `JNZ 0x1001c233` |
| `1001c149` | `f6 05 44 81 03 10 01` | `TEST byte ptr [0x10038144],0x1` |
| `1001c150` | `0f 85 dd 00 00 00` | `JNZ 0x1001c233` |
| `1001c156` | `6a 0d` | `PUSH 0xd` |
| `1001c158` | `e8 a6 a0 ff ff` | `CALL 0x10016203` |
| `1001c15d` | `59` | `POP ECX` |
| `1001c15e` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001c162` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1001c165` | `a3 94 93 03 10` | `MOV [0x10039394],EAX` |
| `1001c16a` | `8b 43 08` | `MOV EAX,dword ptr [EBX + 0x8]` |
| `1001c16d` | `a3 98 93 03 10` | `MOV [0x10039398],EAX` |
| `1001c172` | `8b 43 0c` | `MOV EAX,dword ptr [EBX + 0xc]` |
| `1001c175` | `a3 9c 93 03 10` | `MOV [0x1003939c],EAX` |
| `1001c17a` | `33 c0` | `XOR EAX,EAX` |
| `1001c17c` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001c17f` | `83 f8 05` | `CMP EAX,0x5` |
| `1001c182` | `7d 10` | `JGE 0x1001c194` |
| `1001c184` | `66 8b 4c 43 10` | `MOV CX,word ptr [EBX + EAX*0x2 + 0x10]` |
| `1001c189` | `66 89 0c 45 88 93 03 10` | `MOV word ptr [EAX*0x2 + 0x10039388],CX` |
| `1001c191` | `40` | `INC EAX` |
| `1001c192` | `eb e8` | `JMP 0x1001c17c` |
| `1001c194` | `33 c0` | `XOR EAX,EAX` |
| `1001c196` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001c199` | `3d 01 01 00 00` | `CMP EAX,0x101` |
| `1001c19e` | `7d 0d` | `JGE 0x1001c1ad` |
| `1001c1a0` | `8a 4c 18 1c` | `MOV CL,byte ptr [EAX + EBX*0x1 + 0x1c]` |
| `1001c1a4` | `88 88 40 7e 03 10` | `MOV byte ptr [EAX + 0x10037e40],CL` |
| `1001c1aa` | `40` | `INC EAX` |
| `1001c1ab` | `eb e9` | `JMP 0x1001c196` |
| `1001c1ad` | `33 c0` | `XOR EAX,EAX` |
| `1001c1af` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001c1b2` | `3d 00 01 00 00` | `CMP EAX,0x100` |
| `1001c1b7` | `7d 10` | `JGE 0x1001c1c9` |
| `1001c1b9` | `8a 8c 18 1d 01 00 00` | `MOV CL,byte ptr [EAX + EBX*0x1 + 0x11d]` |
| `1001c1c0` | `88 88 48 7f 03 10` | `MOV byte ptr [EAX + 0x10037f48],CL` |
| `1001c1c6` | `40` | `INC EAX` |
| `1001c1c7` | `eb e6` | `JMP 0x1001c1af` |
| `1001c1c9` | `ff 35 48 80 03 10` | `PUSH dword ptr [0x10038048]` |
| `1001c1cf` | `ff 15 f0 e0 02 10` | `CALL dword ptr [0x1002e0f0]` |
| `1001c1d5` | `85 c0` | `TEST EAX,EAX` |
| `1001c1d7` | `75 13` | `JNZ 0x1001c1ec` |
| `1001c1d9` | `a1 48 80 03 10` | `MOV EAX,[0x10038048]` |
| `1001c1de` | `3d 20 7c 03 10` | `CMP EAX,0x10037c20` |
| `1001c1e3` | `74 07` | `JZ 0x1001c1ec` |
| `1001c1e5` | `50` | `PUSH EAX` |
| `1001c1e6` | `e8 56 50 ff ff` | `CALL 0x10011241` |
| `1001c1eb` | `59` | `POP ECX` |
| `1001c1ec` | `89 1d 48 80 03 10` | `MOV dword ptr [0x10038048],EBX` |
| `1001c1f2` | `53` | `PUSH EBX` |
| `1001c1f3` | `ff d7` | `CALL EDI` |
| `1001c1f5` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001c1fc` | `e8 02 00 00 00` | `CALL 0x1001c203` |
| `1001c201` | `eb 30` | `JMP 0x1001c233` |
| `1001c20e` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001c211` | `75 20` | `JNZ 0x1001c233` |
| `1001c213` | `81 fb 20 7c 03 10` | `CMP EBX,0x10037c20` |
| `1001c219` | `74 07` | `JZ 0x1001c222` |
| `1001c21b` | `53` | `PUSH EBX` |
| `1001c21c` | `e8 20 50 ff ff` | `CALL 0x10011241` |
| `1001c221` | `59` | `POP ECX` |
| `1001c222` | `e8 e2 8e ff ff` | `CALL 0x10015109` |
| `1001c227` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001c22d` | `eb 04` | `JMP 0x1001c233` |
| `1001c22f` | `83 65 e0 00` | `AND dword ptr [EBP + -0x20],0x0` |
| `1001c233` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1001c236` | `e8 06 ab ff ff` | `CALL 0x10016d41` |
| `1001c23b` | `c3` | `RET` |
