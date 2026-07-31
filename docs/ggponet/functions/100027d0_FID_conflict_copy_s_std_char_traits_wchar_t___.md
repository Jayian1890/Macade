# 100027d0 `FID_conflict:copy_s<std::char_traits<wchar_t>_>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100027d0 |
| `name` | FID_conflict:copy_s<std::char_traits<wchar_t>_> |
| `namespace` | Global |
| `signature` | undefined FID_conflict:copy_s<std::char_traits<wchar_t>_>(void) |
| `size_bytes` | 29 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??$copy_s@U?$char_traits@G@std@@@_Traits_helper@std@@YAPAGPAGIPBGIU_Secure_char_traits_tag@1@@Z, ??$copy_s@U?$char_traits@_W@std@@@_Traits_helper@std@@YAPA_WPA_WIPB_WIU_Secure_char_traits_tag@1@@Z, ??$move_s@U?$char_traits@D@std@@@_Traits_helper@std@@YAPADPADIPBDIU_Secure_char_traits_tag@1@@Z, ??$move_s@U?$char_traits@G@std@@@_Traits_helper@std@@YAPAGPAGIPBGIU_Secure_char_traits_tag@1@@Z, ??$move_s@U?$char_traits@_W@std@@@_Traits_helper@std@@YAPA_WPA_WIPB_WIU_Secure_char_traits_tag@1@@Z, FID_conflict:copy_s<std::char_traits<wchar_t>_> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    unsigned short * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<unsigned short>
   >(unsigned short *,unsigned int,unsigned short const *,unsigned int,struct
   std::_Secure_char_traits_tag)
    wchar_t * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<wchar_t> >(wchar_t
   *,unsigned int,wchar_t const *,unsigned int,struct std::_Secure_char_traits_tag)
    char * __cdecl std::_Traits_helper::move_s<struct std::char_traits<char> >(char *,unsigned
   int,char const *,unsigned int,struct std::_Secure_char_traits_tag)
    unsigned short * __cdecl std::_Traits_helper::move_s<struct std::char_traits<unsigned short>
   >(unsigned short *,unsigned int,unsigned short const *,unsigned int,struct
   std::_Secure_char_traits_tag)
     5 names - too many to list
   
   Library: Visual Studio 2008 Debug */

void FID_conflict_copy_s<std::char_traits<wchar_t>_>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FID_conflict__Move_s(param_1,param_2,param_3,param_4);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100027e3` | `100010e0` | `UNCONDITIONAL_CALL` | FID_conflict:_Move_s | `100010e0` |

## Callers

| From | Function |
| --- | --- |
| `10002671` | std::_Traits_helper::move_s<std::char_traits<char>_> |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100027d0` | `55` | `PUSH EBP` |
| `100027d1` | `8b ec` | `MOV EBP,ESP` |
| `100027d3` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `100027d6` | `50` | `PUSH EAX` |
| `100027d7` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `100027da` | `51` | `PUSH ECX` |
| `100027db` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `100027de` | `52` | `PUSH EDX` |
| `100027df` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100027e2` | `50` | `PUSH EAX` |
| `100027e3` | `e8 f8 e8 ff ff` | `CALL 0x100010e0` |
| `100027e8` | `83 c4 10` | `ADD ESP,0x10` |
| `100027eb` | `5d` | `POP EBP` |
| `100027ec` | `c3` | `RET` |
