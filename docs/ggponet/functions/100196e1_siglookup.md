# 100196e1 `siglookup`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 100196e1 |
| `name` | siglookup |
| `namespace` | Global |
| `signature` | undefined __cdecl siglookup(void) |
| `size_bytes` | 55 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _siglookup, siglookup |

## Decompiled C

```c

/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 2008 Release */

uint __cdecl siglookup(uint param_1)

{
  uint uVar1;
  int in_EDX;
  
  uVar1 = param_1;
  do {
    if (*(int *)(uVar1 + 4) == in_EDX) break;
    uVar1 = uVar1 + 0xc;
  } while (uVar1 < DAT_10037bf4 * 0xc + param_1);
  if ((DAT_10037bf4 * 0xc + param_1 <= uVar1) || (*(int *)(uVar1 + 4) != in_EDX)) {
    uVar1 = 0;
  }
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001977f` | _raise |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `100196e9` | `10037bf4` | `READ` | DAT_10037bf4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `100196e1` | `8b ff` | `MOV EDI,EDI` |
| `100196e3` | `55` | `PUSH EBP` |
| `100196e4` | `8b ec` | `MOV EBP,ESP` |
| `100196e6` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `100196e9` | `8b 0d f4 7b 03 10` | `MOV ECX,dword ptr [0x10037bf4]` |
| `100196ef` | `56` | `PUSH ESI` |
| `100196f0` | `39 50 04` | `CMP dword ptr [EAX + 0x4],EDX` |
| `100196f3` | `74 0f` | `JZ 0x10019704` |
| `100196f5` | `8b f1` | `MOV ESI,ECX` |
| `100196f7` | `6b f6 0c` | `IMUL ESI,ESI,0xc` |
| `100196fa` | `03 75 08` | `ADD ESI,dword ptr [EBP + 0x8]` |
| `100196fd` | `83 c0 0c` | `ADD EAX,0xc` |
| `10019700` | `3b c6` | `CMP EAX,ESI` |
| `10019702` | `72 ec` | `JC 0x100196f0` |
| `10019704` | `6b c9 0c` | `IMUL ECX,ECX,0xc` |
| `10019707` | `03 4d 08` | `ADD ECX,dword ptr [EBP + 0x8]` |
| `1001970a` | `5e` | `POP ESI` |
| `1001970b` | `3b c1` | `CMP EAX,ECX` |
| `1001970d` | `73 05` | `JNC 0x10019714` |
| `1001970f` | `39 50 04` | `CMP dword ptr [EAX + 0x4],EDX` |
| `10019712` | `74 02` | `JZ 0x10019716` |
| `10019714` | `33 c0` | `XOR EAX,EAX` |
| `10019716` | `5d` | `POP EBP` |
| `10019717` | `c3` | `RET` |
