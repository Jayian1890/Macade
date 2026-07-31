# 10021c80 `ggpo_client_set_game_event`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021c80 |
| `name` | ggpo_client_set_game_event |
| `namespace` | Global |
| `signature` | undefined ggpo_client_set_game_event(void) |
| `size_bytes` | 26 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_4, ggpo_client_set_game_event |

## Decompiled C

```c

void ggpo_client_set_game_event(int *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x21c80  4  ggpo_client_set_game_event */
  (**(code **)(*param_1 + 0x14))(param_2,param_3);
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021c80` | `55` | `PUSH EBP` |
| `10021c81` | `8b ec` | `MOV EBP,ESP` |
| `10021c83` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10021c86` | `50` | `PUSH EAX` |
| `10021c87` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10021c8a` | `51` | `PUSH ECX` |
| `10021c8b` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10021c8e` | `8b 02` | `MOV EAX,dword ptr [EDX]` |
| `10021c90` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021c93` | `8b 50 14` | `MOV EDX,dword ptr [EAX + 0x14]` |
| `10021c96` | `ff d2` | `CALL EDX` |
| `10021c98` | `5d` | `POP EBP` |
| `10021c99` | `c3` | `RET` |
