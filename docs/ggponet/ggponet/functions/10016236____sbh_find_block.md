# 10016236 `___sbh_find_block`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10016236 |
| `name` | ___sbh_find_block |
| `namespace` | Global |
| `signature` | undefined ___sbh_find_block(void) |
| `size_bytes` | 48 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___sbh_find_block |

## Decompiled C

```c

/* Library Function - Single Match
    ___sbh_find_block
   
   Library: Visual Studio 2008 Release */

uint ___sbh_find_block(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_1343a66c;
  while( true ) {
    if (DAT_1343a668 * 0x14 + DAT_1343a66c <= uVar1) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(uVar1 + 0xc)) < 0x100000) break;
    uVar1 = uVar1 + 0x14;
  }
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001126a` | _free |
| `10012b0b` | _realloc |
| `10012b5b` | _realloc |
| `1001cb20` | __msize |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001623b` | `1343a668` | `READ` | DAT_1343a668 |
| `10016241` | `1343a66c` | `READ` | DAT_1343a66c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10016236` | `8b ff` | `MOV EDI,EDI` |
| `10016238` | `55` | `PUSH EBP` |
| `10016239` | `8b ec` | `MOV EBP,ESP` |
| `1001623b` | `8b 0d 68 a6 43 13` | `MOV ECX,dword ptr [0x1343a668]` |
| `10016241` | `a1 6c a6 43 13` | `MOV EAX,[0x1343a66c]` |
| `10016246` | `6b c9 14` | `IMUL ECX,ECX,0x14` |
| `10016249` | `03 c8` | `ADD ECX,EAX` |
| `1001624b` | `eb 11` | `JMP 0x1001625e` |
| `1001624d` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10016250` | `2b 50 0c` | `SUB EDX,dword ptr [EAX + 0xc]` |
| `10016253` | `81 fa 00 00 10 00` | `CMP EDX,0x100000` |
| `10016259` | `72 09` | `JC 0x10016264` |
| `1001625b` | `83 c0 14` | `ADD EAX,0x14` |
| `1001625e` | `3b c1` | `CMP EAX,ECX` |
| `10016260` | `72 eb` | `JC 0x1001624d` |
| `10016262` | `33 c0` | `XOR EAX,EAX` |
| `10016264` | `5d` | `POP EBP` |
| `10016265` | `c3` | `RET` |
