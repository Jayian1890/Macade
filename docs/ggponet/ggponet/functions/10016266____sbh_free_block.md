# 10016266 `___sbh_free_block`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016266 |
| `name` | ___sbh_free_block |
| `namespace` | Global |
| `signature` | undefined ___sbh_free_block(void) |
| `size_bytes` | 790 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_free_block |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_free_block
   
   Library: Visual Studio 2008 Release */

void ___sbh_free_block(uint *param_1,int param_2)

{
  int *piVar1;
  char *pcVar2;
  uint *puVar3;
  int *piVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint local_8;
  
  uVar6 = param_1[4];
  puVar12 = (uint *)(param_2 + -4);
  uVar14 = param_2 - param_1[3] >> 0xf;
  piVar4 = (int *)(uVar14 * 0x204 + 0x144 + uVar6);
  local_8 = *puVar12 - 1;
  if ((local_8 & 1) == 0) {
    puVar10 = (uint *)(local_8 + (int)puVar12);
    uVar13 = *puVar10;
    uVar7 = *(uint *)(param_2 + -8);
    if ((uVar13 & 1) == 0) {
      uVar9 = ((int)uVar13 >> 4) - 1;
      if (0x3f < uVar9) {
        uVar9 = 0x3f;
      }
      if (puVar10[1] == puVar10[2]) {
        if (uVar9 < 0x20) {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            *param_1 = *param_1 & uVar9;
          }
        }
        else {
          pcVar2 = (char *)(uVar9 + 4 + uVar6);
          uVar9 = ~(0x80000000U >> ((byte)uVar9 - 0x20 & 0x1f));
          puVar11 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar11 = *puVar11 & uVar9;
          *pcVar2 = *pcVar2 + -1;
          if (*pcVar2 == '\0') {
            param_1[1] = param_1[1] & uVar9;
          }
        }
      }
      local_8 = local_8 + uVar13;
      *(uint *)(puVar10[2] + 4) = puVar10[1];
      *(uint *)(puVar10[1] + 8) = puVar10[2];
    }
    puVar10 = (uint *)(((int)local_8 >> 4) + -1);
    if ((uint *)0x3f < puVar10) {
      puVar10 = (uint *)0x3f;
    }
    puVar11 = param_1;
    if ((uVar7 & 1) == 0) {
      puVar12 = (uint *)((int)puVar12 - uVar7);
      puVar11 = (uint *)(((int)uVar7 >> 4) + -1);
      if ((uint *)0x3f < puVar11) {
        puVar11 = (uint *)0x3f;
      }
      local_8 = local_8 + uVar7;
      puVar10 = (uint *)(((int)local_8 >> 4) + -1);
      if ((uint *)0x3f < puVar10) {
        puVar10 = (uint *)0x3f;
      }
      if (puVar11 != puVar10) {
        if (puVar12[1] == puVar12[2]) {
          if (puVar11 < (uint *)0x20) {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              *param_1 = *param_1 & uVar13;
            }
          }
          else {
            uVar13 = ~(0x80000000U >> ((byte)puVar11 - 0x20 & 0x1f));
            puVar3 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
            *puVar3 = *puVar3 & uVar13;
            pcVar2 = (char *)((int)puVar11 + uVar6 + 4);
            *pcVar2 = *pcVar2 + -1;
            if (*pcVar2 == '\0') {
              param_1[1] = param_1[1] & uVar13;
            }
          }
        }
        *(uint *)(puVar12[2] + 4) = puVar12[1];
        *(uint *)(puVar12[1] + 8) = puVar12[2];
      }
    }
    if (((uVar7 & 1) != 0) || (puVar11 != puVar10)) {
      piVar1 = piVar4 + (int)puVar10 * 2;
      uVar13 = piVar1[1];
      puVar12[2] = (uint)piVar1;
      puVar12[1] = uVar13;
      piVar1[1] = (int)puVar12;
      *(uint **)(puVar12[1] + 8) = puVar12;
      if (puVar12[1] == puVar12[2]) {
        cVar5 = *(char *)((int)puVar10 + uVar6 + 4);
        *(char *)((int)puVar10 + uVar6 + 4) = cVar5 + '\x01';
        bVar8 = (byte)puVar10;
        if (puVar10 < (uint *)0x20) {
          if (cVar5 == '\0') {
            *param_1 = *param_1 | 0x80000000U >> (bVar8 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0x44 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 & 0x1f);
        }
        else {
          if (cVar5 == '\0') {
            param_1[1] = param_1[1] | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
          }
          puVar10 = (uint *)(uVar6 + 0xc4 + uVar14 * 4);
          *puVar10 = *puVar10 | 0x80000000U >> (bVar8 - 0x20 & 0x1f);
        }
      }
    }
    *puVar12 = local_8;
    *(uint *)((local_8 - 4) + (int)puVar12) = local_8;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      if (DAT_10038f00 != (uint *)0x0) {
        VirtualFree((LPVOID)(DAT_1343a67c * 0x8000 + DAT_10038f00[3]),0x8000,0x4000);
        DAT_10038f00[2] = DAT_10038f00[2] | 0x80000000U >> ((byte)DAT_1343a67c & 0x1f);
        *(undefined4 *)(DAT_10038f00[4] + 0xc4 + DAT_1343a67c * 4) = 0;
        *(char *)(DAT_10038f00[4] + 0x43) = *(char *)(DAT_10038f00[4] + 0x43) + -1;
        if (*(char *)(DAT_10038f00[4] + 0x43) == '\0') {
          DAT_10038f00[1] = DAT_10038f00[1] & 0xfffffffe;
        }
        if (DAT_10038f00[2] == 0xffffffff) {
          VirtualFree((LPVOID)DAT_10038f00[3],0,0x8000);
          HeapFree(DAT_10038dac,0,(LPVOID)DAT_10038f00[4]);
          _memmove(DAT_10038f00,DAT_10038f00 + 5,
                   (DAT_1343a668 * 0x14 - (int)DAT_10038f00) + -0x14 + DAT_1343a66c);
          DAT_1343a668 = DAT_1343a668 + -1;
          if (DAT_10038f00 < param_1) {
            param_1 = param_1 + -5;
          }
          DAT_1343a674 = DAT_1343a66c;
        }
      }
      DAT_10038f00 = param_1;
      DAT_1343a67c = uVar14;
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100164af` | `EXTERNAL:00000040` | `COMPUTED_CALL` | KERNEL32.DLL::VirtualFree | `` |
| `1001650a` | `EXTERNAL:00000040` | `COMPUTED_CALL` | KERNEL32.DLL::VirtualFree | `` |
| `1001651c` | `EXTERNAL:0000002f` | `COMPUTED_CALL` | KERNEL32.DLL::HeapFree | `` |
| `10016542` | `10012740` | `UNCONDITIONAL_CALL` | _memmove | `10012740` |

## Callers

| From | Function |
| --- | --- |
| `10011279` | _free |
| `10012b65` | _realloc |
| `10012bb2` | _realloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016484` | `10038f00` | `READ` | DAT_10038f00 |
| `10016491` | `1343a67c` | `READ` | DAT_1343a67c |
| `10016497` | `1002e0b8` | `READ` | PTR_VirtualFree_1002e0b8 |
| `100164b1` | `1343a67c` | `READ` | DAT_1343a67c |
| `100164b7` | `10038f00` | `READ` | DAT_10038f00 |
| `100164c6` | `10038f00` | `READ` | DAT_10038f00 |
| `100164ce` | `1343a67c` | `READ` | DAT_1343a67c |
| `100164dc` | `10038f00` | `READ` | DAT_10038f00 |
| `100164e7` | `10038f00` | `READ` | DAT_10038f00 |
| `100164f9` | `10038f00` | `READ` | DAT_10038f00 |
| `1001650c` | `10038f00` | `READ` | DAT_10038f00 |
| `10016516` | `10038dac` | `READ` | DAT_10038dac |
| `1001651c` | `1002e074` | `READ` | PTR_HeapFree_1002e074 |
| `10016522` | `1343a668` | `READ` | DAT_1343a668 |
| `10016528` | `10038f00` | `READ` | DAT_10038f00 |
| `10016530` | `1343a66c` | `READ` | DAT_1343a66c |
| `1001654d` | `1343a668` | `READ_WRITE` | DAT_1343a668 |
| `10016553` | `10038f00` | `READ` | DAT_10038f00 |
| `1001655f` | `1343a66c` | `READ` | DAT_1343a66c |
| `10016564` | `1343a674` | `WRITE` | DAT_1343a674 |
| `1001656c` | `10038f00` | `WRITE` | DAT_10038f00 |
| `10016571` | `1343a67c` | `WRITE` | DAT_1343a67c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016266` | `8b ff` | `MOV EDI,EDI` |
| `10016268` | `55` | `PUSH EBP` |
| `10016269` | `8b ec` | `MOV EBP,ESP` |
| `1001626b` | `83 ec 10` | `SUB ESP,0x10` |
| `1001626e` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016271` | `8b 41 10` | `MOV EAX,dword ptr [ECX + 0x10]` |
| `10016274` | `56` | `PUSH ESI` |
| `10016275` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10016278` | `57` | `PUSH EDI` |
| `10016279` | `8b fe` | `MOV EDI,ESI` |
| `1001627b` | `2b 79 0c` | `SUB EDI,dword ptr [ECX + 0xc]` |
| `1001627e` | `83 c6 fc` | `ADD ESI,-0x4` |
| `10016281` | `c1 ef 0f` | `SHR EDI,0xf` |
| `10016284` | `8b cf` | `MOV ECX,EDI` |
| `10016286` | `69 c9 04 02 00 00` | `IMUL ECX,ECX,0x204` |
| `1001628c` | `8d 8c 01 44 01 00 00` | `LEA ECX,[ECX + EAX*0x1 + 0x144]` |
| `10016293` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `10016296` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `10016298` | `49` | `DEC ECX` |
| `10016299` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `1001629c` | `f6 c1 01` | `TEST CL,0x1` |
| `1001629f` | `0f 85 d3 02 00 00` | `JNZ 0x10016578` |
| `100162a5` | `53` | `PUSH EBX` |
| `100162a6` | `8d 1c 31` | `LEA EBX,[ECX + ESI*0x1]` |
| `100162a9` | `8b 13` | `MOV EDX,dword ptr [EBX]` |
| `100162ab` | `89 55 f4` | `MOV dword ptr [EBP + -0xc],EDX` |
| `100162ae` | `8b 56 fc` | `MOV EDX,dword ptr [ESI + -0x4]` |
| `100162b1` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `100162b4` | `8b 55 f4` | `MOV EDX,dword ptr [EBP + -0xc]` |
| `100162b7` | `89 5d 0c` | `MOV dword ptr [EBP + 0xc],EBX` |
| `100162ba` | `f6 c2 01` | `TEST DL,0x1` |
| `100162bd` | `75 74` | `JNZ 0x10016333` |
| `100162bf` | `c1 fa 04` | `SAR EDX,0x4` |
| `100162c2` | `4a` | `DEC EDX` |
| `100162c3` | `83 fa 3f` | `CMP EDX,0x3f` |
| `100162c6` | `76 03` | `JBE 0x100162cb` |
| `100162c8` | `6a 3f` | `PUSH 0x3f` |
| `100162ca` | `5a` | `POP EDX` |
| `100162cb` | `8b 4b 04` | `MOV ECX,dword ptr [EBX + 0x4]` |
| `100162ce` | `3b 4b 08` | `CMP ECX,dword ptr [EBX + 0x8]` |
| `100162d1` | `75 42` | `JNZ 0x10016315` |
| `100162d3` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `100162d8` | `83 fa 20` | `CMP EDX,0x20` |
| `100162db` | `73 19` | `JNC 0x100162f6` |
| `100162dd` | `8b ca` | `MOV ECX,EDX` |
| `100162df` | `d3 eb` | `SHR EBX,CL` |
| `100162e1` | `8d 4c 02 04` | `LEA ECX,[EDX + EAX*0x1 + 0x4]` |
| `100162e5` | `f7 d3` | `NOT EBX` |
| `100162e7` | `21 5c b8 44` | `AND dword ptr [EAX + EDI*0x4 + 0x44],EBX` |
| `100162eb` | `fe 09` | `DEC byte ptr [ECX]` |
| `100162ed` | `75 23` | `JNZ 0x10016312` |
| `100162ef` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100162f2` | `21 19` | `AND dword ptr [ECX],EBX` |
| `100162f4` | `eb 1c` | `JMP 0x10016312` |
| `100162f6` | `8d 4a e0` | `LEA ECX,[EDX + -0x20]` |
| `100162f9` | `d3 eb` | `SHR EBX,CL` |
| `100162fb` | `8d 4c 02 04` | `LEA ECX,[EDX + EAX*0x1 + 0x4]` |
| `100162ff` | `f7 d3` | `NOT EBX` |
| `10016301` | `21 9c b8 c4 00 00 00` | `AND dword ptr [EAX + EDI*0x4 + 0xc4],EBX` |
| `10016308` | `fe 09` | `DEC byte ptr [ECX]` |
| `1001630a` | `75 06` | `JNZ 0x10016312` |
| `1001630c` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001630f` | `21 59 04` | `AND dword ptr [ECX + 0x4],EBX` |
| `10016312` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `10016315` | `8b 53 08` | `MOV EDX,dword ptr [EBX + 0x8]` |
| `10016318` | `8b 5b 04` | `MOV EBX,dword ptr [EBX + 0x4]` |
| `1001631b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001631e` | `03 4d f4` | `ADD ECX,dword ptr [EBP + -0xc]` |
| `10016321` | `89 5a 04` | `MOV dword ptr [EDX + 0x4],EBX` |
| `10016324` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10016327` | `8b 5a 04` | `MOV EBX,dword ptr [EDX + 0x4]` |
| `1001632a` | `8b 52 08` | `MOV EDX,dword ptr [EDX + 0x8]` |
| `1001632d` | `89 53 08` | `MOV dword ptr [EBX + 0x8],EDX` |
| `10016330` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10016333` | `8b d1` | `MOV EDX,ECX` |
| `10016335` | `c1 fa 04` | `SAR EDX,0x4` |
| `10016338` | `4a` | `DEC EDX` |
| `10016339` | `83 fa 3f` | `CMP EDX,0x3f` |
| `1001633c` | `76 03` | `JBE 0x10016341` |
| `1001633e` | `6a 3f` | `PUSH 0x3f` |
| `10016340` | `5a` | `POP EDX` |
| `10016341` | `8b 5d f8` | `MOV EBX,dword ptr [EBP + -0x8]` |
| `10016344` | `83 e3 01` | `AND EBX,0x1` |
| `10016347` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `1001634a` | `0f 85 8f 00 00 00` | `JNZ 0x100163df` |
| `10016350` | `2b 75 f8` | `SUB ESI,dword ptr [EBP + -0x8]` |
| `10016353` | `8b 5d f8` | `MOV EBX,dword ptr [EBP + -0x8]` |
| `10016356` | `c1 fb 04` | `SAR EBX,0x4` |
| `10016359` | `6a 3f` | `PUSH 0x3f` |
| `1001635b` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `1001635e` | `4b` | `DEC EBX` |
| `1001635f` | `5e` | `POP ESI` |
| `10016360` | `3b de` | `CMP EBX,ESI` |
| `10016362` | `76 02` | `JBE 0x10016366` |
| `10016364` | `8b de` | `MOV EBX,ESI` |
| `10016366` | `03 4d f8` | `ADD ECX,dword ptr [EBP + -0x8]` |
| `10016369` | `8b d1` | `MOV EDX,ECX` |
| `1001636b` | `c1 fa 04` | `SAR EDX,0x4` |
| `1001636e` | `4a` | `DEC EDX` |
| `1001636f` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10016372` | `3b d6` | `CMP EDX,ESI` |
| `10016374` | `76 02` | `JBE 0x10016378` |
| `10016376` | `8b d6` | `MOV EDX,ESI` |
| `10016378` | `3b da` | `CMP EBX,EDX` |
| `1001637a` | `74 5e` | `JZ 0x100163da` |
| `1001637c` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001637f` | `8b 71 04` | `MOV ESI,dword ptr [ECX + 0x4]` |
| `10016382` | `3b 71 08` | `CMP ESI,dword ptr [ECX + 0x8]` |
| `10016385` | `75 3b` | `JNZ 0x100163c2` |
| `10016387` | `be 00 00 00 80` | `MOV ESI,0x80000000` |
| `1001638c` | `83 fb 20` | `CMP EBX,0x20` |
| `1001638f` | `73 17` | `JNC 0x100163a8` |
| `10016391` | `8b cb` | `MOV ECX,EBX` |
| `10016393` | `d3 ee` | `SHR ESI,CL` |
| `10016395` | `f7 d6` | `NOT ESI` |
| `10016397` | `21 74 b8 44` | `AND dword ptr [EAX + EDI*0x4 + 0x44],ESI` |
| `1001639b` | `fe 4c 03 04` | `DEC byte ptr [EBX + EAX*0x1 + 0x4]` |
| `1001639f` | `75 21` | `JNZ 0x100163c2` |
| `100163a1` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100163a4` | `21 31` | `AND dword ptr [ECX],ESI` |
| `100163a6` | `eb 1a` | `JMP 0x100163c2` |
| `100163a8` | `8d 4b e0` | `LEA ECX,[EBX + -0x20]` |
| `100163ab` | `d3 ee` | `SHR ESI,CL` |
| `100163ad` | `f7 d6` | `NOT ESI` |
| `100163af` | `21 b4 b8 c4 00 00 00` | `AND dword ptr [EAX + EDI*0x4 + 0xc4],ESI` |
| `100163b6` | `fe 4c 03 04` | `DEC byte ptr [EBX + EAX*0x1 + 0x4]` |
| `100163ba` | `75 06` | `JNZ 0x100163c2` |
| `100163bc` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100163bf` | `21 71 04` | `AND dword ptr [ECX + 0x4],ESI` |
| `100163c2` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `100163c5` | `8b 71 08` | `MOV ESI,dword ptr [ECX + 0x8]` |
| `100163c8` | `8b 49 04` | `MOV ECX,dword ptr [ECX + 0x4]` |
| `100163cb` | `89 4e 04` | `MOV dword ptr [ESI + 0x4],ECX` |
| `100163ce` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `100163d1` | `8b 71 04` | `MOV ESI,dword ptr [ECX + 0x4]` |
| `100163d4` | `8b 49 08` | `MOV ECX,dword ptr [ECX + 0x8]` |
| `100163d7` | `89 4e 08` | `MOV dword ptr [ESI + 0x8],ECX` |
| `100163da` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `100163dd` | `eb 03` | `JMP 0x100163e2` |
| `100163df` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `100163e2` | `83 7d f4 00` | `CMP dword ptr [EBP + -0xc],0x0` |
| `100163e6` | `75 08` | `JNZ 0x100163f0` |
| `100163e8` | `3b da` | `CMP EBX,EDX` |
| `100163ea` | `0f 84 80 00 00 00` | `JZ 0x10016470` |
| `100163f0` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `100163f3` | `8d 0c d1` | `LEA ECX,[ECX + EDX*0x8]` |
| `100163f6` | `8b 59 04` | `MOV EBX,dword ptr [ECX + 0x4]` |
| `100163f9` | `89 4e 08` | `MOV dword ptr [ESI + 0x8],ECX` |
| `100163fc` | `89 5e 04` | `MOV dword ptr [ESI + 0x4],EBX` |
| `100163ff` | `89 71 04` | `MOV dword ptr [ECX + 0x4],ESI` |
| `10016402` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `10016405` | `89 71 08` | `MOV dword ptr [ECX + 0x8],ESI` |
| `10016408` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `1001640b` | `3b 4e 08` | `CMP ECX,dword ptr [ESI + 0x8]` |
| `1001640e` | `75 60` | `JNZ 0x10016470` |
| `10016410` | `8a 4c 02 04` | `MOV CL,byte ptr [EDX + EAX*0x1 + 0x4]` |
| `10016414` | `88 4d 0f` | `MOV byte ptr [EBP + 0xf],CL` |
| `10016417` | `fe c1` | `INC CL` |
| `10016419` | `88 4c 02 04` | `MOV byte ptr [EDX + EAX*0x1 + 0x4],CL` |
| `1001641d` | `83 fa 20` | `CMP EDX,0x20` |
| `10016420` | `73 25` | `JNC 0x10016447` |
| `10016422` | `80 7d 0f 00` | `CMP byte ptr [EBP + 0xf],0x0` |
| `10016426` | `75 0e` | `JNZ 0x10016436` |
| `10016428` | `8b ca` | `MOV ECX,EDX` |
| `1001642a` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `1001642f` | `d3 eb` | `SHR EBX,CL` |
| `10016431` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10016434` | `09 19` | `OR dword ptr [ECX],EBX` |
| `10016436` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `1001643b` | `8b ca` | `MOV ECX,EDX` |
| `1001643d` | `d3 eb` | `SHR EBX,CL` |
| `1001643f` | `8d 44 b8 44` | `LEA EAX,[EAX + EDI*0x4 + 0x44]` |
| `10016443` | `09 18` | `OR dword ptr [EAX],EBX` |
| `10016445` | `eb 29` | `JMP 0x10016470` |
| `10016447` | `80 7d 0f 00` | `CMP byte ptr [EBP + 0xf],0x0` |
| `1001644b` | `75 10` | `JNZ 0x1001645d` |
| `1001644d` | `8d 4a e0` | `LEA ECX,[EDX + -0x20]` |
| `10016450` | `bb 00 00 00 80` | `MOV EBX,0x80000000` |
| `10016455` | `d3 eb` | `SHR EBX,CL` |
| `10016457` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001645a` | `09 59 04` | `OR dword ptr [ECX + 0x4],EBX` |
| `1001645d` | `8d 4a e0` | `LEA ECX,[EDX + -0x20]` |
| `10016460` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `10016465` | `d3 ea` | `SHR EDX,CL` |
| `10016467` | `8d 84 b8 c4 00 00 00` | `LEA EAX,[EAX + EDI*0x4 + 0xc4]` |
| `1001646e` | `09 10` | `OR dword ptr [EAX],EDX` |
| `10016470` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10016473` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10016475` | `89 44 30 fc` | `MOV dword ptr [EAX + ESI*0x1 + -0x4],EAX` |
| `10016479` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001647c` | `ff 08` | `DEC dword ptr [EAX]` |
| `1001647e` | `0f 85 f3 00 00 00` | `JNZ 0x10016577` |
| `10016484` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `10016489` | `85 c0` | `TEST EAX,EAX` |
| `1001648b` | `0f 84 d8 00 00 00` | `JZ 0x10016569` |
| `10016491` | `8b 0d 7c a6 43 13` | `MOV ECX,dword ptr [0x1343a67c]` |
| `10016497` | `8b 35 b8 e0 02 10` | `MOV ESI,dword ptr [0x1002e0b8]` |
| `1001649d` | `68 00 40 00 00` | `PUSH 0x4000` |
| `100164a2` | `c1 e1 0f` | `SHL ECX,0xf` |
| `100164a5` | `03 48 0c` | `ADD ECX,dword ptr [EAX + 0xc]` |
| `100164a8` | `bb 00 80 00 00` | `MOV EBX,0x8000` |
| `100164ad` | `53` | `PUSH EBX` |
| `100164ae` | `51` | `PUSH ECX` |
| `100164af` | `ff d6` | `CALL ESI` |
| `100164b1` | `8b 0d 7c a6 43 13` | `MOV ECX,dword ptr [0x1343a67c]` |
| `100164b7` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `100164bc` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `100164c1` | `d3 ea` | `SHR EDX,CL` |
| `100164c3` | `09 50 08` | `OR dword ptr [EAX + 0x8],EDX` |
| `100164c6` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `100164cb` | `8b 40 10` | `MOV EAX,dword ptr [EAX + 0x10]` |
| `100164ce` | `8b 0d 7c a6 43 13` | `MOV ECX,dword ptr [0x1343a67c]` |
| `100164d4` | `83 a4 88 c4 00 00 00 00` | `AND dword ptr [EAX + ECX*0x4 + 0xc4],0x0` |
| `100164dc` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `100164e1` | `8b 40 10` | `MOV EAX,dword ptr [EAX + 0x10]` |
| `100164e4` | `fe 48 43` | `DEC byte ptr [EAX + 0x43]` |
| `100164e7` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `100164ec` | `8b 48 10` | `MOV ECX,dword ptr [EAX + 0x10]` |
| `100164ef` | `80 79 43 00` | `CMP byte ptr [ECX + 0x43],0x0` |
| `100164f3` | `75 09` | `JNZ 0x100164fe` |
| `100164f5` | `83 60 04 fe` | `AND dword ptr [EAX + 0x4],0xfffffffe` |
| `100164f9` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `100164fe` | `83 78 08 ff` | `CMP dword ptr [EAX + 0x8],-0x1` |
| `10016502` | `75 65` | `JNZ 0x10016569` |
| `10016504` | `53` | `PUSH EBX` |
| `10016505` | `6a 00` | `PUSH 0x0` |
| `10016507` | `ff 70 0c` | `PUSH dword ptr [EAX + 0xc]` |
| `1001650a` | `ff d6` | `CALL ESI` |
| `1001650c` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `10016511` | `ff 70 10` | `PUSH dword ptr [EAX + 0x10]` |
| `10016514` | `6a 00` | `PUSH 0x0` |
| `10016516` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `1001651c` | `ff 15 74 e0 02 10` | `CALL dword ptr [0x1002e074]` |
| `10016522` | `8b 0d 68 a6 43 13` | `MOV ECX,dword ptr [0x1343a668]` |
| `10016528` | `a1 00 8f 03 10` | `MOV EAX,[0x10038f00]` |
| `1001652d` | `6b c9 14` | `IMUL ECX,ECX,0x14` |
| `10016530` | `8b 15 6c a6 43 13` | `MOV EDX,dword ptr [0x1343a66c]` |
| `10016536` | `2b c8` | `SUB ECX,EAX` |
| `10016538` | `8d 4c 11 ec` | `LEA ECX,[ECX + EDX*0x1 + -0x14]` |
| `1001653c` | `51` | `PUSH ECX` |
| `1001653d` | `8d 48 14` | `LEA ECX,[EAX + 0x14]` |
| `10016540` | `51` | `PUSH ECX` |
| `10016541` | `50` | `PUSH EAX` |
| `10016542` | `e8 f9 c1 ff ff` | `CALL 0x10012740` |
| `10016547` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001654a` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001654d` | `ff 0d 68 a6 43 13` | `DEC dword ptr [0x1343a668]` |
| `10016553` | `3b 05 00 8f 03 10` | `CMP EAX,dword ptr [0x10038f00]` |
| `10016559` | `76 04` | `JBE 0x1001655f` |
| `1001655b` | `83 6d 08 14` | `SUB dword ptr [EBP + 0x8],0x14` |
| `1001655f` | `a1 6c a6 43 13` | `MOV EAX,[0x1343a66c]` |
| `10016564` | `a3 74 a6 43 13` | `MOV [0x1343a674],EAX` |
| `10016569` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001656c` | `a3 00 8f 03 10` | `MOV [0x10038f00],EAX` |
| `10016571` | `89 3d 7c a6 43 13` | `MOV dword ptr [0x1343a67c],EDI` |
| `10016577` | `5b` | `POP EBX` |
| `10016578` | `5f` | `POP EDI` |
| `10016579` | `5e` | `POP ESI` |
| `1001657a` | `c9` | `LEAVE` |
| `1001657b` | `c3` | `RET` |
