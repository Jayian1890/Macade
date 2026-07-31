# 100150c7 `__get_errno_from_oserr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100150c7 |
| `name` | __get_errno_from_oserr |
| `namespace` | Global |
| `signature` | int __cdecl __get_errno_from_oserr(ulong param_1) |
| `size_bytes` | 66 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __get_errno_from_oserr |

## Decompiled C

```c

/* Library Function - Single Match
    __get_errno_from_oserr
   
   Library: Visual Studio 2008 Release */

int __cdecl __get_errno_from_oserr(ulong param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (param_1 == (&DAT_10037498)[uVar1 * 2]) {
      return *(int *)(uVar1 * 8 + 0x1003749c);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x2d);
  if (param_1 - 0x13 < 0x12) {
    return 0xd;
  }
  return (-(uint)(0xe < param_1 - 0xbc) & 0xe) + 8;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100112c1` | _free |
| `10015140` | __dosmaperr |
| `10012c32` | _realloc |
| `10012cbf` | _realloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100150d1` | `10037498` | `READ` | DAT_10037498 |
| `100150d1` | `100374a0` | `READ` | DAT_100374a0 |
| `100150ed` | `100374a4` | `READ` | DAT_100374a4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100150c7` | `8b ff` | `MOV EDI,EDI` |
| `100150c9` | `55` | `PUSH EBP` |
| `100150ca` | `8b ec` | `MOV EBP,ESP` |
| `100150cc` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100150cf` | `33 c9` | `XOR ECX,ECX` |
| `100150d1` | `3b 04 cd 98 74 03 10` | `CMP EAX,dword ptr [ECX*0x8 + 0x10037498]` |
| `100150d8` | `74 13` | `JZ 0x100150ed` |
| `100150da` | `41` | `INC ECX` |
| `100150db` | `83 f9 2d` | `CMP ECX,0x2d` |
| `100150de` | `72 f1` | `JC 0x100150d1` |
| `100150e0` | `8d 48 ed` | `LEA ECX,[EAX + -0x13]` |
| `100150e3` | `83 f9 11` | `CMP ECX,0x11` |
| `100150e6` | `77 0e` | `JA 0x100150f6` |
| `100150e8` | `6a 0d` | `PUSH 0xd` |
| `100150ea` | `58` | `POP EAX` |
| `100150eb` | `5d` | `POP EBP` |
| `100150ec` | `c3` | `RET` |
| `100150ed` | `8b 04 cd 9c 74 03 10` | `MOV EAX,dword ptr [ECX*0x8 + 0x1003749c]` |
| `100150f4` | `5d` | `POP EBP` |
| `100150f5` | `c3` | `RET` |
| `100150f6` | `05 44 ff ff ff` | `ADD EAX,0xffffff44` |
| `100150fb` | `6a 0e` | `PUSH 0xe` |
| `100150fd` | `59` | `POP ECX` |
| `100150fe` | `3b c8` | `CMP ECX,EAX` |
| `10015100` | `1b c0` | `SBB EAX,EAX` |
| `10015102` | `23 c1` | `AND EAX,ECX` |
| `10015104` | `83 c0 08` | `ADD EAX,0x8` |
| `10015107` | `5d` | `POP EBP` |
| `10015108` | `c3` | `RET` |
