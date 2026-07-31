# 1002a8af `__cftof2_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a8af |
| `name` | __cftof2_l |
| `namespace` | Global |
| `signature` | undefined __cftof2_l(void) |
| `size_bytes` | 247 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftof2_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftof2_l
   
   Library: Visual Studio 2008 Release */

undefined4 __cftof2_l(int param_1,size_t param_2,char param_3,localeinfo_struct *param_4)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int *piVar3;
  undefined4 uVar4;
  undefined1 *in_ECX;
  size_t sVar5;
  undefined1 *puVar6;
  int local_14 [2];
  int local_c;
  char local_8;
  
  iVar1 = in_EAX[1];
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,param_4);
  if ((in_ECX == (undefined1 *)0x0) || (param_1 == 0)) {
    piVar3 = __errno();
    uVar4 = 0x16;
    *piVar3 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  else {
    if ((param_3 != '\0') && (iVar1 - 1U == param_2)) {
      iVar2 = *in_EAX;
      in_ECX[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = 0x30;
      (in_ECX + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = 0;
    }
    if (*in_EAX == 0x2d) {
      *in_ECX = 0x2d;
      in_ECX = in_ECX + 1;
    }
    if (in_EAX[1] < 1) {
      __shift();
      *in_ECX = 0x30;
      puVar6 = in_ECX + 1;
    }
    else {
      puVar6 = in_ECX + in_EAX[1];
    }
    if (0 < (int)param_2) {
      __shift();
      *puVar6 = *(undefined1 *)**(undefined4 **)(local_14[0] + 0xbc);
      if (in_EAX[1] < 0) {
        sVar5 = -in_EAX[1];
        if ((param_3 != '\0') || ((int)sVar5 <= (int)param_2)) {
          param_2 = sVar5;
        }
        __shift();
        _memset(puVar6 + 1,0x30,param_2);
      }
    }
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    uVar4 = 0;
  }
  return uVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a8c8` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002a8d1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a8e2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002a93b` | `1002a298` | `UNCONDITIONAL_CALL` | __shift | `1002a298` |
| `1002a950` | `1002a298` | `UNCONDITIONAL_CALL` | __shift | `1002a298` |
| `1002a981` | `1002a298` | `UNCONDITIONAL_CALL` | __shift | `1002a298` |
| `1002a98a` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |

## Callers

| From | Function |
| --- | --- |
| `1002aa4a` | __cftof_l |
| `1002ab26` | __cftog_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a8af` | `8b ff` | `MOV EDI,EDI` |
| `1002a8b1` | `55` | `PUSH EBP` |
| `1002a8b2` | `8b ec` | `MOV EBP,ESP` |
| `1002a8b4` | `83 ec 10` | `SUB ESP,0x10` |
| `1002a8b7` | `53` | `PUSH EBX` |
| `1002a8b8` | `56` | `PUSH ESI` |
| `1002a8b9` | `57` | `PUSH EDI` |
| `1002a8ba` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002a8bd` | `8b d8` | `MOV EBX,EAX` |
| `1002a8bf` | `8b 73 04` | `MOV ESI,dword ptr [EBX + 0x4]` |
| `1002a8c2` | `8b f9` | `MOV EDI,ECX` |
| `1002a8c4` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1002a8c7` | `4e` | `DEC ESI` |
| `1002a8c8` | `e8 e9 a9 fe ff` | `CALL 0x100152b6` |
| `1002a8cd` | `85 ff` | `TEST EDI,EDI` |
| `1002a8cf` | `75 2d` | `JNZ 0x1002a8fe` |
| `1002a8d1` | `e8 33 a8 fe ff` | `CALL 0x10015109` |
| `1002a8d6` | `6a 16` | `PUSH 0x16` |
| `1002a8d8` | `5e` | `POP ESI` |
| `1002a8d9` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1002a8db` | `33 c0` | `XOR EAX,EAX` |
| `1002a8dd` | `50` | `PUSH EAX` |
| `1002a8de` | `50` | `PUSH EAX` |
| `1002a8df` | `50` | `PUSH EAX` |
| `1002a8e0` | `50` | `PUSH EAX` |
| `1002a8e1` | `50` | `PUSH EAX` |
| `1002a8e2` | `e8 c8 6d fe ff` | `CALL 0x100116af` |
| `1002a8e7` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a8ea` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1002a8ee` | `74 07` | `JZ 0x1002a8f7` |
| `1002a8f0` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a8f3` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a8f7` | `8b c6` | `MOV EAX,ESI` |
| `1002a8f9` | `e9 a3 00 00 00` | `JMP 0x1002a9a1` |
| `1002a8fe` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1002a902` | `76 cd` | `JBE 0x1002a8d1` |
| `1002a904` | `80 7d 10 00` | `CMP byte ptr [EBP + 0x10],0x0` |
| `1002a908` | `74 18` | `JZ 0x1002a922` |
| `1002a90a` | `3b 75 0c` | `CMP ESI,dword ptr [EBP + 0xc]` |
| `1002a90d` | `75 13` | `JNZ 0x1002a922` |
| `1002a90f` | `33 c0` | `XOR EAX,EAX` |
| `1002a911` | `83 3b 2d` | `CMP dword ptr [EBX],0x2d` |
| `1002a914` | `0f 94 c0` | `SETZ AL` |
| `1002a917` | `03 c6` | `ADD EAX,ESI` |
| `1002a919` | `03 c7` | `ADD EAX,EDI` |
| `1002a91b` | `c6 00 30` | `MOV byte ptr [EAX],0x30` |
| `1002a91e` | `c6 40 01 00` | `MOV byte ptr [EAX + 0x1],0x0` |
| `1002a922` | `83 3b 2d` | `CMP dword ptr [EBX],0x2d` |
| `1002a925` | `8b f7` | `MOV ESI,EDI` |
| `1002a927` | `75 06` | `JNZ 0x1002a92f` |
| `1002a929` | `c6 07 2d` | `MOV byte ptr [EDI],0x2d` |
| `1002a92c` | `8d 77 01` | `LEA ESI,[EDI + 0x1]` |
| `1002a92f` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1002a932` | `33 ff` | `XOR EDI,EDI` |
| `1002a934` | `47` | `INC EDI` |
| `1002a935` | `85 c0` | `TEST EAX,EAX` |
| `1002a937` | `7f 0d` | `JG 0x1002a946` |
| `1002a939` | `8b c6` | `MOV EAX,ESI` |
| `1002a93b` | `e8 58 f9 ff ff` | `CALL 0x1002a298` |
| `1002a940` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002a943` | `46` | `INC ESI` |
| `1002a944` | `eb 02` | `JMP 0x1002a948` |
| `1002a946` | `03 f0` | `ADD ESI,EAX` |
| `1002a948` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `1002a94c` | `7e 44` | `JLE 0x1002a992` |
| `1002a94e` | `8b c6` | `MOV EAX,ESI` |
| `1002a950` | `e8 43 f9 ff ff` | `CALL 0x1002a298` |
| `1002a955` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1002a958` | `8b 80 bc 00 00 00` | `MOV EAX,dword ptr [EAX + 0xbc]` |
| `1002a95e` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1002a960` | `8a 00` | `MOV AL,byte ptr [EAX]` |
| `1002a962` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a964` | `8b 5b 04` | `MOV EBX,dword ptr [EBX + 0x4]` |
| `1002a967` | `46` | `INC ESI` |
| `1002a968` | `85 db` | `TEST EBX,EBX` |
| `1002a96a` | `7d 26` | `JGE 0x1002a992` |
| `1002a96c` | `f7 db` | `NEG EBX` |
| `1002a96e` | `80 7d 10 00` | `CMP byte ptr [EBP + 0x10],0x0` |
| `1002a972` | `75 05` | `JNZ 0x1002a979` |
| `1002a974` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1002a977` | `7c 03` | `JL 0x1002a97c` |
| `1002a979` | `89 5d 0c` | `MOV dword ptr [EBP + 0xc],EBX` |
| `1002a97c` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002a97f` | `8b c6` | `MOV EAX,ESI` |
| `1002a981` | `e8 12 f9 ff ff` | `CALL 0x1002a298` |
| `1002a986` | `57` | `PUSH EDI` |
| `1002a987` | `6a 30` | `PUSH 0x30` |
| `1002a989` | `56` | `PUSH ESI` |
| `1002a98a` | `e8 61 6d fe ff` | `CALL 0x100116f0` |
| `1002a98f` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002a992` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1002a996` | `74 07` | `JZ 0x1002a99f` |
| `1002a998` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a99b` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a99f` | `33 c0` | `XOR EAX,EAX` |
| `1002a9a1` | `5f` | `POP EDI` |
| `1002a9a2` | `5e` | `POP ESI` |
| `1002a9a3` | `5b` | `POP EBX` |
| `1002a9a4` | `c9` | `LEAVE` |
| `1002a9a5` | `c3` | `RET` |
