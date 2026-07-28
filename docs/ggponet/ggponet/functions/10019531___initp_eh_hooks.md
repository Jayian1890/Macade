# 10019531 `__initp_eh_hooks`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019531 |
| `name` | __initp_eh_hooks |
| `namespace` | Global |
| `signature` | undefined __initp_eh_hooks(void) |
| `size_bytes` | 17 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __initp_eh_hooks |

## Decompiled C

```c

/* Library Function - Single Match
    __initp_eh_hooks
   
   Library: Visual Studio 2008 Release */

void __initp_eh_hooks(void)

{
  DAT_10039254 = __encode_pointer(terminate);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019536` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |

## Callers

| From | Function |
| --- | --- |
| `1001271c` | __init_pointers |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10019531` | `100194ad` | `DATA` | ?terminate@@YAXXZ, terminate |
| `1001953c` | `10039254` | `WRITE` | DAT_10039254 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019531` | `68 ad 94 01 10` | `PUSH 0x100194ad` |
| `10019536` | `e8 d4 db ff ff` | `CALL 0x1001710f` |
| `1001953b` | `59` | `POP ECX` |
| `1001953c` | `a3 54 92 03 10` | `MOV [0x10039254],EAX` |
| `10019541` | `c3` | `RET` |
