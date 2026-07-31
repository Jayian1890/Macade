# 10021d10 `ggpo_start_replay`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021d10 |
| `name` | ggpo_start_replay |
| `namespace` | Global |
| `signature` | undefined ggpo_start_replay(void) |
| `size_bytes` | 66 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_11, ggpo_start_replay |

## Decompiled C

```c

undefined4 ggpo_start_replay(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21d10  11  ggpo_start_replay */
  iVar1 = FUN_100118ec(0x40);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10027f60(param_1,param_2);
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021d18` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |
| `10021d34` | `10027f60` | `UNCONDITIONAL_CALL` | FUN_10027f60 | `10027f60` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021d10` | `55` | `PUSH EBP` |
| `10021d11` | `8b ec` | `MOV EBP,ESP` |
| `10021d13` | `83 ec 0c` | `SUB ESP,0xc` |
| `10021d16` | `6a 40` | `PUSH 0x40` |
| `10021d18` | `e8 cf fb fe ff` | `CALL 0x100118ec` |
| `10021d1d` | `83 c4 04` | `ADD ESP,0x4` |
| `10021d20` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10021d23` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10021d27` | `74 15` | `JZ 0x10021d3e` |
| `10021d29` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10021d2c` | `50` | `PUSH EAX` |
| `10021d2d` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021d30` | `51` | `PUSH ECX` |
| `10021d31` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10021d34` | `e8 27 62 00 00` | `CALL 0x10027f60` |
| `10021d39` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10021d3c` | `eb 07` | `JMP 0x10021d45` |
| `10021d3e` | `c7 45 f4 00 00 00 00` | `MOV dword ptr [EBP + -0xc],0x0` |
| `10021d45` | `8b 55 f4` | `MOV EDX,dword ptr [EBP + -0xc]` |
| `10021d48` | `89 55 fc` | `MOV dword ptr [EBP + -0x4],EDX` |
| `10021d4b` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10021d4e` | `8b e5` | `MOV ESP,EBP` |
| `10021d50` | `5d` | `POP EBP` |
| `10021d51` | `c3` | `RET` |
