# 1001d7f3 `__mbsnbcmp_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d7f3 |
| `name` | __mbsnbcmp_l |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbcmp_l(uchar * _Str1, uchar * _Str2, size_t _MaxCount, _locale_t _Locale) |
| `size_bytes` | 362 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbcmp_l |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbcmp_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbcmp_l(uchar *_Str1,uchar *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  size_t sVar1;
  uchar *puVar2;
  byte bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  ushort uVar7;
  byte *pbVar8;
  _LocaleUpdate local_14 [4];
  int local_10;
  int local_c;
  char local_8;
  
  if (_MaxCount == 0) {
    iVar4 = 0;
  }
  else {
    _LocaleUpdate::_LocaleUpdate(local_14,_Locale);
    if (*(int *)(local_10 + 8) == 0) {
      iVar4 = _strncmp((char *)_Str1,(char *)_Str2,_MaxCount);
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
    }
    else if (_Str1 == (uchar *)0x0) {
      piVar5 = __errno();
      *piVar5 = 0x16;
      __invalid_parameter(0,0,0,0,0);
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar4 = 0x7fffffff;
    }
    else {
      if (_Str2 != (uchar *)0x0) {
        do {
          bVar3 = *_Str1;
          uVar7 = (ushort)bVar3;
          sVar1 = _MaxCount - 1;
          puVar2 = _Str1 + 1;
          if ((*(byte *)(bVar3 + 0x1d + local_10) & 4) == 0) {
LAB_1001d902:
            _Str1 = puVar2;
            uVar6 = (uint)*_Str2;
            pbVar8 = _Str2 + 1;
            if ((*(byte *)(uVar6 + 0x1d + local_10) & 4) != 0) {
              if (sVar1 != 0) {
                sVar1 = _MaxCount - 2;
                if (*pbVar8 != 0) {
                  uVar6 = (uint)CONCAT11(*_Str2,*pbVar8);
                  pbVar8 = _Str2 + 2;
                  goto LAB_1001d934;
                }
              }
              _MaxCount = sVar1;
              uVar6 = 0;
              sVar1 = _MaxCount;
            }
          }
          else {
            if (sVar1 != 0) {
              if (*puVar2 == '\0') {
                uVar7 = 0;
              }
              else {
                uVar7 = CONCAT11(bVar3,*puVar2);
                puVar2 = _Str1 + 2;
              }
              goto LAB_1001d902;
            }
            uVar6 = (uint)*_Str2;
            uVar7 = 0;
            pbVar8 = _Str2;
            _Str1 = puVar2;
            if ((*(byte *)(uVar6 + 0x1d + local_10) & 4) != 0) {
LAB_1001d8d2:
              if (local_8 != '\0') {
                *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
              }
              return 0;
            }
          }
LAB_1001d934:
          _MaxCount = sVar1;
          if ((ushort)uVar6 != uVar7) {
            iVar4 = (-(uint)((ushort)uVar6 < uVar7) & 2) - 1;
            if (local_8 == '\0') {
              return iVar4;
            }
            *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
            return iVar4;
          }
          if ((uVar7 == 0) || (_Str2 = pbVar8, _MaxCount == 0)) goto LAB_1001d8d2;
        } while( true );
      }
      piVar5 = __errno();
      *piVar5 = 0x16;
      __invalid_parameter(0,0,0,0,0);
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar4 = 0x7fffffff;
    }
  }
  return iVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d811` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001d827` | `1001f216` | `UNCONDITIONAL_CALL` | _strncmp | `1001f216` |
| `1001d849` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d859` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001d87c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d88c` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `1001d96d` | __mbsnbcmp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d7f3` | `8b ff` | `MOV EDI,EDI` |
| `1001d7f5` | `55` | `PUSH EBP` |
| `1001d7f6` | `8b ec` | `MOV EBP,ESP` |
| `1001d7f8` | `83 ec 10` | `SUB ESP,0x10` |
| `1001d7fb` | `53` | `PUSH EBX` |
| `1001d7fc` | `33 db` | `XOR EBX,EBX` |
| `1001d7fe` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d801` | `75 07` | `JNZ 0x1001d80a` |
| `1001d803` | `33 c0` | `XOR EAX,EAX` |
| `1001d805` | `e9 d8 00 00 00` | `JMP 0x1001d8e2` |
| `1001d80a` | `57` | `PUSH EDI` |
| `1001d80b` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001d80e` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001d811` | `e8 a0 7a ff ff` | `CALL 0x100152b6` |
| `1001d816` | `8b 7d f4` | `MOV EDI,dword ptr [EBP + -0xc]` |
| `1001d819` | `39 5f 08` | `CMP dword ptr [EDI + 0x8],EBX` |
| `1001d81c` | `75 26` | `JNZ 0x1001d844` |
| `1001d81e` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d821` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d824` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d827` | `e8 ea 19 00 00` | `CALL 0x1001f216` |
| `1001d82c` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d82f` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001d832` | `0f 84 a9 00 00 00` | `JZ 0x1001d8e1` |
| `1001d838` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001d83b` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001d83f` | `e9 9d 00 00 00` | `JMP 0x1001d8e1` |
| `1001d844` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001d847` | `75 2b` | `JNZ 0x1001d874` |
| `1001d849` | `e8 bb 78 ff ff` | `CALL 0x10015109` |
| `1001d84e` | `53` | `PUSH EBX` |
| `1001d84f` | `53` | `PUSH EBX` |
| `1001d850` | `53` | `PUSH EBX` |
| `1001d851` | `53` | `PUSH EBX` |
| `1001d852` | `53` | `PUSH EBX` |
| `1001d853` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001d859` | `e8 51 3e ff ff` | `CALL 0x100116af` |
| `1001d85e` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d861` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001d864` | `74 07` | `JZ 0x1001d86d` |
| `1001d866` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001d869` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d86d` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001d872` | `eb 6d` | `JMP 0x1001d8e1` |
| `1001d874` | `56` | `PUSH ESI` |
| `1001d875` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001d878` | `3b f3` | `CMP ESI,EBX` |
| `1001d87a` | `75 2b` | `JNZ 0x1001d8a7` |
| `1001d87c` | `e8 88 78 ff ff` | `CALL 0x10015109` |
| `1001d881` | `53` | `PUSH EBX` |
| `1001d882` | `53` | `PUSH EBX` |
| `1001d883` | `53` | `PUSH EBX` |
| `1001d884` | `53` | `PUSH EBX` |
| `1001d885` | `53` | `PUSH EBX` |
| `1001d886` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001d88c` | `e8 1e 3e ff ff` | `CALL 0x100116af` |
| `1001d891` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d894` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001d897` | `74 07` | `JZ 0x1001d8a0` |
| `1001d899` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001d89c` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d8a0` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001d8a5` | `eb 39` | `JMP 0x1001d8e0` |
| `1001d8a7` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001d8aa` | `66 0f b6 00` | `MOVZX AX,byte ptr [EAX]` |
| `1001d8ae` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001d8b1` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1001d8b4` | `0f b7 c8` | `MOVZX ECX,AX` |
| `1001d8b7` | `0f b6 c1` | `MOVZX EAX,CL` |
| `1001d8ba` | `f6 44 38 1d 04` | `TEST byte ptr [EAX + EDI*0x1 + 0x1d],0x4` |
| `1001d8bf` | `74 41` | `JZ 0x1001d902` |
| `1001d8c1` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d8c4` | `75 1f` | `JNZ 0x1001d8e5` |
| `1001d8c6` | `0f b6 06` | `MOVZX EAX,byte ptr [ESI]` |
| `1001d8c9` | `33 c9` | `XOR ECX,ECX` |
| `1001d8cb` | `f6 44 38 1d 04` | `TEST byte ptr [EAX + EDI*0x1 + 0x1d],0x4` |
| `1001d8d0` | `74 5f` | `JZ 0x1001d931` |
| `1001d8d2` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001d8d5` | `74 07` | `JZ 0x1001d8de` |
| `1001d8d7` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001d8da` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d8de` | `33 c0` | `XOR EAX,EAX` |
| `1001d8e0` | `5e` | `POP ESI` |
| `1001d8e1` | `5f` | `POP EDI` |
| `1001d8e2` | `5b` | `POP EBX` |
| `1001d8e3` | `c9` | `LEAVE` |
| `1001d8e4` | `c3` | `RET` |
| `1001d8e5` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001d8e8` | `8a 00` | `MOV AL,byte ptr [EAX]` |
| `1001d8ea` | `3a c3` | `CMP AL,BL` |
| `1001d8ec` | `75 04` | `JNZ 0x1001d8f2` |
| `1001d8ee` | `33 c9` | `XOR ECX,ECX` |
| `1001d8f0` | `eb 10` | `JMP 0x1001d902` |
| `1001d8f2` | `c1 e1 08` | `SHL ECX,0x8` |
| `1001d8f5` | `66 0f b6 c0` | `MOVZX AX,AL` |
| `1001d8f9` | `66 0b c8` | `OR CX,AX` |
| `1001d8fc` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1001d8ff` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d902` | `66 0f b6 06` | `MOVZX AX,byte ptr [ESI]` |
| `1001d906` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1001d909` | `0f b6 d0` | `MOVZX EDX,AL` |
| `1001d90c` | `46` | `INC ESI` |
| `1001d90d` | `f6 44 3a 1d 04` | `TEST byte ptr [EDX + EDI*0x1 + 0x1d],0x4` |
| `1001d912` | `74 20` | `JZ 0x1001d934` |
| `1001d914` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d917` | `75 04` | `JNZ 0x1001d91d` |
| `1001d919` | `33 c0` | `XOR EAX,EAX` |
| `1001d91b` | `eb 17` | `JMP 0x1001d934` |
| `1001d91d` | `8a 16` | `MOV DL,byte ptr [ESI]` |
| `1001d91f` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001d922` | `3a d3` | `CMP DL,BL` |
| `1001d924` | `74 f3` | `JZ 0x1001d919` |
| `1001d926` | `66 0f b6 d2` | `MOVZX DX,DL` |
| `1001d92a` | `c1 e0 08` | `SHL EAX,0x8` |
| `1001d92d` | `66 0b c2` | `OR AX,DX` |
| `1001d930` | `46` | `INC ESI` |
| `1001d931` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1001d934` | `66 3b c1` | `CMP AX,CX` |
| `1001d937` | `75 10` | `JNZ 0x1001d949` |
| `1001d939` | `66 3b cb` | `CMP CX,BX` |
| `1001d93c` | `74 94` | `JZ 0x1001d8d2` |
| `1001d93e` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d941` | `0f 85 60 ff ff ff` | `JNZ 0x1001d8a7` |
| `1001d947` | `eb 89` | `JMP 0x1001d8d2` |
| `1001d949` | `1b c0` | `SBB EAX,EAX` |
| `1001d94b` | `83 e0 02` | `AND EAX,0x2` |
| `1001d94e` | `48` | `DEC EAX` |
| `1001d94f` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001d952` | `74 8c` | `JZ 0x1001d8e0` |
| `1001d954` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001d957` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001d95b` | `eb 83` | `JMP 0x1001d8e0` |
