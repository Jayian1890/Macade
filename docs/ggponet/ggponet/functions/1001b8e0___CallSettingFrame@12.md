# 1001b8e0 `__CallSettingFrame@12`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b8e0 |
| `name` | __CallSettingFrame@12 |
| `namespace` | Global |
| `signature` | undefined __CallSettingFrame@12(void) |
| `size_bytes` | 76 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __CallSettingFrame@12 |

## Decompiled C

```c

/* WARNING: Restarted to delay deadcode elimination for space: stack */
/* Library Function - Single Match
    __CallSettingFrame@12
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __CallSettingFrame_12(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)__NLG_Notify1(param_3);
  (*pcVar1)();
  if (param_3 == 0x100) {
    param_3 = 2;
  }
  __NLG_Notify1(param_3);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b8fe` | `1001da84` | `UNCONDITIONAL_CALL` | __NLG_Notify1 | `1001da84` |
| `1001b920` | `1001da84` | `UNCONDITIONAL_CALL` | __NLG_Notify1 | `1001da84` |

## Callers

| From | Function |
| --- | --- |
| `1001ad8d` | ___FrameUnwindToState |
| `10014d1b` | _CallCatchBlock2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b8e0` | `55` | `PUSH EBP` |
| `1001b8e1` | `8b ec` | `MOV EBP,ESP` |
| `1001b8e3` | `83 ec 04` | `SUB ESP,0x4` |
| `1001b8e6` | `53` | `PUSH EBX` |
| `1001b8e7` | `51` | `PUSH ECX` |
| `1001b8e8` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1001b8eb` | `83 c0 0c` | `ADD EAX,0xc` |
| `1001b8ee` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001b8f1` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001b8f4` | `55` | `PUSH EBP` |
| `1001b8f5` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001b8f8` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001b8fb` | `8b 6d fc` | `MOV EBP,dword ptr [EBP + -0x4]` |
| `1001b8fe` | `e8 81 21 00 00` | `CALL 0x1001da84` |
| `1001b903` | `56` | `PUSH ESI` |
| `1001b904` | `57` | `PUSH EDI` |
| `1001b905` | `ff d0` | `CALL EAX` |
| `1001b907` | `5f` | `POP EDI` |
| `1001b908` | `5e` | `POP ESI` |
| `1001b909` | `8b dd` | `MOV EBX,EBP` |
| `1001b90b` | `5d` | `POP EBP` |
| `1001b90c` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001b90f` | `55` | `PUSH EBP` |
| `1001b910` | `8b eb` | `MOV EBP,EBX` |
| `1001b912` | `81 f9 00 01 00 00` | `CMP ECX,0x100` |
| `1001b918` | `75 05` | `JNZ 0x1001b91f` |
| `1001b91a` | `b9 02 00 00 00` | `MOV ECX,0x2` |
| `1001b91f` | `51` | `PUSH ECX` |
| `1001b920` | `e8 5f 21 00 00` | `CALL 0x1001da84` |
| `1001b925` | `5d` | `POP EBP` |
| `1001b926` | `59` | `POP ECX` |
| `1001b927` | `5b` | `POP EBX` |
| `1001b928` | `c9` | `LEAVE` |
| `1001b929` | `c2 0c 00` | `RET 0xc` |
