# 10019718 `___get_sigabrt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019718 |
| `name` | ___get_sigabrt |
| `namespace` | Global |
| `signature` | _PHNDLR __cdecl ___get_sigabrt(void) |
| `size_bytes` | 13 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___get_sigabrt |

## Decompiled C

```c

/* Library Function - Single Match
    ___get_sigabrt
   
   Library: Visual Studio 2008 Release */

_PHNDLR __cdecl ___get_sigabrt(void)

{
  _PHNDLR p_Var1;
  
  p_Var1 = (_PHNDLR)__decode_pointer(DAT_10039260);
  return p_Var1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001971e` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |

## Callers

| From | Function |
| --- | --- |
| `100179d5` | _abort |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10019718` | `10039260` | `READ` | DAT_10039260 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019718` | `ff 35 60 92 03 10` | `PUSH dword ptr [0x10039260]` |
| `1001971e` | `e8 67 da ff ff` | `CALL 0x1001718a` |
| `10019723` | `59` | `POP ECX` |
| `10019724` | `c3` | `RET` |
