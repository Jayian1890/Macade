# 1002a53c `__cftoa_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a53c |
| `name` | __cftoa_l |
| `namespace` | Global |
| `signature` | undefined __cftoa_l(void) |
| `size_bytes` | 883 |
| `stack_frame_size` | 44 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __cftoa_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cftoa_l
   
   Library: Visual Studio 2008 Release */

int __cftoa_l(double *param_1,undefined1 *param_2,uint param_3,size_t param_4,int param_5,
             localeinfo_struct *param_6)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  int *piVar4;
  size_t _SizeInBytes;
  errno_t eVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  short sVar10;
  char *pcVar11;
  char *pcVar12;
  bool bVar13;
  int iVar14;
  int local_28 [2];
  int local_20;
  char local_1c;
  uint local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  local_18 = 0x3ff;
  local_8 = 0x30;
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_28,param_6);
  if ((int)param_4 < 0) {
    param_4 = 0;
  }
  if ((param_2 == (undefined1 *)0x0) || (param_3 == 0)) {
    piVar4 = __errno();
    iVar14 = 0x16;
LAB_1002a577:
    *piVar4 = iVar14;
    __invalid_parameter(0,0,0,0,0);
    if (local_1c != '\0') {
      *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
    }
    return iVar14;
  }
  *param_2 = 0;
  if (param_3 <= param_4 + 0xb) {
    piVar4 = __errno();
    iVar14 = 0x22;
    goto LAB_1002a577;
  }
  local_10 = *(uint *)param_1;
  if ((*(uint *)((int)param_1 + 4) >> 0x14 & 0x7ff) == 0x7ff) {
    if (param_3 == 0xffffffff) {
      _SizeInBytes = 0xffffffff;
    }
    else {
      _SizeInBytes = param_3 - 2;
    }
    eVar5 = __cftoe(param_1,param_2 + 2,_SizeInBytes,param_4,0);
    if (eVar5 != 0) {
      *param_2 = 0;
      if (local_1c == '\0') {
        return eVar5;
      }
      *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
      return eVar5;
    }
    if (param_2[2] == '-') {
      *param_2 = 0x2d;
      param_2 = param_2 + 1;
    }
    *param_2 = 0x30;
    param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
    pcVar6 = _strrchr(param_2 + 2,0x65);
    if (pcVar6 != (char *)0x0) {
      *pcVar6 = ((param_5 == 0) - 1U & 0xe0) + 0x70;
      pcVar6[3] = '\0';
    }
    goto LAB_1002a89b;
  }
  if ((*(uint *)((int)param_1 + 4) & 0x80000000) != 0) {
    *param_2 = 0x2d;
    param_2 = param_2 + 1;
  }
  *param_2 = 0x30;
  param_2[1] = ((param_5 == 0) - 1U & 0xe0) + 0x78;
  sVar10 = (-(ushort)(param_5 != 0) & 0xffe0) + 0x27;
  if (((ulonglong)*param_1 & 0x7ff0000000000000) == 0) {
    param_2[2] = 0x30;
    if (*(int *)param_1 == 0 && ((ulonglong)*param_1 & 0xfffff00000000) == 0) {
      local_18 = 0;
    }
    else {
      local_18 = 0x3fe;
    }
  }
  else {
    param_2[2] = 0x31;
  }
  pcVar12 = param_2 + 3;
  pcVar6 = param_2 + 4;
  if (param_4 == 0) {
    *pcVar12 = '\0';
  }
  else {
    *pcVar12 = *(char *)**(undefined4 **)(local_28[0] + 0xbc);
  }
  if ((((ulonglong)*param_1 & 0xfffff00000000) != 0) || (local_c = 0, *(int *)param_1 != 0)) {
    local_10 = 0;
    local_c = 0xf0000;
    do {
      if ((int)param_4 < 1) break;
      sVar2 = __aullshr();
      uVar3 = sVar2 + 0x30;
      if (0x39 < uVar3) {
        uVar3 = uVar3 + sVar10;
      }
      local_8 = local_8 + -4;
      *pcVar6 = (char)uVar3;
      local_10 = local_10 >> 4 | local_c << 0x1c;
      local_c = local_c >> 4;
      pcVar6 = pcVar6 + 1;
      param_4 = param_4 - 1;
    } while (-1 < (short)local_8);
    if ((-1 < (short)local_8) && (uVar3 = __aullshr(), pcVar11 = pcVar6, 8 < uVar3)) {
      while( true ) {
        pcVar7 = pcVar11 + -1;
        if ((*pcVar7 != 'f') && (*pcVar7 != 'F')) break;
        *pcVar7 = '0';
        pcVar11 = pcVar7;
      }
      if (pcVar7 == pcVar12) {
        pcVar11[-2] = pcVar11[-2] + '\x01';
      }
      else if (*pcVar7 == '9') {
        *pcVar7 = (char)sVar10 + ':';
      }
      else {
        *pcVar7 = *pcVar7 + '\x01';
      }
    }
  }
  if (0 < (int)param_4) {
    _memset(pcVar6,0x30,param_4);
    pcVar6 = pcVar6 + param_4;
  }
  if (*pcVar12 == '\0') {
    pcVar6 = pcVar12;
  }
  *pcVar6 = ((param_5 == 0) - 1U & 0xe0) + 0x70;
  uVar8 = __aullshr();
  uVar9 = (uVar8 & 0x7ff) - local_18;
  iVar14 = -(uint)((uVar8 & 0x7ff) < local_18);
  if (iVar14 < 0) {
    pcVar6[1] = '-';
    bVar13 = uVar9 != 0;
    uVar9 = -uVar9;
    iVar14 = -(iVar14 + (uint)bVar13);
  }
  else {
    pcVar6[1] = '+';
  }
  pcVar11 = pcVar6 + 2;
  *pcVar11 = '0';
  pcVar12 = pcVar11;
  if ((iVar14 < 0) || ((iVar14 < 1 && (uVar9 < 1000)))) {
LAB_1002a84a:
    if ((-1 < iVar14) && ((0 < iVar14 || (99 < uVar9)))) goto LAB_1002a855;
  }
  else {
    cVar1 = __alldvrm(uVar9,iVar14,1000,0);
    *pcVar11 = cVar1 + '0';
    pcVar12 = pcVar6 + 3;
    iVar14 = 0;
    uVar9 = extraout_ECX;
    local_14 = extraout_EDX;
    if (pcVar12 == pcVar11) goto LAB_1002a84a;
LAB_1002a855:
    cVar1 = __alldvrm(uVar9,iVar14,100,0);
    *pcVar12 = cVar1 + '0';
    pcVar12 = pcVar12 + 1;
    iVar14 = 0;
    uVar9 = extraout_ECX_00;
    local_14 = extraout_EDX_00;
  }
  if ((pcVar12 != pcVar11) || ((-1 < iVar14 && ((0 < iVar14 || (9 < uVar9)))))) {
    cVar1 = __alldvrm(uVar9,iVar14,10,0);
    *pcVar12 = cVar1 + '0';
    pcVar12 = pcVar12 + 1;
    uVar9 = extraout_ECX_01;
  }
  *pcVar12 = (char)uVar9 + '0';
  pcVar12[1] = '\0';
LAB_1002a89b:
  if (local_1c != '\0') {
    *(uint *)(local_20 + 0x70) = *(uint *)(local_20 + 0x70) & 0xfffffffd;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a55c` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002a570` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a57f` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002a5ae` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002a5fb` | `1002a51c` | `UNCONDITIONAL_CALL` | __cftoe | `1002a51c` |
| `1002a640` | `1002aca0` | `UNCONDITIONAL_CALL` | _strrchr | `1002aca0` |
| `1002a728` | `1002b110` | `UNCONDITIONAL_CALL` | __aullshr | `1002b110` |
| `1002a77c` | `1002b110` | `UNCONDITIONAL_CALL` | __aullshr | `1002b110` |
| `1002a7c4` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1002a7f0` | `1002b110` | `UNCONDITIONAL_CALL` | __aullshr | `1002b110` |
| `1002a835` | `1002b030` | `UNCONDITIONAL_CALL` | __alldvrm | `1002b030` |
| `1002a85b` | `1002b030` | `UNCONDITIONAL_CALL` | __alldvrm | `1002b030` |
| `1002a881` | `1002b030` | `UNCONDITIONAL_CALL` | __alldvrm | `1002b030` |

## Callers

| From | Function |
| --- | --- |
| `1002abc0` | __cfltcvt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a53c` | `8b ff` | `MOV EDI,EDI` |
| `1002a53e` | `55` | `PUSH EBP` |
| `1002a53f` | `8b ec` | `MOV EBP,ESP` |
| `1002a541` | `83 ec 24` | `SUB ESP,0x24` |
| `1002a544` | `56` | `PUSH ESI` |
| `1002a545` | `57` | `PUSH EDI` |
| `1002a546` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002a549` | `8d 4d dc` | `LEA ECX,[EBP + -0x24]` |
| `1002a54c` | `c7 45 ec ff 03 00 00` | `MOV dword ptr [EBP + -0x14],0x3ff` |
| `1002a553` | `33 ff` | `XOR EDI,EDI` |
| `1002a555` | `c7 45 fc 30 00 00 00` | `MOV dword ptr [EBP + -0x4],0x30` |
| `1002a55c` | `e8 55 ad fe ff` | `CALL 0x100152b6` |
| `1002a561` | `39 7d 14` | `CMP dword ptr [EBP + 0x14],EDI` |
| `1002a564` | `7d 03` | `JGE 0x1002a569` |
| `1002a566` | `89 7d 14` | `MOV dword ptr [EBP + 0x14],EDI` |
| `1002a569` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1002a56c` | `3b f7` | `CMP ESI,EDI` |
| `1002a56e` | `75 2b` | `JNZ 0x1002a59b` |
| `1002a570` | `e8 94 ab fe ff` | `CALL 0x10015109` |
| `1002a575` | `6a 16` | `PUSH 0x16` |
| `1002a577` | `5e` | `POP ESI` |
| `1002a578` | `57` | `PUSH EDI` |
| `1002a579` | `57` | `PUSH EDI` |
| `1002a57a` | `57` | `PUSH EDI` |
| `1002a57b` | `57` | `PUSH EDI` |
| `1002a57c` | `57` | `PUSH EDI` |
| `1002a57d` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1002a57f` | `e8 2b 71 fe ff` | `CALL 0x100116af` |
| `1002a584` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a587` | `80 7d e8 00` | `CMP byte ptr [EBP + -0x18],0x0` |
| `1002a58b` | `74 07` | `JZ 0x1002a594` |
| `1002a58d` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002a590` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a594` | `8b c6` | `MOV EAX,ESI` |
| `1002a596` | `e9 10 03 00 00` | `JMP 0x1002a8ab` |
| `1002a59b` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `1002a59e` | `76 d0` | `JBE 0x1002a570` |
| `1002a5a0` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1002a5a3` | `83 c0 0b` | `ADD EAX,0xb` |
| `1002a5a6` | `c6 06 00` | `MOV byte ptr [ESI],0x0` |
| `1002a5a9` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `1002a5ac` | `77 09` | `JA 0x1002a5b7` |
| `1002a5ae` | `e8 56 ab fe ff` | `CALL 0x10015109` |
| `1002a5b3` | `6a 22` | `PUSH 0x22` |
| `1002a5b5` | `eb c0` | `JMP 0x1002a577` |
| `1002a5b7` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1002a5ba` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a5bc` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002a5bf` | `8b 47 04` | `MOV EAX,dword ptr [EDI + 0x4]` |
| `1002a5c2` | `8b c8` | `MOV ECX,EAX` |
| `1002a5c4` | `c1 e9 14` | `SHR ECX,0x14` |
| `1002a5c7` | `ba ff 07 00 00` | `MOV EDX,0x7ff` |
| `1002a5cc` | `53` | `PUSH EBX` |
| `1002a5cd` | `23 ca` | `AND ECX,EDX` |
| `1002a5cf` | `33 db` | `XOR EBX,EBX` |
| `1002a5d1` | `3b ca` | `CMP ECX,EDX` |
| `1002a5d3` | `0f 85 90 00 00 00` | `JNZ 0x1002a669` |
| `1002a5d9` | `85 db` | `TEST EBX,EBX` |
| `1002a5db` | `0f 85 88 00 00 00` | `JNZ 0x1002a669` |
| `1002a5e1` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1002a5e4` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1002a5e7` | `75 04` | `JNZ 0x1002a5ed` |
| `1002a5e9` | `0b c0` | `OR EAX,EAX` |
| `1002a5eb` | `eb 03` | `JMP 0x1002a5f0` |
| `1002a5ed` | `83 c0 fe` | `ADD EAX,-0x2` |
| `1002a5f0` | `6a 00` | `PUSH 0x0` |
| `1002a5f2` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002a5f5` | `8d 5e 02` | `LEA EBX,[ESI + 0x2]` |
| `1002a5f8` | `50` | `PUSH EAX` |
| `1002a5f9` | `53` | `PUSH EBX` |
| `1002a5fa` | `57` | `PUSH EDI` |
| `1002a5fb` | `e8 1c ff ff ff` | `CALL 0x1002a51c` |
| `1002a600` | `83 c4 14` | `ADD ESP,0x14` |
| `1002a603` | `85 c0` | `TEST EAX,EAX` |
| `1002a605` | `74 19` | `JZ 0x1002a620` |
| `1002a607` | `80 7d e8 00` | `CMP byte ptr [EBP + -0x18],0x0` |
| `1002a60b` | `c6 06 00` | `MOV byte ptr [ESI],0x0` |
| `1002a60e` | `0f 84 96 02 00 00` | `JZ 0x1002a8aa` |
| `1002a614` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1002a617` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1002a61b` | `e9 8a 02 00 00` | `JMP 0x1002a8aa` |
| `1002a620` | `80 3b 2d` | `CMP byte ptr [EBX],0x2d` |
| `1002a623` | `75 04` | `JNZ 0x1002a629` |
| `1002a625` | `c6 06 2d` | `MOV byte ptr [ESI],0x2d` |
| `1002a628` | `46` | `INC ESI` |
| `1002a629` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002a62c` | `46` | `INC ESI` |
| `1002a62d` | `83 7d 18 00` | `CMP dword ptr [EBP + 0x18],0x0` |
| `1002a631` | `6a 65` | `PUSH 0x65` |
| `1002a633` | `0f 94 c0` | `SETZ AL` |
| `1002a636` | `fe c8` | `DEC AL` |
| `1002a638` | `24 e0` | `AND AL,0xe0` |
| `1002a63a` | `04 78` | `ADD AL,0x78` |
| `1002a63c` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a63e` | `46` | `INC ESI` |
| `1002a63f` | `56` | `PUSH ESI` |
| `1002a640` | `e8 5b 06 00 00` | `CALL 0x1002aca0` |
| `1002a645` | `59` | `POP ECX` |
| `1002a646` | `59` | `POP ECX` |
| `1002a647` | `85 c0` | `TEST EAX,EAX` |
| `1002a649` | `0f 84 4c 02 00 00` | `JZ 0x1002a89b` |
| `1002a64f` | `83 7d 18 00` | `CMP dword ptr [EBP + 0x18],0x0` |
| `1002a653` | `0f 94 c1` | `SETZ CL` |
| `1002a656` | `fe c9` | `DEC CL` |
| `1002a658` | `80 e1 e0` | `AND CL,0xe0` |
| `1002a65b` | `80 c1 70` | `ADD CL,0x70` |
| `1002a65e` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1002a660` | `c6 40 03 00` | `MOV byte ptr [EAX + 0x3],0x0` |
| `1002a664` | `e9 32 02 00 00` | `JMP 0x1002a89b` |
| `1002a669` | `25 00 00 00 80` | `AND EAX,0x80000000` |
| `1002a66e` | `33 c9` | `XOR ECX,ECX` |
| `1002a670` | `0b c8` | `OR ECX,EAX` |
| `1002a672` | `74 04` | `JZ 0x1002a678` |
| `1002a674` | `c6 06 2d` | `MOV byte ptr [ESI],0x2d` |
| `1002a677` | `46` | `INC ESI` |
| `1002a678` | `8b 5d 18` | `MOV EBX,dword ptr [EBP + 0x18]` |
| `1002a67b` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002a67e` | `46` | `INC ESI` |
| `1002a67f` | `85 db` | `TEST EBX,EBX` |
| `1002a681` | `0f 94 c0` | `SETZ AL` |
| `1002a684` | `fe c8` | `DEC AL` |
| `1002a686` | `24 e0` | `AND AL,0xe0` |
| `1002a688` | `04 78` | `ADD AL,0x78` |
| `1002a68a` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a68c` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `1002a68f` | `46` | `INC ESI` |
| `1002a690` | `f7 db` | `NEG EBX` |
| `1002a692` | `1b db` | `SBB EBX,EBX` |
| `1002a694` | `83 e3 e0` | `AND EBX,0xffffffe0` |
| `1002a697` | `81 e1 00 00 f0 7f` | `AND ECX,0x7ff00000` |
| `1002a69d` | `33 c0` | `XOR EAX,EAX` |
| `1002a69f` | `83 c3 27` | `ADD EBX,0x27` |
| `1002a6a2` | `33 d2` | `XOR EDX,EDX` |
| `1002a6a4` | `0b c1` | `OR EAX,ECX` |
| `1002a6a6` | `75 21` | `JNZ 0x1002a6c9` |
| `1002a6a8` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002a6ab` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `1002a6ae` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a6b0` | `81 e1 ff ff 0f 00` | `AND ECX,0xfffff` |
| `1002a6b6` | `46` | `INC ESI` |
| `1002a6b7` | `0b c1` | `OR EAX,ECX` |
| `1002a6b9` | `75 05` | `JNZ 0x1002a6c0` |
| `1002a6bb` | `89 55 ec` | `MOV dword ptr [EBP + -0x14],EDX` |
| `1002a6be` | `eb 0d` | `JMP 0x1002a6cd` |
| `1002a6c0` | `c7 45 ec fe 03 00 00` | `MOV dword ptr [EBP + -0x14],0x3fe` |
| `1002a6c7` | `eb 04` | `JMP 0x1002a6cd` |
| `1002a6c9` | `c6 06 31` | `MOV byte ptr [ESI],0x31` |
| `1002a6cc` | `46` | `INC ESI` |
| `1002a6cd` | `8b c6` | `MOV EAX,ESI` |
| `1002a6cf` | `46` | `INC ESI` |
| `1002a6d0` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `1002a6d3` | `39 55 14` | `CMP dword ptr [EBP + 0x14],EDX` |
| `1002a6d6` | `75 04` | `JNZ 0x1002a6dc` |
| `1002a6d8` | `88 10` | `MOV byte ptr [EAX],DL` |
| `1002a6da` | `eb 0f` | `JMP 0x1002a6eb` |
| `1002a6dc` | `8b 4d dc` | `MOV ECX,dword ptr [EBP + -0x24]` |
| `1002a6df` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002a6e5` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002a6e7` | `8a 09` | `MOV CL,byte ptr [ECX]` |
| `1002a6e9` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1002a6eb` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `1002a6ee` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a6f0` | `81 e1 ff ff 0f 00` | `AND ECX,0xfffff` |
| `1002a6f6` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1002a6f9` | `77 08` | `JA 0x1002a703` |
| `1002a6fb` | `3b c2` | `CMP EAX,EDX` |
| `1002a6fd` | `0f 86 b5 00 00 00` | `JBE 0x1002a7b8` |
| `1002a703` | `89 55 f4` | `MOV dword ptr [EBP + -0xc],EDX` |
| `1002a706` | `c7 45 f8 00 00 0f 00` | `MOV dword ptr [EBP + -0x8],0xf0000` |
| `1002a70d` | `83 7d 14 00` | `CMP dword ptr [EBP + 0x14],0x0` |
| `1002a711` | `7e 4d` | `JLE 0x1002a760` |
| `1002a713` | `8b 57 04` | `MOV EDX,dword ptr [EDI + 0x4]` |
| `1002a716` | `23 55 f8` | `AND EDX,dword ptr [EBP + -0x8]` |
| `1002a719` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a71b` | `0f bf 4d fc` | `MOVSX ECX,word ptr [EBP + -0x4]` |
| `1002a71f` | `23 45 f4` | `AND EAX,dword ptr [EBP + -0xc]` |
| `1002a722` | `81 e2 ff ff 0f 00` | `AND EDX,0xfffff` |
| `1002a728` | `e8 e3 09 00 00` | `CALL 0x1002b110` |
| `1002a72d` | `66 83 c0 30` | `ADD AX,0x30` |
| `1002a731` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1002a734` | `66 83 f8 39` | `CMP AX,0x39` |
| `1002a738` | `76 02` | `JBE 0x1002a73c` |
| `1002a73a` | `03 c3` | `ADD EAX,EBX` |
| `1002a73c` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002a73f` | `83 6d fc 04` | `SUB dword ptr [EBP + -0x4],0x4` |
| `1002a743` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a745` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002a748` | `0f ac c8 04` | `SHRD EAX,ECX,0x4` |
| `1002a74c` | `c1 e9 04` | `SHR ECX,0x4` |
| `1002a74f` | `46` | `INC ESI` |
| `1002a750` | `ff 4d 14` | `DEC dword ptr [EBP + 0x14]` |
| `1002a753` | `66 83 7d fc 00` | `CMP word ptr [EBP + -0x4],0x0` |
| `1002a758` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002a75b` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1002a75e` | `7d ad` | `JGE 0x1002a70d` |
| `1002a760` | `66 83 7d fc 00` | `CMP word ptr [EBP + -0x4],0x0` |
| `1002a765` | `7c 51` | `JL 0x1002a7b8` |
| `1002a767` | `8b 57 04` | `MOV EDX,dword ptr [EDI + 0x4]` |
| `1002a76a` | `23 55 f8` | `AND EDX,dword ptr [EBP + -0x8]` |
| `1002a76d` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a76f` | `0f bf 4d fc` | `MOVSX ECX,word ptr [EBP + -0x4]` |
| `1002a773` | `23 45 f4` | `AND EAX,dword ptr [EBP + -0xc]` |
| `1002a776` | `81 e2 ff ff 0f 00` | `AND EDX,0xfffff` |
| `1002a77c` | `e8 8f 09 00 00` | `CALL 0x1002b110` |
| `1002a781` | `66 83 f8 08` | `CMP AX,0x8` |
| `1002a785` | `76 31` | `JBE 0x1002a7b8` |
| `1002a787` | `8d 46 ff` | `LEA EAX,[ESI + -0x1]` |
| `1002a78a` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a78c` | `80 f9 66` | `CMP CL,0x66` |
| `1002a78f` | `74 05` | `JZ 0x1002a796` |
| `1002a791` | `80 f9 46` | `CMP CL,0x46` |
| `1002a794` | `75 06` | `JNZ 0x1002a79c` |
| `1002a796` | `c6 00 30` | `MOV byte ptr [EAX],0x30` |
| `1002a799` | `48` | `DEC EAX` |
| `1002a79a` | `eb ee` | `JMP 0x1002a78a` |
| `1002a79c` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `1002a79f` | `74 14` | `JZ 0x1002a7b5` |
| `1002a7a1` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a7a3` | `80 f9 39` | `CMP CL,0x39` |
| `1002a7a6` | `75 07` | `JNZ 0x1002a7af` |
| `1002a7a8` | `80 c3 3a` | `ADD BL,0x3a` |
| `1002a7ab` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1002a7ad` | `eb 09` | `JMP 0x1002a7b8` |
| `1002a7af` | `fe c1` | `INC CL` |
| `1002a7b1` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1002a7b3` | `eb 03` | `JMP 0x1002a7b8` |
| `1002a7b5` | `fe 40 ff` | `INC byte ptr [EAX + -0x1]` |
| `1002a7b8` | `83 7d 14 00` | `CMP dword ptr [EBP + 0x14],0x0` |
| `1002a7bc` | `7e 11` | `JLE 0x1002a7cf` |
| `1002a7be` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002a7c1` | `6a 30` | `PUSH 0x30` |
| `1002a7c3` | `56` | `PUSH ESI` |
| `1002a7c4` | `e8 27 6f fe ff` | `CALL 0x100116f0` |
| `1002a7c9` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002a7cc` | `03 75 14` | `ADD ESI,dword ptr [EBP + 0x14]` |
| `1002a7cf` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1002a7d2` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `1002a7d5` | `75 02` | `JNZ 0x1002a7d9` |
| `1002a7d7` | `8b f0` | `MOV ESI,EAX` |
| `1002a7d9` | `83 7d 18 00` | `CMP dword ptr [EBP + 0x18],0x0` |
| `1002a7dd` | `b1 34` | `MOV CL,0x34` |
| `1002a7df` | `0f 94 c0` | `SETZ AL` |
| `1002a7e2` | `fe c8` | `DEC AL` |
| `1002a7e4` | `24 e0` | `AND AL,0xe0` |
| `1002a7e6` | `04 70` | `ADD AL,0x70` |
| `1002a7e8` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a7ea` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1002a7ec` | `8b 57 04` | `MOV EDX,dword ptr [EDI + 0x4]` |
| `1002a7ef` | `46` | `INC ESI` |
| `1002a7f0` | `e8 1b 09 00 00` | `CALL 0x1002b110` |
| `1002a7f5` | `33 db` | `XOR EBX,EBX` |
| `1002a7f7` | `25 ff 07 00 00` | `AND EAX,0x7ff` |
| `1002a7fc` | `23 d3` | `AND EDX,EBX` |
| `1002a7fe` | `2b 45 ec` | `SUB EAX,dword ptr [EBP + -0x14]` |
| `1002a801` | `53` | `PUSH EBX` |
| `1002a802` | `59` | `POP ECX` |
| `1002a803` | `1b d1` | `SBB EDX,ECX` |
| `1002a805` | `78 0c` | `JS 0x1002a813` |
| `1002a807` | `7f 04` | `JG 0x1002a80d` |
| `1002a809` | `3b c3` | `CMP EAX,EBX` |
| `1002a80b` | `72 06` | `JC 0x1002a813` |
| `1002a80d` | `c6 06 2b` | `MOV byte ptr [ESI],0x2b` |
| `1002a810` | `46` | `INC ESI` |
| `1002a811` | `eb 0a` | `JMP 0x1002a81d` |
| `1002a813` | `c6 06 2d` | `MOV byte ptr [ESI],0x2d` |
| `1002a816` | `46` | `INC ESI` |
| `1002a817` | `f7 d8` | `NEG EAX` |
| `1002a819` | `13 d3` | `ADC EDX,EBX` |
| `1002a81b` | `f7 da` | `NEG EDX` |
| `1002a81d` | `3b d3` | `CMP EDX,EBX` |
| `1002a81f` | `8b fe` | `MOV EDI,ESI` |
| `1002a821` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002a824` | `7c 24` | `JL 0x1002a84a` |
| `1002a826` | `b9 e8 03 00 00` | `MOV ECX,0x3e8` |
| `1002a82b` | `7f 04` | `JG 0x1002a831` |
| `1002a82d` | `3b c1` | `CMP EAX,ECX` |
| `1002a82f` | `72 19` | `JC 0x1002a84a` |
| `1002a831` | `53` | `PUSH EBX` |
| `1002a832` | `51` | `PUSH ECX` |
| `1002a833` | `52` | `PUSH EDX` |
| `1002a834` | `50` | `PUSH EAX` |
| `1002a835` | `e8 f6 07 00 00` | `CALL 0x1002b030` |
| `1002a83a` | `04 30` | `ADD AL,0x30` |
| `1002a83c` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a83e` | `46` | `INC ESI` |
| `1002a83f` | `89 55 f0` | `MOV dword ptr [EBP + -0x10],EDX` |
| `1002a842` | `8b c1` | `MOV EAX,ECX` |
| `1002a844` | `8b d3` | `MOV EDX,EBX` |
| `1002a846` | `3b f7` | `CMP ESI,EDI` |
| `1002a848` | `75 0b` | `JNZ 0x1002a855` |
| `1002a84a` | `85 d2` | `TEST EDX,EDX` |
| `1002a84c` | `7c 1e` | `JL 0x1002a86c` |
| `1002a84e` | `7f 05` | `JG 0x1002a855` |
| `1002a850` | `83 f8 64` | `CMP EAX,0x64` |
| `1002a853` | `72 17` | `JC 0x1002a86c` |
| `1002a855` | `6a 00` | `PUSH 0x0` |
| `1002a857` | `6a 64` | `PUSH 0x64` |
| `1002a859` | `52` | `PUSH EDX` |
| `1002a85a` | `50` | `PUSH EAX` |
| `1002a85b` | `e8 d0 07 00 00` | `CALL 0x1002b030` |
| `1002a860` | `04 30` | `ADD AL,0x30` |
| `1002a862` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a864` | `89 55 f0` | `MOV dword ptr [EBP + -0x10],EDX` |
| `1002a867` | `46` | `INC ESI` |
| `1002a868` | `8b c1` | `MOV EAX,ECX` |
| `1002a86a` | `8b d3` | `MOV EDX,EBX` |
| `1002a86c` | `3b f7` | `CMP ESI,EDI` |
| `1002a86e` | `75 0b` | `JNZ 0x1002a87b` |
| `1002a870` | `85 d2` | `TEST EDX,EDX` |
| `1002a872` | `7c 1f` | `JL 0x1002a893` |
| `1002a874` | `7f 05` | `JG 0x1002a87b` |
| `1002a876` | `83 f8 0a` | `CMP EAX,0xa` |
| `1002a879` | `72 18` | `JC 0x1002a893` |
| `1002a87b` | `6a 00` | `PUSH 0x0` |
| `1002a87d` | `6a 0a` | `PUSH 0xa` |
| `1002a87f` | `52` | `PUSH EDX` |
| `1002a880` | `50` | `PUSH EAX` |
| `1002a881` | `e8 aa 07 00 00` | `CALL 0x1002b030` |
| `1002a886` | `04 30` | `ADD AL,0x30` |
| `1002a888` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a88a` | `89 55 f0` | `MOV dword ptr [EBP + -0x10],EDX` |
| `1002a88d` | `46` | `INC ESI` |
| `1002a88e` | `8b c1` | `MOV EAX,ECX` |
| `1002a890` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1002a893` | `04 30` | `ADD AL,0x30` |
| `1002a895` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a897` | `c6 46 01 00` | `MOV byte ptr [ESI + 0x1],0x0` |
| `1002a89b` | `80 7d e8 00` | `CMP byte ptr [EBP + -0x18],0x0` |
| `1002a89f` | `74 07` | `JZ 0x1002a8a8` |
| `1002a8a1` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002a8a4` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a8a8` | `33 c0` | `XOR EAX,EAX` |
| `1002a8aa` | `5b` | `POP EBX` |
| `1002a8ab` | `5f` | `POP EDI` |
| `1002a8ac` | `5e` | `POP ESI` |
| `1002a8ad` | `c9` | `LEAVE` |
| `1002a8ae` | `c3` | `RET` |
