# 1001db30 `__free_osfhnd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001db30 |
| `name` | __free_osfhnd |
| `namespace` | Global |
| `signature` | int __cdecl __free_osfhnd(int param_1) |
| `size_bytes` | 134 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __free_osfhnd |

## Decompiled C

```c

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 2008 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  ulong *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((-1 < param_1) && ((uint)param_1 < DAT_13439530)) {
    iVar3 = (param_1 & 0x1fU) * 0x40;
    piVar1 = (int *)((&DAT_13439540)[param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_10038a80 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1001db92;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_1001db92:
      *(undefined4 *)(iVar3 + (&DAT_13439540)[param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  piVar1 = __errno();
  *piVar1 = 9;
  puVar2 = ___doserrno();
  *puVar2 = 0;
  return -1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001db8c` | `EXTERNAL:0000002d` | `COMPUTED_CALL` | KERNEL32.DLL::SetStdHandle | `` |
| `1001db9c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001dba7` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |

## Callers

| From | Function |
| --- | --- |
| `1001d499` | __tsopen_nolock |
| `10018ce0` | __close_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001db41` | `13439530` | `READ` | DAT_13439530 |
| `1001db50` | `13439540` | `DATA` | DAT_13439540 |
| `1001db57` | `13439540` | `DATA` | DAT_13439540 |
| `1001db6c` | `10038a80` | `READ` | DAT_10038a80 |
| `1001db8c` | `1002e06c` | `READ` | PTR_SetStdHandle_1002e06c |
| `1001db92` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001db30` | `8b ff` | `MOV EDI,EDI` |
| `1001db32` | `55` | `PUSH EBP` |
| `1001db33` | `8b ec` | `MOV EBP,ESP` |
| `1001db35` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001db38` | `53` | `PUSH EBX` |
| `1001db39` | `33 db` | `XOR EBX,EBX` |
| `1001db3b` | `3b cb` | `CMP ECX,EBX` |
| `1001db3d` | `56` | `PUSH ESI` |
| `1001db3e` | `57` | `PUSH EDI` |
| `1001db3f` | `7c 5b` | `JL 0x1001db9c` |
| `1001db41` | `3b 0d 30 95 43 13` | `CMP ECX,dword ptr [0x13439530]` |
| `1001db47` | `73 53` | `JNC 0x1001db9c` |
| `1001db49` | `8b c1` | `MOV EAX,ECX` |
| `1001db4b` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001db4e` | `8b f1` | `MOV ESI,ECX` |
| `1001db50` | `8d 3c 85 40 95 43 13` | `LEA EDI,[EAX*0x4 + 0x13439540]` |
| `1001db57` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001db59` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001db5c` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001db5f` | `03 c6` | `ADD EAX,ESI` |
| `1001db61` | `f6 40 04 01` | `TEST byte ptr [EAX + 0x4],0x1` |
| `1001db65` | `74 35` | `JZ 0x1001db9c` |
| `1001db67` | `83 38 ff` | `CMP dword ptr [EAX],-0x1` |
| `1001db6a` | `74 30` | `JZ 0x1001db9c` |
| `1001db6c` | `83 3d 80 8a 03 10 01` | `CMP dword ptr [0x10038a80],0x1` |
| `1001db73` | `75 1d` | `JNZ 0x1001db92` |
| `1001db75` | `2b cb` | `SUB ECX,EBX` |
| `1001db77` | `74 10` | `JZ 0x1001db89` |
| `1001db79` | `49` | `DEC ECX` |
| `1001db7a` | `74 08` | `JZ 0x1001db84` |
| `1001db7c` | `49` | `DEC ECX` |
| `1001db7d` | `75 13` | `JNZ 0x1001db92` |
| `1001db7f` | `53` | `PUSH EBX` |
| `1001db80` | `6a f4` | `PUSH -0xc` |
| `1001db82` | `eb 08` | `JMP 0x1001db8c` |
| `1001db84` | `53` | `PUSH EBX` |
| `1001db85` | `6a f5` | `PUSH -0xb` |
| `1001db87` | `eb 03` | `JMP 0x1001db8c` |
| `1001db89` | `53` | `PUSH EBX` |
| `1001db8a` | `6a f6` | `PUSH -0xa` |
| `1001db8c` | `ff 15 6c e0 02 10` | `CALL dword ptr [0x1002e06c]` |
| `1001db92` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001db94` | `83 0c 06 ff` | `OR dword ptr [ESI + EAX*0x1],0xffffffff` |
| `1001db98` | `33 c0` | `XOR EAX,EAX` |
| `1001db9a` | `eb 15` | `JMP 0x1001dbb1` |
| `1001db9c` | `e8 68 75 ff ff` | `CALL 0x10015109` |
| `1001dba1` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001dba7` | `e8 70 75 ff ff` | `CALL 0x1001511c` |
| `1001dbac` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001dbae` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001dbb1` | `5f` | `POP EDI` |
| `1001dbb2` | `5e` | `POP ESI` |
| `1001dbb3` | `5b` | `POP EBX` |
| `1001dbb4` | `5d` | `POP EBP` |
| `1001dbb5` | `c3` | `RET` |
