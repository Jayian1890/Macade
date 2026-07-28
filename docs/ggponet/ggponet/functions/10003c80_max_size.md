# 10003c80 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10003c80 |
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

/* WARNING: Removing unreachable block (ram,0x10003c9e) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0x5d1745d;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10003bad` | FUN_10003ba0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10003c80` | `55` | `PUSH EBP` |
| `10003c81` | `8b ec` | `MOV EBP,ESP` |
| `10003c83` | `83 ec 0c` | `SUB ESP,0xc` |
| `10003c86` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10003c89` | `c7 45 fc 5d 74 d1 05` | `MOV dword ptr [EBP + -0x4],0x5d1745d` |
| `10003c90` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10003c94` | `76 08` | `JBE 0x10003c9e` |
| `10003c96` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10003c99` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10003c9c` | `eb 07` | `JMP 0x10003ca5` |
| `10003c9e` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10003ca5` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10003ca8` | `8b e5` | `MOV ESP,EBP` |
| `10003caa` | `5d` | `POP EBP` |
| `10003cab` | `c3` | `RET` |
