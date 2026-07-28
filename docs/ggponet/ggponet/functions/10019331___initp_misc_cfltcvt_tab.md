# 10019331 `__initp_misc_cfltcvt_tab`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019331 |
| `name` | __initp_misc_cfltcvt_tab |
| `namespace` | Global |
| `signature` | undefined __initp_misc_cfltcvt_tab(void) |
| `size_bytes` | 33 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __initp_misc_cfltcvt_tab |

## Decompiled C

```c

/* Library Function - Single Match
    __initp_misc_cfltcvt_tab
   
   Library: Visual Studio 2008 Release */

void __initp_misc_cfltcvt_tab(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    puVar1 = (undefined4 *)((int)&PTR_LAB_10037bc0 + uVar3);
    uVar2 = __encode_pointer(*puVar1);
    uVar3 = uVar3 + 4;
    *puVar1 = uVar2;
  } while (uVar3 < 0x28);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001933f` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |

## Callers

| From | Function |
| --- | --- |
| `10012522` | __cinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10019337` | `10037bc0` | `DATA` | PTR_LAB_10037bc0 |
| `1001933d` | `10037bc0` | `READ` | PTR_LAB_10037bc0 |
| `1001933d` | `1001de8e` | `DATA` | LAB_1001de8e |
| `1001933d` | `10037bc4` | `READ` | PTR_LAB_10037bc4 |
| `10019348` | `10037bc0` | `WRITE` | PTR_LAB_10037bc0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019331` | `8b ff` | `MOV EDI,EDI` |
| `10019333` | `56` | `PUSH ESI` |
| `10019334` | `57` | `PUSH EDI` |
| `10019335` | `33 ff` | `XOR EDI,EDI` |
| `10019337` | `8d b7 c0 7b 03 10` | `LEA ESI,[EDI + 0x10037bc0]` |
| `1001933d` | `ff 36` | `PUSH dword ptr [ESI]` |
| `1001933f` | `e8 cb dd ff ff` | `CALL 0x1001710f` |
| `10019344` | `83 c7 04` | `ADD EDI,0x4` |
| `10019347` | `59` | `POP ECX` |
| `10019348` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `1001934a` | `83 ff 28` | `CMP EDI,0x28` |
| `1001934d` | `72 e8` | `JC 0x10019337` |
| `1001934f` | `5f` | `POP EDI` |
| `10019350` | `5e` | `POP ESI` |
| `10019351` | `c3` | `RET` |
