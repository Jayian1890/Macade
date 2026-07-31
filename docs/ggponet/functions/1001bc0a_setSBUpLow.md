# 1001bc0a `setSBUpLow`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bc0a |
| `name` | setSBUpLow |
| `namespace` | Global |
| `signature` | void __cdecl setSBUpLow(threadmbcinfostruct * param_1) |
| `size_bytes` | 403 |
| `stack_frame_size` | 1320 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?setSBUpLow@@YAXPAUthreadmbcinfostruct@@@Z, setSBUpLow |

## Decompiled C

```c

/* Library Function - Single Match
    void __cdecl setSBUpLow(struct threadmbcinfostruct *)
   
   Library: Visual Studio 2008 Release */

void __cdecl setSBUpLow(threadmbcinfostruct *param_1)

{
  byte *pbVar1;
  char *pcVar2;
  BOOL BVar3;
  uint uVar4;
  CHAR CVar5;
  char cVar6;
  BYTE *pBVar7;
  int unaff_ESI;
  _cpinfo local_51c;
  WORD local_508 [256];
  CHAR local_308 [256];
  CHAR local_208 [256];
  CHAR local_108 [256];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  BVar3 = GetCPInfo(*(UINT *)(unaff_ESI + 4),&local_51c);
  if (BVar3 == 0) {
    uVar4 = 0;
    do {
      pcVar2 = (char *)(unaff_ESI + 0x11d + uVar4);
      if (pcVar2 + (-0x61 - (unaff_ESI + 0x11d)) + 0x20 < (char *)0x1a) {
        pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
        *pbVar1 = *pbVar1 | 0x10;
        cVar6 = (char)uVar4 + ' ';
LAB_1001bd83:
        *pcVar2 = cVar6;
      }
      else {
        if (pcVar2 + (-0x61 - (unaff_ESI + 0x11d)) < (char *)0x1a) {
          pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
          *pbVar1 = *pbVar1 | 0x20;
          cVar6 = (char)uVar4 + -0x20;
          goto LAB_1001bd83;
        }
        *pcVar2 = '\0';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
  }
  else {
    uVar4 = 0;
    do {
      local_108[uVar4] = (CHAR)uVar4;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    local_108[0] = ' ';
    if (local_51c.LeadByte[0] != 0) {
      pBVar7 = local_51c.LeadByte + 1;
      do {
        uVar4 = (uint)local_51c.LeadByte[0];
        if (uVar4 <= *pBVar7) {
          _memset(local_108 + uVar4,0x20,(*pBVar7 - uVar4) + 1);
        }
        local_51c.LeadByte[0] = pBVar7[1];
        pBVar7 = pBVar7 + 2;
      } while (local_51c.LeadByte[0] != 0);
    }
    ___crtGetStringTypeA
              ((_locale_t)0x0,1,local_108,0x100,local_508,*(int *)(unaff_ESI + 4),
               *(BOOL *)(unaff_ESI + 0xc));
    ___crtLCMapStringA((_locale_t)0x0,*(LPCWSTR *)(unaff_ESI + 0xc),0x100,local_108,0x100,local_208,
                       0x100,*(int *)(unaff_ESI + 4),0);
    ___crtLCMapStringA((_locale_t)0x0,*(LPCWSTR *)(unaff_ESI + 0xc),0x200,local_108,0x100,local_308,
                       0x100,*(int *)(unaff_ESI + 4),0);
    uVar4 = 0;
    do {
      if ((local_508[uVar4] & 1) == 0) {
        if ((local_508[uVar4] & 2) != 0) {
          pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
          *pbVar1 = *pbVar1 | 0x20;
          CVar5 = local_308[uVar4];
          goto LAB_1001bd21;
        }
        *(undefined1 *)(unaff_ESI + 0x11d + uVar4) = 0;
      }
      else {
        pbVar1 = (byte *)(unaff_ESI + 0x1d + uVar4);
        *pbVar1 = *pbVar1 | 0x10;
        CVar5 = local_208[uVar4];
LAB_1001bd21:
        *(CHAR *)(unaff_ESI + 0x11d + uVar4) = CVar5;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bc2b` | `EXTERNAL:00000060` | `COMPUTED_CALL` | KERNEL32.DLL::GetCPInfo | `` |
| `1001bc7b` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001bca6` | `1001ef17` | `UNCONDITIONAL_CALL` | ___crtGetStringTypeA | `1001ef17` |
| `1001bcc6` | `1001ed18` | `UNCONDITIONAL_CALL` | ___crtLCMapStringA | `1001ed18` |
| `1001bceb` | `1001ed18` | `UNCONDITIONAL_CALL` | ___crtLCMapStringA | `1001ed18` |
| `1001bd96` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001c02e` | __setmbcp_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bc15` | `10037490` | `READ` | DAT_10037490 |
| `1001bc2b` | `1002e138` | `READ` | PTR_GetCPInfo_1002e138 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bc0a` | `8b ff` | `MOV EDI,EDI` |
| `1001bc0c` | `55` | `PUSH EBP` |
| `1001bc0d` | `8b ec` | `MOV EBP,ESP` |
| `1001bc0f` | `81 ec 1c 05 00 00` | `SUB ESP,0x51c` |
| `1001bc15` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001bc1a` | `33 c5` | `XOR EAX,EBP` |
| `1001bc1c` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001bc1f` | `53` | `PUSH EBX` |
| `1001bc20` | `57` | `PUSH EDI` |
| `1001bc21` | `8d 85 e8 fa ff ff` | `LEA EAX,[EBP + 0xfffffae8]` |
| `1001bc27` | `50` | `PUSH EAX` |
| `1001bc28` | `ff 76 04` | `PUSH dword ptr [ESI + 0x4]` |
| `1001bc2b` | `ff 15 38 e1 02 10` | `CALL dword ptr [0x1002e138]` |
| `1001bc31` | `bf 00 01 00 00` | `MOV EDI,0x100` |
| `1001bc36` | `85 c0` | `TEST EAX,EAX` |
| `1001bc38` | `0f 84 fb 00 00 00` | `JZ 0x1001bd39` |
| `1001bc3e` | `33 c0` | `XOR EAX,EAX` |
| `1001bc40` | `88 84 05 fc fe ff ff` | `MOV byte ptr [EBP + EAX*0x1 + 0xfffffefc],AL` |
| `1001bc47` | `40` | `INC EAX` |
| `1001bc48` | `3b c7` | `CMP EAX,EDI` |
| `1001bc4a` | `72 f4` | `JC 0x1001bc40` |
| `1001bc4c` | `8a 85 ee fa ff ff` | `MOV AL,byte ptr [EBP + 0xfffffaee]` |
| `1001bc52` | `c6 85 fc fe ff ff 20` | `MOV byte ptr [EBP + 0xfffffefc],0x20` |
| `1001bc59` | `84 c0` | `TEST AL,AL` |
| `1001bc5b` | `74 2e` | `JZ 0x1001bc8b` |
| `1001bc5d` | `8d 9d ef fa ff ff` | `LEA EBX,[EBP + 0xfffffaef]` |
| `1001bc63` | `0f b6 c8` | `MOVZX ECX,AL` |
| `1001bc66` | `0f b6 03` | `MOVZX EAX,byte ptr [EBX]` |
| `1001bc69` | `3b c8` | `CMP ECX,EAX` |
| `1001bc6b` | `77 16` | `JA 0x1001bc83` |
| `1001bc6d` | `2b c1` | `SUB EAX,ECX` |
| `1001bc6f` | `40` | `INC EAX` |
| `1001bc70` | `50` | `PUSH EAX` |
| `1001bc71` | `8d 94 0d fc fe ff ff` | `LEA EDX,[EBP + ECX*0x1 + 0xfffffefc]` |
| `1001bc78` | `6a 20` | `PUSH 0x20` |
| `1001bc7a` | `52` | `PUSH EDX` |
| `1001bc7b` | `e8 70 5a ff ff` | `CALL 0x100116f0` |
| `1001bc80` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001bc83` | `43` | `INC EBX` |
| `1001bc84` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `1001bc86` | `43` | `INC EBX` |
| `1001bc87` | `84 c0` | `TEST AL,AL` |
| `1001bc89` | `75 d8` | `JNZ 0x1001bc63` |
| `1001bc8b` | `6a 00` | `PUSH 0x0` |
| `1001bc8d` | `ff 76 0c` | `PUSH dword ptr [ESI + 0xc]` |
| `1001bc90` | `8d 85 fc fa ff ff` | `LEA EAX,[EBP + 0xfffffafc]` |
| `1001bc96` | `ff 76 04` | `PUSH dword ptr [ESI + 0x4]` |
| `1001bc99` | `50` | `PUSH EAX` |
| `1001bc9a` | `57` | `PUSH EDI` |
| `1001bc9b` | `8d 85 fc fe ff ff` | `LEA EAX,[EBP + 0xfffffefc]` |
| `1001bca1` | `50` | `PUSH EAX` |
| `1001bca2` | `6a 01` | `PUSH 0x1` |
| `1001bca4` | `6a 00` | `PUSH 0x0` |
| `1001bca6` | `e8 6c 32 00 00` | `CALL 0x1001ef17` |
| `1001bcab` | `33 db` | `XOR EBX,EBX` |
| `1001bcad` | `53` | `PUSH EBX` |
| `1001bcae` | `ff 76 04` | `PUSH dword ptr [ESI + 0x4]` |
| `1001bcb1` | `8d 85 fc fd ff ff` | `LEA EAX,[EBP + 0xfffffdfc]` |
| `1001bcb7` | `57` | `PUSH EDI` |
| `1001bcb8` | `50` | `PUSH EAX` |
| `1001bcb9` | `57` | `PUSH EDI` |
| `1001bcba` | `8d 85 fc fe ff ff` | `LEA EAX,[EBP + 0xfffffefc]` |
| `1001bcc0` | `50` | `PUSH EAX` |
| `1001bcc1` | `57` | `PUSH EDI` |
| `1001bcc2` | `ff 76 0c` | `PUSH dword ptr [ESI + 0xc]` |
| `1001bcc5` | `53` | `PUSH EBX` |
| `1001bcc6` | `e8 4d 30 00 00` | `CALL 0x1001ed18` |
| `1001bccb` | `83 c4 44` | `ADD ESP,0x44` |
| `1001bcce` | `53` | `PUSH EBX` |
| `1001bccf` | `ff 76 04` | `PUSH dword ptr [ESI + 0x4]` |
| `1001bcd2` | `8d 85 fc fc ff ff` | `LEA EAX,[EBP + 0xfffffcfc]` |
| `1001bcd8` | `57` | `PUSH EDI` |
| `1001bcd9` | `50` | `PUSH EAX` |
| `1001bcda` | `57` | `PUSH EDI` |
| `1001bcdb` | `8d 85 fc fe ff ff` | `LEA EAX,[EBP + 0xfffffefc]` |
| `1001bce1` | `50` | `PUSH EAX` |
| `1001bce2` | `68 00 02 00 00` | `PUSH 0x200` |
| `1001bce7` | `ff 76 0c` | `PUSH dword ptr [ESI + 0xc]` |
| `1001bcea` | `53` | `PUSH EBX` |
| `1001bceb` | `e8 28 30 00 00` | `CALL 0x1001ed18` |
| `1001bcf0` | `83 c4 24` | `ADD ESP,0x24` |
| `1001bcf3` | `33 c0` | `XOR EAX,EAX` |
| `1001bcf5` | `0f b7 8c 45 fc fa ff ff` | `MOVZX ECX,word ptr [EBP + EAX*0x2 + 0xfffffafc]` |
| `1001bcfd` | `f6 c1 01` | `TEST CL,0x1` |
| `1001bd00` | `74 0e` | `JZ 0x1001bd10` |
| `1001bd02` | `80 4c 06 1d 10` | `OR byte ptr [ESI + EAX*0x1 + 0x1d],0x10` |
| `1001bd07` | `8a 8c 05 fc fd ff ff` | `MOV CL,byte ptr [EBP + EAX*0x1 + 0xfffffdfc]` |
| `1001bd0e` | `eb 11` | `JMP 0x1001bd21` |
| `1001bd10` | `f6 c1 02` | `TEST CL,0x2` |
| `1001bd13` | `74 15` | `JZ 0x1001bd2a` |
| `1001bd15` | `80 4c 06 1d 20` | `OR byte ptr [ESI + EAX*0x1 + 0x1d],0x20` |
| `1001bd1a` | `8a 8c 05 fc fc ff ff` | `MOV CL,byte ptr [EBP + EAX*0x1 + 0xfffffcfc]` |
| `1001bd21` | `88 8c 06 1d 01 00 00` | `MOV byte ptr [ESI + EAX*0x1 + 0x11d],CL` |
| `1001bd28` | `eb 08` | `JMP 0x1001bd32` |
| `1001bd2a` | `c6 84 06 1d 01 00 00 00` | `MOV byte ptr [ESI + EAX*0x1 + 0x11d],0x0` |
| `1001bd32` | `40` | `INC EAX` |
| `1001bd33` | `3b c7` | `CMP EAX,EDI` |
| `1001bd35` | `72 be` | `JC 0x1001bcf5` |
| `1001bd37` | `eb 56` | `JMP 0x1001bd8f` |
| `1001bd39` | `8d 86 1d 01 00 00` | `LEA EAX,[ESI + 0x11d]` |
| `1001bd3f` | `c7 85 e4 fa ff ff 9f ff ff ff` | `MOV dword ptr [EBP + 0xfffffae4],0xffffff9f` |
| `1001bd49` | `33 c9` | `XOR ECX,ECX` |
| `1001bd4b` | `29 85 e4 fa ff ff` | `SUB dword ptr [EBP + 0xfffffae4],EAX` |
| `1001bd51` | `8b 95 e4 fa ff ff` | `MOV EDX,dword ptr [EBP + 0xfffffae4]` |
| `1001bd57` | `8d 84 0e 1d 01 00 00` | `LEA EAX,[ESI + ECX*0x1 + 0x11d]` |
| `1001bd5e` | `03 d0` | `ADD EDX,EAX` |
| `1001bd60` | `8d 5a 20` | `LEA EBX,[EDX + 0x20]` |
| `1001bd63` | `83 fb 19` | `CMP EBX,0x19` |
| `1001bd66` | `77 0c` | `JA 0x1001bd74` |
| `1001bd68` | `80 4c 0e 1d 10` | `OR byte ptr [ESI + ECX*0x1 + 0x1d],0x10` |
| `1001bd6d` | `8a d1` | `MOV DL,CL` |
| `1001bd6f` | `80 c2 20` | `ADD DL,0x20` |
| `1001bd72` | `eb 0f` | `JMP 0x1001bd83` |
| `1001bd74` | `83 fa 19` | `CMP EDX,0x19` |
| `1001bd77` | `77 0e` | `JA 0x1001bd87` |
| `1001bd79` | `80 4c 0e 1d 20` | `OR byte ptr [ESI + ECX*0x1 + 0x1d],0x20` |
| `1001bd7e` | `8a d1` | `MOV DL,CL` |
| `1001bd80` | `80 ea 20` | `SUB DL,0x20` |
| `1001bd83` | `88 10` | `MOV byte ptr [EAX],DL` |
| `1001bd85` | `eb 03` | `JMP 0x1001bd8a` |
| `1001bd87` | `c6 00 00` | `MOV byte ptr [EAX],0x0` |
| `1001bd8a` | `41` | `INC ECX` |
| `1001bd8b` | `3b cf` | `CMP ECX,EDI` |
| `1001bd8d` | `72 c2` | `JC 0x1001bd51` |
| `1001bd8f` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001bd92` | `5f` | `POP EDI` |
| `1001bd93` | `33 cd` | `XOR ECX,EBP` |
| `1001bd95` | `5b` | `POP EBX` |
| `1001bd96` | `e8 30 4f ff ff` | `CALL 0x10010ccb` |
| `1001bd9b` | `c9` | `LEAVE` |
| `1001bd9c` | `c3` | `RET` |
