# 1002ae1d `__fptostr`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002ae1d |
| `name` | __fptostr |
| `namespace` | Global |
| `signature` | errno_t __cdecl __fptostr(char * _Buf, size_t _SizeInBytes, int _Digits, STRFLT _PtFlt) |
| `size_bytes` | 191 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fptostr |

## Decompiled C

```c

/* Library Function - Single Match
    __fptostr
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl __fptostr(char *_Buf,size_t _SizeInBytes,int _Digits,STRFLT _PtFlt)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  size_t sVar4;
  char cVar5;
  char *pcVar6;
  errno_t eVar7;
  
  pcVar6 = _PtFlt->mantissa;
  if ((_Buf == (char *)0x0) || (_SizeInBytes == 0)) {
    piVar1 = __errno();
    eVar7 = 0x16;
    *piVar1 = 0x16;
  }
  else {
    *_Buf = '\0';
    iVar2 = _Digits;
    if (_Digits < 1) {
      iVar2 = 0;
    }
    if (iVar2 + 1U < _SizeInBytes) {
      *_Buf = '0';
      pcVar3 = _Buf;
      for (; pcVar3 = pcVar3 + 1, 0 < _Digits; _Digits = _Digits + -1) {
        cVar5 = *pcVar6;
        if (cVar5 == '\0') {
          cVar5 = '0';
        }
        else {
          pcVar6 = pcVar6 + 1;
        }
        *pcVar3 = cVar5;
      }
      *pcVar3 = '\0';
      if ((-1 < _Digits) && ('4' < *pcVar6)) {
        while (pcVar3 = pcVar3 + -1, *pcVar3 == '9') {
          *pcVar3 = '0';
        }
        *pcVar3 = *pcVar3 + '\x01';
      }
      if (*_Buf == '1') {
        _PtFlt->decpt = _PtFlt->decpt + 1;
      }
      else {
        sVar4 = _strlen(_Buf + 1);
        _memmove(_Buf,_Buf + 1,sVar4 + 1);
      }
      return 0;
    }
    piVar1 = __errno();
    eVar7 = 0x22;
    *piVar1 = 0x22;
  }
  __invalid_parameter(0,0,0,0,0);
  return eVar7;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002ae34` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002ae43` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002ae6c` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002aec4` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1002aecd` | `10012740` | `UNCONDITIONAL_CALL` | _memmove | `10012740` |

## Callers

| From | Function |
| --- | --- |
| `1002a4e4` | __cftoe_l |
| `1002aa2d` | __cftof_l |
| `1002aae4` | __cftog_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002ae1d` | `8b ff` | `MOV EDI,EDI` |
| `1002ae1f` | `55` | `PUSH EBP` |
| `1002ae20` | `8b ec` | `MOV EBP,ESP` |
| `1002ae22` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `1002ae25` | `53` | `PUSH EBX` |
| `1002ae26` | `56` | `PUSH ESI` |
| `1002ae27` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1002ae2a` | `33 db` | `XOR EBX,EBX` |
| `1002ae2c` | `57` | `PUSH EDI` |
| `1002ae2d` | `8b 79 0c` | `MOV EDI,dword ptr [ECX + 0xc]` |
| `1002ae30` | `3b f3` | `CMP ESI,EBX` |
| `1002ae32` | `75 1e` | `JNZ 0x1002ae52` |
| `1002ae34` | `e8 d0 a2 fe ff` | `CALL 0x10015109` |
| `1002ae39` | `6a 16` | `PUSH 0x16` |
| `1002ae3b` | `5e` | `POP ESI` |
| `1002ae3c` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1002ae3e` | `53` | `PUSH EBX` |
| `1002ae3f` | `53` | `PUSH EBX` |
| `1002ae40` | `53` | `PUSH EBX` |
| `1002ae41` | `53` | `PUSH EBX` |
| `1002ae42` | `53` | `PUSH EBX` |
| `1002ae43` | `e8 67 68 fe ff` | `CALL 0x100116af` |
| `1002ae48` | `83 c4 14` | `ADD ESP,0x14` |
| `1002ae4b` | `8b c6` | `MOV EAX,ESI` |
| `1002ae4d` | `e9 85 00 00 00` | `JMP 0x1002aed7` |
| `1002ae52` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1002ae55` | `76 dd` | `JBE 0x1002ae34` |
| `1002ae57` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `1002ae5a` | `3b d3` | `CMP EDX,EBX` |
| `1002ae5c` | `88 1e` | `MOV byte ptr [ESI],BL` |
| `1002ae5e` | `7e 04` | `JLE 0x1002ae64` |
| `1002ae60` | `8b c2` | `MOV EAX,EDX` |
| `1002ae62` | `eb 02` | `JMP 0x1002ae66` |
| `1002ae64` | `33 c0` | `XOR EAX,EAX` |
| `1002ae66` | `40` | `INC EAX` |
| `1002ae67` | `39 45 0c` | `CMP dword ptr [EBP + 0xc],EAX` |
| `1002ae6a` | `77 0e` | `JA 0x1002ae7a` |
| `1002ae6c` | `e8 98 a2 fe ff` | `CALL 0x10015109` |
| `1002ae71` | `6a 22` | `PUSH 0x22` |
| `1002ae73` | `59` | `POP ECX` |
| `1002ae74` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1002ae76` | `8b f1` | `MOV ESI,ECX` |
| `1002ae78` | `eb c4` | `JMP 0x1002ae3e` |
| `1002ae7a` | `3b d3` | `CMP EDX,EBX` |
| `1002ae7c` | `c6 06 30` | `MOV byte ptr [ESI],0x30` |
| `1002ae7f` | `8d 46 01` | `LEA EAX,[ESI + 0x1]` |
| `1002ae82` | `7e 1a` | `JLE 0x1002ae9e` |
| `1002ae84` | `8a 0f` | `MOV CL,byte ptr [EDI]` |
| `1002ae86` | `3a cb` | `CMP CL,BL` |
| `1002ae88` | `74 06` | `JZ 0x1002ae90` |
| `1002ae8a` | `0f be c9` | `MOVSX ECX,CL` |
| `1002ae8d` | `47` | `INC EDI` |
| `1002ae8e` | `eb 03` | `JMP 0x1002ae93` |
| `1002ae90` | `6a 30` | `PUSH 0x30` |
| `1002ae92` | `59` | `POP ECX` |
| `1002ae93` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1002ae95` | `40` | `INC EAX` |
| `1002ae96` | `4a` | `DEC EDX` |
| `1002ae97` | `3b d3` | `CMP EDX,EBX` |
| `1002ae99` | `7f e9` | `JG 0x1002ae84` |
| `1002ae9b` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `1002ae9e` | `3b d3` | `CMP EDX,EBX` |
| `1002aea0` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1002aea2` | `7c 12` | `JL 0x1002aeb6` |
| `1002aea4` | `80 3f 35` | `CMP byte ptr [EDI],0x35` |
| `1002aea7` | `7c 0d` | `JL 0x1002aeb6` |
| `1002aea9` | `eb 03` | `JMP 0x1002aeae` |
| `1002aeab` | `c6 00 30` | `MOV byte ptr [EAX],0x30` |
| `1002aeae` | `48` | `DEC EAX` |
| `1002aeaf` | `80 38 39` | `CMP byte ptr [EAX],0x39` |
| `1002aeb2` | `74 f7` | `JZ 0x1002aeab` |
| `1002aeb4` | `fe 00` | `INC byte ptr [EAX]` |
| `1002aeb6` | `80 3e 31` | `CMP byte ptr [ESI],0x31` |
| `1002aeb9` | `75 05` | `JNZ 0x1002aec0` |
| `1002aebb` | `ff 41 04` | `INC dword ptr [ECX + 0x4]` |
| `1002aebe` | `eb 15` | `JMP 0x1002aed5` |
| `1002aec0` | `8d 7e 01` | `LEA EDI,[ESI + 0x1]` |
| `1002aec3` | `57` | `PUSH EDI` |
| `1002aec4` | `e8 27 65 fe ff` | `CALL 0x100113f0` |
| `1002aec9` | `40` | `INC EAX` |
| `1002aeca` | `50` | `PUSH EAX` |
| `1002aecb` | `57` | `PUSH EDI` |
| `1002aecc` | `56` | `PUSH ESI` |
| `1002aecd` | `e8 6e 78 fe ff` | `CALL 0x10012740` |
| `1002aed2` | `83 c4 10` | `ADD ESP,0x10` |
| `1002aed5` | `33 c0` | `XOR EAX,EAX` |
| `1002aed7` | `5f` | `POP EDI` |
| `1002aed8` | `5e` | `POP ESI` |
| `1002aed9` | `5b` | `POP EBX` |
| `1002aeda` | `5d` | `POP EBP` |
| `1002aedb` | `c3` | `RET` |
