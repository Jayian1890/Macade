# 10019543 `__XcptFilter`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019543 |
| `name` | __XcptFilter |
| `namespace` | Global |
| `signature` | int __cdecl __XcptFilter(ulong _ExceptionNum, _EXCEPTION_POINTERS * _ExceptionPtr) |
| `size_bytes` | 352 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __XcptFilter |

## Decompiled C

```c

/* Library Function - Single Match
    __XcptFilter
   
   Library: Visual Studio 2008 Release */

int __cdecl __XcptFilter(ulong _ExceptionNum,_EXCEPTION_POINTERS *_ExceptionPtr)

{
  ulong *puVar1;
  code *pcVar2;
  void *pvVar3;
  ulong uVar4;
  _ptiddata p_Var5;
  ulong *puVar6;
  int iVar7;
  int iVar8;
  
  p_Var5 = __getptd_noexit();
  iVar7 = 0;
  if (p_Var5 != (_ptiddata)0x0) {
    puVar1 = p_Var5->_pxcptacttab;
    puVar6 = puVar1;
    do {
      if (*puVar6 == _ExceptionNum) break;
      puVar6 = puVar6 + 3;
    } while (puVar6 < puVar1 + DAT_10037bf4 * 3);
    if ((puVar1 + DAT_10037bf4 * 3 <= puVar6) || (*puVar6 != _ExceptionNum)) {
      puVar6 = (ulong *)0x0;
    }
    if ((puVar6 == (ulong *)0x0) || (pcVar2 = (code *)puVar6[2], pcVar2 == (code *)0x0)) {
      iVar7 = 0;
    }
    else if (pcVar2 == (code *)0x5) {
      puVar6[2] = 0;
      iVar7 = 1;
    }
    else {
      if (pcVar2 != (code *)0x1) {
        pvVar3 = p_Var5->_tpxcptinfoptrs;
        p_Var5->_tpxcptinfoptrs = _ExceptionPtr;
        if (puVar6[1] == 8) {
          if (DAT_10037be8 < DAT_10037bec + DAT_10037be8) {
            iVar8 = DAT_10037be8 * 0xc;
            iVar7 = DAT_10037be8;
            do {
              *(undefined4 *)(iVar8 + 8 + (int)p_Var5->_pxcptacttab) = 0;
              iVar7 = iVar7 + 1;
              iVar8 = iVar8 + 0xc;
            } while (iVar7 < DAT_10037bec + DAT_10037be8);
          }
          uVar4 = *puVar6;
          iVar7 = p_Var5->_tfpecode;
          if (uVar4 == 0xc000008e) {
            p_Var5->_tfpecode = 0x83;
          }
          else if (uVar4 == 0xc0000090) {
            p_Var5->_tfpecode = 0x81;
          }
          else if (uVar4 == 0xc0000091) {
            p_Var5->_tfpecode = 0x84;
          }
          else if (uVar4 == 0xc0000093) {
            p_Var5->_tfpecode = 0x85;
          }
          else if (uVar4 == 0xc000008d) {
            p_Var5->_tfpecode = 0x82;
          }
          else if (uVar4 == 0xc000008f) {
            p_Var5->_tfpecode = 0x86;
          }
          else if (uVar4 == 0xc0000092) {
            p_Var5->_tfpecode = 0x8a;
          }
          (*pcVar2)(8,p_Var5->_tfpecode);
          p_Var5->_tfpecode = iVar7;
        }
        else {
          puVar6[2] = 0;
          (*pcVar2)(puVar6[1]);
        }
        p_Var5->_tpxcptinfoptrs = pvVar3;
      }
      iVar7 = -1;
    }
  }
  return iVar7;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001954b` | `1001735d` | `UNCONDITIONAL_CALL` | __getptd_noexit | `1001735d` |

## Callers

| From | Function |
| --- | --- |
| `100196b6` | ___CppXcptFilter |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001955d` | `10037bf4` | `READ` | DAT_10037bf4 |
| `100195d5` | `10037be8` | `READ` | DAT_10037be8 |
| `100195db` | `10037bec` | `READ` | DAT_10037bec |
| `100195f4` | `10037be8` | `READ` | DAT_10037be8 |
| `100195fa` | `10037bec` | `READ` | DAT_10037bec |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019543` | `8b ff` | `MOV EDI,EDI` |
| `10019545` | `55` | `PUSH EBP` |
| `10019546` | `8b ec` | `MOV EBP,ESP` |
| `10019548` | `51` | `PUSH ECX` |
| `10019549` | `51` | `PUSH ECX` |
| `1001954a` | `56` | `PUSH ESI` |
| `1001954b` | `e8 0d de ff ff` | `CALL 0x1001735d` |
| `10019550` | `8b f0` | `MOV ESI,EAX` |
| `10019552` | `85 f6` | `TEST ESI,ESI` |
| `10019554` | `0f 84 46 01 00 00` | `JZ 0x100196a0` |
| `1001955a` | `8b 56 5c` | `MOV EDX,dword ptr [ESI + 0x5c]` |
| `1001955d` | `a1 f4 7b 03 10` | `MOV EAX,[0x10037bf4]` |
| `10019562` | `57` | `PUSH EDI` |
| `10019563` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10019566` | `8b ca` | `MOV ECX,EDX` |
| `10019568` | `53` | `PUSH EBX` |
| `10019569` | `39 39` | `CMP dword ptr [ECX],EDI` |
| `1001956b` | `74 0e` | `JZ 0x1001957b` |
| `1001956d` | `8b d8` | `MOV EBX,EAX` |
| `1001956f` | `6b db 0c` | `IMUL EBX,EBX,0xc` |
| `10019572` | `83 c1 0c` | `ADD ECX,0xc` |
| `10019575` | `03 da` | `ADD EBX,EDX` |
| `10019577` | `3b cb` | `CMP ECX,EBX` |
| `10019579` | `72 ee` | `JC 0x10019569` |
| `1001957b` | `6b c0 0c` | `IMUL EAX,EAX,0xc` |
| `1001957e` | `03 c2` | `ADD EAX,EDX` |
| `10019580` | `3b c8` | `CMP ECX,EAX` |
| `10019582` | `73 08` | `JNC 0x1001958c` |
| `10019584` | `39 39` | `CMP dword ptr [ECX],EDI` |
| `10019586` | `75 04` | `JNZ 0x1001958c` |
| `10019588` | `8b c1` | `MOV EAX,ECX` |
| `1001958a` | `eb 02` | `JMP 0x1001958e` |
| `1001958c` | `33 c0` | `XOR EAX,EAX` |
| `1001958e` | `85 c0` | `TEST EAX,EAX` |
| `10019590` | `74 0a` | `JZ 0x1001959c` |
| `10019592` | `8b 58 08` | `MOV EBX,dword ptr [EAX + 0x8]` |
| `10019595` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `10019598` | `85 db` | `TEST EBX,EBX` |
| `1001959a` | `75 07` | `JNZ 0x100195a3` |
| `1001959c` | `33 c0` | `XOR EAX,EAX` |
| `1001959e` | `e9 fb 00 00 00` | `JMP 0x1001969e` |
| `100195a3` | `83 fb 05` | `CMP EBX,0x5` |
| `100195a6` | `75 0c` | `JNZ 0x100195b4` |
| `100195a8` | `83 60 08 00` | `AND dword ptr [EAX + 0x8],0x0` |
| `100195ac` | `33 c0` | `XOR EAX,EAX` |
| `100195ae` | `40` | `INC EAX` |
| `100195af` | `e9 ea 00 00 00` | `JMP 0x1001969e` |
| `100195b4` | `83 fb 01` | `CMP EBX,0x1` |
| `100195b7` | `0f 84 de 00 00 00` | `JZ 0x1001969b` |
| `100195bd` | `8b 4e 60` | `MOV ECX,dword ptr [ESI + 0x60]` |
| `100195c0` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `100195c3` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `100195c6` | `89 4e 60` | `MOV dword ptr [ESI + 0x60],ECX` |
| `100195c9` | `8b 48 04` | `MOV ECX,dword ptr [EAX + 0x4]` |
| `100195cc` | `83 f9 08` | `CMP ECX,0x8` |
| `100195cf` | `0f 85 b8 00 00 00` | `JNZ 0x1001968d` |
| `100195d5` | `8b 0d e8 7b 03 10` | `MOV ECX,dword ptr [0x10037be8]` |
| `100195db` | `8b 3d ec 7b 03 10` | `MOV EDI,dword ptr [0x10037bec]` |
| `100195e1` | `8b d1` | `MOV EDX,ECX` |
| `100195e3` | `03 f9` | `ADD EDI,ECX` |
| `100195e5` | `3b d7` | `CMP EDX,EDI` |
| `100195e7` | `7d 24` | `JGE 0x1001960d` |
| `100195e9` | `6b c9 0c` | `IMUL ECX,ECX,0xc` |
| `100195ec` | `8b 7e 5c` | `MOV EDI,dword ptr [ESI + 0x5c]` |
| `100195ef` | `83 64 39 08 00` | `AND dword ptr [ECX + EDI*0x1 + 0x8],0x0` |
| `100195f4` | `8b 3d e8 7b 03 10` | `MOV EDI,dword ptr [0x10037be8]` |
| `100195fa` | `8b 1d ec 7b 03 10` | `MOV EBX,dword ptr [0x10037bec]` |
| `10019600` | `42` | `INC EDX` |
| `10019601` | `03 df` | `ADD EBX,EDI` |
| `10019603` | `83 c1 0c` | `ADD ECX,0xc` |
| `10019606` | `3b d3` | `CMP EDX,EBX` |
| `10019608` | `7c e2` | `JL 0x100195ec` |
| `1001960a` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `1001960d` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001960f` | `8b 7e 64` | `MOV EDI,dword ptr [ESI + 0x64]` |
| `10019612` | `3d 8e 00 00 c0` | `CMP EAX,0xc000008e` |
| `10019617` | `75 09` | `JNZ 0x10019622` |
| `10019619` | `c7 46 64 83 00 00 00` | `MOV dword ptr [ESI + 0x64],0x83` |
| `10019620` | `eb 5e` | `JMP 0x10019680` |
| `10019622` | `3d 90 00 00 c0` | `CMP EAX,0xc0000090` |
| `10019627` | `75 09` | `JNZ 0x10019632` |
| `10019629` | `c7 46 64 81 00 00 00` | `MOV dword ptr [ESI + 0x64],0x81` |
| `10019630` | `eb 4e` | `JMP 0x10019680` |
| `10019632` | `3d 91 00 00 c0` | `CMP EAX,0xc0000091` |
| `10019637` | `75 09` | `JNZ 0x10019642` |
| `10019639` | `c7 46 64 84 00 00 00` | `MOV dword ptr [ESI + 0x64],0x84` |
| `10019640` | `eb 3e` | `JMP 0x10019680` |
| `10019642` | `3d 93 00 00 c0` | `CMP EAX,0xc0000093` |
| `10019647` | `75 09` | `JNZ 0x10019652` |
| `10019649` | `c7 46 64 85 00 00 00` | `MOV dword ptr [ESI + 0x64],0x85` |
| `10019650` | `eb 2e` | `JMP 0x10019680` |
| `10019652` | `3d 8d 00 00 c0` | `CMP EAX,0xc000008d` |
| `10019657` | `75 09` | `JNZ 0x10019662` |
| `10019659` | `c7 46 64 82 00 00 00` | `MOV dword ptr [ESI + 0x64],0x82` |
| `10019660` | `eb 1e` | `JMP 0x10019680` |
| `10019662` | `3d 8f 00 00 c0` | `CMP EAX,0xc000008f` |
| `10019667` | `75 09` | `JNZ 0x10019672` |
| `10019669` | `c7 46 64 86 00 00 00` | `MOV dword ptr [ESI + 0x64],0x86` |
| `10019670` | `eb 0e` | `JMP 0x10019680` |
| `10019672` | `3d 92 00 00 c0` | `CMP EAX,0xc0000092` |
| `10019677` | `75 07` | `JNZ 0x10019680` |
| `10019679` | `c7 46 64 8a 00 00 00` | `MOV dword ptr [ESI + 0x64],0x8a` |
| `10019680` | `ff 76 64` | `PUSH dword ptr [ESI + 0x64]` |
| `10019683` | `6a 08` | `PUSH 0x8` |
| `10019685` | `ff d3` | `CALL EBX` |
| `10019687` | `59` | `POP ECX` |
| `10019688` | `89 7e 64` | `MOV dword ptr [ESI + 0x64],EDI` |
| `1001968b` | `eb 07` | `JMP 0x10019694` |
| `1001968d` | `83 60 08 00` | `AND dword ptr [EAX + 0x8],0x0` |
| `10019691` | `51` | `PUSH ECX` |
| `10019692` | `ff d3` | `CALL EBX` |
| `10019694` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10019697` | `59` | `POP ECX` |
| `10019698` | `89 46 60` | `MOV dword ptr [ESI + 0x60],EAX` |
| `1001969b` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001969e` | `5b` | `POP EBX` |
| `1001969f` | `5f` | `POP EDI` |
| `100196a0` | `5e` | `POP ESI` |
| `100196a1` | `c9` | `LEAVE` |
| `100196a2` | `c3` | `RET` |
