# 1002ac31 `__ms_p5_test_fdiv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ac31 |
| `name` | __ms_p5_test_fdiv |
| `namespace` | Global |
| `signature` | undefined __ms_p5_test_fdiv(void) |
| `size_bytes` | 62 |
| `stack_frame_size` | 32 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __ms_p5_test_fdiv |

## Decompiled C

```c

/* WARNING: Removing unreachable block (ram,0x1002ac66) */
/* Library Function - Single Match
    __ms_p5_test_fdiv
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

undefined4 __ms_p5_test_fdiv(void)

{
  return 0;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002ac93` | __ms_p5_mp_test_fdiv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002ac39` | `10033490` | `READ` | DAT_10033490 |
| `1002ac42` | `10033488` | `READ` | DAT_10033488 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ac31` | `8b ff` | `MOV EDI,EDI` |
| `1002ac33` | `55` | `PUSH EBP` |
| `1002ac34` | `8b ec` | `MOV EBP,ESP` |
| `1002ac36` | `83 ec 18` | `SUB ESP,0x18` |
| `1002ac39` | `dd 05 90 34 03 10` | `FLD double ptr [0x10033490]` |
| `1002ac3f` | `dd 5d f0` | `FSTP double ptr [EBP + -0x10]` |
| `1002ac42` | `dd 05 88 34 03 10` | `FLD double ptr [0x10033488]` |
| `1002ac48` | `dd 5d e8` | `FSTP double ptr [EBP + -0x18]` |
| `1002ac4b` | `dd 45 e8` | `FLD double ptr [EBP + -0x18]` |
| `1002ac4e` | `dc 75 f0` | `FDIV double ptr [EBP + -0x10]` |
| `1002ac51` | `dc 4d f0` | `FMUL double ptr [EBP + -0x10]` |
| `1002ac54` | `dc 6d e8` | `FSUBR double ptr [EBP + -0x18]` |
| `1002ac57` | `dd 5d f8` | `FSTP double ptr [EBP + -0x8]` |
| `1002ac5a` | `d9 e8` | `FLD1` |
| `1002ac5c` | `dc 5d f8` | `FCOMP double ptr [EBP + -0x8]` |
| `1002ac5f` | `df e0` | `FNSTSW AX` |
| `1002ac61` | `f6 c4 05` | `TEST AH,0x5` |
| `1002ac64` | `7a 05` | `JP 0x1002ac6b` |
| `1002ac66` | `33 c0` | `XOR EAX,EAX` |
| `1002ac68` | `40` | `INC EAX` |
| `1002ac69` | `c9` | `LEAVE` |
| `1002ac6a` | `c3` | `RET` |
| `1002ac6b` | `33 c0` | `XOR EAX,EAX` |
| `1002ac6d` | `c9` | `LEAVE` |
| `1002ac6e` | `c3` | `RET` |
