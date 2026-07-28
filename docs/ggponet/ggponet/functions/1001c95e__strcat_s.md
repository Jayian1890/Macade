# 1001c95e `_strcat_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c95e |
| `name` | _strcat_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl _strcat_s(char * _Dst, rsize_t _SizeInBytes, char * _Src) |
| `size_bytes` | 116 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strcat_s |

## Decompiled C

```c

/* Library Function - Single Match
    _strcat_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl _strcat_s(char *_Dst,rsize_t _SizeInBytes,char *_Src)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  errno_t eVar4;
  
  if ((_Dst != (char *)0x0) && (_SizeInBytes != 0)) {
    pcVar3 = _Dst;
    if (_Src != (char *)0x0) {
      do {
        if (*pcVar3 == '\0') break;
        pcVar3 = pcVar3 + 1;
        _SizeInBytes = _SizeInBytes - 1;
      } while (_SizeInBytes != 0);
      if (_SizeInBytes != 0) {
        do {
          cVar1 = *_Src;
          *pcVar3 = cVar1;
          pcVar3 = pcVar3 + 1;
          _Src = _Src + 1;
          if (cVar1 == '\0') break;
          _SizeInBytes = _SizeInBytes - 1;
        } while (_SizeInBytes != 0);
        if (_SizeInBytes != 0) {
          return 0;
        }
        *_Dst = '\0';
        piVar2 = __errno();
        eVar4 = 0x22;
        *piVar2 = 0x22;
        goto LAB_1001c980;
      }
    }
    *_Dst = '\0';
  }
  piVar2 = __errno();
  eVar4 = 0x16;
  *piVar2 = 0x16;
LAB_1001c980:
  __invalid_parameter(0,0,0,0,0);
  return eVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c976` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c985` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001c9bd` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `1001700d` | __NMSG_WRITE |
| `10017032` | __NMSG_WRITE |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c95e` | `8b ff` | `MOV EDI,EDI` |
| `1001c960` | `55` | `PUSH EBP` |
| `1001c961` | `8b ec` | `MOV EBP,ESP` |
| `1001c963` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001c966` | `53` | `PUSH EBX` |
| `1001c967` | `33 db` | `XOR EBX,EBX` |
| `1001c969` | `56` | `PUSH ESI` |
| `1001c96a` | `57` | `PUSH EDI` |
| `1001c96b` | `3b c3` | `CMP EAX,EBX` |
| `1001c96d` | `74 07` | `JZ 0x1001c976` |
| `1001c96f` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001c972` | `3b fb` | `CMP EDI,EBX` |
| `1001c974` | `77 1b` | `JA 0x1001c991` |
| `1001c976` | `e8 8e 87 ff ff` | `CALL 0x10015109` |
| `1001c97b` | `6a 16` | `PUSH 0x16` |
| `1001c97d` | `5e` | `POP ESI` |
| `1001c97e` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001c980` | `53` | `PUSH EBX` |
| `1001c981` | `53` | `PUSH EBX` |
| `1001c982` | `53` | `PUSH EBX` |
| `1001c983` | `53` | `PUSH EBX` |
| `1001c984` | `53` | `PUSH EBX` |
| `1001c985` | `e8 25 4d ff ff` | `CALL 0x100116af` |
| `1001c98a` | `83 c4 14` | `ADD ESP,0x14` |
| `1001c98d` | `8b c6` | `MOV EAX,ESI` |
| `1001c98f` | `eb 3c` | `JMP 0x1001c9cd` |
| `1001c991` | `8b 75 10` | `MOV ESI,dword ptr [EBP + 0x10]` |
| `1001c994` | `3b f3` | `CMP ESI,EBX` |
| `1001c996` | `75 04` | `JNZ 0x1001c99c` |
| `1001c998` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1001c99a` | `eb da` | `JMP 0x1001c976` |
| `1001c99c` | `8b d0` | `MOV EDX,EAX` |
| `1001c99e` | `38 1a` | `CMP byte ptr [EDX],BL` |
| `1001c9a0` | `74 04` | `JZ 0x1001c9a6` |
| `1001c9a2` | `42` | `INC EDX` |
| `1001c9a3` | `4f` | `DEC EDI` |
| `1001c9a4` | `75 f8` | `JNZ 0x1001c99e` |
| `1001c9a6` | `3b fb` | `CMP EDI,EBX` |
| `1001c9a8` | `74 ee` | `JZ 0x1001c998` |
| `1001c9aa` | `8a 0e` | `MOV CL,byte ptr [ESI]` |
| `1001c9ac` | `88 0a` | `MOV byte ptr [EDX],CL` |
| `1001c9ae` | `42` | `INC EDX` |
| `1001c9af` | `46` | `INC ESI` |
| `1001c9b0` | `3a cb` | `CMP CL,BL` |
| `1001c9b2` | `74 03` | `JZ 0x1001c9b7` |
| `1001c9b4` | `4f` | `DEC EDI` |
| `1001c9b5` | `75 f3` | `JNZ 0x1001c9aa` |
| `1001c9b7` | `3b fb` | `CMP EDI,EBX` |
| `1001c9b9` | `75 10` | `JNZ 0x1001c9cb` |
| `1001c9bb` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1001c9bd` | `e8 47 87 ff ff` | `CALL 0x10015109` |
| `1001c9c2` | `6a 22` | `PUSH 0x22` |
| `1001c9c4` | `59` | `POP ECX` |
| `1001c9c5` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1001c9c7` | `8b f1` | `MOV ESI,ECX` |
| `1001c9c9` | `eb b5` | `JMP 0x1001c980` |
| `1001c9cb` | `33 c0` | `XOR EAX,EAX` |
| `1001c9cd` | `5f` | `POP EDI` |
| `1001c9ce` | `5e` | `POP ESI` |
| `1001c9cf` | `5b` | `POP EBX` |
| `1001c9d0` | `5d` | `POP EBP` |
| `1001c9d1` | `c3` | `RET` |
