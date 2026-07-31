# 1002a2dd `__cftoe2_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a2dd |
| `name` | __cftoe2_l |
| `namespace` | Global |
| `signature` | undefined __cftoe2_l(void) |
| `size_bytes` | 364 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftoe2_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftoe2_l
   
   Library: Visual Studio 2008 Release */

int __cftoe2_l(uint param_1,int param_2,int param_3,int *param_4,char param_5,
              localeinfo_struct *param_6)

{
  undefined1 *in_EAX;
  int *piVar1;
  errno_t eVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  char *_Dst;
  int iVar6;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,param_6);
  if ((in_EAX == (undefined1 *)0x0) || (param_1 == 0)) {
    piVar1 = __errno();
    iVar6 = 0x16;
  }
  else {
    iVar6 = param_2;
    if (param_2 < 1) {
      iVar6 = 0;
    }
    if (iVar6 + 9U < param_1) {
      if (param_5 != '\0') {
        __shift();
      }
      puVar4 = in_EAX;
      if (*param_4 == 0x2d) {
        *in_EAX = 0x2d;
        puVar4 = in_EAX + 1;
      }
      puVar5 = puVar4;
      if (0 < param_2) {
        puVar5 = puVar4 + 1;
        *puVar4 = *puVar5;
        *puVar5 = *(undefined1 *)**(undefined4 **)(local_14[0] + 0xbc);
      }
      _Dst = puVar5 + (uint)(param_5 == '\0') + param_2;
      if (param_1 == 0xffffffff) {
        puVar4 = (undefined1 *)0xffffffff;
      }
      else {
        puVar4 = in_EAX + (param_1 - (int)_Dst);
      }
      eVar2 = _strcpy_s(_Dst,(rsize_t)puVar4,"e+000");
      if (eVar2 == 0) {
        if (param_3 != 0) {
          *_Dst = 'E';
        }
        if (*(char *)param_4[3] != '0') {
          iVar6 = param_4[1] + -1;
          if (iVar6 < 0) {
            iVar6 = -iVar6;
            _Dst[1] = '-';
          }
          if (99 < iVar6) {
            iVar3 = iVar6 / 100;
            iVar6 = iVar6 % 100;
            _Dst[2] = _Dst[2] + (char)iVar3;
          }
          if (9 < iVar6) {
            iVar3 = iVar6 / 10;
            iVar6 = iVar6 % 10;
            _Dst[3] = _Dst[3] + (char)iVar3;
          }
          _Dst[4] = _Dst[4] + (char)iVar6;
        }
        if (((DAT_1343952c & 1) != 0) && (_Dst[2] == '0')) {
          _memmove(_Dst + 2,_Dst + 3,3);
        }
        if (local_8 != '\0') {
          *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
        }
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    piVar1 = __errno();
    iVar6 = 0x22;
  }
  *piVar1 = iVar6;
  __invalid_parameter(0,0,0,0,0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return iVar6;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a2f0` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002a2fb` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a30a` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002a33f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a367` | `1002a298` | `UNCONDITIONAL_CALL` | __shift | `1002a298` |
| `1002a3be` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1002a3d1` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1002a430` | `10012740` | `UNCONDITIONAL_CALL` | _memmove | `10012740` |

## Callers

| From | Function |
| --- | --- |
| `1002a505` | __cftoe_l |
| `1002ab44` | __cftog_l |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1002a3b7` | `1003347c` | `e+000` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002a41b` | `1343952c` | `READ` | DAT_1343952c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a2dd` | `8b ff` | `MOV EDI,EDI` |
| `1002a2df` | `55` | `PUSH EBP` |
| `1002a2e0` | `8b ec` | `MOV EBP,ESP` |
| `1002a2e2` | `83 ec 10` | `SUB ESP,0x10` |
| `1002a2e5` | `53` | `PUSH EBX` |
| `1002a2e6` | `56` | `PUSH ESI` |
| `1002a2e7` | `57` | `PUSH EDI` |
| `1002a2e8` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002a2eb` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1002a2ee` | `8b d8` | `MOV EBX,EAX` |
| `1002a2f0` | `e8 c1 af fe ff` | `CALL 0x100152b6` |
| `1002a2f5` | `33 f6` | `XOR ESI,ESI` |
| `1002a2f7` | `3b de` | `CMP EBX,ESI` |
| `1002a2f9` | `75 2b` | `JNZ 0x1002a326` |
| `1002a2fb` | `e8 09 ae fe ff` | `CALL 0x10015109` |
| `1002a300` | `6a 16` | `PUSH 0x16` |
| `1002a302` | `5f` | `POP EDI` |
| `1002a303` | `56` | `PUSH ESI` |
| `1002a304` | `56` | `PUSH ESI` |
| `1002a305` | `56` | `PUSH ESI` |
| `1002a306` | `56` | `PUSH ESI` |
| `1002a307` | `56` | `PUSH ESI` |
| `1002a308` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `1002a30a` | `e8 a0 73 fe ff` | `CALL 0x100116af` |
| `1002a30f` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a312` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1002a316` | `74 07` | `JZ 0x1002a31f` |
| `1002a318` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a31b` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a31f` | `8b c7` | `MOV EAX,EDI` |
| `1002a321` | `e9 21 01 00 00` | `JMP 0x1002a447` |
| `1002a326` | `39 75 08` | `CMP dword ptr [EBP + 0x8],ESI` |
| `1002a329` | `76 d0` | `JBE 0x1002a2fb` |
| `1002a32b` | `39 75 0c` | `CMP dword ptr [EBP + 0xc],ESI` |
| `1002a32e` | `7e 05` | `JLE 0x1002a335` |
| `1002a330` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1002a333` | `eb 02` | `JMP 0x1002a337` |
| `1002a335` | `33 c0` | `XOR EAX,EAX` |
| `1002a337` | `83 c0 09` | `ADD EAX,0x9` |
| `1002a33a` | `39 45 08` | `CMP dword ptr [EBP + 0x8],EAX` |
| `1002a33d` | `77 09` | `JA 0x1002a348` |
| `1002a33f` | `e8 c5 ad fe ff` | `CALL 0x10015109` |
| `1002a344` | `6a 22` | `PUSH 0x22` |
| `1002a346` | `eb ba` | `JMP 0x1002a302` |
| `1002a348` | `80 7d 18 00` | `CMP byte ptr [EBP + 0x18],0x0` |
| `1002a34c` | `74 1e` | `JZ 0x1002a36c` |
| `1002a34e` | `8b 55 14` | `MOV EDX,dword ptr [EBP + 0x14]` |
| `1002a351` | `33 c0` | `XOR EAX,EAX` |
| `1002a353` | `39 75 0c` | `CMP dword ptr [EBP + 0xc],ESI` |
| `1002a356` | `0f 9f c0` | `SETG AL` |
| `1002a359` | `33 c9` | `XOR ECX,ECX` |
| `1002a35b` | `83 3a 2d` | `CMP dword ptr [EDX],0x2d` |
| `1002a35e` | `0f 94 c1` | `SETZ CL` |
| `1002a361` | `8b f8` | `MOV EDI,EAX` |
| `1002a363` | `03 cb` | `ADD ECX,EBX` |
| `1002a365` | `8b c1` | `MOV EAX,ECX` |
| `1002a367` | `e8 2c ff ff ff` | `CALL 0x1002a298` |
| `1002a36c` | `8b 7d 14` | `MOV EDI,dword ptr [EBP + 0x14]` |
| `1002a36f` | `83 3f 2d` | `CMP dword ptr [EDI],0x2d` |
| `1002a372` | `8b f3` | `MOV ESI,EBX` |
| `1002a374` | `75 06` | `JNZ 0x1002a37c` |
| `1002a376` | `c6 03 2d` | `MOV byte ptr [EBX],0x2d` |
| `1002a379` | `8d 73 01` | `LEA ESI,[EBX + 0x1]` |
| `1002a37c` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `1002a380` | `7e 18` | `JLE 0x1002a39a` |
| `1002a382` | `8d 46 01` | `LEA EAX,[ESI + 0x1]` |
| `1002a385` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a387` | `88 0e` | `MOV byte ptr [ESI],CL` |
| `1002a389` | `8b f0` | `MOV ESI,EAX` |
| `1002a38b` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1002a38e` | `8b 80 bc 00 00 00` | `MOV EAX,dword ptr [EAX + 0xbc]` |
| `1002a394` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1002a396` | `8a 00` | `MOV AL,byte ptr [EAX]` |
| `1002a398` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a39a` | `33 c0` | `XOR EAX,EAX` |
| `1002a39c` | `38 45 18` | `CMP byte ptr [EBP + 0x18],AL` |
| `1002a39f` | `0f 94 c0` | `SETZ AL` |
| `1002a3a2` | `03 45 0c` | `ADD EAX,dword ptr [EBP + 0xc]` |
| `1002a3a5` | `03 f0` | `ADD ESI,EAX` |
| `1002a3a7` | `83 7d 08 ff` | `CMP dword ptr [EBP + 0x8],-0x1` |
| `1002a3ab` | `75 05` | `JNZ 0x1002a3b2` |
| `1002a3ad` | `83 cb ff` | `OR EBX,0xffffffff` |
| `1002a3b0` | `eb 05` | `JMP 0x1002a3b7` |
| `1002a3b2` | `2b de` | `SUB EBX,ESI` |
| `1002a3b4` | `03 5d 08` | `ADD EBX,dword ptr [EBP + 0x8]` |
| `1002a3b7` | `68 7c 34 03 10` | `PUSH 0x1003347c` |
| `1002a3bc` | `53` | `PUSH EBX` |
| `1002a3bd` | `56` | `PUSH ESI` |
| `1002a3be` | `e8 b8 bb fe ff` | `CALL 0x10015f7b` |
| `1002a3c3` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002a3c6` | `33 db` | `XOR EBX,EBX` |
| `1002a3c8` | `85 c0` | `TEST EAX,EAX` |
| `1002a3ca` | `74 0d` | `JZ 0x1002a3d9` |
| `1002a3cc` | `53` | `PUSH EBX` |
| `1002a3cd` | `53` | `PUSH EBX` |
| `1002a3ce` | `53` | `PUSH EBX` |
| `1002a3cf` | `53` | `PUSH EBX` |
| `1002a3d0` | `53` | `PUSH EBX` |
| `1002a3d1` | `e8 b1 71 fe ff` | `CALL 0x10011587` |
| `1002a3d9` | `8d 4e 02` | `LEA ECX,[ESI + 0x2]` |
| `1002a3dc` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `1002a3df` | `74 03` | `JZ 0x1002a3e4` |
| `1002a3e1` | `c6 06 45` | `MOV byte ptr [ESI],0x45` |
| `1002a3e4` | `8b 47 0c` | `MOV EAX,dword ptr [EDI + 0xc]` |
| `1002a3e7` | `46` | `INC ESI` |
| `1002a3e8` | `80 38 30` | `CMP byte ptr [EAX],0x30` |
| `1002a3eb` | `74 2e` | `JZ 0x1002a41b` |
| `1002a3ed` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1002a3f0` | `48` | `DEC EAX` |
| `1002a3f1` | `79 05` | `JNS 0x1002a3f8` |
| `1002a3f3` | `f7 d8` | `NEG EAX` |
| `1002a3f5` | `c6 06 2d` | `MOV byte ptr [ESI],0x2d` |
| `1002a3f8` | `46` | `INC ESI` |
| `1002a3f9` | `83 f8 64` | `CMP EAX,0x64` |
| `1002a3fc` | `7c 0a` | `JL 0x1002a408` |
| `1002a3fe` | `99` | `CDQ` |
| `1002a3ff` | `6a 64` | `PUSH 0x64` |
| `1002a401` | `5f` | `POP EDI` |
| `1002a402` | `f7 ff` | `IDIV EDI` |
| `1002a404` | `00 06` | `ADD byte ptr [ESI],AL` |
| `1002a406` | `8b c2` | `MOV EAX,EDX` |
| `1002a408` | `46` | `INC ESI` |
| `1002a409` | `83 f8 0a` | `CMP EAX,0xa` |
| `1002a40c` | `7c 0a` | `JL 0x1002a418` |
| `1002a40e` | `99` | `CDQ` |
| `1002a40f` | `6a 0a` | `PUSH 0xa` |
| `1002a411` | `5f` | `POP EDI` |
| `1002a412` | `f7 ff` | `IDIV EDI` |
| `1002a414` | `00 06` | `ADD byte ptr [ESI],AL` |
| `1002a416` | `8b c2` | `MOV EAX,EDX` |
| `1002a418` | `00 46 01` | `ADD byte ptr [ESI + 0x1],AL` |
| `1002a41b` | `f6 05 2c 95 43 13 01` | `TEST byte ptr [0x1343952c],0x1` |
| `1002a422` | `74 14` | `JZ 0x1002a438` |
| `1002a424` | `80 39 30` | `CMP byte ptr [ECX],0x30` |
| `1002a427` | `75 0f` | `JNZ 0x1002a438` |
| `1002a429` | `6a 03` | `PUSH 0x3` |
| `1002a42b` | `8d 41 01` | `LEA EAX,[ECX + 0x1]` |
| `1002a42e` | `50` | `PUSH EAX` |
| `1002a42f` | `51` | `PUSH ECX` |
| `1002a430` | `e8 0b 83 fe ff` | `CALL 0x10012740` |
| `1002a435` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002a438` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1002a43c` | `74 07` | `JZ 0x1002a445` |
| `1002a43e` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a441` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a445` | `33 c0` | `XOR EAX,EAX` |
| `1002a447` | `5f` | `POP EDI` |
| `1002a448` | `5e` | `POP ESI` |
| `1002a449` | `5b` | `POP EBX` |
| `1002a44a` | `c9` | `LEAVE` |
| `1002a44b` | `c3` | `RET` |
