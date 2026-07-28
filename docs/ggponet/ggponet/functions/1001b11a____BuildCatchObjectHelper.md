# 1001b11a `___BuildCatchObjectHelper`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b11a |
| `name` | ___BuildCatchObjectHelper |
| `namespace` | Global |
| `signature` | undefined ___BuildCatchObjectHelper(void) |
| `size_bytes` | 371 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___BuildCatchObjectHelper |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___BuildCatchObjectHelper
   
   Library: Visual Studio 2008 Release */

char ___BuildCatchObjectHelper(int param_1,int *param_2,uint *param_3,byte *param_4)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  uint in_stack_ffffffd0;
  
  if (((param_3[1] == 0) || (*(char *)(param_3[1] + 8) == '\0')) ||
     ((param_3[2] == 0 && ((*param_3 & 0x80000000) == 0)))) {
    return '\0';
  }
  if (-1 < (int)*param_3) {
    param_2 = (int *)(param_3[2] + 0xc + (int)param_2);
  }
  if ((*param_3 & 8) == 0) {
    pvVar2 = *(void **)(param_1 + 0x18);
    if ((*param_4 & 1) == 0) {
      if (*(int *)(param_4 + 0x18) == 0) {
        iVar1 = _ValidateRead(pvVar2,1);
        if ((iVar1 != 0) && (iVar1 = _ValidateRead(param_2,1), iVar1 != 0)) {
          _Size = *(size_t *)(param_4 + 0x14);
          pvVar2 = (void *)___AdjustPointer(*(undefined4 *)(param_1 + 0x18),param_4 + 8);
          _memmove(param_2,pvVar2,_Size);
          return '\0';
        }
      }
      else {
        iVar1 = _ValidateRead(pvVar2,1);
        if (((iVar1 != 0) && (iVar1 = _ValidateRead(param_2,1), iVar1 != 0)) &&
           (iVar1 = _ValidateRead(*(void **)(param_4 + 0x18),in_stack_ffffffd0), iVar1 != 0)) {
          return ((*param_4 & 4) != 0) + '\x01';
        }
      }
    }
    else {
      iVar1 = _ValidateRead(pvVar2,1);
      if ((iVar1 != 0) && (iVar1 = _ValidateRead(param_2,1), iVar1 != 0)) {
        _memmove(param_2,*(void **)(param_1 + 0x18),*(size_t *)(param_4 + 0x14));
        if (*(int *)(param_4 + 0x14) != 4) {
          return '\0';
        }
        iVar1 = *param_2;
        if (iVar1 == 0) {
          return '\0';
        }
        goto LAB_1001b19f;
      }
    }
  }
  else {
    iVar1 = _ValidateRead(*(void **)(param_1 + 0x18),1);
    if ((iVar1 != 0) && (iVar1 = _ValidateRead(param_2,1), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 0x18);
      *param_2 = iVar1;
LAB_1001b19f:
      iVar1 = ___AdjustPointer(iVar1,param_4 + 8);
      *param_2 = iVar1;
      return '\0';
    }
  }
  _inconsistency();
  return '\0';
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b121` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001b173` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b184` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b1a0` | `1001ae91` | `UNCONDITIONAL_CALL` | ___AdjustPointer | `1001ae91` |
| `1001b1bb` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b1cc` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b1e5` | `10012740` | `UNCONDITIONAL_CALL` | _memmove | `10012740` |
| `1001b208` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b215` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b22d` | `1001ae91` | `UNCONDITIONAL_CALL` | ___AdjustPointer | `1001ae91` |
| `1001b236` | `10012740` | `UNCONDITIONAL_CALL` | _memmove | `10012740` |
| `1001b240` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b24d` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b25b` | `1001e961` | `UNCONDITIONAL_CALL` | _ValidateRead | `1001e961` |
| `1001b274` | `100194f9` | `UNCONDITIONAL_CALL` | _inconsistency | `100194f9` |
| `1001b293` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001b2cf` | ___BuildCatchObject |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001b11c` | `10034138` | `DATA` | DAT_10034138 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b11a` | `6a 0c` | `PUSH 0xc` |
| `1001b11c` | `68 38 41 03 10` | `PUSH 0x10034138` |
| `1001b121` | `e8 d6 bb ff ff` | `CALL 0x10016cfc` |
| `1001b126` | `33 d2` | `XOR EDX,EDX` |
| `1001b128` | `89 55 e4` | `MOV dword ptr [EBP + -0x1c],EDX` |
| `1001b12b` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001b12e` | `8b 48 04` | `MOV ECX,dword ptr [EAX + 0x4]` |
| `1001b131` | `3b ca` | `CMP ECX,EDX` |
| `1001b133` | `0f 84 58 01 00 00` | `JZ 0x1001b291` |
| `1001b139` | `38 51 08` | `CMP byte ptr [ECX + 0x8],DL` |
| `1001b13c` | `0f 84 4f 01 00 00` | `JZ 0x1001b291` |
| `1001b142` | `8b 48 08` | `MOV ECX,dword ptr [EAX + 0x8]` |
| `1001b145` | `3b ca` | `CMP ECX,EDX` |
| `1001b147` | `75 0c` | `JNZ 0x1001b155` |
| `1001b149` | `f7 00 00 00 00 80` | `TEST dword ptr [EAX],0x80000000` |
| `1001b14f` | `0f 84 3c 01 00 00` | `JZ 0x1001b291` |
| `1001b155` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001b157` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001b15a` | `85 c0` | `TEST EAX,EAX` |
| `1001b15c` | `78 04` | `JS 0x1001b162` |
| `1001b15e` | `8d 74 31 0c` | `LEA ESI,[ECX + ESI*0x1 + 0xc]` |
| `1001b162` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `1001b165` | `33 db` | `XOR EBX,EBX` |
| `1001b167` | `43` | `INC EBX` |
| `1001b168` | `53` | `PUSH EBX` |
| `1001b169` | `a8 08` | `TEST AL,0x8` |
| `1001b16b` | `74 41` | `JZ 0x1001b1ae` |
| `1001b16d` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001b170` | `ff 77 18` | `PUSH dword ptr [EDI + 0x18]` |
| `1001b173` | `e8 e9 37 00 00` | `CALL 0x1001e961` |
| `1001b178` | `59` | `POP ECX` |
| `1001b179` | `59` | `POP ECX` |
| `1001b17a` | `85 c0` | `TEST EAX,EAX` |
| `1001b17c` | `0f 84 f2 00 00 00` | `JZ 0x1001b274` |
| `1001b182` | `53` | `PUSH EBX` |
| `1001b183` | `56` | `PUSH ESI` |
| `1001b184` | `e8 d8 37 00 00` | `CALL 0x1001e961` |
| `1001b189` | `59` | `POP ECX` |
| `1001b18a` | `59` | `POP ECX` |
| `1001b18b` | `85 c0` | `TEST EAX,EAX` |
| `1001b18d` | `0f 84 e1 00 00 00` | `JZ 0x1001b274` |
| `1001b193` | `8b 47 18` | `MOV EAX,dword ptr [EDI + 0x18]` |
| `1001b196` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001b198` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `1001b19b` | `83 c1 08` | `ADD ECX,0x8` |
| `1001b19e` | `51` | `PUSH ECX` |
| `1001b19f` | `50` | `PUSH EAX` |
| `1001b1a0` | `e8 ec fc ff ff` | `CALL 0x1001ae91` |
| `1001b1a5` | `59` | `POP ECX` |
| `1001b1a6` | `59` | `POP ECX` |
| `1001b1a7` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001b1a9` | `e9 cb 00 00 00` | `JMP 0x1001b279` |
| `1001b1ae` | `8b 7d 14` | `MOV EDI,dword ptr [EBP + 0x14]` |
| `1001b1b1` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001b1b4` | `ff 70 18` | `PUSH dword ptr [EAX + 0x18]` |
| `1001b1b7` | `84 1f` | `TEST byte ptr [EDI],BL` |
| `1001b1b9` | `74 48` | `JZ 0x1001b203` |
| `1001b1bb` | `e8 a1 37 00 00` | `CALL 0x1001e961` |
| `1001b1c0` | `59` | `POP ECX` |
| `1001b1c1` | `59` | `POP ECX` |
| `1001b1c2` | `85 c0` | `TEST EAX,EAX` |
| `1001b1c4` | `0f 84 aa 00 00 00` | `JZ 0x1001b274` |
| `1001b1ca` | `53` | `PUSH EBX` |
| `1001b1cb` | `56` | `PUSH ESI` |
| `1001b1cc` | `e8 90 37 00 00` | `CALL 0x1001e961` |
| `1001b1d1` | `59` | `POP ECX` |
| `1001b1d2` | `59` | `POP ECX` |
| `1001b1d3` | `85 c0` | `TEST EAX,EAX` |
| `1001b1d5` | `0f 84 99 00 00 00` | `JZ 0x1001b274` |
| `1001b1db` | `ff 77 14` | `PUSH dword ptr [EDI + 0x14]` |
| `1001b1de` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001b1e1` | `ff 70 18` | `PUSH dword ptr [EAX + 0x18]` |
| `1001b1e4` | `56` | `PUSH ESI` |
| `1001b1e5` | `e8 56 75 ff ff` | `CALL 0x10012740` |
| `1001b1ea` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001b1ed` | `83 7f 14 04` | `CMP dword ptr [EDI + 0x14],0x4` |
| `1001b1f1` | `0f 85 82 00 00 00` | `JNZ 0x1001b279` |
| `1001b1f7` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001b1f9` | `85 c0` | `TEST EAX,EAX` |
| `1001b1fb` | `74 7c` | `JZ 0x1001b279` |
| `1001b1fd` | `83 c7 08` | `ADD EDI,0x8` |
| `1001b200` | `57` | `PUSH EDI` |
| `1001b201` | `eb 9c` | `JMP 0x1001b19f` |
| `1001b203` | `39 57 18` | `CMP dword ptr [EDI + 0x18],EDX` |
| `1001b206` | `75 38` | `JNZ 0x1001b240` |
| `1001b208` | `e8 54 37 00 00` | `CALL 0x1001e961` |
| `1001b20d` | `59` | `POP ECX` |
| `1001b20e` | `59` | `POP ECX` |
| `1001b20f` | `85 c0` | `TEST EAX,EAX` |
| `1001b211` | `74 61` | `JZ 0x1001b274` |
| `1001b213` | `53` | `PUSH EBX` |
| `1001b214` | `56` | `PUSH ESI` |
| `1001b215` | `e8 47 37 00 00` | `CALL 0x1001e961` |
| `1001b21a` | `59` | `POP ECX` |
| `1001b21b` | `59` | `POP ECX` |
| `1001b21c` | `85 c0` | `TEST EAX,EAX` |
| `1001b21e` | `74 54` | `JZ 0x1001b274` |
| `1001b220` | `ff 77 14` | `PUSH dword ptr [EDI + 0x14]` |
| `1001b223` | `83 c7 08` | `ADD EDI,0x8` |
| `1001b226` | `57` | `PUSH EDI` |
| `1001b227` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001b22a` | `ff 70 18` | `PUSH dword ptr [EAX + 0x18]` |
| `1001b22d` | `e8 5f fc ff ff` | `CALL 0x1001ae91` |
| `1001b232` | `59` | `POP ECX` |
| `1001b233` | `59` | `POP ECX` |
| `1001b234` | `50` | `PUSH EAX` |
| `1001b235` | `56` | `PUSH ESI` |
| `1001b236` | `e8 05 75 ff ff` | `CALL 0x10012740` |
| `1001b23b` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001b23e` | `eb 39` | `JMP 0x1001b279` |
| `1001b240` | `e8 1c 37 00 00` | `CALL 0x1001e961` |
| `1001b245` | `59` | `POP ECX` |
| `1001b246` | `59` | `POP ECX` |
| `1001b247` | `85 c0` | `TEST EAX,EAX` |
| `1001b249` | `74 29` | `JZ 0x1001b274` |
| `1001b24b` | `53` | `PUSH EBX` |
| `1001b24c` | `56` | `PUSH ESI` |
| `1001b24d` | `e8 0f 37 00 00` | `CALL 0x1001e961` |
| `1001b252` | `59` | `POP ECX` |
| `1001b253` | `59` | `POP ECX` |
| `1001b254` | `85 c0` | `TEST EAX,EAX` |
| `1001b256` | `74 1c` | `JZ 0x1001b274` |
| `1001b258` | `ff 77 18` | `PUSH dword ptr [EDI + 0x18]` |
| `1001b25b` | `e8 01 37 00 00` | `CALL 0x1001e961` |
| `1001b260` | `59` | `POP ECX` |
| `1001b261` | `85 c0` | `TEST EAX,EAX` |
| `1001b263` | `74 0f` | `JZ 0x1001b274` |
| `1001b265` | `f6 07 04` | `TEST byte ptr [EDI],0x4` |
| `1001b268` | `6a 00` | `PUSH 0x0` |
| `1001b26a` | `58` | `POP EAX` |
| `1001b26b` | `0f 95 c0` | `SETNZ AL` |
| `1001b26e` | `40` | `INC EAX` |
| `1001b26f` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001b272` | `eb 05` | `JMP 0x1001b279` |
| `1001b274` | `e8 80 e2 ff ff` | `CALL 0x100194f9` |
| `1001b279` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001b280` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001b283` | `eb 0e` | `JMP 0x1001b293` |
| `1001b291` | `33 c0` | `XOR EAX,EAX` |
| `1001b293` | `e8 a9 ba ff ff` | `CALL 0x10016d41` |
| `1001b298` | `c3` | `RET` |
