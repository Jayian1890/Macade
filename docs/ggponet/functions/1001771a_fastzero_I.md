# 1001771a `fastzero_I`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001771a |
| `name` | fastzero_I |
| `namespace` | Global |
| `signature` | undefined __cdecl fastzero_I(void) |
| `size_bytes` | 79 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _fastzero_I, fastzero_I |

## Decompiled C

```c

/* Library Function - Single Match
    _fastzero_I
   
   Libraries: Visual Studio 2005, Visual Studio 2008, Visual Studio 2019 */

void __cdecl fastzero_I(undefined1 (*param_1) [16],uint param_2)

{
  param_2 = param_2 >> 7;
  do {
    *param_1 = (undefined1  [16])0x0;
    param_1[1] = (undefined1  [16])0x0;
    param_1[2] = (undefined1  [16])0x0;
    param_1[3] = (undefined1  [16])0x0;
    param_1[4] = (undefined1  [16])0x0;
    param_1[5] = (undefined1  [16])0x0;
    param_1[6] = (undefined1  [16])0x0;
    param_1[7] = (undefined1  [16])0x0;
    param_1 = param_1 + 8;
    param_2 = param_2 - 1;
  } while (param_2 != 0);
  return;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `100177a2` | __VEC_memzero |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001771a` | `55` | `PUSH EBP` |
| `1001771b` | `8b ec` | `MOV EBP,ESP` |
| `1001771d` | `83 ec 04` | `SUB ESP,0x4` |
| `10017720` | `89 7d fc` | `MOV dword ptr [EBP + -0x4],EDI` |
| `10017723` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10017726` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10017729` | `c1 e9 07` | `SHR ECX,0x7` |
| `1001772c` | `66 0f ef c0` | `PXOR XMM0,XMM0` |
| `10017730` | `eb 08` | `JMP 0x1001773a` |
| `1001773a` | `66 0f 7f 07` | `MOVDQA xmmword ptr [EDI],XMM0` |
| `1001773e` | `66 0f 7f 47 10` | `MOVDQA xmmword ptr [EDI + 0x10],XMM0` |
| `10017743` | `66 0f 7f 47 20` | `MOVDQA xmmword ptr [EDI + 0x20],XMM0` |
| `10017748` | `66 0f 7f 47 30` | `MOVDQA xmmword ptr [EDI + 0x30],XMM0` |
| `1001774d` | `66 0f 7f 47 40` | `MOVDQA xmmword ptr [EDI + 0x40],XMM0` |
| `10017752` | `66 0f 7f 47 50` | `MOVDQA xmmword ptr [EDI + 0x50],XMM0` |
| `10017757` | `66 0f 7f 47 60` | `MOVDQA xmmword ptr [EDI + 0x60],XMM0` |
| `1001775c` | `66 0f 7f 47 70` | `MOVDQA xmmword ptr [EDI + 0x70],XMM0` |
| `10017761` | `8d bf 80 00 00 00` | `LEA EDI,[EDI + 0x80]` |
| `10017767` | `49` | `DEC ECX` |
| `10017768` | `75 d0` | `JNZ 0x1001773a` |
| `1001776a` | `8b 7d fc` | `MOV EDI,dword ptr [EBP + -0x4]` |
| `1001776d` | `8b e5` | `MOV ESP,EBP` |
| `1001776f` | `5d` | `POP EBP` |
| `10017770` | `c3` | `RET` |
