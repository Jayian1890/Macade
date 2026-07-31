# 1001e40d `___crtsetenv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e40d |
| `name` | ___crtsetenv |
| `namespace` | Global |
| `signature` | int __cdecl ___crtsetenv(char * * _POption, int _Primary) |
| `size_bytes` | 584 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtsetenv |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtsetenv
   
   Library: Visual Studio 2008 Release */

int __cdecl ___crtsetenv(char **_POption,int _Primary)

{
  uint _Size;
  uchar *_Str;
  int *piVar1;
  uchar *puVar2;
  int iVar3;
  uint _Count;
  size_t sVar4;
  char *_Dst;
  errno_t eVar5;
  BOOL BVar6;
  int *piVar7;
  bool bVar8;
  size_t _Size_00;
  uchar *_Src;
  int local_10;
  
  local_10 = 0;
  if (_POption == (char **)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    return -1;
  }
  _Str = (uchar *)*_POption;
  if (((_Str == (uchar *)0x0) || (puVar2 = __mbschr(_Str,0x3d), puVar2 == (uchar *)0x0)) ||
     (_Str == puVar2)) {
LAB_1001e49d:
    piVar1 = __errno();
    *piVar1 = 0x16;
    return -1;
  }
  bVar8 = puVar2[1] == '\0';
  if (DAT_10038a4c == DAT_10038a50) {
    DAT_10038a4c = (int *)copy_environ();
  }
  if (DAT_10038a4c == (int *)0x0) {
    if ((_Primary == 0) || (DAT_10038a54 == (undefined4 *)0x0)) {
      if (bVar8) {
        return 0;
      }
      DAT_10038a4c = __malloc_crt(4);
      if (DAT_10038a4c == (int *)0x0) {
        return -1;
      }
      *DAT_10038a4c = 0;
      if (DAT_10038a54 == (undefined4 *)0x0) {
        DAT_10038a54 = __malloc_crt(4);
        if (DAT_10038a54 == (undefined4 *)0x0) {
          return -1;
        }
        *DAT_10038a54 = 0;
      }
    }
    else {
      iVar3 = ___wtomb_environ();
      if (iVar3 != 0) goto LAB_1001e49d;
    }
  }
  piVar1 = DAT_10038a4c;
  if (DAT_10038a4c == (int *)0x0) {
    return -1;
  }
  _Count = findenv(_Str);
  if (((int)_Count < 0) || (*piVar1 == 0)) {
    if (bVar8) {
      _free(_Str);
      *_POption = (char *)0x0;
      return 0;
    }
    if ((int)_Count < 0) {
      _Count = -_Count;
    }
    _Size = _Count + 2;
    if ((int)_Size < (int)_Count) {
      return -1;
    }
    if (0x3ffffffe < _Size) {
      return -1;
    }
    piVar1 = __recalloc_crt(DAT_10038a4c,4,_Size);
    if (piVar1 == (int *)0x0) {
      return -1;
    }
    piVar1[_Count] = (int)_Str;
    (piVar1 + _Count)[1] = 0;
    *_POption = (char *)0x0;
  }
  else {
    piVar7 = piVar1 + _Count;
    _free((void *)*piVar7);
    if (!bVar8) {
      *piVar7 = (int)_Str;
      *_POption = (char *)0x0;
      goto LAB_1001e5ab;
    }
    while (*piVar7 != 0) {
      *piVar7 = piVar7[1];
      _Count = _Count + 1;
      piVar7 = piVar1 + _Count;
    }
    if ((0x3ffffffe < _Count) ||
       (piVar1 = __recalloc_crt(DAT_10038a4c,_Count,4), piVar1 == (int *)0x0)) goto LAB_1001e5ab;
  }
  DAT_10038a4c = piVar1;
LAB_1001e5ab:
  if (_Primary != 0) {
    _Size_00 = 1;
    sVar4 = _strlen((char *)_Str);
    _Dst = __calloc_crt(sVar4 + 2,_Size_00);
    if (_Dst != (char *)0x0) {
      _Src = _Str;
      sVar4 = _strlen((char *)_Str);
      eVar5 = _strcpy_s(_Dst,sVar4 + 2,(char *)_Src);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      puVar2[(int)_Dst - (int)_Str] = '\0';
      BVar6 = SetEnvironmentVariableA
                        (_Dst,(LPCSTR)(~-(uint)bVar8 & (uint)(puVar2 + ((int)_Dst - (int)_Str) + 1))
                        );
      if (BVar6 == 0) {
        local_10 = -1;
        piVar1 = __errno();
        *piVar1 = 0x2a;
      }
      _free(_Dst);
    }
  }
  if (bVar8) {
    _free(_Str);
    *_POption = (char *)0x0;
    return local_10;
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e422` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e432` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001e44d` | `1001faca` | `UNCONDITIONAL_CALL` | __mbschr | `1001faca` |
| `1001e479` | `1001e3b3` | `UNCONDITIONAL_CALL` | copy_environ | `1001e3b3` |
| `1001e494` | `10019b2b` | `UNCONDITIONAL_CALL` | ___wtomb_environ | `10019b2b` |
| `1001e49d` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e4bb` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001e4d6` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001e4fa` | `1001e361` | `UNCONDITIONAL_CALL` | findenv | `1001e361` |
| `1001e50f` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e54a` | `1001a5ae` | `UNCONDITIONAL_CALL` | __recalloc_crt | `1001a5ae` |
| `1001e586` | `1001a5ae` | `UNCONDITIONAL_CALL` | __recalloc_crt | `1001a5ae` |
| `1001e5b6` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001e5bf` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001e5ce` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001e5d8` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1001e5e9` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1001e608` | `EXTERNAL:0000001c` | `COMPUTED_CALL` | KERNEL32.DLL::SetEnvironmentVariableA | `` |
| `1001e616` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e622` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e630` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e646` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `10019b86` | ___wtomb_environ |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001e46c` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e471` | `10038a50` | `READ` | DAT_10038a50 |
| `1001e47e` | `10038a4c` | `WRITE` | DAT_10038a4c |
| `1001e48c` | `10038a54` | `READ` | DAT_10038a54 |
| `1001e4c1` | `10038a4c` | `WRITE` | DAT_10038a4c |
| `1001e4cc` | `10038a54` | `READ` | DAT_10038a54 |
| `1001e4dc` | `10038a54` | `WRITE` | DAT_10038a54 |
| `1001e4e7` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e544` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e580` | `10038a4c` | `READ` | DAT_10038a4c |
| `1001e5a6` | `10038a4c` | `WRITE` | DAT_10038a4c |
| `1001e608` | `1002e028` | `READ` | PTR_SetEnvironmentVariableA_1002e028 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e40d` | `8b ff` | `MOV EDI,EDI` |
| `1001e40f` | `55` | `PUSH EBP` |
| `1001e410` | `8b ec` | `MOV EBP,ESP` |
| `1001e412` | `83 ec 14` | `SUB ESP,0x14` |
| `1001e415` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e418` | `53` | `PUSH EBX` |
| `1001e419` | `33 db` | `XOR EBX,EBX` |
| `1001e41b` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `1001e41e` | `3b c3` | `CMP EAX,EBX` |
| `1001e420` | `75 1d` | `JNZ 0x1001e43f` |
| `1001e422` | `e8 e2 6c ff ff` | `CALL 0x10015109` |
| `1001e427` | `53` | `PUSH EBX` |
| `1001e428` | `53` | `PUSH EBX` |
| `1001e429` | `53` | `PUSH EBX` |
| `1001e42a` | `53` | `PUSH EBX` |
| `1001e42b` | `53` | `PUSH EBX` |
| `1001e42c` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001e432` | `e8 78 32 ff ff` | `CALL 0x100116af` |
| `1001e437` | `83 c4 14` | `ADD ESP,0x14` |
| `1001e43a` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001e43d` | `eb 6e` | `JMP 0x1001e4ad` |
| `1001e43f` | `56` | `PUSH ESI` |
| `1001e440` | `8b 30` | `MOV ESI,dword ptr [EAX]` |
| `1001e442` | `57` | `PUSH EDI` |
| `1001e443` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `1001e446` | `3b f3` | `CMP ESI,EBX` |
| `1001e448` | `74 53` | `JZ 0x1001e49d` |
| `1001e44a` | `6a 3d` | `PUSH 0x3d` |
| `1001e44c` | `56` | `PUSH ESI` |
| `1001e44d` | `e8 78 16 00 00` | `CALL 0x1001faca` |
| `1001e452` | `8b f8` | `MOV EDI,EAX` |
| `1001e454` | `59` | `POP ECX` |
| `1001e455` | `59` | `POP ECX` |
| `1001e456` | `89 7d ec` | `MOV dword ptr [EBP + -0x14],EDI` |
| `1001e459` | `3b fb` | `CMP EDI,EBX` |
| `1001e45b` | `74 40` | `JZ 0x1001e49d` |
| `1001e45d` | `3b f7` | `CMP ESI,EDI` |
| `1001e45f` | `74 3c` | `JZ 0x1001e49d` |
| `1001e461` | `33 c0` | `XOR EAX,EAX` |
| `1001e463` | `38 5f 01` | `CMP byte ptr [EDI + 0x1],BL` |
| `1001e466` | `0f 94 c0` | `SETZ AL` |
| `1001e469` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001e46c` | `a1 4c 8a 03 10` | `MOV EAX,[0x10038a4c]` |
| `1001e471` | `3b 05 50 8a 03 10` | `CMP EAX,dword ptr [0x10038a50]` |
| `1001e477` | `75 0a` | `JNZ 0x1001e483` |
| `1001e479` | `e8 35 ff ff ff` | `CALL 0x1001e3b3` |
| `1001e47e` | `a3 4c 8a 03 10` | `MOV [0x10038a4c],EAX` |
| `1001e483` | `3b c3` | `CMP EAX,EBX` |
| `1001e485` | `75 60` | `JNZ 0x1001e4e7` |
| `1001e487` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1001e48a` | `74 24` | `JZ 0x1001e4b0` |
| `1001e48c` | `39 1d 54 8a 03 10` | `CMP dword ptr [0x10038a54],EBX` |
| `1001e492` | `74 1c` | `JZ 0x1001e4b0` |
| `1001e494` | `e8 92 b6 ff ff` | `CALL 0x10019b2b` |
| `1001e499` | `85 c0` | `TEST EAX,EAX` |
| `1001e49b` | `74 4a` | `JZ 0x1001e4e7` |
| `1001e49d` | `e8 67 6c ff ff` | `CALL 0x10015109` |
| `1001e4a2` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001e4a8` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001e4ab` | `5f` | `POP EDI` |
| `1001e4ac` | `5e` | `POP ESI` |
| `1001e4ad` | `5b` | `POP EBX` |
| `1001e4ae` | `c9` | `LEAVE` |
| `1001e4af` | `c3` | `RET` |
| `1001e4b0` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `1001e4b3` | `0f 85 98 01 00 00` | `JNZ 0x1001e651` |
| `1001e4b9` | `6a 04` | `PUSH 0x4` |
| `1001e4bb` | `e8 0f c0 ff ff` | `CALL 0x1001a4cf` |
| `1001e4c0` | `59` | `POP ECX` |
| `1001e4c1` | `a3 4c 8a 03 10` | `MOV [0x10038a4c],EAX` |
| `1001e4c6` | `3b c3` | `CMP EAX,EBX` |
| `1001e4c8` | `74 de` | `JZ 0x1001e4a8` |
| `1001e4ca` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001e4cc` | `39 1d 54 8a 03 10` | `CMP dword ptr [0x10038a54],EBX` |
| `1001e4d2` | `75 13` | `JNZ 0x1001e4e7` |
| `1001e4d4` | `6a 04` | `PUSH 0x4` |
| `1001e4d6` | `e8 f4 bf ff ff` | `CALL 0x1001a4cf` |
| `1001e4db` | `59` | `POP ECX` |
| `1001e4dc` | `a3 54 8a 03 10` | `MOV [0x10038a54],EAX` |
| `1001e4e1` | `3b c3` | `CMP EAX,EBX` |
| `1001e4e3` | `74 c3` | `JZ 0x1001e4a8` |
| `1001e4e5` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001e4e7` | `8b 35 4c 8a 03 10` | `MOV ESI,dword ptr [0x10038a4c]` |
| `1001e4ed` | `89 75 f0` | `MOV dword ptr [EBP + -0x10],ESI` |
| `1001e4f0` | `3b f3` | `CMP ESI,EBX` |
| `1001e4f2` | `74 b4` | `JZ 0x1001e4a8` |
| `1001e4f4` | `2b 7d fc` | `SUB EDI,dword ptr [EBP + -0x4]` |
| `1001e4f7` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001e4fa` | `e8 62 fe ff ff` | `CALL 0x1001e361` |
| `1001e4ff` | `8b f8` | `MOV EDI,EAX` |
| `1001e501` | `3b fb` | `CMP EDI,EBX` |
| `1001e503` | `59` | `POP ECX` |
| `1001e504` | `7c 52` | `JL 0x1001e558` |
| `1001e506` | `39 1e` | `CMP dword ptr [ESI],EBX` |
| `1001e508` | `74 4e` | `JZ 0x1001e558` |
| `1001e50a` | `8d 34 be` | `LEA ESI,[ESI + EDI*0x4]` |
| `1001e50d` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001e50f` | `e8 2d 2d ff ff` | `CALL 0x10011241` |
| `1001e514` | `59` | `POP ECX` |
| `1001e515` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `1001e518` | `75 1b` | `JNZ 0x1001e535` |
| `1001e51a` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1001e51d` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001e51f` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e522` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001e524` | `e9 82 00 00 00` | `JMP 0x1001e5ab` |
| `1001e529` | `8b 46 04` | `MOV EAX,dword ptr [ESI + 0x4]` |
| `1001e52c` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001e52e` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e531` | `47` | `INC EDI` |
| `1001e532` | `8d 34 b8` | `LEA ESI,[EAX + EDI*0x4]` |
| `1001e535` | `39 1e` | `CMP dword ptr [ESI],EBX` |
| `1001e537` | `75 f0` | `JNZ 0x1001e529` |
| `1001e539` | `81 ff ff ff ff 3f` | `CMP EDI,0x3fffffff` |
| `1001e53f` | `73 6a` | `JNC 0x1001e5ab` |
| `1001e541` | `6a 04` | `PUSH 0x4` |
| `1001e543` | `57` | `PUSH EDI` |
| `1001e544` | `ff 35 4c 8a 03 10` | `PUSH dword ptr [0x10038a4c]` |
| `1001e54a` | `e8 5f c0 ff ff` | `CALL 0x1001a5ae` |
| `1001e54f` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001e552` | `3b c3` | `CMP EAX,EBX` |
| `1001e554` | `74 55` | `JZ 0x1001e5ab` |
| `1001e556` | `eb 4e` | `JMP 0x1001e5a6` |
| `1001e558` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `1001e55b` | `0f 85 e2 00 00 00` | `JNZ 0x1001e643` |
| `1001e561` | `3b fb` | `CMP EDI,EBX` |
| `1001e563` | `7d 02` | `JGE 0x1001e567` |
| `1001e565` | `f7 df` | `NEG EDI` |
| `1001e567` | `8d 47 02` | `LEA EAX,[EDI + 0x2]` |
| `1001e56a` | `3b c7` | `CMP EAX,EDI` |
| `1001e56c` | `0f 8c 36 ff ff ff` | `JL 0x1001e4a8` |
| `1001e572` | `3d ff ff ff 3f` | `CMP EAX,0x3fffffff` |
| `1001e577` | `0f 83 2b ff ff ff` | `JNC 0x1001e4a8` |
| `1001e57d` | `50` | `PUSH EAX` |
| `1001e57e` | `6a 04` | `PUSH 0x4` |
| `1001e580` | `ff 35 4c 8a 03 10` | `PUSH dword ptr [0x10038a4c]` |
| `1001e586` | `e8 23 c0 ff ff` | `CALL 0x1001a5ae` |
| `1001e58b` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001e58e` | `3b c3` | `CMP EAX,EBX` |
| `1001e590` | `0f 84 12 ff ff ff` | `JZ 0x1001e4a8` |
| `1001e596` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `1001e599` | `8d 0c b8` | `LEA ECX,[EAX + EDI*0x4]` |
| `1001e59c` | `89 11` | `MOV dword ptr [ECX],EDX` |
| `1001e59e` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `1001e5a1` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001e5a4` | `89 19` | `MOV dword ptr [ECX],EBX` |
| `1001e5a6` | `a3 4c 8a 03 10` | `MOV [0x10038a4c],EAX` |
| `1001e5ab` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1001e5ae` | `74 78` | `JZ 0x1001e628` |
| `1001e5b0` | `8b 75 fc` | `MOV ESI,dword ptr [EBP + -0x4]` |
| `1001e5b3` | `6a 01` | `PUSH 0x1` |
| `1001e5b5` | `56` | `PUSH ESI` |
| `1001e5b6` | `e8 35 2e ff ff` | `CALL 0x100113f0` |
| `1001e5bb` | `40` | `INC EAX` |
| `1001e5bc` | `59` | `POP ECX` |
| `1001e5bd` | `40` | `INC EAX` |
| `1001e5be` | `50` | `PUSH EAX` |
| `1001e5bf` | `e8 50 bf ff ff` | `CALL 0x1001a514` |
| `1001e5c4` | `8b f8` | `MOV EDI,EAX` |
| `1001e5c6` | `59` | `POP ECX` |
| `1001e5c7` | `59` | `POP ECX` |
| `1001e5c8` | `3b fb` | `CMP EDI,EBX` |
| `1001e5ca` | `74 5c` | `JZ 0x1001e628` |
| `1001e5cc` | `56` | `PUSH ESI` |
| `1001e5cd` | `56` | `PUSH ESI` |
| `1001e5ce` | `e8 1d 2e ff ff` | `CALL 0x100113f0` |
| `1001e5d3` | `40` | `INC EAX` |
| `1001e5d4` | `59` | `POP ECX` |
| `1001e5d5` | `40` | `INC EAX` |
| `1001e5d6` | `50` | `PUSH EAX` |
| `1001e5d7` | `57` | `PUSH EDI` |
| `1001e5d8` | `e8 9e 79 ff ff` | `CALL 0x10015f7b` |
| `1001e5dd` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001e5e0` | `85 c0` | `TEST EAX,EAX` |
| `1001e5e2` | `74 0d` | `JZ 0x1001e5f1` |
| `1001e5e4` | `53` | `PUSH EBX` |
| `1001e5e5` | `53` | `PUSH EBX` |
| `1001e5e6` | `53` | `PUSH EBX` |
| `1001e5e7` | `53` | `PUSH EBX` |
| `1001e5e8` | `53` | `PUSH EBX` |
| `1001e5e9` | `e8 99 2f ff ff` | `CALL 0x10011587` |
| `1001e5f1` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001e5f4` | `8b c7` | `MOV EAX,EDI` |
| `1001e5f6` | `2b c6` | `SUB EAX,ESI` |
| `1001e5f8` | `03 45 ec` | `ADD EAX,dword ptr [EBP + -0x14]` |
| `1001e5fb` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1001e5fd` | `40` | `INC EAX` |
| `1001e5fe` | `f7 d9` | `NEG ECX` |
| `1001e600` | `1b c9` | `SBB ECX,ECX` |
| `1001e602` | `f7 d1` | `NOT ECX` |
| `1001e604` | `23 c8` | `AND ECX,EAX` |
| `1001e606` | `51` | `PUSH ECX` |
| `1001e607` | `57` | `PUSH EDI` |
| `1001e608` | `ff 15 28 e0 02 10` | `CALL dword ptr [0x1002e028]` |
| `1001e60e` | `85 c0` | `TEST EAX,EAX` |
| `1001e610` | `75 0f` | `JNZ 0x1001e621` |
| `1001e612` | `83 4d f4 ff` | `OR dword ptr [EBP + -0xc],0xffffffff` |
| `1001e616` | `e8 ee 6a ff ff` | `CALL 0x10015109` |
| `1001e61b` | `c7 00 2a 00 00 00` | `MOV dword ptr [EAX],0x2a` |
| `1001e621` | `57` | `PUSH EDI` |
| `1001e622` | `e8 1a 2c ff ff` | `CALL 0x10011241` |
| `1001e627` | `59` | `POP ECX` |
| `1001e628` | `39 5d f8` | `CMP dword ptr [EBP + -0x8],EBX` |
| `1001e62b` | `74 0e` | `JZ 0x1001e63b` |
| `1001e62d` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001e630` | `e8 0c 2c ff ff` | `CALL 0x10011241` |
| `1001e635` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e638` | `59` | `POP ECX` |
| `1001e639` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001e63b` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1001e63e` | `e9 68 fe ff ff` | `JMP 0x1001e4ab` |
| `1001e643` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001e646` | `e8 f6 2b ff ff` | `CALL 0x10011241` |
| `1001e64b` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001e64e` | `59` | `POP ECX` |
| `1001e64f` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001e651` | `33 c0` | `XOR EAX,EAX` |
| `1001e653` | `e9 53 fe ff ff` | `JMP 0x1001e4ab` |
