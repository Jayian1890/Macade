# 1001e267 `__strnicoll_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e267 |
| `name` | __strnicoll_l |
| `namespace` | Global |
| `signature` | int __cdecl __strnicoll_l(char * _Str1, char * _Str2, size_t _MaxCount, _locale_t _Locale) |
| `size_bytes` | 250 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __strnicoll_l |

## Decompiled C

```c

/* Library Function - Single Match
    __strnicoll_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __strnicoll_l(char *_Str1,char *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  LPCWSTR _LocaleName;
  int *piVar1;
  int iVar2;
  localeinfo_struct local_14;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,_Locale);
  if (_MaxCount == 0) {
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  if ((_Str1 == (char *)0x0) || (_Str2 == (char *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    return 0x7fffffff;
  }
  if (_MaxCount < 0x80000000) {
    _LocaleName = (LPCWSTR)(local_14.locinfo)->lc_category[0].locale;
    if (_LocaleName == (LPCWSTR)0x0) {
      iVar2 = __strnicmp_l(_Str1,_Str2,_MaxCount,&local_14);
    }
    else {
      iVar2 = ___crtCompareStringA
                        (&local_14,_LocaleName,0x1001,_Str1,_MaxCount,_Str2,_MaxCount,
                         (local_14.locinfo)->lc_collate_cp);
      if (iVar2 == 0) {
        piVar1 = __errno();
        *piVar1 = 0x16;
        goto LAB_1001e33e;
      }
      iVar2 = iVar2 + -2;
    }
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
LAB_1001e33e:
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    iVar2 = 0x7fffffff;
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e276` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001e29c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e2ac` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001e2d9` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001e2e9` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001e308` | `1001f66c` | `UNCONDITIONAL_CALL` | __strnicmp_l | `1001f66c` |
| `1001e327` | `1001e225` | `UNCONDITIONAL_CALL` | ___crtCompareStringA | `1001e225` |
| `1001e333` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `10019ac1` | __mbsnbicoll_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e267` | `8b ff` | `MOV EDI,EDI` |
| `1001e269` | `55` | `PUSH EBP` |
| `1001e26a` | `8b ec` | `MOV EBP,ESP` |
| `1001e26c` | `83 ec 10` | `SUB ESP,0x10` |
| `1001e26f` | `53` | `PUSH EBX` |
| `1001e270` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001e273` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e276` | `e8 3b 70 ff ff` | `CALL 0x100152b6` |
| `1001e27b` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `1001e27e` | `33 db` | `XOR EBX,EBX` |
| `1001e280` | `3b d3` | `CMP EDX,EBX` |
| `1001e282` | `75 13` | `JNZ 0x1001e297` |
| `1001e284` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e287` | `74 07` | `JZ 0x1001e290` |
| `1001e289` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001e28c` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001e290` | `33 c0` | `XOR EAX,EAX` |
| `1001e292` | `e9 c7 00 00 00` | `JMP 0x1001e35e` |
| `1001e297` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001e29a` | `75 2e` | `JNZ 0x1001e2ca` |
| `1001e29c` | `e8 68 6e ff ff` | `CALL 0x10015109` |
| `1001e2a1` | `53` | `PUSH EBX` |
| `1001e2a2` | `53` | `PUSH EBX` |
| `1001e2a3` | `53` | `PUSH EBX` |
| `1001e2a4` | `53` | `PUSH EBX` |
| `1001e2a5` | `53` | `PUSH EBX` |
| `1001e2a6` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001e2ac` | `e8 fe 33 ff ff` | `CALL 0x100116af` |
| `1001e2b1` | `83 c4 14` | `ADD ESP,0x14` |
| `1001e2b4` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e2b7` | `74 07` | `JZ 0x1001e2c0` |
| `1001e2b9` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001e2bc` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001e2c0` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `1001e2c5` | `e9 94 00 00 00` | `JMP 0x1001e35e` |
| `1001e2ca` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1001e2cd` | `74 cd` | `JZ 0x1001e29c` |
| `1001e2cf` | `56` | `PUSH ESI` |
| `1001e2d0` | `be ff ff ff 7f` | `MOV ESI,0x7fffffff` |
| `1001e2d5` | `3b d6` | `CMP EDX,ESI` |
| `1001e2d7` | `76 1a` | `JBE 0x1001e2f3` |
| `1001e2d9` | `e8 2b 6e ff ff` | `CALL 0x10015109` |
| `1001e2de` | `53` | `PUSH EBX` |
| `1001e2df` | `53` | `PUSH EBX` |
| `1001e2e0` | `53` | `PUSH EBX` |
| `1001e2e1` | `53` | `PUSH EBX` |
| `1001e2e2` | `53` | `PUSH EBX` |
| `1001e2e3` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001e2e9` | `e8 c1 33 ff ff` | `CALL 0x100116af` |
| `1001e2ee` | `83 c4 14` | `ADD ESP,0x14` |
| `1001e2f1` | `eb 4b` | `JMP 0x1001e33e` |
| `1001e2f3` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001e2f6` | `8b 48 10` | `MOV ECX,dword ptr [EAX + 0x10]` |
| `1001e2f9` | `3b cb` | `CMP ECX,EBX` |
| `1001e2fb` | `75 15` | `JNZ 0x1001e312` |
| `1001e2fd` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001e300` | `50` | `PUSH EAX` |
| `1001e301` | `52` | `PUSH EDX` |
| `1001e302` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001e305` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e308` | `e8 5f 13 00 00` | `CALL 0x1001f66c` |
| `1001e30d` | `83 c4 10` | `ADD ESP,0x10` |
| `1001e310` | `eb 3f` | `JMP 0x1001e351` |
| `1001e312` | `ff 70 08` | `PUSH dword ptr [EAX + 0x8]` |
| `1001e315` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001e318` | `52` | `PUSH EDX` |
| `1001e319` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001e31c` | `52` | `PUSH EDX` |
| `1001e31d` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e320` | `68 01 10 00 00` | `PUSH 0x1001` |
| `1001e325` | `51` | `PUSH ECX` |
| `1001e326` | `50` | `PUSH EAX` |
| `1001e327` | `e8 f9 fe ff ff` | `CALL 0x1001e225` |
| `1001e32c` | `83 c4 20` | `ADD ESP,0x20` |
| `1001e32f` | `3b c3` | `CMP EAX,EBX` |
| `1001e331` | `75 1b` | `JNZ 0x1001e34e` |
| `1001e333` | `e8 d1 6d ff ff` | `CALL 0x10015109` |
| `1001e338` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001e33e` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e341` | `74 07` | `JZ 0x1001e34a` |
| `1001e343` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001e346` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001e34a` | `8b c6` | `MOV EAX,ESI` |
| `1001e34c` | `eb 0f` | `JMP 0x1001e35d` |
| `1001e34e` | `83 c0 fe` | `ADD EAX,-0x2` |
| `1001e351` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001e354` | `74 07` | `JZ 0x1001e35d` |
| `1001e356` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001e359` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001e35d` | `5e` | `POP ESI` |
| `1001e35e` | `5b` | `POP EBX` |
| `1001e35f` | `c9` | `LEAVE` |
| `1001e360` | `c3` | `RET` |
