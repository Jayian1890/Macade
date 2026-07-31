# 1002a19e `__cropzeros_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a19e |
| `name` | __cropzeros_l |
| `namespace` | Global |
| `signature` | void __cdecl __cropzeros_l(char * _Buf, _locale_t _Locale) |
| `size_bytes` | 130 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __cropzeros_l |

## Decompiled C

```c

/* Library Function - Single Match
    __cropzeros_l
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __cropzeros_l(char *_Buf,_locale_t _Locale)

{
  char *pcVar1;
  char cVar3;
  int local_14 [2];
  int local_c;
  char local_8;
  char *pcVar2;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,_Locale);
  cVar3 = *_Buf;
  if (cVar3 != '\0') {
    do {
      if (cVar3 == *(char *)**(undefined4 **)(local_14[0] + 0xbc)) break;
      _Buf = _Buf + 1;
      cVar3 = *_Buf;
    } while (cVar3 != '\0');
  }
  if (*_Buf != '\0') {
    do {
      _Buf = _Buf + 1;
      cVar3 = *_Buf;
      pcVar1 = _Buf;
      if ((cVar3 == '\0') || (cVar3 == 'e')) break;
    } while (cVar3 != 'E');
    do {
      pcVar2 = pcVar1;
      pcVar1 = pcVar2 + -1;
    } while (*pcVar1 == '0');
    if (*pcVar1 == *(char *)**(undefined4 **)(local_14[0] + 0xbc)) {
      pcVar1 = pcVar2 + -2;
    }
    do {
      cVar3 = *_Buf;
      pcVar1 = pcVar1 + 1;
      _Buf = _Buf + 1;
      *pcVar1 = cVar3;
    } while (cVar3 != '\0');
  }
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a1ad` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |

## Callers

| From | Function |
| --- | --- |
| `1002a2d4` | __cropzeros |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a19e` | `8b ff` | `MOV EDI,EDI` |
| `1002a1a0` | `55` | `PUSH EBP` |
| `1002a1a1` | `8b ec` | `MOV EBP,ESP` |
| `1002a1a3` | `83 ec 10` | `SUB ESP,0x10` |
| `1002a1a6` | `56` | `PUSH ESI` |
| `1002a1a7` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002a1aa` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1002a1ad` | `e8 04 b1 fe ff` | `CALL 0x100152b6` |
| `1002a1b2` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002a1b5` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a1b7` | `8b 75 f0` | `MOV ESI,dword ptr [EBP + -0x10]` |
| `1002a1ba` | `84 c9` | `TEST CL,CL` |
| `1002a1bc` | `74 15` | `JZ 0x1002a1d3` |
| `1002a1be` | `8b 96 bc 00 00 00` | `MOV EDX,dword ptr [ESI + 0xbc]` |
| `1002a1c4` | `8b 12` | `MOV EDX,dword ptr [EDX]` |
| `1002a1c6` | `8a 12` | `MOV DL,byte ptr [EDX]` |
| `1002a1c8` | `3a ca` | `CMP CL,DL` |
| `1002a1ca` | `74 07` | `JZ 0x1002a1d3` |
| `1002a1cc` | `40` | `INC EAX` |
| `1002a1cd` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a1cf` | `84 c9` | `TEST CL,CL` |
| `1002a1d1` | `75 f5` | `JNZ 0x1002a1c8` |
| `1002a1d3` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a1d5` | `40` | `INC EAX` |
| `1002a1d6` | `84 c9` | `TEST CL,CL` |
| `1002a1d8` | `74 36` | `JZ 0x1002a210` |
| `1002a1da` | `eb 0b` | `JMP 0x1002a1e7` |
| `1002a1dc` | `80 f9 65` | `CMP CL,0x65` |
| `1002a1df` | `74 0c` | `JZ 0x1002a1ed` |
| `1002a1e1` | `80 f9 45` | `CMP CL,0x45` |
| `1002a1e4` | `74 07` | `JZ 0x1002a1ed` |
| `1002a1e6` | `40` | `INC EAX` |
| `1002a1e7` | `8a 08` | `MOV CL,byte ptr [EAX]` |
| `1002a1e9` | `84 c9` | `TEST CL,CL` |
| `1002a1eb` | `75 ef` | `JNZ 0x1002a1dc` |
| `1002a1ed` | `8b d0` | `MOV EDX,EAX` |
| `1002a1ef` | `48` | `DEC EAX` |
| `1002a1f0` | `80 38 30` | `CMP byte ptr [EAX],0x30` |
| `1002a1f3` | `74 fa` | `JZ 0x1002a1ef` |
| `1002a1f5` | `8b 8e bc 00 00 00` | `MOV ECX,dword ptr [ESI + 0xbc]` |
| `1002a1fb` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002a1fd` | `53` | `PUSH EBX` |
| `1002a1fe` | `8a 18` | `MOV BL,byte ptr [EAX]` |
| `1002a200` | `3a 19` | `CMP BL,byte ptr [ECX]` |
| `1002a202` | `5b` | `POP EBX` |
| `1002a203` | `75 01` | `JNZ 0x1002a206` |
| `1002a205` | `48` | `DEC EAX` |
| `1002a206` | `8a 0a` | `MOV CL,byte ptr [EDX]` |
| `1002a208` | `40` | `INC EAX` |
| `1002a209` | `42` | `INC EDX` |
| `1002a20a` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1002a20c` | `84 c9` | `TEST CL,CL` |
| `1002a20e` | `75 f6` | `JNZ 0x1002a206` |
| `1002a210` | `80 7d fc 00` | `CMP byte ptr [EBP + -0x4],0x0` |
| `1002a214` | `5e` | `POP ESI` |
| `1002a215` | `74 07` | `JZ 0x1002a21e` |
| `1002a217` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a21a` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a21e` | `c9` | `LEAVE` |
| `1002a21f` | `c3` | `RET` |
