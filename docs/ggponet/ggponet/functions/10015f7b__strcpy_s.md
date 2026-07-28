# 10015f7b `_strcpy_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10015f7b |
| `name` | _strcpy_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl _strcpy_s(char * _Dst, rsize_t _SizeInBytes, char * _Src) |
| `size_bytes` | 104 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strcpy_s |

## Decompiled C

```c

/* Library Function - Single Match
    _strcpy_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl _strcpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  errno_t eVar4;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    pcVar3 = _Dst;
    if (_Src != (char *)0x0) {
      do {
        cVar1 = *_Src;
        *pcVar3 = cVar1;
        _Src = _Src + 1;
        if (cVar1 == '\0') break;
        _SizeInBytes = _SizeInBytes - 1;
        pcVar3 = pcVar3 + 1;
      } while (_SizeInBytes != 0);
      if (_SizeInBytes != 0) {
        return 0;
      }
      *_Dst = '\0';
      piVar2 = __errno();
      eVar4 = 0x22;
      *piVar2 = 0x22;
      goto LAB_10015f9d;
    }
    *_Dst = '\0';
  }
  piVar2 = __errno();
  eVar4 = 0x16;
  *piVar2 = 0x16;
LAB_10015f9d:
  __invalid_parameter(0,0,0,0,0);
  return eVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10015f93` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10015fa2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10015fce` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `10016f62` | __NMSG_WRITE |
| `10016fa4` | __NMSG_WRITE |
| `1001e5d8` | ___crtsetenv |
| `1001f9ea` | __strdup |
| `10011165` | std::exception::exception |
| `100111e1` | std::exception::exception |
| `1001a67c` | __setenvp |
| `1002a3be` | __cftoe2_l |
| `1002affa` | __fltout2 |
| `1002c430` | $I10_OUTPUT |
| `1002c45c` | $I10_OUTPUT |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10015f7b` | `8b ff` | `MOV EDI,EDI` |
| `10015f7d` | `55` | `PUSH EBP` |
| `10015f7e` | `8b ec` | `MOV EBP,ESP` |
| `10015f80` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `10015f83` | `53` | `PUSH EBX` |
| `10015f84` | `33 db` | `XOR EBX,EBX` |
| `10015f86` | `56` | `PUSH ESI` |
| `10015f87` | `57` | `PUSH EDI` |
| `10015f88` | `3b cb` | `CMP ECX,EBX` |
| `10015f8a` | `74 07` | `JZ 0x10015f93` |
| `10015f8c` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `10015f8f` | `3b fb` | `CMP EDI,EBX` |
| `10015f91` | `77 1b` | `JA 0x10015fae` |
| `10015f93` | `e8 71 f1 ff ff` | `CALL 0x10015109` |
| `10015f98` | `6a 16` | `PUSH 0x16` |
| `10015f9a` | `5e` | `POP ESI` |
| `10015f9b` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10015f9d` | `53` | `PUSH EBX` |
| `10015f9e` | `53` | `PUSH EBX` |
| `10015f9f` | `53` | `PUSH EBX` |
| `10015fa0` | `53` | `PUSH EBX` |
| `10015fa1` | `53` | `PUSH EBX` |
| `10015fa2` | `e8 08 b7 ff ff` | `CALL 0x100116af` |
| `10015fa7` | `83 c4 14` | `ADD ESP,0x14` |
| `10015faa` | `8b c6` | `MOV EAX,ESI` |
| `10015fac` | `eb 30` | `JMP 0x10015fde` |
| `10015fae` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `10015fb1` | `3b f3` | `CMP ESI,EBX` |
| `10015fb3` | `75 04` | `JNZ 0x10015fb9` |
| `10015fb5` | `88 19` | `MOV byte ptr [ECX],BL` |
| `10015fb7` | `eb da` | `JMP 0x10015f93` |
| `10015fb9` | `8b d1` | `MOV EDX,ECX` |
| `10015fbb` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `10015fbd` | `88 02` | `MOV byte ptr [EDX],AL` |
| `10015fbf` | `42` | `INC EDX` |
| `10015fc0` | `46` | `INC ESI` |
| `10015fc1` | `3a c3` | `CMP AL,BL` |
| `10015fc3` | `74 03` | `JZ 0x10015fc8` |
| `10015fc5` | `4f` | `DEC EDI` |
| `10015fc6` | `75 f3` | `JNZ 0x10015fbb` |
| `10015fc8` | `3b fb` | `CMP EDI,EBX` |
| `10015fca` | `75 10` | `JNZ 0x10015fdc` |
| `10015fcc` | `88 19` | `MOV byte ptr [ECX],BL` |
| `10015fce` | `e8 36 f1 ff ff` | `CALL 0x10015109` |
| `10015fd3` | `6a 22` | `PUSH 0x22` |
| `10015fd5` | `59` | `POP ECX` |
| `10015fd6` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `10015fd8` | `8b f1` | `MOV ESI,ECX` |
| `10015fda` | `eb c1` | `JMP 0x10015f9d` |
| `10015fdc` | `33 c0` | `XOR EAX,EAX` |
| `10015fde` | `5f` | `POP EDI` |
| `10015fdf` | `5e` | `POP ESI` |
| `10015fe0` | `5b` | `POP EBX` |
| `10015fe1` | `5d` | `POP EBP` |
| `10015fe2` | `c3` | `RET` |
