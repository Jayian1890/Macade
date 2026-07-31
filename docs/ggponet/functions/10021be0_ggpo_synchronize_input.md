# 10021be0 `ggpo_synchronize_input`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021be0 |
| `name` | ggpo_synchronize_input |
| `namespace` | Global |
| `signature` | undefined ggpo_synchronize_input(void) |
| `size_bytes` | 51 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_15, ggpo_synchronize_input |

## Decompiled C

```c

undefined1
ggpo_synchronize_input(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_5;
  
                    /* 0x21be0  15  ggpo_synchronize_input */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 4))(param_2,param_3,param_4);
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
| `10021be0` | `55` | `PUSH EBP` |
| `10021be1` | `8b ec` | `MOV EBP,ESP` |
| `10021be3` | `51` | `PUSH ECX` |
| `10021be4` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021be8` | `74 1e` | `JZ 0x10021c08` |
| `10021bea` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10021bed` | `50` | `PUSH EAX` |
| `10021bee` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10021bf1` | `51` | `PUSH ECX` |
| `10021bf2` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10021bf5` | `52` | `PUSH EDX` |
| `10021bf6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021bf9` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `10021bfb` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021bfe` | `8b 42 04` | `MOV EAX,dword ptr [EDX + 0x4]` |
| `10021c01` | `ff d0` | `CALL EAX` |
| `10021c03` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021c06` | `eb 04` | `JMP 0x10021c0c` |
| `10021c08` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021c0c` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021c0f` | `8b e5` | `MOV ESP,EBP` |
| `10021c11` | `5d` | `POP EBP` |
| `10021c12` | `c3` | `RET` |
