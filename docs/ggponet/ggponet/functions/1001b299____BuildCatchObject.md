# 1001b299 `___BuildCatchObject`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b299 |
| `name` | ___BuildCatchObject |
| `namespace` | Global |
| `signature` | undefined ___BuildCatchObject(void) |
| `size_bytes` | 133 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___BuildCatchObject |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___BuildCatchObject
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void ___BuildCatchObject(int param_1,int param_2,uint *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = param_2;
  if ((*param_3 & 0x80000000) == 0) {
    iVar3 = param_3[2] + 0xc + param_2;
  }
  iVar1 = ___BuildCatchObjectHelper(param_1,param_2,param_3,param_4);
  if (iVar1 == 1) {
    uVar2 = ___AdjustPointer(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
    FID_conflict__CallMemberFunction1(iVar3,*(undefined4 *)(param_4 + 0x18),uVar2);
  }
  else if (iVar1 == 2) {
    uVar2 = ___AdjustPointer(*(undefined4 *)(param_1 + 0x18),param_4 + 8,1);
    FID_conflict__CallMemberFunction1(iVar3,*(undefined4 *)(param_4 + 0x18),uVar2);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b2a0` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001b2cf` | `1001b11a` | `UNCONDITIONAL_CALL` | ___BuildCatchObjectHelper | `1001b11a` |
| `1001b2e6` | `1001ae91` | `UNCONDITIONAL_CALL` | ___AdjustPointer | `1001ae91` |
| `1001b2f2` | `1001497b` | `UNCONDITIONAL_CALL` | FID_conflict:_CallMemberFunction1 | `1001497b` |
| `1001b300` | `1001ae91` | `UNCONDITIONAL_CALL` | ___AdjustPointer | `1001ae91` |
| `1001b30c` | `1001497b` | `UNCONDITIONAL_CALL` | FID_conflict:_CallMemberFunction1 | `1001497b` |
| `1001b318` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001b33e` | CatchIt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001b29b` | `10034158` | `DATA` | DAT_10034158 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b299` | `6a 08` | `PUSH 0x8` |
| `1001b29b` | `68 58 41 03 10` | `PUSH 0x10034158` |
| `1001b2a0` | `e8 57 ba ff ff` | `CALL 0x10016cfc` |
| `1001b2a5` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001b2a8` | `f7 00 00 00 00 80` | `TEST dword ptr [EAX],0x80000000` |
| `1001b2ae` | `74 05` | `JZ 0x1001b2b5` |
| `1001b2b0` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `1001b2b3` | `eb 0a` | `JMP 0x1001b2bf` |
| `1001b2b5` | `8b 48 08` | `MOV ECX,dword ptr [EAX + 0x8]` |
| `1001b2b8` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001b2bb` | `8d 5c 11 0c` | `LEA EBX,[ECX + EDX*0x1 + 0xc]` |
| `1001b2bf` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001b2c3` | `8b 75 14` | `MOV ESI,dword ptr [EBP + 0x14]` |
| `1001b2c6` | `56` | `PUSH ESI` |
| `1001b2c7` | `50` | `PUSH EAX` |
| `1001b2c8` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001b2cb` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001b2ce` | `57` | `PUSH EDI` |
| `1001b2cf` | `e8 46 fe ff ff` | `CALL 0x1001b11a` |
| `1001b2d4` | `83 c4 10` | `ADD ESP,0x10` |
| `1001b2d7` | `48` | `DEC EAX` |
| `1001b2d8` | `74 1f` | `JZ 0x1001b2f9` |
| `1001b2da` | `48` | `DEC EAX` |
| `1001b2db` | `75 34` | `JNZ 0x1001b311` |
| `1001b2dd` | `6a 01` | `PUSH 0x1` |
| `1001b2df` | `8d 46 08` | `LEA EAX,[ESI + 0x8]` |
| `1001b2e2` | `50` | `PUSH EAX` |
| `1001b2e3` | `ff 77 18` | `PUSH dword ptr [EDI + 0x18]` |
| `1001b2e6` | `e8 a6 fb ff ff` | `CALL 0x1001ae91` |
| `1001b2eb` | `59` | `POP ECX` |
| `1001b2ec` | `59` | `POP ECX` |
| `1001b2ed` | `50` | `PUSH EAX` |
| `1001b2ee` | `ff 76 18` | `PUSH dword ptr [ESI + 0x18]` |
| `1001b2f1` | `53` | `PUSH EBX` |
| `1001b2f2` | `e8 84 96 ff ff` | `CALL 0x1001497b` |
| `1001b2f7` | `eb 18` | `JMP 0x1001b311` |
| `1001b2f9` | `8d 46 08` | `LEA EAX,[ESI + 0x8]` |
| `1001b2fc` | `50` | `PUSH EAX` |
| `1001b2fd` | `ff 77 18` | `PUSH dword ptr [EDI + 0x18]` |
| `1001b300` | `e8 8c fb ff ff` | `CALL 0x1001ae91` |
| `1001b305` | `59` | `POP ECX` |
| `1001b306` | `59` | `POP ECX` |
| `1001b307` | `50` | `PUSH EAX` |
| `1001b308` | `ff 76 18` | `PUSH dword ptr [ESI + 0x18]` |
| `1001b30b` | `53` | `PUSH EBX` |
| `1001b30c` | `e8 6a 96 ff ff` | `CALL 0x1001497b` |
| `1001b311` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001b318` | `e8 24 ba ff ff` | `CALL 0x10016d41` |
| `1001b31d` | `c3` | `RET` |
