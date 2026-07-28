# 1001faca `__mbschr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001faca |
| `name` | __mbschr |
| `namespace` | Global |
| `signature` | uchar * __cdecl __mbschr(uchar * _Str, uint _Ch) |
| `size_bytes` | 23 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbschr |

## Decompiled C

```c

/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 2008 Release */

uchar * __cdecl __mbschr(uchar *_Str,uint _Ch)

{
  uchar *puVar1;
  
  puVar1 = __mbschr_l(_Str,_Ch,(_locale_t)0x0);
  return puVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001fad7` | `1001fa0e` | `UNCONDITIONAL_CALL` | __mbschr_l | `1001fa0e` |

## Callers

| From | Function |
| --- | --- |
| `1001e44d` | ___crtsetenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001faca` | `8b ff` | `MOV EDI,EDI` |
| `1001facc` | `55` | `PUSH EBP` |
| `1001facd` | `8b ec` | `MOV EBP,ESP` |
| `1001facf` | `6a 00` | `PUSH 0x0` |
| `1001fad1` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001fad4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001fad7` | `e8 32 ff ff ff` | `CALL 0x1001fa0e` |
| `1001fadc` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001fadf` | `5d` | `POP EBP` |
| `1001fae0` | `c3` | `RET` |
