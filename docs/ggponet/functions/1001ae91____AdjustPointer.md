# 1001ae91 `___AdjustPointer`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ae91 |
| `name` | ___AdjustPointer |
| `namespace` | Global |
| `signature` | undefined ___AdjustPointer(void) |
| `size_bytes` | 41 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___AdjustPointer |

## Decompiled C

```c

/* Library Function - Single Match
    ___AdjustPointer
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int ___AdjustPointer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2 + param_1;
  if (-1 < param_2[1]) {
    iVar1 = iVar1 + *(int *)(*(int *)(param_2[1] + param_1) + param_2[2]) + param_2[1];
  }
  return iVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001b2e6` | ___BuildCatchObject |
| `1001b300` | ___BuildCatchObject |
| `1001b1a0` | ___BuildCatchObjectHelper |
| `1001b22d` | ___BuildCatchObjectHelper |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ae91` | `8b ff` | `MOV EDI,EDI` |
| `1001ae93` | `55` | `PUSH EBP` |
| `1001ae94` | `8b ec` | `MOV EBP,ESP` |
| `1001ae96` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1001ae99` | `8b 01` | `MOV EAX,dword ptr [ECX]` |
| `1001ae9b` | `56` | `PUSH ESI` |
| `1001ae9c` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001ae9f` | `03 c6` | `ADD EAX,ESI` |
| `1001aea1` | `83 79 04 00` | `CMP dword ptr [ECX + 0x4],0x0` |
| `1001aea5` | `7c 10` | `JL 0x1001aeb7` |
| `1001aea7` | `8b 51 04` | `MOV EDX,dword ptr [ECX + 0x4]` |
| `1001aeaa` | `8b 49 08` | `MOV ECX,dword ptr [ECX + 0x8]` |
| `1001aead` | `8b 34 32` | `MOV ESI,dword ptr [EDX + ESI*0x1]` |
| `1001aeb0` | `8b 0c 0e` | `MOV ECX,dword ptr [ESI + ECX*0x1]` |
| `1001aeb3` | `03 ca` | `ADD ECX,EDX` |
| `1001aeb5` | `03 c1` | `ADD EAX,ECX` |
| `1001aeb7` | `5e` | `POP ESI` |
| `1001aeb8` | `5d` | `POP EBP` |
| `1001aeb9` | `c3` | `RET` |
