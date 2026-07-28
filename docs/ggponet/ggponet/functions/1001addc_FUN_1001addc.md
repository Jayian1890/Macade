# 1001addc `FUN_1001addc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001addc |
| `name` | FUN_1001addc |
| `namespace` | Global |
| `signature` | undefined FUN_1001addc(void) |
| `size_bytes` | 27 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | DEFAULT |
| `export_names` |  |

## Decompiled C

```c

void FUN_1001addc(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (0 < p_Var1->_ProcessingThrow) {
    p_Var1 = __getptd();
    p_Var1->_ProcessingThrow = p_Var1->_ProcessingThrow + -1;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001addc` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `1001adea` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |

## Callers

| From | Function |
| --- | --- |
| `1001adbe` | ___FrameUnwindToState |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001addc` | `e8 f5 c5 ff ff` | `CALL 0x100173d6` |
| `1001ade1` | `83 b8 90 00 00 00 00` | `CMP dword ptr [EAX + 0x90],0x0` |
| `1001ade8` | `7e 0c` | `JLE 0x1001adf6` |
| `1001adea` | `e8 e7 c5 ff ff` | `CALL 0x100173d6` |
| `1001adef` | `05 90 00 00 00` | `ADD EAX,0x90` |
| `1001adf4` | `ff 08` | `DEC dword ptr [EAX]` |
| `1001adf6` | `c3` | `RET` |
