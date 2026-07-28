# 10015fe3 `__heap_init`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10015fe3 |
| `name` | __heap_init |
| `namespace` | Global |
| `signature` | int __cdecl __heap_init(void) |
| `size_bytes` | 48 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __heap_init |

## Decompiled C

```c

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2008 Release */

int __cdecl __heap_init(void)

{
  int in_stack_00000004;
  
  DAT_10038dac = HeapCreate((uint)(in_stack_00000004 == 0),0x1000,0);
  if (DAT_10038dac == (HANDLE)0x0) {
    return 0;
  }
  DAT_1343a680 = 1;
  return 1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10015ff8` | `EXTERNAL:0000003e` | `COMPUTED_CALL` | KERNEL32.DLL::HeapCreate | `` |

## Callers

| From | Function |
| --- | --- |
| `1001467f` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10015ff8` | `1002e0b0` | `READ` | PTR_HeapCreate_1002e0b0 |
| `10015ffe` | `10038dac` | `WRITE` | DAT_10038dac |
| `1001600c` | `1343a680` | `WRITE` | DAT_1343a680 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10015fe3` | `8b ff` | `MOV EDI,EDI` |
| `10015fe5` | `55` | `PUSH EBP` |
| `10015fe6` | `8b ec` | `MOV EBP,ESP` |
| `10015fe8` | `33 c0` | `XOR EAX,EAX` |
| `10015fea` | `39 45 08` | `CMP dword ptr [EBP + 0x8],EAX` |
| `10015fed` | `6a 00` | `PUSH 0x0` |
| `10015fef` | `0f 94 c0` | `SETZ AL` |
| `10015ff2` | `68 00 10 00 00` | `PUSH 0x1000` |
| `10015ff7` | `50` | `PUSH EAX` |
| `10015ff8` | `ff 15 b0 e0 02 10` | `CALL dword ptr [0x1002e0b0]` |
| `10015ffe` | `a3 ac 8d 03 10` | `MOV [0x10038dac],EAX` |
| `10016003` | `85 c0` | `TEST EAX,EAX` |
| `10016005` | `75 02` | `JNZ 0x10016009` |
| `10016007` | `5d` | `POP EBP` |
| `10016008` | `c3` | `RET` |
| `10016009` | `33 c0` | `XOR EAX,EAX` |
| `1001600b` | `40` | `INC EAX` |
| `1001600c` | `a3 80 a6 43 13` | `MOV [0x1343a680],EAX` |
| `10016011` | `5d` | `POP EBP` |
| `10016012` | `c3` | `RET` |
