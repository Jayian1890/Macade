# 1002cccd `___hw_cw_sse2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002cccd |
| `name` | ___hw_cw_sse2 |
| `namespace` | Global |
| `signature` | undefined ___hw_cw_sse2(void) |
| `size_bytes` | 160 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___hw_cw_sse2 |

## Decompiled C

```c

/* Library Function - Single Match
    ___hw_cw_sse2
   
   Library: Visual Studio 2008 Release */

uint ___hw_cw_sse2(void)

{
  uint uVar1;
  uint uVar2;
  uint in_EDX;
  
  uVar1 = 0;
  if ((in_EDX & 0x10) != 0) {
    uVar1 = 0x80;
  }
  if ((in_EDX & 8) != 0) {
    uVar1 = uVar1 | 0x200;
  }
  if ((in_EDX & 4) != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if ((in_EDX & 2) != 0) {
    uVar1 = uVar1 | 0x800;
  }
  if ((in_EDX & 1) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  if ((in_EDX & 0x80000) != 0) {
    uVar1 = uVar1 | 0x100;
  }
  uVar2 = in_EDX & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x2000;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x4000;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0x6000;
    }
  }
  uVar2 = in_EDX & 0x3000000;
  if (uVar2 == 0x1000000) {
    uVar1 = uVar1 | 0x8040;
  }
  else {
    if (uVar2 == 0x2000000) {
      return uVar1 | 0x40;
    }
    if (uVar2 == 0x3000000) {
      return uVar1 | 0x8000;
    }
  }
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002cfb2` | __control87 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002cccd` | `33 c0` | `XOR EAX,EAX` |
| `1002cccf` | `f6 c2 10` | `TEST DL,0x10` |
| `1002ccd2` | `74 05` | `JZ 0x1002ccd9` |
| `1002ccd4` | `b8 80 00 00 00` | `MOV EAX,0x80` |
| `1002ccd9` | `53` | `PUSH EBX` |
| `1002ccda` | `56` | `PUSH ESI` |
| `1002ccdb` | `57` | `PUSH EDI` |
| `1002ccdc` | `bb 00 02 00 00` | `MOV EBX,0x200` |
| `1002cce1` | `f6 c2 08` | `TEST DL,0x8` |
| `1002cce4` | `74 02` | `JZ 0x1002cce8` |
| `1002cce6` | `0b c3` | `OR EAX,EBX` |
| `1002cce8` | `f6 c2 04` | `TEST DL,0x4` |
| `1002cceb` | `74 05` | `JZ 0x1002ccf2` |
| `1002cced` | `0d 00 04 00 00` | `OR EAX,0x400` |
| `1002ccf2` | `f6 c2 02` | `TEST DL,0x2` |
| `1002ccf5` | `74 05` | `JZ 0x1002ccfc` |
| `1002ccf7` | `0d 00 08 00 00` | `OR EAX,0x800` |
| `1002ccfc` | `f6 c2 01` | `TEST DL,0x1` |
| `1002ccff` | `74 05` | `JZ 0x1002cd06` |
| `1002cd01` | `0d 00 10 00 00` | `OR EAX,0x1000` |
| `1002cd06` | `bf 00 01 00 00` | `MOV EDI,0x100` |
| `1002cd0b` | `f7 c2 00 00 08 00` | `TEST EDX,0x80000` |
| `1002cd11` | `74 02` | `JZ 0x1002cd15` |
| `1002cd13` | `0b c7` | `OR EAX,EDI` |
| `1002cd15` | `8b ca` | `MOV ECX,EDX` |
| `1002cd17` | `be 00 03 00 00` | `MOV ESI,0x300` |
| `1002cd1c` | `23 ce` | `AND ECX,ESI` |
| `1002cd1e` | `74 1f` | `JZ 0x1002cd3f` |
| `1002cd20` | `3b cf` | `CMP ECX,EDI` |
| `1002cd22` | `74 16` | `JZ 0x1002cd3a` |
| `1002cd24` | `3b cb` | `CMP ECX,EBX` |
| `1002cd26` | `74 0b` | `JZ 0x1002cd33` |
| `1002cd28` | `3b ce` | `CMP ECX,ESI` |
| `1002cd2a` | `75 13` | `JNZ 0x1002cd3f` |
| `1002cd2c` | `0d 00 60 00 00` | `OR EAX,0x6000` |
| `1002cd31` | `eb 0c` | `JMP 0x1002cd3f` |
| `1002cd33` | `0d 00 40 00 00` | `OR EAX,0x4000` |
| `1002cd38` | `eb 05` | `JMP 0x1002cd3f` |
| `1002cd3a` | `0d 00 20 00 00` | `OR EAX,0x2000` |
| `1002cd3f` | `b9 00 00 00 03` | `MOV ECX,0x3000000` |
| `1002cd44` | `5f` | `POP EDI` |
| `1002cd45` | `23 d1` | `AND EDX,ECX` |
| `1002cd47` | `5e` | `POP ESI` |
| `1002cd48` | `5b` | `POP EBX` |
| `1002cd49` | `81 fa 00 00 00 01` | `CMP EDX,0x1000000` |
| `1002cd4f` | `74 16` | `JZ 0x1002cd67` |
| `1002cd51` | `81 fa 00 00 00 02` | `CMP EDX,0x2000000` |
| `1002cd57` | `74 0a` | `JZ 0x1002cd63` |
| `1002cd59` | `3b d1` | `CMP EDX,ECX` |
| `1002cd5b` | `75 0f` | `JNZ 0x1002cd6c` |
| `1002cd5d` | `0d 00 80 00 00` | `OR EAX,0x8000` |
| `1002cd62` | `c3` | `RET` |
| `1002cd63` | `83 c8 40` | `OR EAX,0x40` |
| `1002cd66` | `c3` | `RET` |
| `1002cd67` | `0d 40 80 00 00` | `OR EAX,0x8040` |
| `1002cd6c` | `c3` | `RET` |
