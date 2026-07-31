# 1002a2b7 `__forcdecpt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a2b7 |
| `name` | __forcdecpt |
| `namespace` | Global |
| `signature` | void __cdecl __forcdecpt(char * _Buf) |
| `size_bytes` | 19 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __forcdecpt |

## Decompiled C

```c

/* Library Function - Single Match
    __forcdecpt
   
   Library: Visual Studio 2008 Release */

void __cdecl __forcdecpt(char *_Buf)

{
  __forcdecpt_l(_Buf,(_locale_t)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a2c1` | `1002a12b` | `UNCONDITIONAL_CALL` | __forcdecpt_l | `1002a12b` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a2b7` | `8b ff` | `MOV EDI,EDI` |
| `1002a2b9` | `55` | `PUSH EBP` |
| `1002a2ba` | `8b ec` | `MOV EBP,ESP` |
| `1002a2bc` | `6a 00` | `PUSH 0x0` |
| `1002a2be` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002a2c1` | `e8 65 fe ff ff` | `CALL 0x1002a12b` |
| `1002a2c6` | `59` | `POP ECX` |
| `1002a2c7` | `59` | `POP ECX` |
| `1002a2c8` | `5d` | `POP EBP` |
| `1002a2c9` | `c3` | `RET` |
