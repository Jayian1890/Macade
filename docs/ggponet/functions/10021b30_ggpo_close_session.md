# 10021b30 `ggpo_close_session`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021b30 |
| `name` | ggpo_close_session |
| `namespace` | Global |
| `signature` | undefined ggpo_close_session(void) |
| `size_bytes` | 26 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_5, ggpo_close_session |

## Decompiled C

```c

void ggpo_close_session(undefined4 param_1)

{
                    /* 0x21b30  5  ggpo_close_session */
  FUN_100117f8(param_1);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021b3e` | `100117f8` | `UNCONDITIONAL_CALL` | FUN_100117f8 | `100117f8` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021b30` | `55` | `PUSH EBP` |
| `10021b31` | `8b ec` | `MOV EBP,ESP` |
| `10021b33` | `51` | `PUSH ECX` |
| `10021b34` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021b37` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10021b3a` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10021b3d` | `51` | `PUSH ECX` |
| `10021b3e` | `e8 b5 fc fe ff` | `CALL 0x100117f8` |
| `10021b43` | `83 c4 04` | `ADD ESP,0x4` |
| `10021b46` | `8b e5` | `MOV ESP,EBP` |
| `10021b48` | `5d` | `POP EBP` |
| `10021b49` | `c3` | `RET` |
