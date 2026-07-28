# 1001bebd `__setmbcp_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bebd |
| `name` | __setmbcp_nolock |
| `namespace` | Global |
| `signature` | undefined __setmbcp_nolock(void) |
| `size_bytes` | 485 |
| `stack_frame_size` | 40 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __setmbcp_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __setmbcp_nolock
   
   Library: Visual Studio 2008 Release */

void __setmbcp_nolock(undefined4 param_1,int param_2)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  BOOL BVar6;
  undefined2 *puVar7;
  byte *pbVar8;
  int extraout_ECX;
  undefined2 *puVar9;
  int iVar10;
  undefined4 extraout_EDX;
  BYTE *pBVar11;
  threadmbcinfostruct *unaff_EDI;
  uint local_24;
  byte *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  uVar4 = getSystemCP((int)unaff_EDI);
  if (uVar4 != 0) {
    local_20 = (byte *)0x0;
    uVar5 = 0;
LAB_1001befb:
    if (*(uint *)((int)&DAT_10038050 + uVar5) != uVar4) goto code_r0x1001bf07;
    _memset((void *)(param_2 + 0x1c),0,0x101);
    local_24 = 0;
    pbVar8 = &DAT_10038060 + (int)local_20 * 0x30;
    local_20 = pbVar8;
    do {
      for (; (*pbVar8 != 0 && (bVar3 = pbVar8[1], bVar3 != 0)); pbVar8 = pbVar8 + 2) {
        for (uVar5 = (uint)*pbVar8; uVar5 <= bVar3; uVar5 = uVar5 + 1) {
          pbVar2 = (byte *)(param_2 + 0x1d + uVar5);
          *pbVar2 = *pbVar2 | *(byte *)(local_24 + 0x1003804c);
          bVar3 = pbVar8[1];
        }
      }
      local_24 = local_24 + 1;
      pbVar8 = local_20 + 8;
      local_20 = pbVar8;
    } while (local_24 < 4);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 8) = 1;
    iVar10 = CPtoLCID((int)unaff_EDI);
    *(int *)(param_2 + 0xc) = iVar10;
    puVar7 = (undefined2 *)(param_2 + 0x10);
    puVar9 = (undefined2 *)(&DAT_10038054 + extraout_ECX);
    iVar10 = 6;
    do {
      *puVar7 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar7 = puVar7 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    goto LAB_1001c02c;
  }
LAB_1001bee8:
  setSBCS(unaff_EDI);
LAB_1001c093:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
code_r0x1001bf07:
  local_20 = (byte *)((int)local_20 + 1);
  uVar5 = uVar5 + 0x30;
  if (0xef < uVar5) goto code_r0x1001bf14;
  goto LAB_1001befb;
code_r0x1001bf14:
  if (((uVar4 == 65000) || (uVar4 == 0xfde9)) ||
     (BVar6 = IsValidCodePage(uVar4 & 0xffff), BVar6 == 0)) goto LAB_1001c093;
  BVar6 = GetCPInfo(uVar4,&local_1c);
  if (BVar6 != 0) {
    _memset((void *)(param_2 + 0x1c),0,0x101);
    *(uint *)(param_2 + 4) = uVar4;
    *(undefined4 *)(param_2 + 0xc) = 0;
    if (local_1c.MaxCharSize < 2) {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      if (local_1c.LeadByte[0] != '\0') {
        pBVar11 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar11;
          if (bVar3 == 0) break;
          for (uVar4 = (uint)pBVar11[-1]; uVar4 <= bVar3; uVar4 = uVar4 + 1) {
            pbVar8 = (byte *)(param_2 + 0x1d + uVar4);
            *pbVar8 = *pbVar8 | 4;
          }
          pBVar1 = pBVar11 + 1;
          pBVar11 = pBVar11 + 2;
        } while (*pBVar1 != 0);
      }
      pbVar8 = (byte *)(param_2 + 0x1e);
      iVar10 = 0xfe;
      do {
        *pbVar8 = *pbVar8 | 8;
        pbVar8 = pbVar8 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar10 = CPtoLCID((int)unaff_EDI);
      *(int *)(param_2 + 0xc) = iVar10;
      *(undefined4 *)(param_2 + 8) = extraout_EDX;
    }
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x18) = 0;
LAB_1001c02c:
    setSBUpLow(unaff_EDI);
    goto LAB_1001c093;
  }
  if (DAT_10039384 == 0) goto LAB_1001c093;
  goto LAB_1001bee8;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bed8` | `1001be41` | `UNCONDITIONAL_CALL` | getSystemCP | `1001be41` |
| `1001beea` | `1001bba6` | `UNCONDITIONAL_CALL` | setSBCS | `1001bba6` |
| `1001bf30` | `EXTERNAL:00000063` | `COMPUTED_CALL` | KERNEL32.DLL::IsValidCodePage | `` |
| `1001bf43` | `EXTERNAL:00000060` | `COMPUTED_CALL` | KERNEL32.DLL::GetCPInfo | `` |
| `1001bf5b` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001bfa2` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001c00b` | `1001bb77` | `UNCONDITIONAL_CALL` | CPtoLCID | `1001bb77` |
| `1001c02e` | `1001bc0a` | `UNCONDITIONAL_CALL` | setSBUpLow | `1001bc0a` |
| `1001c060` | `1001bb77` | `UNCONDITIONAL_CALL` | CPtoLCID | `1001bb77` |
| `1001c09b` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001c100` | __setmbcp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bec5` | `10037490` | `READ` | DAT_10037490 |
| `1001befb` | `10038050` | `READ` | DAT_10038050 |
| `1001befb` | `10038080` | `READ` | DAT_10038080 |
| `1001bf30` | `1002e144` | `READ` | PTR_IsValidCodePage_1002e144 |
| `1001bf43` | `1002e138` | `READ` | PTR_GetCPInfo_1002e138 |
| `1001bfb3` | `10038060` | `DATA` | DAT_10038060 |
| `1001bfbe` | `10038069` | `DATA` | DAT_10038069 |
| `1001bfc5` | `10038068` | `DATA` | DAT_10038068 |
| `1001bfd0` | `1003804d` | `DATA` | DAT_1003804d |
| `1001bfda` | `10038069` | `DATA` | DAT_10038069 |
| `1001bfe8` | `10038060` | `DATA` | DAT_10038060 |
| `1001bfe8` | `10038068` | `DATA` | DAT_10038068 |
| `1001bfe8` | `1003806a` | `DATA` | DAT_1003806a |
| `1001c018` | `10038054` | `DATA` | DAT_10038054 |
| `1001c01f` | `10038054` | `DATA` | DAT_10038054 |
| `1001c01f` | `10038056` | `DATA` | DAT_10038056 |
| `1001c084` | `10039384` | `READ` | DAT_10039384 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bebd` | `8b ff` | `MOV EDI,EDI` |
| `1001bebf` | `55` | `PUSH EBP` |
| `1001bec0` | `8b ec` | `MOV EBP,ESP` |
| `1001bec2` | `83 ec 20` | `SUB ESP,0x20` |
| `1001bec5` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001beca` | `33 c5` | `XOR EAX,EBP` |
| `1001becc` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001becf` | `53` | `PUSH EBX` |
| `1001bed0` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `1001bed3` | `56` | `PUSH ESI` |
| `1001bed4` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001bed7` | `57` | `PUSH EDI` |
| `1001bed8` | `e8 64 ff ff ff` | `CALL 0x1001be41` |
| `1001bedd` | `8b f8` | `MOV EDI,EAX` |
| `1001bedf` | `33 f6` | `XOR ESI,ESI` |
| `1001bee1` | `89 7d 08` | `MOV dword ptr [EBP + 0x8],EDI` |
| `1001bee4` | `3b fe` | `CMP EDI,ESI` |
| `1001bee6` | `75 0e` | `JNZ 0x1001bef6` |
| `1001bee8` | `8b c3` | `MOV EAX,EBX` |
| `1001beea` | `e8 b7 fc ff ff` | `CALL 0x1001bba6` |
| `1001beef` | `33 c0` | `XOR EAX,EAX` |
| `1001bef1` | `e9 9d 01 00 00` | `JMP 0x1001c093` |
| `1001bef6` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001bef9` | `33 c0` | `XOR EAX,EAX` |
| `1001befb` | `39 b8 50 80 03 10` | `CMP dword ptr [EAX + 0x10038050],EDI` |
| `1001bf01` | `0f 84 91 00 00 00` | `JZ 0x1001bf98` |
| `1001bf07` | `ff 45 e4` | `INC dword ptr [EBP + -0x1c]` |
| `1001bf0a` | `83 c0 30` | `ADD EAX,0x30` |
| `1001bf0d` | `3d f0 00 00 00` | `CMP EAX,0xf0` |
| `1001bf12` | `72 e7` | `JC 0x1001befb` |
| `1001bf14` | `81 ff e8 fd 00 00` | `CMP EDI,0xfde8` |
| `1001bf1a` | `0f 84 70 01 00 00` | `JZ 0x1001c090` |
| `1001bf20` | `81 ff e9 fd 00 00` | `CMP EDI,0xfde9` |
| `1001bf26` | `0f 84 64 01 00 00` | `JZ 0x1001c090` |
| `1001bf2c` | `0f b7 c7` | `MOVZX EAX,DI` |
| `1001bf2f` | `50` | `PUSH EAX` |
| `1001bf30` | `ff 15 44 e1 02 10` | `CALL dword ptr [0x1002e144]` |
| `1001bf36` | `85 c0` | `TEST EAX,EAX` |
| `1001bf38` | `0f 84 52 01 00 00` | `JZ 0x1001c090` |
| `1001bf3e` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001bf41` | `50` | `PUSH EAX` |
| `1001bf42` | `57` | `PUSH EDI` |
| `1001bf43` | `ff 15 38 e1 02 10` | `CALL dword ptr [0x1002e138]` |
| `1001bf49` | `85 c0` | `TEST EAX,EAX` |
| `1001bf4b` | `0f 84 33 01 00 00` | `JZ 0x1001c084` |
| `1001bf51` | `68 01 01 00 00` | `PUSH 0x101` |
| `1001bf56` | `8d 43 1c` | `LEA EAX,[EBX + 0x1c]` |
| `1001bf59` | `56` | `PUSH ESI` |
| `1001bf5a` | `50` | `PUSH EAX` |
| `1001bf5b` | `e8 90 57 ff ff` | `CALL 0x100116f0` |
| `1001bf60` | `33 d2` | `XOR EDX,EDX` |
| `1001bf62` | `42` | `INC EDX` |
| `1001bf63` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001bf66` | `89 7b 04` | `MOV dword ptr [EBX + 0x4],EDI` |
| `1001bf69` | `89 73 0c` | `MOV dword ptr [EBX + 0xc],ESI` |
| `1001bf6c` | `39 55 e8` | `CMP dword ptr [EBP + -0x18],EDX` |
| `1001bf6f` | `0f 86 f8 00 00 00` | `JBE 0x1001c06d` |
| `1001bf75` | `80 7d ee 00` | `CMP byte ptr [EBP + -0x12],0x0` |
| `1001bf79` | `0f 84 cf 00 00 00` | `JZ 0x1001c04e` |
| `1001bf7f` | `8d 75 ef` | `LEA ESI,[EBP + -0x11]` |
| `1001bf82` | `8a 0e` | `MOV CL,byte ptr [ESI]` |
| `1001bf84` | `84 c9` | `TEST CL,CL` |
| `1001bf86` | `0f 84 c2 00 00 00` | `JZ 0x1001c04e` |
| `1001bf8c` | `0f b6 46 ff` | `MOVZX EAX,byte ptr [ESI + -0x1]` |
| `1001bf90` | `0f b6 c9` | `MOVZX ECX,CL` |
| `1001bf93` | `e9 a6 00 00 00` | `JMP 0x1001c03e` |
| `1001bf98` | `68 01 01 00 00` | `PUSH 0x101` |
| `1001bf9d` | `8d 43 1c` | `LEA EAX,[EBX + 0x1c]` |
| `1001bfa0` | `56` | `PUSH ESI` |
| `1001bfa1` | `50` | `PUSH EAX` |
| `1001bfa2` | `e8 49 57 ff ff` | `CALL 0x100116f0` |
| `1001bfa7` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1001bfaa` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001bfad` | `6b c9 30` | `IMUL ECX,ECX,0x30` |
| `1001bfb0` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `1001bfb3` | `8d b1 60 80 03 10` | `LEA ESI,[ECX + 0x10038060]` |
| `1001bfb9` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001bfbc` | `eb 2a` | `JMP 0x1001bfe8` |
| `1001bfbe` | `8a 46 01` | `MOV AL,byte ptr [ESI + 0x1]` |
| `1001bfc1` | `84 c0` | `TEST AL,AL` |
| `1001bfc3` | `74 28` | `JZ 0x1001bfed` |
| `1001bfc5` | `0f b6 3e` | `MOVZX EDI,byte ptr [ESI]` |
| `1001bfc8` | `0f b6 c0` | `MOVZX EAX,AL` |
| `1001bfcb` | `eb 12` | `JMP 0x1001bfdf` |
| `1001bfcd` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1001bfd0` | `8a 80 4c 80 03 10` | `MOV AL,byte ptr [EAX + 0x1003804c]` |
| `1001bfd6` | `08 44 3b 1d` | `OR byte ptr [EBX + EDI*0x1 + 0x1d],AL` |
| `1001bfda` | `0f b6 46 01` | `MOVZX EAX,byte ptr [ESI + 0x1]` |
| `1001bfde` | `47` | `INC EDI` |
| `1001bfdf` | `3b f8` | `CMP EDI,EAX` |
| `1001bfe1` | `76 ea` | `JBE 0x1001bfcd` |
| `1001bfe3` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001bfe6` | `46` | `INC ESI` |
| `1001bfe7` | `46` | `INC ESI` |
| `1001bfe8` | `80 3e 00` | `CMP byte ptr [ESI],0x0` |
| `1001bfeb` | `75 d1` | `JNZ 0x1001bfbe` |
| `1001bfed` | `8b 75 e4` | `MOV ESI,dword ptr [EBP + -0x1c]` |
| `1001bff0` | `ff 45 e0` | `INC dword ptr [EBP + -0x20]` |
| `1001bff3` | `83 c6 08` | `ADD ESI,0x8` |
| `1001bff6` | `83 7d e0 04` | `CMP dword ptr [EBP + -0x20],0x4` |
| `1001bffa` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001bffd` | `72 e9` | `JC 0x1001bfe8` |
| `1001bfff` | `8b c7` | `MOV EAX,EDI` |
| `1001c001` | `89 7b 04` | `MOV dword ptr [EBX + 0x4],EDI` |
| `1001c004` | `c7 43 08 01 00 00 00` | `MOV dword ptr [EBX + 0x8],0x1` |
| `1001c00b` | `e8 67 fb ff ff` | `CALL 0x1001bb77` |
| `1001c010` | `6a 06` | `PUSH 0x6` |
| `1001c012` | `89 43 0c` | `MOV dword ptr [EBX + 0xc],EAX` |
| `1001c015` | `8d 43 10` | `LEA EAX,[EBX + 0x10]` |
| `1001c018` | `8d 89 54 80 03 10` | `LEA ECX,[ECX + 0x10038054]` |
| `1001c01e` | `5a` | `POP EDX` |
| `1001c01f` | `66 8b 31` | `MOV SI,word ptr [ECX]` |
| `1001c022` | `41` | `INC ECX` |
| `1001c023` | `66 89 30` | `MOV word ptr [EAX],SI` |
| `1001c026` | `41` | `INC ECX` |
| `1001c027` | `40` | `INC EAX` |
| `1001c028` | `40` | `INC EAX` |
| `1001c029` | `4a` | `DEC EDX` |
| `1001c02a` | `75 f3` | `JNZ 0x1001c01f` |
| `1001c02c` | `8b f3` | `MOV ESI,EBX` |
| `1001c02e` | `e8 d7 fb ff ff` | `CALL 0x1001bc0a` |
| `1001c033` | `e9 b7 fe ff ff` | `JMP 0x1001beef` |
| `1001c038` | `80 4c 03 1d 04` | `OR byte ptr [EBX + EAX*0x1 + 0x1d],0x4` |
| `1001c03d` | `40` | `INC EAX` |
| `1001c03e` | `3b c1` | `CMP EAX,ECX` |
| `1001c040` | `76 f6` | `JBE 0x1001c038` |
| `1001c042` | `46` | `INC ESI` |
| `1001c043` | `46` | `INC ESI` |
| `1001c044` | `80 7e ff 00` | `CMP byte ptr [ESI + -0x1],0x0` |
| `1001c048` | `0f 85 34 ff ff ff` | `JNZ 0x1001bf82` |
| `1001c04e` | `8d 43 1e` | `LEA EAX,[EBX + 0x1e]` |
| `1001c051` | `b9 fe 00 00 00` | `MOV ECX,0xfe` |
| `1001c056` | `80 08 08` | `OR byte ptr [EAX],0x8` |
| `1001c059` | `40` | `INC EAX` |
| `1001c05a` | `49` | `DEC ECX` |
| `1001c05b` | `75 f9` | `JNZ 0x1001c056` |
| `1001c05d` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1001c060` | `e8 12 fb ff ff` | `CALL 0x1001bb77` |
| `1001c065` | `89 43 0c` | `MOV dword ptr [EBX + 0xc],EAX` |
| `1001c068` | `89 53 08` | `MOV dword ptr [EBX + 0x8],EDX` |
| `1001c06b` | `eb 03` | `JMP 0x1001c070` |
| `1001c06d` | `89 73 08` | `MOV dword ptr [EBX + 0x8],ESI` |
| `1001c070` | `33 c0` | `XOR EAX,EAX` |
| `1001c072` | `0f b7 c8` | `MOVZX ECX,AX` |
| `1001c075` | `8b c1` | `MOV EAX,ECX` |
| `1001c077` | `c1 e1 10` | `SHL ECX,0x10` |
| `1001c07a` | `0b c1` | `OR EAX,ECX` |
| `1001c07c` | `8d 7b 10` | `LEA EDI,[EBX + 0x10]` |
| `1001c07f` | `ab` | `STOSD ES:EDI` |
| `1001c080` | `ab` | `STOSD ES:EDI` |
| `1001c081` | `ab` | `STOSD ES:EDI` |
| `1001c082` | `eb a8` | `JMP 0x1001c02c` |
| `1001c084` | `39 35 84 93 03 10` | `CMP dword ptr [0x10039384],ESI` |
| `1001c08a` | `0f 85 58 fe ff ff` | `JNZ 0x1001bee8` |
| `1001c090` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001c093` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001c096` | `5f` | `POP EDI` |
| `1001c097` | `5e` | `POP ESI` |
| `1001c098` | `33 cd` | `XOR ECX,EBP` |
| `1001c09a` | `5b` | `POP EBX` |
| `1001c09b` | `e8 2b 4c ff ff` | `CALL 0x10010ccb` |
| `1001c0a0` | `c9` | `LEAVE` |
| `1001c0a1` | `c3` | `RET` |
