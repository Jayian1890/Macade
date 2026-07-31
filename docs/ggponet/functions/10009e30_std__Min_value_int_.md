# 10009e30 `std::_Min_value<int>`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10009e30 |
| `name` | std::_Min_value<int> |
| `namespace` | std |
| `signature` | int * __cdecl _Min_value<int>(int * param_1, int * param_2) |
| `size_bytes` | 45 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ??$_Min_value@H@std@@YAABHABH0@Z, std::_Min_value<int> |

## Decompiled C

```c

/* Library Function - Single Match
    int const & __cdecl std::_Min_value<int>(int const &,int const &)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

int * __cdecl std::_Min_value<int>(int *param_1,int *param_2)

{
  undefined4 local_c;
  
  if (*param_1 < *param_2) {
    local_c = param_2;
  }
  else {
    local_c = param_1;
  }
  return local_c;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10028075` | FUN_10027ff0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10009e30` | `55` | `PUSH EBP` |
| `10009e31` | `8b ec` | `MOV EBP,ESP` |
| `10009e33` | `83 ec 08` | `SUB ESP,0x8` |
| `10009e36` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10009e39` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10009e3c` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `10009e3e` | `3b 11` | `CMP EDX,dword ptr [ECX]` |
| `10009e40` | `7d 08` | `JGE 0x10009e4a` |
| `10009e42` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10009e45` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10009e48` | `eb 06` | `JMP 0x10009e50` |
| `10009e4a` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10009e4d` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10009e50` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `10009e53` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `10009e56` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10009e59` | `8b e5` | `MOV ESP,EBP` |
| `10009e5b` | `5d` | `POP EBP` |
| `10009e5c` | `c3` | `RET` |
