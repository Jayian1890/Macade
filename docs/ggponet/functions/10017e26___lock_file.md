# 10017e26 `__lock_file`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10017e26 |
| `name` | __lock_file |
| `namespace` | Global |
| `signature` | void __cdecl __lock_file(FILE * _File) |
| `size_bytes` | 65 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __lock_file |

## Decompiled C

```c

/* Library Function - Single Match
    __lock_file
   
   Library: Visual Studio 2008 Release */

void __cdecl __lock_file(FILE *_File)

{
  if ((_File < &PTR_DAT_10037800) || ((FILE *)&DAT_10037a60 < _File)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  }
  else {
    __lock(((int)(_File + -0x801bc0) >> 5) + 0x10);
    _File->_flag = _File->_flag | 0x8000;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017e4b` | `10016203` | `UNCONDITIONAL_CALL` | __lock | `10016203` |
| `10017e5e` | `EXTERNAL:00000043` | `COMPUTED_CALL` | KERNEL32.DLL::EnterCriticalSection | `` |

## Callers

| From | Function |
| --- | --- |
| `100120a6` | _fprintf |
| `100121c2` | vfprintf_helper |
| `10014632` | _fflush |
| `10011dac` | _fread_s |
| `10011ece` | _fclose |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017e2f` | `10037800` | `DATA` | PTR_DAT_10037800 |
| `10017e38` | `10037a60` | `DATA` | DAT_10037a60 |
| `10017e5e` | `1002e0c4` | `READ` | PTR_EnterCriticalSection_1002e0c4 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10017e26` | `8b ff` | `MOV EDI,EDI` |
| `10017e28` | `55` | `PUSH EBP` |
| `10017e29` | `8b ec` | `MOV EBP,ESP` |
| `10017e2b` | `56` | `PUSH ESI` |
| `10017e2c` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10017e2f` | `b8 00 78 03 10` | `MOV EAX,0x10037800` |
| `10017e34` | `3b f0` | `CMP ESI,EAX` |
| `10017e36` | `72 22` | `JC 0x10017e5a` |
| `10017e38` | `81 fe 60 7a 03 10` | `CMP ESI,0x10037a60` |
| `10017e3e` | `77 1a` | `JA 0x10017e5a` |
| `10017e40` | `8b ce` | `MOV ECX,ESI` |
| `10017e42` | `2b c8` | `SUB ECX,EAX` |
| `10017e44` | `c1 f9 05` | `SAR ECX,0x5` |
| `10017e47` | `83 c1 10` | `ADD ECX,0x10` |
| `10017e4a` | `51` | `PUSH ECX` |
| `10017e4b` | `e8 b3 e3 ff ff` | `CALL 0x10016203` |
| `10017e50` | `81 4e 0c 00 80 00 00` | `OR dword ptr [ESI + 0xc],0x8000` |
| `10017e57` | `59` | `POP ECX` |
| `10017e58` | `eb 0a` | `JMP 0x10017e64` |
| `10017e5a` | `83 c6 20` | `ADD ESI,0x20` |
| `10017e5d` | `56` | `PUSH ESI` |
| `10017e5e` | `ff 15 c4 e0 02 10` | `CALL dword ptr [0x1002e0c4]` |
| `10017e64` | `5e` | `POP ESI` |
| `10017e65` | `5d` | `POP EBP` |
| `10017e66` | `c3` | `RET` |
