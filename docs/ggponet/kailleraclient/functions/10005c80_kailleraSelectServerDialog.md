# 10005c80 `kailleraSelectServerDialog`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005c80 |
| `name` | kailleraSelectServerDialog |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraSelectServerDialog(HWND param_1) |
| `size_bytes` | 19 |
| `stack_frame_size` | 8 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_6, _kailleraSelectServerDialog@4, kailleraSelectServerDialog |

## Decompiled C

```c

/* __stdcall kailleraSelectServerDialog,4 */

void kailleraSelectServerDialog(HWND param_1)

{
                    /* 0x5c80  6  _kailleraSelectServerDialog@4 */
  DAT_1000f09c = param_1;
  FUN_10009f30(param_1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10005c8a` | `10009f30` | `UNCONDITIONAL_CALL` | FUN_10009f30 | `10009f30` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10005c85` | `1000f09c` | `WRITE` | DAT_1000f09c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005c80` | `8b 44 24 04` | `MOV EAX,dword ptr [ESP + 0x4]` |
| `10005c84` | `50` | `PUSH EAX` |
| `10005c85` | `a3 9c f0 00 10` | `MOV [0x1000f09c],EAX` |
| `10005c8a` | `e8 a1 42 00 00` | `CALL 0x10009f30` |
| `10005c8f` | `59` | `POP ECX` |
| `10005c90` | `c2 04 00` | `RET 0x4` |
