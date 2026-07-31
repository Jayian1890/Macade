# 10011f78 `_vsprintf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011f78 |
| `name` | _vsprintf |
| `namespace` | Global |
| `signature` | int __cdecl _vsprintf(char * _Dest, char * _Format, va_list _Args) |
| `size_bytes` | 26 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _vsprintf |

## Decompiled C

```c

/* Library Function - Single Match
    _vsprintf
   
   Library: Visual Studio 2008 Release */

int __cdecl _vsprintf(char *_Dest,char *_Format,va_list _Args)

{
  int iVar1;
  
  iVar1 = __vsprintf_l(_Dest,_Format,(_locale_t)0x0,_Args);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011f88` | `10011efa` | `UNCONDITIONAL_CALL` | __vsprintf_l | `10011efa` |

## Callers

| From | Function |
| --- | --- |
| `10021f57` | FUN_10021ec0 |
| `10027468` | FUN_10027440 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011f78` | `8b ff` | `MOV EDI,EDI` |
| `10011f7a` | `55` | `PUSH EBP` |
| `10011f7b` | `8b ec` | `MOV EBP,ESP` |
| `10011f7d` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10011f80` | `6a 00` | `PUSH 0x0` |
| `10011f82` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10011f85` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10011f88` | `e8 6d ff ff ff` | `CALL 0x10011efa` |
| `10011f8d` | `83 c4 10` | `ADD ESP,0x10` |
| `10011f90` | `5d` | `POP EBP` |
| `10011f91` | `c3` | `RET` |
