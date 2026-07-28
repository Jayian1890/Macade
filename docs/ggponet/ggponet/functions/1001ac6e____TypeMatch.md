# 1001ac6e `___TypeMatch`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ac6e |
| `name` | ___TypeMatch |
| `namespace` | Global |
| `signature` | undefined ___TypeMatch(void) |
| `size_bytes` | 95 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___TypeMatch |

## Decompiled C

```c

/* Library Function - Single Match
    ___TypeMatch
   
   Library: Visual Studio 2008 Release */

undefined4 ___TypeMatch(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_1001acc6:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_1001aca5:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_1001acc6;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_1001aca5;
    }
    uVar2 = 0;
  }
  return uVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ac96` | `10011770` | `UNCONDITIONAL_CALL` | _strcmp | `10011770` |

## Callers

| From | Function |
| --- | --- |
| `1001b698` | FindHandler |
| `1001af0a` | IsInExceptionSpec |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ac6e` | `8b ff` | `MOV EDI,EDI` |
| `1001ac70` | `55` | `PUSH EBP` |
| `1001ac71` | `8b ec` | `MOV EBP,ESP` |
| `1001ac73` | `56` | `PUSH ESI` |
| `1001ac74` | `57` | `PUSH EDI` |
| `1001ac75` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001ac78` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1001ac7b` | `85 c0` | `TEST EAX,EAX` |
| `1001ac7d` | `74 47` | `JZ 0x1001acc6` |
| `1001ac7f` | `8d 50 08` | `LEA EDX,[EAX + 0x8]` |
| `1001ac82` | `80 3a 00` | `CMP byte ptr [EDX],0x0` |
| `1001ac85` | `74 3f` | `JZ 0x1001acc6` |
| `1001ac87` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001ac8a` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `1001ac8d` | `3b c1` | `CMP EAX,ECX` |
| `1001ac8f` | `74 14` | `JZ 0x1001aca5` |
| `1001ac91` | `83 c1 08` | `ADD ECX,0x8` |
| `1001ac94` | `51` | `PUSH ECX` |
| `1001ac95` | `52` | `PUSH EDX` |
| `1001ac96` | `e8 d5 6a ff ff` | `CALL 0x10011770` |
| `1001ac9b` | `59` | `POP ECX` |
| `1001ac9c` | `59` | `POP ECX` |
| `1001ac9d` | `85 c0` | `TEST EAX,EAX` |
| `1001ac9f` | `74 04` | `JZ 0x1001aca5` |
| `1001aca1` | `33 c0` | `XOR EAX,EAX` |
| `1001aca3` | `eb 24` | `JMP 0x1001acc9` |
| `1001aca5` | `f6 06 02` | `TEST byte ptr [ESI],0x2` |
| `1001aca8` | `74 05` | `JZ 0x1001acaf` |
| `1001acaa` | `f6 07 08` | `TEST byte ptr [EDI],0x8` |
| `1001acad` | `74 f2` | `JZ 0x1001aca1` |
| `1001acaf` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001acb2` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001acb4` | `a8 01` | `TEST AL,0x1` |
| `1001acb6` | `74 05` | `JZ 0x1001acbd` |
| `1001acb8` | `f6 07 01` | `TEST byte ptr [EDI],0x1` |
| `1001acbb` | `74 e4` | `JZ 0x1001aca1` |
| `1001acbd` | `a8 02` | `TEST AL,0x2` |
| `1001acbf` | `74 05` | `JZ 0x1001acc6` |
| `1001acc1` | `f6 07 02` | `TEST byte ptr [EDI],0x2` |
| `1001acc4` | `74 db` | `JZ 0x1001aca1` |
| `1001acc6` | `33 c0` | `XOR EAX,EAX` |
| `1001acc8` | `40` | `INC EAX` |
| `1001acc9` | `5f` | `POP EDI` |
| `1001acca` | `5e` | `POP ESI` |
| `1001accb` | `5d` | `POP EBP` |
| `1001accc` | `c3` | `RET` |
