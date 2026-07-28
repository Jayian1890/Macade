# 1002b030 `__alldvrm`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002b030 |
| `name` | __alldvrm |
| `namespace` | Global |
| `signature` | undefined __alldvrm(void) |
| `size_bytes` | 223 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __alldvrm |

## Decompiled C

```c

/* Library Function - Single Match
    __alldvrm
   
   Library: Visual Studio 2008 Release */

undefined8 __alldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar10;
  char cVar11;
  uint uVar9;
  
  cVar11 = (int)param_2 < 0;
  if ((bool)cVar11) {
    bVar10 = param_1 != 0;
    param_1 = -param_1;
    param_2 = -(uint)bVar10 - param_2;
  }
  if ((int)param_4 < 0) {
    cVar11 = cVar11 + '\x01';
    bVar10 = param_3 != 0;
    param_3 = -param_3;
    param_4 = -(uint)bVar10 - param_4;
  }
  uVar3 = param_1;
  uVar5 = param_3;
  uVar6 = param_2;
  uVar9 = param_4;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar8 = uVar9 >> 1;
      uVar5 = uVar5 >> 1 | (uint)((uVar9 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar6 = uVar7;
      uVar9 = uVar8;
    } while (uVar8 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar5;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar5 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar5)) ||
       ((param_2 <= uVar5 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  if (cVar11 == '\x01') {
    bVar10 = iVar4 != 0;
    iVar4 = -iVar4;
    uVar3 = -(uint)bVar10 - uVar3;
  }
  return CONCAT44(uVar3,iVar4);
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002a835` | __cftoa_l |
| `1002a85b` | __cftoa_l |
| `1002a881` | __cftoa_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002b030` | `57` | `PUSH EDI` |
| `1002b031` | `56` | `PUSH ESI` |
| `1002b032` | `55` | `PUSH EBP` |
| `1002b033` | `33 ff` | `XOR EDI,EDI` |
| `1002b035` | `33 ed` | `XOR EBP,EBP` |
| `1002b037` | `8b 44 24 14` | `MOV EAX,dword ptr [ESP + 0x14]` |
| `1002b03b` | `0b c0` | `OR EAX,EAX` |
| `1002b03d` | `7d 15` | `JGE 0x1002b054` |
| `1002b03f` | `47` | `INC EDI` |
| `1002b040` | `45` | `INC EBP` |
| `1002b041` | `8b 54 24 10` | `MOV EDX,dword ptr [ESP + 0x10]` |
| `1002b045` | `f7 d8` | `NEG EAX` |
| `1002b047` | `f7 da` | `NEG EDX` |
| `1002b049` | `83 d8 00` | `SBB EAX,0x0` |
| `1002b04c` | `89 44 24 14` | `MOV dword ptr [ESP + 0x14],EAX` |
| `1002b050` | `89 54 24 10` | `MOV dword ptr [ESP + 0x10],EDX` |
| `1002b054` | `8b 44 24 1c` | `MOV EAX,dword ptr [ESP + 0x1c]` |
| `1002b058` | `0b c0` | `OR EAX,EAX` |
| `1002b05a` | `7d 14` | `JGE 0x1002b070` |
| `1002b05c` | `47` | `INC EDI` |
| `1002b05d` | `8b 54 24 18` | `MOV EDX,dword ptr [ESP + 0x18]` |
| `1002b061` | `f7 d8` | `NEG EAX` |
| `1002b063` | `f7 da` | `NEG EDX` |
| `1002b065` | `83 d8 00` | `SBB EAX,0x0` |
| `1002b068` | `89 44 24 1c` | `MOV dword ptr [ESP + 0x1c],EAX` |
| `1002b06c` | `89 54 24 18` | `MOV dword ptr [ESP + 0x18],EDX` |
| `1002b070` | `0b c0` | `OR EAX,EAX` |
| `1002b072` | `75 28` | `JNZ 0x1002b09c` |
| `1002b074` | `8b 4c 24 18` | `MOV ECX,dword ptr [ESP + 0x18]` |
| `1002b078` | `8b 44 24 14` | `MOV EAX,dword ptr [ESP + 0x14]` |
| `1002b07c` | `33 d2` | `XOR EDX,EDX` |
| `1002b07e` | `f7 f1` | `DIV ECX` |
| `1002b080` | `8b d8` | `MOV EBX,EAX` |
| `1002b082` | `8b 44 24 10` | `MOV EAX,dword ptr [ESP + 0x10]` |
| `1002b086` | `f7 f1` | `DIV ECX` |
| `1002b088` | `8b f0` | `MOV ESI,EAX` |
| `1002b08a` | `8b c3` | `MOV EAX,EBX` |
| `1002b08c` | `f7 64 24 18` | `MUL dword ptr [ESP + 0x18]` |
| `1002b090` | `8b c8` | `MOV ECX,EAX` |
| `1002b092` | `8b c6` | `MOV EAX,ESI` |
| `1002b094` | `f7 64 24 18` | `MUL dword ptr [ESP + 0x18]` |
| `1002b098` | `03 d1` | `ADD EDX,ECX` |
| `1002b09a` | `eb 47` | `JMP 0x1002b0e3` |
| `1002b09c` | `8b d8` | `MOV EBX,EAX` |
| `1002b09e` | `8b 4c 24 18` | `MOV ECX,dword ptr [ESP + 0x18]` |
| `1002b0a2` | `8b 54 24 14` | `MOV EDX,dword ptr [ESP + 0x14]` |
| `1002b0a6` | `8b 44 24 10` | `MOV EAX,dword ptr [ESP + 0x10]` |
| `1002b0aa` | `d1 eb` | `SHR EBX,0x1` |
| `1002b0ac` | `d1 d9` | `RCR ECX,0x1` |
| `1002b0ae` | `d1 ea` | `SHR EDX,0x1` |
| `1002b0b0` | `d1 d8` | `RCR EAX,0x1` |
| `1002b0b2` | `0b db` | `OR EBX,EBX` |
| `1002b0b4` | `75 f4` | `JNZ 0x1002b0aa` |
| `1002b0b6` | `f7 f1` | `DIV ECX` |
| `1002b0b8` | `8b f0` | `MOV ESI,EAX` |
| `1002b0ba` | `f7 64 24 1c` | `MUL dword ptr [ESP + 0x1c]` |
| `1002b0be` | `8b c8` | `MOV ECX,EAX` |
| `1002b0c0` | `8b 44 24 18` | `MOV EAX,dword ptr [ESP + 0x18]` |
| `1002b0c4` | `f7 e6` | `MUL ESI` |
| `1002b0c6` | `03 d1` | `ADD EDX,ECX` |
| `1002b0c8` | `72 0e` | `JC 0x1002b0d8` |
| `1002b0ca` | `3b 54 24 14` | `CMP EDX,dword ptr [ESP + 0x14]` |
| `1002b0ce` | `77 08` | `JA 0x1002b0d8` |
| `1002b0d0` | `72 0f` | `JC 0x1002b0e1` |
| `1002b0d2` | `3b 44 24 10` | `CMP EAX,dword ptr [ESP + 0x10]` |
| `1002b0d6` | `76 09` | `JBE 0x1002b0e1` |
| `1002b0d8` | `4e` | `DEC ESI` |
| `1002b0d9` | `2b 44 24 18` | `SUB EAX,dword ptr [ESP + 0x18]` |
| `1002b0dd` | `1b 54 24 1c` | `SBB EDX,dword ptr [ESP + 0x1c]` |
| `1002b0e1` | `33 db` | `XOR EBX,EBX` |
| `1002b0e3` | `2b 44 24 10` | `SUB EAX,dword ptr [ESP + 0x10]` |
| `1002b0e7` | `1b 54 24 14` | `SBB EDX,dword ptr [ESP + 0x14]` |
| `1002b0eb` | `4d` | `DEC EBP` |
| `1002b0ec` | `79 07` | `JNS 0x1002b0f5` |
| `1002b0ee` | `f7 da` | `NEG EDX` |
| `1002b0f0` | `f7 d8` | `NEG EAX` |
| `1002b0f2` | `83 da 00` | `SBB EDX,0x0` |
| `1002b0f5` | `8b ca` | `MOV ECX,EDX` |
| `1002b0f7` | `8b d3` | `MOV EDX,EBX` |
| `1002b0f9` | `8b d9` | `MOV EBX,ECX` |
| `1002b0fb` | `8b c8` | `MOV ECX,EAX` |
| `1002b0fd` | `8b c6` | `MOV EAX,ESI` |
| `1002b0ff` | `4f` | `DEC EDI` |
| `1002b100` | `75 07` | `JNZ 0x1002b109` |
| `1002b102` | `f7 da` | `NEG EDX` |
| `1002b104` | `f7 d8` | `NEG EAX` |
| `1002b106` | `83 da 00` | `SBB EDX,0x0` |
| `1002b109` | `5d` | `POP EBP` |
| `1002b10a` | `5e` | `POP ESI` |
| `1002b10b` | `5f` | `POP EDI` |
| `1002b10c` | `c2 10 00` | `RET 0x10` |
