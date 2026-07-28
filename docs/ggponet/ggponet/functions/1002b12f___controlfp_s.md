# 1002b12f `__controlfp_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002b12f |
| `name` | __controlfp_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl __controlfp_s(uint * _CurrentState, uint _NewValue, uint _Mask) |
| `size_bytes` | 108 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __controlfp_s |

## Decompiled C

```c

/* Library Function - Single Match
    __controlfp_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl __controlfp_s(uint *_CurrentState,uint _NewValue,uint _Mask)

{
  uint uVar1;
  int *piVar2;
  errno_t eVar3;
  
  uVar1 = _Mask & 0xfff7ffff;
  if ((_NewValue & uVar1 & 0xfcf0fce0) == 0) {
    if (_CurrentState == (uint *)0x0) {
      __control87(_NewValue,uVar1);
    }
    else {
      uVar1 = __control87(_NewValue,uVar1);
      *_CurrentState = uVar1;
    }
    eVar3 = 0;
  }
  else {
    if (_CurrentState != (uint *)0x0) {
      uVar1 = __control87(0,0);
      *_CurrentState = uVar1;
    }
    piVar2 = __errno();
    eVar3 = 0x16;
    *piVar2 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  return eVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002b156` | `1002cd6d` | `UNCONDITIONAL_CALL` | __control87 | `1002cd6d` |
| `1002b15f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002b16e` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002b186` | `1002cd6d` | `UNCONDITIONAL_CALL` | __control87 | `1002cd6d` |
| `1002b18f` | `1002cd6d` | `UNCONDITIONAL_CALL` | __control87 | `1002cd6d` |

## Callers

| From | Function |
| --- | --- |
| `1002ac16` | __setdefaultprecision |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002b12f` | `8b ff` | `MOV EDI,EDI` |
| `1002b131` | `55` | `PUSH EBP` |
| `1002b132` | `8b ec` | `MOV EBP,ESP` |
| `1002b134` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1002b137` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `1002b13a` | `25 ff ff f7 ff` | `AND EAX,0xfff7ffff` |
| `1002b13f` | `23 c8` | `AND ECX,EAX` |
| `1002b141` | `56` | `PUSH ESI` |
| `1002b142` | `f7 c1 e0 fc f0 fc` | `TEST ECX,0xfcf0fce0` |
| `1002b148` | `74 31` | `JZ 0x1002b17b` |
| `1002b14a` | `57` | `PUSH EDI` |
| `1002b14b` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `1002b14e` | `33 f6` | `XOR ESI,ESI` |
| `1002b150` | `3b fe` | `CMP EDI,ESI` |
| `1002b152` | `74 0b` | `JZ 0x1002b15f` |
| `1002b154` | `56` | `PUSH ESI` |
| `1002b155` | `56` | `PUSH ESI` |
| `1002b156` | `e8 12 1c 00 00` | `CALL 0x1002cd6d` |
| `1002b15b` | `59` | `POP ECX` |
| `1002b15c` | `59` | `POP ECX` |
| `1002b15d` | `89 07` | `MOV dword ptr [EDI],EAX` |
| `1002b15f` | `e8 a5 9f fe ff` | `CALL 0x10015109` |
| `1002b164` | `6a 16` | `PUSH 0x16` |
| `1002b166` | `5f` | `POP EDI` |
| `1002b167` | `56` | `PUSH ESI` |
| `1002b168` | `56` | `PUSH ESI` |
| `1002b169` | `56` | `PUSH ESI` |
| `1002b16a` | `56` | `PUSH ESI` |
| `1002b16b` | `56` | `PUSH ESI` |
| `1002b16c` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `1002b16e` | `e8 3c 65 fe ff` | `CALL 0x100116af` |
| `1002b173` | `83 c4 14` | `ADD ESP,0x14` |
| `1002b176` | `8b c7` | `MOV EAX,EDI` |
| `1002b178` | `5f` | `POP EDI` |
| `1002b179` | `eb 1d` | `JMP 0x1002b198` |
| `1002b17b` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1002b17e` | `50` | `PUSH EAX` |
| `1002b17f` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002b182` | `85 f6` | `TEST ESI,ESI` |
| `1002b184` | `74 09` | `JZ 0x1002b18f` |
| `1002b186` | `e8 e2 1b 00 00` | `CALL 0x1002cd6d` |
| `1002b18b` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1002b18d` | `eb 05` | `JMP 0x1002b194` |
| `1002b18f` | `e8 d9 1b 00 00` | `CALL 0x1002cd6d` |
| `1002b194` | `59` | `POP ECX` |
| `1002b195` | `59` | `POP ECX` |
| `1002b196` | `33 c0` | `XOR EAX,EAX` |
| `1002b198` | `5e` | `POP ESI` |
| `1002b199` | `5d` | `POP EBP` |
| `1002b19a` | `c3` | `RET` |
