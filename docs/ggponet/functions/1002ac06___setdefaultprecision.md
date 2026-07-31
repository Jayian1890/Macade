# 1002ac06 `__setdefaultprecision`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ac06 |
| `name` | __setdefaultprecision |
| `namespace` | Global |
| `signature` | undefined __setdefaultprecision(void) |
| `size_bytes` | 40 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __setdefaultprecision |

## Decompiled C

```c

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 2008 Release */

void __setdefaultprecision(void)

{
  errno_t eVar1;
  
  eVar1 = __controlfp_s((uint *)0x0,0x10000,0x30000);
  if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ac16` | `1002b12f` | `UNCONDITIONAL_CALL` | __controlfp_s | `1002b12f` |
| `1002ac27` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |

## Callers

| From | Function |
| --- | --- |
| `1002a069` | __fpmath |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ac06` | `8b ff` | `MOV EDI,EDI` |
| `1002ac08` | `56` | `PUSH ESI` |
| `1002ac09` | `68 00 00 03 00` | `PUSH 0x30000` |
| `1002ac0e` | `68 00 00 01 00` | `PUSH 0x10000` |
| `1002ac13` | `33 f6` | `XOR ESI,ESI` |
| `1002ac15` | `56` | `PUSH ESI` |
| `1002ac16` | `e8 14 05 00 00` | `CALL 0x1002b12f` |
| `1002ac1b` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002ac1e` | `85 c0` | `TEST EAX,EAX` |
| `1002ac20` | `74 0d` | `JZ 0x1002ac2f` |
| `1002ac22` | `56` | `PUSH ESI` |
| `1002ac23` | `56` | `PUSH ESI` |
| `1002ac24` | `56` | `PUSH ESI` |
| `1002ac25` | `56` | `PUSH ESI` |
| `1002ac26` | `56` | `PUSH ESI` |
| `1002ac27` | `e8 5b 69 fe ff` | `CALL 0x10011587` |
| `1002ac2f` | `5e` | `POP ESI` |
| `1002ac30` | `c3` | `RET` |
