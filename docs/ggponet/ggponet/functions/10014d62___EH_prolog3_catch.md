# 10014d62 `__EH_prolog3_catch`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10014d62 |
| `name` | __EH_prolog3_catch |
| `namespace` | Global |
| `signature` | undefined __EH_prolog3_catch(void) |
| `size_bytes` | 54 |
| `stack_frame_size` | 16 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __EH_prolog3_catch |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* WARNING: Unable to track spacebase fully for stack */
/* Library Function - Single Match
    __EH_prolog3_catch
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2010, Visual Studio 2012 */

void __EH_prolog3_catch(int param_1)

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
| `1001af3c` | FUN_1001af35 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10014d63` | `ffdff000` | `READ` | ExceptionList |
| `10014d79` | `10037490` | `READ` | DAT_10037490 |
| `10014d91` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10014d62` | `50` | `PUSH EAX` |
| `10014d63` | `64 ff 35 00 00 00 00` | `PUSH dword ptr FS:[0x0]` |
| `10014d6a` | `8d 44 24 0c` | `LEA EAX,[ESP + 0xc]` |
| `10014d6e` | `2b 64 24 0c` | `SUB ESP,dword ptr [ESP + 0xc]` |
| `10014d72` | `53` | `PUSH EBX` |
| `10014d73` | `56` | `PUSH ESI` |
| `10014d74` | `57` | `PUSH EDI` |
| `10014d75` | `89 28` | `MOV dword ptr [EAX],EBP` |
| `10014d77` | `8b e8` | `MOV EBP,EAX` |
| `10014d79` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10014d7e` | `33 c5` | `XOR EAX,EBP` |
| `10014d80` | `50` | `PUSH EAX` |
| `10014d81` | `89 65 f0` | `MOV dword ptr [EBP + -0x10],ESP` |
| `10014d84` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10014d87` | `c7 45 fc ff ff ff ff` | `MOV dword ptr [EBP + -0x4],0xffffffff` |
| `10014d8e` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10014d91` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10014d97` | `c3` | `RET` |
