# 10018411 `_EH4_TransferToHandler`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018411 |
| `name` | _EH4_TransferToHandler |
| `namespace` | Global |
| `signature` | undefined __fastcall _EH4_TransferToHandler(void) |
| `size_bytes` | 25 |
| `stack_frame_size` | 4 |
| `calling_convention` | __fastcall |
| `source_type` | ANALYSIS |
| `export_names` | @_EH4_TransferToHandler@8, _EH4_TransferToHandler |

## Decompiled C

```c

/* Library Function - Single Match
    @_EH4_TransferToHandler@8
   
   Library: Visual Studio 2008 Release
   __fastcall _EH4_TransferToHandler,8 */

void __fastcall _EH4_TransferToHandler(code *UNRECOVERED_JUMPTABLE)

{
  __NLG_Notify(1);
                    /* WARNING: Could not recover jumptable at 0x10018428. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018419` | `1001da8d` | `UNCONDITIONAL_CALL` | __NLG_Notify | `1001da8d` |

## Callers

| From | Function |
| --- | --- |
| `10016ec7` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018411` | `8b ea` | `MOV EBP,EDX` |
| `10018413` | `8b f1` | `MOV ESI,ECX` |
| `10018415` | `8b c1` | `MOV EAX,ECX` |
| `10018417` | `6a 01` | `PUSH 0x1` |
| `10018419` | `e8 6f 56 00 00` | `CALL 0x1001da8d` |
| `1001841e` | `33 c0` | `XOR EAX,EAX` |
| `10018420` | `33 db` | `XOR EBX,EBX` |
| `10018422` | `33 c9` | `XOR ECX,ECX` |
| `10018424` | `33 d2` | `XOR EDX,EDX` |
| `10018426` | `33 ff` | `XOR EDI,EDI` |
| `10018428` | `ff e6` | `JMP ESI` |
