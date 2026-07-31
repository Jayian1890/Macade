# 1001ae3c `___DestructExceptionObject`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ae3c |
| `name` | ___DestructExceptionObject |
| `namespace` | Global |
| `signature` | undefined ___DestructExceptionObject(void) |
| `size_bytes` | 67 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___DestructExceptionObject |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___DestructExceptionObject
   
   Library: Visual Studio 2008 Release */

void ___DestructExceptionObject(int *param_1)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (*param_1 == -0x1f928c9d)) && (param_1[7] != 0)) &&
     (iVar1 = *(int *)(param_1[7] + 4), iVar1 != 0)) {
    FID_conflict__CallMemberFunction1(param_1[6],iVar1);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ae43` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001ae6d` | `1001497b` | `UNCONDITIONAL_CALL` | FID_conflict:_CallMemberFunction1 | `1001497b` |
| `1001ae79` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001b5d3` | FindHandler |
| `1001b6fd` | FindHandler |
| `1001b112` | FUN_1001b0a4 |
| `10016e6a` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001ae3e` | `10034098` | `DATA` | DAT_10034098 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ae3c` | `6a 08` | `PUSH 0x8` |
| `1001ae3e` | `68 98 40 03 10` | `PUSH 0x10034098` |
| `1001ae43` | `e8 b4 be ff ff` | `CALL 0x10016cfc` |
| `1001ae48` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001ae4b` | `85 c9` | `TEST ECX,ECX` |
| `1001ae4d` | `74 2a` | `JZ 0x1001ae79` |
| `1001ae4f` | `81 39 63 73 6d e0` | `CMP dword ptr [ECX],0xe06d7363` |
| `1001ae55` | `75 22` | `JNZ 0x1001ae79` |
| `1001ae57` | `8b 41 1c` | `MOV EAX,dword ptr [ECX + 0x1c]` |
| `1001ae5a` | `85 c0` | `TEST EAX,EAX` |
| `1001ae5c` | `74 1b` | `JZ 0x1001ae79` |
| `1001ae5e` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001ae61` | `85 c0` | `TEST EAX,EAX` |
| `1001ae63` | `74 14` | `JZ 0x1001ae79` |
| `1001ae65` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `1001ae69` | `50` | `PUSH EAX` |
| `1001ae6a` | `ff 71 18` | `PUSH dword ptr [ECX + 0x18]` |
| `1001ae6d` | `e8 09 9b ff ff` | `CALL 0x1001497b` |
| `1001ae72` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001ae79` | `e8 c3 be ff ff` | `CALL 0x10016d41` |
| `1001ae7e` | `c3` | `RET` |
