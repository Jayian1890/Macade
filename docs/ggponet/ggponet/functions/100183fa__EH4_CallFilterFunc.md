# 100183fa `_EH4_CallFilterFunc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100183fa |
| `name` | _EH4_CallFilterFunc |
| `namespace` | Global |
| `signature` | undefined __fastcall _EH4_CallFilterFunc(void) |
| `size_bytes` | 23 |
| `stack_frame_size` | 4 |
| `calling_convention` | __fastcall |
| `source_type` | ANALYSIS |
| `export_names` | @_EH4_CallFilterFunc@8, _EH4_CallFilterFunc |

## Decompiled C

```c

/* Library Function - Single Match
    @_EH4_CallFilterFunc@8
   
   Library: Visual Studio 2008 Release
   __fastcall _EH4_CallFilterFunc,8 */

void __fastcall _EH4_CallFilterFunc(code *param_1)

{
  (*param_1)();
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10016de9` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100183fa` | `55` | `PUSH EBP` |
| `100183fb` | `56` | `PUSH ESI` |
| `100183fc` | `57` | `PUSH EDI` |
| `100183fd` | `53` | `PUSH EBX` |
| `100183fe` | `8b ea` | `MOV EBP,EDX` |
| `10018400` | `33 c0` | `XOR EAX,EAX` |
| `10018402` | `33 db` | `XOR EBX,EBX` |
| `10018404` | `33 d2` | `XOR EDX,EDX` |
| `10018406` | `33 f6` | `XOR ESI,ESI` |
| `10018408` | `33 ff` | `XOR EDI,EDI` |
| `1001840a` | `ff d1` | `CALL ECX` |
| `1001840c` | `5b` | `POP EBX` |
| `1001840d` | `5f` | `POP EDI` |
| `1001840e` | `5e` | `POP ESI` |
| `1001840f` | `5d` | `POP EBP` |
| `10018410` | `c3` | `RET` |
