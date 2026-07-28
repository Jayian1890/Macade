# 1002a12b `__forcdecpt_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002a12b |
| `name` | __forcdecpt_l |
| `namespace` | Global |
| `signature` | void __cdecl __forcdecpt_l(char * _Buf, _locale_t _Locale) |
| `size_bytes` | 115 |
| `stack_frame_size` | 32 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __forcdecpt_l |

## Decompiled C

```c

/* Library Function - Single Match
    __forcdecpt_l
   
   Library: Visual Studio 2008 Release */

void __cdecl __forcdecpt_l(char *_Buf,_locale_t _Locale)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,_Locale);
  iVar3 = _tolower((int)*_Buf);
  bVar4 = iVar3 == 0x65;
  while (!bVar4) {
    _Buf = _Buf + 1;
    iVar3 = _isdigit((uint)(byte)*_Buf);
    bVar4 = iVar3 == 0;
  }
  iVar3 = _tolower((int)*_Buf);
  if (iVar3 == 0x78) {
    _Buf = _Buf + 2;
  }
  bVar2 = *_Buf;
  *_Buf = *(byte *)**(undefined4 **)(local_14[0] + 0xbc);
  do {
    _Buf = _Buf + 1;
    bVar1 = *_Buf;
    *_Buf = bVar2;
    bVar2 = bVar1;
  } while (*_Buf != 0);
  if (local_8 != '\0') {
    *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
  }
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002a13a` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1002a146` | `1001fc42` | `UNCONDITIONAL_CALL` | _tolower | `1001fc42` |
| `1002a155` | `1001cbc6` | `UNCONDITIONAL_CALL` | _isdigit | `1001cbc6` |
| `1002a163` | `1001fc42` | `UNCONDITIONAL_CALL` | _tolower | `1001fc42` |

## Callers

| From | Function |
| --- | --- |
| `1002a2c1` | __forcdecpt |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002a12b` | `8b ff` | `MOV EDI,EDI` |
| `1002a12d` | `55` | `PUSH EBP` |
| `1002a12e` | `8b ec` | `MOV EBP,ESP` |
| `1002a130` | `83 ec 10` | `SUB ESP,0x10` |
| `1002a133` | `56` | `PUSH ESI` |
| `1002a134` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1002a137` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1002a13a` | `e8 77 b1 fe ff` | `CALL 0x100152b6` |
| `1002a13f` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1002a142` | `0f be 06` | `MOVSX EAX,byte ptr [ESI]` |
| `1002a145` | `50` | `PUSH EAX` |
| `1002a146` | `e8 f7 5a ff ff` | `CALL 0x1001fc42` |
| `1002a14b` | `83 f8 65` | `CMP EAX,0x65` |
| `1002a14e` | `eb 0c` | `JMP 0x1002a15c` |
| `1002a150` | `46` | `INC ESI` |
| `1002a151` | `0f b6 06` | `MOVZX EAX,byte ptr [ESI]` |
| `1002a154` | `50` | `PUSH EAX` |
| `1002a155` | `e8 6c 2a ff ff` | `CALL 0x1001cbc6` |
| `1002a15a` | `85 c0` | `TEST EAX,EAX` |
| `1002a15c` | `59` | `POP ECX` |
| `1002a15d` | `75 f1` | `JNZ 0x1002a150` |
| `1002a15f` | `0f be 06` | `MOVSX EAX,byte ptr [ESI]` |
| `1002a162` | `50` | `PUSH EAX` |
| `1002a163` | `e8 da 5a ff ff` | `CALL 0x1001fc42` |
| `1002a168` | `59` | `POP ECX` |
| `1002a169` | `83 f8 78` | `CMP EAX,0x78` |
| `1002a16c` | `75 02` | `JNZ 0x1002a170` |
| `1002a16e` | `46` | `INC ESI` |
| `1002a16f` | `46` | `INC ESI` |
| `1002a170` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002a173` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002a179` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002a17b` | `8a 06` | `MOV AL,byte ptr [ESI]` |
| `1002a17d` | `8a 09` | `MOV CL,byte ptr [ECX]` |
| `1002a17f` | `88 0e` | `MOV byte ptr [ESI],CL` |
| `1002a181` | `46` | `INC ESI` |
| `1002a182` | `8a 0e` | `MOV CL,byte ptr [ESI]` |
| `1002a184` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1002a186` | `8a c1` | `MOV AL,CL` |
| `1002a188` | `8a 0e` | `MOV CL,byte ptr [ESI]` |
| `1002a18a` | `46` | `INC ESI` |
| `1002a18b` | `84 c9` | `TEST CL,CL` |
| `1002a18d` | `75 f3` | `JNZ 0x1002a182` |
| `1002a18f` | `5e` | `POP ESI` |
| `1002a190` | `38 4d fc` | `CMP byte ptr [EBP + -0x4],CL` |
| `1002a193` | `74 07` | `JZ 0x1002a19c` |
| `1002a195` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002a198` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1002a19c` | `c9` | `LEAVE` |
| `1002a19d` | `c3` | `RET` |
