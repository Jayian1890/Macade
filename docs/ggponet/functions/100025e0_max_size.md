# 100025e0 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100025e0 |
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

/* WARNING: Removing unreachable block (ram,0x100025fe) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0x9249249;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000341d` | FUN_10003410 |
| `1000248d` | FUN_10002480 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100025e0` | `55` | `PUSH EBP` |
| `100025e1` | `8b ec` | `MOV EBP,ESP` |
| `100025e3` | `83 ec 0c` | `SUB ESP,0xc` |
| `100025e6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100025e9` | `c7 45 fc 49 92 24 09` | `MOV dword ptr [EBP + -0x4],0x9249249` |
| `100025f0` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `100025f4` | `76 08` | `JBE 0x100025fe` |
| `100025f6` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `100025f9` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `100025fc` | `eb 07` | `JMP 0x10002605` |
| `100025fe` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10002605` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10002608` | `8b e5` | `MOV ESP,EBP` |
| `1000260a` | `5d` | `POP EBP` |
| `1000260b` | `c3` | `RET` |
