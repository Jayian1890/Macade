# 1001bb77 `CPtoLCID`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001bb77 |
| `name` | CPtoLCID |
| `namespace` | Global |
| `signature` | int __cdecl CPtoLCID(int param_1) |
| `size_bytes` | 47 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?CPtoLCID@@YAHH@Z, CPtoLCID |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl CPtoLCID(int)
   
   Library: Visual Studio 2008 Release */

int __cdecl CPtoLCID(int param_1)

{
  int in_EAX;
  
  if (in_EAX == 0x3a4) {
    return 0x411;
  }
  if (in_EAX == 0x3a8) {
    return 0x804;
  }
  if (in_EAX == 0x3b5) {
    return 0x412;
  }
  if (in_EAX != 0x3b6) {
    return 0;
  }
  return 0x404;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001c00b` | __setmbcp_nolock |
| `1001c060` | __setmbcp_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001bb77` | `2d a4 03 00 00` | `SUB EAX,0x3a4` |
| `1001bb7c` | `74 22` | `JZ 0x1001bba0` |
| `1001bb7e` | `83 e8 04` | `SUB EAX,0x4` |
| `1001bb81` | `74 17` | `JZ 0x1001bb9a` |
| `1001bb83` | `83 e8 0d` | `SUB EAX,0xd` |
| `1001bb86` | `74 0c` | `JZ 0x1001bb94` |
| `1001bb88` | `48` | `DEC EAX` |
| `1001bb89` | `74 03` | `JZ 0x1001bb8e` |
| `1001bb8b` | `33 c0` | `XOR EAX,EAX` |
| `1001bb8d` | `c3` | `RET` |
| `1001bb8e` | `b8 04 04 00 00` | `MOV EAX,0x404` |
| `1001bb93` | `c3` | `RET` |
| `1001bb94` | `b8 12 04 00 00` | `MOV EAX,0x412` |
| `1001bb99` | `c3` | `RET` |
| `1001bb9a` | `b8 04 08 00 00` | `MOV EAX,0x804` |
| `1001bb9f` | `c3` | `RET` |
| `1001bba0` | `b8 11 04 00 00` | `MOV EAX,0x411` |
| `1001bba5` | `c3` | `RET` |
