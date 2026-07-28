# 10017af5 `strtoxl`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017af5 |
| `name` | strtoxl |
| `namespace` | Global |
| `signature` | ulong __cdecl strtoxl(localeinfo_struct * param_1, char * param_2, char * * param_3, int param_4, int param_5) |
| `size_bytes` | 559 |
| `stack_frame_size` | 48 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?strtoxl@@YAKPAUlocaleinfo_struct@@PBDPAPBDHH@Z, strtoxl |

## Decompiled C

```c

/* Library Function - Single Match
    unsigned long __cdecl strtoxl(struct localeinfo_struct *,char const *,char const * *,int,int)
   
   Library: Visual Studio 2008 Release */

ulong __cdecl
strtoxl(localeinfo_struct *param_1,char *param_2,char **param_3,int param_4,int param_5)

{
  ushort uVar1;
  byte *pbVar2;
  int *piVar3;
  uint uVar4;
  pthreadlocinfo ptVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  localeinfo_struct local_18;
  int local_10;
  char local_c;
  uint local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_18,param_1);
  if (param_3 != (char **)0x0) {
    *param_3 = param_2;
  }
  if ((param_2 == (char *)0x0) || ((param_4 != 0 && ((param_4 < 2 || (0x24 < param_4)))))) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  bVar8 = *param_2;
  local_8 = 0;
  ptVar5 = local_18.locinfo;
  pbVar2 = (byte *)param_2;
  while( true ) {
    pbVar9 = pbVar2 + 1;
    if ((int)ptVar5->locale_name[3] < 2) {
      uVar4 = *(ushort *)(ptVar5[1].lc_category[0].locale + (uint)bVar8 * 2) & 8;
    }
    else {
      uVar4 = __isctype_l((uint)bVar8,8,&local_18);
      ptVar5 = local_18.locinfo;
    }
    if (uVar4 == 0) break;
    bVar8 = *pbVar9;
    pbVar2 = pbVar9;
  }
  if (bVar8 == 0x2d) {
    param_5 = param_5 | 2;
LAB_10017bae:
    bVar8 = *pbVar9;
    pbVar9 = pbVar2 + 2;
  }
  else if (bVar8 == 0x2b) goto LAB_10017bae;
  if (((param_4 < 0) || (param_4 == 1)) || (0x24 < param_4)) {
    if (param_3 != (char **)0x0) {
      *param_3 = param_2;
    }
    if (local_c != '\0') {
      *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
    }
    return 0;
  }
  if (param_4 == 0) {
    if (bVar8 != 0x30) {
      param_4 = 10;
      goto LAB_10017c14;
    }
    if ((*pbVar9 != 0x78) && (*pbVar9 != 0x58)) {
      param_4 = 8;
      goto LAB_10017c14;
    }
    param_4 = 0x10;
  }
  else if ((param_4 != 0x10) || (bVar8 != 0x30)) goto LAB_10017c14;
  if ((*pbVar9 == 0x78) || (*pbVar9 == 0x58)) {
    bVar8 = pbVar9[1];
    pbVar9 = pbVar9 + 2;
  }
LAB_10017c14:
  uVar4 = (uint)(0xffffffff / (ulonglong)(uint)param_4);
  do {
    uVar1 = *(ushort *)(ptVar5[1].lc_category[0].locale + (uint)bVar8 * 2);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 0x103) == 0) {
LAB_10017c71:
        pbVar9 = pbVar9 + -1;
        if ((param_5 & 8U) == 0) {
          if (param_3 != (char **)0x0) {
            pbVar9 = (byte *)param_2;
          }
          local_8 = 0;
        }
        else if (((param_5 & 4U) != 0) ||
                (((param_5 & 1U) == 0 &&
                 ((((param_5 & 2U) != 0 && (0x80000000 < local_8)) ||
                  (((param_5 & 2U) == 0 && (0x7fffffff < local_8)))))))) {
          piVar3 = __errno();
          *piVar3 = 0x22;
          if ((param_5 & 1U) == 0) {
            local_8 = ((param_5 & 2U) != 0) + 0x7fffffff;
          }
          else {
            local_8 = 0xffffffff;
          }
        }
        if (param_3 != (char **)0x0) {
          *param_3 = (char *)pbVar9;
        }
        if ((param_5 & 2U) != 0) {
          local_8 = -local_8;
        }
        if (local_c == '\0') {
          return local_8;
        }
        *(uint *)(local_10 + 0x70) = *(uint *)(local_10 + 0x70) & 0xfffffffd;
        return local_8;
      }
      iVar7 = (int)(char)bVar8;
      if ((byte)(bVar8 + 0x9f) < 0x1a) {
        iVar7 = iVar7 + -0x20;
      }
      uVar6 = iVar7 - 0x37;
    }
    else {
      uVar6 = (int)(char)bVar8 - 0x30;
    }
    if ((uint)param_4 <= uVar6) goto LAB_10017c71;
    if ((local_8 < uVar4) ||
       ((local_8 == uVar4 && (uVar6 <= (uint)(0xffffffff % (ulonglong)(uint)param_4))))) {
      local_8 = local_8 * param_4 + uVar6;
      param_5 = param_5 | 8;
    }
    else {
      param_5 = param_5 | 0xc;
      if (param_3 == (char **)0x0) goto LAB_10017c71;
    }
    bVar8 = *pbVar9;
    pbVar9 = pbVar9 + 1;
  } while( true );
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017b05` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `10017b1c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10017b2c` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10017b78` | `1001cc14` | `UNCONDITIONAL_CALL` | __isctype_l | `1001cc14` |
| `10017cbd` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `10017d45` | _strtol |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017af5` | `8b ff` | `MOV EDI,EDI` |
| `10017af7` | `55` | `PUSH EBP` |
| `10017af8` | `8b ec` | `MOV EBP,ESP` |
| `10017afa` | `83 ec 14` | `SUB ESP,0x14` |
| `10017afd` | `56` | `PUSH ESI` |
| `10017afe` | `57` | `PUSH EDI` |
| `10017aff` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10017b02` | `8d 4d ec` | `LEA ECX,[EBP + -0x14]` |
| `10017b05` | `e8 ac d7 ff ff` | `CALL 0x100152b6` |
| `10017b0a` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10017b0d` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10017b10` | `33 ff` | `XOR EDI,EDI` |
| `10017b12` | `3b c7` | `CMP EAX,EDI` |
| `10017b14` | `74 02` | `JZ 0x10017b18` |
| `10017b16` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10017b18` | `3b f7` | `CMP ESI,EDI` |
| `10017b1a` | `75 2c` | `JNZ 0x10017b48` |
| `10017b1c` | `e8 e8 d5 ff ff` | `CALL 0x10015109` |
| `10017b21` | `57` | `PUSH EDI` |
| `10017b22` | `57` | `PUSH EDI` |
| `10017b23` | `57` | `PUSH EDI` |
| `10017b24` | `57` | `PUSH EDI` |
| `10017b25` | `57` | `PUSH EDI` |
| `10017b26` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10017b2c` | `e8 7e 9b ff ff` | `CALL 0x100116af` |
| `10017b31` | `83 c4 14` | `ADD ESP,0x14` |
| `10017b34` | `80 7d f8 00` | `CMP byte ptr [EBP + -0x8],0x0` |
| `10017b38` | `74 07` | `JZ 0x10017b41` |
| `10017b3a` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10017b3d` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10017b41` | `33 c0` | `XOR EAX,EAX` |
| `10017b43` | `e9 d8 01 00 00` | `JMP 0x10017d20` |
| `10017b48` | `39 7d 14` | `CMP dword ptr [EBP + 0x14],EDI` |
| `10017b4b` | `74 0c` | `JZ 0x10017b59` |
| `10017b4d` | `83 7d 14 02` | `CMP dword ptr [EBP + 0x14],0x2` |
| `10017b51` | `7c c9` | `JL 0x10017b1c` |
| `10017b53` | `83 7d 14 24` | `CMP dword ptr [EBP + 0x14],0x24` |
| `10017b57` | `7f c3` | `JG 0x10017b1c` |
| `10017b59` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `10017b5c` | `53` | `PUSH EBX` |
| `10017b5d` | `8a 1e` | `MOV BL,byte ptr [ESI]` |
| `10017b5f` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10017b62` | `8d 7e 01` | `LEA EDI,[ESI + 0x1]` |
| `10017b65` | `83 b9 ac 00 00 00 01` | `CMP dword ptr [ECX + 0xac],0x1` |
| `10017b6c` | `7e 17` | `JLE 0x10017b85` |
| `10017b6e` | `8d 45 ec` | `LEA EAX,[EBP + -0x14]` |
| `10017b71` | `50` | `PUSH EAX` |
| `10017b72` | `0f b6 c3` | `MOVZX EAX,BL` |
| `10017b75` | `6a 08` | `PUSH 0x8` |
| `10017b77` | `50` | `PUSH EAX` |
| `10017b78` | `e8 97 50 00 00` | `CALL 0x1001cc14` |
| `10017b7d` | `8b 4d ec` | `MOV ECX,dword ptr [EBP + -0x14]` |
| `10017b80` | `83 c4 0c` | `ADD ESP,0xc` |
| `10017b83` | `eb 10` | `JMP 0x10017b95` |
| `10017b85` | `8b 91 c8 00 00 00` | `MOV EDX,dword ptr [ECX + 0xc8]` |
| `10017b8b` | `0f b6 c3` | `MOVZX EAX,BL` |
| `10017b8e` | `0f b7 04 42` | `MOVZX EAX,word ptr [EDX + EAX*0x2]` |
| `10017b92` | `83 e0 08` | `AND EAX,0x8` |
| `10017b95` | `85 c0` | `TEST EAX,EAX` |
| `10017b97` | `74 05` | `JZ 0x10017b9e` |
| `10017b99` | `8a 1f` | `MOV BL,byte ptr [EDI]` |
| `10017b9b` | `47` | `INC EDI` |
| `10017b9c` | `eb c7` | `JMP 0x10017b65` |
| `10017b9e` | `80 fb 2d` | `CMP BL,0x2d` |
| `10017ba1` | `75 06` | `JNZ 0x10017ba9` |
| `10017ba3` | `83 4d 18 02` | `OR dword ptr [EBP + 0x18],0x2` |
| `10017ba7` | `eb 05` | `JMP 0x10017bae` |
| `10017ba9` | `80 fb 2b` | `CMP BL,0x2b` |
| `10017bac` | `75 03` | `JNZ 0x10017bb1` |
| `10017bae` | `8a 1f` | `MOV BL,byte ptr [EDI]` |
| `10017bb0` | `47` | `INC EDI` |
| `10017bb1` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10017bb4` | `85 c0` | `TEST EAX,EAX` |
| `10017bb6` | `0f 8c 4b 01 00 00` | `JL 0x10017d07` |
| `10017bbc` | `83 f8 01` | `CMP EAX,0x1` |
| `10017bbf` | `0f 84 42 01 00 00` | `JZ 0x10017d07` |
| `10017bc5` | `83 f8 24` | `CMP EAX,0x24` |
| `10017bc8` | `0f 8f 39 01 00 00` | `JG 0x10017d07` |
| `10017bce` | `85 c0` | `TEST EAX,EAX` |
| `10017bd0` | `75 2a` | `JNZ 0x10017bfc` |
| `10017bd2` | `80 fb 30` | `CMP BL,0x30` |
| `10017bd5` | `74 09` | `JZ 0x10017be0` |
| `10017bd7` | `c7 45 14 0a 00 00 00` | `MOV dword ptr [EBP + 0x14],0xa` |
| `10017bde` | `eb 34` | `JMP 0x10017c14` |
| `10017be0` | `8a 07` | `MOV AL,byte ptr [EDI]` |
| `10017be2` | `3c 78` | `CMP AL,0x78` |
| `10017be4` | `74 0d` | `JZ 0x10017bf3` |
| `10017be6` | `3c 58` | `CMP AL,0x58` |
| `10017be8` | `74 09` | `JZ 0x10017bf3` |
| `10017bea` | `c7 45 14 08 00 00 00` | `MOV dword ptr [EBP + 0x14],0x8` |
| `10017bf1` | `eb 21` | `JMP 0x10017c14` |
| `10017bf3` | `c7 45 14 10 00 00 00` | `MOV dword ptr [EBP + 0x14],0x10` |
| `10017bfa` | `eb 0a` | `JMP 0x10017c06` |
| `10017bfc` | `83 f8 10` | `CMP EAX,0x10` |
| `10017bff` | `75 13` | `JNZ 0x10017c14` |
| `10017c01` | `80 fb 30` | `CMP BL,0x30` |
| `10017c04` | `75 0e` | `JNZ 0x10017c14` |
| `10017c06` | `8a 07` | `MOV AL,byte ptr [EDI]` |
| `10017c08` | `3c 78` | `CMP AL,0x78` |
| `10017c0a` | `74 04` | `JZ 0x10017c10` |
| `10017c0c` | `3c 58` | `CMP AL,0x58` |
| `10017c0e` | `75 04` | `JNZ 0x10017c14` |
| `10017c10` | `47` | `INC EDI` |
| `10017c11` | `8a 1f` | `MOV BL,byte ptr [EDI]` |
| `10017c13` | `47` | `INC EDI` |
| `10017c14` | `8b b1 c8 00 00 00` | `MOV ESI,dword ptr [ECX + 0xc8]` |
| `10017c1a` | `b8 ff ff ff ff` | `MOV EAX,0xffffffff` |
| `10017c1f` | `33 d2` | `XOR EDX,EDX` |
| `10017c21` | `f7 75 14` | `DIV dword ptr [EBP + 0x14]` |
| `10017c24` | `0f b6 cb` | `MOVZX ECX,BL` |
| `10017c27` | `0f b7 0c 4e` | `MOVZX ECX,word ptr [ESI + ECX*0x2]` |
| `10017c2b` | `f6 c1 04` | `TEST CL,0x4` |
| `10017c2e` | `74 08` | `JZ 0x10017c38` |
| `10017c30` | `0f be cb` | `MOVSX ECX,BL` |
| `10017c33` | `83 e9 30` | `SUB ECX,0x30` |
| `10017c36` | `eb 1b` | `JMP 0x10017c53` |
| `10017c38` | `f7 c1 03 01 00 00` | `TEST ECX,0x103` |
| `10017c3e` | `74 31` | `JZ 0x10017c71` |
| `10017c40` | `8a cb` | `MOV CL,BL` |
| `10017c42` | `80 e9 61` | `SUB CL,0x61` |
| `10017c45` | `80 f9 19` | `CMP CL,0x19` |
| `10017c48` | `0f be cb` | `MOVSX ECX,BL` |
| `10017c4b` | `77 03` | `JA 0x10017c50` |
| `10017c4d` | `83 e9 20` | `SUB ECX,0x20` |
| `10017c50` | `83 c1 c9` | `ADD ECX,-0x37` |
| `10017c53` | `3b 4d 14` | `CMP ECX,dword ptr [EBP + 0x14]` |
| `10017c56` | `73 19` | `JNC 0x10017c71` |
| `10017c58` | `83 4d 18 08` | `OR dword ptr [EBP + 0x18],0x8` |
| `10017c5c` | `39 45 fc` | `CMP dword ptr [EBP + -0x4],EAX` |
| `10017c5f` | `72 27` | `JC 0x10017c88` |
| `10017c61` | `75 04` | `JNZ 0x10017c67` |
| `10017c63` | `3b ca` | `CMP ECX,EDX` |
| `10017c65` | `76 21` | `JBE 0x10017c88` |
| `10017c67` | `83 4d 18 04` | `OR dword ptr [EBP + 0x18],0x4` |
| `10017c6b` | `83 7d 10 00` | `CMP dword ptr [EBP + 0x10],0x0` |
| `10017c6f` | `75 23` | `JNZ 0x10017c94` |
| `10017c71` | `8b 45 18` | `MOV EAX,dword ptr [EBP + 0x18]` |
| `10017c74` | `4f` | `DEC EDI` |
| `10017c75` | `a8 08` | `TEST AL,0x8` |
| `10017c77` | `75 20` | `JNZ 0x10017c99` |
| `10017c79` | `83 7d 10 00` | `CMP dword ptr [EBP + 0x10],0x0` |
| `10017c7d` | `74 03` | `JZ 0x10017c82` |
| `10017c7f` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `10017c82` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10017c86` | `eb 5b` | `JMP 0x10017ce3` |
| `10017c88` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `10017c8b` | `0f af 5d 14` | `IMUL EBX,dword ptr [EBP + 0x14]` |
| `10017c8f` | `03 d9` | `ADD EBX,ECX` |
| `10017c91` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `10017c94` | `8a 1f` | `MOV BL,byte ptr [EDI]` |
| `10017c96` | `47` | `INC EDI` |
| `10017c97` | `eb 8b` | `JMP 0x10017c24` |
| `10017c99` | `be ff ff ff 7f` | `MOV ESI,0x7fffffff` |
| `10017c9e` | `a8 04` | `TEST AL,0x4` |
| `10017ca0` | `75 1b` | `JNZ 0x10017cbd` |
| `10017ca2` | `a8 01` | `TEST AL,0x1` |
| `10017ca4` | `75 3d` | `JNZ 0x10017ce3` |
| `10017ca6` | `83 e0 02` | `AND EAX,0x2` |
| `10017ca9` | `74 09` | `JZ 0x10017cb4` |
| `10017cab` | `81 7d fc 00 00 00 80` | `CMP dword ptr [EBP + -0x4],0x80000000` |
| `10017cb2` | `77 09` | `JA 0x10017cbd` |
| `10017cb4` | `85 c0` | `TEST EAX,EAX` |
| `10017cb6` | `75 2b` | `JNZ 0x10017ce3` |
| `10017cb8` | `39 75 fc` | `CMP dword ptr [EBP + -0x4],ESI` |
| `10017cbb` | `76 26` | `JBE 0x10017ce3` |
| `10017cbd` | `e8 47 d4 ff ff` | `CALL 0x10015109` |
| `10017cc2` | `f6 45 18 01` | `TEST byte ptr [EBP + 0x18],0x1` |
| `10017cc6` | `c7 00 22 00 00 00` | `MOV dword ptr [EAX],0x22` |
| `10017ccc` | `74 06` | `JZ 0x10017cd4` |
| `10017cce` | `83 4d fc ff` | `OR dword ptr [EBP + -0x4],0xffffffff` |
| `10017cd2` | `eb 0f` | `JMP 0x10017ce3` |
| `10017cd4` | `f6 45 18 02` | `TEST byte ptr [EBP + 0x18],0x2` |
| `10017cd8` | `6a 00` | `PUSH 0x0` |
| `10017cda` | `58` | `POP EAX` |
| `10017cdb` | `0f 95 c0` | `SETNZ AL` |
| `10017cde` | `03 c6` | `ADD EAX,ESI` |
| `10017ce0` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10017ce3` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10017ce6` | `85 c0` | `TEST EAX,EAX` |
| `10017ce8` | `74 02` | `JZ 0x10017cec` |
| `10017cea` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `10017cec` | `f6 45 18 02` | `TEST byte ptr [EBP + 0x18],0x2` |
| `10017cf0` | `74 03` | `JZ 0x10017cf5` |
| `10017cf2` | `f7 5d fc` | `NEG dword ptr [EBP + -0x4]` |
| `10017cf5` | `80 7d f8 00` | `CMP byte ptr [EBP + -0x8],0x0` |
| `10017cf9` | `74 07` | `JZ 0x10017d02` |
| `10017cfb` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10017cfe` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10017d02` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10017d05` | `eb 18` | `JMP 0x10017d1f` |
| `10017d07` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10017d0a` | `85 c0` | `TEST EAX,EAX` |
| `10017d0c` | `74 02` | `JZ 0x10017d10` |
| `10017d0e` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10017d10` | `80 7d f8 00` | `CMP byte ptr [EBP + -0x8],0x0` |
| `10017d14` | `74 07` | `JZ 0x10017d1d` |
| `10017d16` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10017d19` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `10017d1d` | `33 c0` | `XOR EAX,EAX` |
| `10017d1f` | `5b` | `POP EBX` |
| `10017d20` | `5f` | `POP EDI` |
| `10017d21` | `5e` | `POP ESI` |
| `10017d22` | `c9` | `LEAVE` |
| `10017d23` | `c3` | `RET` |
