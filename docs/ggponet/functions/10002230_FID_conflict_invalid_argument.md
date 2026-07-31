# 10002230 `FID_conflict:invalid_argument`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10002230 |
| `name` | FID_conflict:invalid_argument |
| `namespace` | Global |
| `signature` | undefined FID_conflict:invalid_argument(void) |
| `size_bytes` | 37 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??0failure@ios_base@std@@QAE@ABV012@@Z, ??0invalid_argument@std@@QAE@ABV01@@Z, ??0length_error@std@@QAE@ABV01@@Z, ??0out_of_range@std@@QAE@ABV01@@Z, FID_conflict:invalid_argument |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::ios_base::failure::failure(class std::ios_base::failure const &)
    public: __thiscall std::invalid_argument::invalid_argument(class std::invalid_argument const &)
    public: __thiscall std::length_error::length_error(class std::length_error const &)
    public: __thiscall std::out_of_range::out_of_range(class std::out_of_range const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 * FID_conflict_invalid_argument(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FID_conflict_runtime_error(param_1);
  *in_ECX = std::length_error::vftable;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000223e` | `10001300` | `UNCONDITIONAL_CALL` | FID_conflict:runtime_error | `10001300` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10002246` | `1002ef74` | `DATA` | std::length_error::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10002230` | `55` | `PUSH EBP` |
| `10002231` | `8b ec` | `MOV EBP,ESP` |
| `10002233` | `51` | `PUSH ECX` |
| `10002234` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10002237` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1000223a` | `50` | `PUSH EAX` |
| `1000223b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000223e` | `e8 bd f0 ff ff` | `CALL 0x10001300` |
| `10002243` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10002246` | `c7 01 74 ef 02 10` | `MOV dword ptr [ECX],0x1002ef74` |
| `1000224c` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000224f` | `8b e5` | `MOV ESP,EBP` |
| `10002251` | `5d` | `POP EBP` |
| `10002252` | `c2 04 00` | `RET 0x4` |
