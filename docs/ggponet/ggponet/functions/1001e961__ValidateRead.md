# 1001e961 `_ValidateRead`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e961 |
| `name` | _ValidateRead |
| `namespace` | Global |
| `signature` | int __cdecl _ValidateRead(void * param_1, uint param_2) |
| `size_bytes` | 18 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?_ValidateRead@@YAHPBXI@Z, _ValidateRead |

## Decompiled C

```c

/* Library Function - Single Match
    int __cdecl _ValidateRead(void const *,unsigned int)
   
   Library: Visual Studio 2008 Release */

int __cdecl _ValidateRead(void *param_1,uint param_2)

{
  return (uint)(param_1 != (void *)0x0);
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001b539` | FindHandler |
| `1001b173` | ___BuildCatchObjectHelper |
| `1001b184` | ___BuildCatchObjectHelper |
| `1001b1bb` | ___BuildCatchObjectHelper |
| `1001b1cc` | ___BuildCatchObjectHelper |
| `1001b208` | ___BuildCatchObjectHelper |
| `1001b215` | ___BuildCatchObjectHelper |
| `1001b240` | ___BuildCatchObjectHelper |
| `1001b24d` | ___BuildCatchObjectHelper |
| `1001b25b` | ___BuildCatchObjectHelper |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e961` | `8b ff` | `MOV EDI,EDI` |
| `1001e963` | `55` | `PUSH EBP` |
| `1001e964` | `8b ec` | `MOV EBP,ESP` |
| `1001e966` | `33 c0` | `XOR EAX,EAX` |
| `1001e968` | `40` | `INC EAX` |
| `1001e969` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `1001e96d` | `75 02` | `JNZ 0x1001e971` |
| `1001e96f` | `33 c0` | `XOR EAX,EAX` |
| `1001e971` | `5d` | `POP EBP` |
| `1001e972` | `c3` | `RET` |
