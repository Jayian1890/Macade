# 10018ead `__ftbuf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018ead |
| `name` | __ftbuf |
| `namespace` | Global |
| `signature` | void __cdecl __ftbuf(int _Flag, FILE * _File) |
| `size_bytes` | 52 |
| `stack_frame_size` | 12 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __ftbuf |

## Decompiled C

```c

/* Library Function - Single Match
    __ftbuf
   
   Library: Visual Studio 2008 Release */

void __cdecl __ftbuf(int _Flag,FILE *_File)

{
  if ((_Flag != 0) && ((_File->_flag & 0x1000U) != 0)) {
    __flush(_File);
    _File->_flag = _File->_flag & 0xffffeeff;
    _File->_bufsiz = 0;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018ec6` | `10014489` | `UNCONDITIONAL_CALL` | __flush | `10014489` |

## Callers

| From | Function |
| --- | --- |
| `1001214c` | _fprintf |
| `10012267` | vfprintf_helper |
| `100123dd` | _puts |
| `10012011` | _printf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018ead` | `8b ff` | `MOV EDI,EDI` |
| `10018eaf` | `55` | `PUSH EBP` |
| `10018eb0` | `8b ec` | `MOV EBP,ESP` |
| `10018eb2` | `83 7d 08 00` | `CMP dword ptr [EBP + 0x8],0x0` |
| `10018eb6` | `74 27` | `JZ 0x10018edf` |
| `10018eb8` | `56` | `PUSH ESI` |
| `10018eb9` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `10018ebc` | `f7 46 0c 00 10 00 00` | `TEST dword ptr [ESI + 0xc],0x1000` |
| `10018ec3` | `74 19` | `JZ 0x10018ede` |
| `10018ec5` | `56` | `PUSH ESI` |
| `10018ec6` | `e8 be b5 ff ff` | `CALL 0x10014489` |
| `10018ecb` | `81 66 0c ff ee ff ff` | `AND dword ptr [ESI + 0xc],0xffffeeff` |
| `10018ed2` | `83 66 18 00` | `AND dword ptr [ESI + 0x18],0x0` |
| `10018ed6` | `83 26 00` | `AND dword ptr [ESI],0x0` |
| `10018ed9` | `83 66 08 00` | `AND dword ptr [ESI + 0x8],0x0` |
| `10018edd` | `59` | `POP ECX` |
| `10018ede` | `5e` | `POP ESI` |
| `10018edf` | `5d` | `POP EBP` |
| `10018ee0` | `c3` | `RET` |
