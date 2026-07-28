# 10016734 `___sbh_resize_block`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016734 |
| `name` | ___sbh_resize_block |
| `namespace` | Global |
| `signature` | undefined ___sbh_resize_block(void) |
| `size_bytes` | 737 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_resize_block |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_resize_block
   
   Library: Visual Studio 2008 Release */

undefined4 ___sbh_resize_block(uint *param_1,int param_2,int param_3)

{
  char *pcVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_c;
  
  uVar8 = param_1[4];
  uVar10 = param_2 - param_1[3] >> 0xf;
  iVar5 = uVar10 * 0x204 + 0x144 + uVar8;
  uVar12 = param_3 + 0x17U & 0xfffffff0;
  param_3 = *(int *)(param_2 + -4) + -1;
  puVar9 = (uint *)(*(int *)(param_2 + -4) + -5 + param_2);
  uVar13 = *puVar9;
  if (param_3 < (int)uVar12) {
    if (((uVar13 & 1) != 0) || ((int)(uVar13 + param_3) < (int)uVar12)) {
      return 0;
    }
    local_c = ((int)uVar13 >> 4) - 1;
    if (0x3f < local_c) {
      local_c = 0x3f;
    }
    if (puVar9[1] == puVar9[2]) {
      if (local_c < 0x20) {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c & 0x1f));
        puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          *param_1 = *param_1 & uVar11;
        }
      }
      else {
        pcVar1 = (char *)(local_c + 4 + uVar8);
        uVar11 = ~(0x80000000U >> ((byte)local_c - 0x20 & 0x1f));
        puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        *puVar2 = *puVar2 & uVar11;
        *pcVar1 = *pcVar1 + -1;
        if (*pcVar1 == '\0') {
          param_1[1] = param_1[1] & uVar11;
        }
      }
    }
    *(uint *)(puVar9[2] + 4) = puVar9[1];
    *(uint *)(puVar9[1] + 8) = puVar9[2];
    iVar6 = uVar13 + (param_3 - uVar12);
    if (0 < iVar6) {
      uVar13 = (iVar6 >> 4) - 1;
      iVar3 = param_2 + -4 + uVar12;
      if (0x3f < uVar13) {
        uVar13 = 0x3f;
      }
      iVar5 = iVar5 + uVar13 * 8;
      *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar5 + 4);
      *(int *)(iVar3 + 8) = iVar5;
      *(int *)(iVar5 + 4) = iVar3;
      *(int *)(*(int *)(iVar3 + 4) + 8) = iVar3;
      if (*(int *)(iVar3 + 4) == *(int *)(iVar3 + 8)) {
        cVar7 = *(char *)(uVar13 + 4 + uVar8);
        *(char *)(uVar13 + 4 + uVar8) = cVar7 + '\x01';
        if (uVar13 < 0x20) {
          if (cVar7 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> ((byte)uVar13 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
        }
        else {
          if (cVar7 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar13 - 0x20 & 0x1f);
          }
          puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          uVar13 = uVar13 - 0x20;
        }
        *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar13 & 0x1f);
      }
      piVar4 = (int *)(param_2 + -4 + uVar12);
      *piVar4 = iVar6;
      *(int *)(iVar6 + -4 + (int)piVar4) = iVar6;
    }
    *(uint *)(param_2 + -4) = uVar12 + 1;
    *(uint *)(param_2 + -8 + uVar12) = uVar12 + 1;
  }
  else if ((int)uVar12 < param_3) {
    param_3 = param_3 - uVar12;
    *(uint *)(param_2 + -4) = uVar12 + 1;
    piVar4 = (int *)(param_2 + -4 + uVar12);
    uVar11 = (param_3 >> 4) - 1;
    piVar4[-1] = uVar12 + 1;
    if (0x3f < uVar11) {
      uVar11 = 0x3f;
    }
    if ((uVar13 & 1) == 0) {
      uVar12 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar12) {
        uVar12 = 0x3f;
      }
      if (puVar9[1] == puVar9[2]) {
        if (uVar12 < 0x20) {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            *param_1 = *param_1 & uVar12;
          }
        }
        else {
          pcVar1 = (char *)(uVar12 + 4 + uVar8);
          uVar12 = ~(0x80000000U >> ((byte)uVar12 - 0x20 & 0x1f));
          puVar2 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
          *puVar2 = *puVar2 & uVar12;
          *pcVar1 = *pcVar1 + -1;
          if (*pcVar1 == '\0') {
            param_1[1] = param_1[1] & uVar12;
          }
        }
      }
      *(uint *)(puVar9[2] + 4) = puVar9[1];
      *(uint *)(puVar9[1] + 8) = puVar9[2];
      param_3 = param_3 + uVar13;
      uVar11 = (param_3 >> 4) - 1;
      if (0x3f < uVar11) {
        uVar11 = 0x3f;
      }
    }
    iVar5 = iVar5 + uVar11 * 8;
    iVar6 = *(int *)(iVar5 + 4);
    piVar4[2] = iVar5;
    piVar4[1] = iVar6;
    *(int **)(iVar5 + 4) = piVar4;
    *(int **)(piVar4[1] + 8) = piVar4;
    if (piVar4[1] == piVar4[2]) {
      cVar7 = *(char *)(uVar11 + 4 + uVar8);
      *(char *)(uVar11 + 4 + uVar8) = cVar7 + '\x01';
      if (uVar11 < 0x20) {
        if (cVar7 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> ((byte)uVar11 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0x44 + uVar10 * 4);
      }
      else {
        if (cVar7 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> ((byte)uVar11 - 0x20 & 0x1f);
        }
        puVar9 = (uint *)(uVar8 + 0xc4 + uVar10 * 4);
        uVar11 = uVar11 - 0x20;
      }
      *puVar9 = *puVar9 | 0x80000000U >> ((byte)uVar11 & 0x1f);
    }
    *piVar4 = param_3;
    *(int *)(param_3 + -4 + (int)piVar4) = param_3;
  }
  return 1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10012b27` | _realloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016734` | `8b ff` | `MOV EDI,EDI` |
| `10016736` | `55` | `PUSH EBP` |
| `10016737` | `8b ec` | `MOV EBP,ESP` |
| `10016739` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001673c` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001673f` | `8b 41 10` | `MOV EAX,dword ptr [ECX + 0x10]` |
| `10016742` | `53` | `PUSH EBX` |
| `10016743` | `56` | `PUSH ESI` |
| `10016744` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `10016747` | `57` | `PUSH EDI` |
| `10016748` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001674b` | `8b d7` | `MOV EDX,EDI` |
| `1001674d` | `2b 51 0c` | `SUB EDX,dword ptr [ECX + 0xc]` |
| `10016750` | `83 c6 17` | `ADD ESI,0x17` |
| `10016753` | `c1 ea 0f` | `SHR EDX,0xf` |
| `10016756` | `8b ca` | `MOV ECX,EDX` |
| `10016758` | `69 c9 04 02 00 00` | `IMUL ECX,ECX,0x204` |
| `1001675e` | `8d 8c 01 44 01 00 00` | `LEA ECX,[ECX + EAX*0x1 + 0x144]` |
| `10016765` | `89 4d f4` | `MOV dword ptr [EBP + -0xc],ECX` |
| `10016768` | `8b 4f fc` | `MOV ECX,dword ptr [EDI + -0x4]` |
| `1001676b` | `83 e6 f0` | `AND ESI,0xfffffff0` |
| `1001676e` | `49` | `DEC ECX` |
| `1001676f` | `3b f1` | `CMP ESI,ECX` |
| `10016771` | `8d 7c 39 fc` | `LEA EDI,[ECX + EDI*0x1 + -0x4]` |
| `10016775` | `8b 1f` | `MOV EBX,dword ptr [EDI]` |
| `10016777` | `89 4d 10` | `MOV dword ptr [EBP + 0x10],ECX` |
| `1001677a` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001677d` | `0f 8e 55 01 00 00` | `JLE 0x100168d8` |
| `10016783` | `f6 c3 01` | `TEST BL,0x1` |
| `10016786` | `0f 85 45 01 00 00` | `JNZ 0x100168d1` |
| `1001678c` | `03 d9` | `ADD EBX,ECX` |
| `1001678e` | `3b f3` | `CMP ESI,EBX` |
| `10016790` | `0f 8f 3b 01 00 00` | `JG 0x100168d1` |
| `10016796` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016799` | `c1 f9 04` | `SAR ECX,0x4` |
| `1001679c` | `49` | `DEC ECX` |
| `1001679d` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100167a0` | `83 f9 3f` | `CMP ECX,0x3f` |
| `100167a3` | `76 06` | `JBE 0x100167ab` |
| `100167a5` | `6a 3f` | `PUSH 0x3f` |
| `100167a7` | `59` | `POP ECX` |
| `100167a8` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100167ab` | `8b 5f 04` | `MOV EBX,dword ptr [EDI + 0x4]` |
| `100167ae` | `3b 5f 08` | `CMP EBX,dword ptr [EDI + 0x8]` |
| `100167b1` | `75 43` | `JNZ 0x100167f6` |
| `100167b3` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `100167b8` | `83 f9 20` | `CMP ECX,0x20` |
| `100167bb` | `73 1a` | `JNC 0x100167d7` |
| `100167bd` | `d3 eb` | `SHR EBX,CL` |
| `100167bf` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `100167c2` | `8d 4c 01 04` | `LEA ECX,[ECX + EAX*0x1 + 0x4]` |
| `100167c6` | `f7 d3` | `NOT EBX` |
| `100167c8` | `21 5c 90 44` | `AND dword ptr [EAX + EDX*0x4 + 0x44],EBX` |
| `100167cc` | `fe 09` | `DEC byte ptr [ECX]` |
| `100167ce` | `75 26` | `JNZ 0x100167f6` |
| `100167d0` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100167d3` | `21 19` | `AND dword ptr [ECX],EBX` |
| `100167d5` | `eb 1f` | `JMP 0x100167f6` |
| `100167d7` | `83 c1 e0` | `ADD ECX,-0x20` |
| `100167da` | `d3 eb` | `SHR EBX,CL` |
| `100167dc` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `100167df` | `8d 4c 01 04` | `LEA ECX,[ECX + EAX*0x1 + 0x4]` |
| `100167e3` | `f7 d3` | `NOT EBX` |
| `100167e5` | `21 9c 90 c4 00 00 00` | `AND dword ptr [EAX + EDX*0x4 + 0xc4],EBX` |
| `100167ec` | `fe 09` | `DEC byte ptr [ECX]` |
| `100167ee` | `75 06` | `JNZ 0x100167f6` |
| `100167f0` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100167f3` | `21 59 04` | `AND dword ptr [ECX + 0x4],EBX` |
| `100167f6` | `8b 4f 08` | `MOV ECX,dword ptr [EDI + 0x8]` |
| `100167f9` | `8b 5f 04` | `MOV EBX,dword ptr [EDI + 0x4]` |
| `100167fc` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `100167ff` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `10016802` | `8b 7f 08` | `MOV EDI,dword ptr [EDI + 0x8]` |
| `10016805` | `89 79 08` | `MOV dword ptr [ECX + 0x8],EDI` |
| `10016808` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001680b` | `2b ce` | `SUB ECX,ESI` |
| `1001680d` | `01 4d fc` | `ADD dword ptr [EBP + -0x4],ECX` |
| `10016810` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `10016814` | `0f 8e a5 00 00 00` | `JLE 0x100168bf` |
| `1001681a` | `8b 7d fc` | `MOV EDI,dword ptr [EBP + -0x4]` |
| `1001681d` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10016820` | `c1 ff 04` | `SAR EDI,0x4` |
| `10016823` | `4f` | `DEC EDI` |
| `10016824` | `8d 4c 31 fc` | `LEA ECX,[ECX + ESI*0x1 + -0x4]` |
| `10016828` | `83 ff 3f` | `CMP EDI,0x3f` |
| `1001682b` | `76 03` | `JBE 0x10016830` |
| `1001682d` | `6a 3f` | `PUSH 0x3f` |
| `1001682f` | `5f` | `POP EDI` |
| `10016830` | `8b 5d f4` | `MOV EBX,dword ptr [EBP + -0xc]` |
| `10016833` | `8d 1c fb` | `LEA EBX,[EBX + EDI*0x8]` |
| `10016836` | `89 5d 10` | `MOV dword ptr [EBP + 0x10],EBX` |
| `10016839` | `8b 5b 04` | `MOV EBX,dword ptr [EBX + 0x4]` |
| `1001683c` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `1001683f` | `8b 5d 10` | `MOV EBX,dword ptr [EBP + 0x10]` |
| `10016842` | `89 59 08` | `MOV dword ptr [ECX + 0x8],EBX` |
| `10016845` | `89 4b 04` | `MOV dword ptr [EBX + 0x4],ECX` |
| `10016848` | `8b 59 04` | `MOV EBX,dword ptr [ECX + 0x4]` |
| `1001684b` | `89 4b 08` | `MOV dword ptr [EBX + 0x8],ECX` |
| `1001684e` | `8b 59 04` | `MOV EBX,dword ptr [ECX + 0x4]` |
| `10016851` | `3b 59 08` | `CMP EBX,dword ptr [ECX + 0x8]` |
| `10016854` | `75 57` | `JNZ 0x100168ad` |
| `10016856` | `8a 4c 07 04` | `MOV CL,byte ptr [EDI + EAX*0x1 + 0x4]` |
| `1001685a` | `88 4d 13` | `MOV byte ptr [EBP + 0x13],CL` |
| `1001685d` | `fe c1` | `INC CL` |
| `1001685f` | `88 4c 07 04` | `MOV byte ptr [EDI + EAX*0x1 + 0x4],CL` |
| `10016863` | `83 ff 20` | `CMP EDI,0x20` |
| `10016866` | `73 1c` | `JNC 0x10016884` |
| `10016868` | `80 7d 13 00` | `CMP byte ptr [EBP + 0x13],0x0` |
| `1001686c` | `75 0e` | `JNZ 0x1001687c` |
| `1001686e` | `8b cf` | `MOV ECX,EDI` |
| `10016870` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `10016875` | `d3 eb` | `SHR EBX,CL` |
| `10016877` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001687a` | `09 19` | `OR dword ptr [ECX],EBX` |
| `1001687c` | `8d 44 90 44` | `LEA EAX,[EAX + EDX*0x4 + 0x44]` |
| `10016880` | `8b cf` | `MOV ECX,EDI` |
| `10016882` | `eb 20` | `JMP 0x100168a4` |
| `10016884` | `80 7d 13 00` | `CMP byte ptr [EBP + 0x13],0x0` |
| `10016888` | `75 10` | `JNZ 0x1001689a` |
| `1001688a` | `8d 4f e0` | `LEA ECX,[EDI + -0x20]` |
| `1001688d` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `10016892` | `d3 eb` | `SHR EBX,CL` |
| `10016894` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016897` | `09 59 04` | `OR dword ptr [ECX + 0x4],EBX` |
| `1001689a` | `8d 84 90 c4 00 00 00` | `LEA EAX,[EAX + EDX*0x4 + 0xc4]` |
| `100168a1` | `8d 4f e0` | `LEA ECX,[EDI + -0x20]` |
| `100168a4` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `100168a9` | `d3 ea` | `SHR EDX,CL` |
| `100168ab` | `09 10` | `OR dword ptr [EAX],EDX` |
| `100168ad` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `100168b0` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `100168b3` | `8d 44 32 fc` | `LEA EAX,[EDX + ESI*0x1 + -0x4]` |
| `100168b7` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `100168b9` | `89 4c 01 fc` | `MOV dword ptr [ECX + EAX*0x1 + -0x4],ECX` |
| `100168bd` | `eb 03` | `JMP 0x100168c2` |
| `100168bf` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `100168c2` | `8d 46 01` | `LEA EAX,[ESI + 0x1]` |
| `100168c5` | `89 42 fc` | `MOV dword ptr [EDX + -0x4],EAX` |
| `100168c8` | `89 44 32 f8` | `MOV dword ptr [EDX + ESI*0x1 + -0x8],EAX` |
| `100168cc` | `e9 3c 01 00 00` | `JMP 0x10016a0d` |
| `100168d1` | `33 c0` | `XOR EAX,EAX` |
| `100168d3` | `e9 38 01 00 00` | `JMP 0x10016a10` |
| `100168d8` | `0f 8d 2f 01 00 00` | `JGE 0x10016a0d` |
| `100168de` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `100168e1` | `29 75 10` | `SUB dword ptr [EBP + 0x10],ESI` |
| `100168e4` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `100168e7` | `89 4b fc` | `MOV dword ptr [EBX + -0x4],ECX` |
| `100168ea` | `8d 5c 33 fc` | `LEA EBX,[EBX + ESI*0x1 + -0x4]` |
| `100168ee` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `100168f1` | `c1 fe 04` | `SAR ESI,0x4` |
| `100168f4` | `4e` | `DEC ESI` |
| `100168f5` | `89 5d 0c` | `MOV dword ptr [EBP + 0xc],EBX` |
| `100168f8` | `89 4b fc` | `MOV dword ptr [EBX + -0x4],ECX` |
| `100168fb` | `83 fe 3f` | `CMP ESI,0x3f` |
| `100168fe` | `76 03` | `JBE 0x10016903` |
| `10016900` | `6a 3f` | `PUSH 0x3f` |
| `10016902` | `5e` | `POP ESI` |
| `10016903` | `f6 45 fc 01` | `TEST byte ptr [EBP + -0x4],0x1` |
| `10016907` | `0f 85 80 00 00 00` | `JNZ 0x1001698d` |
| `1001690d` | `8b 75 fc` | `MOV ESI,dword ptr [EBP + -0x4]` |
| `10016910` | `c1 fe 04` | `SAR ESI,0x4` |
| `10016913` | `4e` | `DEC ESI` |
| `10016914` | `83 fe 3f` | `CMP ESI,0x3f` |
| `10016917` | `76 03` | `JBE 0x1001691c` |
| `10016919` | `6a 3f` | `PUSH 0x3f` |
| `1001691b` | `5e` | `POP ESI` |
| `1001691c` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `1001691f` | `3b 4f 08` | `CMP ECX,dword ptr [EDI + 0x8]` |
| `10016922` | `75 42` | `JNZ 0x10016966` |
| `10016924` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `10016929` | `83 fe 20` | `CMP ESI,0x20` |
| `1001692c` | `73 19` | `JNC 0x10016947` |
| `1001692e` | `8b ce` | `MOV ECX,ESI` |
| `10016930` | `d3 eb` | `SHR EBX,CL` |
| `10016932` | `8d 74 06 04` | `LEA ESI,[ESI + EAX*0x1 + 0x4]` |
| `10016936` | `f7 d3` | `NOT EBX` |
| `10016938` | `21 5c 90 44` | `AND dword ptr [EAX + EDX*0x4 + 0x44],EBX` |
| `1001693c` | `fe 0e` | `DEC byte ptr [ESI]` |
| `1001693e` | `75 23` | `JNZ 0x10016963` |
| `10016940` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016943` | `21 19` | `AND dword ptr [ECX],EBX` |
| `10016945` | `eb 1c` | `JMP 0x10016963` |
| `10016947` | `8d 4e e0` | `LEA ECX,[ESI + -0x20]` |
| `1001694a` | `d3 eb` | `SHR EBX,CL` |
| `1001694c` | `8d 4c 06 04` | `LEA ECX,[ESI + EAX*0x1 + 0x4]` |
| `10016950` | `f7 d3` | `NOT EBX` |
| `10016952` | `21 9c 90 c4 00 00 00` | `AND dword ptr [EAX + EDX*0x4 + 0xc4],EBX` |
| `10016959` | `fe 09` | `DEC byte ptr [ECX]` |
| `1001695b` | `75 06` | `JNZ 0x10016963` |
| `1001695d` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016960` | `21 59 04` | `AND dword ptr [ECX + 0x4],EBX` |
| `10016963` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10016966` | `8b 4f 08` | `MOV ECX,dword ptr [EDI + 0x8]` |
| `10016969` | `8b 77 04` | `MOV ESI,dword ptr [EDI + 0x4]` |
| `1001696c` | `89 71 04` | `MOV dword ptr [ECX + 0x4],ESI` |
| `1001696f` | `8b 77 08` | `MOV ESI,dword ptr [EDI + 0x8]` |
| `10016972` | `8b 4f 04` | `MOV ECX,dword ptr [EDI + 0x4]` |
| `10016975` | `89 71 08` | `MOV dword ptr [ECX + 0x8],ESI` |
| `10016978` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `1001697b` | `03 75 fc` | `ADD ESI,dword ptr [EBP + -0x4]` |
| `1001697e` | `89 75 10` | `MOV dword ptr [EBP + 0x10],ESI` |
| `10016981` | `c1 fe 04` | `SAR ESI,0x4` |
| `10016984` | `4e` | `DEC ESI` |
| `10016985` | `83 fe 3f` | `CMP ESI,0x3f` |
| `10016988` | `76 03` | `JBE 0x1001698d` |
| `1001698a` | `6a 3f` | `PUSH 0x3f` |
| `1001698c` | `5e` | `POP ESI` |
| `1001698d` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10016990` | `8d 0c f1` | `LEA ECX,[ECX + ESI*0x8]` |
| `10016993` | `8b 79 04` | `MOV EDI,dword ptr [ECX + 0x4]` |
| `10016996` | `89 4b 08` | `MOV dword ptr [EBX + 0x8],ECX` |
| `10016999` | `89 7b 04` | `MOV dword ptr [EBX + 0x4],EDI` |
| `1001699c` | `89 59 04` | `MOV dword ptr [ECX + 0x4],EBX` |
| `1001699f` | `8b 4b 04` | `MOV ECX,dword ptr [EBX + 0x4]` |
| `100169a2` | `89 59 08` | `MOV dword ptr [ECX + 0x8],EBX` |
| `100169a5` | `8b 4b 04` | `MOV ECX,dword ptr [EBX + 0x4]` |
| `100169a8` | `3b 4b 08` | `CMP ECX,dword ptr [EBX + 0x8]` |
| `100169ab` | `75 57` | `JNZ 0x10016a04` |
| `100169ad` | `8a 4c 06 04` | `MOV CL,byte ptr [ESI + EAX*0x1 + 0x4]` |
| `100169b1` | `88 4d 0f` | `MOV byte ptr [EBP + 0xf],CL` |
| `100169b4` | `fe c1` | `INC CL` |
| `100169b6` | `88 4c 06 04` | `MOV byte ptr [ESI + EAX*0x1 + 0x4],CL` |
| `100169ba` | `83 fe 20` | `CMP ESI,0x20` |
| `100169bd` | `73 1c` | `JNC 0x100169db` |
| `100169bf` | `80 7d 0f 00` | `CMP byte ptr [EBP + 0xf],0x0` |
| `100169c3` | `75 0e` | `JNZ 0x100169d3` |
| `100169c5` | `8b ce` | `MOV ECX,ESI` |
| `100169c7` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `100169cc` | `d3 ef` | `SHR EDI,CL` |
| `100169ce` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100169d1` | `09 39` | `OR dword ptr [ECX],EDI` |
| `100169d3` | `8d 44 90 44` | `LEA EAX,[EAX + EDX*0x4 + 0x44]` |
| `100169d7` | `8b ce` | `MOV ECX,ESI` |
| `100169d9` | `eb 20` | `JMP 0x100169fb` |
| `100169db` | `80 7d 0f 00` | `CMP byte ptr [EBP + 0xf],0x0` |
| `100169df` | `75 10` | `JNZ 0x100169f1` |
| `100169e1` | `8d 4e e0` | `LEA ECX,[ESI + -0x20]` |
| `100169e4` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `100169e9` | `d3 ef` | `SHR EDI,CL` |
| `100169eb` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100169ee` | `09 79 04` | `OR dword ptr [ECX + 0x4],EDI` |
| `100169f1` | `8d 84 90 c4 00 00 00` | `LEA EAX,[EAX + EDX*0x4 + 0xc4]` |
| `100169f8` | `8d 4e e0` | `LEA ECX,[ESI + -0x20]` |
| `100169fb` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `10016a00` | `d3 ea` | `SHR EDX,CL` |
| `10016a02` | `09 10` | `OR dword ptr [EAX],EDX` |
| `10016a04` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10016a07` | `89 03` | `MOV dword ptr [EBX],EAX` |
| `10016a09` | `89 44 18 fc` | `MOV dword ptr [EAX + EBX*0x1 + -0x4],EAX` |
| `10016a0d` | `33 c0` | `XOR EAX,EAX` |
| `10016a0f` | `40` | `INC EAX` |
| `10016a10` | `5f` | `POP EDI` |
| `10016a11` | `5e` | `POP ESI` |
| `10016a12` | `5b` | `POP EBX` |
| `10016a13` | `c9` | `LEAVE` |
| `10016a14` | `c3` | `RET` |
