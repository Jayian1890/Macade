# 1001c23c `___initmbctable`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c23c |
| `name` | ___initmbctable |
| `namespace` | Global |
| `signature` | undefined ___initmbctable(void) |
| `size_bytes` | 30 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___initmbctable |

## Decompiled C

```c

/* Library Function - Single Match
    ___initmbctable
   
   Library: Visual Studio 2008 Release */

undefined4 ___initmbctable(void)

{
  if (DAT_1343a698 == 0) {
    __setmbcp(-3);
    DAT_1343a698 = 1;
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c247` | `1001c0a2` | `UNCONDITIONAL_CALL` | __setmbcp | `1001c0a2` |

## Callers

| From | Function |
| --- | --- |
| `1001a609` | __setenvp |
| `1001a88d` | __setargv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c23c` | `1343a698` | `READ` | DAT_1343a698 |
| `1001c24d` | `1343a698` | `WRITE` | DAT_1343a698 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c23c` | `83 3d 98 a6 43 13 00` | `CMP dword ptr [0x1343a698],0x0` |
| `1001c243` | `75 12` | `JNZ 0x1001c257` |
| `1001c245` | `6a fd` | `PUSH -0x3` |
| `1001c247` | `e8 56 fe ff ff` | `CALL 0x1001c0a2` |
| `1001c24c` | `59` | `POP ECX` |
| `1001c24d` | `c7 05 98 a6 43 13 01 00 00 00` | `MOV dword ptr [0x1343a698],0x1` |
| `1001c257` | `33 c0` | `XOR EAX,EAX` |
| `1001c259` | `c3` | `RET` |
