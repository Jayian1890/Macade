# 1001e850 `__alloca_probe`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e850 |
| `name` | __alloca_probe |
| `namespace` | Global |
| `signature` | undefined __alloca_probe(void) |
| `size_bytes` | 43 |
| `stack_frame_size` | 8196 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __alloca_probe, __chkstk |

## Decompiled C

```c

/* WARNING: This is an inlined function */
/* Library Function - Single Match
    __chkstk
   
   Library: Visual Studio 2008 Release */

void __alloca_probe(void)

{
  undefined1 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 unaff_retaddr;
  undefined1 auStack_4 [4];
  
  puVar2 = (undefined4 *)((int)&stack0x00000000 - (int)in_EAX & ~-(uint)(&stack0x00000000 < in_EAX))
  ;
  for (puVar1 = (undefined4 *)((uint)auStack_4 & 0xfffff000); puVar2 < puVar1;
      puVar1 = puVar1 + -0x400) {
  }
  *puVar2 = unaff_retaddr;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10019be9` | __write_nolock |
| `1001f331` | __alloca_probe_16 |
| `10021878` | FUN_10021870 |
| `100233f8` | FUN_100233f0 |
| `10029168` | FUN_10029160 |
| `1001f347` | __alloca_probe_8 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e850` | `51` | `PUSH ECX` |
| `1001e851` | `8d 4c 24 04` | `LEA ECX,[ESP + 0x4]` |
| `1001e855` | `2b c8` | `SUB ECX,EAX` |
| `1001e857` | `1b c0` | `SBB EAX,EAX` |
| `1001e859` | `f7 d0` | `NOT EAX` |
| `1001e85b` | `23 c8` | `AND ECX,EAX` |
| `1001e85d` | `8b c4` | `MOV EAX,ESP` |
| `1001e85f` | `25 00 f0 ff ff` | `AND EAX,0xfffff000` |
| `1001e864` | `3b c8` | `CMP ECX,EAX` |
| `1001e866` | `72 0a` | `JC 0x1001e872` |
| `1001e868` | `8b c1` | `MOV EAX,ECX` |
| `1001e86a` | `59` | `POP ECX` |
| `1001e86b` | `94` | `XCHG EAX,ESP` |
| `1001e86c` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001e86e` | `89 04 24` | `MOV dword ptr [ESP],EAX` |
| `1001e871` | `c3` | `RET` |
| `1001e872` | `2d 00 10 00 00` | `SUB EAX,0x1000` |
| `1001e877` | `85 00` | `TEST dword ptr [EAX],EAX` |
| `1001e879` | `eb e9` | `JMP 0x1001e864` |
