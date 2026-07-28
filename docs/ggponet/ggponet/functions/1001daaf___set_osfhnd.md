# 1001daaf `__set_osfhnd`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001daaf |
| `name` | __set_osfhnd |
| `namespace` | Global |
| `signature` | int __cdecl __set_osfhnd(int param_1, intptr_t param_2) |
| `size_bytes` | 129 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __set_osfhnd |

## Decompiled C

```c

/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2008 Release */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  int *piVar1;
  ulong *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((-1 < param_1) && ((uint)param_1 < DAT_13439530)) {
    iVar3 = (param_1 & 0x1fU) * 0x40;
    if (*(int *)(iVar3 + (&DAT_13439540)[param_1 >> 5]) == -1) {
      if (DAT_10038a80 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_1001db0c;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)param_2);
      }
LAB_1001db0c:
      *(intptr_t *)(iVar3 + (&DAT_13439540)[param_1 >> 5]) = param_2;
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
| `1001db06` | `EXTERNAL:0000002d` | `COMPUTED_CALL` | KERNEL32.DLL::SetStdHandle | `` |
| `1001db16` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001db21` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |

## Callers

| From | Function |
| --- | --- |
| `1001d0b3` | __tsopen_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001dabd` | `13439530` | `READ` | DAT_13439530 |
| `1001dacf` | `13439540` | `DATA` | DAT_13439540 |
| `1001dad6` | `13439540` | `DATA` | DAT_13439540 |
| `1001dae1` | `10038a80` | `READ` | DAT_10038a80 |
| `1001db06` | `1002e06c` | `READ` | PTR_SetStdHandle_1002e06c |
| `1001db0c` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001daaf` | `8b ff` | `MOV EDI,EDI` |
| `1001dab1` | `55` | `PUSH EBP` |
| `1001dab2` | `8b ec` | `MOV EBP,ESP` |
| `1001dab4` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001dab7` | `56` | `PUSH ESI` |
| `1001dab8` | `57` | `PUSH EDI` |
| `1001dab9` | `85 c0` | `TEST EAX,EAX` |
| `1001dabb` | `7c 59` | `JL 0x1001db16` |
| `1001dabd` | `3b 05 30 95 43 13` | `CMP EAX,dword ptr [0x13439530]` |
| `1001dac3` | `73 51` | `JNC 0x1001db16` |
| `1001dac5` | `8b c8` | `MOV ECX,EAX` |
| `1001dac7` | `c1 f9 05` | `SAR ECX,0x5` |
| `1001daca` | `8b f0` | `MOV ESI,EAX` |
| `1001dacc` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001dacf` | `8d 3c 8d 40 95 43 13` | `LEA EDI,[ECX*0x4 + 0x13439540]` |
| `1001dad6` | `8b 0f` | `MOV ECX,dword ptr [EDI]` |
| `1001dad8` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001dadb` | `83 3c 0e ff` | `CMP dword ptr [ESI + ECX*0x1],-0x1` |
| `1001dadf` | `75 35` | `JNZ 0x1001db16` |
| `1001dae1` | `83 3d 80 8a 03 10 01` | `CMP dword ptr [0x10038a80],0x1` |
| `1001dae8` | `53` | `PUSH EBX` |
| `1001dae9` | `8b 5d 0c` | `MOV EBX,dword ptr [EBP + 0xc]` |
| `1001daec` | `75 1e` | `JNZ 0x1001db0c` |
| `1001daee` | `83 e8 00` | `SUB EAX,0x0` |
| `1001daf1` | `74 10` | `JZ 0x1001db03` |
| `1001daf3` | `48` | `DEC EAX` |
| `1001daf4` | `74 08` | `JZ 0x1001dafe` |
| `1001daf6` | `48` | `DEC EAX` |
| `1001daf7` | `75 13` | `JNZ 0x1001db0c` |
| `1001daf9` | `53` | `PUSH EBX` |
| `1001dafa` | `6a f4` | `PUSH -0xc` |
| `1001dafc` | `eb 08` | `JMP 0x1001db06` |
| `1001dafe` | `53` | `PUSH EBX` |
| `1001daff` | `6a f5` | `PUSH -0xb` |
| `1001db01` | `eb 03` | `JMP 0x1001db06` |
| `1001db03` | `53` | `PUSH EBX` |
| `1001db04` | `6a f6` | `PUSH -0xa` |
| `1001db06` | `ff 15 6c e0 02 10` | `CALL dword ptr [0x1002e06c]` |
| `1001db0c` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001db0e` | `89 1c 06` | `MOV dword ptr [ESI + EAX*0x1],EBX` |
| `1001db11` | `33 c0` | `XOR EAX,EAX` |
| `1001db13` | `5b` | `POP EBX` |
| `1001db14` | `eb 16` | `JMP 0x1001db2c` |
| `1001db16` | `e8 ee 75 ff ff` | `CALL 0x10015109` |
| `1001db1b` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001db21` | `e8 f6 75 ff ff` | `CALL 0x1001511c` |
| `1001db26` | `83 20 00` | `AND dword ptr [EAX],0x0` |
| `1001db29` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001db2c` | `5f` | `POP EDI` |
| `1001db2d` | `5e` | `POP ESI` |
| `1001db2e` | `5d` | `POP EBP` |
| `1001db2f` | `c3` | `RET` |
