# 10021cc0 `ggpo_log`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021cc0 |
| `name` | ggpo_log |
| `namespace` | Global |
| `signature` | undefined ggpo_log(void) |
| `size_bytes` | 41 |
| `stack_frame_size` | 12 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_8, ggpo_log |

## Decompiled C

```c

void ggpo_log(undefined4 param_1,undefined4 param_2)

{
                    /* 0x21cc0  8  ggpo_log */
  ggpo_logv(param_1,param_2,&stack0x0000000c);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021cd6` | `10021ca0` | `UNCONDITIONAL_CALL` | ggpo_logv | `10021ca0` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021cc0` | `55` | `PUSH EBP` |
| `10021cc1` | `8b ec` | `MOV EBP,ESP` |
| `10021cc3` | `51` | `PUSH ECX` |
| `10021cc4` | `8d 45 10` | `LEA EAX,[EBP + 0x10]` |
| `10021cc7` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10021cca` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10021ccd` | `51` | `PUSH ECX` |
| `10021cce` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10021cd1` | `52` | `PUSH EDX` |
| `10021cd2` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021cd5` | `50` | `PUSH EAX` |
| `10021cd6` | `e8 c5 ff ff ff` | `CALL 0x10021ca0` |
| `10021cdb` | `83 c4 0c` | `ADD ESP,0xc` |
| `10021cde` | `c7 45 fc 00 00 00 00` | `MOV dword ptr [EBP + -0x4],0x0` |
| `10021ce5` | `8b e5` | `MOV ESP,EBP` |
| `10021ce7` | `5d` | `POP EBP` |
| `10021ce8` | `c3` | `RET` |
