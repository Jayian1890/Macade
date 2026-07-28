# 10005ca0 `kailleraModifyPlayValues`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10005ca0 |
| `name` | kailleraModifyPlayValues |
| `namespace` | Global |
| `signature` | undefined __stdcall kailleraModifyPlayValues(char * param_1, uint param_2) |
| `size_bytes` | 21 |
| `stack_frame_size` | 12 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | Ordinal_5, _kailleraModifyPlayValues@8, kailleraModifyPlayValues |

## Decompiled C

```c

/* __stdcall kailleraModifyPlayValues,8 */

void kailleraModifyPlayValues(char *param_1,uint param_2)

{
                    /* 0x5ca0  5  _kailleraModifyPlayValues@8 */
  FUN_10008f30(param_1,param_2);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10005caa` | `10008f30` | `UNCONDITIONAL_CALL` | FUN_10008f30 | `10008f30` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10005ca0` | `8b 44 24 08` | `MOV EAX,dword ptr [ESP + 0x8]` |
| `10005ca4` | `8b 4c 24 04` | `MOV ECX,dword ptr [ESP + 0x4]` |
| `10005ca8` | `50` | `PUSH EAX` |
| `10005ca9` | `51` | `PUSH ECX` |
| `10005caa` | `e8 81 32 00 00` | `CALL 0x10008f30` |
| `10005caf` | `83 c4 08` | `ADD ESP,0x8` |
| `10005cb2` | `c2 08 00` | `RET 0x8` |
