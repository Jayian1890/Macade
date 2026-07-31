# 10021e50 `ggpo_start_session`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021e50 |
| `name` | ggpo_start_session |
| `namespace` | Global |
| `signature` | undefined ggpo_start_session(void) |
| `size_bytes` | 106 |
| `stack_frame_size` | 24 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_12, ggpo_start_session |

## Decompiled C

```c

undefined4
ggpo_start_session(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,int param_6)

{
  int iVar1;
  undefined4 local_14;
  
                    /* 0x21e50  12  ggpo_start_session */
  iVar1 = FUN_100118ec(0x19d8);
  if (iVar1 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = FUN_100287f0(param_1,param_2,param_3);
  }
  FUN_10028ac0(param_4,param_5,param_6 != 0);
  return local_14;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021e5b` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |
| `10021e7b` | `100287f0` | `UNCONDITIONAL_CALL` | FUN_100287f0 | `100287f0` |
| `10021eae` | `10028ac0` | `UNCONDITIONAL_CALL` | FUN_10028ac0 | `10028ac0` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021e50` | `55` | `PUSH EBP` |
| `10021e51` | `8b ec` | `MOV EBP,ESP` |
| `10021e53` | `83 ec 10` | `SUB ESP,0x10` |
| `10021e56` | `68 d8 19 00 00` | `PUSH 0x19d8` |
| `10021e5b` | `e8 8c fa fe ff` | `CALL 0x100118ec` |
| `10021e60` | `83 c4 04` | `ADD ESP,0x4` |
| `10021e63` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10021e66` | `83 7d f4 00` | `CMP dword ptr [EBP + -0xc],0x0` |
| `10021e6a` | `74 19` | `JZ 0x10021e85` |
| `10021e6c` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10021e6f` | `50` | `PUSH EAX` |
| `10021e70` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10021e73` | `51` | `PUSH ECX` |
| `10021e74` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10021e77` | `52` | `PUSH EDX` |
| `10021e78` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10021e7b` | `e8 70 69 00 00` | `CALL 0x100287f0` |
| `10021e80` | `89 45 f0` | `MOV dword ptr [EBP + -0x10],EAX` |
| `10021e83` | `eb 07` | `JMP 0x10021e8c` |
| `10021e85` | `c7 45 f0 00 00 00 00` | `MOV dword ptr [EBP + -0x10],0x0` |
| `10021e8c` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `10021e8f` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10021e92` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10021e95` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10021e98` | `83 7d 1c 00` | `CMP dword ptr [EBP + 0x1c],0x0` |
| `10021e9c` | `0f 95 c2` | `SETNZ DL` |
| `10021e9f` | `0f b6 c2` | `MOVZX EAX,DL` |
| `10021ea2` | `50` | `PUSH EAX` |
| `10021ea3` | `8b 4d 18` | `MOV ECX,dword ptr [EBP + 0x18]` |
| `10021ea6` | `51` | `PUSH ECX` |
| `10021ea7` | `8b 55 14` | `MOV EDX,dword ptr [EBP + 0x14]` |
| `10021eaa` | `52` | `PUSH EDX` |
| `10021eab` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `10021eae` | `e8 0d 6c 00 00` | `CALL 0x10028ac0` |
| `10021eb3` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10021eb6` | `8b e5` | `MOV ESP,EBP` |
| `10021eb8` | `5d` | `POP EBP` |
| `10021eb9` | `c3` | `RET` |
