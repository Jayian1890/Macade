# 10021bb0 `ggpo_advance_frame`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021bb0 |
| `name` | ggpo_advance_frame |
| `namespace` | Global |
| `signature` | undefined ggpo_advance_frame(void) |
| `size_bytes` | 39 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_1, ggpo_advance_frame |

## Decompiled C

```c

undefined1 ggpo_advance_frame(int *param_1)

{
  undefined1 local_5;
  
                    /* 0x21bb0  1  ggpo_advance_frame */
  if (param_1 == (int *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)(*param_1 + 8))();
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
| `10021bb0` | `55` | `PUSH EBP` |
| `10021bb1` | `8b ec` | `MOV EBP,ESP` |
| `10021bb3` | `51` | `PUSH ECX` |
| `10021bb4` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021bb8` | `74 12` | `JZ 0x10021bcc` |
| `10021bba` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021bbd` | `8b 10` | `MOV EDX,dword ptr [EAX]` |
| `10021bbf` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021bc2` | `8b 42 08` | `MOV EAX,dword ptr [EDX + 0x8]` |
| `10021bc5` | `ff d0` | `CALL EAX` |
| `10021bc7` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021bca` | `eb 04` | `JMP 0x10021bd0` |
| `10021bcc` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021bd0` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021bd3` | `8b e5` | `MOV ESP,EBP` |
| `10021bd5` | `5d` | `POP EBP` |
| `10021bd6` | `c3` | `RET` |
