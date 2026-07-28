# 10021b50 `ggpo_get_stats`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021b50 |
| `name` | ggpo_get_stats |
| `namespace` | Global |
| `signature` | undefined ggpo_get_stats(void) |
| `size_bytes` | 43 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_6, ggpo_get_stats |

## Decompiled C

```c

undefined1 ggpo_get_stats(int *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21b50  6  ggpo_get_stats */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 0x10))(param_2);
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
| `10021b50` | `55` | `PUSH EBP` |
| `10021b51` | `8b ec` | `MOV EBP,ESP` |
| `10021b53` | `51` | `PUSH ECX` |
| `10021b54` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021b58` | `74 16` | `JZ 0x10021b70` |
| `10021b5a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10021b5d` | `50` | `PUSH EAX` |
| `10021b5e` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021b61` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10021b63` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021b66` | `8b 42 10` | `MOV EAX,dword ptr [EDX + 0x10]` |
| `10021b69` | `ff d0` | `CALL EAX` |
| `10021b6b` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021b6e` | `eb 04` | `JMP 0x10021b74` |
| `10021b70` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021b74` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021b77` | `8b e5` | `MOV ESP,EBP` |
| `10021b79` | `5d` | `POP EBP` |
| `10021b7a` | `c3` | `RET` |
