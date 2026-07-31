# 10002500 `std::allocator<char>::max_size`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002500 |
| `name` | std::allocator<char>::max_size |
| `namespace` | std::allocator<char> (GhidraClass) |
| `signature` | uint __thiscall max_size(allocator<char> * this) |
| `size_bytes` | 44 |
| `stack_frame_size` | 20 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ?max_size@?$allocator@D@std@@QBEIXZ, std::allocator<char>::max_size |

## Decompiled C

```c

/* WARNING: Removing unreachable block (ram,0x1000251e) */
/* Library Function - Single Match
    public: unsigned int __thiscall std::allocator<char>::max_size(void)const 
   
   Library: Visual Studio 2003 Debug */

uint __thiscall std::allocator<char>::max_size(allocator<char> *this)

{
  return 0xffffffff;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1000226c` | FID_conflict:max_size |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002500` | `55` | `PUSH EBP` |
| `10002501` | `8b ec` | `MOV EBP,ESP` |
| `10002503` | `83 ec 0c` | `SUB ESP,0xc` |
| `10002506` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10002509` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `10002510` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10002514` | `76 08` | `JBE 0x1000251e` |
| `10002516` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10002519` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1000251c` | `eb 07` | `JMP 0x10002525` |
| `1000251e` | `c7 45 f4 01 00 00 00` | `MOV dword ptr [EBP + -0xc],0x1` |
| `10002525` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10002528` | `8b e5` | `MOV ESP,EBP` |
| `1000252a` | `5d` | `POP EBP` |
| `1000252b` | `c3` | `RET` |
