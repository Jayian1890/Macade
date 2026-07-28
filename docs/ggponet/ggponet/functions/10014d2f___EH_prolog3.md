# 10014d2f `__EH_prolog3`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014d2f |
| `name` | __EH_prolog3 |
| `namespace` | Global |
| `signature` | undefined __EH_prolog3(void) |
| `size_bytes` | 51 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __EH_prolog3 |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __EH_prolog3
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_prolog3(int param_1)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 unaff_retaddr;
  uint auStack_1c [5];
  undefined1 local_8 [8];
  
  param_1 = -param_1;
  *(undefined4 *)((int)auStack_1c + param_1 + 0x10) = unaff_EBX;
  *(undefined4 *)((int)auStack_1c + param_1 + 0xc) = unaff_ESI;
  *(undefined4 *)((int)auStack_1c + param_1 + 8) = unaff_EDI;
  *(uint *)((int)auStack_1c + param_1 + 4) = DAT_10037490 ^ (uint)&stack0x00000004;
  *(undefined4 *)((int)auStack_1c + param_1) = unaff_retaddr;
  ExceptionList = local_8;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10010c57` | FUN_10010c50 |
| `10010c8f` | FUN_10010c88 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014d30` | `ffdff000` | `READ` | ExceptionList |
| `10014d46` | `10037490` | `READ` | DAT_10037490 |
| `10014d5b` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014d2f` | `50` | `PUSH EAX` |
| `10014d30` | `64 ff 35 00 00 00 00` | `PUSH dword ptr FS:[0x0]` |
| `10014d37` | `8d 44 24 0c` | `LEA EAX,[ESP + 0xc]` |
| `10014d3b` | `2b 64 24 0c` | `SUB ESP,dword ptr [ESP + 0xc]` |
| `10014d3f` | `53` | `PUSH EBX` |
| `10014d40` | `56` | `PUSH ESI` |
| `10014d41` | `57` | `PUSH EDI` |
| `10014d42` | `89 28` | `MOV dword ptr [EAX],EBP` |
| `10014d44` | `8b e8` | `MOV EBP,EAX` |
| `10014d46` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10014d4b` | `33 c5` | `XOR EAX,EBP` |
| `10014d4d` | `50` | `PUSH EAX` |
| `10014d4e` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10014d51` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `10014d58` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10014d5b` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014d61` | `c3` | `RET` |
