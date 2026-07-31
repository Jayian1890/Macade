# 1001cbc6 `_isdigit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001cbc6 |
| `name` | _isdigit |
| `namespace` | Global |
| `signature` | int __cdecl _isdigit(int _C) |
| `size_bytes` | 46 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _isdigit |

## Decompiled C

```c

/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2008 Release */

int __cdecl _isdigit(int _C)

{
  int iVar1;
  
  if (DAT_100393a0 == 0) {
    return *(ushort *)(PTR_DAT_10038218 + _C * 2) & 4;
  }
  iVar1 = __isdigit_l(_C,(_locale_t)0x0);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001cbeb` | `1001cb75` | `UNCONDITIONAL_CALL` | __isdigit_l | `1001cb75` |

## Callers

| From | Function |
| --- | --- |
| `1002a155` | __forcdecpt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001cbcb` | `100393a0` | `READ` | DAT_100393a0 |
| `1001cbd7` | `10038218` | `READ` | PTR_DAT_10038218 |
| `1001cbdd` | `10030100` | `DATA` | DAT_10030100 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001cbc6` | `8b ff` | `MOV EDI,EDI` |
| `1001cbc8` | `55` | `PUSH EBP` |
| `1001cbc9` | `8b ec` | `MOV EBP,ESP` |
| `1001cbcb` | `83 3d a0 93 03 10 00` | `CMP dword ptr [0x100393a0],0x0` |
| `1001cbd2` | `75 12` | `JNZ 0x1001cbe6` |
| `1001cbd4` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001cbd7` | `8b 0d 18 82 03 10` | `MOV ECX,dword ptr [0x10038218]` |
| `1001cbdd` | `0f b7 04 41` | `MOVZX EAX,word ptr [ECX + EAX*0x2]` |
| `1001cbe1` | `83 e0 04` | `AND EAX,0x4` |
| `1001cbe4` | `5d` | `POP EBP` |
| `1001cbe5` | `c3` | `RET` |
| `1001cbe6` | `6a 00` | `PUSH 0x0` |
| `1001cbe8` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001cbeb` | `e8 85 ff ff ff` | `CALL 0x1001cb75` |
| `1001cbf0` | `59` | `POP ECX` |
| `1001cbf1` | `59` | `POP ECX` |
| `1001cbf2` | `5d` | `POP EBP` |
| `1001cbf3` | `c3` | `RET` |
