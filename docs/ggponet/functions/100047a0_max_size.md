# 100047a0 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100047a0 |
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

/* WARNING: Removing unreachable block (ram,0x100047be) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0xfffffff;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000973d` | FUN_10009730 |
| `100045ad` | FUN_100045a0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100047a0` | `55` | `PUSH EBP` |
| `100047a1` | `8b ec` | `MOV EBP,ESP` |
| `100047a3` | `83 ec 0c` | `SUB ESP,0xc` |
| `100047a6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100047a9` | `c7 45 fc ff ff ff 0f` | `MOV dword ptr [EBP + -0x4],0xfffffff` |
| `100047b0` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `100047b4` | `76 08` | `JBE 0x100047be` |
| `100047b6` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `100047b9` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `100047bc` | `eb 07` | `JMP 0x100047c5` |
| `100047be` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `100047c5` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `100047c8` | `8b e5` | `MOV ESP,EBP` |
| `100047ca` | `5d` | `POP EBP` |
| `100047cb` | `c3` | `RET` |
