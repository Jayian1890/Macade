# 1002abe3 `__cfltcvt`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002abe3 |
| `name` | __cfltcvt |
| `namespace` | Global |
| `signature` | errno_t __cdecl __cfltcvt(double * arg, char * buffer, size_t sizeInBytes, int format, int precision, int caps) |
| `size_bytes` | 35 |
| `stack_frame_size` | 28 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cfltcvt |

## Decompiled C

```c

/* Library Function - Single Match
    __cfltcvt
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release,
   Visual Studio 2012 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  errno_t eVar1;
  
  eVar1 = __cfltcvt_l(arg,buffer,sizeInBytes,format,precision,caps,(_locale_t)0x0);
  return eVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002abfc` | `1002ab5b` | `UNCONDITIONAL_CALL` | __cfltcvt_l | `1002ab5b` |

## Callers

No direct callers identified by Ghidra.

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002abe3` | `8b ff` | `MOV EDI,EDI` |
| `1002abe5` | `55` | `PUSH EBP` |
| `1002abe6` | `8b ec` | `MOV EBP,ESP` |
| `1002abe8` | `6a 00` | `PUSH 0x0` |
| `1002abea` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1002abed` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1002abf0` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1002abf3` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1002abf6` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002abf9` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1002abfc` | `e8 5a ff ff ff` | `CALL 0x1002ab5b` |
| `1002ac01` | `83 c4 1c` | `ADD ESP,0x1c` |
| `1002ac04` | `5d` | `POP EBP` |
| `1002ac05` | `c3` | `RET` |
