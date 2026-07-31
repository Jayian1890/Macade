# 1001da8d `__NLG_Notify`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001da8d |
| `name` | __NLG_Notify |
| `namespace` | Global |
| `signature` | void __stdcall __NLG_Notify(ulong param_1) |
| `size_bytes` | 31 |
| `stack_frame_size` | 8 |
| `calling_convention` | __stdcall |
| `source_type` | ANALYSIS |
| `export_names` | __NLG_Notify |

## Decompiled C

```c

/* Library Function - Single Match
    __NLG_Notify
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

void __NLG_Notify(ulong param_1)

{
  undefined4 in_EAX;
  undefined4 unaff_EBP;
  
  DAT_10038248 = param_1;
  DAT_10038244 = in_EAX;
  DAT_1003824c = unaff_EBP;
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10018376` | __local_unwind4 |
| `10018419` | _EH4_TransferToHandler |
| `1001da3f` | __local_unwind2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001da8f` | `10038240` | `DATA` | DAT_10038240 |
| `1001da98` | `10038248` | `WRITE` | DAT_10038248 |
| `1001da9b` | `10038244` | `WRITE` | DAT_10038244 |
| `1001da9e` | `1003824c` | `WRITE` | DAT_1003824c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001da8d` | `53` | `PUSH EBX` |
| `1001da8e` | `51` | `PUSH ECX` |
| `1001da8f` | `bb 40 82 03 10` | `MOV EBX,0x10038240` |
| `1001da94` | `8b 4c 24 0c` | `MOV ECX,dword ptr [ESP + 0xc]` |
| `1001da98` | `89 4b 08` | `MOV dword ptr [EBX + 0x8],ECX` |
| `1001da9b` | `89 43 04` | `MOV dword ptr [EBX + 0x4],EAX` |
| `1001da9e` | `89 6b 0c` | `MOV dword ptr [EBX + 0xc],EBP` |
| `1001daa1` | `55` | `PUSH EBP` |
| `1001daa2` | `51` | `PUSH ECX` |
| `1001daa3` | `50` | `PUSH EAX` |
| `1001daa4` | `58` | `POP EAX` |
| `1001daa5` | `59` | `POP ECX` |
| `1001daa6` | `5d` | `POP EBP` |
| `1001daa7` | `59` | `POP ECX` |
| `1001daa8` | `5b` | `POP EBX` |
| `1001daa9` | `c2 04 00` | `RET 0x4` |
