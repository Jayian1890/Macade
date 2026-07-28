# 1001d58e `__sopen_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d58e |
| `name` | __sopen_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl __sopen_s(int * _FileHandle, char * _Filename, int _OpenFlag, int _ShareFlag, int _PermissionMode) |
| `size_bytes` | 32 |
| `stack_frame_size` | 24 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __sopen_s |

## Decompiled C

```c

/* Library Function - Single Match
    __sopen_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl
__sopen_s(int *_FileHandle,char *_Filename,int _OpenFlag,int _ShareFlag,int _PermissionMode)

{
  errno_t eVar1;
  
  eVar1 = __sopen_helper(_Filename,_OpenFlag,_ShareFlag,_PermissionMode,_FileHandle,1);
  return eVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d5a4` | `1001d4c2` | `UNCONDITIONAL_CALL` | __sopen_helper | `1001d4c2` |

## Callers

| From | Function |
| --- | --- |
| `10018198` | __openfile |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d58e` | `8b ff` | `MOV EDI,EDI` |
| `1001d590` | `55` | `PUSH EBP` |
| `1001d591` | `8b ec` | `MOV EBP,ESP` |
| `1001d593` | `6a 01` | `PUSH 0x1` |
| `1001d595` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d598` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001d59b` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001d59e` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d5a1` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d5a4` | `e8 19 ff ff ff` | `CALL 0x1001d4c2` |
| `1001d5a9` | `83 c4 18` | `ADD ESP,0x18` |
| `1001d5ac` | `5d` | `POP EBP` |
| `1001d5ad` | `c3` | `RET` |
