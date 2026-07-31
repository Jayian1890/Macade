# 1000afe0 `max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000afe0 |
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

/* WARNING: Removing unreachable block (ram,0x1000affe) */
/* Library Function - Multiple Matches With Same Base Name
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<unsigned short>::max_size(void)const 
    public: unsigned int __thiscall std::allocator<wchar_t>::max_size(void)const 
   
   Libraries: Visual Studio 2003, Visual Studio 2005, Visual Studio 2008, Visual Studio 2010 */

undefined4 max_size(void)

{
  return 0x7ffffff;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000af2d` | FUN_1000af20 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000afe0` | `55` | `PUSH EBP` |
| `1000afe1` | `8b ec` | `MOV EBP,ESP` |
| `1000afe3` | `83 ec 0c` | `SUB ESP,0xc` |
| `1000afe6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1000afe9` | `c7 45 fc ff ff ff 07` | `MOV dword ptr [EBP + -0x4],0x7ffffff` |
| `1000aff0` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `1000aff4` | `76 08` | `JBE 0x1000affe` |
| `1000aff6` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000aff9` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1000affc` | `eb 07` | `JMP 0x1000b005` |
| `1000affe` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `1000b005` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1000b008` | `8b e5` | `MOV ESP,EBP` |
| `1000b00a` | `5d` | `POP EBP` |
| `1000b00b` | `c3` | `RET` |
