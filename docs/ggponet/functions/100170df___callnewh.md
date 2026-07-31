# 100170df `__callnewh`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100170df |
| `name` | __callnewh |
| `namespace` | Global |
| `signature` | int __cdecl __callnewh(size_t _Size) |
| `size_bytes` | 40 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __callnewh |

## Decompiled C

```c

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2008 Release */

int __cdecl __callnewh(size_t _Size)

{
  code *pcVar1;
  int iVar2;
  
  pcVar1 = (code *)__decode_pointer(DAT_1003921c);
  if (pcVar1 != (code *)0x0) {
    iVar2 = (*pcVar1)(_Size);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100170ea` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |

## Callers

| From | Function |
| --- | --- |
| `100113ab` | _malloc |
| `100113d2` | _malloc |
| `1001abd3` | __calloc_impl |
| `10012c11` | _realloc |
| `10012c8a` | _realloc |
| `10012c7a` | _realloc |
| `100118f9` | FUN_100118ec |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100170e4` | `1003921c` | `READ` | DAT_1003921c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100170df` | `8b ff` | `MOV EDI,EDI` |
| `100170e1` | `55` | `PUSH EBP` |
| `100170e2` | `8b ec` | `MOV EBP,ESP` |
| `100170e4` | `ff 35 1c 92 03 10` | `PUSH dword ptr [0x1003921c]` |
| `100170ea` | `e8 9b 00 00 00` | `CALL 0x1001718a` |
| `100170ef` | `59` | `POP ECX` |
| `100170f0` | `85 c0` | `TEST EAX,EAX` |
| `100170f2` | `74 0f` | `JZ 0x10017103` |
| `100170f4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `100170f7` | `ff d0` | `CALL EAX` |
| `100170f9` | `59` | `POP ECX` |
| `100170fa` | `85 c0` | `TEST EAX,EAX` |
| `100170fc` | `74 05` | `JZ 0x10017103` |
| `100170fe` | `33 c0` | `XOR EAX,EAX` |
| `10017100` | `40` | `INC EAX` |
| `10017101` | `5d` | `POP EBP` |
| `10017102` | `c3` | `RET` |
| `10017103` | `33 c0` | `XOR EAX,EAX` |
| `10017105` | `5d` | `POP EBP` |
| `10017106` | `c3` | `RET` |
