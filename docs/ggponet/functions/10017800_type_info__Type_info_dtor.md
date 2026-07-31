# 10017800 `type_info::_Type_info_dtor`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017800 |
| `name` | type_info::_Type_info_dtor |
| `namespace` | type_info (GhidraClass) |
| `signature` | void __cdecl _Type_info_dtor(type_info * param_1) |
| `size_bytes` | 103 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_Type_info_dtor@type_info@@CAXPAV1@@Z, type_info::_Type_info_dtor |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static void __cdecl type_info::_Type_info_dtor(class type_info *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl type_info::_Type_info_dtor(type_info *param_1)

{
  int *_Memory;
  int *piVar1;
  int *piVar2;
  
  __lock(0xe);
  _Memory = DAT_10039238;
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)&DAT_10039234;
    do {
      piVar2 = piVar1;
      if (DAT_10039238 == (int *)0x0) goto LAB_10017844;
      piVar1 = DAT_10039238;
    } while (*DAT_10039238 != *(int *)(param_1 + 4));
    piVar2[1] = DAT_10039238[1];
    _free(_Memory);
LAB_10017844:
    _free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  FUN_10017867();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017807` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001780e` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001783e` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10017847` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `10017858` | `10017867` | `UNCONDITIONAL_CALL` | FUN_10017867 | `10017867` |
| `1001785d` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10011889` | type_info::~type_info |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017802` | `10033eb0` | `DATA` | DAT_10033eb0 |
| `10017822` | `10039238` | `READ` | DAT_10039238 |
| `10017827` | `10039234` | `DATA` | DAT_10039234 |
| `1001783a` | `10039238` | `WRITE` | DAT_10039238 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017800` | `6a 0c` | `PUSH 0xc` |
| `10017802` | `68 b0 3e 03 10` | `PUSH 0x10033eb0` |
| `10017807` | `e8 f0 f4 ff ff` | `CALL 0x10016cfc` |
| `1001780c` | `6a 0e` | `PUSH 0xe` |
| `1001780e` | `e8 f0 e9 ff ff` | `CALL 0x10016203` |
| `10017813` | `59` | `POP ECX` |
| `10017814` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `10017818` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001781b` | `8b 4e 04` | `MOV ECX,dword ptr [ESI + 0x4]` |
| `1001781e` | `85 c9` | `TEST ECX,ECX` |
| `10017820` | `74 2f` | `JZ 0x10017851` |
| `10017822` | `a1 38 92 03 10` | `MOV EAX,[0x10039238]` |
| `10017827` | `ba 34 92 03 10` | `MOV EDX,0x10039234` |
| `1001782c` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001782f` | `85 c0` | `TEST EAX,EAX` |
| `10017831` | `74 11` | `JZ 0x10017844` |
| `10017833` | `39 08` | `CMP dword ptr [EAX],ECX` |
| `10017835` | `75 2c` | `JNZ 0x10017863` |
| `10017837` | `8b 48 04` | `MOV ECX,dword ptr [EAX + 0x4]` |
| `1001783a` | `89 4a 04` | `MOV dword ptr [EDX + 0x4],ECX` |
| `1001783d` | `50` | `PUSH EAX` |
| `1001783e` | `e8 fe 99 ff ff` | `CALL 0x10011241` |
| `10017843` | `59` | `POP ECX` |
| `10017844` | `ff 76 04` | `PUSH dword ptr [ESI + 0x4]` |
| `10017847` | `e8 f5 99 ff ff` | `CALL 0x10011241` |
| `1001784c` | `59` | `POP ECX` |
| `1001784d` | `83 66 04 00` | `AND dword ptr [ESI + 0x4],0x0` |
| `10017851` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10017858` | `e8 0a 00 00 00` | `CALL 0x10017867` |
| `1001785d` | `e8 df f4 ff ff` | `CALL 0x10016d41` |
| `10017862` | `c3` | `RET` |
| `10017863` | `8b d0` | `MOV EDX,EAX` |
| `10017865` | `eb c5` | `JMP 0x1001782c` |
