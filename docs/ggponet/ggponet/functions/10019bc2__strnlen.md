# 10019bc2 `_strnlen`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019bc2 |
| `name` | _strnlen |
| `namespace` | Global |
| `signature` | size_t __cdecl _strnlen(char * _Str, size_t _MaxCount) |
| `size_bytes` | 29 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strnlen |

## Decompiled C

```c

/* Library Function - Single Match
    _strnlen
   
   Library: Visual Studio 2008 Release */

size_t __cdecl _strnlen(char *_Str,size_t _MaxCount)

{
  uint uVar1;
  
  uVar1 = 0;
  if (_MaxCount != 0) {
    do {
      if (*_Str == '\0') {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
      _Str = _Str + 1;
    } while (uVar1 < _MaxCount);
  }
  return uVar1;
}
```

## Calls

No direct call references identified by Ghidra.

## Callers

| From | Function |
| --- | --- |
| `10012d91` | _getenv |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019bc2` | `8b ff` | `MOV EDI,EDI` |
| `10019bc4` | `55` | `PUSH EBP` |
| `10019bc5` | `8b ec` | `MOV EBP,ESP` |
| `10019bc7` | `33 c0` | `XOR EAX,EAX` |
| `10019bc9` | `39 45 0c` | `CMP dword ptr [EBP + 0xc],EAX` |
| `10019bcc` | `76 0f` | `JBE 0x10019bdd` |
| `10019bce` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10019bd1` | `80 39 00` | `CMP byte ptr [ECX],0x0` |
| `10019bd4` | `74 07` | `JZ 0x10019bdd` |
| `10019bd6` | `40` | `INC EAX` |
| `10019bd7` | `41` | `INC ECX` |
| `10019bd8` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `10019bdb` | `72 f4` | `JC 0x10019bd1` |
| `10019bdd` | `5d` | `POP EBP` |
| `10019bde` | `c3` | `RET` |
