# 10021c20 `ggpo_idle`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10021c20 |
| `name` | ggpo_idle |
| `namespace` | Global |
| `signature` | undefined ggpo_idle(void) |
| `size_bytes` | 42 |
| `stack_frame_size` | 9 |
| `calling_convention` | unknown |
| `source_type` | IMPORTED |
| `export_names` | Ordinal_7, ggpo_idle |

## Decompiled C

```c

undefined1 ggpo_idle(undefined4 *param_1,undefined4 param_2)

{
  undefined1 local_5;
  
                    /* 0x21c20  7  ggpo_idle */
  if (param_1 == (undefined4 *)0x0) {
    local_5 = 0;
  }
  else {
    local_5 = (**(code **)*param_1)(param_2);
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
| `10021c20` | `55` | `PUSH EBP` |
| `10021c21` | `8b ec` | `MOV EBP,ESP` |
| `10021c23` | `51` | `PUSH ECX` |
| `10021c24` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10021c28` | `74 15` | `JZ 0x10021c3f` |
| `10021c2a` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10021c2d` | `50` | `PUSH EAX` |
| `10021c2e` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021c31` | `8b 11` | `MOV EDX,dword ptr [ECX]` |
| `10021c33` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10021c36` | `8b 02` | `MOV EAX,dword ptr [EDX]` |
| `10021c38` | `ff d0` | `CALL EAX` |
| `10021c3a` | `88 45 ff` | `MOV byte ptr [EBP + -0x1],AL` |
| `10021c3d` | `eb 04` | `JMP 0x10021c43` |
| `10021c3f` | `c6 45 ff 00` | `MOV byte ptr [EBP + -0x1],0x0` |
| `10021c43` | `8a 45 ff` | `MOV AL,byte ptr [EBP + -0x1]` |
| `10021c46` | `8b e5` | `MOV ESP,EBP` |
| `10021c48` | `5d` | `POP EBP` |
| `10021c49` | `c3` | `RET` |
