# 10017ac5 `__set_abort_behavior`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017ac5 |
| `name` | __set_abort_behavior |
| `namespace` | Global |
| `signature` | uint __cdecl __set_abort_behavior(uint _Flags, uint _Mask) |
| `size_bytes` | 33 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __set_abort_behavior |

## Decompiled C

```c

/* Library Function - Single Match
    __set_abort_behavior
   
   Library: Visual Studio 2008 Release */

uint __cdecl __set_abort_behavior(uint _Flags,uint _Mask)

{
  uint uVar1;
  
  uVar1 = DAT_100377fc;
  DAT_100377fc = ~_Mask & DAT_100377fc | _Flags & _Mask;
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001196e` | __purecall |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017acd` | `100377fc` | `READ` | DAT_100377fc |
| `10017ade` | `100377fc` | `WRITE` | DAT_100377fc |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017ac5` | `8b ff` | `MOV EDI,EDI` |
| `10017ac7` | `55` | `PUSH EBP` |
| `10017ac8` | `8b ec` | `MOV EBP,ESP` |
| `10017aca` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10017acd` | `a1 fc 77 03 10` | `MOV EAX,[0x100377fc]` |
| `10017ad2` | `8b 55 08` | `MOV EDX,dword ptr [EBP + 0x8]` |
| `10017ad5` | `23 55 0c` | `AND EDX,dword ptr [EBP + 0xc]` |
| `10017ad8` | `f7 d1` | `NOT ECX` |
| `10017ada` | `23 c8` | `AND ECX,EAX` |
| `10017adc` | `0b ca` | `OR ECX,EDX` |
| `10017ade` | `89 0d fc 77 03 10` | `MOV dword ptr [0x100377fc],ECX` |
| `10017ae4` | `5d` | `POP EBP` |
| `10017ae5` | `c3` | `RET` |
