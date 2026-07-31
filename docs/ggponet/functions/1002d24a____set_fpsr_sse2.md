# 1002d24a `___set_fpsr_sse2`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002d24a |
| `name` | ___set_fpsr_sse2 |
| `namespace` | Global |
| `signature` | undefined ___set_fpsr_sse2(void) |
| `size_bytes` | 68 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___set_fpsr_sse2 |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___set_fpsr_sse2
   
   Library: Visual Studio 2008 Release */

void ___set_fpsr_sse2(uint param_1)

{
  if (DAT_1343a684 != 0) {
    if (((param_1 & 0x40) == 0) || (DAT_10038a14 == 0)) {
      MXCSR = param_1 & 0xffffffbf;
    }
    else {
      MXCSR = param_1;
    }
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002d251` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1002d2b6` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1002cfbb` | __control87 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002d24c` | `10034dd8` | `DATA` | DAT_10034dd8 |
| `1002d258` | `1343a684` | `READ` | DAT_1343a684 |
| `1002d266` | `10038a14` | `READ` | DAT_10038a14 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002d24a` | `6a 08` | `PUSH 0x8` |
| `1002d24c` | `68 d8 4d 03 10` | `PUSH 0x10034dd8` |
| `1002d251` | `e8 a6 9a fe ff` | `CALL 0x10016cfc` |
| `1002d256` | `33 c0` | `XOR EAX,EAX` |
| `1002d258` | `39 05 84 a6 43 13` | `CMP dword ptr [0x1343a684],EAX` |
| `1002d25e` | `74 56` | `JZ 0x1002d2b6` |
| `1002d260` | `f6 45 08 40` | `TEST byte ptr [EBP + 0x8],0x40` |
| `1002d264` | `74 48` | `JZ 0x1002d2ae` |
| `1002d266` | `39 05 14 8a 03 10` | `CMP dword ptr [0x10038a14],EAX` |
| `1002d26c` | `74 40` | `JZ 0x1002d2ae` |
| `1002d26e` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002d271` | `0f ae 55 08` | `LDMXCSR dword ptr [EBP + 0x8]` |
| `1002d275` | `eb 2e` | `JMP 0x1002d2a5` |
| `1002d2a5` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1002d2ac` | `eb 08` | `JMP 0x1002d2b6` |
| `1002d2ae` | `83 65 08 bf` | `AND dword ptr [EBP + 0x8],0xffffffbf` |
| `1002d2b2` | `0f ae 55 08` | `LDMXCSR dword ptr [EBP + 0x8]` |
| `1002d2b6` | `e8 86 9a fe ff` | `CALL 0x10016d41` |
| `1002d2bb` | `c3` | `RET` |
