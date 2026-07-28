# 1001f320 `__alloca_probe_16`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f320 |
| `name` | __alloca_probe_16 |
| `namespace` | Global |
| `signature` | undefined __alloca_probe_16(void) |
| `size_bytes` | 22 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __alloca_probe_16 |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* Library Function - Single Match
    __alloca_probe_16
   
   Library: Visual Studio 2008 Release */

uint __alloca_probe_16(void)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = 4 - in_EAX & 0xf;
  return in_EAX + uVar1 | -(uint)CARRY4(in_EAX,uVar1);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f331` | `1001e850` | `UNCONDITIONAL_CALL` | __alloca_probe | `1001e850` |

## Callers

| From | Function |
| --- | --- |
| `1001e068` | __crtCompareStringA_stat |
| `1001e0e8` | __crtCompareStringA_stat |
| `1001ee24` | __crtGetStringTypeA_stat |
| `1001f8a7` | ___convertcp |
| `1001ea68` | __crtLCMapStringA_stat |
| `1001eb27` | __crtLCMapStringA_stat |
| `1001ec3d` | __crtLCMapStringA_stat |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f320` | `51` | `PUSH ECX` |
| `1001f321` | `8d 4c 24 08` | `LEA ECX,[ESP + 0x8]` |
| `1001f325` | `2b c8` | `SUB ECX,EAX` |
| `1001f327` | `83 e1 0f` | `AND ECX,0xf` |
| `1001f32a` | `03 c1` | `ADD EAX,ECX` |
| `1001f32c` | `1b c9` | `SBB ECX,ECX` |
| `1001f32e` | `0b c1` | `OR EAX,ECX` |
| `1001f330` | `59` | `POP ECX` |
| `1001f331` | `e9 1a f5 ff ff` | `JMP 0x1001e850` |
