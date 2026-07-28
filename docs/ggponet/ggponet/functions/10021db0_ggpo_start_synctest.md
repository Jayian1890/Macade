# 10021db0 `ggpo_start_synctest`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021db0 |
| `name` | ggpo_start_synctest |
| `namespace` | Global |
| `signature` | undefined ggpo_start_synctest(void) |
| `size_bytes` | 73 |
| `stack_frame_size` | 20 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_14, ggpo_start_synctest |

## Decompiled C

```c

undefined4 ggpo_start_synctest(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x21db0  14  ggpo_start_synctest */
  iVar1 = FUN_100118ec(0x360);
  if (iVar1 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10027980(param_1,param_2,param_3);
  }
  return local_10;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10021dbb` | `100118ec` | `UNCONDITIONAL_CALL` | FUN_100118ec | `100118ec` |
| `10021ddb` | `10027980` | `UNCONDITIONAL_CALL` | FUN_10027980 | `10027980` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10021db0` | `55` | `PUSH EBP` |
| `10021db1` | `8b ec` | `MOV EBP,ESP` |
| `10021db3` | `83 ec 0c` | `SUB ESP,0xc` |
| `10021db6` | `68 60 03 00 00` | `PUSH 0x360` |
| `10021dbb` | `e8 2c fb fe ff` | `CALL 0x100118ec` |
| `10021dc0` | `83 c4 04` | `ADD ESP,0x4` |
| `10021dc3` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `10021dc6` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10021dca` | `74 19` | `JZ 0x10021de5` |
| `10021dcc` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10021dcf` | `50` | `PUSH EAX` |
| `10021dd0` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10021dd3` | `51` | `PUSH ECX` |
| `10021dd4` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10021dd7` | `52` | `PUSH EDX` |
| `10021dd8` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `10021ddb` | `e8 a0 5b 00 00` | `CALL 0x10027980` |
| `10021de0` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `10021de3` | `eb 07` | `JMP 0x10021dec` |
| `10021de5` | `c7 45 f4 00 00 00 00` | `MOV dword ptr [EBP + -0xc],0x0` |
| `10021dec` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `10021def` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10021df2` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10021df5` | `8b e5` | `MOV ESP,EBP` |
| `10021df7` | `5d` | `POP EBP` |
| `10021df8` | `c3` | `RET` |
