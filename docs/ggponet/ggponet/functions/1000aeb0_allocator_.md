# 1000aeb0 `allocator<>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000aeb0 |
| `name` | allocator<> |
| `namespace` | Global |
| `signature` | undefined allocator<>(void) |
| `size_bytes` | 14 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | allocator<> |

## Decompiled C

```c

/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::allocator<char>::allocator<char>(void)
    public: __thiscall std::allocator<unsigned short>::allocator<unsigned short>(void)
    public: __thiscall std::allocator<wchar_t>::allocator<wchar_t>(void)
   
   Library: Visual Studio 2003 Debug */

undefined4 allocator<>(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000150c` | basic_string<> |
| `10002e4f` | FUN_10002e40 |
| `1000255b` | FUN_10002530 |
| `10004aec` | FUN_10004ae0 |
| `10008d2e` | FUN_10008d00 |
| `10008e6e` | FUN_10008e40 |
| `1000160e` | FUN_100015e0 |
| `10007a6e` | FUN_10007a40 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000aeb0` | `55` | `PUSH EBP` |
| `1000aeb1` | `8b ec` | `MOV EBP,ESP` |
| `1000aeb3` | `51` | `PUSH ECX` |
| `1000aeb4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1000aeb7` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000aeba` | `8b e5` | `MOV ESP,EBP` |
| `1000aebc` | `5d` | `POP EBP` |
| `1000aebd` | `c3` | `RET` |
