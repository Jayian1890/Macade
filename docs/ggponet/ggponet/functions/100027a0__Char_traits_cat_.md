# 100027a0 `_Char_traits_cat<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100027a0 |
| `name` | _Char_traits_cat<> |
| `namespace` | Global |
| `signature` | undefined _Char_traits_cat<>(void) |
| `size_bytes` | 11 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _Char_traits_cat<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    struct std::_Secure_char_traits_tag __cdecl std::_Char_traits_cat<struct std::char_traits<char>
   >(void)
    struct std::_Secure_char_traits_tag __cdecl std::_Char_traits_cat<struct
   std::char_traits<unsigned short> >(void)
    struct std::_Secure_char_traits_tag __cdecl std::_Char_traits_cat<struct
   std::char_traits<wchar_t> >(void)
   
   Library: Visual Studio 2008 Debug */

undefined1 _Char_traits_cat<>(void)

{
  undefined4 in_ECX;
  undefined1 local_5;
  
  local_5 = (undefined1)((uint)in_ECX >> 0x18);
  return local_5;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10002614` | std::_Traits_helper::copy_s<std::char_traits<char>_> |
| `10002c5c` | FUN_10002c50 |
| `10002654` | std::_Traits_helper::move_s<std::char_traits<char>_> |
| `10002c9c` | FUN_10002c90 |
| `10003cc1` | FUN_10003cb0 |
| `1000489c` | FUN_10004890 |
| `1000b061` | FUN_1000b050 |
| `10009e71` | FUN_10009e60 |
| `10009f6d` | FUN_10009f60 |
| `1000a22d` | FUN_1000a220 |
| `1000a2b1` | FUN_1000a2a0 |
| `1000a551` | FUN_1000a540 |
| `10009ec1` | FUN_10009eb0 |
| `1000a03d` | FUN_1000a030 |
| `1000a2fd` | FUN_1000a2f0 |
| `1000a391` | FUN_1000a380 |
| `1000a5f1` | FUN_1000a5e0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100027a0` | `55` | `PUSH EBP` |
| `100027a1` | `8b ec` | `MOV EBP,ESP` |
| `100027a3` | `51` | `PUSH ECX` |
| `100027a4` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `100027a7` | `8b e5` | `MOV ESP,EBP` |
| `100027a9` | `5d` | `POP EBP` |
| `100027aa` | `c3` | `RET` |
