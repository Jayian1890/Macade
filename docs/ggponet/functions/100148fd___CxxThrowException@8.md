# 100148fd `__CxxThrowException@8`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100148fd |
| `name` | __CxxThrowException@8 |
| `namespace` | Global |
| `signature` | noreturn undefined __CxxThrowException@8(void) |
| `size_bytes` | 76 |
| `stack_frame_size` | 40 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __CxxThrowException@8 |

## Decompiled C

```c

/* Library Function - Single Match
    __CxxThrowException@8
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __CxxThrowException_8(undefined4 param_1,byte *param_2)

{
  int iVar1;
  DWORD *pDVar2;
  DWORD *pDVar3;
  DWORD local_24 [4];
  DWORD local_14;
  ULONG_PTR local_10;
  undefined4 local_c;
  byte *local_8;
  
  pDVar2 = &DAT_1002f004;
  pDVar3 = local_24;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pDVar3 = *pDVar2;
    pDVar2 = pDVar2 + 1;
    pDVar3 = pDVar3 + 1;
  }
  local_c = param_1;
  local_8 = param_2;
  if ((param_2 != (byte *)0x0) && ((*param_2 & 8) != 0)) {
    local_10 = 0x1994000;
  }
  RaiseException(local_24[0],local_24[1],local_14,&local_10);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001493f` | `EXTERNAL:0000003c` | `COMPUTED_CALL` | KERNEL32.DLL::RaiseException | `` |

## Callers

| From | Function |
| --- | --- |
| `1001af78` | Catch_All@1001af66 |
| `1000a1ea` | FUN_1000a1d0 |
| `1000a12a` | FUN_1000a110 |
| `10008206` | Catch_All@100081b5 |
| `10007db3` | Catch_All@10007d80 |
| `100071a3` | Catch_All@1000718e |
| `100070ab` | Catch_All@1000705a |
| `10002036` | Catch_All@10001fe5 |
| `10001c13` | Catch_All@10001be0 |
| `1000a7cc` | FUN_1000a7b2 |
| `1000a70c` | FUN_1000a6f2 |
| `1000651a` | FUN_100064b0 |
| `10002755` | std::_Allocate<char> |
| `10010c82` | FUN_10010c50 |
| `10010cba` | FUN_10010c88 |
| `1001194b` | FUN_100118ec |
| `1000238f` | Catch_All@1000237f |
| `10009909` | Catch_All@100098ac |
| `10009a3a` | Catch_All@10009a17 |
| `10009487` | Catch_All@1000942c |
| `100095ac` | Catch_All@10009589 |
| `1000b2b6` | FUN_1000b276 |
| `10003dd5` | FUN_10003da0 |
| `10003505` | FUN_100034d0 |
| `1000460e` | FUN_100045c0 |
| `100077b5` | FUN_10007780 |
| `10008895` | FUN_10008860 |
| `100096ce` | FUN_10009680 |
| `10008845` | FUN_10008810 |
| `100026b5` | FUN_10002680 |
| `100020d4` | FUN_10002070 |
| `10003d35` | FUN_10003d00 |
| `10005e35` | FUN_10005dd0 |
| `100082a4` | FUN_10008240 |
| `1000b0e5` | FUN_1000b0b0 |
| `1001b5f0` | FindHandler |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001490d` | `1002f004` | `DATA` | DAT_1002f004 |
| `10014915` | `1002f004` | `READ` | DAT_1002f004 |
| `10014915` | `1002f008` | `READ` | DAT_1002f008 |
| `1001493f` | `1002e0a8` | `READ` | PTR_RaiseException_1002e0a8 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100148fd` | `8b ff` | `MOV EDI,EDI` |
| `100148ff` | `55` | `PUSH EBP` |
| `10014900` | `8b ec` | `MOV EBP,ESP` |
| `10014902` | `83 ec 20` | `SUB ESP,0x20` |
| `10014905` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10014908` | `56` | `PUSH ESI` |
| `10014909` | `57` | `PUSH EDI` |
| `1001490a` | `6a 08` | `PUSH 0x8` |
| `1001490c` | `59` | `POP ECX` |
| `1001490d` | `be 04 f0 02 10` | `MOV ESI,0x1002f004` |
| `10014912` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `10014915` | `f3 a5` | `MOVSD.REP ES:EDI,ESI` |
| `10014917` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001491a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1001491d` | `5f` | `POP EDI` |
| `1001491e` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10014921` | `5e` | `POP ESI` |
| `10014922` | `85 c0` | `TEST EAX,EAX` |
| `10014924` | `74 0c` | `JZ 0x10014932` |
| `10014926` | `f6 00 08` | `TEST byte ptr [EAX],0x8` |
| `10014929` | `74 07` | `JZ 0x10014932` |
| `1001492b` | `c7 45 f4 00 40 99 01` | `MOV dword ptr [EBP + -0xc],0x1994000` |
| `10014932` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10014935` | `50` | `PUSH EAX` |
| `10014936` | `ff 75 f0` | `PUSH dword ptr [EBP + -0x10]` |
| `10014939` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001493c` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001493f` | `ff 15 a8 e0 02 10` | `CALL dword ptr [0x1002e0a8]` |
| `10014945` | `c9` | `LEAVE` |
| `10014946` | `c2 08 00` | `RET 0x8` |
