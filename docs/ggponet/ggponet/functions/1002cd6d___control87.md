# 1002cd6d `__control87`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002cd6d |
| `name` | __control87 |
| `namespace` | Global |
| `signature` | uint __cdecl __control87(uint _NewValue, uint _Mask) |
| `size_bytes` | 783 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __control87 |

## Decompiled C

```c

/* Library Function - Single Match
    __control87
   
   Library: Visual Studio 2008 Release */

uint __cdecl __control87(uint _NewValue,uint _Mask)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort in_FPUControlWord;
  
  uVar5 = 0;
  if ((in_FPUControlWord & 1) != 0) {
    uVar5 = 0x10;
  }
  if ((in_FPUControlWord & 4) != 0) {
    uVar5 = uVar5 | 8;
  }
  if ((in_FPUControlWord & 8) != 0) {
    uVar5 = uVar5 | 4;
  }
  if ((in_FPUControlWord & 0x10) != 0) {
    uVar5 = uVar5 | 2;
  }
  if ((in_FPUControlWord & 0x20) != 0) {
    uVar5 = uVar5 | 1;
  }
  if ((in_FPUControlWord & 2) != 0) {
    uVar5 = uVar5 | 0x80000;
  }
  uVar1 = in_FPUControlWord & 0xc00;
  if ((in_FPUControlWord & 0xc00) != 0) {
    if (uVar1 == 0x400) {
      uVar5 = uVar5 | 0x100;
    }
    else if (uVar1 == 0x800) {
      uVar5 = uVar5 | 0x200;
    }
    else if (uVar1 == 0xc00) {
      uVar5 = uVar5 | 0x300;
    }
  }
  if ((in_FPUControlWord & 0x300) == 0) {
    uVar5 = uVar5 | 0x20000;
  }
  else if ((in_FPUControlWord & 0x300) == 0x200) {
    uVar5 = uVar5 | 0x10000;
  }
  if ((in_FPUControlWord & 0x1000) != 0) {
    uVar5 = uVar5 | 0x40000;
  }
  uVar2 = ~_Mask & uVar5 | _NewValue & _Mask;
  if (uVar2 != uVar5) {
    uVar5 = __hw_cw();
    uVar2 = 0;
    if ((uVar5 & 1) != 0) {
      uVar2 = 0x10;
    }
    if ((uVar5 & 4) != 0) {
      uVar2 = uVar2 | 8;
    }
    if ((uVar5 & 8) != 0) {
      uVar2 = uVar2 | 4;
    }
    if ((uVar5 & 0x10) != 0) {
      uVar2 = uVar2 | 2;
    }
    if ((uVar5 & 0x20) != 0) {
      uVar2 = uVar2 | 1;
    }
    if ((uVar5 & 2) != 0) {
      uVar2 = uVar2 | 0x80000;
    }
    uVar3 = uVar5 & 0xc00;
    if (uVar3 != 0) {
      if (uVar3 == 0x400) {
        uVar2 = uVar2 | 0x100;
      }
      else if (uVar3 == 0x800) {
        uVar2 = uVar2 | 0x200;
      }
      else if (uVar3 == 0xc00) {
        uVar2 = uVar2 | 0x300;
      }
    }
    if ((uVar5 & 0x300) == 0) {
      uVar2 = uVar2 | 0x20000;
    }
    else if ((uVar5 & 0x300) == 0x200) {
      uVar2 = uVar2 | 0x10000;
    }
    if ((uVar5 & 0x1000) != 0) {
      uVar2 = uVar2 | 0x40000;
    }
  }
  uVar5 = 0;
  if (DAT_1343a684 != 0) {
    if ((char)MXCSR < '\0') {
      uVar5 = 0x10;
    }
    if ((MXCSR & 0x200) != 0) {
      uVar5 = uVar5 | 8;
    }
    if ((MXCSR & 0x400) != 0) {
      uVar5 = uVar5 | 4;
    }
    if ((MXCSR & 0x800) != 0) {
      uVar5 = uVar5 | 2;
    }
    if ((MXCSR & 0x1000) != 0) {
      uVar5 = uVar5 | 1;
    }
    if ((MXCSR & 0x100) != 0) {
      uVar5 = uVar5 | 0x80000;
    }
    uVar3 = MXCSR & 0x6000;
    if (uVar3 != 0) {
      if (uVar3 == 0x2000) {
        uVar5 = uVar5 | 0x100;
      }
      else if (uVar3 == 0x4000) {
        uVar5 = uVar5 | 0x200;
      }
      else if (uVar3 == 0x6000) {
        uVar5 = uVar5 | 0x300;
      }
    }
    uVar3 = MXCSR & 0x8040;
    if (uVar3 == 0x40) {
      uVar5 = uVar5 | 0x2000000;
    }
    else if (uVar3 == 0x8000) {
      uVar5 = uVar5 | 0x3000000;
    }
    else if (uVar3 == 0x8040) {
      uVar5 = uVar5 | 0x1000000;
    }
    if ((~(_Mask & 0x308031f) & uVar5 | _Mask & 0x308031f & _NewValue) != uVar5) {
      uVar4 = ___hw_cw_sse2();
      ___set_fpsr_sse2(uVar4);
      uVar5 = 0;
      if ((char)MXCSR < '\0') {
        uVar5 = 0x10;
      }
      if ((MXCSR & 0x200) != 0) {
        uVar5 = uVar5 | 8;
      }
      if ((MXCSR & 0x400) != 0) {
        uVar5 = uVar5 | 4;
      }
      if ((MXCSR & 0x800) != 0) {
        uVar5 = uVar5 | 2;
      }
      if ((MXCSR & 0x1000) != 0) {
        uVar5 = uVar5 | 1;
      }
      if ((MXCSR & 0x100) != 0) {
        uVar5 = uVar5 | 0x80000;
      }
      uVar3 = MXCSR & 0x6000;
      if (uVar3 != 0) {
        if (uVar3 == 0x2000) {
          uVar5 = uVar5 | 0x100;
        }
        else if (uVar3 == 0x4000) {
          uVar5 = uVar5 | 0x200;
        }
        else if (uVar3 == 0x6000) {
          uVar5 = uVar5 | 0x300;
        }
      }
      uVar3 = MXCSR & 0x8040;
      if (uVar3 == 0x40) {
        uVar5 = uVar5 | 0x2000000;
      }
      else if (uVar3 == 0x8000) {
        uVar5 = uVar5 | 0x3000000;
      }
      else if (uVar3 == 0x8040) {
        uVar5 = uVar5 | 0x1000000;
      }
    }
    uVar3 = uVar5 ^ uVar2;
    uVar2 = uVar5 | uVar2;
    if ((uVar3 & 0x8031f) != 0) {
      uVar2 = uVar2 | 0x80000000;
    }
  }
  return uVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ce30` | `1002cc3f` | `UNCONDITIONAL_CALL` | __hw_cw | `1002cc3f` |
| `1002cfb2` | `1002cccd` | `UNCONDITIONAL_CALL` | ___hw_cw_sse2 | `1002cccd` |
| `1002cfbb` | `1002d24a` | `UNCONDITIONAL_CALL` | ___set_fpsr_sse2 | `1002d24a` |

## Callers

| From | Function |
| --- | --- |
| `1002b156` | __controlfp_s |
| `1002b186` | __controlfp_s |
| `1002b18f` | __controlfp_s |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002cede` | `1343a684` | `READ` | DAT_1343a684 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002cd6d` | `8b ff` | `MOV EDI,EDI` |
| `1002cd6f` | `55` | `PUSH EBP` |
| `1002cd70` | `8b ec` | `MOV EBP,ESP` |
| `1002cd72` | `83 ec 14` | `SUB ESP,0x14` |
| `1002cd75` | `53` | `PUSH EBX` |
| `1002cd76` | `56` | `PUSH ESI` |
| `1002cd77` | `57` | `PUSH EDI` |
| `1002cd78` | `9b d9 7d f8` | `FSTCW word ptr [EBP + -0x8]` |
| `1002cd7c` | `8b 5d f8` | `MOV EBX,dword ptr [EBP + -0x8]` |
| `1002cd7f` | `33 d2` | `XOR EDX,EDX` |
| `1002cd81` | `f6 c3 01` | `TEST BL,0x1` |
| `1002cd84` | `74 03` | `JZ 0x1002cd89` |
| `1002cd86` | `6a 10` | `PUSH 0x10` |
| `1002cd88` | `5a` | `POP EDX` |
| `1002cd89` | `f6 c3 04` | `TEST BL,0x4` |
| `1002cd8c` | `74 03` | `JZ 0x1002cd91` |
| `1002cd8e` | `83 ca 08` | `OR EDX,0x8` |
| `1002cd91` | `f6 c3 08` | `TEST BL,0x8` |
| `1002cd94` | `74 03` | `JZ 0x1002cd99` |
| `1002cd96` | `83 ca 04` | `OR EDX,0x4` |
| `1002cd99` | `f6 c3 10` | `TEST BL,0x10` |
| `1002cd9c` | `74 03` | `JZ 0x1002cda1` |
| `1002cd9e` | `83 ca 02` | `OR EDX,0x2` |
| `1002cda1` | `f6 c3 20` | `TEST BL,0x20` |
| `1002cda4` | `74 03` | `JZ 0x1002cda9` |
| `1002cda6` | `83 ca 01` | `OR EDX,0x1` |
| `1002cda9` | `f6 c3 02` | `TEST BL,0x2` |
| `1002cdac` | `74 06` | `JZ 0x1002cdb4` |
| `1002cdae` | `81 ca 00 00 08 00` | `OR EDX,0x80000` |
| `1002cdb4` | `0f b7 cb` | `MOVZX ECX,BX` |
| `1002cdb7` | `8b c1` | `MOV EAX,ECX` |
| `1002cdb9` | `be 00 0c 00 00` | `MOV ESI,0xc00` |
| `1002cdbe` | `23 c6` | `AND EAX,ESI` |
| `1002cdc0` | `bf 00 03 00 00` | `MOV EDI,0x300` |
| `1002cdc5` | `74 24` | `JZ 0x1002cdeb` |
| `1002cdc7` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1002cdcc` | `74 17` | `JZ 0x1002cde5` |
| `1002cdce` | `3d 00 08 00 00` | `CMP EAX,0x800` |
| `1002cdd3` | `74 08` | `JZ 0x1002cddd` |
| `1002cdd5` | `3b c6` | `CMP EAX,ESI` |
| `1002cdd7` | `75 12` | `JNZ 0x1002cdeb` |
| `1002cdd9` | `0b d7` | `OR EDX,EDI` |
| `1002cddb` | `eb 0e` | `JMP 0x1002cdeb` |
| `1002cddd` | `81 ca 00 02 00 00` | `OR EDX,0x200` |
| `1002cde3` | `eb 06` | `JMP 0x1002cdeb` |
| `1002cde5` | `81 ca 00 01 00 00` | `OR EDX,0x100` |
| `1002cdeb` | `23 cf` | `AND ECX,EDI` |
| `1002cded` | `74 10` | `JZ 0x1002cdff` |
| `1002cdef` | `81 f9 00 02 00 00` | `CMP ECX,0x200` |
| `1002cdf5` | `75 0e` | `JNZ 0x1002ce05` |
| `1002cdf7` | `81 ca 00 00 01 00` | `OR EDX,0x10000` |
| `1002cdfd` | `eb 06` | `JMP 0x1002ce05` |
| `1002cdff` | `81 ca 00 00 02 00` | `OR EDX,0x20000` |
| `1002ce05` | `f7 c3 00 10 00 00` | `TEST EBX,0x1000` |
| `1002ce0b` | `74 06` | `JZ 0x1002ce13` |
| `1002ce0d` | `81 ca 00 00 04 00` | `OR EDX,0x40000` |
| `1002ce13` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1002ce16` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1002ce19` | `8b c7` | `MOV EAX,EDI` |
| `1002ce1b` | `f7 d0` | `NOT EAX` |
| `1002ce1d` | `23 c2` | `AND EAX,EDX` |
| `1002ce1f` | `23 cf` | `AND ECX,EDI` |
| `1002ce21` | `0b c1` | `OR EAX,ECX` |
| `1002ce23` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `1002ce26` | `3b c2` | `CMP EAX,EDX` |
| `1002ce28` | `0f 84 ae 00 00 00` | `JZ 0x1002cedc` |
| `1002ce2e` | `8b d8` | `MOV EBX,EAX` |
| `1002ce30` | `e8 0a fe ff ff` | `CALL 0x1002cc3f` |
| `1002ce35` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1002ce38` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002ce3b` | `d9 6d fc` | `FLDCW word ptr [EBP + -0x4]` |
| `1002ce3e` | `9b d9 7d fc` | `FSTCW word ptr [EBP + -0x4]` |
| `1002ce42` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `1002ce45` | `33 d2` | `XOR EDX,EDX` |
| `1002ce47` | `f6 c3 01` | `TEST BL,0x1` |
| `1002ce4a` | `74 03` | `JZ 0x1002ce4f` |
| `1002ce4c` | `6a 10` | `PUSH 0x10` |
| `1002ce4e` | `5a` | `POP EDX` |
| `1002ce4f` | `f6 c3 04` | `TEST BL,0x4` |
| `1002ce52` | `74 03` | `JZ 0x1002ce57` |
| `1002ce54` | `83 ca 08` | `OR EDX,0x8` |
| `1002ce57` | `f6 c3 08` | `TEST BL,0x8` |
| `1002ce5a` | `74 03` | `JZ 0x1002ce5f` |
| `1002ce5c` | `83 ca 04` | `OR EDX,0x4` |
| `1002ce5f` | `f6 c3 10` | `TEST BL,0x10` |
| `1002ce62` | `74 03` | `JZ 0x1002ce67` |
| `1002ce64` | `83 ca 02` | `OR EDX,0x2` |
| `1002ce67` | `f6 c3 20` | `TEST BL,0x20` |
| `1002ce6a` | `74 03` | `JZ 0x1002ce6f` |
| `1002ce6c` | `83 ca 01` | `OR EDX,0x1` |
| `1002ce6f` | `f6 c3 02` | `TEST BL,0x2` |
| `1002ce72` | `74 06` | `JZ 0x1002ce7a` |
| `1002ce74` | `81 ca 00 00 08 00` | `OR EDX,0x80000` |
| `1002ce7a` | `0f b7 cb` | `MOVZX ECX,BX` |
| `1002ce7d` | `8b c1` | `MOV EAX,ECX` |
| `1002ce7f` | `23 c6` | `AND EAX,ESI` |
| `1002ce81` | `74 28` | `JZ 0x1002ceab` |
| `1002ce83` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1002ce88` | `74 1b` | `JZ 0x1002cea5` |
| `1002ce8a` | `3d 00 08 00 00` | `CMP EAX,0x800` |
| `1002ce8f` | `74 0c` | `JZ 0x1002ce9d` |
| `1002ce91` | `3b c6` | `CMP EAX,ESI` |
| `1002ce93` | `75 16` | `JNZ 0x1002ceab` |
| `1002ce95` | `81 ca 00 03 00 00` | `OR EDX,0x300` |
| `1002ce9b` | `eb 0e` | `JMP 0x1002ceab` |
| `1002ce9d` | `81 ca 00 02 00 00` | `OR EDX,0x200` |
| `1002cea3` | `eb 06` | `JMP 0x1002ceab` |
| `1002cea5` | `81 ca 00 01 00 00` | `OR EDX,0x100` |
| `1002ceab` | `81 e1 00 03 00 00` | `AND ECX,0x300` |
| `1002ceb1` | `74 10` | `JZ 0x1002cec3` |
| `1002ceb3` | `81 f9 00 02 00 00` | `CMP ECX,0x200` |
| `1002ceb9` | `75 0e` | `JNZ 0x1002cec9` |
| `1002cebb` | `81 ca 00 00 01 00` | `OR EDX,0x10000` |
| `1002cec1` | `eb 06` | `JMP 0x1002cec9` |
| `1002cec3` | `81 ca 00 00 02 00` | `OR EDX,0x20000` |
| `1002cec9` | `f7 c3 00 10 00 00` | `TEST EBX,0x1000` |
| `1002cecf` | `74 06` | `JZ 0x1002ced7` |
| `1002ced1` | `81 ca 00 00 04 00` | `OR EDX,0x40000` |
| `1002ced7` | `89 55 0c` | `MOV dword ptr [EBP + 0xc],EDX` |
| `1002ceda` | `8b c2` | `MOV EAX,EDX` |
| `1002cedc` | `33 f6` | `XOR ESI,ESI` |
| `1002cede` | `39 35 84 a6 43 13` | `CMP dword ptr [0x1343a684],ESI` |
| `1002cee4` | `0f 84 8d 01 00 00` | `JZ 0x1002d077` |
| `1002ceea` | `81 e7 1f 03 08 03` | `AND EDI,0x308031f` |
| `1002cef0` | `89 7d ec` | `MOV dword ptr [EBP + -0x14],EDI` |
| `1002cef3` | `0f ae 5d f0` | `STMXCSR dword ptr [EBP + -0x10]` |
| `1002cef7` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1002cefa` | `84 c0` | `TEST AL,AL` |
| `1002cefc` | `79 03` | `JNS 0x1002cf01` |
| `1002cefe` | `6a 10` | `PUSH 0x10` |
| `1002cf00` | `5e` | `POP ESI` |
| `1002cf01` | `a9 00 02 00 00` | `TEST EAX,0x200` |
| `1002cf06` | `74 03` | `JZ 0x1002cf0b` |
| `1002cf08` | `83 ce 08` | `OR ESI,0x8` |
| `1002cf0b` | `a9 00 04 00 00` | `TEST EAX,0x400` |
| `1002cf10` | `74 03` | `JZ 0x1002cf15` |
| `1002cf12` | `83 ce 04` | `OR ESI,0x4` |
| `1002cf15` | `a9 00 08 00 00` | `TEST EAX,0x800` |
| `1002cf1a` | `74 03` | `JZ 0x1002cf1f` |
| `1002cf1c` | `83 ce 02` | `OR ESI,0x2` |
| `1002cf1f` | `a9 00 10 00 00` | `TEST EAX,0x1000` |
| `1002cf24` | `74 03` | `JZ 0x1002cf29` |
| `1002cf26` | `83 ce 01` | `OR ESI,0x1` |
| `1002cf29` | `a9 00 01 00 00` | `TEST EAX,0x100` |
| `1002cf2e` | `74 06` | `JZ 0x1002cf36` |
| `1002cf30` | `81 ce 00 00 08 00` | `OR ESI,0x80000` |
| `1002cf36` | `8b c8` | `MOV ECX,EAX` |
| `1002cf38` | `bb 00 60 00 00` | `MOV EBX,0x6000` |
| `1002cf3d` | `23 cb` | `AND ECX,EBX` |
| `1002cf3f` | `74 2a` | `JZ 0x1002cf6b` |
| `1002cf41` | `81 f9 00 20 00 00` | `CMP ECX,0x2000` |
| `1002cf47` | `74 1c` | `JZ 0x1002cf65` |
| `1002cf49` | `81 f9 00 40 00 00` | `CMP ECX,0x4000` |
| `1002cf4f` | `74 0c` | `JZ 0x1002cf5d` |
| `1002cf51` | `3b cb` | `CMP ECX,EBX` |
| `1002cf53` | `75 16` | `JNZ 0x1002cf6b` |
| `1002cf55` | `81 ce 00 03 00 00` | `OR ESI,0x300` |
| `1002cf5b` | `eb 0e` | `JMP 0x1002cf6b` |
| `1002cf5d` | `81 ce 00 02 00 00` | `OR ESI,0x200` |
| `1002cf63` | `eb 06` | `JMP 0x1002cf6b` |
| `1002cf65` | `81 ce 00 01 00 00` | `OR ESI,0x100` |
| `1002cf6b` | `bf 40 80 00 00` | `MOV EDI,0x8040` |
| `1002cf70` | `23 c7` | `AND EAX,EDI` |
| `1002cf72` | `83 e8 40` | `SUB EAX,0x40` |
| `1002cf75` | `74 1c` | `JZ 0x1002cf93` |
| `1002cf77` | `2d c0 7f 00 00` | `SUB EAX,0x7fc0` |
| `1002cf7c` | `74 0d` | `JZ 0x1002cf8b` |
| `1002cf7e` | `83 e8 40` | `SUB EAX,0x40` |
| `1002cf81` | `75 16` | `JNZ 0x1002cf99` |
| `1002cf83` | `81 ce 00 00 00 01` | `OR ESI,0x1000000` |
| `1002cf89` | `eb 0e` | `JMP 0x1002cf99` |
| `1002cf8b` | `81 ce 00 00 00 03` | `OR ESI,0x3000000` |
| `1002cf91` | `eb 06` | `JMP 0x1002cf99` |
| `1002cf93` | `81 ce 00 00 00 02` | `OR ESI,0x2000000` |
| `1002cf99` | `8b 45 ec` | `MOV EAX,dword ptr [EBP + -0x14]` |
| `1002cf9c` | `8b d0` | `MOV EDX,EAX` |
| `1002cf9e` | `23 45 08` | `AND EAX,dword ptr [EBP + 0x8]` |
| `1002cfa1` | `f7 d2` | `NOT EDX` |
| `1002cfa3` | `23 d6` | `AND EDX,ESI` |
| `1002cfa5` | `0b d0` | `OR EDX,EAX` |
| `1002cfa7` | `3b d6` | `CMP EDX,ESI` |
| `1002cfa9` | `75 07` | `JNZ 0x1002cfb2` |
| `1002cfab` | `8b c6` | `MOV EAX,ESI` |
| `1002cfad` | `e9 b0 00 00 00` | `JMP 0x1002d062` |
| `1002cfb2` | `e8 16 fd ff ff` | `CALL 0x1002cccd` |
| `1002cfb7` | `50` | `PUSH EAX` |
| `1002cfb8` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002cfbb` | `e8 8a 02 00 00` | `CALL 0x1002d24a` |
| `1002cfc0` | `59` | `POP ECX` |
| `1002cfc1` | `0f ae 5d f4` | `STMXCSR dword ptr [EBP + -0xc]` |
| `1002cfc5` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `1002cfc8` | `33 d2` | `XOR EDX,EDX` |
| `1002cfca` | `84 c9` | `TEST CL,CL` |
| `1002cfcc` | `79 03` | `JNS 0x1002cfd1` |
| `1002cfce` | `6a 10` | `PUSH 0x10` |
| `1002cfd0` | `5a` | `POP EDX` |
| `1002cfd1` | `f7 c1 00 02 00 00` | `TEST ECX,0x200` |
| `1002cfd7` | `74 03` | `JZ 0x1002cfdc` |
| `1002cfd9` | `83 ca 08` | `OR EDX,0x8` |
| `1002cfdc` | `f7 c1 00 04 00 00` | `TEST ECX,0x400` |
| `1002cfe2` | `74 03` | `JZ 0x1002cfe7` |
| `1002cfe4` | `83 ca 04` | `OR EDX,0x4` |
| `1002cfe7` | `f7 c1 00 08 00 00` | `TEST ECX,0x800` |
| `1002cfed` | `74 03` | `JZ 0x1002cff2` |
| `1002cfef` | `83 ca 02` | `OR EDX,0x2` |
| `1002cff2` | `f7 c1 00 10 00 00` | `TEST ECX,0x1000` |
| `1002cff8` | `74 03` | `JZ 0x1002cffd` |
| `1002cffa` | `83 ca 01` | `OR EDX,0x1` |
| `1002cffd` | `be 00 01 00 00` | `MOV ESI,0x100` |
| `1002d002` | `85 ce` | `TEST ESI,ECX` |
| `1002d004` | `74 06` | `JZ 0x1002d00c` |
| `1002d006` | `81 ca 00 00 08 00` | `OR EDX,0x80000` |
| `1002d00c` | `8b c1` | `MOV EAX,ECX` |
| `1002d00e` | `23 c3` | `AND EAX,EBX` |
| `1002d010` | `74 24` | `JZ 0x1002d036` |
| `1002d012` | `3d 00 20 00 00` | `CMP EAX,0x2000` |
| `1002d017` | `74 1b` | `JZ 0x1002d034` |
| `1002d019` | `3d 00 40 00 00` | `CMP EAX,0x4000` |
| `1002d01e` | `74 0c` | `JZ 0x1002d02c` |
| `1002d020` | `3b c3` | `CMP EAX,EBX` |
| `1002d022` | `75 12` | `JNZ 0x1002d036` |
| `1002d024` | `81 ca 00 03 00 00` | `OR EDX,0x300` |
| `1002d02a` | `eb 0a` | `JMP 0x1002d036` |
| `1002d02c` | `81 ca 00 02 00 00` | `OR EDX,0x200` |
| `1002d032` | `eb 02` | `JMP 0x1002d036` |
| `1002d034` | `0b d6` | `OR EDX,ESI` |
| `1002d036` | `23 cf` | `AND ECX,EDI` |
| `1002d038` | `83 e9 40` | `SUB ECX,0x40` |
| `1002d03b` | `74 1d` | `JZ 0x1002d05a` |
| `1002d03d` | `81 e9 c0 7f 00 00` | `SUB ECX,0x7fc0` |
| `1002d043` | `74 0d` | `JZ 0x1002d052` |
| `1002d045` | `83 e9 40` | `SUB ECX,0x40` |
| `1002d048` | `75 16` | `JNZ 0x1002d060` |
| `1002d04a` | `81 ca 00 00 00 01` | `OR EDX,0x1000000` |
| `1002d050` | `eb 0e` | `JMP 0x1002d060` |
| `1002d052` | `81 ca 00 00 00 03` | `OR EDX,0x3000000` |
| `1002d058` | `eb 06` | `JMP 0x1002d060` |
| `1002d05a` | `81 ca 00 00 00 02` | `OR EDX,0x2000000` |
| `1002d060` | `8b c2` | `MOV EAX,EDX` |
| `1002d062` | `8b c8` | `MOV ECX,EAX` |
| `1002d064` | `33 4d 0c` | `XOR ECX,dword ptr [EBP + 0xc]` |
| `1002d067` | `0b 45 0c` | `OR EAX,dword ptr [EBP + 0xc]` |
| `1002d06a` | `f7 c1 1f 03 08 00` | `TEST ECX,0x8031f` |
| `1002d070` | `74 05` | `JZ 0x1002d077` |
| `1002d072` | `0d 00 00 00 80` | `OR EAX,0x80000000` |
| `1002d077` | `5f` | `POP EDI` |
| `1002d078` | `5e` | `POP ESI` |
| `1002d079` | `5b` | `POP EBX` |
| `1002d07a` | `c9` | `LEAVE` |
| `1002d07b` | `c3` | `RET` |
