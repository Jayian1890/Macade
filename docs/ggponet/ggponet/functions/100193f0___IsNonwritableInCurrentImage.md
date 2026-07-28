# 100193f0 `__IsNonwritableInCurrentImage`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100193f0 |
| `name` | __IsNonwritableInCurrentImage |
| `namespace` | Global |
| `signature` | BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget) |
| `size_bytes` | 166 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __IsNonwritableInCurrentImage |

## Decompiled C

```c

/* Library Function - Single Match
    __IsNonwritableInCurrentImage
   
   Library: Visual Studio 2008 Release */

BOOL __cdecl __IsNonwritableInCurrentImage(PBYTE pTarget)

{
  BOOL BVar1;
  PIMAGE_SECTION_HEADER p_Var2;
  void *local_14;
  code *pcStack_10;
  uint local_c;
  undefined4 local_8;
  
  pcStack_10 = __except_handler4;
  local_14 = ExceptionList;
  local_c = DAT_10037490 ^ 0x10033f70;
  ExceptionList = &local_14;
  local_8 = 0;
  BVar1 = __ValidateImageBase((PBYTE)&IMAGE_DOS_HEADER_10000000);
  if (BVar1 != 0) {
    p_Var2 = __FindPESection((PBYTE)&IMAGE_DOS_HEADER_10000000,(DWORD_PTR)(pTarget + -0x10000000));
    if (p_Var2 != (PIMAGE_SECTION_HEADER)0x0) {
      ExceptionList = local_14;
      return ~(p_Var2->Characteristics >> 0x1f) & 1;
    }
  }
  ExceptionList = local_14;
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019431` | `10019360` | `UNCONDITIONAL_CALL` | __ValidateImageBase | `10019360` |
| `1001944b` | `100193a0` | `UNCONDITIONAL_CALL` | __FindPESection | `100193a0` |

## Callers

| From | Function |
| --- | --- |
| `1001250e` | __cinit |
| `10012566` | __cinit |
| `10016e58` | __except_handler4 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100193f7` | `10033f70` | `DATA` | DAT_10033f70 |
| `100193fc` | `10016d60` | `DATA` | __except_handler4 |
| `10019401` | `ffdff000` | `READ` | ExceptionList |
| `1001940e` | `10037490` | `READ` | DAT_10037490 |
| `1001941c` | `ffdff000` | `WRITE` | ExceptionList |
| `1001942c` | `10000000` | `DATA` | IMAGE_DOS_HEADER_10000000 |
| `10019440` | `10000000` | `DATA` | IMAGE_DOS_HEADER_10000000 |
| `10019446` | `10000000` | `DATA` | IMAGE_DOS_HEADER_10000000 |
| `1001946c` | `ffdff000` | `WRITE` | ExceptionList |
| `1001949e` | `ffdff000` | `WRITE` | ExceptionList |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100193f0` | `8b ff` | `MOV EDI,EDI` |
| `100193f2` | `55` | `PUSH EBP` |
| `100193f3` | `8b ec` | `MOV EBP,ESP` |
| `100193f5` | `6a fe` | `PUSH -0x2` |
| `100193f7` | `68 70 3f 03 10` | `PUSH 0x10033f70` |
| `100193fc` | `68 60 6d 01 10` | `PUSH 0x10016d60` |
| `10019401` | `64 a1 00 00 00 00` | `MOV EAX,FS:[0x0]` |
| `10019407` | `50` | `PUSH EAX` |
| `10019408` | `83 ec 08` | `SUB ESP,0x8` |
| `1001940b` | `53` | `PUSH EBX` |
| `1001940c` | `56` | `PUSH ESI` |
| `1001940d` | `57` | `PUSH EDI` |
| `1001940e` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10019413` | `31 45 f8` | `XOR dword ptr [EBP + -0x8],EAX` |
| `10019416` | `33 c5` | `XOR EAX,EBP` |
| `10019418` | `50` | `PUSH EAX` |
| `10019419` | `8d 45 f0` | `LEA EAX,[EBP + -0x10]` |
| `1001941c` | `64 a3 00 00 00 00` | `MOV FS:[0x0],EAX` |
| `10019422` | `89 65 e8` | `MOV dword ptr [EBP + -0x18],ESP` |
| `10019425` | `c7 45 fc 00 00 00 00` | `MOV dword ptr [EBP + -0x4],0x0` |
| `1001942c` | `68 00 00 00 10` | `PUSH 0x10000000` |
| `10019431` | `e8 2a ff ff ff` | `CALL 0x10019360` |
| `10019436` | `83 c4 04` | `ADD ESP,0x4` |
| `10019439` | `85 c0` | `TEST EAX,EAX` |
| `1001943b` | `74 55` | `JZ 0x10019492` |
| `1001943d` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10019440` | `2d 00 00 00 10` | `SUB EAX,0x10000000` |
| `10019445` | `50` | `PUSH EAX` |
| `10019446` | `68 00 00 00 10` | `PUSH 0x10000000` |
| `1001944b` | `e8 50 ff ff ff` | `CALL 0x100193a0` |
| `10019450` | `83 c4 08` | `ADD ESP,0x8` |
| `10019453` | `85 c0` | `TEST EAX,EAX` |
| `10019455` | `74 3b` | `JZ 0x10019492` |
| `10019457` | `8b 40 24` | `MOV EAX,dword ptr [EAX + 0x24]` |
| `1001945a` | `c1 e8 1f` | `SHR EAX,0x1f` |
| `1001945d` | `f7 d0` | `NOT EAX` |
| `1001945f` | `83 e0 01` | `AND EAX,0x1` |
| `10019462` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10019469` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001946c` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `10019473` | `59` | `POP ECX` |
| `10019474` | `5f` | `POP EDI` |
| `10019475` | `5e` | `POP ESI` |
| `10019476` | `5b` | `POP EBX` |
| `10019477` | `8b e5` | `MOV ESP,EBP` |
| `10019479` | `5d` | `POP EBP` |
| `1001947a` | `c3` | `RET` |
| `10019492` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10019499` | `33 c0` | `XOR EAX,EAX` |
| `1001949b` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1001949e` | `64 89 0d 00 00 00 00` | `MOV dword ptr FS:[0x0],ECX` |
| `100194a5` | `59` | `POP ECX` |
| `100194a6` | `5f` | `POP EDI` |
| `100194a7` | `5e` | `POP ESI` |
| `100194a8` | `5b` | `POP EBX` |
| `100194a9` | `8b e5` | `MOV ESP,EBP` |
| `100194ab` | `5d` | `POP EBP` |
| `100194ac` | `c3` | `RET` |
