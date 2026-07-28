# 100010c0 `FID_conflict:_Move_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100010c0 |
| `name` | FID_conflict:_Move_s |
| `namespace` | Global |
| `signature` | undefined FID_conflict:_Move_s(void) |
| `size_bytes` | 32 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ?_Copy_s@?$char_traits@G@std@@SAPAGPAGIPBGI@Z, ?_Copy_s@?$char_traits@_W@std@@SAPA_WPA_WIPB_WI@Z, ?_Move_s@?$char_traits@D@std@@SAPADPADIPBDI@Z, ?_Move_s@?$char_traits@G@std@@SAPAGPAGIPBGI@Z, ?_Move_s@?$char_traits@_W@std@@SAPA_WPA_WIPB_WI@Z, FID_conflict:_Move_s |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: static unsigned short * __cdecl std::char_traits<unsigned short>::_Copy_s(unsigned short
   *,unsigned int,unsigned short const *,unsigned int)
    public: static wchar_t * __cdecl std::char_traits<wchar_t>::_Copy_s(wchar_t *,unsigned
   int,wchar_t const *,unsigned int)
    public: static char * __cdecl std::char_traits<char>::_Move_s(char *,unsigned int,char const
   *,unsigned int)
    public: static unsigned short * __cdecl std::char_traits<unsigned short>::_Move_s(unsigned short
   *,unsigned int,unsigned short const *,unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

void * FID_conflict__Move_s(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  _memcpy_s(param_1,param_2,param_3,param_4);
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100010d3` | `10011803` | `UNCONDITIONAL_CALL` | _memcpy_s | `10011803` |

## Callers

| From | Function |
| --- | --- |
| `100027c3` | FID_conflict:copy_s<std::char_traits<wchar_t>_> |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100010c0` | `55` | `PUSH EBP` |
| `100010c1` | `8b ec` | `MOV EBP,ESP` |
| `100010c3` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `100010c6` | `50` | `PUSH EAX` |
| `100010c7` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `100010ca` | `51` | `PUSH ECX` |
| `100010cb` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `100010ce` | `52` | `PUSH EDX` |
| `100010cf` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100010d2` | `50` | `PUSH EAX` |
| `100010d3` | `e8 2b 07 01 00` | `CALL 0x10011803` |
| `100010d8` | `83 c4 10` | `ADD ESP,0x10` |
| `100010db` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100010de` | `5d` | `POP EBP` |
| `100010df` | `c3` | `RET` |
