# 10018de0 `__freebuf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10018de0 |
| `name` | __freebuf |
| `namespace` | Global |
| `signature` | void __cdecl __freebuf(FILE * _File) |
| `size_bytes` | 49 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __freebuf |

## Decompiled C

```c

/* Library Function - Single Match
    __freebuf
   
   Library: Visual Studio 2008 Release */

void __cdecl __freebuf(FILE *_File)

{
  if (((_File->_flag & 0x83U) != 0) && ((_File->_flag & 8U) != 0)) {
    _free(_File->_base);
    _File->_flag = _File->_flag & 0xfffffbf7;
    _File->_ptr = (char *)0x0;
    _File->_base = (char *)0x0;
    _File->_cnt = 0;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10018df7` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `10011e46` | __fclose_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10018de0` | `8b ff` | `MOV EDI,EDI` |
| `10018de2` | `55` | `PUSH EBP` |
| `10018de3` | `8b ec` | `MOV EBP,ESP` |
| `10018de5` | `56` | `PUSH ESI` |
| `10018de6` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10018de9` | `8b 46 0c` | `MOV EAX,dword ptr [ESI + 0xc]` |
| `10018dec` | `a8 83` | `TEST AL,0x83` |
| `10018dee` | `74 1e` | `JZ 0x10018e0e` |
| `10018df0` | `a8 08` | `TEST AL,0x8` |
| `10018df2` | `74 1a` | `JZ 0x10018e0e` |
| `10018df4` | `ff 76 08` | `PUSH dword ptr [ESI + 0x8]` |
| `10018df7` | `e8 45 84 ff ff` | `CALL 0x10011241` |
| `10018dfc` | `81 66 0c f7 fb ff ff` | `AND dword ptr [ESI + 0xc],0xfffffbf7` |
| `10018e03` | `33 c0` | `XOR EAX,EAX` |
| `10018e05` | `59` | `POP ECX` |
| `10018e06` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `10018e08` | `89 46 08` | `MOV dword ptr [ESI + 0x8],EAX` |
| `10018e0b` | `89 46 04` | `MOV dword ptr [ESI + 0x4],EAX` |
| `10018e0e` | `5e` | `POP ESI` |
| `10018e0f` | `5d` | `POP EBP` |
| `10018e10` | `c3` | `RET` |
