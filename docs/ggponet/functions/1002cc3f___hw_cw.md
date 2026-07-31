# 1002cc3f `__hw_cw`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002cc3f |
| `name` | __hw_cw |
| `namespace` | Global |
| `signature` | undefined __hw_cw(void) |
| `size_bytes` | 142 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __hw_cw |

## Decompiled C

```c

/* Library Function - Single Match
    __hw_cw
   
   Library: Visual Studio 2008 Release */

uint __hw_cw(void)

{
  uint uVar1;
  uint uVar2;
  uint unaff_EBX;
  
  uVar1 = (uint)((unaff_EBX & 0x10) != 0);
  if ((unaff_EBX & 8) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((unaff_EBX & 4) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((unaff_EBX & 2) != 0) {
    uVar1 = uVar1 | 0x10;
  }
  if ((unaff_EBX & 1) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  if ((unaff_EBX & 0x80000) != 0) {
    uVar1 = uVar1 | 2;
  }
  uVar2 = unaff_EBX & 0x300;
  if (uVar2 != 0) {
    if (uVar2 == 0x100) {
      uVar1 = uVar1 | 0x400;
    }
    else if (uVar2 == 0x200) {
      uVar1 = uVar1 | 0x800;
    }
    else if (uVar2 == 0x300) {
      uVar1 = uVar1 | 0xc00;
    }
  }
  if ((unaff_EBX & 0x30000) == 0) {
    uVar1 = uVar1 | 0x300;
  }
  else if ((unaff_EBX & 0x30000) == 0x10000) {
    uVar1 = uVar1 | 0x200;
  }
  if ((unaff_EBX & 0x40000) != 0) {
    uVar1 = uVar1 | 0x1000;
  }
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002ce30` | __control87 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002cc3f` | `33 c0` | `XOR EAX,EAX` |
| `1002cc41` | `f6 c3 10` | `TEST BL,0x10` |
| `1002cc44` | `74 01` | `JZ 0x1002cc47` |
| `1002cc46` | `40` | `INC EAX` |
| `1002cc47` | `f6 c3 08` | `TEST BL,0x8` |
| `1002cc4a` | `74 03` | `JZ 0x1002cc4f` |
| `1002cc4c` | `83 c8 04` | `OR EAX,0x4` |
| `1002cc4f` | `f6 c3 04` | `TEST BL,0x4` |
| `1002cc52` | `74 03` | `JZ 0x1002cc57` |
| `1002cc54` | `83 c8 08` | `OR EAX,0x8` |
| `1002cc57` | `f6 c3 02` | `TEST BL,0x2` |
| `1002cc5a` | `74 03` | `JZ 0x1002cc5f` |
| `1002cc5c` | `83 c8 10` | `OR EAX,0x10` |
| `1002cc5f` | `f6 c3 01` | `TEST BL,0x1` |
| `1002cc62` | `74 03` | `JZ 0x1002cc67` |
| `1002cc64` | `83 c8 20` | `OR EAX,0x20` |
| `1002cc67` | `f7 c3 00 00 08 00` | `TEST EBX,0x80000` |
| `1002cc6d` | `74 03` | `JZ 0x1002cc72` |
| `1002cc6f` | `83 c8 02` | `OR EAX,0x2` |
| `1002cc72` | `8b cb` | `MOV ECX,EBX` |
| `1002cc74` | `ba 00 03 00 00` | `MOV EDX,0x300` |
| `1002cc79` | `23 ca` | `AND ECX,EDX` |
| `1002cc7b` | `56` | `PUSH ESI` |
| `1002cc7c` | `be 00 02 00 00` | `MOV ESI,0x200` |
| `1002cc81` | `74 23` | `JZ 0x1002cca6` |
| `1002cc83` | `81 f9 00 01 00 00` | `CMP ECX,0x100` |
| `1002cc89` | `74 16` | `JZ 0x1002cca1` |
| `1002cc8b` | `3b ce` | `CMP ECX,ESI` |
| `1002cc8d` | `74 0b` | `JZ 0x1002cc9a` |
| `1002cc8f` | `3b ca` | `CMP ECX,EDX` |
| `1002cc91` | `75 13` | `JNZ 0x1002cca6` |
| `1002cc93` | `0d 00 0c 00 00` | `OR EAX,0xc00` |
| `1002cc98` | `eb 0c` | `JMP 0x1002cca6` |
| `1002cc9a` | `0d 00 08 00 00` | `OR EAX,0x800` |
| `1002cc9f` | `eb 05` | `JMP 0x1002cca6` |
| `1002cca1` | `0d 00 04 00 00` | `OR EAX,0x400` |
| `1002cca6` | `8b cb` | `MOV ECX,EBX` |
| `1002cca8` | `81 e1 00 00 03 00` | `AND ECX,0x30000` |
| `1002ccae` | `74 0c` | `JZ 0x1002ccbc` |
| `1002ccb0` | `81 f9 00 00 01 00` | `CMP ECX,0x10000` |
| `1002ccb6` | `75 06` | `JNZ 0x1002ccbe` |
| `1002ccb8` | `0b c6` | `OR EAX,ESI` |
| `1002ccba` | `eb 02` | `JMP 0x1002ccbe` |
| `1002ccbc` | `0b c2` | `OR EAX,EDX` |
| `1002ccbe` | `5e` | `POP ESI` |
| `1002ccbf` | `f7 c3 00 00 04 00` | `TEST EBX,0x40000` |
| `1002ccc5` | `74 05` | `JZ 0x1002cccc` |
| `1002ccc7` | `0d 00 10 00 00` | `OR EAX,0x1000` |
| `1002cccc` | `c3` | `RET` |
