# 1001c3a3 `___addlocaleref`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c3a3 |
| `name` | ___addlocaleref |
| `namespace` | Global |
| `signature` | undefined ___addlocaleref(void) |
| `size_bytes` | 143 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___addlocaleref |

## Decompiled C

```c

/* Library Function - Single Match
    ___addlocaleref
   
   Library: Visual Studio 2008 Release */

void ___addlocaleref(LONG *param_1)

{
  LONG *pLVar1;
  LONG *pLVar2;
  
  pLVar1 = param_1;
  InterlockedIncrement(param_1);
  if ((LONG *)param_1[0x2c] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2c]);
  }
  if ((LONG *)param_1[0x2e] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2e]);
  }
  if ((LONG *)param_1[0x2d] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x2d]);
  }
  if ((LONG *)param_1[0x30] != (LONG *)0x0) {
    InterlockedIncrement((LONG *)param_1[0x30]);
  }
  pLVar2 = param_1 + 0x14;
  param_1 = (LONG *)0x6;
  do {
    if (((undefined *)pLVar2[-2] != &DAT_10038148) && ((LONG *)*pLVar2 != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)*pLVar2);
    }
    if ((pLVar2[-1] != 0) && ((LONG *)pLVar2[1] != (LONG *)0x0)) {
      InterlockedIncrement((LONG *)pLVar2[1]);
    }
    pLVar2 = pLVar2 + 4;
    param_1 = (LONG *)((int)param_1 + -1);
  } while (param_1 != (LONG *)0x0);
  InterlockedIncrement((LONG *)(pLVar1[0x35] + 0xb4));
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c3b5` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c3c2` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c3cf` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c3dc` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c3e9` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c405` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c415` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |
| `1001c42b` | `EXTERNAL:0000004c` | `COMPUTED_CALL` | KERNEL32.DLL::InterlockedIncrement | `` |

## Callers

| From | Function |
| --- | --- |
| `1001732d` | __initptd |
| `1001c4dd` | __updatetlocinfoEx_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c3aa` | `1002e0e8` | `READ` | PTR_InterlockedIncrement_1002e0e8 |
| `1001c3f5` | `10038148` | `DATA` | DAT_10038148 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c3a3` | `8b ff` | `MOV EDI,EDI` |
| `1001c3a5` | `55` | `PUSH EBP` |
| `1001c3a6` | `8b ec` | `MOV EBP,ESP` |
| `1001c3a8` | `53` | `PUSH EBX` |
| `1001c3a9` | `56` | `PUSH ESI` |
| `1001c3aa` | `8b 35 e8 e0 02 10` | `MOV ESI,dword ptr [0x1002e0e8]` |
| `1001c3b0` | `57` | `PUSH EDI` |
| `1001c3b1` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1001c3b4` | `57` | `PUSH EDI` |
| `1001c3b5` | `ff d6` | `CALL ESI` |
| `1001c3b7` | `8b 87 b0 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb0]` |
| `1001c3bd` | `85 c0` | `TEST EAX,EAX` |
| `1001c3bf` | `74 03` | `JZ 0x1001c3c4` |
| `1001c3c1` | `50` | `PUSH EAX` |
| `1001c3c2` | `ff d6` | `CALL ESI` |
| `1001c3c4` | `8b 87 b8 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb8]` |
| `1001c3ca` | `85 c0` | `TEST EAX,EAX` |
| `1001c3cc` | `74 03` | `JZ 0x1001c3d1` |
| `1001c3ce` | `50` | `PUSH EAX` |
| `1001c3cf` | `ff d6` | `CALL ESI` |
| `1001c3d1` | `8b 87 b4 00 00 00` | `MOV EAX,dword ptr [EDI + 0xb4]` |
| `1001c3d7` | `85 c0` | `TEST EAX,EAX` |
| `1001c3d9` | `74 03` | `JZ 0x1001c3de` |
| `1001c3db` | `50` | `PUSH EAX` |
| `1001c3dc` | `ff d6` | `CALL ESI` |
| `1001c3de` | `8b 87 c0 00 00 00` | `MOV EAX,dword ptr [EDI + 0xc0]` |
| `1001c3e4` | `85 c0` | `TEST EAX,EAX` |
| `1001c3e6` | `74 03` | `JZ 0x1001c3eb` |
| `1001c3e8` | `50` | `PUSH EAX` |
| `1001c3e9` | `ff d6` | `CALL ESI` |
| `1001c3eb` | `8d 5f 50` | `LEA EBX,[EDI + 0x50]` |
| `1001c3ee` | `c7 45 08 06 00 00 00` | `MOV dword ptr [EBP + 0x8],0x6` |
| `1001c3f5` | `81 7b f8 48 81 03 10` | `CMP dword ptr [EBX + -0x8],0x10038148` |
| `1001c3fc` | `74 09` | `JZ 0x1001c407` |
| `1001c3fe` | `8b 03` | `MOV EAX,dword ptr [EBX]` |
| `1001c400` | `85 c0` | `TEST EAX,EAX` |
| `1001c402` | `74 03` | `JZ 0x1001c407` |
| `1001c404` | `50` | `PUSH EAX` |
| `1001c405` | `ff d6` | `CALL ESI` |
| `1001c407` | `83 7b fc 00` | `CMP dword ptr [EBX + -0x4],0x0` |
| `1001c40b` | `74 0a` | `JZ 0x1001c417` |
| `1001c40d` | `8b 43 04` | `MOV EAX,dword ptr [EBX + 0x4]` |
| `1001c410` | `85 c0` | `TEST EAX,EAX` |
| `1001c412` | `74 03` | `JZ 0x1001c417` |
| `1001c414` | `50` | `PUSH EAX` |
| `1001c415` | `ff d6` | `CALL ESI` |
| `1001c417` | `83 c3 10` | `ADD EBX,0x10` |
| `1001c41a` | `ff 4d 08` | `DEC dword ptr [EBP + 0x8]` |
| `1001c41d` | `75 d6` | `JNZ 0x1001c3f5` |
| `1001c41f` | `8b 87 d4 00 00 00` | `MOV EAX,dword ptr [EDI + 0xd4]` |
| `1001c425` | `05 b4 00 00 00` | `ADD EAX,0xb4` |
| `1001c42a` | `50` | `PUSH EAX` |
| `1001c42b` | `ff d6` | `CALL ESI` |
| `1001c42d` | `5f` | `POP EDI` |
| `1001c42e` | `5e` | `POP ESI` |
| `1001c42f` | `5b` | `POP EBX` |
| `1001c430` | `5d` | `POP EBP` |
| `1001c431` | `c3` | `RET` |
