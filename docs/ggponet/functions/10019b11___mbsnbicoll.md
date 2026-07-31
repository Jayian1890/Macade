# 10019b11 `__mbsnbicoll`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019b11 |
| `name` | __mbsnbicoll |
| `namespace` | Global |
| `signature` | int __cdecl __mbsnbicoll(uchar * _Str1, uchar * _Str2, size_t _MaxCount) |
| `size_bytes` | 26 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbsnbicoll |

## Decompiled C

```c

/* Library Function - Single Match
    __mbsnbicoll
   
   Library: Visual Studio 2008 Release */

int __cdecl __mbsnbicoll(uchar *_Str1,uchar *_Str2,size_t _MaxCount)

{
  int iVar1;
  
  iVar1 = __mbsnbicoll_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019b21` | `10019a23` | `UNCONDITIONAL_CALL` | __mbsnbicoll_l | `10019a23` |

## Callers

| From | Function |
| --- | --- |
| `10012d2f` | __getenv_helper_nolock |
| `1001e374` | findenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019b11` | `8b ff` | `MOV EDI,EDI` |
| `10019b13` | `55` | `PUSH EBP` |
| `10019b14` | `8b ec` | `MOV EBP,ESP` |
| `10019b16` | `6a 00` | `PUSH 0x0` |
| `10019b18` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10019b1b` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10019b1e` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019b21` | `e8 fd fe ff ff` | `CALL 0x10019a23` |
| `10019b26` | `83 c4 10` | `ADD ESP,0x10` |
| `10019b29` | `5d` | `POP EBP` |
| `10019b2a` | `c3` | `RET` |
