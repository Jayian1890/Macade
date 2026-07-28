# 10006340 `_String_const_iterator<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10006340 |
| `name` | _String_const_iterator<> |
| `namespace` | Global |
| `signature` | undefined _String_const_iterator<>(void) |
| `size_bytes` | 32 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _String_const_iterator<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::_String_const_iterator<char,struct std::char_traits<char>,class
   std::allocator<char> >::_String_const_iterator<char,struct std::char_traits<char>,class
   std::allocator<char> >(void)
    public: __thiscall std::_String_const_iterator<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::_String_const_iterator<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(void)
    public: __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<char> > >(void)
    public: __thiscall std::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >::_String_const_iterator<class std::_String_val<struct
   std::_Simple_types<unsigned short> > >(void)
     6 names - too many to list
   
   Library: Visual Studio */

int _String_const_iterator<>(void)

{
  int in_ECX;
  
  FUN_100086c0();
  *(undefined4 *)(in_ECX + 4) = 0;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000634a` | `100086c0` | `UNCONDITIONAL_CALL` | FUN_100086c0 | `100086c0` |

## Callers

| From | Function |
| --- | --- |
| `10004f3c` | FUN_10004f30 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10006340` | `55` | `PUSH EBP` |
| `10006341` | `8b ec` | `MOV EBP,ESP` |
| `10006343` | `51` | `PUSH ECX` |
| `10006344` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10006347` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000634a` | `e8 71 23 00 00` | `CALL 0x100086c0` |
| `1000634f` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10006352` | `c7 40 04 00 00 00 00` | `MOV dword ptr [EAX + 0x4],0x0` |
| `10006359` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000635c` | `8b e5` | `MOV ESP,EBP` |
| `1000635e` | `5d` | `POP EBP` |
| `1000635f` | `c3` | `RET` |
