# 1001d95d `__mbsnbcmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d95d |
| `name` | __mbsnbcmp |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbcmp(uchar * _Str1, uchar * _Str2, size_t _MaxCount) |
| `size_bytes` | 26 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbcmp |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbcmp
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbcmp(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  iVar1 = __mbsnbcmp_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d96d` | `1001d7f3` | `UNCONDITIONAL_CALL` | __mbsnbcmp_l | `1001d7f3` |

## Callers

| From | Function |
| --- | --- |
| `100180dc` | __openfile |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d95d` | `8b ff` | `MOV EDI,EDI` |
| `1001d95f` | `55` | `PUSH EBP` |
| `1001d960` | `8b ec` | `MOV EBP,ESP` |
| `1001d962` | `6a 00` | `PUSH 0x0` |
| `1001d964` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d967` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d96a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d96d` | `e8 81 fe ff ff` | `CALL 0x1001d7f3` |
| `1001d972` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d975` | `5d` | `POP EBP` |
| `1001d976` | `c3` | `RET` |
