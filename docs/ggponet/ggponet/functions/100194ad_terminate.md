# 100194ad `terminate`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100194ad |
| `name` | terminate |
| `namespace` | Global |
| `signature` | void __cdecl terminate(void) |
| `size_bytes` | 44 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?terminate@@YAXXZ, terminate |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* Library Function - Single Match
    void __cdecl terminate(void)
   
   Library: Visual Studio 2008 Release */

void __cdecl terminate(void)

{
  _ptiddata p_Var1;
  
  p_Var1 = __getptd();
  if (p_Var1->_terminate != (code *)0x0) {
    (*p_Var1->_terminate)();
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100194b4` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `100194b9` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `100194db` | `100179ae` | `UNCONDITIONAL_CALL` | _abort | `100179ae` |

## Callers

| From | Function |
| --- | --- |
| `1001952b` | _inconsistency |
| `1001b5c9` | FindHandler |
| `1001aecb` | IsInExceptionSpec |
| `1001af61` | FUN_1001af35 |
| `100194f4` | FUN_100194e6 |
| `1001acf3` | ___FrameUnwindFilter |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100194af` | `10033f90` | `DATA` | DAT_10033f90 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100194ad` | `6a 08` | `PUSH 0x8` |
| `100194af` | `68 90 3f 03 10` | `PUSH 0x10033f90` |
| `100194b4` | `e8 43 d8 ff ff` | `CALL 0x10016cfc` |
| `100194b9` | `e8 18 df ff ff` | `CALL 0x100173d6` |
| `100194be` | `8b 40 78` | `MOV EAX,dword ptr [EAX + 0x78]` |
| `100194c1` | `85 c0` | `TEST EAX,EAX` |
| `100194c3` | `74 16` | `JZ 0x100194db` |
| `100194c5` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `100194c9` | `ff d0` | `CALL EAX` |
| `100194cb` | `eb 07` | `JMP 0x100194d4` |
| `100194d4` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `100194db` | `e8 ce e4 ff ff` | `CALL 0x100179ae` |
