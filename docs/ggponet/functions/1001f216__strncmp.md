# 1001f216 `_strncmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f216 |
| `name` | _strncmp |
| `namespace` | Global |
| `signature` | int __cdecl _strncmp(char * _Str1, char * _Str2, size_t _MaxCount) |
| `size_bytes` | 192 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strncmp |

## Decompiled C

```c

/* Library Function - Single Match
    _strncmp
   
   Library: Visual Studio 2008 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  byte *pbVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint local_8;
  
  local_8 = 0;
  if (_MaxCount != 0) {
    if ((3 < _MaxCount) && (pbVar1 = (byte *)_Str1, pbVar3 = (byte *)_Str2, _MaxCount != 4)) {
      do {
        _Str1 = (char *)(pbVar1 + 4);
        _Str2 = (char *)(pbVar3 + 4);
        if ((*pbVar1 == 0) || (*pbVar1 != *pbVar3)) {
          uVar2 = (uint)*pbVar1;
          uVar4 = (uint)*pbVar3;
          goto LAB_1001f2d2;
        }
        if ((pbVar1[1] == 0) || (pbVar1[1] != pbVar3[1])) {
          uVar2 = (uint)pbVar1[1];
          uVar4 = (uint)pbVar3[1];
          goto LAB_1001f2d2;
        }
        if ((pbVar1[2] == 0) || (pbVar1[2] != pbVar3[2])) {
          uVar2 = (uint)pbVar1[2];
          uVar4 = (uint)pbVar3[2];
          goto LAB_1001f2d2;
        }
        if ((pbVar1[3] == 0) || (pbVar1[3] != pbVar3[3])) {
          uVar2 = (uint)pbVar1[3];
          uVar4 = (uint)pbVar3[3];
          goto LAB_1001f2d2;
        }
        local_8 = local_8 + 4;
        pbVar1 = (byte *)_Str1;
        pbVar3 = (byte *)_Str2;
      } while (local_8 < _MaxCount - 4);
    }
    for (; local_8 < _MaxCount; local_8 = local_8 + 1) {
      if ((*_Str1 == 0) || (*_Str1 != *_Str2)) {
        uVar2 = (uint)(byte)*_Str1;
        uVar4 = (uint)(byte)*_Str2;
LAB_1001f2d2:
        return uVar2 - uVar4;
      }
      _Str1 = _Str1 + 1;
      _Str2 = _Str2 + 1;
    }
  }
  return 0;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001d827` | __mbsnbcmp_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f216` | `8b ff` | `MOV EDI,EDI` |
| `1001f218` | `55` | `PUSH EBP` |
| `1001f219` | `8b ec` | `MOV EBP,ESP` |
| `1001f21b` | `51` | `PUSH ECX` |
| `1001f21c` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001f220` | `53` | `PUSH EBX` |
| `1001f221` | `8b 5d 10` | `MOV EBX,dword ptr [EBP + 0x10]` |
| `1001f224` | `85 db` | `TEST EBX,EBX` |
| `1001f226` | `75 07` | `JNZ 0x1001f22f` |
| `1001f228` | `33 c0` | `XOR EAX,EAX` |
| `1001f22a` | `e9 9a 00 00 00` | `JMP 0x1001f2c9` |
| `1001f22f` | `57` | `PUSH EDI` |
| `1001f230` | `83 fb 04` | `CMP EBX,0x4` |
| `1001f233` | `72 75` | `JC 0x1001f2aa` |
| `1001f235` | `8d 7b fc` | `LEA EDI,[EBX + -0x4]` |
| `1001f238` | `85 ff` | `TEST EDI,EDI` |
| `1001f23a` | `76 6e` | `JBE 0x1001f2aa` |
| `1001f23c` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001f23f` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001f242` | `8a 10` | `MOV DL,byte ptr [EAX]` |
| `1001f244` | `83 c0 04` | `ADD EAX,0x4` |
| `1001f247` | `83 c1 04` | `ADD ECX,0x4` |
| `1001f24a` | `84 d2` | `TEST DL,DL` |
| `1001f24c` | `74 52` | `JZ 0x1001f2a0` |
| `1001f24e` | `3a 51 fc` | `CMP DL,byte ptr [ECX + -0x4]` |
| `1001f251` | `75 4d` | `JNZ 0x1001f2a0` |
| `1001f253` | `8a 50 fd` | `MOV DL,byte ptr [EAX + -0x3]` |
| `1001f256` | `84 d2` | `TEST DL,DL` |
| `1001f258` | `74 3c` | `JZ 0x1001f296` |
| `1001f25a` | `3a 51 fd` | `CMP DL,byte ptr [ECX + -0x3]` |
| `1001f25d` | `75 37` | `JNZ 0x1001f296` |
| `1001f25f` | `8a 50 fe` | `MOV DL,byte ptr [EAX + -0x2]` |
| `1001f262` | `84 d2` | `TEST DL,DL` |
| `1001f264` | `74 26` | `JZ 0x1001f28c` |
| `1001f266` | `3a 51 fe` | `CMP DL,byte ptr [ECX + -0x2]` |
| `1001f269` | `75 21` | `JNZ 0x1001f28c` |
| `1001f26b` | `8a 50 ff` | `MOV DL,byte ptr [EAX + -0x1]` |
| `1001f26e` | `84 d2` | `TEST DL,DL` |
| `1001f270` | `74 10` | `JZ 0x1001f282` |
| `1001f272` | `3a 51 ff` | `CMP DL,byte ptr [ECX + -0x1]` |
| `1001f275` | `75 0b` | `JNZ 0x1001f282` |
| `1001f277` | `83 45 fc 04` | `ADD dword ptr [EBP + -0x4],0x4` |
| `1001f27b` | `39 7d fc` | `CMP dword ptr [EBP + -0x4],EDI` |
| `1001f27e` | `72 c2` | `JC 0x1001f242` |
| `1001f280` | `eb 3f` | `JMP 0x1001f2c1` |
| `1001f282` | `0f b6 40 ff` | `MOVZX EAX,byte ptr [EAX + -0x1]` |
| `1001f286` | `0f b6 49 ff` | `MOVZX ECX,byte ptr [ECX + -0x1]` |
| `1001f28a` | `eb 46` | `JMP 0x1001f2d2` |
| `1001f28c` | `0f b6 40 fe` | `MOVZX EAX,byte ptr [EAX + -0x2]` |
| `1001f290` | `0f b6 49 fe` | `MOVZX ECX,byte ptr [ECX + -0x2]` |
| `1001f294` | `eb 3c` | `JMP 0x1001f2d2` |
| `1001f296` | `0f b6 40 fd` | `MOVZX EAX,byte ptr [EAX + -0x3]` |
| `1001f29a` | `0f b6 49 fd` | `MOVZX ECX,byte ptr [ECX + -0x3]` |
| `1001f29e` | `eb 32` | `JMP 0x1001f2d2` |
| `1001f2a0` | `0f b6 40 fc` | `MOVZX EAX,byte ptr [EAX + -0x4]` |
| `1001f2a4` | `0f b6 49 fc` | `MOVZX ECX,byte ptr [ECX + -0x4]` |
| `1001f2a8` | `eb 28` | `JMP 0x1001f2d2` |
| `1001f2aa` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001f2ad` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001f2b0` | `eb 0f` | `JMP 0x1001f2c1` |
| `1001f2b2` | `8a 10` | `MOV DL,byte ptr [EAX]` |
| `1001f2b4` | `84 d2` | `TEST DL,DL` |
| `1001f2b6` | `74 14` | `JZ 0x1001f2cc` |
| `1001f2b8` | `3a 11` | `CMP DL,byte ptr [ECX]` |
| `1001f2ba` | `75 10` | `JNZ 0x1001f2cc` |
| `1001f2bc` | `40` | `INC EAX` |
| `1001f2bd` | `41` | `INC ECX` |
| `1001f2be` | `ff 45 fc` | `INC dword ptr [EBP + -0x4]` |
| `1001f2c1` | `39 5d fc` | `CMP dword ptr [EBP + -0x4],EBX` |
| `1001f2c4` | `72 ec` | `JC 0x1001f2b2` |
| `1001f2c6` | `33 c0` | `XOR EAX,EAX` |
| `1001f2c8` | `5f` | `POP EDI` |
| `1001f2c9` | `5b` | `POP EBX` |
| `1001f2ca` | `c9` | `LEAVE` |
| `1001f2cb` | `c3` | `RET` |
| `1001f2cc` | `0f b6 00` | `MOVZX EAX,byte ptr [EAX]` |
| `1001f2cf` | `0f b6 09` | `MOVZX ECX,byte ptr [ECX]` |
| `1001f2d2` | `2b c1` | `SUB EAX,ECX` |
| `1001f2d4` | `eb f2` | `JMP 0x1001f2c8` |
