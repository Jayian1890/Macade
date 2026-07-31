# 1001f633 `__get_fmode`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f633 |
| `name` | __get_fmode |
| `namespace` | Global |
| `signature` | errno_t __cdecl __get_fmode(int * _PMode) |
| `size_bytes` | 57 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __get_fmode |

## Decompiled C

```c

/* Library Function - Single Match
    __get_fmode
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl __get_fmode(int *_PMode)

{
  int *piVar1;
  errno_t eVar2;
  
  if (_PMode == (int *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    eVar2 = 0x16;
  }
  else {
    *_PMode = DAT_100394e0;
    eVar2 = 0;
  }
  return eVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f642` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f652` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |

## Callers

| From | Function |
| --- | --- |
| `1001cddf` | __tsopen_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f65f` | `100394e0` | `READ` | DAT_100394e0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f633` | `8b ff` | `MOV EDI,EDI` |
| `1001f635` | `55` | `PUSH EBP` |
| `1001f636` | `8b ec` | `MOV EBP,ESP` |
| `1001f638` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001f63b` | `56` | `PUSH ESI` |
| `1001f63c` | `33 f6` | `XOR ESI,ESI` |
| `1001f63e` | `3b c6` | `CMP EAX,ESI` |
| `1001f640` | `75 1d` | `JNZ 0x1001f65f` |
| `1001f642` | `e8 c2 5a ff ff` | `CALL 0x10015109` |
| `1001f647` | `56` | `PUSH ESI` |
| `1001f648` | `56` | `PUSH ESI` |
| `1001f649` | `56` | `PUSH ESI` |
| `1001f64a` | `56` | `PUSH ESI` |
| `1001f64b` | `56` | `PUSH ESI` |
| `1001f64c` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001f652` | `e8 58 20 ff ff` | `CALL 0x100116af` |
| `1001f657` | `83 c4 14` | `ADD ESP,0x14` |
| `1001f65a` | `6a 16` | `PUSH 0x16` |
| `1001f65c` | `58` | `POP EAX` |
| `1001f65d` | `eb 0a` | `JMP 0x1001f669` |
| `1001f65f` | `8b 0d e0 94 03 10` | `MOV ECX,dword ptr [0x100394e0]` |
| `1001f665` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1001f667` | `33 c0` | `XOR EAX,EAX` |
| `1001f669` | `5e` | `POP ESI` |
| `1001f66a` | `5d` | `POP EBP` |
| `1001f66b` | `c3` | `RET` |
