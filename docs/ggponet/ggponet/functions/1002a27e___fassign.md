# 1002a27e `__fassign`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a27e |
| `name` | __fassign |
| `namespace` | Global |
| `signature` | void __cdecl __fassign(int flag, char * argument, char * number) |
| `size_bytes` | 26 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fassign |

## Decompiled C

```c

/* Library Function - Single Match
    __fassign
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __fassign(int flag,char *argument,char *number)

{
  __fassign_l(flag,argument,number,(_locale_t)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a28e` | `1002a23c` | `UNCONDITIONAL_CALL` | __fassign_l | `1002a23c` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a27e` | `8b ff` | `MOV EDI,EDI` |
| `1002a280` | `55` | `PUSH EBP` |
| `1002a281` | `8b ec` | `MOV EBP,ESP` |
| `1002a283` | `6a 00` | `PUSH 0x0` |
| `1002a285` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002a288` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002a28b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002a28e` | `e8 a9 ff ff ff` | `CALL 0x1002a23c` |
| `1002a293` | `83 c4 10` | `ADD ESP,0x10` |
| `1002a296` | `5d` | `POP EBP` |
| `1002a297` | `c3` | `RET` |
