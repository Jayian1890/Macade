# 100147a4 `___DllMainCRTStartup`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100147a4 |
| `name` | ___DllMainCRTStartup |
| `namespace` | Global |
| `signature` | undefined ___DllMainCRTStartup(void) |
| `size_bytes` | 226 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___DllMainCRTStartup |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10014836) */
/* WARNING: Removing unreachable block (ram,0x100147e3) */
/* WARNING: Removing unreachable block (ram,0x10014863) */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2008 Release */

int ___DllMainCRTStartup(undefined4 param_1)

{
  int iVar1;
  undefined4 in_ECX;
  int in_EDX;
  int local_20;
  
  if (((in_EDX == 0) && (DAT_10038a70 == 0)) ||
     (((in_EDX == 1 || (in_EDX == 2)) && (iVar1 = __CRT_INIT_12(param_1,in_EDX,in_ECX), iVar1 == 0))
     )) {
    local_20 = 0;
  }
  else {
    local_20 = FUN_10021cf0(param_1,in_EDX,in_ECX);
    if ((in_EDX == 1) && (local_20 == 0)) {
      FUN_10021cf0(param_1,0,in_ECX);
      __CRT_INIT_12(param_1,0,in_ECX);
    }
    if (((in_EDX == 0) || (in_EDX == 3)) &&
       (iVar1 = __CRT_INIT_12(param_1,in_EDX,in_ECX), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100147ab` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `100147f8` | `1001466f` | `UNCONDITIONAL_CALL` | __CRT_INIT@12 | `1001466f` |
| `1001480b` | `10021cf0` | `UNCONDITIONAL_CALL` | FUN_10021cf0 | `10021cf0` |
| `1001481f` | `10021cf0` | `UNCONDITIONAL_CALL` | FUN_10021cf0 | `10021cf0` |
| `10014828` | `1001466f` | `UNCONDITIONAL_CALL` | __CRT_INIT@12 | `1001466f` |
| `10014848` | `1001466f` | `UNCONDITIONAL_CALL` | __CRT_INIT@12 | `1001466f` |
| `10014894` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `100148b3` | entry |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100147a6` | `10033e00` | `DATA` | DAT_10033e00 |
| `100147c1` | `10038a70` | `READ` | DAT_10038a70 |
| `100147da` | `1002f000` | `READ` | DAT_1002f000 |
| `1001482d` | `1002f000` | `READ` | DAT_1002f000 |
| `1001485a` | `1002f000` | `READ` | DAT_1002f000 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100147a4` | `6a 0c` | `PUSH 0xc` |
| `100147a6` | `68 00 3e 03 10` | `PUSH 0x10033e00` |
| `100147ab` | `e8 4c 25 00 00` | `CALL 0x10016cfc` |
| `100147b0` | `8b f9` | `MOV EDI,ECX` |
| `100147b2` | `8b f2` | `MOV ESI,EDX` |
| `100147b4` | `8b 5d 08` | `MOV EBX,dword ptr [EBP + 0x8]` |
| `100147b7` | `33 c0` | `XOR EAX,EAX` |
| `100147b9` | `40` | `INC EAX` |
| `100147ba` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `100147bd` | `85 f6` | `TEST ESI,ESI` |
| `100147bf` | `75 0c` | `JNZ 0x100147cd` |
| `100147c1` | `39 15 70 8a 03 10` | `CMP dword ptr [0x10038a70],EDX` |
| `100147c7` | `0f 84 c5 00 00 00` | `JZ 0x10014892` |
| `100147cd` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `100147d1` | `3b f0` | `CMP ESI,EAX` |
| `100147d3` | `74 05` | `JZ 0x100147da` |
| `100147d5` | `83 fe 02` | `CMP ESI,0x2` |
| `100147d8` | `75 2e` | `JNZ 0x10014808` |
| `100147da` | `a1 00 f0 02 10` | `MOV EAX,[0x1002f000]` |
| `100147df` | `85 c0` | `TEST EAX,EAX` |
| `100147e1` | `74 08` | `JZ 0x100147eb` |
| `100147e3` | `57` | `PUSH EDI` |
| `100147e4` | `56` | `PUSH ESI` |
| `100147e5` | `53` | `PUSH EBX` |
| `100147e6` | `ff d0` | `CALL EAX` |
| `100147e8` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `100147eb` | `83 7d e4 00` | `CMP dword ptr [EBP + -0x1c],0x0` |
| `100147ef` | `0f 84 96 00 00 00` | `JZ 0x1001488b` |
| `100147f5` | `57` | `PUSH EDI` |
| `100147f6` | `56` | `PUSH ESI` |
| `100147f7` | `53` | `PUSH EBX` |
| `100147f8` | `e8 72 fe ff ff` | `CALL 0x1001466f` |
| `100147fd` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10014800` | `85 c0` | `TEST EAX,EAX` |
| `10014802` | `0f 84 83 00 00 00` | `JZ 0x1001488b` |
| `10014808` | `57` | `PUSH EDI` |
| `10014809` | `56` | `PUSH ESI` |
| `1001480a` | `53` | `PUSH EBX` |
| `1001480b` | `e8 e0 d4 00 00` | `CALL 0x10021cf0` |
| `10014810` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10014813` | `83 fe 01` | `CMP ESI,0x1` |
| `10014816` | `75 24` | `JNZ 0x1001483c` |
| `10014818` | `85 c0` | `TEST EAX,EAX` |
| `1001481a` | `75 20` | `JNZ 0x1001483c` |
| `1001481c` | `57` | `PUSH EDI` |
| `1001481d` | `50` | `PUSH EAX` |
| `1001481e` | `53` | `PUSH EBX` |
| `1001481f` | `e8 cc d4 00 00` | `CALL 0x10021cf0` |
| `10014824` | `57` | `PUSH EDI` |
| `10014825` | `6a 00` | `PUSH 0x0` |
| `10014827` | `53` | `PUSH EBX` |
| `10014828` | `e8 42 fe ff ff` | `CALL 0x1001466f` |
| `1001482d` | `a1 00 f0 02 10` | `MOV EAX,[0x1002f000]` |
| `10014832` | `85 c0` | `TEST EAX,EAX` |
| `10014834` | `74 06` | `JZ 0x1001483c` |
| `10014836` | `57` | `PUSH EDI` |
| `10014837` | `6a 00` | `PUSH 0x0` |
| `10014839` | `53` | `PUSH EBX` |
| `1001483a` | `ff d0` | `CALL EAX` |
| `1001483c` | `85 f6` | `TEST ESI,ESI` |
| `1001483e` | `74 05` | `JZ 0x10014845` |
| `10014840` | `83 fe 03` | `CMP ESI,0x3` |
| `10014843` | `75 26` | `JNZ 0x1001486b` |
| `10014845` | `57` | `PUSH EDI` |
| `10014846` | `56` | `PUSH ESI` |
| `10014847` | `53` | `PUSH EBX` |
| `10014848` | `e8 22 fe ff ff` | `CALL 0x1001466f` |
| `1001484d` | `85 c0` | `TEST EAX,EAX` |
| `1001484f` | `75 03` | `JNZ 0x10014854` |
| `10014851` | `21 45 e4` | `AND dword ptr [EBP + -0x1c],EAX` |
| `10014854` | `83 7d e4 00` | `CMP dword ptr [EBP + -0x1c],0x0` |
| `10014858` | `74 11` | `JZ 0x1001486b` |
| `1001485a` | `a1 00 f0 02 10` | `MOV EAX,[0x1002f000]` |
| `1001485f` | `85 c0` | `TEST EAX,EAX` |
| `10014861` | `74 08` | `JZ 0x1001486b` |
| `10014863` | `57` | `PUSH EDI` |
| `10014864` | `56` | `PUSH ESI` |
| `10014865` | `53` | `PUSH EBX` |
| `10014866` | `ff d0` | `CALL EAX` |
| `10014868` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001486b` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10014872` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `10014875` | `eb 1d` | `JMP 0x10014894` |
| `1001488b` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10014892` | `33 c0` | `XOR EAX,EAX` |
| `10014894` | `e8 a8 24 00 00` | `CALL 0x10016d41` |
| `10014899` | `c3` | `RET` |
