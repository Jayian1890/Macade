# 100049d0 `FID_conflict:invalid_argument`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100049d0 |
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
  *in_ECX = std::out_of_range::vftable;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100049de` | `10001300` | `UNCONDITIONAL_CALL` | FID_conflict:runtime_error | `10001300` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100049e6` | `1002ef80` | `DATA` | std::out_of_range::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100049d0` | `55` | `PUSH EBP` |
| `100049d1` | `8b ec` | `MOV EBP,ESP` |
| `100049d3` | `51` | `PUSH ECX` |
| `100049d4` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100049d7` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100049da` | `50` | `PUSH EAX` |
| `100049db` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100049de` | `e8 1d c9 ff ff` | `CALL 0x10001300` |
| `100049e3` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100049e6` | `c7 01 80 ef 02 10` | `MOV dword ptr [ECX],0x1002ef80` |
| `100049ec` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `100049ef` | `8b e5` | `MOV ESP,EBP` |
| `100049f1` | `5d` | `POP EBP` |
| `100049f2` | `c2 04 00` | `RET 0x4` |
