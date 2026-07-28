# 10018ee1 `__ioinit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018ee1 |
| `name` | __ioinit |
| `namespace` | Global |
| `signature` | int __cdecl __ioinit(void) |
| `size_bytes` | 582 |
| `stack_frame_size` | 108 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __ioinit |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __ioinit
   
   Library: Visual Studio 2008 Release */

int __cdecl __ioinit(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  int iVar4;
  HANDLE pvVar5;
  int iVar6;
  UINT *pUVar7;
  int *piVar8;
  UINT UVar9;
  UINT UVar10;
  _STARTUPINFOA local_68;
  uint local_24;
  byte *local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x10018eed;
  local_8 = 0;
  GetStartupInfoA(&local_68);
  local_8 = 0xfffffffe;
  puVar2 = __calloc_crt(0x20,0x40);
  if (puVar2 == (undefined4 *)0x0) {
LAB_1001912c:
    iVar4 = -1;
  }
  else {
    DAT_13439530 = 0x20;
    DAT_13439540 = puVar2;
    for (; puVar2 < DAT_13439540 + 0x200; puVar2 = puVar2 + 0x10) {
      *(undefined1 *)(puVar2 + 1) = 0;
      *puVar2 = 0xffffffff;
      *(undefined1 *)((int)puVar2 + 5) = 10;
      puVar2[2] = 0;
      *(undefined1 *)(puVar2 + 9) = 0;
      *(undefined1 *)((int)puVar2 + 0x25) = 10;
      *(undefined1 *)((int)puVar2 + 0x26) = 10;
      puVar2[0xe] = 0;
      *(undefined1 *)(puVar2 + 0xd) = 0;
    }
    if ((local_68.cbReserved2 != 0) && ((UINT *)local_68.lpReserved2 != (UINT *)0x0)) {
      UVar9 = *(UINT *)local_68.lpReserved2;
      pUVar7 = (UINT *)((int)local_68.lpReserved2 + 4);
      local_20 = (byte *)((int)pUVar7 + UVar9);
      if (0x7ff < (int)UVar9) {
        UVar9 = 0x800;
      }
      local_24 = 1;
      while ((UVar10 = UVar9, (int)DAT_13439530 < (int)UVar9 &&
             (puVar2 = __calloc_crt(0x20,0x40), UVar10 = DAT_13439530, puVar2 != (undefined4 *)0x0))
            ) {
        (&DAT_13439540)[local_24] = puVar2;
        DAT_13439530 = DAT_13439530 + 0x20;
        puVar1 = puVar2;
        for (; puVar2 < puVar1 + 0x200; puVar2 = puVar2 + 0x10) {
          *(undefined1 *)(puVar2 + 1) = 0;
          *puVar2 = 0xffffffff;
          *(undefined1 *)((int)puVar2 + 5) = 10;
          puVar2[2] = 0;
          *(byte *)(puVar2 + 9) = *(byte *)(puVar2 + 9) & 0x80;
          *(undefined1 *)((int)puVar2 + 0x25) = 10;
          *(undefined1 *)((int)puVar2 + 0x26) = 10;
          puVar2[0xe] = 0;
          *(undefined1 *)(puVar2 + 0xd) = 0;
          puVar1 = (&DAT_13439540)[local_24];
        }
        local_24 = local_24 + 1;
      }
      local_24 = 0;
      if (0 < (int)UVar10) {
        do {
          pvVar5 = *(HANDLE *)local_20;
          if ((((pvVar5 != (HANDLE)0xffffffff) && (pvVar5 != (HANDLE)0xfffffffe)) &&
              ((*pUVar7 & 1) != 0)) &&
             (((*pUVar7 & 8) != 0 || (DVar3 = GetFileType(pvVar5), DVar3 != 0)))) {
            puVar2 = (undefined4 *)
                     ((local_24 & 0x1f) * 0x40 + (int)(&DAT_13439540)[(int)local_24 >> 5]);
            *puVar2 = *(undefined4 *)local_20;
            *(byte *)(puVar2 + 1) = (byte)*pUVar7;
            iVar4 = ___crtInitCritSecAndSpinCount(puVar2 + 3,4000);
            if (iVar4 == 0) goto LAB_1001912c;
            puVar2[2] = puVar2[2] + 1;
          }
          local_24 = local_24 + 1;
          pUVar7 = (UINT *)((int)pUVar7 + 1);
          local_20 = local_20 + 4;
        } while ((int)local_24 < (int)UVar10);
      }
    }
    iVar4 = 0;
    do {
      piVar8 = DAT_13439540 + iVar4 * 0x10;
      if ((*piVar8 == -1) || (*piVar8 == -2)) {
        *(undefined1 *)(piVar8 + 1) = 0x81;
        if (iVar4 == 0) {
          DVar3 = 0xfffffff6;
        }
        else {
          DVar3 = 0xfffffff5 - (iVar4 != 1);
        }
        pvVar5 = GetStdHandle(DVar3);
        if (((pvVar5 == (HANDLE)0xffffffff) || (pvVar5 == (HANDLE)0x0)) ||
           (DVar3 = GetFileType(pvVar5), DVar3 == 0)) {
          *(byte *)(piVar8 + 1) = *(byte *)(piVar8 + 1) | 0x40;
          *piVar8 = -2;
        }
        else {
          *piVar8 = (int)pvVar5;
          if ((DVar3 & 0xff) == 2) {
            *(byte *)(piVar8 + 1) = *(byte *)(piVar8 + 1) | 0x40;
          }
          else if ((DVar3 & 0xff) == 3) {
            *(byte *)(piVar8 + 1) = *(byte *)(piVar8 + 1) | 8;
          }
          iVar6 = ___crtInitCritSecAndSpinCount(piVar8 + 3,4000);
          if (iVar6 == 0) goto LAB_1001912c;
          piVar8[2] = piVar8[2] + 1;
        }
      }
      else {
        *(byte *)(piVar8 + 1) = *(byte *)(piVar8 + 1) | 0x80;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
    SetHandleCount(DAT_13439530);
    iVar4 = 0;
  }
  return iVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018ee8` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `10018ef6` | `EXTERNAL:00000052` | `COMPUTED_CALL` | KERNEL32.DLL::GetStartupInfoA | `` |
| `10018f09` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `10018f97` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `10019020` | `EXTERNAL:00000051` | `COMPUTED_CALL` | KERNEL32.DLL::GetFileType | `` |
| `10019054` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `100190aa` | `EXTERNAL:00000046` | `COMPUTED_CALL` | KERNEL32.DLL::GetStdHandle | `` |
| `100190bc` | `EXTERNAL:00000051` | `COMPUTED_CALL` | KERNEL32.DLL::GetFileType | `` |
| `100190ea` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `10019114` | `EXTERNAL:00000050` | `COMPUTED_CALL` | KERNEL32.DLL::SetHandleCount | `` |
| `1001912f` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `100146ba` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10018ee3` | `10033f50` | `DATA` | DAT_10033f50 |
| `10018ef6` | `1002e100` | `READ` | PTR_GetStartupInfoA_1002e100 |
| `10018f18` | `13439540` | `WRITE` | DAT_13439540 |
| `10018f1d` | `13439530` | `WRITE` | DAT_13439530 |
| `10018f4f` | `13439540` | `READ` | DAT_13439540 |
| `10018fa5` | `13439544` | `DATA` | DAT_13439544 |
| `10018fac` | `13439544` | `WRITE` | DAT_13439544 |
| `10018fae` | `13439530` | `READ_WRITE` | DAT_13439530 |
| `10018fe3` | `13439544` | `READ` | DAT_13439544 |
| `10018fee` | `13439530` | `READ` | DAT_13439530 |
| `10018ff8` | `13439530` | `READ` | DAT_13439530 |
| `10019020` | `1002e0fc` | `READ` | PTR_GetFileType_1002e0fc |
| `10019038` | `13439540` | `DATA` | DAT_13439540 |
| `1001907a` | `13439540` | `READ` | DAT_13439540 |
| `100190aa` | `1002e0d0` | `READ` | PTR_GetStdHandle_1002e0d0 |
| `100190bc` | `1002e0fc` | `READ` | PTR_GetFileType_1002e0fc |
| `1001910e` | `13439530` | `READ` | DAT_13439530 |
| `10019114` | `1002e0f8` | `READ` | PTR_SetHandleCount_1002e0f8 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018ee1` | `6a 54` | `PUSH 0x54` |
| `10018ee3` | `68 50 3f 03 10` | `PUSH 0x10033f50` |
| `10018ee8` | `e8 0f de ff ff` | `CALL 0x10016cfc` |
| `10018eed` | `33 ff` | `XOR EDI,EDI` |
| `10018eef` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10018ef2` | `8d 45 9c` | `LEA EAX,[EBP + -0x64]` |
| `10018ef5` | `50` | `PUSH EAX` |
| `10018ef6` | `ff 15 00 e1 02 10` | `CALL dword ptr [0x1002e100]` |
| `10018efc` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10018f03` | `6a 40` | `PUSH 0x40` |
| `10018f05` | `6a 20` | `PUSH 0x20` |
| `10018f07` | `5e` | `POP ESI` |
| `10018f08` | `56` | `PUSH ESI` |
| `10018f09` | `e8 06 16 00 00` | `CALL 0x1001a514` |
| `10018f0e` | `59` | `POP ECX` |
| `10018f0f` | `59` | `POP ECX` |
| `10018f10` | `3b c7` | `CMP EAX,EDI` |
| `10018f12` | `0f 84 14 02 00 00` | `JZ 0x1001912c` |
| `10018f18` | `a3 40 95 43 13` | `MOV [0x13439540],EAX` |
| `10018f1d` | `89 35 30 95 43 13` | `MOV dword ptr [0x13439530],ESI` |
| `10018f23` | `8d 88 00 08 00 00` | `LEA ECX,[EAX + 0x800]` |
| `10018f29` | `eb 30` | `JMP 0x10018f5b` |
| `10018f2b` | `c6 40 04 00` | `MOV byte ptr [EAX + 0x4],0x0` |
| `10018f2f` | `83 08 ff` | `OR dword ptr [EAX],0xffffffff` |
| `10018f32` | `c6 40 05 0a` | `MOV byte ptr [EAX + 0x5],0xa` |
| `10018f36` | `89 78 08` | `MOV dword ptr [EAX + 0x8],EDI` |
| `10018f39` | `c6 40 24 00` | `MOV byte ptr [EAX + 0x24],0x0` |
| `10018f3d` | `c6 40 25 0a` | `MOV byte ptr [EAX + 0x25],0xa` |
| `10018f41` | `c6 40 26 0a` | `MOV byte ptr [EAX + 0x26],0xa` |
| `10018f45` | `89 78 38` | `MOV dword ptr [EAX + 0x38],EDI` |
| `10018f48` | `c6 40 34 00` | `MOV byte ptr [EAX + 0x34],0x0` |
| `10018f4c` | `83 c0 40` | `ADD EAX,0x40` |
| `10018f4f` | `8b 0d 40 95 43 13` | `MOV ECX,dword ptr [0x13439540]` |
| `10018f55` | `81 c1 00 08 00 00` | `ADD ECX,0x800` |
| `10018f5b` | `3b c1` | `CMP EAX,ECX` |
| `10018f5d` | `72 cc` | `JC 0x10018f2b` |
| `10018f5f` | `66 39 7d ce` | `CMP word ptr [EBP + -0x32],DI` |
| `10018f63` | `0f 84 0a 01 00 00` | `JZ 0x10019073` |
| `10018f69` | `8b 45 d0` | `MOV EAX,dword ptr [EBP + -0x30]` |
| `10018f6c` | `3b c7` | `CMP EAX,EDI` |
| `10018f6e` | `0f 84 ff 00 00 00` | `JZ 0x10019073` |
| `10018f74` | `8b 38` | `MOV EDI,dword ptr [EAX]` |
| `10018f76` | `8d 58 04` | `LEA EBX,[EAX + 0x4]` |
| `10018f79` | `8d 04 3b` | `LEA EAX,[EBX + EDI*0x1]` |
| `10018f7c` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10018f7f` | `be 00 08 00 00` | `MOV ESI,0x800` |
| `10018f84` | `3b fe` | `CMP EDI,ESI` |
| `10018f86` | `7c 02` | `JL 0x10018f8a` |
| `10018f88` | `8b fe` | `MOV EDI,ESI` |
| `10018f8a` | `c7 45 e0 01 00 00 00` | `MOV dword ptr [EBP + -0x20],0x1` |
| `10018f91` | `eb 5b` | `JMP 0x10018fee` |
| `10018f93` | `6a 40` | `PUSH 0x40` |
| `10018f95` | `6a 20` | `PUSH 0x20` |
| `10018f97` | `e8 78 15 00 00` | `CALL 0x1001a514` |
| `10018f9c` | `59` | `POP ECX` |
| `10018f9d` | `59` | `POP ECX` |
| `10018f9e` | `85 c0` | `TEST EAX,EAX` |
| `10018fa0` | `74 56` | `JZ 0x10018ff8` |
| `10018fa2` | `8b 4d e0` | `MOV ECX,dword ptr [EBP + -0x20]` |
| `10018fa5` | `8d 0c 8d 40 95 43 13` | `LEA ECX,[ECX*0x4 + 0x13439540]` |
| `10018fac` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `10018fae` | `83 05 30 95 43 13 20` | `ADD dword ptr [0x13439530],0x20` |
| `10018fb5` | `8d 90 00 08 00 00` | `LEA EDX,[EAX + 0x800]` |
| `10018fbb` | `eb 2a` | `JMP 0x10018fe7` |
| `10018fbd` | `c6 40 04 00` | `MOV byte ptr [EAX + 0x4],0x0` |
| `10018fc1` | `83 08 ff` | `OR dword ptr [EAX],0xffffffff` |
| `10018fc4` | `c6 40 05 0a` | `MOV byte ptr [EAX + 0x5],0xa` |
| `10018fc8` | `83 60 08 00` | `AND dword ptr [EAX + 0x8],0x0` |
| `10018fcc` | `80 60 24 80` | `AND byte ptr [EAX + 0x24],0x80` |
| `10018fd0` | `c6 40 25 0a` | `MOV byte ptr [EAX + 0x25],0xa` |
| `10018fd4` | `c6 40 26 0a` | `MOV byte ptr [EAX + 0x26],0xa` |
| `10018fd8` | `83 60 38 00` | `AND dword ptr [EAX + 0x38],0x0` |
| `10018fdc` | `c6 40 34 00` | `MOV byte ptr [EAX + 0x34],0x0` |
| `10018fe0` | `83 c0 40` | `ADD EAX,0x40` |
| `10018fe3` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10018fe5` | `03 d6` | `ADD EDX,ESI` |
| `10018fe7` | `3b c2` | `CMP EAX,EDX` |
| `10018fe9` | `72 d2` | `JC 0x10018fbd` |
| `10018feb` | `ff 45 e0` | `INC dword ptr [EBP + -0x20]` |
| `10018fee` | `39 3d 30 95 43 13` | `CMP dword ptr [0x13439530],EDI` |
| `10018ff4` | `7c 9d` | `JL 0x10018f93` |
| `10018ff6` | `eb 06` | `JMP 0x10018ffe` |
| `10018ff8` | `8b 3d 30 95 43 13` | `MOV EDI,dword ptr [0x13439530]` |
| `10018ffe` | `83 65 e0 00` | `AND dword ptr [EBP + -0x20],0x0` |
| `10019002` | `85 ff` | `TEST EDI,EDI` |
| `10019004` | `7e 6d` | `JLE 0x10019073` |
| `10019006` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `10019009` | `8b 08` | `MOV ECX,dword ptr [EAX]` |
| `1001900b` | `83 f9 ff` | `CMP ECX,-0x1` |
| `1001900e` | `74 56` | `JZ 0x10019066` |
| `10019010` | `83 f9 fe` | `CMP ECX,-0x2` |
| `10019013` | `74 51` | `JZ 0x10019066` |
| `10019015` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `10019017` | `a8 01` | `TEST AL,0x1` |
| `10019019` | `74 4b` | `JZ 0x10019066` |
| `1001901b` | `a8 08` | `TEST AL,0x8` |
| `1001901d` | `75 0b` | `JNZ 0x1001902a` |
| `1001901f` | `51` | `PUSH ECX` |
| `10019020` | `ff 15 fc e0 02 10` | `CALL dword ptr [0x1002e0fc]` |
| `10019026` | `85 c0` | `TEST EAX,EAX` |
| `10019028` | `74 3c` | `JZ 0x10019066` |
| `1001902a` | `8b 75 e0` | `MOV ESI,dword ptr [EBP + -0x20]` |
| `1001902d` | `8b c6` | `MOV EAX,ESI` |
| `1001902f` | `c1 f8 05` | `SAR EAX,0x5` |
| `10019032` | `83 e6 1f` | `AND ESI,0x1f` |
| `10019035` | `c1 e6 06` | `SHL ESI,0x6` |
| `10019038` | `03 34 85 40 95 43 13` | `ADD ESI,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001903f` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `10019042` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `10019044` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10019046` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `10019048` | `88 46 04` | `MOV byte ptr [ESI + 0x4],AL` |
| `1001904b` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `10019050` | `8d 46 0c` | `LEA EAX,[ESI + 0xc]` |
| `10019053` | `50` | `PUSH EAX` |
| `10019054` | `e8 9a 08 00 00` | `CALL 0x100198f3` |
| `10019059` | `59` | `POP ECX` |
| `1001905a` | `59` | `POP ECX` |
| `1001905b` | `85 c0` | `TEST EAX,EAX` |
| `1001905d` | `0f 84 c9 00 00 00` | `JZ 0x1001912c` |
| `10019063` | `ff 46 08` | `INC dword ptr [ESI + 0x8]` |
| `10019066` | `ff 45 e0` | `INC dword ptr [EBP + -0x20]` |
| `10019069` | `43` | `INC EBX` |
| `1001906a` | `83 45 e4 04` | `ADD dword ptr [EBP + -0x1c],0x4` |
| `1001906e` | `39 7d e0` | `CMP dword ptr [EBP + -0x20],EDI` |
| `10019071` | `7c 93` | `JL 0x10019006` |
| `10019073` | `33 db` | `XOR EBX,EBX` |
| `10019075` | `8b f3` | `MOV ESI,EBX` |
| `10019077` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001907a` | `03 35 40 95 43 13` | `ADD ESI,dword ptr [0x13439540]` |
| `10019080` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019082` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10019085` | `74 0b` | `JZ 0x10019092` |
| `10019087` | `83 f8 fe` | `CMP EAX,-0x2` |
| `1001908a` | `74 06` | `JZ 0x10019092` |
| `1001908c` | `80 4e 04 80` | `OR byte ptr [ESI + 0x4],0x80` |
| `10019090` | `eb 72` | `JMP 0x10019104` |
| `10019092` | `c6 46 04 81` | `MOV byte ptr [ESI + 0x4],0x81` |
| `10019096` | `85 db` | `TEST EBX,EBX` |
| `10019098` | `75 05` | `JNZ 0x1001909f` |
| `1001909a` | `6a f6` | `PUSH -0xa` |
| `1001909c` | `58` | `POP EAX` |
| `1001909d` | `eb 0a` | `JMP 0x100190a9` |
| `1001909f` | `8b c3` | `MOV EAX,EBX` |
| `100190a1` | `48` | `DEC EAX` |
| `100190a2` | `f7 d8` | `NEG EAX` |
| `100190a4` | `1b c0` | `SBB EAX,EAX` |
| `100190a6` | `83 c0 f5` | `ADD EAX,-0xb` |
| `100190a9` | `50` | `PUSH EAX` |
| `100190aa` | `ff 15 d0 e0 02 10` | `CALL dword ptr [0x1002e0d0]` |
| `100190b0` | `8b f8` | `MOV EDI,EAX` |
| `100190b2` | `83 ff ff` | `CMP EDI,-0x1` |
| `100190b5` | `74 43` | `JZ 0x100190fa` |
| `100190b7` | `85 ff` | `TEST EDI,EDI` |
| `100190b9` | `74 3f` | `JZ 0x100190fa` |
| `100190bb` | `57` | `PUSH EDI` |
| `100190bc` | `ff 15 fc e0 02 10` | `CALL dword ptr [0x1002e0fc]` |
| `100190c2` | `85 c0` | `TEST EAX,EAX` |
| `100190c4` | `74 34` | `JZ 0x100190fa` |
| `100190c6` | `89 3e` | `MOV dword ptr [ESI],EDI` |
| `100190c8` | `25 ff 00 00 00` | `AND EAX,0xff` |
| `100190cd` | `83 f8 02` | `CMP EAX,0x2` |
| `100190d0` | `75 06` | `JNZ 0x100190d8` |
| `100190d2` | `80 4e 04 40` | `OR byte ptr [ESI + 0x4],0x40` |
| `100190d6` | `eb 09` | `JMP 0x100190e1` |
| `100190d8` | `83 f8 03` | `CMP EAX,0x3` |
| `100190db` | `75 04` | `JNZ 0x100190e1` |
| `100190dd` | `80 4e 04 08` | `OR byte ptr [ESI + 0x4],0x8` |
| `100190e1` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `100190e6` | `8d 46 0c` | `LEA EAX,[ESI + 0xc]` |
| `100190e9` | `50` | `PUSH EAX` |
| `100190ea` | `e8 04 08 00 00` | `CALL 0x100198f3` |
| `100190ef` | `59` | `POP ECX` |
| `100190f0` | `59` | `POP ECX` |
| `100190f1` | `85 c0` | `TEST EAX,EAX` |
| `100190f3` | `74 37` | `JZ 0x1001912c` |
| `100190f5` | `ff 46 08` | `INC dword ptr [ESI + 0x8]` |
| `100190f8` | `eb 0a` | `JMP 0x10019104` |
| `100190fa` | `80 4e 04 40` | `OR byte ptr [ESI + 0x4],0x40` |
| `100190fe` | `c7 06 fe ff ff ff` | `MOV dword ptr [ESI],0xfffffffe` |
| `10019104` | `43` | `INC EBX` |
| `10019105` | `83 fb 03` | `CMP EBX,0x3` |
| `10019108` | `0f 8c 67 ff ff ff` | `JL 0x10019075` |
| `1001910e` | `ff 35 30 95 43 13` | `PUSH dword ptr [0x13439530]` |
| `10019114` | `ff 15 f8 e0 02 10` | `CALL dword ptr [0x1002e0f8]` |
| `1001911a` | `33 c0` | `XOR EAX,EAX` |
| `1001911c` | `eb 11` | `JMP 0x1001912f` |
| `1001912c` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001912f` | `e8 0d dc ff ff` | `CALL 0x10016d41` |
| `10019134` | `c3` | `RET` |
