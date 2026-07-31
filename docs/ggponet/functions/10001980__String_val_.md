# 10001980 `_String_val<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001980 |
| `name` | _String_val<> |
| `namespace` | Global |
| `signature` | undefined _String_val<>(void) |
| `size_bytes` | 28 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _String_val<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall std::_String_val<char,class std::allocator<char> >::_String_val<char,class
   std::allocator<char> >(class std::allocator<char>)
    protected: __thiscall std::_String_val<unsigned short,class std::allocator<unsigned short>
   >::_String_val<unsigned short,class std::allocator<unsigned short> >(class
   std::allocator<unsigned short>)
    protected: __thiscall std::_String_val<wchar_t,class std::allocator<wchar_t>
   >::_String_val<wchar_t,class std::allocator<wchar_t> >(class std::allocator<wchar_t>)
   
   Library: Visual Studio 2003 Debug */

allocator<char> * _String_val<>(void)

{
  allocator<char> *in_ECX;
  
  std::allocator<char>::allocator<char>(in_ECX,(allocator<char> *)&stack0x00000004);
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000198e` | `10003df0` | `UNCONDITIONAL_CALL` | std::allocator<char>::allocator<char> | `10003df0` |

## Callers

| From | Function |
| --- | --- |
| `10001514` | basic_string<> |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001980` | `55` | `PUSH EBP` |
| `10001981` | `8b ec` | `MOV EBP,ESP` |
| `10001983` | `51` | `PUSH ECX` |
| `10001984` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001987` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1000198a` | `50` | `PUSH EAX` |
| `1000198b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000198e` | `e8 5d 24 00 00` | `CALL 0x10003df0` |
| `10001993` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10001996` | `8b e5` | `MOV ESP,EBP` |
| `10001998` | `5d` | `POP EBP` |
| `10001999` | `c2 04 00` | `RET 0x4` |
