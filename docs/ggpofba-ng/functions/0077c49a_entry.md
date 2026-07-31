# 0077c49a `entry`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 0077c49a |
| `name` | entry |
| `namespace` | Global |
| `signature` | undefined entry(void) |
| `size_bytes` | 10 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | entry |

## Decompiled C

```c

void entry(void)

{
  ___security_init_cookie();
  ___tmainCRTStartup();
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `0077c49a` | `0078a061` | `UNCONDITIONAL_CALL` | ___security_init_cookie | `0078a061` |
| `0077c49f` | `0077c31c` | `UNCONDITIONAL_CALL` | ___tmainCRTStartup | `0077c31c` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `0077c49a` | `e8 c2 db 00 00` | `CALL 0x0078a061` |
| `0077c49f` | `e9 78 fe ff ff` | `JMP 0x0077c31c` |
