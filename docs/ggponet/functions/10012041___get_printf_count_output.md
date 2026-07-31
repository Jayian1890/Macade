# 10012041 `__get_printf_count_output`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10012041 |
| `name` | __get_printf_count_output |
| `namespace` | Global |
| `signature` | int __cdecl __get_printf_count_output(void) |
| `size_bytes` | 22 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __get_printf_count_output |

## Decompiled C

```c

/* Library Function - Single Match
    __get_printf_count_output
   
   Library: Visual Studio 2008 Release */

int __cdecl __get_printf_count_output(void)

{
  return (uint)(DAT_10038a38 == (DAT_10037490 | 1));
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10015a12` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012041` | `10037490` | `READ` | DAT_10037490 |
| `1001204b` | `10038a38` | `READ` | DAT_10038a38 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10012041` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10012046` | `83 c8 01` | `OR EAX,0x1` |
| `10012049` | `33 c9` | `XOR ECX,ECX` |
| `1001204b` | `39 05 38 8a 03 10` | `CMP dword ptr [0x10038a38],EAX` |
| `10012051` | `0f 94 c1` | `SETZ CL` |
| `10012054` | `8b c1` | `MOV EAX,ECX` |
| `10012056` | `c3` | `RET` |
