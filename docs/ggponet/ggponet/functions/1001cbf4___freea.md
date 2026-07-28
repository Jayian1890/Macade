# 1001cbf4 `__freea`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cbf4 |
| `name` | __freea |
| `namespace` | Global |
| `signature` | void __cdecl __freea(void * _Memory) |
| `size_bytes` | 32 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __freea |

## Decompiled C

```c

/* Library Function - Single Match
    __freea
   
   Library: Visual Studio 2008 Release */

void __cdecl __freea(void *_Memory)

{
  if ((_Memory != (void *)0x0) && (*(int *)((int)_Memory + -8) == 0xdddd)) {
    _free((int *)((int)_Memory + -8));
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cc0c` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `1001e147` | __crtCompareStringA_stat |
| `1001e150` | __crtCompareStringA_stat |
| `1001ee85` | __crtGetStringTypeA_stat |
| `1001f99e` | ___convertcp |
| `1001eb96` | __crtLCMapStringA_stat |
| `1001eb9f` | __crtLCMapStringA_stat |
| `1001ecc1` | __crtLCMapStringA_stat |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cbf4` | `8b ff` | `MOV EDI,EDI` |
| `1001cbf6` | `55` | `PUSH EBP` |
| `1001cbf7` | `8b ec` | `MOV EBP,ESP` |
| `1001cbf9` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001cbfc` | `85 c0` | `TEST EAX,EAX` |
| `1001cbfe` | `74 12` | `JZ 0x1001cc12` |
| `1001cc00` | `83 e8 08` | `SUB EAX,0x8` |
| `1001cc03` | `81 38 dd dd 00 00` | `CMP dword ptr [EAX],0xdddd` |
| `1001cc09` | `75 07` | `JNZ 0x1001cc12` |
| `1001cc0b` | `50` | `PUSH EAX` |
| `1001cc0c` | `e8 30 46 ff ff` | `CALL 0x10011241` |
| `1001cc11` | `59` | `POP ECX` |
| `1001cc12` | `5d` | `POP EBP` |
| `1001cc13` | `c3` | `RET` |
