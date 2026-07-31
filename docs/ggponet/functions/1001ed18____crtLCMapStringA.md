# 1001ed18 `___crtLCMapStringA`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ed18 |
| `name` | ___crtLCMapStringA |
| `namespace` | Global |
| `signature` | int __cdecl ___crtLCMapStringA(_locale_t _Plocinfo, LPCWSTR _LocaleName, DWORD _DwMapFlag, LPCSTR _LpSrcStr, int _CchSrc, LPSTR _LpDestStr, int _CchDest, int _Code_page, BOOL _BError) |
| `size_bytes` | 69 |
| `stack_frame_size` | 60 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtLCMapStringA |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtLCMapStringA
   
   Library: Visual Studio 2008 Release */

int __cdecl
___crtLCMapStringA(_locale_t _Plocinfo,LPCWSTR _LocaleName,DWORD _DwMapFlag,LPCSTR _LpSrcStr,
                  int _CchSrc,LPSTR _LpDestStr,int _CchDest,int _Code_page,BOOL _BError)

{
  int iVar1;
  int in_stack_ffffffec;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&stack0xffffffec,_Plocinfo);
  iVar1 = __crtLCMapStringA_stat
                    ((localeinfo_struct *)_LocaleName,_DwMapFlag,(ulong)_LpSrcStr,(char *)_CchSrc,
                     (int)_LpDestStr,(char *)_CchDest,_Code_page,_BError,in_stack_ffffffec);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ed26` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001ed46` | `1001e973` | `UNCONDITIONAL_CALL` | __crtLCMapStringA_stat | `1001e973` |

## Callers

| From | Function |
| --- | --- |
| `1001fc0f` | __tolower_l |
| `1001bcc6` | setSBUpLow |
| `1001bceb` | setSBUpLow |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ed18` | `8b ff` | `MOV EDI,EDI` |
| `1001ed1a` | `55` | `PUSH EBP` |
| `1001ed1b` | `8b ec` | `MOV EBP,ESP` |
| `1001ed1d` | `83 ec 10` | `SUB ESP,0x10` |
| `1001ed20` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ed23` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001ed26` | `e8 8b 65 ff ff` | `CALL 0x100152b6` |
| `1001ed2b` | `ff 75 28` | `PUSH dword ptr [EBP + 0x28]` |
| `1001ed2e` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001ed31` | `ff 75 24` | `PUSH dword ptr [EBP + 0x24]` |
| `1001ed34` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001ed37` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001ed3a` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001ed3d` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ed40` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ed43` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ed46` | `e8 28 fc ff ff` | `CALL 0x1001e973` |
| `1001ed4b` | `83 c4 20` | `ADD ESP,0x20` |
| `1001ed4e` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1001ed52` | `74 07` | `JZ 0x1001ed5b` |
| `1001ed54` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001ed57` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001ed5b` | `c9` | `LEAVE` |
| `1001ed5c` | `c3` | `RET` |
