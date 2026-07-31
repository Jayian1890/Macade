# 1001842a `_EH4_GlobalUnwind`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001842a |
| `name` | _EH4_GlobalUnwind |
| `namespace` | Global |
| `signature` | undefined __fastcall _EH4_GlobalUnwind(void) |
| `size_bytes` | 26 |
| `stack_frame_size` | 4 |
| `calling_convention` | __fastcall |
| `source_type` | ANALYSIS |
| `export_names` | @_EH4_GlobalUnwind@4, _EH4_GlobalUnwind |

## Decompiled C

```c

/* Library Function - Single Match
    @_EH4_GlobalUnwind@4
   
   Library: Visual Studio 2008 Release
   __fastcall _EH4_GlobalUnwind,4 */

void __fastcall _EH4_GlobalUnwind(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x1001843f,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001843a` | `1001fcd2` | `UNCONDITIONAL_CALL` | KERNEL32.DLL::RtlUnwind | `1001fcd2` |

## Callers

| From | Function |
| --- | --- |
| `10016e76` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001842a` | `55` | `PUSH EBP` |
| `1001842b` | `8b ec` | `MOV EBP,ESP` |
| `1001842d` | `53` | `PUSH EBX` |
| `1001842e` | `56` | `PUSH ESI` |
| `1001842f` | `57` | `PUSH EDI` |
| `10018430` | `6a 00` | `PUSH 0x0` |
| `10018432` | `6a 00` | `PUSH 0x0` |
| `10018434` | `68 3f 84 01 10` | `PUSH 0x1001843f` |
| `10018439` | `51` | `PUSH ECX` |
| `1001843a` | `e8 93 78 00 00` | `CALL 0x1001fcd2` |
| `1001843f` | `5f` | `POP EDI` |
| `10018440` | `5e` | `POP ESI` |
| `10018441` | `5b` | `POP EBX` |
| `10018442` | `5d` | `POP EBP` |
| `10018443` | `c3` | `RET` |
