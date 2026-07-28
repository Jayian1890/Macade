# 1001228e `FID_conflict:_vfprintf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001228e |
| `name` | FID_conflict:_vfprintf |
| `namespace` | Global |
| `signature` | int __cdecl FID_conflict:_vfprintf(FILE * _File, char * _Format, va_list _ArgList) |
| `size_bytes` | 31 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | FID_conflict:_vfprintf, __vfprintf_p, _vfprintf, _vfprintf_s |

## Decompiled C

```c

/* Library Function - Multiple Matches With Different Base Names
    __vfprintf_p
    _vfprintf
    _vfprintf_s
   
   Library: Visual Studio 2008 Release */

int __cdecl FID_conflict__vfprintf(FILE *_File,char *_Format,va_list _ArgList)

{
  int iVar1;
  
  iVar1 = vfprintf_helper(__output_l,_File,_Format,0,_ArgList);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100122a3` | `10012173` | `UNCONDITIONAL_CALL` | vfprintf_helper | `10012173` |

## Callers

| From | Function |
| --- | --- |
| `10021f36` | FUN_10021ec0 |
| `10027425` | FUN_10027400 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001229e` | `100153e3` | `DATA` | __output_l |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001228e` | `8b ff` | `MOV EDI,EDI` |
| `10012290` | `55` | `PUSH EBP` |
| `10012291` | `8b ec` | `MOV EBP,ESP` |
| `10012293` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10012296` | `6a 00` | `PUSH 0x0` |
| `10012298` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001229b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001229e` | `68 e3 53 01 10` | `PUSH 0x100153e3` |
| `100122a3` | `e8 cb fe ff ff` | `CALL 0x10012173` |
| `100122a8` | `83 c4 14` | `ADD ESP,0x14` |
| `100122ab` | `5d` | `POP EBP` |
| `100122ac` | `c3` | `RET` |
