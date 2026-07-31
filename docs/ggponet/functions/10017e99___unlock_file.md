# 10017e99 `__unlock_file`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017e99 |
| `name` | __unlock_file |
| `namespace` | Global |
| `signature` | void __cdecl __unlock_file(FILE * _File) |
| `size_bytes` | 60 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __unlock_file |

## Decompiled C

```c

/* Library Function - Single Match
    __unlock_file
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)((int)&DAT_100377fc + 3U) < _File) && (_File < (FILE *)0x10037a61)) {
    _File->_flag = _File->_flag & 0xffff7fff;
    FUN_10016129(((int)(_File + -0x801bc0) >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017ec1` | `10016129` | `UNCONDITIONAL_CALL` | FUN_10016129 | `10016129` |
| `10017ecd` | `EXTERNAL:00000042` | `COMPUTED_CALL` | KERNEL32.DLL::LeaveCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `10011b2c` | FUN_10011b29 |
| `1001216c` | FUN_10012169 |
| `10012287` | FUN_10012284 |
| `1001465f` | FUN_1001465c |
| `10011de3` | FUN_10011de0 |
| `10011ef3` | FUN_10011ef2 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017ea1` | `10037800` | `DATA` | PTR_DAT_10037800 |
| `10017eaa` | `10037a60` | `DATA` | DAT_10037a60 |
| `10017ecd` | `1002e0c0` | `READ` | PTR_LeaveCriticalSection_1002e0c0 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017e99` | `8b ff` | `MOV EDI,EDI` |
| `10017e9b` | `55` | `PUSH EBP` |
| `10017e9c` | `8b ec` | `MOV EBP,ESP` |
| `10017e9e` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10017ea1` | `b9 00 78 03 10` | `MOV ECX,0x10037800` |
| `10017ea6` | `3b c1` | `CMP EAX,ECX` |
| `10017ea8` | `72 1f` | `JC 0x10017ec9` |
| `10017eaa` | `3d 60 7a 03 10` | `CMP EAX,0x10037a60` |
| `10017eaf` | `77 18` | `JA 0x10017ec9` |
| `10017eb1` | `81 60 0c ff 7f ff ff` | `AND dword ptr [EAX + 0xc],0xffff7fff` |
| `10017eb8` | `2b c1` | `SUB EAX,ECX` |
| `10017eba` | `c1 f8 05` | `SAR EAX,0x5` |
| `10017ebd` | `83 c0 10` | `ADD EAX,0x10` |
| `10017ec0` | `50` | `PUSH EAX` |
| `10017ec1` | `e8 63 e2 ff ff` | `CALL 0x10016129` |
| `10017ec6` | `59` | `POP ECX` |
| `10017ec7` | `5d` | `POP EBP` |
| `10017ec8` | `c3` | `RET` |
| `10017ec9` | `83 c0 20` | `ADD EAX,0x20` |
| `10017ecc` | `50` | `PUSH EAX` |
| `10017ecd` | `ff 15 c0 e0 02 10` | `CALL dword ptr [0x1002e0c0]` |
| `10017ed3` | `5d` | `POP EBP` |
| `10017ed4` | `c3` | `RET` |
