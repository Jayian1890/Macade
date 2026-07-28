# 10011183 `std::exception::exception`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011183 |
| `name` | std::exception::exception |
| `namespace` | std::exception (GhidraClass) |
| `signature` | undefined __thiscall exception(exception * this, char * * param_1, int param_2) |
| `size_bytes` | 29 |
| `stack_frame_size` | 12 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0exception@std@@QAE@ABQBDH@Z, std::exception::exception |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::exception::exception(char const * const &,int)
   
   Library: Visual Studio 2008 Release */

void __thiscall std::exception::exception(exception *this,char **param_1,int param_2)

{
  char *pcVar1;
  
  *(undefined ***)this = vftable;
  pcVar1 = *param_1;
  *(undefined4 *)(this + 8) = 0;
  *(char **)(this + 4) = pcVar1;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100118dd` | std::bad_alloc::bad_alloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001118d` | `1002efb4` | `DATA` | std::exception::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011183` | `8b ff` | `MOV EDI,EDI` |
| `10011185` | `55` | `PUSH EBP` |
| `10011186` | `8b ec` | `MOV EBP,ESP` |
| `10011188` | `8b c1` | `MOV EAX,ECX` |
| `1001118a` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001118d` | `c7 00 b4 ef 02 10` | `MOV dword ptr [EAX],0x1002efb4` |
| `10011193` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `10011195` | `83 60 08 00` | `AND dword ptr [EAX + 0x8],0x0` |
| `10011199` | `89 48 04` | `MOV dword ptr [EAX + 0x4],ECX` |
| `1001119c` | `5d` | `POP EBP` |
| `1001119d` | `c2 08 00` | `RET 0x8` |
