# 1001ad16 `___FrameUnwindToState`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ad16 |
| `name` | ___FrameUnwindToState |
| `namespace` | Global |
| `signature` | undefined ___FrameUnwindToState(void) |
| `size_bytes` | 166 |
| `stack_frame_size` | 40 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___FrameUnwindToState |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___FrameUnwindToState
   
   Library: Visual Studio 2008 Release */

void ___FrameUnwindToState(int param_1,undefined4 param_2,int param_3,int param_4)

{
  _ptiddata p_Var1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(int *)(param_3 + 4) < 0x81) {
    iVar4 = (int)*(char *)(param_1 + 8);
  }
  else {
    iVar4 = *(int *)(param_1 + 8);
  }
  p_Var1 = __getptd();
  p_Var1->_ProcessingThrow = p_Var1->_ProcessingThrow + 1;
  while (iVar4 != param_4) {
    if ((iVar4 < 0) || (*(int *)(param_3 + 4) <= iVar4)) {
      _inconsistency();
    }
    iVar2 = iVar4 * 8;
    piVar3 = (int *)(*(int *)(param_3 + 8) + iVar2);
    iVar4 = *piVar3;
    if (piVar3[1] != 0) {
      *(int *)(param_1 + 8) = iVar4;
      __CallSettingFrame_12(*(undefined4 *)(*(int *)(param_3 + 8) + 4 + iVar2),param_1,0x103);
    }
  }
  FUN_1001addc();
  if (iVar4 != param_4) {
    _inconsistency();
  }
  *(int *)(param_1 + 8) = iVar4;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ad1d` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001ad3d` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001ad5c` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001ad8d` | `1001b8e0` | `UNCONDITIONAL_CALL` | __CallSettingFrame@12 | `1001b8e0` |
| `1001adbe` | `1001addc` | `UNCONDITIONAL_CALL` | FUN_1001addc | `1001addc` |
| `1001adc8` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001add0` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001b85b` | ___InternalCxxFrameHandler |
| `1001b77d` | FindHandler |
| `1001b363` | CatchIt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001ad18` | `10034070` | `DATA` | DAT_10034070 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ad16` | `6a 10` | `PUSH 0x10` |
| `1001ad18` | `68 70 40 03 10` | `PUSH 0x10034070` |
| `1001ad1d` | `e8 da bf ff ff` | `CALL 0x10016cfc` |
| `1001ad22` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `1001ad25` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1001ad28` | `81 7f 04 80 00 00 00` | `CMP dword ptr [EDI + 0x4],0x80` |
| `1001ad2f` | `7f 06` | `JG 0x1001ad37` |
| `1001ad31` | `0f be 73 08` | `MOVSX ESI,byte ptr [EBX + 0x8]` |
| `1001ad35` | `eb 03` | `JMP 0x1001ad3a` |
| `1001ad37` | `8b 73 08` | `MOV ESI,dword ptr [EBX + 0x8]` |
| `1001ad3a` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001ad3d` | `e8 94 c6 ff ff` | `CALL 0x100173d6` |
| `1001ad42` | `05 90 00 00 00` | `ADD EAX,0x90` |
| `1001ad47` | `ff 00` | `INC dword ptr [EAX]` |
| `1001ad49` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001ad4d` | `3b 75 14` | `CMP ESI,dword ptr [EBP + 0x14]` |
| `1001ad50` | `74 65` | `JZ 0x1001adb7` |
| `1001ad52` | `83 fe ff` | `CMP ESI,-0x1` |
| `1001ad55` | `7e 05` | `JLE 0x1001ad5c` |
| `1001ad57` | `3b 77 04` | `CMP ESI,dword ptr [EDI + 0x4]` |
| `1001ad5a` | `7c 05` | `JL 0x1001ad61` |
| `1001ad5c` | `e8 98 e7 ff ff` | `CALL 0x100194f9` |
| `1001ad61` | `8b c6` | `MOV EAX,ESI` |
| `1001ad63` | `c1 e0 03` | `SHL EAX,0x3` |
| `1001ad66` | `8b 4f 08` | `MOV ECX,dword ptr [EDI + 0x8]` |
| `1001ad69` | `03 c8` | `ADD ECX,EAX` |
| `1001ad6b` | `8b 31` | `MOV ESI,dword ptr [ECX]` |
| `1001ad6d` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `1001ad70` | `c7 45 fc 01 00 00 00` | `MOV dword ptr [EBP + -0x4],0x1` |
| `1001ad77` | `83 79 04 00` | `CMP dword ptr [ECX + 0x4],0x0` |
| `1001ad7b` | `74 15` | `JZ 0x1001ad92` |
| `1001ad7d` | `89 73 08` | `MOV dword ptr [EBX + 0x8],ESI` |
| `1001ad80` | `68 03 01 00 00` | `PUSH 0x103` |
| `1001ad85` | `53` | `PUSH EBX` |
| `1001ad86` | `8b 4f 08` | `MOV ECX,dword ptr [EDI + 0x8]` |
| `1001ad89` | `ff 74 01 04` | `PUSH dword ptr [ECX + EAX*0x1 + 0x4]` |
| `1001ad8d` | `e8 4e 0b 00 00` | `CALL 0x1001b8e0` |
| `1001ad92` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001ad96` | `eb 1a` | `JMP 0x1001adb2` |
| `1001adb2` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001adb5` | `eb 96` | `JMP 0x1001ad4d` |
| `1001adb7` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001adbe` | `e8 19 00 00 00` | `CALL 0x1001addc` |
| `1001adc3` | `3b 75 14` | `CMP ESI,dword ptr [EBP + 0x14]` |
| `1001adc6` | `74 05` | `JZ 0x1001adcd` |
| `1001adc8` | `e8 2c e7 ff ff` | `CALL 0x100194f9` |
| `1001adcd` | `89 73 08` | `MOV dword ptr [EBX + 0x8],ESI` |
| `1001add0` | `e8 6c bf ff ff` | `CALL 0x10016d41` |
| `1001add5` | `c3` | `RET` |
