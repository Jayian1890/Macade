# 1001cad2 `__msize`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cad2 |
| `name` | __msize |
| `namespace` | Global |
| `signature` | size_t __cdecl __msize(void * _Memory) |
| `size_bytes` | 146 |
| `stack_frame_size` | 44 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __msize |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __msize
   
   Library: Visual Studio 2008 Release */

size_t __cdecl __msize(void *_Memory)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  size_t local_20;
  
  if (_Memory == (void *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    sVar2 = 0xffffffff;
  }
  else {
    if (DAT_1343a680 == 3) {
      __lock(4);
      iVar3 = ___sbh_find_block(_Memory);
      if (iVar3 != 0) {
        local_20 = *(int *)((int)_Memory + -4) - 9;
      }
      FUN_1001cb6c();
      if (iVar3 != 0) {
        return local_20;
      }
    }
    sVar2 = HeapSize(DAT_10038dac,0,_Memory);
  }
  return sVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cad9` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001caee` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001cafe` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001cb16` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001cb20` | `10016236` | `UNCONDITIONAL_CALL` | ___sbh_find_block | `10016236` |
| `1001cb42` | `1001cb6c` | `UNCONDITIONAL_CALL` | FUN_1001cb6c | `1001cb6c` |
| `1001cb54` | `EXTERNAL:00000064` | `COMPUTED_CALL` | KERNEL32.DLL::HeapSize | `` |
| `1001cb5e` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001e8c2` | __recalloc |
| `100178ad` | __onexit_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001cad4` | `10034230` | `DATA` | DAT_10034230 |
| `1001cb0b` | `1343a680` | `READ` | DAT_1343a680 |
| `1001cb4e` | `10038dac` | `READ` | DAT_10038dac |
| `1001cb54` | `1002e148` | `READ` | PTR_HeapSize_1002e148 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cad2` | `6a 10` | `PUSH 0x10` |
| `1001cad4` | `68 30 42 03 10` | `PUSH 0x10034230` |
| `1001cad9` | `e8 1e a2 ff ff` | `CALL 0x10016cfc` |
| `1001cade` | `33 c0` | `XOR EAX,EAX` |
| `1001cae0` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `1001cae3` | `33 ff` | `XOR EDI,EDI` |
| `1001cae5` | `3b df` | `CMP EBX,EDI` |
| `1001cae7` | `0f 95 c0` | `SETNZ AL` |
| `1001caea` | `3b c7` | `CMP EAX,EDI` |
| `1001caec` | `75 1d` | `JNZ 0x1001cb0b` |
| `1001caee` | `e8 16 86 ff ff` | `CALL 0x10015109` |
| `1001caf3` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001caf9` | `57` | `PUSH EDI` |
| `1001cafa` | `57` | `PUSH EDI` |
| `1001cafb` | `57` | `PUSH EDI` |
| `1001cafc` | `57` | `PUSH EDI` |
| `1001cafd` | `57` | `PUSH EDI` |
| `1001cafe` | `e8 ac 4b ff ff` | `CALL 0x100116af` |
| `1001cb03` | `83 c4 14` | `ADD ESP,0x14` |
| `1001cb06` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001cb09` | `eb 53` | `JMP 0x1001cb5e` |
| `1001cb0b` | `83 3d 80 a6 43 13 03` | `CMP dword ptr [0x1343a680],0x3` |
| `1001cb12` | `75 38` | `JNZ 0x1001cb4c` |
| `1001cb14` | `6a 04` | `PUSH 0x4` |
| `1001cb16` | `e8 e8 96 ff ff` | `CALL 0x10016203` |
| `1001cb1b` | `59` | `POP ECX` |
| `1001cb1c` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `1001cb1f` | `53` | `PUSH EBX` |
| `1001cb20` | `e8 11 97 ff ff` | `CALL 0x10016236` |
| `1001cb25` | `59` | `POP ECX` |
| `1001cb26` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001cb29` | `3b c7` | `CMP EAX,EDI` |
| `1001cb2b` | `74 0b` | `JZ 0x1001cb38` |
| `1001cb2d` | `8b 73 fc` | `MOV ESI,dword ptr [EBX + -0x4]` |
| `1001cb30` | `83 ee 09` | `SUB ESI,0x9` |
| `1001cb33` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001cb36` | `eb 03` | `JMP 0x1001cb3b` |
| `1001cb38` | `8b 75 e4` | `MOV ESI,dword ptr [EBP + -0x1c]` |
| `1001cb3b` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001cb42` | `e8 25 00 00 00` | `CALL 0x1001cb6c` |
| `1001cb47` | `39 7d e0` | `CMP dword ptr [EBP + -0x20],EDI` |
| `1001cb4a` | `75 10` | `JNZ 0x1001cb5c` |
| `1001cb4c` | `53` | `PUSH EBX` |
| `1001cb4d` | `57` | `PUSH EDI` |
| `1001cb4e` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `1001cb54` | `ff 15 48 e1 02 10` | `CALL dword ptr [0x1002e148]` |
| `1001cb5a` | `8b f0` | `MOV ESI,EAX` |
| `1001cb5c` | `8b c6` | `MOV EAX,ESI` |
| `1001cb5e` | `e8 de a1 ff ff` | `CALL 0x10016d41` |
| `1001cb63` | `c3` | `RET` |
