# 10011dea `_fread`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011dea |
| `name` | _fread |
| `namespace` | Global |
| `signature` | size_t __cdecl _fread(void * _DstBuf, size_t _ElementSize, size_t _Count, FILE * _File) |
| `size_bytes` | 29 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _fread |

## Decompiled C

```c

/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 2008 Release */

size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  sVar1 = _fread_s(_DstBuf,0xffffffff,_ElementSize,_Count,_File);
  return sVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011dfd` | `10011d54` | `UNCONDITIONAL_CALL` | _fread_s | `10011d54` |

## Callers

| From | Function |
| --- | --- |
| `10027c39` | FUN_10027b70 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011dea` | `8b ff` | `MOV EDI,EDI` |
| `10011dec` | `55` | `PUSH EBP` |
| `10011ded` | `8b ec` | `MOV EBP,ESP` |
| `10011def` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `10011df2` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10011df5` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10011df8` | `6a ff` | `PUSH -0x1` |
| `10011dfa` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10011dfd` | `e8 52 ff ff ff` | `CALL 0x10011d54` |
| `10011e02` | `83 c4 14` | `ADD ESP,0x14` |
| `10011e05` | `5d` | `POP EBP` |
| `10011e06` | `c3` | `RET` |
