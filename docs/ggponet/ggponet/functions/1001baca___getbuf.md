# 1001baca `__getbuf`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001baca |
| `name` | __getbuf |
| `namespace` | Global |
| `signature` | void __cdecl __getbuf(FILE * _File) |
| `size_bytes` | 73 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __getbuf |

## Decompiled C

```c

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __getbuf
   
   Library: Visual Studio 2008 Release */

void __cdecl __getbuf(FILE *_File)

{
  char *pcVar1;
  
  _DAT_10039248 = _DAT_10039248 + 1;
  pcVar1 = __malloc_crt(0x1000);
  _File->_base = pcVar1;
  if (pcVar1 == (char *)0x0) {
    _File->_flag = _File->_flag | 4;
    _File->_base = (char *)&_File->_charbuf;
    _File->_bufsiz = 2;
  }
  else {
    _File->_flag = _File->_flag | 8;
    _File->_bufsiz = 0x1000;
  }
  _File->_cnt = 0;
  _File->_ptr = _File->_base;
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001bada` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |

## Callers

| From | Function |
| --- | --- |
| `100151f1` | __flsbuf |
| `100184b8` | __filbuf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001bacf` | `10039248` | `READ_WRITE` | DAT_10039248 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001baca` | `8b ff` | `MOV EDI,EDI` |
| `1001bacc` | `55` | `PUSH EBP` |
| `1001bacd` | `8b ec` | `MOV EBP,ESP` |
| `1001bacf` | `ff 05 48 92 03 10` | `INC dword ptr [0x10039248]` |
| `1001bad5` | `68 00 10 00 00` | `PUSH 0x1000` |
| `1001bada` | `e8 f0 e9 ff ff` | `CALL 0x1001a4cf` |
| `1001badf` | `59` | `POP ECX` |
| `1001bae0` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001bae3` | `89 41 08` | `MOV dword ptr [ECX + 0x8],EAX` |
| `1001bae6` | `85 c0` | `TEST EAX,EAX` |
| `1001bae8` | `74 0d` | `JZ 0x1001baf7` |
| `1001baea` | `83 49 0c 08` | `OR dword ptr [ECX + 0xc],0x8` |
| `1001baee` | `c7 41 18 00 10 00 00` | `MOV dword ptr [ECX + 0x18],0x1000` |
| `1001baf5` | `eb 11` | `JMP 0x1001bb08` |
| `1001baf7` | `83 49 0c 04` | `OR dword ptr [ECX + 0xc],0x4` |
| `1001bafb` | `8d 41 14` | `LEA EAX,[ECX + 0x14]` |
| `1001bafe` | `89 41 08` | `MOV dword ptr [ECX + 0x8],EAX` |
| `1001bb01` | `c7 41 18 02 00 00 00` | `MOV dword ptr [ECX + 0x18],0x2` |
| `1001bb08` | `8b 41 08` | `MOV EAX,dword ptr [ECX + 0x8]` |
| `1001bb0b` | `83 61 04 00` | `AND dword ptr [ECX + 0x4],0x0` |
| `1001bb0f` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `1001bb11` | `5d` | `POP EBP` |
| `1001bb12` | `c3` | `RET` |
