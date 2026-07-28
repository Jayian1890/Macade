# 10014c2a `__CreateFrameInfo`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014c2a |
| `name` | __CreateFrameInfo |
| `namespace` | Global |
| `signature` | undefined __CreateFrameInfo(void) |
| `size_bytes` | 44 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __CreateFrameInfo |

## Decompiled C

```c

/* Library Function - Single Match
    __CreateFrameInfo
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4 * __CreateFrameInfo(undefined4 *param_1,undefined4 param_2)

{
  _ptiddata p_Var1;
  
  *param_1 = param_2;
  p_Var1 = __getptd();
  param_1[1] = p_Var1->_pFrameInfoChain;
  p_Var1 = __getptd();
  p_Var1->_pFrameInfoChain = param_1;
  return param_1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10014c38` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `10014c46` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |

## Callers

| From | Function |
| --- | --- |
| `1001afa6` | CallCatchBlock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014c2a` | `8b ff` | `MOV EDI,EDI` |
| `10014c2c` | `55` | `PUSH EBP` |
| `10014c2d` | `8b ec` | `MOV EBP,ESP` |
| `10014c2f` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10014c32` | `56` | `PUSH ESI` |
| `10014c33` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10014c36` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10014c38` | `e8 99 27 00 00` | `CALL 0x100173d6` |
| `10014c3d` | `8b 80 98 00 00 00` | `MOV EAX,dword ptr [EAX + 0x98]` |
| `10014c43` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `10014c46` | `e8 8b 27 00 00` | `CALL 0x100173d6` |
| `10014c4b` | `89 b0 98 00 00 00` | `MOV dword ptr [EAX + 0x98],ESI` |
| `10014c51` | `8b c6` | `MOV EAX,ESI` |
| `10014c53` | `5e` | `POP ESI` |
| `10014c54` | `5d` | `POP EBP` |
| `10014c55` | `c3` | `RET` |
