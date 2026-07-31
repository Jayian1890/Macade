# 1002a04f `__fpmath`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a04f |
| `name` | __fpmath |
| `namespace` | Global |
| `signature` | void __cdecl __fpmath(int param_1) |
| `size_bytes` | 35 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fpmath |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __fpmath
   
   Library: Visual Studio 2008 Release */

void __cdecl __fpmath(int param_1)

{
  __cfltcvt_init();
  _DAT_13439528 = __ms_p5_mp_test_fdiv();
  if (param_1 != 0) {
    __setdefaultprecision();
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a054` | `10029fef` | `UNCONDITIONAL_CALL` | __cfltcvt_init | `10029fef` |
| `1002a059` | `1002ac6f` | `UNCONDITIONAL_CALL` | __ms_p5_mp_test_fdiv | `1002ac6f` |
| `1002a069` | `1002ac06` | `UNCONDITIONAL_CALL` | __setdefaultprecision | `1002ac06` |

## Callers

| From | Function |
| --- | --- |
| `1001251b` | __cinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002a062` | `13439528` | `WRITE` | DAT_13439528 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a04f` | `8b ff` | `MOV EDI,EDI` |
| `1002a051` | `55` | `PUSH EBP` |
| `1002a052` | `8b ec` | `MOV EBP,ESP` |
| `1002a054` | `e8 96 ff ff ff` | `CALL 0x10029fef` |
| `1002a059` | `e8 11 0c 00 00` | `CALL 0x1002ac6f` |
| `1002a05e` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1002a062` | `a3 28 95 43 13` | `MOV [0x13439528],EAX` |
| `1002a067` | `74 05` | `JZ 0x1002a06e` |
| `1002a069` | `e8 98 0b 00 00` | `CALL 0x1002ac06` |
| `1002a06e` | `db e2` | `FNCLEX` |
| `1002a070` | `5d` | `POP EBP` |
| `1002a071` | `c3` | `RET` |
