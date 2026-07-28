# 10014c56 `__IsExceptionObjectToBeDestroyed`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014c56 |
| `name` | __IsExceptionObjectToBeDestroyed |
| `namespace` | Global |
| `signature` | undefined __IsExceptionObjectToBeDestroyed(void) |
| `size_bytes` | 39 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __IsExceptionObjectToBeDestroyed |

## Decompiled C

```c

/* Library Function - Single Match
    __IsExceptionObjectToBeDestroyed
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 __IsExceptionObjectToBeDestroyed(int param_1)

{
  _ptiddata p_Var1;
  int *piVar2;
  
  p_Var1 = __getptd();
  piVar2 = p_Var1->_pFrameInfoChain;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 1;
    }
    if (*piVar2 == param_1) break;
    piVar2 = (int *)piVar2[1];
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014c5b` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |

## Callers

| From | Function |
| --- | --- |
| `1001b104` | FUN_1001b0a4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014c56` | `8b ff` | `MOV EDI,EDI` |
| `10014c58` | `55` | `PUSH EBP` |
| `10014c59` | `8b ec` | `MOV EBP,ESP` |
| `10014c5b` | `e8 76 27 00 00` | `CALL 0x100173d6` |
| `10014c60` | `8b 80 98 00 00 00` | `MOV EAX,dword ptr [EAX + 0x98]` |
| `10014c66` | `eb 0a` | `JMP 0x10014c72` |
| `10014c68` | `8b 08` | `MOV ECX,dword ptr [EAX]` |
| `10014c6a` | `3b 4d 08` | `CMP ECX,dword ptr [EBP + 0x8]` |
| `10014c6d` | `74 0a` | `JZ 0x10014c79` |
| `10014c6f` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `10014c72` | `85 c0` | `TEST EAX,EAX` |
| `10014c74` | `75 f2` | `JNZ 0x10014c68` |
| `10014c76` | `40` | `INC EAX` |
| `10014c77` | `5d` | `POP EBP` |
| `10014c78` | `c3` | `RET` |
| `10014c79` | `33 c0` | `XOR EAX,EAX` |
| `10014c7b` | `5d` | `POP EBP` |
| `10014c7c` | `c3` | `RET` |
