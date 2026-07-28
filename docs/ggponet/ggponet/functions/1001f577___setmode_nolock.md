# 1001f577 `__setmode_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f577 |
| `name` | __setmode_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __setmode_nolock(int _FileHandle, int _Mode) |
| `size_bytes` | 188 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __setmode_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __setmode_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __setmode_nolock(int _FileHandle,int _Mode)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  
  piVar2 = &DAT_13439540 + (_FileHandle >> 5);
  iVar7 = (_FileHandle & 0x1fU) * 0x40;
  iVar1 = *piVar2 + iVar7;
  cVar3 = *(char *)(iVar1 + 0x24);
  bVar4 = *(byte *)(iVar1 + 4);
  if (_Mode == 0x4000) {
    *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 0x80;
    pbVar5 = (byte *)(*piVar2 + 0x24 + iVar7);
    *pbVar5 = *pbVar5 & 0x80;
  }
  else if (_Mode == 0x8000) {
    *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0x7f;
  }
  else {
    if ((_Mode == 0x10000) || (_Mode == 0x20000)) {
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 0x80;
      pbVar5 = (byte *)(*piVar2 + 0x24 + iVar7);
      bVar6 = *pbVar5 & 0x82 | 2;
    }
    else {
      if (_Mode != 0x40000) goto LAB_1001f615;
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 0x80;
      pbVar5 = (byte *)(*piVar2 + 0x24 + iVar7);
      bVar6 = *pbVar5 & 0x81 | 1;
    }
    *pbVar5 = bVar6;
  }
LAB_1001f615:
  if ((bVar4 & 0x80) == 0) {
    return 0x8000;
  }
  return (-(uint)((char)(cVar3 * '\x02') >> 1 != '\0') & 0xc000) + 0x4000;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001f3e8` | __chsize_nolock |
| `1001f42c` | __chsize_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f589` | `13439540` | `DATA` | DAT_13439540 |
| `1001f590` | `13439540` | `DATA` | DAT_13439540 |
| `1001f5dc` | `13439540` | `DATA` | DAT_13439540 |
| `1001f5f2` | `13439540` | `DATA` | DAT_13439540 |
| `1001f60c` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f577` | `8b ff` | `MOV EDI,EDI` |
| `1001f579` | `55` | `PUSH EBP` |
| `1001f57a` | `8b ec` | `MOV EBP,ESP` |
| `1001f57c` | `53` | `PUSH EBX` |
| `1001f57d` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `1001f580` | `56` | `PUSH ESI` |
| `1001f581` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f584` | `8b c6` | `MOV EAX,ESI` |
| `1001f586` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001f589` | `8d 14 85 40 95 43 13` | `LEA EDX,[EAX*0x4 + 0x13439540]` |
| `1001f590` | `8b 02` | `MOV EAX,dword ptr [EDX]` |
| `1001f592` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001f595` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001f598` | `8d 0c 30` | `LEA ECX,[EAX + ESI*0x1]` |
| `1001f59b` | `8a 41 24` | `MOV AL,byte ptr [ECX + 0x24]` |
| `1001f59e` | `02 c0` | `ADD AL,AL` |
| `1001f5a0` | `57` | `PUSH EDI` |
| `1001f5a1` | `0f b6 79 04` | `MOVZX EDI,byte ptr [ECX + 0x4]` |
| `1001f5a5` | `0f be c0` | `MOVSX EAX,AL` |
| `1001f5a8` | `81 e7 80 00 00 00` | `AND EDI,0x80` |
| `1001f5ae` | `d1 f8` | `SAR EAX,0x1` |
| `1001f5b0` | `81 fb 00 40 00 00` | `CMP EBX,0x4000` |
| `1001f5b6` | `74 50` | `JZ 0x1001f608` |
| `1001f5b8` | `81 fb 00 80 00 00` | `CMP EBX,0x8000` |
| `1001f5be` | `74 42` | `JZ 0x1001f602` |
| `1001f5c0` | `81 fb 00 00 01 00` | `CMP EBX,0x10000` |
| `1001f5c6` | `74 26` | `JZ 0x1001f5ee` |
| `1001f5c8` | `81 fb 00 00 02 00` | `CMP EBX,0x20000` |
| `1001f5ce` | `74 1e` | `JZ 0x1001f5ee` |
| `1001f5d0` | `81 fb 00 00 04 00` | `CMP EBX,0x40000` |
| `1001f5d6` | `75 3d` | `JNZ 0x1001f615` |
| `1001f5d8` | `80 49 04 80` | `OR byte ptr [ECX + 0x4],0x80` |
| `1001f5dc` | `8b 0a` | `MOV ECX,dword ptr [EDX]` |
| `1001f5de` | `8d 4c 31 24` | `LEA ECX,[ECX + ESI*0x1 + 0x24]` |
| `1001f5e2` | `8a 11` | `MOV DL,byte ptr [ECX]` |
| `1001f5e4` | `80 e2 81` | `AND DL,0x81` |
| `1001f5e7` | `80 ca 01` | `OR DL,0x1` |
| `1001f5ea` | `88 11` | `MOV byte ptr [ECX],DL` |
| `1001f5ec` | `eb 27` | `JMP 0x1001f615` |
| `1001f5ee` | `80 49 04 80` | `OR byte ptr [ECX + 0x4],0x80` |
| `1001f5f2` | `8b 0a` | `MOV ECX,dword ptr [EDX]` |
| `1001f5f4` | `8d 4c 31 24` | `LEA ECX,[ECX + ESI*0x1 + 0x24]` |
| `1001f5f8` | `8a 11` | `MOV DL,byte ptr [ECX]` |
| `1001f5fa` | `80 e2 82` | `AND DL,0x82` |
| `1001f5fd` | `80 ca 02` | `OR DL,0x2` |
| `1001f600` | `eb e8` | `JMP 0x1001f5ea` |
| `1001f602` | `80 61 04 7f` | `AND byte ptr [ECX + 0x4],0x7f` |
| `1001f606` | `eb 0d` | `JMP 0x1001f615` |
| `1001f608` | `80 49 04 80` | `OR byte ptr [ECX + 0x4],0x80` |
| `1001f60c` | `8b 0a` | `MOV ECX,dword ptr [EDX]` |
| `1001f60e` | `8d 4c 31 24` | `LEA ECX,[ECX + ESI*0x1 + 0x24]` |
| `1001f612` | `80 21 80` | `AND byte ptr [ECX],0x80` |
| `1001f615` | `85 ff` | `TEST EDI,EDI` |
| `1001f617` | `5f` | `POP EDI` |
| `1001f618` | `5e` | `POP ESI` |
| `1001f619` | `5b` | `POP EBX` |
| `1001f61a` | `75 07` | `JNZ 0x1001f623` |
| `1001f61c` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1001f621` | `5d` | `POP EBP` |
| `1001f622` | `c3` | `RET` |
| `1001f623` | `f7 d8` | `NEG EAX` |
| `1001f625` | `1b c0` | `SBB EAX,EAX` |
| `1001f627` | `25 00 c0 00 00` | `AND EAX,0xc000` |
| `1001f62c` | `05 00 40 00 00` | `ADD EAX,0x4000` |
| `1001f631` | `5d` | `POP EBP` |
| `1001f632` | `c3` | `RET` |
