# 100152b6 `_LocaleUpdate::_LocaleUpdate`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100152b6 |
| `name` | _LocaleUpdate::_LocaleUpdate |
| `namespace` | _LocaleUpdate (GhidraClass) |
| `signature` | undefined __thiscall _LocaleUpdate(_LocaleUpdate * this, localeinfo_struct * param_1) |
| `size_bytes` | 135 |
| `stack_frame_size` | 8 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0_LocaleUpdate@@QAE@PAUlocaleinfo_struct@@@Z, _LocaleUpdate::_LocaleUpdate |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct *)
   
   Library: Visual Studio 2008 Release */

_LocaleUpdate * __thiscall
_LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this,localeinfo_struct *param_1)

{
  uint *puVar1;
  _ptiddata p_Var2;
  pthreadlocinfo ptVar3;
  pthreadmbcinfo ptVar4;
  
  this[0xc] = (_LocaleUpdate)0x0;
  if (param_1 == (localeinfo_struct *)0x0) {
    p_Var2 = __getptd();
    *(_ptiddata *)(this + 8) = p_Var2;
    *(pthreadlocinfo *)this = p_Var2->ptlocinfo;
    *(pthreadmbcinfo *)(this + 4) = p_Var2->ptmbcinfo;
    if ((*(undefined **)this != PTR_DAT_10038228) && ((p_Var2->_ownlocale & DAT_10038144) == 0)) {
      ptVar3 = ___updatetlocinfo();
      *(pthreadlocinfo *)this = ptVar3;
    }
    if ((*(undefined **)(this + 4) != PTR_DAT_10038048) &&
       ((*(uint *)(*(int *)(this + 8) + 0x70) & DAT_10038144) == 0)) {
      ptVar4 = ___updatetmbcinfo();
      *(pthreadmbcinfo *)(this + 4) = ptVar4;
    }
    if ((*(byte *)(*(int *)(this + 8) + 0x70) & 2) == 0) {
      puVar1 = (uint *)(*(int *)(this + 8) + 0x70);
      *puVar1 = *puVar1 | 2;
      this[0xc] = (_LocaleUpdate)0x1;
    }
  }
  else {
    *(pthreadlocinfo *)this = param_1->locinfo;
    *(pthreadmbcinfo *)(this + 4) = param_1->mbcinfo;
  }
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100152c9` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `100152f1` | `1001c509` | `UNCONDITIONAL_CALL` | ___updatetlocinfo | `1001c509` |
| `10015311` | `1001bd9d` | `UNCONDITIONAL_CALL` | ___updatetmbcinfo | `1001bd9d` |

## Callers

| From | Function |
| --- | --- |
| `10015445` | __output_l |
| `10019a32` | __mbsnbicoll_l |
| `1001c716` | __isleadbyte_l |
| `1001d5bd` | __mbsnbicmp_l |
| `1001d811` | __mbsnbcmp_l |
| `1001e233` | ___crtCompareStringA |
| `1001e276` | __strnicoll_l |
| `1001e751` | __mbtowc_l |
| `1001f688` | __strnicmp_l |
| `10017b05` | strtoxl |
| `1001cc23` | __isctype_l |
| `1001ef25` | ___crtGetStringTypeA |
| `1001fa1d` | __mbschr_l |
| `1001fb3d` | __tolower_l |
| `1001ed26` | ___crtLCMapStringA |
| `1001be50` | getSystemCP |
| `1001e904` | x_ismbbtype_l |
| `1001c5dd` | __wctomb_s_l |
| `1001cb83` | __isdigit_l |
| `1002a13a` | __forcdecpt_l |
| `1002a1ad` | __cropzeros_l |
| `1002acee` | FID_conflict:__atoflt_l |
| `1002ad96` | FID_conflict:__atoflt_l |
| `1002a2f0` | __cftoe2_l |
| `1002a55c` | __cftoa_l |
| `1002a8c8` | __cftof2_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100152de` | `10038228` | `READ` | PTR_DAT_10038228 |
| `100152e6` | `10038144` | `READ` | DAT_10038144 |
| `100152fb` | `10038048` | `READ` | PTR_DAT_10038048 |
| `10015306` | `10038144` | `READ` | DAT_10038144 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100152b6` | `8b ff` | `MOV EDI,EDI` |
| `100152b8` | `55` | `PUSH EBP` |
| `100152b9` | `8b ec` | `MOV EBP,ESP` |
| `100152bb` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100152be` | `56` | `PUSH ESI` |
| `100152bf` | `8b f1` | `MOV ESI,ECX` |
| `100152c1` | `c6 46 0c 00` | `MOV byte ptr [ESI + 0xc],0x0` |
| `100152c5` | `85 c0` | `TEST EAX,EAX` |
| `100152c7` | `75 63` | `JNZ 0x1001532c` |
| `100152c9` | `e8 08 21 00 00` | `CALL 0x100173d6` |
| `100152ce` | `89 46 08` | `MOV dword ptr [ESI + 0x8],EAX` |
| `100152d1` | `8b 48 6c` | `MOV ECX,dword ptr [EAX + 0x6c]` |
| `100152d4` | `89 0e` | `MOV dword ptr [ESI],ECX` |
| `100152d6` | `8b 48 68` | `MOV ECX,dword ptr [EAX + 0x68]` |
| `100152d9` | `89 4e 04` | `MOV dword ptr [ESI + 0x4],ECX` |
| `100152dc` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `100152de` | `3b 0d 28 82 03 10` | `CMP ECX,dword ptr [0x10038228]` |
| `100152e4` | `74 12` | `JZ 0x100152f8` |
| `100152e6` | `8b 0d 44 81 03 10` | `MOV ECX,dword ptr [0x10038144]` |
| `100152ec` | `85 48 70` | `TEST dword ptr [EAX + 0x70],ECX` |
| `100152ef` | `75 07` | `JNZ 0x100152f8` |
| `100152f1` | `e8 13 72 00 00` | `CALL 0x1001c509` |
| `100152f6` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `100152f8` | `8b 46 04` | `MOV EAX,dword ptr [ESI + 0x4]` |
| `100152fb` | `3b 05 48 80 03 10` | `CMP EAX,dword ptr [0x10038048]` |
| `10015301` | `74 16` | `JZ 0x10015319` |
| `10015303` | `8b 46 08` | `MOV EAX,dword ptr [ESI + 0x8]` |
| `10015306` | `8b 0d 44 81 03 10` | `MOV ECX,dword ptr [0x10038144]` |
| `1001530c` | `85 48 70` | `TEST dword ptr [EAX + 0x70],ECX` |
| `1001530f` | `75 08` | `JNZ 0x10015319` |
| `10015311` | `e8 87 6a 00 00` | `CALL 0x1001bd9d` |
| `10015316` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `10015319` | `8b 46 08` | `MOV EAX,dword ptr [ESI + 0x8]` |
| `1001531c` | `f6 40 70 02` | `TEST byte ptr [EAX + 0x70],0x2` |
| `10015320` | `75 14` | `JNZ 0x10015336` |
| `10015322` | `83 48 70 02` | `OR dword ptr [EAX + 0x70],0x2` |
| `10015326` | `c6 46 0c 01` | `MOV byte ptr [ESI + 0xc],0x1` |
| `1001532a` | `eb 0a` | `JMP 0x10015336` |
| `1001532c` | `8b 08` | `MOV ECX,dword ptr [EAX]` |
| `1001532e` | `89 0e` | `MOV dword ptr [ESI],ECX` |
| `10015330` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `10015333` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `10015336` | `8b c6` | `MOV EAX,ESI` |
| `10015338` | `5e` | `POP ESI` |
| `10015339` | `5d` | `POP EBP` |
| `1001533a` | `c2 04 00` | `RET 0x4` |
