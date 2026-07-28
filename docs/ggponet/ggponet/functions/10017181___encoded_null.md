# 10017181 `__encoded_null`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017181 |
| `name` | __encoded_null |
| `namespace` | Global |
| `signature` | undefined __encoded_null(void) |
| `size_bytes` | 9 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __encoded_null |

## Decompiled C

```c

/* Library Function - Single Match
    __encoded_null
   
   Library: Visual Studio 2008 Release */

void __encoded_null(void)

{
  __encode_pointer(0);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017183` | `1001710f` | `UNCONDITIONAL_CALL` | __encode_pointer | `1001710f` |

## Callers

| From | Function |
| --- | --- |
| `1001c800` | ___crtMessageBoxA |
| `100125f5` | doexit |
| `1001260b` | doexit |
| `100126ea` | __init_pointers |
| `10019871` | _raise |
| `1001b3ca` | FindHandlerForForeignException |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017181` | `6a 00` | `PUSH 0x0` |
| `10017183` | `e8 87 ff ff ff` | `CALL 0x1001710f` |
| `10017188` | `59` | `POP ECX` |
| `10017189` | `c3` | `RET` |
