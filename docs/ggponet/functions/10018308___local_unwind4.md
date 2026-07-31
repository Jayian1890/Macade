# 10018308 `__local_unwind4`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018308 |
| `name` | __local_unwind4 |
| `namespace` | Global |
| `signature` | undefined __local_unwind4(void) |
| `size_bytes` | 144 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __local_unwind4 |

## Decompiled C

```c

/* Library Function - Single Match
    __local_unwind4
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release */

void __local_unwind4(uint *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  void *pvStack_28;
  undefined1 *puStack_24;
  uint local_20;
  uint uStack_1c;
  int iStack_18;
  uint *puStack_14;
  
  puStack_14 = param_1;
  iStack_18 = param_2;
  uStack_1c = param_3;
  puStack_24 = &LAB_10018398;
  pvStack_28 = ExceptionList;
  local_20 = DAT_10037490 ^ (uint)&pvStack_28;
  ExceptionList = &pvStack_28;
  while( true ) {
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((uVar2 == 0xfffffffe) || ((param_3 != 0xfffffffe && (uVar2 <= param_3)))) break;
    puVar1 = (undefined4 *)((*(uint *)(param_2 + 8) ^ *param_1) + 0x10 + uVar2 * 0xc);
    *(undefined4 *)(param_2 + 0xc) = *puVar1;
    if (puVar1[1] == 0) {
      __NLG_Notify(0x101);
      FUN_1001daac();
    }
  }
  ExceptionList = pvStack_28;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018376` | `1001da8d` | `UNCONDITIONAL_CALL` | __NLG_Notify | `1001da8d` |
| `10018383` | `1001daac` | `UNCONDITIONAL_CALL` | FUN_1001daac | `1001daac` |

## Callers

| From | Function |
| --- | --- |
| `10011af9` | __fsopen |
| `1001844f` | _EH4_LocalUnwind |
| `100183c5` |  |
| `100183ee` | FUN_100183de |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001831c` | `10018398` | `DATA` | LAB_10018398 |
| `10018321` | `ffdff000` | `READ` | ExceptionList |
| `10018328` | `10037490` | `READ` | DAT_10037490 |
| `10018333` | `ffdff000` | `WRITE` | ExceptionList |
| `1001838a` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018308` | `53` | `PUSH EBX` |
| `10018309` | `56` | `PUSH ESI` |
| `1001830a` | `57` | `PUSH EDI` |
| `1001830b` | `8b 54 24 10` | `MOV EDX,dword ptr [ESP + 0x10]` |
| `1001830f` | `8b 44 24 14` | `MOV EAX,dword ptr [ESP + 0x14]` |
| `10018313` | `8b 4c 24 18` | `MOV ECX,dword ptr [ESP + 0x18]` |
| `10018317` | `55` | `PUSH EBP` |
| `10018318` | `52` | `PUSH EDX` |
| `10018319` | `50` | `PUSH EAX` |
| `1001831a` | `51` | `PUSH ECX` |
| `1001831b` | `51` | `PUSH ECX` |
| `1001831c` | `68 98 83 01 10` | `PUSH 0x10018398` |
| `10018321` | `64 ff 35 00 00 00 00` | `PUSH dword ptr FS:[0x0]` |
| `10018328` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001832d` | `33 c4` | `XOR EAX,ESP` |
| `1001832f` | `89 44 24 08` | `MOV dword ptr [ESP + 0x8],EAX` |
| `10018333` | `64 89 25 00 00 00 00` | `MOV dword ptr FS:[0x0],ESP` |
| `1001833a` | `8b 44 24 30` | `MOV EAX,dword ptr [ESP + 0x30]` |
| `1001833e` | `8b 58 08` | `MOV EBX,dword ptr [EAX + 0x8]` |
| `10018341` | `8b 4c 24 2c` | `MOV ECX,dword ptr [ESP + 0x2c]` |
| `10018345` | `33 19` | `XOR EBX,dword ptr [ECX]` |
| `10018347` | `8b 70 0c` | `MOV ESI,dword ptr [EAX + 0xc]` |
| `1001834a` | `83 fe fe` | `CMP ESI,-0x2` |
| `1001834d` | `74 3b` | `JZ 0x1001838a` |
| `1001834f` | `8b 54 24 34` | `MOV EDX,dword ptr [ESP + 0x34]` |
| `10018353` | `83 fa fe` | `CMP EDX,-0x2` |
| `10018356` | `74 04` | `JZ 0x1001835c` |
| `10018358` | `3b f2` | `CMP ESI,EDX` |
| `1001835a` | `76 2e` | `JBE 0x1001838a` |
| `1001835c` | `8d 34 76` | `LEA ESI,[ESI + ESI*0x2]` |
| `1001835f` | `8d 5c b3 10` | `LEA EBX,[EBX + ESI*0x4 + 0x10]` |
| `10018363` | `8b 0b` | `MOV ECX,dword ptr [EBX]` |
| `10018365` | `89 48 0c` | `MOV dword ptr [EAX + 0xc],ECX` |
| `10018368` | `83 7b 04 00` | `CMP dword ptr [EBX + 0x4],0x0` |
| `1001836c` | `75 cc` | `JNZ 0x1001833a` |
| `1001836e` | `68 01 01 00 00` | `PUSH 0x101` |
| `10018373` | `8b 43 08` | `MOV EAX,dword ptr [EBX + 0x8]` |
| `10018376` | `e8 12 57 00 00` | `CALL 0x1001da8d` |
| `1001837b` | `b9 01 00 00 00` | `MOV ECX,0x1` |
| `10018380` | `8b 43 08` | `MOV EAX,dword ptr [EBX + 0x8]` |
| `10018383` | `e8 24 57 00 00` | `CALL 0x1001daac` |
| `10018388` | `eb b0` | `JMP 0x1001833a` |
| `1001838a` | `64 8f 05 00 00 00 00` | `POP dword ptr FS:[0x0]` |
| `10018391` | `83 c4 18` | `ADD ESP,0x18` |
| `10018394` | `5f` | `POP EDI` |
| `10018395` | `5e` | `POP ESI` |
| `10018396` | `5b` | `POP EBX` |
| `10018397` | `c3` | `RET` |
