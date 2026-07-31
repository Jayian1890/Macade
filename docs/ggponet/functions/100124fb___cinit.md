# 100124fb `__cinit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100124fb |
| `name` | __cinit |
| `namespace` | Global |
| `signature` | int __cdecl __cinit(int param_1) |
| `size_bytes` | 133 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cinit |

## Decompiled C

```c

/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2008 Release */

int __cdecl __cinit(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR___fpmath_10033470);
  if (BVar1 != 0) {
    __fpmath(param_1);
  }
  __initp_misc_cfltcvt_tab();
  iVar2 = __initterm_e(&DAT_1002e1b0,&DAT_1002e1c4);
  if (iVar2 == 0) {
    _atexit((_func_4879 *)&LAB_1001930b);
    __initterm(&DAT_1002e1ac);
    if ((DAT_1343a69c != (code *)0x0) &&
       (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1343a69c), BVar1 != 0)) {
      (*DAT_1343a69c)(0,2,0);
    }
    iVar2 = 0;
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001250e` | `100193f0` | `UNCONDITIONAL_CALL` | __IsNonwritableInCurrentImage | `100193f0` |
| `1001251b` | `1002a04f` | `COMPUTED_CALL` | __fpmath | `1002a04f` |
| `10012522` | `10019331` | `UNCONDITIONAL_CALL` | __initp_misc_cfltcvt_tab | `10019331` |
| `10012531` | `100124d7` | `UNCONDITIONAL_CALL` | __initterm_e | `100124d7` |
| `10012541` | `10017997` | `UNCONDITIONAL_CALL` | _atexit | `10017997` |
| `10012552` | `100124ba` | `UNCONDITIONAL_CALL` | __initterm | `100124ba` |
| `10012566` | `100193f0` | `UNCONDITIONAL_CALL` | __IsNonwritableInCurrentImage | `100193f0` |

## Callers

| From | Function |
| --- | --- |
| `100146de` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012500` | `10033470` | `READ` | PTR___fpmath_10033470 |
| `10012509` | `10033470` | `DATA` | PTR___fpmath_10033470 |
| `1001251b` | `10033470` | `READ` | PTR___fpmath_10033470 |
| `10012527` | `1002e1c4` | `DATA` | DAT_1002e1c4 |
| `1001252c` | `1002e1b0` | `DATA` | DAT_1002e1b0 |
| `1001253c` | `1001930b` | `DATA` | LAB_1001930b |
| `10012546` | `1002e1a8` | `DATA` | DAT_1002e1a8 |
| `1001254b` | `1002e1ac` | `DATA` | DAT_1002e1ac |
| `10012557` | `1343a69c` | `READ` | DAT_1343a69c |
| `10012561` | `1343a69c` | `DATA` | DAT_1343a69c |
| `10012576` | `1343a69c` | `READ` | DAT_1343a69c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100124fb` | `8b ff` | `MOV EDI,EDI` |
| `100124fd` | `55` | `PUSH EBP` |
| `100124fe` | `8b ec` | `MOV EBP,ESP` |
| `10012500` | `83 3d 70 34 03 10 00` | `CMP dword ptr [0x10033470],0x0` |
| `10012507` | `74 19` | `JZ 0x10012522` |
| `10012509` | `68 70 34 03 10` | `PUSH 0x10033470` |
| `1001250e` | `e8 dd 6e 00 00` | `CALL 0x100193f0` |
| `10012513` | `59` | `POP ECX` |
| `10012514` | `85 c0` | `TEST EAX,EAX` |
| `10012516` | `74 0a` | `JZ 0x10012522` |
| `10012518` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001251b` | `ff 15 70 34 03 10` | `CALL dword ptr [0x10033470]` |
| `10012521` | `59` | `POP ECX` |
| `10012522` | `e8 0a 6e 00 00` | `CALL 0x10019331` |
| `10012527` | `68 c4 e1 02 10` | `PUSH 0x1002e1c4` |
| `1001252c` | `68 b0 e1 02 10` | `PUSH 0x1002e1b0` |
| `10012531` | `e8 a1 ff ff ff` | `CALL 0x100124d7` |
| `10012536` | `59` | `POP ECX` |
| `10012537` | `59` | `POP ECX` |
| `10012538` | `85 c0` | `TEST EAX,EAX` |
| `1001253a` | `75 42` | `JNZ 0x1001257e` |
| `1001253c` | `68 0b 93 01 10` | `PUSH 0x1001930b` |
| `10012541` | `e8 51 54 00 00` | `CALL 0x10017997` |
| `10012546` | `b8 a8 e1 02 10` | `MOV EAX,0x1002e1a8` |
| `1001254b` | `c7 04 24 ac e1 02 10` | `MOV dword ptr [ESP],0x1002e1ac` |
| `10012552` | `e8 63 ff ff ff` | `CALL 0x100124ba` |
| `10012557` | `83 3d 9c a6 43 13 00` | `CMP dword ptr [0x1343a69c],0x0` |
| `1001255e` | `59` | `POP ECX` |
| `1001255f` | `74 1b` | `JZ 0x1001257c` |
| `10012561` | `68 9c a6 43 13` | `PUSH 0x1343a69c` |
| `10012566` | `e8 85 6e 00 00` | `CALL 0x100193f0` |
| `1001256b` | `59` | `POP ECX` |
| `1001256c` | `85 c0` | `TEST EAX,EAX` |
| `1001256e` | `74 0c` | `JZ 0x1001257c` |
| `10012570` | `6a 00` | `PUSH 0x0` |
| `10012572` | `6a 02` | `PUSH 0x2` |
| `10012574` | `6a 00` | `PUSH 0x0` |
| `10012576` | `ff 15 9c a6 43 13` | `CALL dword ptr [0x1343a69c]` |
| `1001257c` | `33 c0` | `XOR EAX,EAX` |
| `1001257e` | `5d` | `POP EBP` |
| `1001257f` | `c3` | `RET` |
