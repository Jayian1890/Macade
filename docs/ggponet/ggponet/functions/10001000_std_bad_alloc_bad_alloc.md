# 10001000 `std::bad_alloc::bad_alloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10001000 |
| `name` | std::bad_alloc::bad_alloc |
| `namespace` | std::bad_alloc (GhidraClass) |
| `signature` | undefined __thiscall bad_alloc(bad_alloc * this, char * param_1) |
| `size_bytes` | 37 |
| `stack_frame_size` | 16 |
| `calling_convention` | __thiscall |
| `source_type` | ANALYSIS |
| `export_names` | ??0bad_alloc@std@@QAE@PBD@Z, std::bad_alloc::bad_alloc |

## Decompiled C

```c

/* Library Function - Single Match
    public: __thiscall std::bad_alloc::bad_alloc(char const *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this,char *param_1)

{
  exception::exception((exception *)this,&param_1);
  *(undefined ***)this = vftable;
  return this;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000100e` | `10011130` | `UNCONDITIONAL_CALL` | std::exception::exception | `10011130` |

## Callers

| From | Function |
| --- | --- |
| `10002747` | std::_Allocate<char> |
| `10003dc7` | FUN_10003da0 |
| `100034f7` | FUN_100034d0 |
| `100077a7` | FUN_10007780 |
| `10008887` | FUN_10008860 |
| `10008837` | FUN_10008810 |
| `100026a7` | FUN_10002680 |
| `10003d27` | FUN_10003d00 |
| `1000b0d7` | FUN_1000b0b0 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10001016` | `1002ef5c` | `DATA` | std::bad_alloc::vftable |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10001000` | `55` | `PUSH EBP` |
| `10001001` | `8b ec` | `MOV EBP,ESP` |
| `10001003` | `51` | `PUSH ECX` |
| `10001004` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10001007` | `8d 45 08` | `LEA EAX,[EBP + 0x8]` |
| `1000100a` | `50` | `PUSH EAX` |
| `1000100b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1000100e` | `e8 1d 01 01 00` | `CALL 0x10011130` |
| `10001013` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10001016` | `c7 01 5c ef 02 10` | `MOV dword ptr [ECX],0x1002ef5c` |
| `1000101c` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `1000101f` | `8b e5` | `MOV ESP,EBP` |
| `10001021` | `5d` | `POP EBP` |
| `10001022` | `c2 04 00` | `RET 0x4` |
