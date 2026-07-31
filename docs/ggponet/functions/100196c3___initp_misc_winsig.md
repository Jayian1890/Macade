# 100196c3 `__initp_misc_winsig`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100196c3 |
| `name` | __initp_misc_winsig |
| `namespace` | Global |
| `signature` | undefined __initp_misc_winsig(void) |
| `size_bytes` | 30 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __initp_misc_winsig |

## Decompiled C

```c

/* Library Function - Single Match
    __initp_misc_winsig
   
   Library: Visual Studio 2008 Release */

void __initp_misc_winsig(undefined4 param_1)

{
  DAT_10039258 = param_1;
  DAT_1003925c = param_1;
  DAT_10039260 = param_1;
  DAT_10039264 = param_1;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10012710` | __init_pointers |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100196cb` | `10039258` | `WRITE` | DAT_10039258 |
| `100196d0` | `1003925c` | `WRITE` | DAT_1003925c |
| `100196d5` | `10039260` | `WRITE` | DAT_10039260 |
| `100196da` | `10039264` | `WRITE` | DAT_10039264 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100196c3` | `8b ff` | `MOV EDI,EDI` |
| `100196c5` | `55` | `PUSH EBP` |
| `100196c6` | `8b ec` | `MOV EBP,ESP` |
| `100196c8` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100196cb` | `a3 58 92 03 10` | `MOV [0x10039258],EAX` |
| `100196d0` | `a3 5c 92 03 10` | `MOV [0x1003925c],EAX` |
| `100196d5` | `a3 60 92 03 10` | `MOV [0x10039260],EAX` |
| `100196da` | `a3 64 92 03 10` | `MOV [0x10039264],EAX` |
| `100196df` | `5d` | `POP EBP` |
| `100196e0` | `c3` | `RET` |
