# 10001190 `FID_conflict:runtime_error`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001190 |
| `name` | FID_conflict:runtime_error |
| `namespace` | Global |
| `signature` | undefined FID_conflict:runtime_error(void) |
| `size_bytes` | 104 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ??0logic_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z, ??0runtime_error@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z, FID_conflict:runtime_error |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::logic_error::logic_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::runtime_error::runtime_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 * FID_conflict_runtime_error(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001111f(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = std::logic_error::vftable;
  FUN_10001540(param_1);
  ExceptionList = local_10;
  return in_ECX;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100011b9` | `1001111f` | `UNCONDITIONAL_CALL` | FUN_1001111f | `1001111f` |
| `100011d8` | `10001540` | `UNCONDITIONAL_CALL` | FUN_10001540 | `10001540` |

## Callers

| From | Function |
| --- | --- |
| `1000495e` | FID_conflict:length_error |
| `1000128e` | FID_conflict:length_error |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10001195` | `1002d808` | `DATA` | LAB_1002d808 |
| `1000119a` | `ffdff000` | `READ` | ExceptionList |
| `100011a2` | `10037490` | `READ` | DAT_10037490 |
| `100011ad` | `ffdff000` | `WRITE` | ExceptionList |
| `100011c8` | `1002ef68` | `DATA` | std::logic_error::vftable |
| `100011ea` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001190` | `55` | `PUSH EBP` |
| `10001191` | `8b ec` | `MOV EBP,ESP` |
| `10001193` | `6a ff` | `PUSH -0x1` |
| `10001195` | `68 08 d8 02 10` | `PUSH 0x1002d808` |
| `1000119a` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `100011a0` | `50` | `PUSH EAX` |
| `100011a1` | `51` | `PUSH ECX` |
| `100011a2` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `100011a7` | `33 c5` | `XOR EAX,EBP` |
| `100011a9` | `50` | `PUSH EAX` |
| `100011aa` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `100011ad` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `100011b3` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `100011b6` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `100011b9` | `e8 61 ff 00 00` | `CALL 0x1001111f` |
| `100011be` | `c7 45 fc 00 00 00 00` | `MOV dword ptr [EBP + -0x4],0x0` |
| `100011c5` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100011c8` | `c7 00 68 ef 02 10` | `MOV dword ptr [EAX],0x1002ef68` |
| `100011ce` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100011d1` | `51` | `PUSH ECX` |
| `100011d2` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `100011d5` | `83 c1 0c` | `ADD ECX,0xc` |
| `100011d8` | `e8 63 03 00 00` | `CALL 0x10001540` |
| `100011dd` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `100011e4` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `100011e7` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `100011ea` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `100011f1` | `59` | `POP ECX` |
| `100011f2` | `8b e5` | `MOV ESP,EBP` |
| `100011f4` | `5d` | `POP EBP` |
| `100011f5` | `c2 04 00` | `RET 0x4` |
