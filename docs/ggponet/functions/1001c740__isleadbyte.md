# 1001c740 `_isleadbyte`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c740 |
| `name` | _isleadbyte |
| `namespace` | Global |
| `signature` | int __cdecl _isleadbyte(int _C) |
| `size_bytes` | 19 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _isleadbyte |

## Decompiled C

```c

/* Library Function - Single Match
    _isleadbyte
   
   Library: Visual Studio 2008 Release */

int __cdecl _isleadbyte(int _C)

{
  int iVar1;
  
  iVar1 = __isleadbyte_l(_C,(_locale_t)0x0);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c74a` | `1001c708` | `UNCONDITIONAL_CALL` | __isleadbyte_l | `1001c708` |

## Callers

| From | Function |
| --- | --- |
| `10019d96` | __write_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c740` | `8b ff` | `MOV EDI,EDI` |
| `1001c742` | `55` | `PUSH EBP` |
| `1001c743` | `8b ec` | `MOV EBP,ESP` |
| `1001c745` | `6a 00` | `PUSH 0x0` |
| `1001c747` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001c74a` | `e8 b9 ff ff ff` | `CALL 0x1001c708` |
| `1001c74f` | `59` | `POP ECX` |
| `1001c750` | `59` | `POP ECX` |
| `1001c751` | `5d` | `POP EBP` |
| `1001c752` | `c3` | `RET` |
