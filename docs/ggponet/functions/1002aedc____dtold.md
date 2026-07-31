# 1002aedc `___dtold`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002aedc |
| `name` | ___dtold |
| `namespace` | Global |
| `signature` | undefined ___dtold(void) |
| `size_bytes` | 189 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___dtold |

## Decompiled C

```c

/* Library Function - Single Match
    ___dtold
   
   Library: Visual Studio 2008 Release */

void ___dtold(uint *param_1,uint *param_2)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint local_8;
  
  uVar2 = *(ushort *)((int)param_2 + 6) >> 4;
  uVar4 = *(ushort *)((int)param_2 + 6) & 0x8000;
  uVar3 = uVar2 & 0x7ff;
  uVar1 = *param_2;
  local_8 = 0x80000000;
  if ((uVar2 & 0x7ff) == 0) {
    if (((param_2[1] & 0xfffff) == 0) && (uVar1 == 0)) {
      param_1[1] = 0;
      *param_1 = 0;
      goto LAB_1002af90;
    }
    uVar3 = uVar3 + 0x3c01;
    local_8 = 0;
  }
  else if (uVar3 == 0x7ff) {
    uVar3 = 0x7fff;
  }
  else {
    uVar3 = uVar3 + 0x3c00;
  }
  param_1[1] = uVar1 >> 0x15 | (param_2[1] & 0xfffff) << 0xb | local_8;
  *param_1 = uVar1 << 0xb;
  while (local_8 == 0) {
    uVar1 = param_1[1];
    uVar3 = uVar3 - 1;
    param_1[1] = uVar1 * 2 | *param_1 >> 0x1f;
    *param_1 = *param_1 * 2;
    local_8 = uVar1 * 2 & 0x80000000;
  }
  uVar4 = uVar4 | uVar3;
LAB_1002af90:
  *(ushort *)(param_1 + 2) = uVar4;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1002afbf` | __fltout2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002aedc` | `8b ff` | `MOV EDI,EDI` |
| `1002aede` | `55` | `PUSH EBP` |
| `1002aedf` | `8b ec` | `MOV EBP,ESP` |
| `1002aee1` | `51` | `PUSH ECX` |
| `1002aee2` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `1002aee5` | `0f b7 42 06` | `MOVZX EAX,word ptr [EDX + 0x6]` |
| `1002aee9` | `53` | `PUSH EBX` |
| `1002aeea` | `8b c8` | `MOV ECX,EAX` |
| `1002aeec` | `56` | `PUSH ESI` |
| `1002aeed` | `57` | `PUSH EDI` |
| `1002aeee` | `c1 e9 04` | `SHR ECX,0x4` |
| `1002aef1` | `25 00 80 00 00` | `AND EAX,0x8000` |
| `1002aef6` | `bf ff 07 00 00` | `MOV EDI,0x7ff` |
| `1002aefb` | `23 cf` | `AND ECX,EDI` |
| `1002aefd` | `89 45 0c` | `MOV dword ptr [EBP + 0xc],EAX` |
| `1002af00` | `8b 42 04` | `MOV EAX,dword ptr [EDX + 0x4]` |
| `1002af03` | `8b 12` | `MOV EDX,dword ptr [EDX]` |
| `1002af05` | `0f b7 d9` | `MOVZX EBX,CX` |
| `1002af08` | `be 00 00 00 80` | `MOV ESI,0x80000000` |
| `1002af0d` | `25 ff ff 0f 00` | `AND EAX,0xfffff` |
| `1002af12` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `1002af15` | `85 db` | `TEST EBX,EBX` |
| `1002af17` | `74 13` | `JZ 0x1002af2c` |
| `1002af19` | `3b df` | `CMP EBX,EDI` |
| `1002af1b` | `74 08` | `JZ 0x1002af25` |
| `1002af1d` | `81 c1 00 3c 00 00` | `ADD ECX,0x3c00` |
| `1002af23` | `eb 28` | `JMP 0x1002af4d` |
| `1002af25` | `bf ff 7f 00 00` | `MOV EDI,0x7fff` |
| `1002af2a` | `eb 24` | `JMP 0x1002af50` |
| `1002af2c` | `33 db` | `XOR EBX,EBX` |
| `1002af2e` | `3b c3` | `CMP EAX,EBX` |
| `1002af30` | `75 12` | `JNZ 0x1002af44` |
| `1002af32` | `3b d3` | `CMP EDX,EBX` |
| `1002af34` | `75 0e` | `JNZ 0x1002af44` |
| `1002af36` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002af39` | `66 8b 4d 0c` | `MOV CX,word ptr [EBP + 0xc]` |
| `1002af3d` | `89 58 04` | `MOV dword ptr [EAX + 0x4],EBX` |
| `1002af40` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1002af42` | `eb 4c` | `JMP 0x1002af90` |
| `1002af44` | `81 c1 01 3c 00 00` | `ADD ECX,0x3c01` |
| `1002af4a` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1002af4d` | `0f b7 f9` | `MOVZX EDI,CX` |
| `1002af50` | `8b ca` | `MOV ECX,EDX` |
| `1002af52` | `c1 e9 15` | `SHR ECX,0x15` |
| `1002af55` | `c1 e0 0b` | `SHL EAX,0xb` |
| `1002af58` | `0b c8` | `OR ECX,EAX` |
| `1002af5a` | `0b 4d fc` | `OR ECX,dword ptr [EBP + -0x4]` |
| `1002af5d` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002af60` | `c1 e2 0b` | `SHL EDX,0xb` |
| `1002af63` | `89 48 04` | `MOV dword ptr [EAX + 0x4],ECX` |
| `1002af66` | `89 10` | `MOV dword ptr [EAX],EDX` |
| `1002af68` | `85 ce` | `TEST ESI,ECX` |
| `1002af6a` | `75 1f` | `JNZ 0x1002af8b` |
| `1002af6c` | `8b 08` | `MOV ECX,dword ptr [EAX]` |
| `1002af6e` | `8b 50 04` | `MOV EDX,dword ptr [EAX + 0x4]` |
| `1002af71` | `8b d9` | `MOV EBX,ECX` |
| `1002af73` | `03 d2` | `ADD EDX,EDX` |
| `1002af75` | `c1 eb 1f` | `SHR EBX,0x1f` |
| `1002af78` | `0b d3` | `OR EDX,EBX` |
| `1002af7a` | `03 c9` | `ADD ECX,ECX` |
| `1002af7c` | `81 c7 ff ff 00 00` | `ADD EDI,0xffff` |
| `1002af82` | `89 50 04` | `MOV dword ptr [EAX + 0x4],EDX` |
| `1002af85` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1002af87` | `85 d6` | `TEST ESI,EDX` |
| `1002af89` | `74 e1` | `JZ 0x1002af6c` |
| `1002af8b` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002af8e` | `0b cf` | `OR ECX,EDI` |
| `1002af90` | `5f` | `POP EDI` |
| `1002af91` | `5e` | `POP ESI` |
| `1002af92` | `66 89 48 08` | `MOV word ptr [EAX + 0x8],CX` |
| `1002af96` | `5b` | `POP EBX` |
| `1002af97` | `c9` | `LEAVE` |
| `1002af98` | `c3` | `RET` |
