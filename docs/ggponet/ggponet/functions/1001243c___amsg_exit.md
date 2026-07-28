# 1001243c `__amsg_exit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001243c |
| `name` | __amsg_exit |
| `namespace` | Global |
| `signature` | void __cdecl __amsg_exit(int param_1) |
| `size_bytes` | 41 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __amsg_exit |

## Decompiled C

```c

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2008 Release */

void __cdecl __amsg_exit(int param_1)

{
  code *pcVar1;
  
  __FF_MSGBANNER();
  __NMSG_WRITE(param_1);
  pcVar1 = (code *)__decode_pointer(PTR___exit_10037480);
  (*pcVar1)(0xff);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10012441` | `10017097` | `UNCONDITIONAL_CALL` | __FF_MSGBANNER | `10017097` |
| `10012449` | `10016eec` | `UNCONDITIONAL_CALL` | __NMSG_WRITE | `10016eec` |
| `10012454` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |

## Callers

| From | Function |
| --- | --- |
| `10016225` | __lock |
| `100173e6` | __getptd |
| `1001bdc9` | ___updatetmbcinfo |
| `1001c53a` | ___updatetlocinfo |
| `1001e3e8` | copy_environ |
| `1001de90` |  |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001244e` | `10037480` | `READ` | PTR___exit_10037480 |
| `1001244e` | `100126c2` | `DATA` | __exit |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001243c` | `8b ff` | `MOV EDI,EDI` |
| `1001243e` | `55` | `PUSH EBP` |
| `1001243f` | `8b ec` | `MOV EBP,ESP` |
| `10012441` | `e8 51 4c 00 00` | `CALL 0x10017097` |
| `10012446` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10012449` | `e8 9e 4a 00 00` | `CALL 0x10016eec` |
| `1001244e` | `ff 35 80 74 03 10` | `PUSH dword ptr [0x10037480]` |
| `10012454` | `e8 31 4d 00 00` | `CALL 0x1001718a` |
| `10012459` | `68 ff 00 00 00` | `PUSH 0xff` |
| `1001245e` | `ff d0` | `CALL EAX` |
| `10012460` | `83 c4 0c` | `ADD ESP,0xc` |
| `10012463` | `5d` | `POP EBP` |
| `10012464` | `c3` | `RET` |
