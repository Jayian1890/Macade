# 100126e7 `__init_pointers`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100126e7 |
| `name` | __init_pointers |
| `namespace` | Global |
| `signature` | void __cdecl __init_pointers(void) |
| `size_bytes` | 78 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __init_pointers |

## Decompiled C

```c

/* Library Function - Single Match
    __init_pointers
   
   Library: Visual Studio 2008 Release */

void __cdecl __init_pointers(void)

{
  undefined4 uVar1;
  
  uVar1 = __encoded_null();
  FUN_100170d0(uVar1);
  FUN_100198e4(uVar1);
  FUN_10011578(uVar1);
  FUN_10017ae6(uVar1);
  FUN_100198d5(uVar1);
  __initp_misc_winsig(uVar1);
  FUN_10019542(uVar1);
  __initp_eh_hooks(uVar1);
  PTR___exit_10037480 = (undefined *)__encode_pointer(__exit);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100126ea` | `10017181` | `UNCONDITIONAL_CALL` | __encoded_null | `10017181` |
| `100126f2` | `100170d0` | `UNCONDITIONAL_CALL` | FUN_100170d0 | `100170d0` |
| `100126f8` | `100198e4` | `UNCONDITIONAL_CALL` | FUN_100198e4 | `100198e4` |
| `100126fe` | `10011578` | `UNCONDITIONAL_CALL` | FUN_10011578 | `10011578` |
| `10012704` | `10017ae6` | `UNCONDITIONAL_CALL` | FUN_10017ae6 | `10017ae6` |
| `1001270a` | `100198d5` | `UNCONDITIONAL_CALL` | FUN_100198d5 | `100198d5` |
| `10012710` | `100196c3` | `UNCONDITIONAL_CALL` | __initp_misc_winsig | `100196c3` |
| `10012716` | `10019542` | `UNCONDITIONAL_CALL` | FUN_10019542 | `10019542` |
| `1001271c` | `10019531` | `UNCONDITIONAL_CALL` | __initp_eh_hooks | `10019531` |
| `10012726` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |

## Callers

| From | Function |
| --- | --- |
| `1001765a` | __mtinit |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10012721` | `100126c2` | `DATA` | __exit |
| `1001272e` | `10037480` | `WRITE` | PTR___exit_10037480 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100126e7` | `8b ff` | `MOV EDI,EDI` |
| `100126e9` | `56` | `PUSH ESI` |
| `100126ea` | `e8 92 4a 00 00` | `CALL 0x10017181` |
| `100126ef` | `8b f0` | `MOV ESI,EAX` |
| `100126f1` | `56` | `PUSH ESI` |
| `100126f2` | `e8 d9 49 00 00` | `CALL 0x100170d0` |
| `100126f7` | `56` | `PUSH ESI` |
| `100126f8` | `e8 e7 71 00 00` | `CALL 0x100198e4` |
| `100126fd` | `56` | `PUSH ESI` |
| `100126fe` | `e8 75 ee ff ff` | `CALL 0x10011578` |
| `10012703` | `56` | `PUSH ESI` |
| `10012704` | `e8 dd 53 00 00` | `CALL 0x10017ae6` |
| `10012709` | `56` | `PUSH ESI` |
| `1001270a` | `e8 c6 71 00 00` | `CALL 0x100198d5` |
| `1001270f` | `56` | `PUSH ESI` |
| `10012710` | `e8 ae 6f 00 00` | `CALL 0x100196c3` |
| `10012715` | `56` | `PUSH ESI` |
| `10012716` | `e8 27 6e 00 00` | `CALL 0x10019542` |
| `1001271b` | `56` | `PUSH ESI` |
| `1001271c` | `e8 10 6e 00 00` | `CALL 0x10019531` |
| `10012721` | `68 c2 26 01 10` | `PUSH 0x100126c2` |
| `10012726` | `e8 e4 49 00 00` | `CALL 0x1001710f` |
| `1001272b` | `83 c4 24` | `ADD ESP,0x24` |
| `1001272e` | `a3 80 74 03 10` | `MOV [0x10037480],EAX` |
| `10012733` | `5e` | `POP ESI` |
| `10012734` | `c3` | `RET` |
