# 10021c50 `ggpo_set_frame_delay`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021c50 |
| `name` | ggpo_set_frame_delay |
| `namespace` | Global |
| `signature` | undefined ggpo_set_frame_delay(void) |
| `size_bytes` | 43 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_10, ggpo_set_frame_delay |

## Decompiled C

```c

undefined1 ggpo_set_frame_delay(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21c50  10  ggpo_set_frame_delay */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0x1c))(param_2);
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
| `10021c50` | `55` | `PUSH EBP` |
| `10021c51` | `8b ec` | `MOV EBP,ESP` |
| `10021c53` | `51` | `PUSH ECX` |
| `10021c54` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021c58` | `74 16` | `JZ 0x10021c70` |
| `10021c5a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10021c5d` | `50` | `PUSH EAX` |
| `10021c5e` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021c61` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10021c63` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021c66` | `8b 42 1c` | `MOV EAX,dword ptr [EDX + 0x1c]` |
| `10021c69` | `ff d0` | `CALL EAX` |
| `10021c6b` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021c6e` | `eb 04` | `JMP 0x10021c74` |
| `10021c70` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021c74` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021c77` | `8b e5` | `MOV ESP,EBP` |
| `10021c79` | `5d` | `POP EBP` |
| `10021c7a` | `c3` | `RET` |
