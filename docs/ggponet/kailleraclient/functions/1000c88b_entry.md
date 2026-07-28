# 1000c88b `entry`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1000c88b |
| `name` | entry |
| `namespace` | Global |
| `signature` | int __stdcall entry(undefined4 param_1, int param_2, undefined4 param_3) |
| `size_bytes` | 157 |
| `stack_frame_size` | 16 |
| `calling_convention` | __stdcall |
| `source_type` | IMPORTED |
| `export_names` | entry |

## Decompiled C

```c

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = DAT_1000f440;
  if (param_2 != 0) {
    if ((param_2 != 1) && (param_2 != 2)) goto LAB_1000c8d3;
    if ((DAT_1000f448 != (code *)0x0) &&
       (iVar2 = (*DAT_1000f448)(param_1,param_2,param_3), iVar2 == 0)) {
      return 0;
    }
    iVar2 = FUN_1000c7e0(param_1,param_2);
  }
  if (iVar2 == 0) {
    return 0;
  }
LAB_1000c8d3:
  iVar2 = FUN_100057e0(param_1);
  if (param_2 == 1) {
    if (iVar2 != 0) {
      return iVar2;
    }
    FUN_1000c7e0(param_1,0);
  }
  if ((param_2 != 0) && (param_2 != 3)) {
    return iVar2;
  }
  iVar3 = FUN_1000c7e0(param_1,param_2);
  param_2 = iVar2;
  if (iVar3 == 0) {
    param_2 = 0;
  }
  if (param_2 != 0) {
    if (DAT_1000f448 != (code *)0x0) {
      iVar2 = (*DAT_1000f448)(param_1,iVar1,param_3);
      return iVar2;
    }
    return param_2;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1000c8c6` | `1000c7e0` | `UNCONDITIONAL_CALL` | FUN_1000c7e0 | `1000c7e0` |
| `1000c8d6` | `100057e0` | `UNCONDITIONAL_CALL` | FUN_100057e0 | `100057e0` |
| `1000c8ea` | `1000c7e0` | `UNCONDITIONAL_CALL` | FUN_1000c7e0 | `1000c7e0` |
| `1000c8fb` | `1000c7e0` | `UNCONDITIONAL_CALL` | FUN_1000c7e0 | `1000c7e0` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1000c89e` | `1000f440` | `READ` | DAT_1000f440 |
| `1000c8b1` | `1000f448` | `READ` | DAT_1000f448 |
| `1000c90d` | `1000f448` | `READ` | DAT_1000f448 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1000c88b` | `55` | `PUSH EBP` |
| `1000c88c` | `8b ec` | `MOV EBP,ESP` |
| `1000c88e` | `53` | `PUSH EBX` |
| `1000c88f` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1000c892` | `56` | `PUSH ESI` |
| `1000c893` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1000c896` | `57` | `PUSH EDI` |
| `1000c897` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `1000c89a` | `85 f6` | `TEST ESI,ESI` |
| `1000c89c` | `75 09` | `JNZ 0x1000c8a7` |
| `1000c89e` | `83 3d 40 f4 00 10 00` | `CMP dword ptr [0x1000f440],0x0` |
| `1000c8a5` | `eb 26` | `JMP 0x1000c8cd` |
| `1000c8a7` | `83 fe 01` | `CMP ESI,0x1` |
| `1000c8aa` | `74 05` | `JZ 0x1000c8b1` |
| `1000c8ac` | `83 fe 02` | `CMP ESI,0x2` |
| `1000c8af` | `75 22` | `JNZ 0x1000c8d3` |
| `1000c8b1` | `a1 48 f4 00 10` | `MOV EAX,[0x1000f448]` |
| `1000c8b6` | `85 c0` | `TEST EAX,EAX` |
| `1000c8b8` | `74 09` | `JZ 0x1000c8c3` |
| `1000c8ba` | `57` | `PUSH EDI` |
| `1000c8bb` | `56` | `PUSH ESI` |
| `1000c8bc` | `53` | `PUSH EBX` |
| `1000c8bd` | `ff d0` | `CALL EAX` |
| `1000c8bf` | `85 c0` | `TEST EAX,EAX` |
| `1000c8c1` | `74 0c` | `JZ 0x1000c8cf` |
| `1000c8c3` | `57` | `PUSH EDI` |
| `1000c8c4` | `56` | `PUSH ESI` |
| `1000c8c5` | `53` | `PUSH EBX` |
| `1000c8c6` | `e8 15 ff ff ff` | `CALL 0x1000c7e0` |
| `1000c8cb` | `85 c0` | `TEST EAX,EAX` |
| `1000c8cd` | `75 04` | `JNZ 0x1000c8d3` |
| `1000c8cf` | `33 c0` | `XOR EAX,EAX` |
| `1000c8d1` | `eb 4e` | `JMP 0x1000c921` |
| `1000c8d3` | `57` | `PUSH EDI` |
| `1000c8d4` | `56` | `PUSH ESI` |
| `1000c8d5` | `53` | `PUSH EBX` |
| `1000c8d6` | `e8 05 8f ff ff` | `CALL 0x100057e0` |
| `1000c8db` | `83 fe 01` | `CMP ESI,0x1` |
| `1000c8de` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `1000c8e1` | `75 0c` | `JNZ 0x1000c8ef` |
| `1000c8e3` | `85 c0` | `TEST EAX,EAX` |
| `1000c8e5` | `75 37` | `JNZ 0x1000c91e` |
| `1000c8e7` | `57` | `PUSH EDI` |
| `1000c8e8` | `50` | `PUSH EAX` |
| `1000c8e9` | `53` | `PUSH EBX` |
| `1000c8ea` | `e8 f1 fe ff ff` | `CALL 0x1000c7e0` |
| `1000c8ef` | `85 f6` | `TEST ESI,ESI` |
| `1000c8f1` | `74 05` | `JZ 0x1000c8f8` |
| `1000c8f3` | `83 fe 03` | `CMP ESI,0x3` |
| `1000c8f6` | `75 26` | `JNZ 0x1000c91e` |
| `1000c8f8` | `57` | `PUSH EDI` |
| `1000c8f9` | `56` | `PUSH ESI` |
| `1000c8fa` | `53` | `PUSH EBX` |
| `1000c8fb` | `e8 e0 fe ff ff` | `CALL 0x1000c7e0` |
| `1000c900` | `85 c0` | `TEST EAX,EAX` |
| `1000c902` | `75 03` | `JNZ 0x1000c907` |
| `1000c904` | `21 45 0c` | `AND dword ptr [EBP + 0xc],EAX` |
| `1000c907` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `1000c90b` | `74 11` | `JZ 0x1000c91e` |
| `1000c90d` | `a1 48 f4 00 10` | `MOV EAX,[0x1000f448]` |
| `1000c912` | `85 c0` | `TEST EAX,EAX` |
| `1000c914` | `74 08` | `JZ 0x1000c91e` |
| `1000c916` | `57` | `PUSH EDI` |
| `1000c917` | `56` | `PUSH ESI` |
| `1000c918` | `53` | `PUSH EBX` |
| `1000c919` | `ff d0` | `CALL EAX` |
| `1000c91b` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `1000c91e` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1000c921` | `5f` | `POP EDI` |
| `1000c922` | `5e` | `POP ESI` |
| `1000c923` | `5b` | `POP EBX` |
| `1000c924` | `5d` | `POP EBP` |
| `1000c925` | `c2 0c 00` | `RET 0xc` |
