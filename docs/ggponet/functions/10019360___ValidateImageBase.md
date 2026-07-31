# 10019360 `__ValidateImageBase`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019360 |
| `name` | __ValidateImageBase |
| `namespace` | Global |
| `signature` | BOOL __cdecl __ValidateImageBase(PBYTE pImageBase) |
| `size_bytes` | 53 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __ValidateImageBase |

## Decompiled C

```c

/* Library Function - Single Match
    __ValidateImageBase
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

BOOL __cdecl __ValidateImageBase(PBYTE pImageBase)

{
  if ((*(short *)pImageBase == 0x5a4d) &&
     (*(int *)(pImageBase + *(int *)(pImageBase + 0x3c)) == 0x4550)) {
    return (uint)((short)*(int *)((int)(pImageBase + *(int *)(pImageBase + 0x3c)) + 0x18) == 0x10b);
  }
  return 0;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10019431` | __IsNonwritableInCurrentImage |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019360` | `8b ff` | `MOV EDI,EDI` |
| `10019362` | `55` | `PUSH EBP` |
| `10019363` | `8b ec` | `MOV EBP,ESP` |
| `10019365` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10019368` | `b8 4d 5a 00 00` | `MOV EAX,0x5a4d` |
| `1001936d` | `66 39 01` | `CMP word ptr [ECX],AX` |
| `10019370` | `74 04` | `JZ 0x10019376` |
| `10019372` | `33 c0` | `XOR EAX,EAX` |
| `10019374` | `5d` | `POP EBP` |
| `10019375` | `c3` | `RET` |
| `10019376` | `8b 41 3c` | `MOV EAX,dword ptr [ECX + 0x3c]` |
| `10019379` | `03 c1` | `ADD EAX,ECX` |
| `1001937b` | `81 38 50 45 00 00` | `CMP dword ptr [EAX],0x4550` |
| `10019381` | `75 ef` | `JNZ 0x10019372` |
| `10019383` | `33 d2` | `XOR EDX,EDX` |
| `10019385` | `b9 0b 01 00 00` | `MOV ECX,0x10b` |
| `1001938a` | `66 39 48 18` | `CMP word ptr [EAX + 0x18],CX` |
| `1001938e` | `0f 94 c2` | `SETZ DL` |
| `10019391` | `8b c2` | `MOV EAX,EDX` |
| `10019393` | `5d` | `POP EBP` |
| `10019394` | `c3` | `RET` |
