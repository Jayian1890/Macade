# 1001e225 `___crtCompareStringA`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e225 |
| `name` | ___crtCompareStringA |
| `namespace` | Global |
| `signature` | int __cdecl ___crtCompareStringA(_locale_t _Plocinfo, LPCWSTR _LocaleName, DWORD _DwCmpFlags, LPCSTR _LpString1, int _CchCount1, LPCSTR _LpString2, int _CchCount2, int _Code_page) |
| `size_bytes` | 66 |
| `stack_frame_size` | 56 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtCompareStringA |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtCompareStringA
   
   Library: Visual Studio 2008 Release */

int __cdecl
___crtCompareStringA
          (_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwCmpFlags,LPCSTR _LpString1,
          int _CchCount1,LPCSTR _LpString2,int _CchCount2,int _Code_page)

{
  int iVar1;
  int in_stack_ffffffec;
  int in_stack_fffffff0;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&stack0xffffffec,_Plocinfo);
  iVar1 = __crtCompareStringA_stat
                    ((localeinfo_struct *)_LocaleName,_DwCmpFlags,_CchCount1,_LpString2,_CchCount2,
                     (char *)_Code_page,in_stack_ffffffec,in_stack_fffffff0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e233` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001e250` | `1001deb5` | `UNCONDITIONAL_CALL` | __crtCompareStringA_stat | `1001deb5` |

## Callers

| From | Function |
| --- | --- |
| `10019ae2` | __mbsnbicoll_l |
| `1001e327` | __strnicoll_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e225` | `8b ff` | `MOV EDI,EDI` |
| `1001e227` | `55` | `PUSH EBP` |
| `1001e228` | `8b ec` | `MOV EBP,ESP` |
| `1001e22a` | `83 ec 10` | `SUB ESP,0x10` |
| `1001e22d` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e230` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e233` | `e8 7e 70 ff ff` | `CALL 0x100152b6` |
| `1001e238` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001e23b` | `8b 55 14` | `MOV EDX,dword ptr [EBP + 0x14]` |
| `1001e23e` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001e241` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001e244` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e247` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001e24a` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001e24d` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001e250` | `e8 60 fc ff ff` | `CALL 0x1001deb5` |
| `1001e255` | `83 c4 18` | `ADD ESP,0x18` |
| `1001e258` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001e25c` | `74 07` | `JZ 0x1001e265` |
| `1001e25e` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001e261` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001e265` | `c9` | `LEAVE` |
| `1001e266` | `c3` | `RET` |
