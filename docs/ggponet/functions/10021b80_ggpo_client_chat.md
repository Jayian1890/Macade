# 10021b80 `ggpo_client_chat`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021b80 |
| `name` | ggpo_client_chat |
| `namespace` | Global |
| `signature` | undefined ggpo_client_chat(void) |
| `size_bytes` | 43 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_2, ggpo_client_chat |

## Decompiled C

```c

undefined1 ggpo_client_chat(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21b80  2  ggpo_client_chat */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0xc))(param_2);
  }
  return local_5;
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
| `10021b80` | `55` | `PUSH EBP` |
| `10021b81` | `8b ec` | `MOV EBP,ESP` |
| `10021b83` | `51` | `PUSH ECX` |
| `10021b84` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021b88` | `74 16` | `JZ 0x10021ba0` |
| `10021b8a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10021b8d` | `50` | `PUSH EAX` |
| `10021b8e` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021b91` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10021b93` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021b96` | `8b 42 0c` | `MOV EAX,dword ptr [EDX + 0xc]` |
| `10021b99` | `ff d0` | `CALL EAX` |
| `10021b9b` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021b9e` | `eb 04` | `JMP 0x10021ba4` |
| `10021ba0` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021ba4` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021ba7` | `8b e5` | `MOV ESP,EBP` |
| `10021ba9` | `5d` | `POP EBP` |
| `10021baa` | `c3` | `RET` |
