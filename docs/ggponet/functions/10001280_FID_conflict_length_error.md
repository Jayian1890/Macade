# 10001280 `FID_conflict:length_error`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001280 |
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
  *in_ECX = std::length_error::vftable;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000128e` | `10001190` | `UNCONDITIONAL_CALL` | FID_conflict:runtime_error | `10001190` |

## Callers

| From | Function |
| --- | --- |
| `10010c74` | FUN_10010c50 |
| `10004600` | FUN_100045c0 |
| `100096c0` | FUN_10009680 |
| `100020c6` | FUN_10002070 |
| `10005e27` | FUN_10005dd0 |
| `10008296` | FUN_10008240 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10001296` | `1002ef74` | `DATA` | std::length_error::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001280` | `55` | `PUSH EBP` |
| `10001281` | `8b ec` | `MOV EBP,ESP` |
| `10001283` | `51` | `PUSH ECX` |
| `10001284` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001287` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1000128a` | `50` | `PUSH EAX` |
| `1000128b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000128e` | `e8 fd fe ff ff` | `CALL 0x10001190` |
| `10001293` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001296` | `c7 01 74 ef 02 10` | `MOV dword ptr [ECX],0x1002ef74` |
| `1000129c` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000129f` | `8b e5` | `MOV ESP,EBP` |
| `100012a1` | `5d` | `POP EBP` |
| `100012a2` | `c2 04 00` | `RET 0x4` |
