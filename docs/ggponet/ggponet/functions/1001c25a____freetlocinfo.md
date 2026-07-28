# 1001c25a `___freetlocinfo`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c25a |
| `name` | ___freetlocinfo |
| `namespace` | Global |
| `signature` | undefined ___freetlocinfo(void) |
| `size_bytes` | 329 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___freetlocinfo |

## Decompiled C

```c

/* Library Function - Single Match
    ___freetlocinfo
   
   Library: Visual Studio 2008 Release */

void ___freetlocinfo(void *param_1)

{
  int *piVar1;
  undefined **ppuVar2;
  void *_Memory;
  undefined4 *puVar3;
  
  _Memory = param_1;
  if ((((*(undefined ***)((int)param_1 + 0xbc) != (undefined **)0x0) &&
       (*(undefined ***)((int)param_1 + 0xbc) != &PTR_DAT_10038328)) &&
      (*(int **)((int)param_1 + 0xb0) != (int *)0x0)) && (**(int **)((int)param_1 + 0xb0) == 0)) {
    piVar1 = *(int **)((int)param_1 + 0xb8);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_mon(*(undefined4 *)((int)param_1 + 0xbc));
    }
    piVar1 = *(int **)((int)param_1 + 0xb4);
    if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
      _free(piVar1);
      ___free_lconv_num(*(undefined4 *)((int)param_1 + 0xbc));
    }
    _free(*(void **)((int)param_1 + 0xb0));
    _free(*(void **)((int)param_1 + 0xbc));
  }
  if ((*(int **)((int)param_1 + 0xc0) != (int *)0x0) && (**(int **)((int)param_1 + 0xc0) == 0)) {
    _free((void *)(*(int *)((int)param_1 + 0xc4) + -0xfe));
    _free((void *)(*(int *)((int)param_1 + 0xcc) + -0x80));
    _free((void *)(*(int *)((int)param_1 + 0xd0) + -0x80));
    _free(*(void **)((int)param_1 + 0xc0));
  }
  ppuVar2 = *(undefined ***)((int)param_1 + 0xd4);
  if ((ppuVar2 != &PTR_DAT_10038268) && (ppuVar2[0x2d] == (undefined *)0x0)) {
    ___free_lc_time(ppuVar2);
    _free(*(void **)((int)param_1 + 0xd4));
  }
  puVar3 = (undefined4 *)((int)param_1 + 0x50);
  param_1 = (void *)0x6;
  do {
    if ((((undefined *)puVar3[-2] != &DAT_10038148) &&
        (piVar1 = (int *)*puVar3, piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
      _free(piVar1);
    }
    if (((puVar3[-1] != 0) && (piVar1 = (int *)puVar3[1], piVar1 != (int *)0x0)) && (*piVar1 == 0))
    {
      _free(piVar1);
    }
    puVar3 = puVar3 + 4;
    param_1 = (void *)((int)param_1 + -1);
  } while (param_1 != (void *)0x0);
  _free(_Memory);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c295` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c2a0` | `1001f133` | `UNCONDITIONAL_CALL` | ___free_lconv_mon | `1001f133` |
| `1001c2b6` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c2c1` | `1001f0ee` | `UNCONDITIONAL_CALL` | ___free_lconv_num | `1001f0ee` |
| `1001c2ce` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c2d9` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c2fa` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c30d` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c31b` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c326` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c346` | `1001ef59` | `UNCONDITIONAL_CALL` | ___free_lc_time | `1001ef59` |
| `1001c34d` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c372` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c389` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001c398` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `1001c4fc` | __updatetlocinfoEx_nolock |
| `100174e6` | __freefls@4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c271` | `10038328` | `DATA` | PTR_DAT_10038328 |
| `1001c336` | `10038268` | `DATA` | PTR_DAT_10038268 |
| `1001c35e` | `10038148` | `DATA` | DAT_10038148 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c25a` | `8b ff` | `MOV EDI,EDI` |
| `1001c25c` | `55` | `PUSH EBP` |
| `1001c25d` | `8b ec` | `MOV EBP,ESP` |
| `1001c25f` | `53` | `PUSH EBX` |
| `1001c260` | `56` | `PUSH ESI` |
| `1001c261` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001c264` | `8b 86 bc 00 00 00` | `MOV EAX,dword ptr [ESI + 0xbc]` |
| `1001c26a` | `33 db` | `XOR EBX,EBX` |
| `1001c26c` | `57` | `PUSH EDI` |
| `1001c26d` | `3b c3` | `CMP EAX,EBX` |
| `1001c26f` | `74 6f` | `JZ 0x1001c2e0` |
| `1001c271` | `3d 28 83 03 10` | `CMP EAX,0x10038328` |
| `1001c276` | `74 68` | `JZ 0x1001c2e0` |
| `1001c278` | `8b 86 b0 00 00 00` | `MOV EAX,dword ptr [ESI + 0xb0]` |
| `1001c27e` | `3b c3` | `CMP EAX,EBX` |
| `1001c280` | `74 5e` | `JZ 0x1001c2e0` |
| `1001c282` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c284` | `75 5a` | `JNZ 0x1001c2e0` |
| `1001c286` | `8b 86 b8 00 00 00` | `MOV EAX,dword ptr [ESI + 0xb8]` |
| `1001c28c` | `3b c3` | `CMP EAX,EBX` |
| `1001c28e` | `74 17` | `JZ 0x1001c2a7` |
| `1001c290` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c292` | `75 13` | `JNZ 0x1001c2a7` |
| `1001c294` | `50` | `PUSH EAX` |
| `1001c295` | `e8 a7 4f ff ff` | `CALL 0x10011241` |
| `1001c29a` | `ff b6 bc 00 00 00` | `PUSH dword ptr [ESI + 0xbc]` |
| `1001c2a0` | `e8 8e 2e 00 00` | `CALL 0x1001f133` |
| `1001c2a5` | `59` | `POP ECX` |
| `1001c2a6` | `59` | `POP ECX` |
| `1001c2a7` | `8b 86 b4 00 00 00` | `MOV EAX,dword ptr [ESI + 0xb4]` |
| `1001c2ad` | `3b c3` | `CMP EAX,EBX` |
| `1001c2af` | `74 17` | `JZ 0x1001c2c8` |
| `1001c2b1` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c2b3` | `75 13` | `JNZ 0x1001c2c8` |
| `1001c2b5` | `50` | `PUSH EAX` |
| `1001c2b6` | `e8 86 4f ff ff` | `CALL 0x10011241` |
| `1001c2bb` | `ff b6 bc 00 00 00` | `PUSH dword ptr [ESI + 0xbc]` |
| `1001c2c1` | `e8 28 2e 00 00` | `CALL 0x1001f0ee` |
| `1001c2c6` | `59` | `POP ECX` |
| `1001c2c7` | `59` | `POP ECX` |
| `1001c2c8` | `ff b6 b0 00 00 00` | `PUSH dword ptr [ESI + 0xb0]` |
| `1001c2ce` | `e8 6e 4f ff ff` | `CALL 0x10011241` |
| `1001c2d3` | `ff b6 bc 00 00 00` | `PUSH dword ptr [ESI + 0xbc]` |
| `1001c2d9` | `e8 63 4f ff ff` | `CALL 0x10011241` |
| `1001c2de` | `59` | `POP ECX` |
| `1001c2df` | `59` | `POP ECX` |
| `1001c2e0` | `8b 86 c0 00 00 00` | `MOV EAX,dword ptr [ESI + 0xc0]` |
| `1001c2e6` | `3b c3` | `CMP EAX,EBX` |
| `1001c2e8` | `74 44` | `JZ 0x1001c32e` |
| `1001c2ea` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c2ec` | `75 40` | `JNZ 0x1001c32e` |
| `1001c2ee` | `8b 86 c4 00 00 00` | `MOV EAX,dword ptr [ESI + 0xc4]` |
| `1001c2f4` | `2d fe 00 00 00` | `SUB EAX,0xfe` |
| `1001c2f9` | `50` | `PUSH EAX` |
| `1001c2fa` | `e8 42 4f ff ff` | `CALL 0x10011241` |
| `1001c2ff` | `8b 86 cc 00 00 00` | `MOV EAX,dword ptr [ESI + 0xcc]` |
| `1001c305` | `bf 80 00 00 00` | `MOV EDI,0x80` |
| `1001c30a` | `2b c7` | `SUB EAX,EDI` |
| `1001c30c` | `50` | `PUSH EAX` |
| `1001c30d` | `e8 2f 4f ff ff` | `CALL 0x10011241` |
| `1001c312` | `8b 86 d0 00 00 00` | `MOV EAX,dword ptr [ESI + 0xd0]` |
| `1001c318` | `2b c7` | `SUB EAX,EDI` |
| `1001c31a` | `50` | `PUSH EAX` |
| `1001c31b` | `e8 21 4f ff ff` | `CALL 0x10011241` |
| `1001c320` | `ff b6 c0 00 00 00` | `PUSH dword ptr [ESI + 0xc0]` |
| `1001c326` | `e8 16 4f ff ff` | `CALL 0x10011241` |
| `1001c32b` | `83 c4 10` | `ADD ESP,0x10` |
| `1001c32e` | `8d be d4 00 00 00` | `LEA EDI,[ESI + 0xd4]` |
| `1001c334` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001c336` | `3d 68 82 03 10` | `CMP EAX,0x10038268` |
| `1001c33b` | `74 17` | `JZ 0x1001c354` |
| `1001c33d` | `39 98 b4 00 00 00` | `CMP dword ptr [EAX + 0xb4],EBX` |
| `1001c343` | `75 0f` | `JNZ 0x1001c354` |
| `1001c345` | `50` | `PUSH EAX` |
| `1001c346` | `e8 0e 2c 00 00` | `CALL 0x1001ef59` |
| `1001c34b` | `ff 37` | `PUSH dword ptr [EDI]` |
| `1001c34d` | `e8 ef 4e ff ff` | `CALL 0x10011241` |
| `1001c352` | `59` | `POP ECX` |
| `1001c353` | `59` | `POP ECX` |
| `1001c354` | `8d 7e 50` | `LEA EDI,[ESI + 0x50]` |
| `1001c357` | `c7 45 08 06 00 00 00` | `MOV dword ptr [EBP + 0x8],0x6` |
| `1001c35e` | `81 7f f8 48 81 03 10` | `CMP dword ptr [EDI + -0x8],0x10038148` |
| `1001c365` | `74 11` | `JZ 0x1001c378` |
| `1001c367` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001c369` | `3b c3` | `CMP EAX,EBX` |
| `1001c36b` | `74 0b` | `JZ 0x1001c378` |
| `1001c36d` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c36f` | `75 07` | `JNZ 0x1001c378` |
| `1001c371` | `50` | `PUSH EAX` |
| `1001c372` | `e8 ca 4e ff ff` | `CALL 0x10011241` |
| `1001c377` | `59` | `POP ECX` |
| `1001c378` | `39 5f fc` | `CMP dword ptr [EDI + -0x4],EBX` |
| `1001c37b` | `74 12` | `JZ 0x1001c38f` |
| `1001c37d` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1001c380` | `3b c3` | `CMP EAX,EBX` |
| `1001c382` | `74 0b` | `JZ 0x1001c38f` |
| `1001c384` | `39 18` | `CMP dword ptr [EAX],EBX` |
| `1001c386` | `75 07` | `JNZ 0x1001c38f` |
| `1001c388` | `50` | `PUSH EAX` |
| `1001c389` | `e8 b3 4e ff ff` | `CALL 0x10011241` |
| `1001c38e` | `59` | `POP ECX` |
| `1001c38f` | `83 c7 10` | `ADD EDI,0x10` |
| `1001c392` | `ff 4d 08` | `DEC dword ptr [EBP + 0x8]` |
| `1001c395` | `75 c7` | `JNZ 0x1001c35e` |
| `1001c397` | `56` | `PUSH ESI` |
| `1001c398` | `e8 a4 4e ff ff` | `CALL 0x10011241` |
| `1001c39d` | `59` | `POP ECX` |
| `1001c39e` | `5f` | `POP EDI` |
| `1001c39f` | `5e` | `POP ESI` |
| `1001c3a0` | `5b` | `POP EBX` |
| `1001c3a1` | `5d` | `POP EBP` |
| `1001c3a2` | `c3` | `RET` |
