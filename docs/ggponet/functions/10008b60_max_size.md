# 10008b60 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10008b60 |
| `name` | max_size |
| `namespace` | Global |
| `signature` | undefined max_size(void) |
| `size_bytes` | 44 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | max_size |

## Decompiled C

```c

/* WARNING: Removing unreachable block (ram,0x10008b7e) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0x3fffffff;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000643d` | FUN_10006430 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10008b60` | `55` | `PUSH EBP` |
| `10008b61` | `8b ec` | `MOV EBP,ESP` |
| `10008b63` | `83 ec 0c` | `SUB ESP,0xc` |
| `10008b66` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10008b69` | `c7 45 fc ff ff ff 3f` | `MOV dword ptr [EBP + -0x4],0x3fffffff` |
| `10008b70` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10008b74` | `76 08` | `JBE 0x10008b7e` |
| `10008b76` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10008b79` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10008b7c` | `eb 07` | `JMP 0x10008b85` |
| `10008b7e` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10008b85` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10008b88` | `8b e5` | `MOV ESP,EBP` |
| `10008b8a` | `5d` | `POP EBP` |
| `10008b8b` | `c3` | `RET` |
