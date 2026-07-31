# 10016a15 `___sbh_alloc_block`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016a15 |
| `name` | ___sbh_alloc_block |
| `namespace` | Global |
| `signature` | undefined ___sbh_alloc_block(void) |
| `size_bytes` | 741 |
| `stack_frame_size` | 28 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_alloc_block |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_alloc_block
   
   Library: Visual Studio 2008 Release */

int * ___sbh_alloc_block(uint *param_1)

{
  int *piVar1;
  char *pcVar2;
  int *piVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  byte bVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  uint local_c;
  int local_8;
  
  puVar10 = DAT_1343a66c + DAT_1343a668 * 5;
  uVar8 = (int)param_1 + 0x17U & 0xfffffff0;
  iVar9 = ((int)((int)param_1 + 0x17U) >> 4) + -1;
  bVar7 = (byte)iVar9;
  param_1 = DAT_1343a674;
  if (iVar9 < 0x20) {
    uVar16 = 0xffffffff >> (bVar7 & 0x1f);
    local_c = 0xffffffff;
  }
  else {
    uVar16 = 0;
    local_c = 0xffffffff >> (bVar7 - 0x20 & 0x1f);
  }
  for (; (param_1 < puVar10 && ((param_1[1] & local_c) == 0 && (*param_1 & uVar16) == 0));
      param_1 = param_1 + 5) {
  }
  puVar14 = DAT_1343a66c;
  if (param_1 == puVar10) {
    for (; (puVar14 < DAT_1343a674 && ((puVar14[1] & local_c) == 0 && (*puVar14 & uVar16) == 0));
        puVar14 = puVar14 + 5) {
    }
    param_1 = puVar14;
    if (puVar14 == DAT_1343a674) {
      for (; (puVar14 < puVar10 && (puVar14[2] == 0)); puVar14 = puVar14 + 5) {
      }
      puVar15 = DAT_1343a66c;
      param_1 = puVar14;
      if (puVar14 == puVar10) {
        for (; (puVar15 < DAT_1343a674 && (puVar15[2] == 0)); puVar15 = puVar15 + 5) {
        }
        param_1 = puVar15;
        if ((puVar15 == DAT_1343a674) &&
           (param_1 = (uint *)___sbh_alloc_new_region(), param_1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      uVar6 = ___sbh_alloc_new_group(param_1);
      *(undefined4 *)param_1[4] = uVar6;
      if (*(int *)param_1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  piVar5 = (int *)param_1[4];
  local_8 = *piVar5;
  if ((local_8 == -1) ||
     ((piVar5[local_8 + 0x31] & local_c) == 0 && (piVar5[local_8 + 0x11] & uVar16) == 0)) {
    local_8 = 0;
    puVar10 = (uint *)(piVar5 + 0x11);
    uVar12 = piVar5[0x31];
    while ((uVar12 & local_c) == 0 && (*puVar10 & uVar16) == 0) {
      local_8 = local_8 + 1;
      puVar14 = puVar10 + 0x21;
      puVar10 = puVar10 + 1;
      uVar12 = *puVar14;
    }
  }
  piVar3 = piVar5 + local_8 * 0x81 + 0x51;
  iVar9 = 0;
  uVar16 = piVar5[local_8 + 0x11] & uVar16;
  if (uVar16 == 0) {
    uVar16 = piVar5[local_8 + 0x31] & local_c;
    iVar9 = 0x20;
  }
  for (; -1 < (int)uVar16; uVar16 = uVar16 * 2) {
    iVar9 = iVar9 + 1;
  }
  piVar13 = (int *)piVar3[iVar9 * 2 + 1];
  iVar11 = *piVar13 - uVar8;
  iVar17 = (iVar11 >> 4) + -1;
  if (0x3f < iVar17) {
    iVar17 = 0x3f;
  }
  DAT_1343a674 = param_1;
  if (iVar17 != iVar9) {
    if (piVar13[1] == piVar13[2]) {
      if (iVar9 < 0x20) {
        pcVar2 = (char *)((int)piVar5 + iVar9 + 4);
        uVar16 = ~(0x80000000U >> ((byte)iVar9 & 0x1f));
        piVar5[local_8 + 0x11] = uVar16 & piVar5[local_8 + 0x11];
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          *param_1 = *param_1 & uVar16;
        }
      }
      else {
        pcVar2 = (char *)((int)piVar5 + iVar9 + 4);
        uVar16 = ~(0x80000000U >> ((byte)iVar9 - 0x20 & 0x1f));
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] & uVar16;
        *pcVar2 = *pcVar2 + -1;
        if (*pcVar2 == '\0') {
          param_1[1] = param_1[1] & uVar16;
        }
      }
    }
    *(int *)(piVar13[2] + 4) = piVar13[1];
    *(int *)(piVar13[1] + 8) = piVar13[2];
    if (iVar11 == 0) goto LAB_10016cb7;
    piVar1 = piVar3 + iVar17 * 2;
    iVar9 = piVar1[1];
    piVar13[2] = (int)piVar1;
    piVar13[1] = iVar9;
    piVar1[1] = (int)piVar13;
    *(int **)(piVar13[1] + 8) = piVar13;
    if (piVar13[1] == piVar13[2]) {
      cVar4 = *(char *)(iVar17 + 4 + (int)piVar5);
      *(char *)(iVar17 + 4 + (int)piVar5) = cVar4 + '\x01';
      bVar7 = (byte)iVar17;
      if (iVar17 < 0x20) {
        if (cVar4 == '\0') {
          *param_1 = *param_1 | 0x80000000U >> (bVar7 & 0x1f);
        }
        piVar5[local_8 + 0x11] = piVar5[local_8 + 0x11] | 0x80000000U >> (bVar7 & 0x1f);
      }
      else {
        if (cVar4 == '\0') {
          param_1[1] = param_1[1] | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
        }
        piVar5[local_8 + 0x31] = piVar5[local_8 + 0x31] | 0x80000000U >> (bVar7 - 0x20 & 0x1f);
      }
    }
  }
  if (iVar11 != 0) {
    *piVar13 = iVar11;
    *(int *)(iVar11 + -4 + (int)piVar13) = iVar11;
  }
LAB_10016cb7:
  piVar13 = (int *)((int)piVar13 + iVar11);
  *piVar13 = uVar8 + 1;
  *(uint *)((int)piVar13 + (uVar8 - 4)) = uVar8 + 1;
  iVar9 = *piVar3;
  *piVar3 = iVar9 + 1;
  if (((iVar9 == 0) && (param_1 == DAT_10038f00)) && (local_8 == DAT_1343a67c)) {
    DAT_10038f00 = (uint *)0x0;
  }
  *piVar5 = local_8;
  return piVar13 + 1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10016ad7` | `1001657c` | `UNCONDITIONAL_CALL` | ___sbh_alloc_new_region | `1001657c` |
| `10016aed` | `1001662c` | `UNCONDITIONAL_CALL` | ___sbh_alloc_new_group | `1001662c` |

## Callers

| From | Function |
| --- | --- |
| `100112f7` | _V6_HeapAlloc |
| `1001ab88` | __calloc_impl |
| `10012b39` | _realloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016a1d` | `1343a668` | `READ` | DAT_1343a668 |
| `10016a28` | `1343a66c` | `READ` | DAT_1343a66c |
| `10016a5b` | `1343a674` | `READ` | DAT_1343a674 |
| `10016a81` | `1343a66c` | `READ` | DAT_1343a66c |
| `10016abb` | `1343a66c` | `READ` | DAT_1343a66c |
| `10016b00` | `1343a674` | `WRITE` | DAT_1343a674 |
| `10016cd3` | `10038f00` | `READ` | DAT_10038f00 |
| `10016cde` | `1343a67c` | `READ` | DAT_1343a67c |
| `10016ce6` | `10038f00` | `READ_WRITE` | DAT_10038f00 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016a15` | `8b ff` | `MOV EDI,EDI` |
| `10016a17` | `55` | `PUSH EBP` |
| `10016a18` | `8b ec` | `MOV EBP,ESP` |
| `10016a1a` | `83 ec 14` | `SUB ESP,0x14` |
| `10016a1d` | `a1 68 a6 43 13` | `MOV EAX,[0x1343a668]` |
| `10016a22` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016a25` | `6b c0 14` | `IMUL EAX,EAX,0x14` |
| `10016a28` | `03 05 6c a6 43 13` | `ADD EAX,dword ptr [0x1343a66c]` |
| `10016a2e` | `83 c1 17` | `ADD ECX,0x17` |
| `10016a31` | `83 e1 f0` | `AND ECX,0xfffffff0` |
| `10016a34` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `10016a37` | `c1 f9 04` | `SAR ECX,0x4` |
| `10016a3a` | `53` | `PUSH EBX` |
| `10016a3b` | `49` | `DEC ECX` |
| `10016a3c` | `83 f9 20` | `CMP ECX,0x20` |
| `10016a3f` | `56` | `PUSH ESI` |
| `10016a40` | `57` | `PUSH EDI` |
| `10016a41` | `7d 0b` | `JGE 0x10016a4e` |
| `10016a43` | `83 ce ff` | `OR ESI,0xffffffff` |
| `10016a46` | `d3 ee` | `SHR ESI,CL` |
| `10016a48` | `83 4d f8 ff` | `OR dword ptr [EBP + -0x8],0xffffffff` |
| `10016a4c` | `eb 0d` | `JMP 0x10016a5b` |
| `10016a4e` | `83 c1 e0` | `ADD ECX,-0x20` |
| `10016a51` | `83 ca ff` | `OR EDX,0xffffffff` |
| `10016a54` | `33 f6` | `XOR ESI,ESI` |
| `10016a56` | `d3 ea` | `SHR EDX,CL` |
| `10016a58` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `10016a5b` | `8b 0d 74 a6 43 13` | `MOV ECX,dword ptr [0x1343a674]` |
| `10016a61` | `8b d9` | `MOV EBX,ECX` |
| `10016a63` | `eb 11` | `JMP 0x10016a76` |
| `10016a65` | `8b 53 04` | `MOV EDX,dword ptr [EBX + 0x4]` |
| `10016a68` | `8b 3b` | `MOV EDI,dword ptr [EBX]` |
| `10016a6a` | `23 55 f8` | `AND EDX,dword ptr [EBP + -0x8]` |
| `10016a6d` | `23 fe` | `AND EDI,ESI` |
| `10016a6f` | `0b d7` | `OR EDX,EDI` |
| `10016a71` | `75 0a` | `JNZ 0x10016a7d` |
| `10016a73` | `83 c3 14` | `ADD EBX,0x14` |
| `10016a76` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `10016a79` | `3b d8` | `CMP EBX,EAX` |
| `10016a7b` | `72 e8` | `JC 0x10016a65` |
| `10016a7d` | `3b d8` | `CMP EBX,EAX` |
| `10016a7f` | `75 7f` | `JNZ 0x10016b00` |
| `10016a81` | `8b 1d 6c a6 43 13` | `MOV EBX,dword ptr [0x1343a66c]` |
| `10016a87` | `eb 11` | `JMP 0x10016a9a` |
| `10016a89` | `8b 53 04` | `MOV EDX,dword ptr [EBX + 0x4]` |
| `10016a8c` | `8b 3b` | `MOV EDI,dword ptr [EBX]` |
| `10016a8e` | `23 55 f8` | `AND EDX,dword ptr [EBP + -0x8]` |
| `10016a91` | `23 fe` | `AND EDI,ESI` |
| `10016a93` | `0b d7` | `OR EDX,EDI` |
| `10016a95` | `75 0a` | `JNZ 0x10016aa1` |
| `10016a97` | `83 c3 14` | `ADD EBX,0x14` |
| `10016a9a` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `10016a9d` | `3b d9` | `CMP EBX,ECX` |
| `10016a9f` | `72 e8` | `JC 0x10016a89` |
| `10016aa1` | `3b d9` | `CMP EBX,ECX` |
| `10016aa3` | `75 5b` | `JNZ 0x10016b00` |
| `10016aa5` | `eb 0c` | `JMP 0x10016ab3` |
| `10016aa7` | `83 7b 08 00` | `CMP dword ptr [EBX + 0x8],0x0` |
| `10016aab` | `75 0a` | `JNZ 0x10016ab7` |
| `10016aad` | `83 c3 14` | `ADD EBX,0x14` |
| `10016ab0` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `10016ab3` | `3b d8` | `CMP EBX,EAX` |
| `10016ab5` | `72 f0` | `JC 0x10016aa7` |
| `10016ab7` | `3b d8` | `CMP EBX,EAX` |
| `10016ab9` | `75 31` | `JNZ 0x10016aec` |
| `10016abb` | `8b 1d 6c a6 43 13` | `MOV EBX,dword ptr [0x1343a66c]` |
| `10016ac1` | `eb 09` | `JMP 0x10016acc` |
| `10016ac3` | `83 7b 08 00` | `CMP dword ptr [EBX + 0x8],0x0` |
| `10016ac7` | `75 0a` | `JNZ 0x10016ad3` |
| `10016ac9` | `83 c3 14` | `ADD EBX,0x14` |
| `10016acc` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `10016acf` | `3b d9` | `CMP EBX,ECX` |
| `10016ad1` | `72 f0` | `JC 0x10016ac3` |
| `10016ad3` | `3b d9` | `CMP EBX,ECX` |
| `10016ad5` | `75 15` | `JNZ 0x10016aec` |
| `10016ad7` | `e8 a0 fa ff ff` | `CALL 0x1001657c` |
| `10016adc` | `8b d8` | `MOV EBX,EAX` |
| `10016ade` | `89 5d 08` | `MOV dword ptr [EBP + 0x8],EBX` |
| `10016ae1` | `85 db` | `TEST EBX,EBX` |
| `10016ae3` | `75 07` | `JNZ 0x10016aec` |
| `10016ae5` | `33 c0` | `XOR EAX,EAX` |
| `10016ae7` | `e9 09 02 00 00` | `JMP 0x10016cf5` |
| `10016aec` | `53` | `PUSH EBX` |
| `10016aed` | `e8 3a fb ff ff` | `CALL 0x1001662c` |
| `10016af2` | `59` | `POP ECX` |
| `10016af3` | `8b 4b 10` | `MOV ECX,dword ptr [EBX + 0x10]` |
| `10016af6` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `10016af8` | `8b 43 10` | `MOV EAX,dword ptr [EBX + 0x10]` |
| `10016afb` | `83 38 ff` | `CMP dword ptr [EAX],-0x1` |
| `10016afe` | `74 e5` | `JZ 0x10016ae5` |
| `10016b00` | `89 1d 74 a6 43 13` | `MOV dword ptr [0x1343a674],EBX` |
| `10016b06` | `8b 43 10` | `MOV EAX,dword ptr [EBX + 0x10]` |
| `10016b09` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `10016b0b` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `10016b0e` | `83 fa ff` | `CMP EDX,-0x1` |
| `10016b11` | `74 14` | `JZ 0x10016b27` |
| `10016b13` | `8b 8c 90 c4 00 00 00` | `MOV ECX,dword ptr [EAX + EDX*0x4 + 0xc4]` |
| `10016b1a` | `8b 7c 90 44` | `MOV EDI,dword ptr [EAX + EDX*0x4 + 0x44]` |
| `10016b1e` | `23 4d f8` | `AND ECX,dword ptr [EBP + -0x8]` |
| `10016b21` | `23 fe` | `AND EDI,ESI` |
| `10016b23` | `0b cf` | `OR ECX,EDI` |
| `10016b25` | `75 29` | `JNZ 0x10016b50` |
| `10016b27` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10016b2b` | `8b 90 c4 00 00 00` | `MOV EDX,dword ptr [EAX + 0xc4]` |
| `10016b31` | `8d 48 44` | `LEA ECX,[EAX + 0x44]` |
| `10016b34` | `8b 39` | `MOV EDI,dword ptr [ECX]` |
| `10016b36` | `23 55 f8` | `AND EDX,dword ptr [EBP + -0x8]` |
| `10016b39` | `23 fe` | `AND EDI,ESI` |
| `10016b3b` | `0b d7` | `OR EDX,EDI` |
| `10016b3d` | `75 0e` | `JNZ 0x10016b4d` |
| `10016b3f` | `ff 45 fc` | `INC dword ptr [EBP + -0x4]` |
| `10016b42` | `8b 91 84 00 00 00` | `MOV EDX,dword ptr [ECX + 0x84]` |
| `10016b48` | `83 c1 04` | `ADD ECX,0x4` |
| `10016b4b` | `eb e7` | `JMP 0x10016b34` |
| `10016b4d` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `10016b50` | `8b ca` | `MOV ECX,EDX` |
| `10016b52` | `69 c9 04 02 00 00` | `IMUL ECX,ECX,0x204` |
| `10016b58` | `8d 8c 01 44 01 00 00` | `LEA ECX,[ECX + EAX*0x1 + 0x144]` |
| `10016b5f` | `89 4d f4` | `MOV dword ptr [EBP + -0xc],ECX` |
| `10016b62` | `8b 4c 90 44` | `MOV ECX,dword ptr [EAX + EDX*0x4 + 0x44]` |
| `10016b66` | `33 ff` | `XOR EDI,EDI` |
| `10016b68` | `23 ce` | `AND ECX,ESI` |
| `10016b6a` | `75 12` | `JNZ 0x10016b7e` |
| `10016b6c` | `8b 8c 90 c4 00 00 00` | `MOV ECX,dword ptr [EAX + EDX*0x4 + 0xc4]` |
| `10016b73` | `23 4d f8` | `AND ECX,dword ptr [EBP + -0x8]` |
| `10016b76` | `6a 20` | `PUSH 0x20` |
| `10016b78` | `5f` | `POP EDI` |
| `10016b79` | `eb 03` | `JMP 0x10016b7e` |
| `10016b7b` | `03 c9` | `ADD ECX,ECX` |
| `10016b7d` | `47` | `INC EDI` |
| `10016b7e` | `85 c9` | `TEST ECX,ECX` |
| `10016b80` | `7d f9` | `JGE 0x10016b7b` |
| `10016b82` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10016b85` | `8b 54 f9 04` | `MOV EDX,dword ptr [ECX + EDI*0x8 + 0x4]` |
| `10016b89` | `8b 0a` | `MOV ECX,dword ptr [EDX]` |
| `10016b8b` | `2b 4d f0` | `SUB ECX,dword ptr [EBP + -0x10]` |
| `10016b8e` | `8b f1` | `MOV ESI,ECX` |
| `10016b90` | `c1 fe 04` | `SAR ESI,0x4` |
| `10016b93` | `4e` | `DEC ESI` |
| `10016b94` | `83 fe 3f` | `CMP ESI,0x3f` |
| `10016b97` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `10016b9a` | `7e 03` | `JLE 0x10016b9f` |
| `10016b9c` | `6a 3f` | `PUSH 0x3f` |
| `10016b9e` | `5e` | `POP ESI` |
| `10016b9f` | `3b f7` | `CMP ESI,EDI` |
| `10016ba1` | `0f 84 01 01 00 00` | `JZ 0x10016ca8` |
| `10016ba7` | `8b 4a 04` | `MOV ECX,dword ptr [EDX + 0x4]` |
| `10016baa` | `3b 4a 08` | `CMP ECX,dword ptr [EDX + 0x8]` |
| `10016bad` | `75 5c` | `JNZ 0x10016c0b` |
| `10016baf` | `83 ff 20` | `CMP EDI,0x20` |
| `10016bb2` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `10016bb7` | `7d 26` | `JGE 0x10016bdf` |
| `10016bb9` | `8b cf` | `MOV ECX,EDI` |
| `10016bbb` | `d3 eb` | `SHR EBX,CL` |
| `10016bbd` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016bc0` | `8d 7c 38 04` | `LEA EDI,[EAX + EDI*0x1 + 0x4]` |
| `10016bc4` | `f7 d3` | `NOT EBX` |
| `10016bc6` | `89 5d ec` | `MOV dword ptr [EBP + -0x14],EBX` |
| `10016bc9` | `23 5c 88 44` | `AND EBX,dword ptr [EAX + ECX*0x4 + 0x44]` |
| `10016bcd` | `89 5c 88 44` | `MOV dword ptr [EAX + ECX*0x4 + 0x44],EBX` |
| `10016bd1` | `fe 0f` | `DEC byte ptr [EDI]` |
| `10016bd3` | `75 33` | `JNZ 0x10016c08` |
| `10016bd5` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `10016bd8` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10016bdb` | `21 0b` | `AND dword ptr [EBX],ECX` |
| `10016bdd` | `eb 2c` | `JMP 0x10016c0b` |
| `10016bdf` | `8d 4f e0` | `LEA ECX,[EDI + -0x20]` |
| `10016be2` | `d3 eb` | `SHR EBX,CL` |
| `10016be4` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016be7` | `8d 8c 88 c4 00 00 00` | `LEA ECX,[EAX + ECX*0x4 + 0xc4]` |
| `10016bee` | `8d 7c 38 04` | `LEA EDI,[EAX + EDI*0x1 + 0x4]` |
| `10016bf2` | `f7 d3` | `NOT EBX` |
| `10016bf4` | `21 19` | `AND dword ptr [ECX],EBX` |
| `10016bf6` | `fe 0f` | `DEC byte ptr [EDI]` |
| `10016bf8` | `89 5d ec` | `MOV dword ptr [EBP + -0x14],EBX` |
| `10016bfb` | `75 0b` | `JNZ 0x10016c08` |
| `10016bfd` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10016c00` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `10016c03` | `21 4b 04` | `AND dword ptr [EBX + 0x4],ECX` |
| `10016c06` | `eb 03` | `JMP 0x10016c0b` |
| `10016c08` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `10016c0b` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10016c0f` | `8b 4a 08` | `MOV ECX,dword ptr [EDX + 0x8]` |
| `10016c12` | `8b 7a 04` | `MOV EDI,dword ptr [EDX + 0x4]` |
| `10016c15` | `89 79 04` | `MOV dword ptr [ECX + 0x4],EDI` |
| `10016c18` | `8b 4a 04` | `MOV ECX,dword ptr [EDX + 0x4]` |
| `10016c1b` | `8b 7a 08` | `MOV EDI,dword ptr [EDX + 0x8]` |
| `10016c1e` | `89 79 08` | `MOV dword ptr [ECX + 0x8],EDI` |
| `10016c21` | `0f 84 8d 00 00 00` | `JZ 0x10016cb4` |
| `10016c27` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10016c2a` | `8d 0c f1` | `LEA ECX,[ECX + ESI*0x8]` |
| `10016c2d` | `8b 79 04` | `MOV EDI,dword ptr [ECX + 0x4]` |
| `10016c30` | `89 4a 08` | `MOV dword ptr [EDX + 0x8],ECX` |
| `10016c33` | `89 7a 04` | `MOV dword ptr [EDX + 0x4],EDI` |
| `10016c36` | `89 51 04` | `MOV dword ptr [ECX + 0x4],EDX` |
| `10016c39` | `8b 4a 04` | `MOV ECX,dword ptr [EDX + 0x4]` |
| `10016c3c` | `89 51 08` | `MOV dword ptr [ECX + 0x8],EDX` |
| `10016c3f` | `8b 4a 04` | `MOV ECX,dword ptr [EDX + 0x4]` |
| `10016c42` | `3b 4a 08` | `CMP ECX,dword ptr [EDX + 0x8]` |
| `10016c45` | `75 5e` | `JNZ 0x10016ca5` |
| `10016c47` | `8a 4c 06 04` | `MOV CL,byte ptr [ESI + EAX*0x1 + 0x4]` |
| `10016c4b` | `88 4d 0b` | `MOV byte ptr [EBP + 0xb],CL` |
| `10016c4e` | `fe c1` | `INC CL` |
| `10016c50` | `83 fe 20` | `CMP ESI,0x20` |
| `10016c53` | `88 4c 06 04` | `MOV byte ptr [ESI + EAX*0x1 + 0x4],CL` |
| `10016c57` | `7d 23` | `JGE 0x10016c7c` |
| `10016c59` | `80 7d 0b 00` | `CMP byte ptr [EBP + 0xb],0x0` |
| `10016c5d` | `75 0b` | `JNZ 0x10016c6a` |
| `10016c5f` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `10016c64` | `8b ce` | `MOV ECX,ESI` |
| `10016c66` | `d3 ef` | `SHR EDI,CL` |
| `10016c68` | `09 3b` | `OR dword ptr [EBX],EDI` |
| `10016c6a` | `8b ce` | `MOV ECX,ESI` |
| `10016c6c` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `10016c71` | `d3 ef` | `SHR EDI,CL` |
| `10016c73` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016c76` | `09 7c 88 44` | `OR dword ptr [EAX + ECX*0x4 + 0x44],EDI` |
| `10016c7a` | `eb 29` | `JMP 0x10016ca5` |
| `10016c7c` | `80 7d 0b 00` | `CMP byte ptr [EBP + 0xb],0x0` |
| `10016c80` | `75 0d` | `JNZ 0x10016c8f` |
| `10016c82` | `8d 4e e0` | `LEA ECX,[ESI + -0x20]` |
| `10016c85` | `bf 00 00 00 80` | `MOV EDI,0x80000000` |
| `10016c8a` | `d3 ef` | `SHR EDI,CL` |
| `10016c8c` | `09 7b 04` | `OR dword ptr [EBX + 0x4],EDI` |
| `10016c8f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016c92` | `8d bc 88 c4 00 00 00` | `LEA EDI,[EAX + ECX*0x4 + 0xc4]` |
| `10016c99` | `8d 4e e0` | `LEA ECX,[ESI + -0x20]` |
| `10016c9c` | `be 00 00 00 80` | `MOV ESI,0x80000000` |
| `10016ca1` | `d3 ee` | `SHR ESI,CL` |
| `10016ca3` | `09 37` | `OR dword ptr [EDI],ESI` |
| `10016ca5` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10016ca8` | `85 c9` | `TEST ECX,ECX` |
| `10016caa` | `74 0b` | `JZ 0x10016cb7` |
| `10016cac` | `89 0a` | `MOV dword ptr [EDX],ECX` |
| `10016cae` | `89 4c 11 fc` | `MOV dword ptr [ECX + EDX*0x1 + -0x4],ECX` |
| `10016cb2` | `eb 03` | `JMP 0x10016cb7` |
| `10016cb4` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10016cb7` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `10016cba` | `03 d1` | `ADD EDX,ECX` |
| `10016cbc` | `8d 4e 01` | `LEA ECX,[ESI + 0x1]` |
| `10016cbf` | `89 0a` | `MOV dword ptr [EDX],ECX` |
| `10016cc1` | `89 4c 32 fc` | `MOV dword ptr [EDX + ESI*0x1 + -0x4],ECX` |
| `10016cc5` | `8b 75 f4` | `MOV ESI,dword ptr [EBP + -0xc]` |
| `10016cc8` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `10016cca` | `8d 79 01` | `LEA EDI,[ECX + 0x1]` |
| `10016ccd` | `89 3e` | `MOV dword ptr [ESI],EDI` |
| `10016ccf` | `85 c9` | `TEST ECX,ECX` |
| `10016cd1` | `75 1a` | `JNZ 0x10016ced` |
| `10016cd3` | `3b 1d 00 8f 03 10` | `CMP EBX,dword ptr [0x10038f00]` |
| `10016cd9` | `75 12` | `JNZ 0x10016ced` |
| `10016cdb` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016cde` | `3b 0d 7c a6 43 13` | `CMP ECX,dword ptr [0x1343a67c]` |
| `10016ce4` | `75 07` | `JNZ 0x10016ced` |
| `10016ce6` | `83 25 00 8f 03 10 00` | `AND dword ptr [0x10038f00],0x0` |
| `10016ced` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10016cf0` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `10016cf2` | `8d 42 04` | `LEA EAX,[EDX + 0x4]` |
| `10016cf5` | `5f` | `POP EDI` |
| `10016cf6` | `5e` | `POP ESI` |
| `10016cf7` | `5b` | `POP EBX` |
| `10016cf8` | `c9` | `LEAVE` |
| `10016cf9` | `c3` | `RET` |
