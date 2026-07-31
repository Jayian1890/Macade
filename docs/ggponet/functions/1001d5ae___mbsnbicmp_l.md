# 1001d5ae `__mbsnbicmp_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d5ae |
| `name` | __mbsnbicmp_l |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbicmp_l(uchar * _Str1, uchar * _Str2, size_t _MaxCount, _locale_t _Locale) |
| `size_bytes` | 555 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbicmp_l |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbicmp_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbicmp_l(uchar *_Str1,uchar *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  size_t sVar1;
  uchar *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  byte *pbVar6;
  _LocaleUpdate local_1c [4];
  int local_18;
  int local_14;
  char local_10;
  ushort local_c;
  ushort local_8;
  
  _LocaleUpdate::_LocaleUpdate(local_1c,_Locale);
  if (_MaxCount == 0) {
    if (local_10 != '\0') {
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
    }
    iVar3 = 0;
  }
  else if (*(int *)(local_18 + 8) == 0) {
    iVar3 = __strnicmp((char *)_Str1,(char *)_Str2,_MaxCount);
    if (local_10 != '\0') {
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
    }
  }
  else if (_Str1 == (uchar *)0x0) {
    piVar4 = __errno();
    *piVar4 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_10 != '\0') {
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
    }
    iVar3 = 0x7fffffff;
  }
  else {
    if (_Str2 != (uchar *)0x0) {
      do {
        uVar5 = (uint)*_Str1;
        sVar1 = _MaxCount - 1;
        puVar2 = _Str1 + 1;
        if ((*(byte *)(uVar5 + 0x1d + local_18) & 4) == 0) {
          if ((*(byte *)(uVar5 + local_18 + 0x1d) & 0x10) != 0) {
            uVar5 = (uint)*(byte *)(uVar5 + local_18 + 0x11d);
          }
          local_c = (ushort)uVar5;
          _Str1 = puVar2;
LAB_1001d71e:
          uVar5 = (uint)*_Str2;
          pbVar6 = _Str2 + 1;
          if ((*(byte *)(uVar5 + 0x1d + local_18) & 4) == 0) {
            if ((*(byte *)(uVar5 + local_18 + 0x1d) & 0x10) != 0) {
              uVar5 = (uint)*(byte *)(uVar5 + local_18 + 0x11d);
            }
            goto LAB_1001d798;
          }
          if (sVar1 == 0) {
LAB_1001d738:
            _MaxCount = sVar1;
            local_8 = 0;
          }
          else {
            sVar1 = _MaxCount - 2;
            if (*pbVar6 == 0) goto LAB_1001d738;
            local_8 = CONCAT11(*_Str2,*pbVar6);
            pbVar6 = _Str2 + 2;
            _MaxCount = sVar1;
            if ((local_8 < *(ushort *)(local_18 + 0x10)) || (*(ushort *)(local_18 + 0x12) < local_8)
               ) {
              if ((*(ushort *)(local_18 + 0x16) <= local_8) &&
                 (local_8 <= *(ushort *)(local_18 + 0x18))) {
                local_8 = local_8 + *(short *)(local_18 + 0x1a);
              }
            }
            else {
              local_8 = local_8 + *(short *)(local_18 + 0x14);
            }
          }
        }
        else {
          if (sVar1 != 0) {
            if (*puVar2 == '\0') {
              local_c = 0;
              _Str1 = puVar2;
            }
            else {
              local_c = CONCAT11(*_Str1,*puVar2);
              _Str1 = _Str1 + 2;
              if ((local_c < *(ushort *)(local_18 + 0x10)) ||
                 (*(ushort *)(local_18 + 0x12) < local_c)) {
                if ((*(ushort *)(local_18 + 0x16) <= local_c) &&
                   (local_c <= *(ushort *)(local_18 + 0x18))) {
                  local_c = local_c + *(short *)(local_18 + 0x1a);
                }
              }
              else {
                local_c = local_c + *(short *)(local_18 + 0x14);
              }
            }
            goto LAB_1001d71e;
          }
          uVar5 = (uint)*_Str2;
          if ((*(byte *)(uVar5 + 0x1d + local_18) & 4) != 0) {
LAB_1001d7b2:
            if (local_10 != '\0') {
              *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
            }
            return 0;
          }
          local_c = 0;
          pbVar6 = _Str2;
          _Str1 = puVar2;
LAB_1001d798:
          local_8 = (ushort)uVar5;
          _MaxCount = sVar1;
        }
        if (local_8 != local_c) {
          iVar3 = (-(uint)(local_8 < local_c) & 2) - 1;
          if (local_10 == '\0') {
            return iVar3;
          }
          *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
          return iVar3;
        }
        if ((local_c == 0) || (_Str2 = pbVar6, _MaxCount == 0)) goto LAB_1001d7b2;
      } while( true );
    }
    piVar4 = __errno();
    *piVar4 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_10 != '\0') {
      *(uint *)(local_14 + 0x70) = *(uint *)(local_14 + 0x70) & 0xfffffffd;
    }
    iVar3 = 0x7fffffff;
  }
  return iVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d5bd` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001d5ed` | `1001f75e` | `UNCONDITIONAL_CALL` | __strnicmp | `1001f75e` |
| `1001d60f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d61f` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001d645` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d655` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `1001d7e9` | __mbsnbicmp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d5ae` | `8b ff` | `MOV EDI,EDI` |
| `1001d5b0` | `55` | `PUSH EBP` |
| `1001d5b1` | `8b ec` | `MOV EBP,ESP` |
| `1001d5b3` | `83 ec 18` | `SUB ESP,0x18` |
| `1001d5b6` | `53` | `PUSH EBX` |
| `1001d5b7` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001d5ba` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1001d5bd` | `e8 f4 7c ff ff` | `CALL 0x100152b6` |
| `1001d5c2` | `33 db` | `XOR EBX,EBX` |
| `1001d5c4` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d5c7` | `75 13` | `JNZ 0x1001d5dc` |
| `1001d5c9` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d5cc` | `74 07` | `JZ 0x1001d5d5` |
| `1001d5ce` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001d5d1` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d5d5` | `33 c0` | `XOR EAX,EAX` |
| `1001d5d7` | `e9 e6 01 00 00` | `JMP 0x1001d7c2` |
| `1001d5dc` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `1001d5df` | `39 58 08` | `CMP dword ptr [EAX + 0x8],EBX` |
| `1001d5e2` | `75 26` | `JNZ 0x1001d60a` |
| `1001d5e4` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d5e7` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d5ea` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d5ed` | `e8 6c 21 00 00` | `CALL 0x1001f75e` |
| `1001d5f2` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001d5f5` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d5f8` | `0f 84 c4 01 00 00` | `JZ 0x1001d7c2` |
| `1001d5fe` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001d601` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001d605` | `e9 b8 01 00 00` | `JMP 0x1001d7c2` |
| `1001d60a` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001d60d` | `75 2e` | `JNZ 0x1001d63d` |
| `1001d60f` | `e8 f5 7a ff ff` | `CALL 0x10015109` |
| `1001d614` | `53` | `PUSH EBX` |
| `1001d615` | `53` | `PUSH EBX` |
| `1001d616` | `53` | `PUSH EBX` |
| `1001d617` | `53` | `PUSH EBX` |
| `1001d618` | `53` | `PUSH EBX` |
| `1001d619` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001d61f` | `e8 8b 40 ff ff` | `CALL 0x100116af` |
| `1001d624` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d627` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d62a` | `74 07` | `JZ 0x1001d633` |
| `1001d62c` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001d62f` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d633` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001d638` | `e9 85 01 00 00` | `JMP 0x1001d7c2` |
| `1001d63d` | `57` | `PUSH EDI` |
| `1001d63e` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001d641` | `3b fb` | `CMP EDI,EBX` |
| `1001d643` | `75 2e` | `JNZ 0x1001d673` |
| `1001d645` | `e8 bf 7a ff ff` | `CALL 0x10015109` |
| `1001d64a` | `53` | `PUSH EBX` |
| `1001d64b` | `53` | `PUSH EBX` |
| `1001d64c` | `53` | `PUSH EBX` |
| `1001d64d` | `53` | `PUSH EBX` |
| `1001d64e` | `53` | `PUSH EBX` |
| `1001d64f` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001d655` | `e8 55 40 ff ff` | `CALL 0x100116af` |
| `1001d65a` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d65d` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d660` | `74 07` | `JZ 0x1001d669` |
| `1001d662` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001d665` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d669` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001d66e` | `e9 4e 01 00 00` | `JMP 0x1001d7c1` |
| `1001d673` | `56` | `PUSH ESI` |
| `1001d674` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001d677` | `66 0f b6 09` | `MOVZX CX,byte ptr [ECX]` |
| `1001d67b` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001d67e` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1001d681` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d684` | `0f b6 d1` | `MOVZX EDX,CL` |
| `1001d687` | `f6 44 02 1d 04` | `TEST byte ptr [EDX + EAX*0x1 + 0x1d],0x4` |
| `1001d68c` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1001d68f` | `74 69` | `JZ 0x1001d6fa` |
| `1001d691` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d694` | `75 1c` | `JNZ 0x1001d6b2` |
| `1001d696` | `0f b6 0f` | `MOVZX ECX,byte ptr [EDI]` |
| `1001d699` | `f6 44 01 1d 04` | `TEST byte ptr [ECX + EAX*0x1 + 0x1d],0x4` |
| `1001d69e` | `89 5d f8` | `MOV dword ptr [EBP + -0x8],EBX` |
| `1001d6a1` | `0f 85 0b 01 00 00` | `JNZ 0x1001d7b2` |
| `1001d6a7` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d6aa` | `66 8b f3` | `MOV SI,BX` |
| `1001d6ad` | `e9 e6 00 00 00` | `JMP 0x1001d798` |
| `1001d6b2` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `1001d6b5` | `8a 12` | `MOV DL,byte ptr [EDX]` |
| `1001d6b7` | `3a d3` | `CMP DL,BL` |
| `1001d6b9` | `75 05` | `JNZ 0x1001d6c0` |
| `1001d6bb` | `89 5d f8` | `MOV dword ptr [EBP + -0x8],EBX` |
| `1001d6be` | `eb 5a` | `JMP 0x1001d71a` |
| `1001d6c0` | `c1 e1 08` | `SHL ECX,0x8` |
| `1001d6c3` | `66 0f b6 d2` | `MOVZX DX,DL` |
| `1001d6c7` | `66 0b ca` | `OR CX,DX` |
| `1001d6ca` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1001d6cd` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d6d0` | `66 8b f1` | `MOV SI,CX` |
| `1001d6d3` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1001d6d6` | `66 3b 70 10` | `CMP SI,word ptr [EAX + 0x10]` |
| `1001d6da` | `72 0c` | `JC 0x1001d6e8` |
| `1001d6dc` | `66 3b 70 12` | `CMP SI,word ptr [EAX + 0x12]` |
| `1001d6e0` | `77 06` | `JA 0x1001d6e8` |
| `1001d6e2` | `66 03 70 14` | `ADD SI,word ptr [EAX + 0x14]` |
| `1001d6e6` | `eb 36` | `JMP 0x1001d71e` |
| `1001d6e8` | `66 3b 70 16` | `CMP SI,word ptr [EAX + 0x16]` |
| `1001d6ec` | `72 30` | `JC 0x1001d71e` |
| `1001d6ee` | `66 3b 70 18` | `CMP SI,word ptr [EAX + 0x18]` |
| `1001d6f2` | `77 2a` | `JA 0x1001d71e` |
| `1001d6f4` | `66 03 70 1a` | `ADD SI,word ptr [EAX + 0x1a]` |
| `1001d6f8` | `eb 24` | `JMP 0x1001d71e` |
| `1001d6fa` | `0f b7 55 f8` | `MOVZX EDX,word ptr [EBP + -0x8]` |
| `1001d6fe` | `8d 0c 02` | `LEA ECX,[EDX + EAX*0x1]` |
| `1001d701` | `f6 41 1d 10` | `TEST byte ptr [ECX + 0x1d],0x10` |
| `1001d705` | `74 0d` | `JZ 0x1001d714` |
| `1001d707` | `66 0f b6 89 1d 01 00 00` | `MOVZX CX,byte ptr [ECX + 0x11d]` |
| `1001d70f` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d712` | `eb 03` | `JMP 0x1001d717` |
| `1001d714` | `0f b7 ca` | `MOVZX ECX,DX` |
| `1001d717` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1001d71a` | `66 8b 75 f8` | `MOV SI,word ptr [EBP + -0x8]` |
| `1001d71e` | `66 0f b6 0f` | `MOVZX CX,byte ptr [EDI]` |
| `1001d722` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d725` | `0f b6 d1` | `MOVZX EDX,CL` |
| `1001d728` | `47` | `INC EDI` |
| `1001d729` | `f6 44 02 1d 04` | `TEST byte ptr [EDX + EAX*0x1 + 0x1d],0x4` |
| `1001d72e` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1001d731` | `74 48` | `JZ 0x1001d77b` |
| `1001d733` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d736` | `75 05` | `JNZ 0x1001d73d` |
| `1001d738` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001d73b` | `eb 5e` | `JMP 0x1001d79b` |
| `1001d73d` | `8a 17` | `MOV DL,byte ptr [EDI]` |
| `1001d73f` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001d742` | `3a d3` | `CMP DL,BL` |
| `1001d744` | `74 f2` | `JZ 0x1001d738` |
| `1001d746` | `c1 e1 08` | `SHL ECX,0x8` |
| `1001d749` | `66 0f b6 d2` | `MOVZX DX,DL` |
| `1001d74d` | `66 0b ca` | `OR CX,DX` |
| `1001d750` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d753` | `47` | `INC EDI` |
| `1001d754` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1001d757` | `66 3b 48 10` | `CMP CX,word ptr [EAX + 0x10]` |
| `1001d75b` | `72 0c` | `JC 0x1001d769` |
| `1001d75d` | `66 3b 48 12` | `CMP CX,word ptr [EAX + 0x12]` |
| `1001d761` | `77 06` | `JA 0x1001d769` |
| `1001d763` | `66 03 48 14` | `ADD CX,word ptr [EAX + 0x14]` |
| `1001d767` | `eb 36` | `JMP 0x1001d79f` |
| `1001d769` | `66 3b 48 16` | `CMP CX,word ptr [EAX + 0x16]` |
| `1001d76d` | `72 30` | `JC 0x1001d79f` |
| `1001d76f` | `66 3b 48 18` | `CMP CX,word ptr [EAX + 0x18]` |
| `1001d773` | `77 2a` | `JA 0x1001d79f` |
| `1001d775` | `66 03 48 1a` | `ADD CX,word ptr [EAX + 0x1a]` |
| `1001d779` | `eb 24` | `JMP 0x1001d79f` |
| `1001d77b` | `0f b7 55 fc` | `MOVZX EDX,word ptr [EBP + -0x4]` |
| `1001d77f` | `8d 0c 02` | `LEA ECX,[EDX + EAX*0x1]` |
| `1001d782` | `f6 41 1d 10` | `TEST byte ptr [ECX + 0x1d],0x10` |
| `1001d786` | `74 0d` | `JZ 0x1001d795` |
| `1001d788` | `66 0f b6 89 1d 01 00 00` | `MOVZX CX,byte ptr [ECX + 0x11d]` |
| `1001d790` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001d793` | `eb 03` | `JMP 0x1001d798` |
| `1001d795` | `0f b7 ca` | `MOVZX ECX,DX` |
| `1001d798` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1001d79b` | `66 8b 4d fc` | `MOV CX,word ptr [EBP + -0x4]` |
| `1001d79f` | `66 3b ce` | `CMP CX,SI` |
| `1001d7a2` | `75 21` | `JNZ 0x1001d7c5` |
| `1001d7a4` | `66 3b f3` | `CMP SI,BX` |
| `1001d7a7` | `74 09` | `JZ 0x1001d7b2` |
| `1001d7a9` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001d7ac` | `0f 85 c2 fe ff ff` | `JNZ 0x1001d674` |
| `1001d7b2` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d7b5` | `74 07` | `JZ 0x1001d7be` |
| `1001d7b7` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001d7ba` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001d7be` | `33 c0` | `XOR EAX,EAX` |
| `1001d7c0` | `5e` | `POP ESI` |
| `1001d7c1` | `5f` | `POP EDI` |
| `1001d7c2` | `5b` | `POP EBX` |
| `1001d7c3` | `c9` | `LEAVE` |
| `1001d7c4` | `c3` | `RET` |
| `1001d7c5` | `1b c0` | `SBB EAX,EAX` |
| `1001d7c7` | `83 e0 02` | `AND EAX,0x2` |
| `1001d7ca` | `48` | `DEC EAX` |
| `1001d7cb` | `38 5d f4` | `CMP byte ptr [EBP + -0xc],BL` |
| `1001d7ce` | `74 f0` | `JZ 0x1001d7c0` |
| `1001d7d0` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001d7d3` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001d7d7` | `eb e7` | `JMP 0x1001d7c0` |
