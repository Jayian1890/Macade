# 100194f9 `_inconsistency`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100194f9 |
| `name` | _inconsistency |
| `namespace` | Global |
| `signature` | void __cdecl _inconsistency(void) |
| `size_bytes` | 49 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_inconsistency@@YAXXZ, _inconsistency |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    void __cdecl _inconsistency(void)
   
   Library: Visual Studio 2008 Release */

void __cdecl _inconsistency(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)__decode_pointer(DAT_10039254);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)();
  }
  terminate();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019500` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001950b` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `1001952b` | `100194ad` | `UNCONDITIONAL_CALL` | terminate | `100194ad` |

## Callers

| From | Function |
| --- | --- |
| `1001ad5c` | ___FrameUnwindToState |
| `1001adc8` | ___FrameUnwindToState |
| `1001b4c1` | FindHandler |
| `1001b544` | FindHandler |
| `1001b56e` | FindHandler |
| `1001b7ca` | FindHandler |
| `10014c18` | _GetRangeOfTrysToCheck |
| `10014bd3` | _GetRangeOfTrysToCheck |
| `1001aec6` | IsInExceptionSpec |
| `1001af4f` | FUN_1001af35 |
| `1001b274` | ___BuildCatchObjectHelper |
| `1001b407` | FindHandlerForForeignException |
| `10014cc2` | __FindAndUnlinkFrame |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100194fb` | `10033fb0` | `DATA` | DAT_10033fb0 |
| `10019505` | `10039254` | `READ` | DAT_10039254 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100194f9` | `6a 08` | `PUSH 0x8` |
| `100194fb` | `68 b0 3f 03 10` | `PUSH 0x10033fb0` |
| `10019500` | `e8 f7 d7 ff ff` | `CALL 0x10016cfc` |
| `10019505` | `ff 35 54 92 03 10` | `PUSH dword ptr [0x10039254]` |
| `1001950b` | `e8 7a dc ff ff` | `CALL 0x1001718a` |
| `10019510` | `59` | `POP ECX` |
| `10019511` | `85 c0` | `TEST EAX,EAX` |
| `10019513` | `74 16` | `JZ 0x1001952b` |
| `10019515` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10019519` | `ff d0` | `CALL EAX` |
| `1001951b` | `eb 07` | `JMP 0x10019524` |
| `10019524` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001952b` | `e8 7d ff ff ff` | `CALL 0x100194ad` |
| `10019530` | `cc` | `INT3` |
