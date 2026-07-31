# 1001f336 `__alloca_probe_8`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f336 |
| `name` | __alloca_probe_8 |
| `namespace` | Global |
| `signature` | undefined __alloca_probe_8(void) |
| `size_bytes` | 22 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __alloca_probe_8 |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_8
   
   Library: Visual Studio */

uint __alloca_probe_8(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 7;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f347` | `1001e850` | `UNCONDITIONAL_CALL` | __alloca_probe | `1001e850` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f336` | `51` | `PUSH ECX` |
| `1001f337` | `8d 4c 24 08` | `LEA ECX,[ESP + 0x8]` |
| `1001f33b` | `2b c8` | `SUB ECX,EAX` |
| `1001f33d` | `83 e1 07` | `AND ECX,0x7` |
| `1001f340` | `03 c1` | `ADD EAX,ECX` |
| `1001f342` | `1b c9` | `SBB ECX,ECX` |
| `1001f344` | `0b c1` | `OR EAX,ECX` |
| `1001f346` | `59` | `POP ECX` |
| `1001f347` | `e9 04 f5 ff ff` | `JMP 0x1001e850` |
