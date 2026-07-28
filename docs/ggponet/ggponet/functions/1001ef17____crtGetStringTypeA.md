# 1001ef17 `___crtGetStringTypeA`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ef17 |
| `name` | ___crtGetStringTypeA |
| `namespace` | Global |
| `signature` | BOOL __cdecl ___crtGetStringTypeA(_locale_t _Plocinfo, DWORD _DWInfoType, LPCSTR _LpSrcStr, int _CchSrc, LPWORD _LpCharType, int _Code_page, BOOL _BError) |
| `size_bytes` | 66 |
| `stack_frame_size` | 52 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtGetStringTypeA |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtGetStringTypeA
   
   Library: Visual Studio 2008 Release */

BOOL __cdecl
___crtGetStringTypeA
          (_locale_t _Plocinfo,DWORD _DWInfoType,LPCSTR _LpSrcStr,int _CchSrc,LPWORD _LpCharType,
          int _Code_page,BOOL _BError)

{
  int iVar1;
  int in_stack_00000020;
  int in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&stack0xffffffec,_Plocinfo);
  iVar1 = __crtGetStringTypeA_stat
                    ((localeinfo_struct *)_DWInfoType,(ulong)_LpSrcStr,(char *)_CchSrc,
                     (int)_LpCharType,(ushort *)_Code_page,_BError,in_stack_00000020,
                     in_stack_ffffffec);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ef25` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001ef42` | `1001ed5d` | `UNCONDITIONAL_CALL` | __crtGetStringTypeA_stat | `1001ed5d` |

## Callers

| From | Function |
| --- | --- |
| `1001cc99` | __isctype_l |
| `1001bca6` | setSBUpLow |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ef17` | `8b ff` | `MOV EDI,EDI` |
| `1001ef19` | `55` | `PUSH EBP` |
| `1001ef1a` | `8b ec` | `MOV EBP,ESP` |
| `1001ef1c` | `83 ec 10` | `SUB ESP,0x10` |
| `1001ef1f` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ef22` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001ef25` | `e8 8c 63 ff ff` | `CALL 0x100152b6` |
| `1001ef2a` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001ef2d` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001ef30` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001ef33` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001ef36` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001ef39` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ef3c` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ef3f` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ef42` | `e8 16 fe ff ff` | `CALL 0x1001ed5d` |
| `1001ef47` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1001ef4a` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001ef4e` | `74 07` | `JZ 0x1001ef57` |
| `1001ef50` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001ef53` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001ef57` | `c9` | `LEAVE` |
| `1001ef58` | `c3` | `RET` |
