# 10021d60 `ggpo_start_streaming`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021d60 |
| `name` | ggpo_start_streaming |
| `namespace` | Global |
| `signature` | undefined ggpo_start_streaming(void) |
| `size_bytes` | 77 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_13, ggpo_start_streaming |

## Decompiled C

```c

undefined4
ggpo_start_streaming(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21d60  13  ggpo_start_streaming */
  iVar1 = FUN_100118ec(0xb90);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10028d90(param_1,param_2,param_3,param_4);
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021d6b` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |
| `10021d8f` | `10028d90` | `UNCONDITIONAL_CALL` | FUN_10028d90 | `10028d90` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021d60` | `55` | `PUSH EBP` |
| `10021d61` | `8b ec` | `MOV EBP,ESP` |
| `10021d63` | `83 ec 0c` | `SUB ESP,0xc` |
| `10021d66` | `68 90 0b 00 00` | `PUSH 0xb90` |
| `10021d6b` | `e8 7c fb fe ff` | `CALL 0x100118ec` |
| `10021d70` | `83 c4 04` | `ADD ESP,0x4` |
| `10021d73` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10021d76` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10021d7a` | `74 1d` | `JZ 0x10021d99` |
| `10021d7c` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10021d7f` | `50` | `PUSH EAX` |
| `10021d80` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10021d83` | `51` | `PUSH ECX` |
| `10021d84` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10021d87` | `52` | `PUSH EDX` |
| `10021d88` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021d8b` | `50` | `PUSH EAX` |
| `10021d8c` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10021d8f` | `e8 fc 6f 00 00` | `CALL 0x10028d90` |
| `10021d94` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10021d97` | `eb 07` | `JMP 0x10021da0` |
| `10021d99` | `c7 45 f4 00 00 00 00` | `MOV dword ptr [EBP + -0xc],0x0` |
| `10021da0` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10021da3` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10021da6` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10021da9` | `8b e5` | `MOV ESP,EBP` |
| `10021dab` | `5d` | `POP EBP` |
| `10021dac` | `c3` | `RET` |
