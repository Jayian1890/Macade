# 1002a220 `__positive`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a220 |
| `name` | __positive |
| `namespace` | Global |
| `signature` | int __cdecl __positive(double * arg) |
| `size_bytes` | 28 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __positive |

## Decompiled C

```c

/* Library Function - Single Match
    __positive
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl __positive(double *arg)

{
  double dVar1;
  
  dVar1 = *arg;
  if (!NAN(dVar1) && 0.0 < dVar1 != (dVar1 == 0.0)) {
    return 1;
  }
  return 0;
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
| `1002a220` | `8b ff` | `MOV EDI,EDI` |
| `1002a222` | `55` | `PUSH EBP` |
| `1002a223` | `8b ec` | `MOV EBP,ESP` |
| `1002a225` | `d9 ee` | `FLDZ` |
| `1002a227` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002a22a` | `dc 18` | `FCOMP double ptr [EAX]` |
| `1002a22c` | `df e0` | `FNSTSW AX` |
| `1002a22e` | `f6 c4 41` | `TEST AH,0x41` |
| `1002a231` | `7a 05` | `JP 0x1002a238` |
| `1002a233` | `33 c0` | `XOR EAX,EAX` |
| `1002a235` | `40` | `INC EAX` |
| `1002a236` | `5d` | `POP EBP` |
| `1002a237` | `c3` | `RET` |
| `1002a238` | `33 c0` | `XOR EAX,EAX` |
| `1002a23a` | `5d` | `POP EBP` |
| `1002a23b` | `c3` | `RET` |
