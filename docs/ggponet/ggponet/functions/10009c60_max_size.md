# 10009c60 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10009c60 |
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

/* WARNING: Removing unreachable block (ram,0x10009c7e) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0x1fffffff;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100092bd` | FUN_100092b0 |
| `1000873d` | FUN_10008730 |
| `1000649d` | FUN_10006490 |
| `100086fd` | FUN_100086f0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10009c60` | `55` | `PUSH EBP` |
| `10009c61` | `8b ec` | `MOV EBP,ESP` |
| `10009c63` | `83 ec 0c` | `SUB ESP,0xc` |
| `10009c66` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10009c69` | `c7 45 fc ff ff ff 1f` | `MOV dword ptr [EBP + -0x4],0x1fffffff` |
| `10009c70` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10009c74` | `76 08` | `JBE 0x10009c7e` |
| `10009c76` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10009c79` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10009c7c` | `eb 07` | `JMP 0x10009c85` |
| `10009c7e` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10009c85` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10009c88` | `8b e5` | `MOV ESP,EBP` |
| `10009c8a` | `5d` | `POP EBP` |
| `10009c8b` | `c3` | `RET` |
