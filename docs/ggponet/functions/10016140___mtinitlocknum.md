# 10016140 `__mtinitlocknum`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016140 |
| `name` | __mtinitlocknum |
| `namespace` | Global |
| `signature` | int __cdecl __mtinitlocknum(int _LockNum) |
| `size_bytes` | 186 |
| `stack_frame_size` | 40 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mtinitlocknum |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __mtinitlocknum
   
   Library: Visual Studio 2008 Release */

int __cdecl __mtinitlocknum(int _LockNum)

{
  void *_Memory;
  int *piVar1;
  int iVar2;
  int local_20;
  
  iVar2 = 1;
  local_20 = 1;
  if (DAT_10038dac == 0) {
    __FF_MSGBANNER();
    __NMSG_WRITE(0x1e);
    ___crtExitProcess(0xff);
  }
  piVar1 = &DAT_10037618 + _LockNum * 2;
  if (*piVar1 == 0) {
    _Memory = __malloc_crt(0x18);
    if (_Memory == (void *)0x0) {
      piVar1 = __errno();
      *piVar1 = 0xc;
      iVar2 = 0;
    }
    else {
      __lock(10);
      if (*piVar1 == 0) {
        iVar2 = ___crtInitCritSecAndSpinCount(_Memory,4000);
        if (iVar2 == 0) {
          _free(_Memory);
          piVar1 = __errno();
          *piVar1 = 0xc;
          local_20 = 0;
        }
        else {
          *piVar1 = (int)_Memory;
        }
      }
      else {
        _free(_Memory);
      }
      FUN_100161fa();
      iVar2 = local_20;
    }
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10016147` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001615c` | `10017097` | `UNCONDITIONAL_CALL` | __FF_MSGBANNER | `10017097` |
| `10016163` | `10016eec` | `UNCONDITIONAL_CALL` | __NMSG_WRITE | `10016eec` |
| `1001616d` | `10012490` | `UNCONDITIONAL_CALL` | ___crtExitProcess | `10012490` |
| `10016188` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `10016194` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100161a5` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `100161b8` | `100198f3` | `UNCONDITIONAL_CALL` | ___crtInitCritSecAndSpinCount | `100198f3` |
| `100161c4` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `100161ca` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100161df` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `100161ec` | `100161fa` | `UNCONDITIONAL_CALL` | FUN_100161fa | `100161fa` |
| `100161f4` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10016219` | __lock |
| `10018224` | __getstream |
| `1001dd0b` | __alloc_osfhnd |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10016142` | `10033e40` | `DATA` | DAT_10033e40 |
| `10016154` | `10038dac` | `READ` | DAT_10038dac |
| `10016177` | `10037618` | `DATA` | DAT_10037618 |
| `1001617e` | `10037618` | `DATA` | DAT_10037618 |
| `100161ae` | `10037618` | `DATA` | DAT_10037618 |
| `100161da` | `10037618` | `DATA` | DAT_10037618 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016140` | `6a 0c` | `PUSH 0xc` |
| `10016142` | `68 40 3e 03 10` | `PUSH 0x10033e40` |
| `10016147` | `e8 b0 0b 00 00` | `CALL 0x10016cfc` |
| `1001614c` | `33 ff` | `XOR EDI,EDI` |
| `1001614e` | `47` | `INC EDI` |
| `1001614f` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `10016152` | `33 db` | `XOR EBX,EBX` |
| `10016154` | `39 1d ac 8d 03 10` | `CMP dword ptr [0x10038dac],EBX` |
| `1001615a` | `75 18` | `JNZ 0x10016174` |
| `1001615c` | `e8 36 0f 00 00` | `CALL 0x10017097` |
| `10016161` | `6a 1e` | `PUSH 0x1e` |
| `10016163` | `e8 84 0d 00 00` | `CALL 0x10016eec` |
| `10016168` | `68 ff 00 00 00` | `PUSH 0xff` |
| `1001616d` | `e8 1e c3 ff ff` | `CALL 0x10012490` |
| `10016172` | `59` | `POP ECX` |
| `10016173` | `59` | `POP ECX` |
| `10016174` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10016177` | `8d 34 f5 18 76 03 10` | `LEA ESI,[ESI*0x8 + 0x10037618]` |
| `1001617e` | `39 1e` | `CMP dword ptr [ESI],EBX` |
| `10016180` | `74 04` | `JZ 0x10016186` |
| `10016182` | `8b c7` | `MOV EAX,EDI` |
| `10016184` | `eb 6e` | `JMP 0x100161f4` |
| `10016186` | `6a 18` | `PUSH 0x18` |
| `10016188` | `e8 42 43 00 00` | `CALL 0x1001a4cf` |
| `1001618d` | `59` | `POP ECX` |
| `1001618e` | `8b f8` | `MOV EDI,EAX` |
| `10016190` | `3b fb` | `CMP EDI,EBX` |
| `10016192` | `75 0f` | `JNZ 0x100161a3` |
| `10016194` | `e8 70 ef ff ff` | `CALL 0x10015109` |
| `10016199` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `1001619f` | `33 c0` | `XOR EAX,EAX` |
| `100161a1` | `eb 51` | `JMP 0x100161f4` |
| `100161a3` | `6a 0a` | `PUSH 0xa` |
| `100161a5` | `e8 59 00 00 00` | `CALL 0x10016203` |
| `100161aa` | `59` | `POP ECX` |
| `100161ab` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `100161ae` | `39 1e` | `CMP dword ptr [ESI],EBX` |
| `100161b0` | `75 2c` | `JNZ 0x100161de` |
| `100161b2` | `68 a0 0f 00 00` | `PUSH 0xfa0` |
| `100161b7` | `57` | `PUSH EDI` |
| `100161b8` | `e8 36 37 00 00` | `CALL 0x100198f3` |
| `100161bd` | `59` | `POP ECX` |
| `100161be` | `59` | `POP ECX` |
| `100161bf` | `85 c0` | `TEST EAX,EAX` |
| `100161c1` | `75 17` | `JNZ 0x100161da` |
| `100161c3` | `57` | `PUSH EDI` |
| `100161c4` | `e8 78 b0 ff ff` | `CALL 0x10011241` |
| `100161c9` | `59` | `POP ECX` |
| `100161ca` | `e8 3a ef ff ff` | `CALL 0x10015109` |
| `100161cf` | `c7 00 0c 00 00 00` | `MOV dword ptr [EAX],0xc` |
| `100161d5` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `100161d8` | `eb 0b` | `JMP 0x100161e5` |
| `100161da` | `89 3e` | `MOV dword ptr [ESI],EDI` |
| `100161dc` | `eb 07` | `JMP 0x100161e5` |
| `100161de` | `57` | `PUSH EDI` |
| `100161df` | `e8 5d b0 ff ff` | `CALL 0x10011241` |
| `100161e4` | `59` | `POP ECX` |
| `100161e5` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `100161ec` | `e8 09 00 00 00` | `CALL 0x100161fa` |
| `100161f1` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `100161f4` | `e8 48 0b 00 00` | `CALL 0x10016d41` |
| `100161f9` | `c3` | `RET` |
