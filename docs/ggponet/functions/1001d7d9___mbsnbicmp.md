# 1001d7d9 `__mbsnbicmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d7d9 |
| `name` | __mbsnbicmp |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbicmp(uchar * _Str1, uchar * _Str2, size_t _MaxCount) |
| `size_bytes` | 26 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbicmp |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbicmp
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbicmp(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  iVar1 = __mbsnbicmp_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d7e9` | `1001d5ae` | `UNCONDITIONAL_CALL` | __mbsnbicmp_l | `1001d5ae` |

## Callers

| From | Function |
| --- | --- |
| `1001810a` | __openfile |
| `1001812a` | __openfile |
| `1001814a` | __openfile |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d7d9` | `8b ff` | `MOV EDI,EDI` |
| `1001d7db` | `55` | `PUSH EBP` |
| `1001d7dc` | `8b ec` | `MOV EBP,ESP` |
| `1001d7de` | `6a 00` | `PUSH 0x0` |
| `1001d7e0` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d7e3` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d7e6` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d7e9` | `e8 c0 fd ff ff` | `CALL 0x1001d5ae` |
| `1001d7ee` | `83 c4 10` | `ADD ESP,0x10` |
| `1001d7f1` | `5d` | `POP EBP` |
| `1001d7f2` | `c3` | `RET` |
