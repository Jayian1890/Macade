# 1002a2ca `__cropzeros`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a2ca |
| `name` | __cropzeros |
| `namespace` | Global |
| `signature` | void __cdecl __cropzeros(char * _Buf) |
| `size_bytes` | 19 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cropzeros |

## Decompiled C

```c

/* Library Function - Single Match
    __cropzeros
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __cropzeros(char *_Buf)

{
  __cropzeros_l(_Buf,(_locale_t)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a2d4` | `1002a19e` | `UNCONDITIONAL_CALL` | __cropzeros_l | `1002a19e` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a2ca` | `8b ff` | `MOV EDI,EDI` |
| `1002a2cc` | `55` | `PUSH EBP` |
| `1002a2cd` | `8b ec` | `MOV EBP,ESP` |
| `1002a2cf` | `6a 00` | `PUSH 0x0` |
| `1002a2d1` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002a2d4` | `e8 c5 fe ff ff` | `CALL 0x1002a19e` |
| `1002a2d9` | `59` | `POP ECX` |
| `1002a2da` | `59` | `POP ECX` |
| `1002a2db` | `5d` | `POP EBP` |
| `1002a2dc` | `c3` | `RET` |
