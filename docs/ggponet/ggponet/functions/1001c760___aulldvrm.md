# 1001c760 `__aulldvrm`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c760 |
| `name` | __aulldvrm |
| `namespace` | Global |
| `signature` | undefined __aulldvrm(void) |
| `size_bytes` | 149 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __aulldvrm |

## Decompiled C

```c

/* Library Function - Single Match
    __aulldvrm
   
   Library: Visual Studio 2008 Release */

undefined8 __aulldvrm(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = param_1;
  uVar8 = param_4;
  uVar6 = param_2;
  uVar9 = param_3;
  if (param_4 == 0) {
    uVar3 = param_2 / param_3;
    iVar4 = (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                 (ulonglong)param_3);
  }
  else {
    do {
      uVar5 = uVar8 >> 1;
      uVar9 = uVar9 >> 1 | (uint)((uVar8 & 1) != 0) << 0x1f;
      uVar7 = uVar6 >> 1;
      uVar3 = uVar3 >> 1 | (uint)((uVar6 & 1) != 0) << 0x1f;
      uVar8 = uVar5;
      uVar6 = uVar7;
    } while (uVar5 != 0);
    uVar1 = CONCAT44(uVar7,uVar3) / (ulonglong)uVar9;
    iVar4 = (int)uVar1;
    lVar2 = (ulonglong)param_3 * (uVar1 & 0xffffffff);
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    uVar8 = uVar3 + iVar4 * param_4;
    if (((CARRY4(uVar3,iVar4 * param_4)) || (param_2 < uVar8)) ||
       ((param_2 <= uVar8 && (param_1 < (uint)lVar2)))) {
      iVar4 = iVar4 + -1;
    }
    uVar3 = 0;
  }
  return CONCAT44(uVar3,iVar4);
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10015ce7` | __output_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c760` | `56` | `PUSH ESI` |
| `1001c761` | `8b 44 24 14` | `MOV EAX,dword ptr [ESP + 0x14]` |
| `1001c765` | `0b c0` | `OR EAX,EAX` |
| `1001c767` | `75 28` | `JNZ 0x1001c791` |
| `1001c769` | `8b 4c 24 10` | `MOV ECX,dword ptr [ESP + 0x10]` |
| `1001c76d` | `8b 44 24 0c` | `MOV EAX,dword ptr [ESP + 0xc]` |
| `1001c771` | `33 d2` | `XOR EDX,EDX` |
| `1001c773` | `f7 f1` | `DIV ECX` |
| `1001c775` | `8b d8` | `MOV EBX,EAX` |
| `1001c777` | `8b 44 24 08` | `MOV EAX,dword ptr [ESP + 0x8]` |
| `1001c77b` | `f7 f1` | `DIV ECX` |
| `1001c77d` | `8b f0` | `MOV ESI,EAX` |
| `1001c77f` | `8b c3` | `MOV EAX,EBX` |
| `1001c781` | `f7 64 24 10` | `MUL dword ptr [ESP + 0x10]` |
| `1001c785` | `8b c8` | `MOV ECX,EAX` |
| `1001c787` | `8b c6` | `MOV EAX,ESI` |
| `1001c789` | `f7 64 24 10` | `MUL dword ptr [ESP + 0x10]` |
| `1001c78d` | `03 d1` | `ADD EDX,ECX` |
| `1001c78f` | `eb 47` | `JMP 0x1001c7d8` |
| `1001c791` | `8b c8` | `MOV ECX,EAX` |
| `1001c793` | `8b 5c 24 10` | `MOV EBX,dword ptr [ESP + 0x10]` |
| `1001c797` | `8b 54 24 0c` | `MOV EDX,dword ptr [ESP + 0xc]` |
| `1001c79b` | `8b 44 24 08` | `MOV EAX,dword ptr [ESP + 0x8]` |
| `1001c79f` | `d1 e9` | `SHR ECX,0x1` |
| `1001c7a1` | `d1 db` | `RCR EBX,0x1` |
| `1001c7a3` | `d1 ea` | `SHR EDX,0x1` |
| `1001c7a5` | `d1 d8` | `RCR EAX,0x1` |
| `1001c7a7` | `0b c9` | `OR ECX,ECX` |
| `1001c7a9` | `75 f4` | `JNZ 0x1001c79f` |
| `1001c7ab` | `f7 f3` | `DIV EBX` |
| `1001c7ad` | `8b f0` | `MOV ESI,EAX` |
| `1001c7af` | `f7 64 24 14` | `MUL dword ptr [ESP + 0x14]` |
| `1001c7b3` | `8b c8` | `MOV ECX,EAX` |
| `1001c7b5` | `8b 44 24 10` | `MOV EAX,dword ptr [ESP + 0x10]` |
| `1001c7b9` | `f7 e6` | `MUL ESI` |
| `1001c7bb` | `03 d1` | `ADD EDX,ECX` |
| `1001c7bd` | `72 0e` | `JC 0x1001c7cd` |
| `1001c7bf` | `3b 54 24 0c` | `CMP EDX,dword ptr [ESP + 0xc]` |
| `1001c7c3` | `77 08` | `JA 0x1001c7cd` |
| `1001c7c5` | `72 0f` | `JC 0x1001c7d6` |
| `1001c7c7` | `3b 44 24 08` | `CMP EAX,dword ptr [ESP + 0x8]` |
| `1001c7cb` | `76 09` | `JBE 0x1001c7d6` |
| `1001c7cd` | `4e` | `DEC ESI` |
| `1001c7ce` | `2b 44 24 10` | `SUB EAX,dword ptr [ESP + 0x10]` |
| `1001c7d2` | `1b 54 24 14` | `SBB EDX,dword ptr [ESP + 0x14]` |
| `1001c7d6` | `33 db` | `XOR EBX,EBX` |
| `1001c7d8` | `2b 44 24 08` | `SUB EAX,dword ptr [ESP + 0x8]` |
| `1001c7dc` | `1b 54 24 0c` | `SBB EDX,dword ptr [ESP + 0xc]` |
| `1001c7e0` | `f7 da` | `NEG EDX` |
| `1001c7e2` | `f7 d8` | `NEG EAX` |
| `1001c7e4` | `83 da 00` | `SBB EDX,0x0` |
| `1001c7e7` | `8b ca` | `MOV ECX,EDX` |
| `1001c7e9` | `8b d3` | `MOV EDX,EBX` |
| `1001c7eb` | `8b d9` | `MOV EBX,ECX` |
| `1001c7ed` | `8b c8` | `MOV ECX,EAX` |
| `1001c7ef` | `8b c6` | `MOV EAX,ESI` |
| `1001c7f1` | `5e` | `POP ESI` |
| `1001c7f2` | `c2 10 00` | `RET 0x10` |
