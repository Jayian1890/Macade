# 1001c432 `___removelocaleref`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c432 |
| `name` | ___removelocaleref |
| `namespace` | Global |
| `signature` | undefined ___removelocaleref(void) |
| `size_bytes` | 153 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___removelocaleref |

## Decompiled C

```c

/* Library Function - Single Match
    ___removelocaleref
   
   Library: Visual Studio 2008 Release */

LONG * ___removelocaleref(LONG *param_1)

{
  LONG *pLVar1;
  LONG *pLVar2;
  
  pLVar1 = param_1;
  if (param_1 != (LONG *)0x0) {
    InterlockedDecrement(param_1);
    if ((LONG *)param_1[0x2c] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2c]);
    }
    if ((LONG *)param_1[0x2e] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2e]);
    }
    if ((LONG *)param_1[0x2d] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x2d]);
    }
    if ((LONG *)param_1[0x30] != (LONG *)0x0) {
      InterlockedDecrement((LONG *)param_1[0x30]);
    }
    pLVar2 = param_1 + 0x14;
    param_1 = (LONG *)0x6;
    do {
      if (((undefined *)pLVar2[-2] != &DAT_10038148) && ((LONG *)*pLVar2 != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)*pLVar2);
      }
      if ((pLVar2[-1] != 0) && ((LONG *)pLVar2[1] != (LONG *)0x0)) {
        InterlockedDecrement((LONG *)pLVar2[1]);
      }
      pLVar2 = pLVar2 + 4;
      param_1 = (LONG *)((int)param_1 + -1);
    } while (param_1 != (LONG *)0x0);
    InterlockedDecrement((LONG *)(pLVar1[0x35] + 0xb4));
  }
  return pLVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c44c` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c459` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c466` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c473` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c480` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c49c` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c4ac` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |
| `1001c4c2` | `EXTERNAL:0000004e` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedDecrement | `` |

## Callers

| From | Function |
| --- | --- |
| `1001c4e8` | __updatetlocinfoEx_nolock |
| `100174ca` | __freefls@4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c445` | `1002e0f0` | `READ` | PTR_InterlockedDecrement_1002e0f0 |
| `1001c48c` | `10038148` | `DATA` | DAT_10038148 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c432` | `8b ff` | `MOV EDI,EDI` |
| `1001c434` | `55` | `PUSH EBP` |
| `1001c435` | `8b ec` | `MOV EBP,ESP` |
| `1001c437` | `57` | `PUSH EDI` |
| `1001c438` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001c43b` | `85 ff` | `TEST EDI,EDI` |
| `1001c43d` | `0f 84 83 00 00 00` | `JZ 0x1001c4c6` |
| `1001c443` | `53` | `PUSH EBX` |
| `1001c444` | `56` | `PUSH ESI` |
| `1001c445` | `8b 35 f0 e0 02 10` | `MOV ESI,dword ptr [0x1002e0f0]` |
| `1001c44b` | `57` | `PUSH EDI` |
| `1001c44c` | `ff d6` | `CALL ESI` |
| `1001c44e` | `8b 87 b0 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb0]` |
| `1001c454` | `85 c0` | `TEST EAX,EAX` |
| `1001c456` | `74 03` | `JZ 0x1001c45b` |
| `1001c458` | `50` | `PUSH EAX` |
| `1001c459` | `ff d6` | `CALL ESI` |
| `1001c45b` | `8b 87 b8 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb8]` |
| `1001c461` | `85 c0` | `TEST EAX,EAX` |
| `1001c463` | `74 03` | `JZ 0x1001c468` |
| `1001c465` | `50` | `PUSH EAX` |
| `1001c466` | `ff d6` | `CALL ESI` |
| `1001c468` | `8b 87 b4 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb4]` |
| `1001c46e` | `85 c0` | `TEST EAX,EAX` |
| `1001c470` | `74 03` | `JZ 0x1001c475` |
| `1001c472` | `50` | `PUSH EAX` |
| `1001c473` | `ff d6` | `CALL ESI` |
| `1001c475` | `8b 87 c0 00 00 00` | `MOV EAX,dword ptr [EDI + 0xc0]` |
| `1001c47b` | `85 c0` | `TEST EAX,EAX` |
| `1001c47d` | `74 03` | `JZ 0x1001c482` |
| `1001c47f` | `50` | `PUSH EAX` |
| `1001c480` | `ff d6` | `CALL ESI` |
| `1001c482` | `8d 5f 50` | `LEA EBX,[EDI + 0x50]` |
| `1001c485` | `c7 45 08 06 00 00 00` | `MOV dword ptr [EBP + 0x8],0x6` |
| `1001c48c` | `81 7b f8 48 81 03 10` | `CMP dword ptr [EBX + -0x8],0x10038148` |
| `1001c493` | `74 09` | `JZ 0x1001c49e` |
| `1001c495` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `1001c497` | `85 c0` | `TEST EAX,EAX` |
| `1001c499` | `74 03` | `JZ 0x1001c49e` |
| `1001c49b` | `50` | `PUSH EAX` |
| `1001c49c` | `ff d6` | `CALL ESI` |
| `1001c49e` | `83 7b fc 00` | `CMP dword ptr [EBX + -0x4],0x0` |
| `1001c4a2` | `74 0a` | `JZ 0x1001c4ae` |
| `1001c4a4` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1001c4a7` | `85 c0` | `TEST EAX,EAX` |
| `1001c4a9` | `74 03` | `JZ 0x1001c4ae` |
| `1001c4ab` | `50` | `PUSH EAX` |
| `1001c4ac` | `ff d6` | `CALL ESI` |
| `1001c4ae` | `83 c3 10` | `ADD EBX,0x10` |
| `1001c4b1` | `ff 4d 08` | `DEC dword ptr [EBP + 0x8]` |
| `1001c4b4` | `75 d6` | `JNZ 0x1001c48c` |
| `1001c4b6` | `8b 87 d4 00 00 00` | `MOV EAX,dword ptr [EDI + 0xd4]` |
| `1001c4bc` | `05 b4 00 00 00` | `ADD EAX,0xb4` |
| `1001c4c1` | `50` | `PUSH EAX` |
| `1001c4c2` | `ff d6` | `CALL ESI` |
| `1001c4c4` | `5e` | `POP ESI` |
| `1001c4c5` | `5b` | `POP EBX` |
| `1001c4c6` | `8b c7` | `MOV EAX,EDI` |
| `1001c4c8` | `5f` | `POP EDI` |
| `1001c4c9` | `5d` | `POP EBP` |
| `1001c4ca` | `c3` | `RET` |
