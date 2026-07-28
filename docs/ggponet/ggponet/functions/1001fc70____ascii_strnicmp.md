# 1001fc70 `___ascii_strnicmp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fc70 |
| `name` | ___ascii_strnicmp |
| `namespace` | Global |
| `signature` | int __cdecl ___ascii_strnicmp(char * _Str1, char * _Str2, size_t _MaxCount) |
| `size_bytes` | 97 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___ascii_strnicmp |

## Decompiled C

```c

/* Library Function - Single Match
    ___ascii_strnicmp
   
   Library: Visual Studio 2008 Release */

int __cdecl ___ascii_strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = 0;
  if (_MaxCount != 0) {
    do {
      bVar2 = *_Str1;
      cVar1 = *_Str2;
      uVar3 = CONCAT11(bVar2,cVar1);
      if (bVar2 == 0) break;
      uVar3 = CONCAT11(bVar2,cVar1);
      uVar4 = (uint)uVar3;
      if (cVar1 == '\0') break;
      _Str1 = _Str1 + 1;
      _Str2 = _Str2 + 1;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar4 = (uint)CONCAT11(bVar2 + 0x20,cVar1);
      }
      uVar3 = (ushort)uVar4;
      bVar2 = (byte)uVar4;
      if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
        uVar3 = (ushort)CONCAT31((int3)(uVar4 >> 8),bVar2 + 0x20);
      }
      bVar2 = (byte)(uVar3 >> 8);
      bVar6 = bVar2 < (byte)uVar3;
      if (bVar2 != (byte)uVar3) goto LAB_1001fcc1;
      _MaxCount = _MaxCount - 1;
    } while (_MaxCount != 0);
    iVar5 = 0;
    bVar2 = (byte)(uVar3 >> 8);
    bVar6 = bVar2 < (byte)uVar3;
    if (bVar2 != (byte)uVar3) {
LAB_1001fcc1:
      iVar5 = -1;
      if (!bVar6) {
        iVar5 = 1;
      }
    }
  }
  return iVar5;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001f708` | __strnicmp_l |
| `1001f7a2` | __strnicmp |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fc70` | `55` | `PUSH EBP` |
| `1001fc71` | `8b ec` | `MOV EBP,ESP` |
| `1001fc73` | `57` | `PUSH EDI` |
| `1001fc74` | `56` | `PUSH ESI` |
| `1001fc75` | `53` | `PUSH EBX` |
| `1001fc76` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `1001fc79` | `0b c9` | `OR ECX,ECX` |
| `1001fc7b` | `74 4d` | `JZ 0x1001fcca` |
| `1001fc7d` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001fc80` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001fc83` | `b7 41` | `MOV BH,0x41` |
| `1001fc85` | `b3 5a` | `MOV BL,0x5a` |
| `1001fc87` | `b6 20` | `MOV DH,0x20` |
| `1001fc89` | `8d 49 00` | `LEA ECX,[ECX]` |
| `1001fc8c` | `8a 26` | `MOV AH,byte ptr [ESI]` |
| `1001fc8e` | `0a e4` | `OR AH,AH` |
| `1001fc90` | `8a 07` | `MOV AL,byte ptr [EDI]` |
| `1001fc92` | `74 27` | `JZ 0x1001fcbb` |
| `1001fc94` | `0a c0` | `OR AL,AL` |
| `1001fc96` | `74 23` | `JZ 0x1001fcbb` |
| `1001fc98` | `83 c6 01` | `ADD ESI,0x1` |
| `1001fc9b` | `83 c7 01` | `ADD EDI,0x1` |
| `1001fc9e` | `3a e7` | `CMP AH,BH` |
| `1001fca0` | `72 06` | `JC 0x1001fca8` |
| `1001fca2` | `3a e3` | `CMP AH,BL` |
| `1001fca4` | `77 02` | `JA 0x1001fca8` |
| `1001fca6` | `02 e6` | `ADD AH,DH` |
| `1001fca8` | `3a c7` | `CMP AL,BH` |
| `1001fcaa` | `72 06` | `JC 0x1001fcb2` |
| `1001fcac` | `3a c3` | `CMP AL,BL` |
| `1001fcae` | `77 02` | `JA 0x1001fcb2` |
| `1001fcb0` | `02 c6` | `ADD AL,DH` |
| `1001fcb2` | `3a e0` | `CMP AH,AL` |
| `1001fcb4` | `75 0b` | `JNZ 0x1001fcc1` |
| `1001fcb6` | `83 e9 01` | `SUB ECX,0x1` |
| `1001fcb9` | `75 d1` | `JNZ 0x1001fc8c` |
| `1001fcbb` | `33 c9` | `XOR ECX,ECX` |
| `1001fcbd` | `3a e0` | `CMP AH,AL` |
| `1001fcbf` | `74 09` | `JZ 0x1001fcca` |
| `1001fcc1` | `b9 ff ff ff ff` | `MOV ECX,0xffffffff` |
| `1001fcc6` | `72 02` | `JC 0x1001fcca` |
| `1001fcc8` | `f7 d9` | `NEG ECX` |
| `1001fcca` | `8b c1` | `MOV EAX,ECX` |
| `1001fccc` | `5b` | `POP EBX` |
| `1001fccd` | `5e` | `POP ESI` |
| `1001fcce` | `5f` | `POP EDI` |
| `1001fccf` | `c9` | `LEAVE` |
| `1001fcd0` | `c3` | `RET` |
