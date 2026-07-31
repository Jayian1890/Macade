# 10004950 `FID_conflict:length_error`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10004950 |
| `name` | FID_conflict:length_error |
| `namespace` | Global |
| `signature` | undefined FID_conflict:length_error(void) |
| `size_bytes` | 37 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??0failure@ios_base@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@2@@Z, ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z, ??0length_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z, ??0out_of_range@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z, FID_conflict:length_error |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::ios_base::failure::failure(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::invalid_argument::invalid_argument(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::length_error::length_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::out_of_range::out_of_range(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 * FID_conflict_length_error(undefined4 param_1)

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
| `1000495e` | `10001190` | `UNCONDITIONAL_CALL` | FID_conflict:runtime_error | `10001190` |

## Callers

| From | Function |
| --- | --- |
| `1000650c` | FUN_100064b0 |
| `10010cac` | FUN_10010c88 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10004966` | `1002ef80` | `DATA` | std::out_of_range::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10004950` | `55` | `PUSH EBP` |
| `10004951` | `8b ec` | `MOV EBP,ESP` |
| `10004953` | `51` | `PUSH ECX` |
| `10004954` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10004957` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1000495a` | `50` | `PUSH EAX` |
| `1000495b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000495e` | `e8 2d c8 ff ff` | `CALL 0x10001190` |
| `10004963` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10004966` | `c7 01 80 ef 02 10` | `MOV dword ptr [ECX],0x1002ef80` |
| `1000496c` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000496f` | `8b e5` | `MOV ESP,EBP` |
| `10004971` | `5d` | `POP EBP` |
| `10004972` | `c2 04 00` | `RET 0x4` |
