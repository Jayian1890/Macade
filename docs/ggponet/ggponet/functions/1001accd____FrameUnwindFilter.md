# 1001accd `___FrameUnwindFilter`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001accd |
| `name` | ___FrameUnwindFilter |
| `namespace` | Global |
| `signature` | undefined ___FrameUnwindFilter(void) |
| `size_bytes` | 73 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___FrameUnwindFilter |

## Decompiled C

```c

/* Library Function - Single Match
    ___FrameUnwindFilter
   
   Library: Visual Studio 2008 Release */

undefined4 ___FrameUnwindFilter(undefined4 *param_1)

{
  _ptiddata p_Var1;
  undefined4 extraout_EAX;
  
  if (*(int *)*param_1 == -0x1fbcb0b3) {
    p_Var1 = __getptd();
    if (0 < p_Var1->_ProcessingThrow) {
      p_Var1 = __getptd();
      p_Var1->_ProcessingThrow = p_Var1->_ProcessingThrow + -1;
    }
  }
  else if (*(int *)*param_1 == -0x1f928c9d) {
    p_Var1 = __getptd();
    p_Var1->_ProcessingThrow = 0;
    terminate();
    return extraout_EAX;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ace7` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001acf3` | `100194ad` | `UNCONDITIONAL_CALL` | terminate | `100194ad` |
| `1001acf8` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001ad06` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001accd` | `8b ff` | `MOV EDI,EDI` |
| `1001accf` | `55` | `PUSH EBP` |
| `1001acd0` | `8b ec` | `MOV EBP,ESP` |
| `1001acd2` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001acd5` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001acd7` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001acd9` | `3d 4d 4f 43 e0` | `CMP EAX,0xe0434f4d` |
| `1001acde` | `74 18` | `JZ 0x1001acf8` |
| `1001ace0` | `3d 63 73 6d e0` | `CMP EAX,0xe06d7363` |
| `1001ace5` | `75 2b` | `JNZ 0x1001ad12` |
| `1001ace7` | `e8 ea c6 ff ff` | `CALL 0x100173d6` |
| `1001acec` | `83 a0 90 00 00 00 00` | `AND dword ptr [EAX + 0x90],0x0` |
| `1001acf3` | `e9 b5 e7 ff ff` | `JMP 0x100194ad` |
| `1001acf8` | `e8 d9 c6 ff ff` | `CALL 0x100173d6` |
| `1001acfd` | `83 b8 90 00 00 00 00` | `CMP dword ptr [EAX + 0x90],0x0` |
| `1001ad04` | `7e 0c` | `JLE 0x1001ad12` |
| `1001ad06` | `e8 cb c6 ff ff` | `CALL 0x100173d6` |
| `1001ad0b` | `05 90 00 00 00` | `ADD EAX,0x90` |
| `1001ad10` | `ff 08` | `DEC dword ptr [EAX]` |
| `1001ad12` | `33 c0` | `XOR EAX,EAX` |
| `1001ad14` | `5d` | `POP EBP` |
| `1001ad15` | `c3` | `RET` |
