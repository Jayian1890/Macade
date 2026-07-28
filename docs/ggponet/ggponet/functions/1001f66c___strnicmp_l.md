# 1001f66c `__strnicmp_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f66c |
| `name` | __strnicmp_l |
| `namespace` | Global |
| `signature` | int __cdecl __strnicmp_l(char * _Str1, char * _Str2, size_t _MaxCount, _locale_t _Locale) |
| `size_bytes` | 242 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __strnicmp_l |

## Decompiled C

```c

/* Library Function - Single Match
    __strnicmp_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __strnicmp_l(char *_Str1,char *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  if (_MaxCount == 0) {
    iVar2 = 0;
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Locale);
    if ((_Str1 == (char *)0x0) || (_Str2 == (char *)0x0)) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      __invalid_parameter(0,0,0,0,0);
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar2 = 0x7fffffff;
    }
    else if (_MaxCount < 0x80000000) {
      if ((local_14.locinfo)->lc_category[0].wlocale == (wchar_t *)0x0) {
        iVar2 = ___ascii_strnicmp(_Str1,_Str2,_MaxCount);
      }
      else {
        do {
          iVar2 = __tolower_l((uint)(byte)*_Str1,&local_14);
          _Str1 = _Str1 + 1;
          iVar3 = __tolower_l((uint)(byte)*_Str2,&local_14);
          _Str2 = _Str2 + 1;
          _MaxCount = _MaxCount - 1;
          if ((_MaxCount == 0) || (iVar2 == 0)) break;
        } while (iVar2 == iVar3);
        iVar2 = iVar2 - iVar3;
      }
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
    }
    else {
      piVar1 = __errno();
      *piVar1 = 0x16;
      __invalid_parameter(0,0,0,0,0);
      if (local_8 != '\0') {
        *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
      }
      iVar2 = 0x7fffffff;
    }
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f688` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001f692` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f6a2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001f6d1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f6e1` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001f708` | `1001fc70` | `UNCONDITIONAL_CALL` | ___ascii_strnicmp | `1001fc70` |
| `1001f729` | `1001fb2d` | `UNCONDITIONAL_CALL` | __tolower_l | `1001fb2d` |
| `1001f73b` | `1001fb2d` | `UNCONDITIONAL_CALL` | __tolower_l | `1001fb2d` |

## Callers

| From | Function |
| --- | --- |
| `1001e308` | __strnicoll_l |
| `1001f7b1` | __strnicmp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f66c` | `8b ff` | `MOV EDI,EDI` |
| `1001f66e` | `55` | `PUSH EBP` |
| `1001f66f` | `8b ec` | `MOV EBP,ESP` |
| `1001f671` | `83 ec 10` | `SUB ESP,0x10` |
| `1001f674` | `53` | `PUSH EBX` |
| `1001f675` | `33 db` | `XOR EBX,EBX` |
| `1001f677` | `56` | `PUSH ESI` |
| `1001f678` | `57` | `PUSH EDI` |
| `1001f679` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1001f67c` | `0f 84 d5 00 00 00` | `JZ 0x1001f757` |
| `1001f682` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001f685` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001f688` | `e8 29 5c ff ff` | `CALL 0x100152b6` |
| `1001f68d` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001f690` | `75 2e` | `JNZ 0x1001f6c0` |
| `1001f692` | `e8 72 5a ff ff` | `CALL 0x10015109` |
| `1001f697` | `53` | `PUSH EBX` |
| `1001f698` | `53` | `PUSH EBX` |
| `1001f699` | `53` | `PUSH EBX` |
| `1001f69a` | `53` | `PUSH EBX` |
| `1001f69b` | `53` | `PUSH EBX` |
| `1001f69c` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001f6a2` | `e8 08 20 ff ff` | `CALL 0x100116af` |
| `1001f6a7` | `83 c4 14` | `ADD ESP,0x14` |
| `1001f6aa` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001f6ad` | `74 07` | `JZ 0x1001f6b6` |
| `1001f6af` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001f6b2` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001f6b6` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001f6bb` | `e9 99 00 00 00` | `JMP 0x1001f759` |
| `1001f6c0` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001f6c3` | `3b fb` | `CMP EDI,EBX` |
| `1001f6c5` | `74 cb` | `JZ 0x1001f692` |
| `1001f6c7` | `be ff ff ff 7f` | `MOV ESI,0x7fffffff` |
| `1001f6cc` | `39 75 10` | `CMP dword ptr [EBP + 0x10],ESI` |
| `1001f6cf` | `76 28` | `JBE 0x1001f6f9` |
| `1001f6d1` | `e8 33 5a ff ff` | `CALL 0x10015109` |
| `1001f6d6` | `53` | `PUSH EBX` |
| `1001f6d7` | `53` | `PUSH EBX` |
| `1001f6d8` | `53` | `PUSH EBX` |
| `1001f6d9` | `53` | `PUSH EBX` |
| `1001f6da` | `53` | `PUSH EBX` |
| `1001f6db` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001f6e1` | `e8 c9 1f ff ff` | `CALL 0x100116af` |
| `1001f6e6` | `83 c4 14` | `ADD ESP,0x14` |
| `1001f6e9` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001f6ec` | `74 07` | `JZ 0x1001f6f5` |
| `1001f6ee` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001f6f1` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001f6f5` | `8b c6` | `MOV EAX,ESI` |
| `1001f6f7` | `eb 60` | `JMP 0x1001f759` |
| `1001f6f9` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001f6fc` | `39 58 14` | `CMP dword ptr [EAX + 0x14],EBX` |
| `1001f6ff` | `75 1d` | `JNZ 0x1001f71e` |
| `1001f701` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001f704` | `57` | `PUSH EDI` |
| `1001f705` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f708` | `e8 63 05 00 00` | `CALL 0x1001fc70` |
| `1001f70d` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001f710` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001f713` | `74 44` | `JZ 0x1001f759` |
| `1001f715` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001f718` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001f71c` | `eb 3b` | `JMP 0x1001f759` |
| `1001f71e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001f721` | `0f b6 00` | `MOVZX EAX,byte ptr [EAX]` |
| `1001f724` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001f727` | `51` | `PUSH ECX` |
| `1001f728` | `50` | `PUSH EAX` |
| `1001f729` | `e8 ff 03 00 00` | `CALL 0x1001fb2d` |
| `1001f72e` | `ff 45 08` | `INC dword ptr [EBP + 0x8]` |
| `1001f731` | `8b f0` | `MOV ESI,EAX` |
| `1001f733` | `0f b6 07` | `MOVZX EAX,byte ptr [EDI]` |
| `1001f736` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001f739` | `51` | `PUSH ECX` |
| `1001f73a` | `50` | `PUSH EAX` |
| `1001f73b` | `e8 ed 03 00 00` | `CALL 0x1001fb2d` |
| `1001f740` | `83 c4 10` | `ADD ESP,0x10` |
| `1001f743` | `47` | `INC EDI` |
| `1001f744` | `ff 4d 10` | `DEC dword ptr [EBP + 0x10]` |
| `1001f747` | `74 08` | `JZ 0x1001f751` |
| `1001f749` | `3b f3` | `CMP ESI,EBX` |
| `1001f74b` | `74 04` | `JZ 0x1001f751` |
| `1001f74d` | `3b f0` | `CMP ESI,EAX` |
| `1001f74f` | `74 cd` | `JZ 0x1001f71e` |
| `1001f751` | `2b f0` | `SUB ESI,EAX` |
| `1001f753` | `8b c6` | `MOV EAX,ESI` |
| `1001f755` | `eb b9` | `JMP 0x1001f710` |
| `1001f757` | `33 c0` | `XOR EAX,EAX` |
| `1001f759` | `5f` | `POP EDI` |
| `1001f75a` | `5e` | `POP ESI` |
| `1001f75b` | `5b` | `POP EBX` |
| `1001f75c` | `c9` | `LEAVE` |
| `1001f75d` | `c3` | `RET` |
