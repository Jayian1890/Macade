# 10021e00 `ggpo_client_connect`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021e00 |
| `name` | ggpo_client_connect |
| `namespace` | Global |
| `signature` | undefined ggpo_client_connect(void) |
| `size_bytes` | 77 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_3, ggpo_client_connect |

## Decompiled C

```c

undefined4
ggpo_client_connect(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21e00  3  ggpo_client_connect */
  iVar1 = FUN_100118ec(0x2338);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10029a40(param_1,param_2,param_3,param_4);
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021e0b` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |
| `10021e2f` | `10029a40` | `UNCONDITIONAL_CALL` | FUN_10029a40 | `10029a40` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021e00` | `55` | `PUSH EBP` |
| `10021e01` | `8b ec` | `MOV EBP,ESP` |
| `10021e03` | `83 ec 0c` | `SUB ESP,0xc` |
| `10021e06` | `68 38 23 00 00` | `PUSH 0x2338` |
| `10021e0b` | `e8 dc fa fe ff` | `CALL 0x100118ec` |
| `10021e10` | `83 c4 04` | `ADD ESP,0x4` |
| `10021e13` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10021e16` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10021e1a` | `74 1d` | `JZ 0x10021e39` |
| `10021e1c` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `10021e1f` | `50` | `PUSH EAX` |
| `10021e20` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10021e23` | `51` | `PUSH ECX` |
| `10021e24` | `8b 55 0c` | `MOV EDX,dword ptr [EBP + 0xc]` |
| `10021e27` | `52` | `PUSH EDX` |
| `10021e28` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10021e2b` | `50` | `PUSH EAX` |
| `10021e2c` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10021e2f` | `e8 0c 7c 00 00` | `CALL 0x10029a40` |
| `10021e34` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10021e37` | `eb 07` | `JMP 0x10021e40` |
| `10021e39` | `c7 45 f4 00 00 00 00` | `MOV dword ptr [EBP + -0xc],0x0` |
| `10021e40` | `8b 4d f4` | `MOV ECX,dword ptr [EBP + -0xc]` |
| `10021e43` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `10021e46` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10021e49` | `8b e5` | `MOV ESP,EBP` |
| `10021e4b` | `5d` | `POP EBP` |
| `10021e4c` | `c3` | `RET` |
