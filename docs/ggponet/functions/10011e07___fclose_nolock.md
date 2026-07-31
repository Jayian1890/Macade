# 10011e07 `__fclose_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011e07 |
| `name` | __fclose_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __fclose_nolock(FILE * _File) |
| `size_bytes` | 119 |
| `stack_frame_size` | 8 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fclose_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __fclose_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __fclose_nolock(FILE *_File)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = -1;
  if (_File == (FILE *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar3 = -1;
  }
  else {
    if ((_File->_flag & 0x83) != 0) {
      iVar3 = __flush(_File);
      __freebuf(_File);
      iVar2 = __fileno(_File);
      iVar2 = __close(iVar2);
      if (iVar2 < 0) {
        iVar3 = -1;
      }
      else if (_File->_tmpfname != (char *)0x0) {
        _free(_File->_tmpfname);
        _File->_tmpfname = (char *)0x0;
      }
    }
    _File->_flag = 0;
  }
  return iVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011e1b` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011e2b` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10011e3e` | `10014489` | `UNCONDITIONAL_CALL` | __flush | `10014489` |
| `10011e46` | `10018de0` | `UNCONDITIONAL_CALL` | __freebuf | `10018de0` |
| `10011e4c` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `10011e52` | `10018d13` | `UNCONDITIONAL_CALL` | __close | `10018d13` |
| `10011e6b` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |

## Callers

| From | Function |
| --- | --- |
| `10011ed8` | _fclose |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011e07` | `8b ff` | `MOV EDI,EDI` |
| `10011e09` | `55` | `PUSH EBP` |
| `10011e0a` | `8b ec` | `MOV EBP,ESP` |
| `10011e0c` | `53` | `PUSH EBX` |
| `10011e0d` | `56` | `PUSH ESI` |
| `10011e0e` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `10011e11` | `57` | `PUSH EDI` |
| `10011e12` | `33 ff` | `XOR EDI,EDI` |
| `10011e14` | `83 cb ff` | `OR EBX,0xffffffff` |
| `10011e17` | `3b f7` | `CMP ESI,EDI` |
| `10011e19` | `75 1c` | `JNZ 0x10011e37` |
| `10011e1b` | `e8 e9 32 00 00` | `CALL 0x10015109` |
| `10011e20` | `57` | `PUSH EDI` |
| `10011e21` | `57` | `PUSH EDI` |
| `10011e22` | `57` | `PUSH EDI` |
| `10011e23` | `57` | `PUSH EDI` |
| `10011e24` | `57` | `PUSH EDI` |
| `10011e25` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011e2b` | `e8 7f f8 ff ff` | `CALL 0x100116af` |
| `10011e30` | `83 c4 14` | `ADD ESP,0x14` |
| `10011e33` | `0b c3` | `OR EAX,EBX` |
| `10011e35` | `eb 42` | `JMP 0x10011e79` |
| `10011e37` | `f6 46 0c 83` | `TEST byte ptr [ESI + 0xc],0x83` |
| `10011e3b` | `74 37` | `JZ 0x10011e74` |
| `10011e3d` | `56` | `PUSH ESI` |
| `10011e3e` | `e8 46 26 00 00` | `CALL 0x10014489` |
| `10011e43` | `56` | `PUSH ESI` |
| `10011e44` | `8b d8` | `MOV EBX,EAX` |
| `10011e46` | `e8 95 6f 00 00` | `CALL 0x10018de0` |
| `10011e4b` | `56` | `PUSH ESI` |
| `10011e4c` | `e8 f4 6d 00 00` | `CALL 0x10018c45` |
| `10011e51` | `50` | `PUSH EAX` |
| `10011e52` | `e8 bc 6e 00 00` | `CALL 0x10018d13` |
| `10011e57` | `83 c4 10` | `ADD ESP,0x10` |
| `10011e5a` | `85 c0` | `TEST EAX,EAX` |
| `10011e5c` | `7d 05` | `JGE 0x10011e63` |
| `10011e5e` | `83 cb ff` | `OR EBX,0xffffffff` |
| `10011e61` | `eb 11` | `JMP 0x10011e74` |
| `10011e63` | `8b 46 1c` | `MOV EAX,dword ptr [ESI + 0x1c]` |
| `10011e66` | `3b c7` | `CMP EAX,EDI` |
| `10011e68` | `74 0a` | `JZ 0x10011e74` |
| `10011e6a` | `50` | `PUSH EAX` |
| `10011e6b` | `e8 d1 f3 ff ff` | `CALL 0x10011241` |
| `10011e70` | `59` | `POP ECX` |
| `10011e71` | `89 7e 1c` | `MOV dword ptr [ESI + 0x1c],EDI` |
| `10011e74` | `89 7e 0c` | `MOV dword ptr [ESI + 0xc],EDI` |
| `10011e77` | `8b c3` | `MOV EAX,EBX` |
| `10011e79` | `5f` | `POP EDI` |
| `10011e7a` | `5e` | `POP ESI` |
| `10011e7b` | `5b` | `POP EBX` |
| `10011e7c` | `5d` | `POP EBP` |
| `10011e7d` | `c3` | `RET` |
