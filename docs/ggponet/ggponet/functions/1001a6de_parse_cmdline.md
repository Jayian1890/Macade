# 1001a6de `parse_cmdline`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a6de |
| `name` | parse_cmdline |
| `namespace` | Global |
| `signature` | undefined __cdecl parse_cmdline(void) |
| `size_bytes` | 410 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _parse_cmdline, parse_cmdline |

## Decompiled C

```c

/* Library Function - Single Match
    _parse_cmdline
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl parse_cmdline(undefined4 *param_1,byte *param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  byte *in_EDX;
  byte *pbVar5;
  byte bVar6;
  byte *pbVar7;
  byte *pbVar8;
  int *unaff_EDI;
  
  *unaff_EDI = 0;
  *param_3 = 1;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = param_2;
    param_1 = param_1 + 1;
  }
  bVar2 = false;
  pbVar5 = param_2;
  do {
    if (*in_EDX == 0x22) {
      bVar2 = !bVar2;
      bVar6 = 0x22;
      pbVar7 = in_EDX + 1;
    }
    else {
      *unaff_EDI = *unaff_EDI + 1;
      if (pbVar5 != (byte *)0x0) {
        *pbVar5 = *in_EDX;
        param_2 = pbVar5 + 1;
      }
      bVar6 = *in_EDX;
      pbVar7 = in_EDX + 1;
      iVar3 = __ismbblead((uint)bVar6);
      if (iVar3 != 0) {
        *unaff_EDI = *unaff_EDI + 1;
        if (param_2 != (byte *)0x0) {
          *param_2 = *pbVar7;
          param_2 = param_2 + 1;
        }
        pbVar7 = in_EDX + 2;
      }
      pbVar5 = param_2;
      if (bVar6 == 0) {
        pbVar7 = pbVar7 + -1;
        goto LAB_1001a772;
      }
    }
    in_EDX = pbVar7;
  } while ((bVar2) || ((bVar6 != 0x20 && (bVar6 != 9))));
  if (pbVar5 != (byte *)0x0) {
    pbVar5[-1] = 0;
  }
LAB_1001a772:
  bVar2 = false;
  while (*pbVar7 != 0) {
    for (; (*pbVar7 == 0x20 || (*pbVar7 == 9)); pbVar7 = pbVar7 + 1) {
    }
    if (*pbVar7 == 0) break;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = pbVar5;
      param_1 = param_1 + 1;
    }
    *param_3 = *param_3 + 1;
    while( true ) {
      bVar1 = true;
      uVar4 = 0;
      for (; *pbVar7 == 0x5c; pbVar7 = pbVar7 + 1) {
        uVar4 = uVar4 + 1;
      }
      if (*pbVar7 == 0x22) {
        pbVar8 = pbVar7;
        if (((uVar4 & 1) == 0) && ((!bVar2 || (pbVar8 = pbVar7 + 1, *pbVar8 != 0x22)))) {
          bVar1 = false;
          bVar2 = !bVar2;
          pbVar8 = pbVar7;
        }
        uVar4 = uVar4 >> 1;
        pbVar7 = pbVar8;
      }
      while (uVar4 != 0) {
        uVar4 = uVar4 - 1;
        if (pbVar5 != (byte *)0x0) {
          *pbVar5 = 0x5c;
          pbVar5 = pbVar5 + 1;
        }
        *unaff_EDI = *unaff_EDI + 1;
        param_2 = pbVar5;
      }
      bVar6 = *pbVar7;
      if ((bVar6 == 0) || ((!bVar2 && ((bVar6 == 0x20 || (bVar6 == 9)))))) break;
      if (bVar1) {
        if (pbVar5 == (byte *)0x0) {
          iVar3 = __ismbblead((int)(char)bVar6);
          if (iVar3 != 0) {
            pbVar7 = pbVar7 + 1;
            *unaff_EDI = *unaff_EDI + 1;
          }
        }
        else {
          iVar3 = __ismbblead((int)(char)bVar6);
          if (iVar3 != 0) {
            *param_2 = *pbVar7;
            pbVar7 = pbVar7 + 1;
            *unaff_EDI = *unaff_EDI + 1;
            param_2 = param_2 + 1;
          }
          *param_2 = *pbVar7;
          param_2 = param_2 + 1;
        }
        *unaff_EDI = *unaff_EDI + 1;
        pbVar5 = param_2;
      }
      pbVar7 = pbVar7 + 1;
    }
    if (pbVar5 != (byte *)0x0) {
      *pbVar5 = 0;
      pbVar5 = pbVar5 + 1;
      param_2 = pbVar5;
    }
    *unaff_EDI = *unaff_EDI + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  *param_3 = *param_3 + 1;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a733` | `1001e949` | `UNCONDITIONAL_CALL` | __ismbblead | `1001e949` |
| `1001a818` | `1001e949` | `UNCONDITIONAL_CALL` | __ismbblead | `1001e949` |
| `1001a83b` | `1001e949` | `UNCONDITIONAL_CALL` | __ismbblead | `1001e949` |

## Callers

| From | Function |
| --- | --- |
| `1001a8cf` | __setargv |
| `1001a910` | __setargv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a6de` | `8b ff` | `MOV EDI,EDI` |
| `1001a6e0` | `55` | `PUSH EBP` |
| `1001a6e1` | `8b ec` | `MOV EBP,ESP` |
| `1001a6e3` | `51` | `PUSH ECX` |
| `1001a6e4` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001a6e7` | `53` | `PUSH EBX` |
| `1001a6e8` | `33 c0` | `XOR EAX,EAX` |
| `1001a6ea` | `56` | `PUSH ESI` |
| `1001a6eb` | `89 07` | `MOV dword ptr [EDI],EAX` |
| `1001a6ed` | `8b f2` | `MOV ESI,EDX` |
| `1001a6ef` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001a6f2` | `c7 01 01 00 00 00` | `MOV dword ptr [ECX],0x1` |
| `1001a6f8` | `39 45 08` | `CMP dword ptr [EBP + 0x8],EAX` |
| `1001a6fb` | `74 09` | `JZ 0x1001a706` |
| `1001a6fd` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1001a700` | `83 45 08 04` | `ADD dword ptr [EBP + 0x8],0x4` |
| `1001a704` | `89 13` | `MOV dword ptr [EBX],EDX` |
| `1001a706` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001a709` | `80 3e 22` | `CMP byte ptr [ESI],0x22` |
| `1001a70c` | `75 10` | `JNZ 0x1001a71e` |
| `1001a70e` | `33 c0` | `XOR EAX,EAX` |
| `1001a710` | `39 45 fc` | `CMP dword ptr [EBP + -0x4],EAX` |
| `1001a713` | `b3 22` | `MOV BL,0x22` |
| `1001a715` | `0f 94 c0` | `SETZ AL` |
| `1001a718` | `46` | `INC ESI` |
| `1001a719` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001a71c` | `eb 3c` | `JMP 0x1001a75a` |
| `1001a71e` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a720` | `85 d2` | `TEST EDX,EDX` |
| `1001a722` | `74 08` | `JZ 0x1001a72c` |
| `1001a724` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a726` | `88 02` | `MOV byte ptr [EDX],AL` |
| `1001a728` | `42` | `INC EDX` |
| `1001a729` | `89 55 0c` | `MOV dword ptr [EBP + 0xc],EDX` |
| `1001a72c` | `8a 1e` | `MOV BL,byte ptr [ESI]` |
| `1001a72e` | `0f b6 c3` | `MOVZX EAX,BL` |
| `1001a731` | `50` | `PUSH EAX` |
| `1001a732` | `46` | `INC ESI` |
| `1001a733` | `e8 11 42 00 00` | `CALL 0x1001e949` |
| `1001a738` | `59` | `POP ECX` |
| `1001a739` | `85 c0` | `TEST EAX,EAX` |
| `1001a73b` | `74 13` | `JZ 0x1001a750` |
| `1001a73d` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a73f` | `83 7d 0c 00` | `CMP dword ptr [EBP + 0xc],0x0` |
| `1001a743` | `74 0a` | `JZ 0x1001a74f` |
| `1001a745` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001a748` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a74a` | `ff 45 0c` | `INC dword ptr [EBP + 0xc]` |
| `1001a74d` | `88 01` | `MOV byte ptr [ECX],AL` |
| `1001a74f` | `46` | `INC ESI` |
| `1001a750` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001a753` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001a756` | `84 db` | `TEST BL,BL` |
| `1001a758` | `74 32` | `JZ 0x1001a78c` |
| `1001a75a` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `1001a75e` | `75 a9` | `JNZ 0x1001a709` |
| `1001a760` | `80 fb 20` | `CMP BL,0x20` |
| `1001a763` | `74 05` | `JZ 0x1001a76a` |
| `1001a765` | `80 fb 09` | `CMP BL,0x9` |
| `1001a768` | `75 9f` | `JNZ 0x1001a709` |
| `1001a76a` | `85 d2` | `TEST EDX,EDX` |
| `1001a76c` | `74 04` | `JZ 0x1001a772` |
| `1001a76e` | `c6 42 ff 00` | `MOV byte ptr [EDX + -0x1],0x0` |
| `1001a772` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001a776` | `80 3e 00` | `CMP byte ptr [ESI],0x0` |
| `1001a779` | `0f 84 e9 00 00 00` | `JZ 0x1001a868` |
| `1001a77f` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a781` | `3c 20` | `CMP AL,0x20` |
| `1001a783` | `74 04` | `JZ 0x1001a789` |
| `1001a785` | `3c 09` | `CMP AL,0x9` |
| `1001a787` | `75 06` | `JNZ 0x1001a78f` |
| `1001a789` | `46` | `INC ESI` |
| `1001a78a` | `eb f3` | `JMP 0x1001a77f` |
| `1001a78c` | `4e` | `DEC ESI` |
| `1001a78d` | `eb e3` | `JMP 0x1001a772` |
| `1001a78f` | `80 3e 00` | `CMP byte ptr [ESI],0x0` |
| `1001a792` | `0f 84 d0 00 00 00` | `JZ 0x1001a868` |
| `1001a798` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1001a79c` | `74 09` | `JZ 0x1001a7a7` |
| `1001a79e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001a7a1` | `83 45 08 04` | `ADD dword ptr [EBP + 0x8],0x4` |
| `1001a7a5` | `89 10` | `MOV dword ptr [EAX],EDX` |
| `1001a7a7` | `ff 01` | `INC dword ptr [ECX]` |
| `1001a7a9` | `33 db` | `XOR EBX,EBX` |
| `1001a7ab` | `43` | `INC EBX` |
| `1001a7ac` | `33 c9` | `XOR ECX,ECX` |
| `1001a7ae` | `eb 02` | `JMP 0x1001a7b2` |
| `1001a7b0` | `46` | `INC ESI` |
| `1001a7b1` | `41` | `INC ECX` |
| `1001a7b2` | `80 3e 5c` | `CMP byte ptr [ESI],0x5c` |
| `1001a7b5` | `74 f9` | `JZ 0x1001a7b0` |
| `1001a7b7` | `80 3e 22` | `CMP byte ptr [ESI],0x22` |
| `1001a7ba` | `75 26` | `JNZ 0x1001a7e2` |
| `1001a7bc` | `f6 c1 01` | `TEST CL,0x1` |
| `1001a7bf` | `75 1f` | `JNZ 0x1001a7e0` |
| `1001a7c1` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `1001a7c5` | `74 0c` | `JZ 0x1001a7d3` |
| `1001a7c7` | `8d 46 01` | `LEA EAX,[ESI + 0x1]` |
| `1001a7ca` | `80 38 22` | `CMP byte ptr [EAX],0x22` |
| `1001a7cd` | `75 04` | `JNZ 0x1001a7d3` |
| `1001a7cf` | `8b f0` | `MOV ESI,EAX` |
| `1001a7d1` | `eb 0d` | `JMP 0x1001a7e0` |
| `1001a7d3` | `33 c0` | `XOR EAX,EAX` |
| `1001a7d5` | `33 db` | `XOR EBX,EBX` |
| `1001a7d7` | `39 45 fc` | `CMP dword ptr [EBP + -0x4],EAX` |
| `1001a7da` | `0f 94 c0` | `SETZ AL` |
| `1001a7dd` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001a7e0` | `d1 e9` | `SHR ECX,0x1` |
| `1001a7e2` | `85 c9` | `TEST ECX,ECX` |
| `1001a7e4` | `74 12` | `JZ 0x1001a7f8` |
| `1001a7e6` | `49` | `DEC ECX` |
| `1001a7e7` | `85 d2` | `TEST EDX,EDX` |
| `1001a7e9` | `74 04` | `JZ 0x1001a7ef` |
| `1001a7eb` | `c6 02 5c` | `MOV byte ptr [EDX],0x5c` |
| `1001a7ee` | `42` | `INC EDX` |
| `1001a7ef` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a7f1` | `85 c9` | `TEST ECX,ECX` |
| `1001a7f3` | `75 f1` | `JNZ 0x1001a7e6` |
| `1001a7f5` | `89 55 0c` | `MOV dword ptr [EBP + 0xc],EDX` |
| `1001a7f8` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a7fa` | `84 c0` | `TEST AL,AL` |
| `1001a7fc` | `74 55` | `JZ 0x1001a853` |
| `1001a7fe` | `83 7d fc 00` | `CMP dword ptr [EBP + -0x4],0x0` |
| `1001a802` | `75 08` | `JNZ 0x1001a80c` |
| `1001a804` | `3c 20` | `CMP AL,0x20` |
| `1001a806` | `74 4b` | `JZ 0x1001a853` |
| `1001a808` | `3c 09` | `CMP AL,0x9` |
| `1001a80a` | `74 47` | `JZ 0x1001a853` |
| `1001a80c` | `85 db` | `TEST EBX,EBX` |
| `1001a80e` | `74 3d` | `JZ 0x1001a84d` |
| `1001a810` | `0f be c0` | `MOVSX EAX,AL` |
| `1001a813` | `50` | `PUSH EAX` |
| `1001a814` | `85 d2` | `TEST EDX,EDX` |
| `1001a816` | `74 23` | `JZ 0x1001a83b` |
| `1001a818` | `e8 2c 41 00 00` | `CALL 0x1001e949` |
| `1001a81d` | `59` | `POP ECX` |
| `1001a81e` | `85 c0` | `TEST EAX,EAX` |
| `1001a820` | `74 0d` | `JZ 0x1001a82f` |
| `1001a822` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a824` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001a827` | `ff 45 0c` | `INC dword ptr [EBP + 0xc]` |
| `1001a82a` | `88 01` | `MOV byte ptr [ECX],AL` |
| `1001a82c` | `46` | `INC ESI` |
| `1001a82d` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a82f` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001a832` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1001a834` | `ff 45 0c` | `INC dword ptr [EBP + 0xc]` |
| `1001a837` | `88 01` | `MOV byte ptr [ECX],AL` |
| `1001a839` | `eb 0d` | `JMP 0x1001a848` |
| `1001a83b` | `e8 09 41 00 00` | `CALL 0x1001e949` |
| `1001a840` | `59` | `POP ECX` |
| `1001a841` | `85 c0` | `TEST EAX,EAX` |
| `1001a843` | `74 03` | `JZ 0x1001a848` |
| `1001a845` | `46` | `INC ESI` |
| `1001a846` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a848` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a84a` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1001a84d` | `46` | `INC ESI` |
| `1001a84e` | `e9 56 ff ff ff` | `JMP 0x1001a7a9` |
| `1001a853` | `85 d2` | `TEST EDX,EDX` |
| `1001a855` | `74 07` | `JZ 0x1001a85e` |
| `1001a857` | `c6 02 00` | `MOV byte ptr [EDX],0x0` |
| `1001a85a` | `42` | `INC EDX` |
| `1001a85b` | `89 55 0c` | `MOV dword ptr [EBP + 0xc],EDX` |
| `1001a85e` | `ff 07` | `INC dword ptr [EDI]` |
| `1001a860` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001a863` | `e9 0e ff ff ff` | `JMP 0x1001a776` |
| `1001a868` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001a86b` | `5e` | `POP ESI` |
| `1001a86c` | `5b` | `POP EBX` |
| `1001a86d` | `85 c0` | `TEST EAX,EAX` |
| `1001a86f` | `74 03` | `JZ 0x1001a874` |
| `1001a871` | `83 20 00` | `AND dword ptr [EAX],0x0` |
| `1001a874` | `ff 01` | `INC dword ptr [ECX]` |
| `1001a876` | `c9` | `LEAVE` |
| `1001a877` | `c3` | `RET` |
