# 10019a06 `__vsnprintf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019a06 |
| `name` | __vsnprintf |
| `namespace` | Global |
| `signature` | int __cdecl __vsnprintf(char * _Dest, size_t _Count, char * _Format, va_list _Args) |
| `size_bytes` | 29 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __vsnprintf |

## Decompiled C

```c

/* Library Function - Single Match
    __vsnprintf
   
   Library: Visual Studio 2008 Release */

int __cdecl __vsnprintf(char *_Dest,size_t _Count,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsnprintf_l(_Dest,_Count,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019a19` | `10019953` | `UNCONDITIONAL_CALL` | __vsnprintf_l | `10019953` |

## Callers

| From | Function |
| --- | --- |
| `1002457e` | FUN_10024520 |
| `10022cae` | FUN_10022c50 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019a06` | `8b ff` | `MOV EDI,EDI` |
| `10019a08` | `55` | `PUSH EBP` |
| `10019a09` | `8b ec` | `MOV EBP,ESP` |
| `10019a0b` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `10019a0e` | `6a 00` | `PUSH 0x0` |
| `10019a10` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10019a13` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10019a16` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019a19` | `e8 35 ff ff ff` | `CALL 0x10019953` |
| `10019a1e` | `83 c4 14` | `ADD ESP,0x14` |
| `10019a21` | `5d` | `POP EBP` |
| `10019a22` | `c3` | `RET` |
