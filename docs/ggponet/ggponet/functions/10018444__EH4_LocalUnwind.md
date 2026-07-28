# 10018444 `_EH4_LocalUnwind`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018444 |
| `name` | _EH4_LocalUnwind |
| `namespace` | Global |
| `signature` | undefined __fastcall _EH4_LocalUnwind(void) |
| `size_bytes` | 23 |
| `stack_frame_size` | 4 |
| `calling_convention` | __fastcall |
| `source_type` | ANALYSIS |
| `export_names` | @_EH4_LocalUnwind@16, _EH4_LocalUnwind |

## Decompiled C

```c

/* Library Function - Single Match
    @_EH4_LocalUnwind@16
   
   Library: Visual Studio 2008 Release
   __fastcall _EH4_LocalUnwind,16 */

void __fastcall
_EH4_LocalUnwind(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  __local_unwind4(param_4,param_1,param_2);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001844f` | `10018308` | `UNCONDITIONAL_CALL` | __local_unwind4 | `10018308` |

## Callers

| From | Function |
| --- | --- |
| `10016e8d` | __except_handler4 |
| `10016ee2` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018444` | `55` | `PUSH EBP` |
| `10018445` | `8b 6c 24 08` | `MOV EBP,dword ptr [ESP + 0x8]` |
| `10018449` | `52` | `PUSH EDX` |
| `1001844a` | `51` | `PUSH ECX` |
| `1001844b` | `ff 74 24 14` | `PUSH dword ptr [ESP + 0x14]` |
| `1001844f` | `e8 b4 fe ff ff` | `CALL 0x10018308` |
| `10018454` | `83 c4 0c` | `ADD ESP,0xc` |
| `10018457` | `5d` | `POP EBP` |
| `10018458` | `c2 08 00` | `RET 0x8` |
