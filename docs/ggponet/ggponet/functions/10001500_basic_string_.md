# 10001500 `basic_string<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001500 |
| `name` | basic_string<> |
| `namespace` | Global |
| `signature` | undefined basic_string<>(void) |
| `size_bytes` | 58 |
| `stack_frame_size` | 16 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | basic_string<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const *)
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const *)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *)
   
   Library: Visual Studio 2003 Debug */

undefined4 basic_string<>(undefined4 param_1)

{
  undefined4 in_ECX;
  undefined4 uVar1;
  
  uVar1 = in_ECX;
  allocator<>();
  _String_val<>(uVar1);
  FUN_100018d0(0,0);
  FID_conflict_assign(param_1);
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000150c` | `1000aeb0` | `UNCONDITIONAL_CALL` | allocator<> | `1000aeb0` |
| `10001514` | `10001980` | `UNCONDITIONAL_CALL` | _String_val<> | `10001980` |
| `10001520` | `100018d0` | `UNCONDITIONAL_CALL` | FUN_100018d0 | `100018d0` |
| `1000152c` | `100018a0` | `UNCONDITIONAL_CALL` | FID_conflict:assign | `100018a0` |

## Callers

| From | Function |
| --- | --- |
| `100064f9` | FUN_100064b0 |
| `10010c64` | FUN_10010c50 |
| `10010c9c` | FUN_10010c88 |
| `100045ed` | FUN_100045c0 |
| `100096ad` | FUN_10009680 |
| `100020b3` | FUN_10002070 |
| `10005e14` | FUN_10005dd0 |
| `10008283` | FUN_10008240 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001500` | `55` | `PUSH EBP` |
| `10001501` | `8b ec` | `MOV EBP,ESP` |
| `10001503` | `83 ec 08` | `SUB ESP,0x8` |
| `10001506` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10001509` | `51` | `PUSH ECX` |
| `1000150a` | `8b cc` | `MOV ECX,ESP` |
| `1000150c` | `e8 9f 99 00 00` | `CALL 0x1000aeb0` |
| `10001511` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001514` | `e8 67 04 00 00` | `CALL 0x10001980` |
| `10001519` | `6a 00` | `PUSH 0x0` |
| `1000151b` | `6a 00` | `PUSH 0x0` |
| `1000151d` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10001520` | `e8 ab 03 00 00` | `CALL 0x100018d0` |
| `10001525` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10001528` | `50` | `PUSH EAX` |
| `10001529` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1000152c` | `e8 6f 03 00 00` | `CALL 0x100018a0` |
| `10001531` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10001534` | `8b e5` | `MOV ESP,EBP` |
| `10001536` | `5d` | `POP EBP` |
| `10001537` | `c2 04 00` | `RET 0x4` |
