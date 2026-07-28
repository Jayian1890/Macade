# 1001d978 `__global_unwind2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d978 |
| `name` | __global_unwind2 |
| `namespace` | Global |
| `signature` | undefined __global_unwind2(void) |
| `size_bytes` | 32 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __global_unwind2 |

## Decompiled C

```c

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void __global_unwind2(PVOID param_1)

{
  RtlUnwind(param_1,(PVOID)0x1001d990,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d98b` | `1001fcd2` | `UNCONDITIONAL_CALL` | KERNEL32.DLL::RtlUnwind | `1001fcd2` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d978` | `55` | `PUSH EBP` |
| `1001d979` | `8b ec` | `MOV EBP,ESP` |
| `1001d97b` | `53` | `PUSH EBX` |
| `1001d97c` | `56` | `PUSH ESI` |
| `1001d97d` | `57` | `PUSH EDI` |
| `1001d97e` | `55` | `PUSH EBP` |
| `1001d97f` | `6a 00` | `PUSH 0x0` |
| `1001d981` | `6a 00` | `PUSH 0x0` |
| `1001d983` | `68 90 d9 01 10` | `PUSH 0x1001d990` |
| `1001d988` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d98b` | `e8 42 23 00 00` | `CALL 0x1001fcd2` |
| `1001d990` | `5d` | `POP EBP` |
| `1001d991` | `5f` | `POP EDI` |
| `1001d992` | `5e` | `POP ESI` |
| `1001d993` | `5b` | `POP EBX` |
| `1001d994` | `8b e5` | `MOV ESP,EBP` |
| `1001d996` | `5d` | `POP EBP` |
| `1001d997` | `c3` | `RET` |
