# 10019a23 `__mbsnbicoll_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019a23 |
| `name` | __mbsnbicoll_l |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbicoll_l(uchar * _Str1, uchar * _Str2, size_t _MaxCount, _locale_t _Locale) |
| `size_bytes` | 238 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbicoll_l |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbicoll_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbicoll_l(uchar *_Str1,uchar *_Str2,size_t _MaxCount,_locale_t _Locale)

{
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
  if ((_Str1 == (uchar *)0x0) || (_Str2 == (uchar *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    return 0x7fffffff;
  }
  if (_MaxCount < 0x80000000) {
    if ((local_14.mbcinfo)->ismbcodepage == 0) {
      iVar2 = __strnicoll_l((char *)_Str1,(char *)_Str2,_MaxCount,_Locale);
    }
    else {
      iVar2 = ___crtCompareStringA
                        (&local_14,*(LPCWSTR *)(local_14.mbcinfo)->mbulinfo,0x1001,(LPCSTR)_Str1,
                         _MaxCount,(LPCSTR)_Str2,_MaxCount,(local_14.mbcinfo)->mbcodepage);
      if (iVar2 == 0) goto LAB_10019aee;
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
LAB_10019aee:
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
| `10019a32` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `10019a58` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10019a68` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019a95` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10019aa5` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019ac1` | `1001e267` | `UNCONDITIONAL_CALL` | __strnicoll_l | `1001e267` |
| `10019ae2` | `1001e225` | `UNCONDITIONAL_CALL` | ___crtCompareStringA | `1001e225` |

## Callers

| From | Function |
| --- | --- |
| `10019b21` | __mbsnbicoll |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019a23` | `8b ff` | `MOV EDI,EDI` |
| `10019a25` | `55` | `PUSH EBP` |
| `10019a26` | `8b ec` | `MOV EBP,ESP` |
| `10019a28` | `83 ec 10` | `SUB ESP,0x10` |
| `10019a2b` | `53` | `PUSH EBX` |
| `10019a2c` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `10019a2f` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `10019a32` | `e8 7f b8 ff ff` | `CALL 0x100152b6` |
| `10019a37` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10019a3a` | `33 db` | `XOR EBX,EBX` |
| `10019a3c` | `3b cb` | `CMP ECX,EBX` |
| `10019a3e` | `75 13` | `JNZ 0x10019a53` |
| `10019a40` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `10019a43` | `74 07` | `JZ 0x10019a4c` |
| `10019a45` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10019a48` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10019a4c` | `33 c0` | `XOR EAX,EAX` |
| `10019a4e` | `e9 bb 00 00 00` | `JMP 0x10019b0e` |
| `10019a53` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `10019a56` | `75 2e` | `JNZ 0x10019a86` |
| `10019a58` | `e8 ac b6 ff ff` | `CALL 0x10015109` |
| `10019a5d` | `53` | `PUSH EBX` |
| `10019a5e` | `53` | `PUSH EBX` |
| `10019a5f` | `53` | `PUSH EBX` |
| `10019a60` | `53` | `PUSH EBX` |
| `10019a61` | `53` | `PUSH EBX` |
| `10019a62` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10019a68` | `e8 42 7c ff ff` | `CALL 0x100116af` |
| `10019a6d` | `83 c4 14` | `ADD ESP,0x14` |
| `10019a70` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `10019a73` | `74 07` | `JZ 0x10019a7c` |
| `10019a75` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10019a78` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10019a7c` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `10019a81` | `e9 88 00 00 00` | `JMP 0x10019b0e` |
| `10019a86` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `10019a89` | `74 cd` | `JZ 0x10019a58` |
| `10019a8b` | `56` | `PUSH ESI` |
| `10019a8c` | `be ff ff ff 7f` | `MOV ESI,0x7fffffff` |
| `10019a91` | `3b ce` | `CMP ECX,ESI` |
| `10019a93` | `76 1a` | `JBE 0x10019aaf` |
| `10019a95` | `e8 6f b6 ff ff` | `CALL 0x10015109` |
| `10019a9a` | `53` | `PUSH EBX` |
| `10019a9b` | `53` | `PUSH EBX` |
| `10019a9c` | `53` | `PUSH EBX` |
| `10019a9d` | `53` | `PUSH EBX` |
| `10019a9e` | `53` | `PUSH EBX` |
| `10019a9f` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10019aa5` | `e8 05 7c ff ff` | `CALL 0x100116af` |
| `10019aaa` | `83 c4 14` | `ADD ESP,0x14` |
| `10019aad` | `eb 3f` | `JMP 0x10019aee` |
| `10019aaf` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10019ab2` | `39 58 08` | `CMP dword ptr [EAX + 0x8],EBX` |
| `10019ab5` | `75 14` | `JNZ 0x10019acb` |
| `10019ab7` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `10019aba` | `51` | `PUSH ECX` |
| `10019abb` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10019abe` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019ac1` | `e8 a1 47 00 00` | `CALL 0x1001e267` |
| `10019ac6` | `83 c4 10` | `ADD ESP,0x10` |
| `10019ac9` | `eb 36` | `JMP 0x10019b01` |
| `10019acb` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `10019ace` | `51` | `PUSH ECX` |
| `10019acf` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10019ad2` | `51` | `PUSH ECX` |
| `10019ad3` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019ad6` | `68 01 10 00 00` | `PUSH 0x1001` |
| `10019adb` | `ff 70 0c` | `PUSH dword ptr [EAX + 0xc]` |
| `10019ade` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `10019ae1` | `50` | `PUSH EAX` |
| `10019ae2` | `e8 3e 47 00 00` | `CALL 0x1001e225` |
| `10019ae7` | `83 c4 20` | `ADD ESP,0x20` |
| `10019aea` | `3b c3` | `CMP EAX,EBX` |
| `10019aec` | `75 10` | `JNZ 0x10019afe` |
| `10019aee` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `10019af1` | `74 07` | `JZ 0x10019afa` |
| `10019af3` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10019af6` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10019afa` | `8b c6` | `MOV EAX,ESI` |
| `10019afc` | `eb 0f` | `JMP 0x10019b0d` |
| `10019afe` | `83 c0 fe` | `ADD EAX,-0x2` |
| `10019b01` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `10019b04` | `74 07` | `JZ 0x10019b0d` |
| `10019b06` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10019b09` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `10019b0d` | `5e` | `POP ESI` |
| `10019b0e` | `5b` | `POP EBX` |
| `10019b0f` | `c9` | `LEAVE` |
| `10019b10` | `c3` | `RET` |
