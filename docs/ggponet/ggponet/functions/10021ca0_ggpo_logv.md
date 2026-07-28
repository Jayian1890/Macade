# 10021ca0 `ggpo_logv`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021ca0 |
| `name` | ggpo_logv |
| `namespace` | Global |
| `signature` | undefined ggpo_logv(void) |
| `size_bytes` | 32 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_9, ggpo_logv |

## Decompiled C

```c

void ggpo_logv(int *param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x21ca0  9  ggpo_logv */
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x18))(param_2,param_3);
  }
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10021cd6` | ggpo_log |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021ca0` | `55` | `PUSH EBP` |
| `10021ca1` | `8b ec` | `MOV EBP,ESP` |
| `10021ca3` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021ca7` | `74 15` | `JZ 0x10021cbe` |
| `10021ca9` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10021cac` | `50` | `PUSH EAX` |
| `10021cad` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10021cb0` | `51` | `PUSH ECX` |
| `10021cb1` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10021cb4` | `8b 02` | `MOV EAX,dword ptr [EDX]` |
| `10021cb6` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021cb9` | `8b 50 18` | `MOV EDX,dword ptr [EAX + 0x18]` |
| `10021cbc` | `ff d2` | `CALL EDX` |
| `10021cbe` | `5d` | `POP EBP` |
| `10021cbf` | `c3` | `RET` |
