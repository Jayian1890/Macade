# 1001da84 `__NLG_Notify1`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001da84 |
| `name` | __NLG_Notify1 |
| `namespace` | Global |
| `signature` | undefined __NLG_Notify1(void) |
| `size_bytes` | 9 |
| `stack_frame_size` | 4 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | __NLG_Notify1 |

## Decompiled C

```c

/* Library Function - Single Match
    __NLG_Notify1
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

undefined4 __NLG_Notify1(void)

{
  undefined4 in_EAX;
  undefined4 in_ECX;
  undefined4 unaff_EBP;
  
  DAT_10038248 = in_ECX;
  DAT_10038244 = in_EAX;
  DAT_1003824c = unaff_EBP;
  return in_EAX;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `1001b8fe` | __CallSettingFrame@12 |
| `1001b920` | __CallSettingFrame@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001da86` | `10038240` | `DATA` | DAT_10038240 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001da84` | `53` | `PUSH EBX` |
| `1001da85` | `51` | `PUSH ECX` |
| `1001da86` | `bb 40 82 03 10` | `MOV EBX,0x10038240` |
| `1001da8b` | `eb 0b` | `JMP 0x1001da98` |
