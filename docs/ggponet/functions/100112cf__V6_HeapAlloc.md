# 100112cf `_V6_HeapAlloc`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100112cf |
| `name` | _V6_HeapAlloc |
| `namespace` | Global |
| `signature` | undefined _V6_HeapAlloc(void) |
| `size_bytes` | 70 |
| `stack_frame_size` | 36 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | _V6_HeapAlloc |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _V6_HeapAlloc
   
   Library: Visual Studio 2008 Release */

undefined4 _V6_HeapAlloc(uint param_1)

{
  undefined4 local_20;
  
  local_20 = 0;
  if (param_1 <= DAT_1343a670) {
    __lock(4);
    local_20 = ___sbh_alloc_block(param_1);
    FUN_10011315();
  }
  return local_20;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100112d6` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `100112ec` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `100112f7` | `10016a15` | `UNCONDITIONAL_CALL` | ___sbh_alloc_block | `10016a15` |
| `10011307` | `10011315` | `UNCONDITIONAL_CALL` | FUN_10011315 | `10011315` |
| `1001130f` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `10011377` | _malloc |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100112d1` | `10033c58` | `DATA` | DAT_10033c58 |
| `100112e2` | `1343a670` | `READ` | DAT_1343a670 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100112cf` | `6a 0c` | `PUSH 0xc` |
| `100112d1` | `68 58 3c 03 10` | `PUSH 0x10033c58` |
| `100112d6` | `e8 21 5a 00 00` | `CALL 0x10016cfc` |
| `100112db` | `83 65 e4 00` | `AND dword ptr [EBP + -0x1c],0x0` |
| `100112df` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `100112e2` | `3b 35 70 a6 43 13` | `CMP ESI,dword ptr [0x1343a670]` |
| `100112e8` | `77 22` | `JA 0x1001130c` |
| `100112ea` | `6a 04` | `PUSH 0x4` |
| `100112ec` | `e8 12 4f 00 00` | `CALL 0x10016203` |
| `100112f1` | `59` | `POP ECX` |
| `100112f2` | `83 65 fc 00` | `AND dword ptr [EBP + -0x4],0x0` |
| `100112f6` | `56` | `PUSH ESI` |
| `100112f7` | `e8 19 57 00 00` | `CALL 0x10016a15` |
| `100112fc` | `59` | `POP ECX` |
| `100112fd` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `10011300` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `10011307` | `e8 09 00 00 00` | `CALL 0x10011315` |
| `1001130c` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001130f` | `e8 2d 5a 00 00` | `CALL 0x10016d41` |
| `10011314` | `c3` | `RET` |
