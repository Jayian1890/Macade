# 1001e949 `__ismbblead`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e949 |
| `name` | __ismbblead |
| `namespace` | Global |
| `signature` | int __cdecl __ismbblead(uint _C) |
| `size_bytes` | 24 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __ismbblead |

## Decompiled C

```c

/* Library Function - Single Match
    __ismbblead
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl __ismbblead(uint _C)

{
  int iVar1;
  
  iVar1 = x_ismbbtype_l((localeinfo_struct *)0x0,_C,0,4);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e957` | `1001e8f6` | `UNCONDITIONAL_CALL` | x_ismbbtype_l | `1001e8f6` |

## Callers

| From | Function |
| --- | --- |
| `1001a733` | parse_cmdline |
| `1001a818` | parse_cmdline |
| `1001a83b` | parse_cmdline |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e949` | `8b ff` | `MOV EDI,EDI` |
| `1001e94b` | `55` | `PUSH EBP` |
| `1001e94c` | `8b ec` | `MOV EBP,ESP` |
| `1001e94e` | `6a 04` | `PUSH 0x4` |
| `1001e950` | `6a 00` | `PUSH 0x0` |
| `1001e952` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e955` | `6a 00` | `PUSH 0x0` |
| `1001e957` | `e8 9a ff ff ff` | `CALL 0x1001e8f6` |
| `1001e95c` | `83 c4 10` | `ADD ESP,0x10` |
| `1001e95f` | `5d` | `POP EBP` |
| `1001e960` | `c3` | `RET` |
