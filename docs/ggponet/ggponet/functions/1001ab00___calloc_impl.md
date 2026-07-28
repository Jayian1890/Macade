# 1001ab00 `__calloc_impl`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ab00 |
| `name` | __calloc_impl |
| `namespace` | Global |
| `signature` | undefined __calloc_impl(void) |
| `size_bytes` | 272 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __calloc_impl |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __calloc_impl
   
   Library: Visual Studio 2008 Release */

void * __calloc_impl(uint param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  void *_Dst;
  uint dwBytes;
  
  if ((param_1 == 0) || (param_2 <= 0xffffffe0 / param_1)) {
    param_1 = param_1 * param_2;
    dwBytes = param_1;
    if (param_1 == 0) {
      dwBytes = 1;
    }
    do {
      _Dst = (void *)0x0;
      if (dwBytes < 0xffffffe1) {
        if ((DAT_1343a680 == 3) && (dwBytes = dwBytes + 0xf & 0xfffffff0, param_1 <= DAT_1343a670))
        {
          __lock(4);
          _Dst = (void *)___sbh_alloc_block(param_1);
          FUN_1001abfc();
          if (_Dst != (void *)0x0) {
            _memset(_Dst,0,param_1);
            goto LAB_1001abb1;
          }
        }
        else {
LAB_1001abb1:
          if (_Dst != (void *)0x0) {
            return _Dst;
          }
        }
        _Dst = HeapAlloc(DAT_10038dac,8,dwBytes);
      }
      if (_Dst != (void *)0x0) {
        return _Dst;
      }
      if (DAT_10039220 == 0) {
        if (param_3 == (undefined4 *)0x0) {
          return (void *)0x0;
        }
        *param_3 = 0xc;
        return (void *)0x0;
      }
      iVar2 = __callnewh(dwBytes);
    } while (iVar2 != 0);
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0xc;
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0xc;
    __invalid_parameter(0,0,0,0,0);
  }
  return (void *)0x0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ab07` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001ab24` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001ab34` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001ab7c` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `1001ab88` | `10016a15` | `UNCONDITIONAL_CALL` | ___sbh_alloc_block | `10016a15` |
| `1001ab98` | `1001abfc` | `UNCONDITIONAL_CALL` | FUN_1001abfc | `1001abfc` |
| `1001aba9` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001abbe` | `EXTERNAL:00000030` | `COMPUTED_CALL` | KERNEL32.DLL::HeapAlloc | `` |
| `1001abd3` | `100170df` | `UNCONDITIONAL_CALL` | __callnewh | `100170df` |
| `1001ac18` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001a525` | __calloc_crt |
| `100148d2` | _calloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001ab02` | `10034050` | `DATA` | DAT_10034050 |
| `1001ab5d` | `1343a680` | `READ` | DAT_1343a680 |
| `1001ab72` | `1343a670` | `READ` | DAT_1343a670 |
| `1001abb8` | `10038dac` | `READ` | DAT_10038dac |
| `1001abbe` | `1002e078` | `READ` | PTR_HeapAlloc_1002e078 |
| `1001abca` | `10039220` | `READ` | DAT_10039220 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ab00` | `6a 0c` | `PUSH 0xc` |
| `1001ab02` | `68 50 40 03 10` | `PUSH 0x10034050` |
| `1001ab07` | `e8 f0 c1 ff ff` | `CALL 0x10016cfc` |
| `1001ab0c` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001ab0f` | `33 ff` | `XOR EDI,EDI` |
| `1001ab11` | `3b cf` | `CMP ECX,EDI` |
| `1001ab13` | `76 2e` | `JBE 0x1001ab43` |
| `1001ab15` | `6a e0` | `PUSH -0x20` |
| `1001ab17` | `58` | `POP EAX` |
| `1001ab18` | `33 d2` | `XOR EDX,EDX` |
| `1001ab1a` | `f7 f1` | `DIV ECX` |
| `1001ab1c` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `1001ab1f` | `1b c0` | `SBB EAX,EAX` |
| `1001ab21` | `40` | `INC EAX` |
| `1001ab22` | `75 1f` | `JNZ 0x1001ab43` |
| `1001ab24` | `e8 e0 a5 ff ff` | `CALL 0x10015109` |
| `1001ab29` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001ab2f` | `57` | `PUSH EDI` |
| `1001ab30` | `57` | `PUSH EDI` |
| `1001ab31` | `57` | `PUSH EDI` |
| `1001ab32` | `57` | `PUSH EDI` |
| `1001ab33` | `57` | `PUSH EDI` |
| `1001ab34` | `e8 76 6b ff ff` | `CALL 0x100116af` |
| `1001ab39` | `83 c4 14` | `ADD ESP,0x14` |
| `1001ab3c` | `33 c0` | `XOR EAX,EAX` |
| `1001ab3e` | `e9 d5 00 00 00` | `JMP 0x1001ac18` |
| `1001ab43` | `0f af 4d 0c` | `IMUL ECX,dword ptr [EBP + 0xc]` |
| `1001ab47` | `8b f1` | `MOV ESI,ECX` |
| `1001ab49` | `89 75 08` | `MOV dword ptr [EBP + 0x8],ESI` |
| `1001ab4c` | `3b f7` | `CMP ESI,EDI` |
| `1001ab4e` | `75 03` | `JNZ 0x1001ab53` |
| `1001ab50` | `33 f6` | `XOR ESI,ESI` |
| `1001ab52` | `46` | `INC ESI` |
| `1001ab53` | `33 db` | `XOR EBX,EBX` |
| `1001ab55` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1001ab58` | `83 fe e0` | `CMP ESI,-0x20` |
| `1001ab5b` | `77 69` | `JA 0x1001abc6` |
| `1001ab5d` | `83 3d 80 a6 43 13 03` | `CMP dword ptr [0x1343a680],0x3` |
| `1001ab64` | `75 4b` | `JNZ 0x1001abb1` |
| `1001ab66` | `83 c6 0f` | `ADD ESI,0xf` |
| `1001ab69` | `83 e6 f0` | `AND ESI,0xfffffff0` |
| `1001ab6c` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `1001ab6f` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001ab72` | `3b 05 70 a6 43 13` | `CMP EAX,dword ptr [0x1343a670]` |
| `1001ab78` | `77 37` | `JA 0x1001abb1` |
| `1001ab7a` | `6a 04` | `PUSH 0x4` |
| `1001ab7c` | `e8 82 b6 ff ff` | `CALL 0x10016203` |
| `1001ab81` | `59` | `POP ECX` |
| `1001ab82` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `1001ab85` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ab88` | `e8 88 be ff ff` | `CALL 0x10016a15` |
| `1001ab8d` | `59` | `POP ECX` |
| `1001ab8e` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001ab91` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001ab98` | `e8 5f 00 00 00` | `CALL 0x1001abfc` |
| `1001ab9d` | `8b 5d e4` | `MOV EBX,dword ptr [EBP + -0x1c]` |
| `1001aba0` | `3b df` | `CMP EBX,EDI` |
| `1001aba2` | `74 11` | `JZ 0x1001abb5` |
| `1001aba4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001aba7` | `57` | `PUSH EDI` |
| `1001aba8` | `53` | `PUSH EBX` |
| `1001aba9` | `e8 42 6b ff ff` | `CALL 0x100116f0` |
| `1001abae` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001abb1` | `3b df` | `CMP EBX,EDI` |
| `1001abb3` | `75 61` | `JNZ 0x1001ac16` |
| `1001abb5` | `56` | `PUSH ESI` |
| `1001abb6` | `6a 08` | `PUSH 0x8` |
| `1001abb8` | `ff 35 ac 8d 03 10` | `PUSH dword ptr [0x10038dac]` |
| `1001abbe` | `ff 15 78 e0 02 10` | `CALL dword ptr [0x1002e078]` |
| `1001abc4` | `8b d8` | `MOV EBX,EAX` |
| `1001abc6` | `3b df` | `CMP EBX,EDI` |
| `1001abc8` | `75 4c` | `JNZ 0x1001ac16` |
| `1001abca` | `39 3d 20 92 03 10` | `CMP dword ptr [0x10039220],EDI` |
| `1001abd0` | `74 33` | `JZ 0x1001ac05` |
| `1001abd2` | `56` | `PUSH ESI` |
| `1001abd3` | `e8 07 c5 ff ff` | `CALL 0x100170df` |
| `1001abd8` | `59` | `POP ECX` |
| `1001abd9` | `85 c0` | `TEST EAX,EAX` |
| `1001abdb` | `0f 85 72 ff ff ff` | `JNZ 0x1001ab53` |
| `1001abe1` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001abe4` | `3b c7` | `CMP EAX,EDI` |
| `1001abe6` | `0f 84 50 ff ff ff` | `JZ 0x1001ab3c` |
| `1001abec` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001abf2` | `e9 45 ff ff ff` | `JMP 0x1001ab3c` |
| `1001ac05` | `3b df` | `CMP EBX,EDI` |
| `1001ac07` | `75 0d` | `JNZ 0x1001ac16` |
| `1001ac09` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001ac0c` | `3b c7` | `CMP EAX,EDI` |
| `1001ac0e` | `74 06` | `JZ 0x1001ac16` |
| `1001ac10` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001ac16` | `8b c3` | `MOV EAX,EBX` |
| `1001ac18` | `e8 24 c1 ff ff` | `CALL 0x10016d41` |
| `1001ac1d` | `c3` | `RET` |
