# 100181cd `__getstream`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100181cd |
| `name` | __getstream |
| `namespace` | Global |
| `signature` | FILE * __cdecl __getstream(void) |
| `size_bytes` | 300 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __getstream |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 2008 Release */

FILE * __cdecl __getstream(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  FILE *pFVar6;
  FILE *_File;
  
  pFVar6 = (FILE *)0x0;
  __lock(1);
  iVar5 = 0;
  do {
    _File = pFVar6;
    if (DAT_1343a660 <= iVar5) {
LAB_100182cb:
      if (_File != (FILE *)0x0) {
        _File->_flag = _File->_flag & 0x8000;
        _File->_cnt = 0;
        _File->_base = (char *)0x0;
        _File->_ptr = (char *)0x0;
        _File->_tmpfname = (char *)0x0;
        _File->_file = -1;
      }
      FUN_100182fc();
      return _File;
    }
    piVar1 = (int *)(DAT_13439640 + iVar5 * 4);
    if (*piVar1 == 0) {
      iVar5 = iVar5 * 4;
      pvVar4 = __malloc_crt(0x38);
      *(void **)(iVar5 + DAT_13439640) = pvVar4;
      if (*(int *)(DAT_13439640 + iVar5) != 0) {
        iVar3 = ___crtInitCritSecAndSpinCount(*(int *)(DAT_13439640 + iVar5) + 0x20,4000);
        if (iVar3 == 0) {
          _free(*(void **)(iVar5 + DAT_13439640));
          *(undefined4 *)(iVar5 + DAT_13439640) = 0;
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar5 + DAT_13439640) + 0x20));
          _File = *(FILE **)(iVar5 + DAT_13439640);
          _File->_flag = 0;
        }
      }
      goto LAB_100182cb;
    }
    uVar2 = *(uint *)(*piVar1 + 0xc);
    if (((uVar2 & 0x83) == 0) && ((uVar2 & 0x8000) == 0)) {
      if ((iVar5 - 3U < 0x11) && (iVar3 = __mtinitlocknum(iVar5 + 0x10), iVar3 == 0))
      goto LAB_100182cb;
      __lock_file2(iVar5,*(void **)(DAT_13439640 + iVar5 * 4));
      _File = *(FILE **)(DAT_13439640 + iVar5 * 4);
      if ((_File->_flag & 0x83) == 0) goto LAB_100182cb;
      __unlock_file2(iVar5,_File);
    }
    iVar5 = iVar5 + 1;
  } while( true );
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100181d4` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `100181e2` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `10018224` | `10016140` | `UNCONDITIONAL_CALL` | __mtinitlocknum | `10016140` |
| `1001823b` | `10017e67` | `UNCONDITIONAL_CALL` | __lock_file2 | `10017e67` |
| `10018252` | `10017ed5` | `UNCONDITIONAL_CALL` | __unlock_file2 | `10017ed5` |
| `10018268` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001828d` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `100182a0` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `100182b7` | `EXTERNAL:00000043` | `COMPUTED_CALL` | KERNEL32.DLL::EnterCriticalSection | `` |
| `100182ec` | `100182fc` | `UNCONDITIONAL_CALL` | FUN_100182fc | `100182fc` |
| `100182f3` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10011ac3` | __fsopen |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100181cf` | `10033ef0` | `DATA` | DAT_10033ef0 |
| `100181f0` | `1343a660` | `READ` | DAT_1343a660 |
| `100181fc` | `13439640` | `READ` | DAT_13439640 |
| `10018232` | `13439640` | `READ` | DAT_13439640 |
| `10018242` | `13439640` | `READ` | DAT_13439640 |
| `1001826e` | `13439640` | `READ` | DAT_13439640 |
| `10018277` | `13439640` | `READ` | DAT_13439640 |
| `10018296` | `13439640` | `READ` | DAT_13439640 |
| `100182a6` | `13439640` | `READ` | DAT_13439640 |
| `100182b7` | `1002e0c4` | `READ` | PTR_EnterCriticalSection_1002e0c4 |
| `100182bd` | `13439640` | `READ` | DAT_13439640 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100181cd` | `6a 10` | `PUSH 0x10` |
| `100181cf` | `68 f0 3e 03 10` | `PUSH 0x10033ef0` |
| `100181d4` | `e8 23 eb ff ff` | `CALL 0x10016cfc` |
| `100181d9` | `33 db` | `XOR EBX,EBX` |
| `100181db` | `33 ff` | `XOR EDI,EDI` |
| `100181dd` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `100181e0` | `6a 01` | `PUSH 0x1` |
| `100181e2` | `e8 1c e0 ff ff` | `CALL 0x10016203` |
| `100181e7` | `59` | `POP ECX` |
| `100181e8` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `100181eb` | `33 f6` | `XOR ESI,ESI` |
| `100181ed` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `100181f0` | `3b 35 60 a6 43 13` | `CMP ESI,dword ptr [0x1343a660]` |
| `100181f6` | `0f 8d cf 00 00 00` | `JGE 0x100182cb` |
| `100181fc` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `10018201` | `8d 04 b0` | `LEA EAX,[EAX + ESI*0x4]` |
| `10018204` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `10018206` | `74 5b` | `JZ 0x10018263` |
| `10018208` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001820a` | `8b 40 0c` | `MOV EAX,dword ptr [EAX + 0xc]` |
| `1001820d` | `a8 83` | `TEST AL,0x83` |
| `1001820f` | `75 48` | `JNZ 0x10018259` |
| `10018211` | `a9 00 80 00 00` | `TEST EAX,0x8000` |
| `10018216` | `75 41` | `JNZ 0x10018259` |
| `10018218` | `8d 46 fd` | `LEA EAX,[ESI + -0x3]` |
| `1001821b` | `83 f8 10` | `CMP EAX,0x10` |
| `1001821e` | `77 12` | `JA 0x10018232` |
| `10018220` | `8d 46 10` | `LEA EAX,[ESI + 0x10]` |
| `10018223` | `50` | `PUSH EAX` |
| `10018224` | `e8 17 df ff ff` | `CALL 0x10016140` |
| `10018229` | `59` | `POP ECX` |
| `1001822a` | `85 c0` | `TEST EAX,EAX` |
| `1001822c` | `0f 84 99 00 00 00` | `JZ 0x100182cb` |
| `10018232` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `10018237` | `ff 34 b0` | `PUSH dword ptr [EAX + ESI*0x4]` |
| `1001823a` | `56` | `PUSH ESI` |
| `1001823b` | `e8 27 fc ff ff` | `CALL 0x10017e67` |
| `10018240` | `59` | `POP ECX` |
| `10018241` | `59` | `POP ECX` |
| `10018242` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `10018247` | `8b 04 b0` | `MOV EAX,dword ptr [EAX + ESI*0x4]` |
| `1001824a` | `f6 40 0c 83` | `TEST byte ptr [EAX + 0xc],0x83` |
| `1001824e` | `74 0c` | `JZ 0x1001825c` |
| `10018250` | `50` | `PUSH EAX` |
| `10018251` | `56` | `PUSH ESI` |
| `10018252` | `e8 7e fc ff ff` | `CALL 0x10017ed5` |
| `10018257` | `59` | `POP ECX` |
| `10018258` | `59` | `POP ECX` |
| `10018259` | `46` | `INC ESI` |
| `1001825a` | `eb 91` | `JMP 0x100181ed` |
| `1001825c` | `8b f8` | `MOV EDI,EAX` |
| `1001825e` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `10018261` | `eb 68` | `JMP 0x100182cb` |
| `10018263` | `c1 e6 02` | `SHL ESI,0x2` |
| `10018266` | `6a 38` | `PUSH 0x38` |
| `10018268` | `e8 62 22 00 00` | `CALL 0x1001a4cf` |
| `1001826d` | `59` | `POP ECX` |
| `1001826e` | `8b 0d 40 96 43 13` | `MOV ECX,dword ptr [0x13439640]` |
| `10018274` | `89 04 0e` | `MOV dword ptr [ESI + ECX*0x1],EAX` |
| `10018277` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `1001827c` | `03 c6` | `ADD EAX,ESI` |
| `1001827e` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `10018280` | `74 49` | `JZ 0x100182cb` |
| `10018282` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `10018287` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `10018289` | `83 c0 20` | `ADD EAX,0x20` |
| `1001828c` | `50` | `PUSH EAX` |
| `1001828d` | `e8 61 16 00 00` | `CALL 0x100198f3` |
| `10018292` | `59` | `POP ECX` |
| `10018293` | `59` | `POP ECX` |
| `10018294` | `85 c0` | `TEST EAX,EAX` |
| `10018296` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `1001829b` | `75 13` | `JNZ 0x100182b0` |
| `1001829d` | `ff 34 06` | `PUSH dword ptr [ESI + EAX*0x1]` |
| `100182a0` | `e8 9c 8f ff ff` | `CALL 0x10011241` |
| `100182a5` | `59` | `POP ECX` |
| `100182a6` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `100182ab` | `89 1c 06` | `MOV dword ptr [ESI + EAX*0x1],EBX` |
| `100182ae` | `eb 1b` | `JMP 0x100182cb` |
| `100182b0` | `8b 04 06` | `MOV EAX,dword ptr [ESI + EAX*0x1]` |
| `100182b3` | `83 c0 20` | `ADD EAX,0x20` |
| `100182b6` | `50` | `PUSH EAX` |
| `100182b7` | `ff 15 c4 e0 02 10` | `CALL dword ptr [0x1002e0c4]` |
| `100182bd` | `a1 40 96 43 13` | `MOV EAX,[0x13439640]` |
| `100182c2` | `8b 3c 06` | `MOV EDI,dword ptr [ESI + EAX*0x1]` |
| `100182c5` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `100182c8` | `89 5f 0c` | `MOV dword ptr [EDI + 0xc],EBX` |
| `100182cb` | `3b fb` | `CMP EDI,EBX` |
| `100182cd` | `74 16` | `JZ 0x100182e5` |
| `100182cf` | `81 67 0c 00 80 00 00` | `AND dword ptr [EDI + 0xc],0x8000` |
| `100182d6` | `89 5f 04` | `MOV dword ptr [EDI + 0x4],EBX` |
| `100182d9` | `89 5f 08` | `MOV dword ptr [EDI + 0x8],EBX` |
| `100182dc` | `89 1f` | `MOV dword ptr [EDI],EBX` |
| `100182de` | `89 5f 1c` | `MOV dword ptr [EDI + 0x1c],EBX` |
| `100182e1` | `83 4f 10 ff` | `OR dword ptr [EDI + 0x10],0xffffffff` |
| `100182e5` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `100182ec` | `e8 0b 00 00 00` | `CALL 0x100182fc` |
| `100182f1` | `8b c7` | `MOV EAX,EDI` |
| `100182f3` | `e8 49 ea ff ff` | `CALL 0x10016d41` |
| `100182f8` | `c3` | `RET` |
