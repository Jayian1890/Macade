# 100149d6 `FID_conflict:___CxxFrameHandler3`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100149d6 |
| `name` | FID_conflict:___CxxFrameHandler3 |
| `namespace` | Global |
| `signature` | undefined FID_conflict:___CxxFrameHandler3(void) |
| `size_bytes` | 54 |
| `stack_frame_size` | 16 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | FID_conflict:___CxxFrameHandler3, ___CxxFrameHandler, ___CxxFrameHandler2, ___CxxFrameHandler3 |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    ___CxxFrameHandler
    ___CxxFrameHandler2
    ___CxxFrameHandler3
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

undefined4
FID_conflict____CxxFrameHandler3
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = ___InternalCxxFrameHandler(param_1,param_2,param_3,param_4);
  return uVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100149f7` | `1001b7f1` | `UNCONDITIONAL_CALL` | ___InternalCxxFrameHandler | `1001b7f1` |

## Callers

| From | Function |
| --- | --- |
| `1002d2de` |  |
| `1002d2f9` |  |
| `1002d316` |  |
| `1002d336` |  |
| `1002d356` |  |
| `1002d376` |  |
| `1002d396` |  |
| `1002d3b6` |  |
| `1002d3de` |  |
| `1002d406` |  |
| `1002d426` |  |
| `1002d446` |  |
| `1002d466` |  |
| `1002d48e` |  |
| `1002d4c4` |  |
| `1002d4ea` |  |
| `1002d51e` |  |
| `1002d573` |  |
| `1002d5aa` |  |
| `1002d5de` |  |
| `1002d604` |  |
| `1002d637` |  |
| `1002d66b` |  |
| `1002d69f` |  |
| `1002d6e1` |  |
| `1002d731` |  |
| `1002d754` |  |
| `1002d7a1` |  |
| `1002d7ce` |  |
| `1002d7f6` |  |
| `1002d81e` |  |
| `1002d846` |  |
| `1002d866` |  |
| `1002d88e` |  |
| `1002d8be` |  |
| `1002d8ee` |  |
| `1002d91e` |  |
| `1002d94e` |  |
| `1002d97e` |  |
| `1002d9a6` |  |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100149d6` | `55` | `PUSH EBP` |
| `100149d7` | `8b ec` | `MOV EBP,ESP` |
| `100149d9` | `83 ec 08` | `SUB ESP,0x8` |
| `100149dc` | `53` | `PUSH EBX` |
| `100149dd` | `56` | `PUSH ESI` |
| `100149de` | `57` | `PUSH EDI` |
| `100149df` | `fc` | `CLD` |
| `100149e0` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `100149e3` | `33 c0` | `XOR EAX,EAX` |
| `100149e5` | `50` | `PUSH EAX` |
| `100149e6` | `50` | `PUSH EAX` |
| `100149e7` | `50` | `PUSH EAX` |
| `100149e8` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `100149eb` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `100149ee` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `100149f1` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `100149f4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100149f7` | `e8 f5 6d 00 00` | `CALL 0x1001b7f1` |
| `100149fc` | `83 c4 20` | `ADD ESP,0x20` |
| `100149ff` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10014a02` | `5f` | `POP EDI` |
| `10014a03` | `5e` | `POP ESI` |
| `10014a04` | `5b` | `POP EBX` |
| `10014a05` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `10014a08` | `8b e5` | `MOV ESP,EBP` |
| `10014a0a` | `5d` | `POP EBP` |
| `10014a0b` | `c3` | `RET` |
