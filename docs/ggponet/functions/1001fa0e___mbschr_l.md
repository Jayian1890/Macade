# 1001fa0e `__mbschr_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001fa0e |
| `name` | __mbschr_l |
| `namespace` | Global |
| `signature` | uchar * __cdecl __mbschr_l(uchar * _Str, uint _Ch, _locale_t _Locale) |
| `size_bytes` | 188 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __mbschr_l |

## Decompiled C

```c

/* Library Function - Single Match
    __mbschr_l
   
   Library: Visual Studio 2008 Release */

uchar * __cdecl __mbschr_l(uchar *_Str,uint _Ch,_locale_t _Locale)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  _LocaleUpdate local_14 [4];
  int local_10;
  int local_c;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate(local_14,_Locale);
  if (_Str == (uchar *)0x0) {
    piVar3 = __errno();
    *piVar3 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    _Str = (byte *)0x0;
  }
  else {
    if (*(int *)(local_10 + 8) == 0) {
      _Str = (uchar *)_strchr((char *)_Str,_Ch);
    }
    else {
      while( true ) {
        bVar2 = *_Str;
        if (bVar2 == 0) break;
        if ((*(byte *)(bVar2 + 0x1d + local_10) & 4) == 0) {
          pbVar4 = _Str;
          if (_Ch == bVar2) break;
        }
        else {
          bVar1 = _Str[1];
          if (bVar1 == 0) goto LAB_1001fab8;
          pbVar4 = _Str + 1;
          if (_Ch == CONCAT11(bVar2,bVar1)) goto LAB_1001faaa;
        }
        _Str = pbVar4 + 1;
      }
      if (_Ch != (ushort)bVar2) {
LAB_1001fab8:
        if (local_8 != '\0') {
          *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
        }
        return (uchar *)0x0;
      }
    }
LAB_1001faaa:
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  return _Str;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001fa1d` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001fa2b` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001fa3b` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001fa60` | `10011990` | `UNCONDITIONAL_CALL` | _strchr | `10011990` |

## Callers

| From | Function |
| --- | --- |
| `1001fad7` | __mbschr |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001fa0e` | `8b ff` | `MOV EDI,EDI` |
| `1001fa10` | `55` | `PUSH EBP` |
| `1001fa11` | `8b ec` | `MOV EBP,ESP` |
| `1001fa13` | `83 ec 10` | `SUB ESP,0x10` |
| `1001fa16` | `53` | `PUSH EBX` |
| `1001fa17` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001fa1a` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001fa1d` | `e8 94 58 ff ff` | `CALL 0x100152b6` |
| `1001fa22` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001fa25` | `33 db` | `XOR EBX,EBX` |
| `1001fa27` | `3b c3` | `CMP EAX,EBX` |
| `1001fa29` | `75 28` | `JNZ 0x1001fa53` |
| `1001fa2b` | `e8 d9 56 ff ff` | `CALL 0x10015109` |
| `1001fa30` | `53` | `PUSH EBX` |
| `1001fa31` | `53` | `PUSH EBX` |
| `1001fa32` | `53` | `PUSH EBX` |
| `1001fa33` | `53` | `PUSH EBX` |
| `1001fa34` | `53` | `PUSH EBX` |
| `1001fa35` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1001fa3b` | `e8 6f 1c ff ff` | `CALL 0x100116af` |
| `1001fa40` | `83 c4 14` | `ADD ESP,0x14` |
| `1001fa43` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001fa46` | `74 07` | `JZ 0x1001fa4f` |
| `1001fa48` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001fa4b` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001fa4f` | `33 c0` | `XOR EAX,EAX` |
| `1001fa51` | `eb 74` | `JMP 0x1001fac7` |
| `1001fa53` | `56` | `PUSH ESI` |
| `1001fa54` | `8b 75 f4` | `MOV ESI,dword ptr [EBP + -0xc]` |
| `1001fa57` | `39 5e 08` | `CMP dword ptr [ESI + 0x8],EBX` |
| `1001fa5a` | `75 3a` | `JNZ 0x1001fa96` |
| `1001fa5c` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001fa5f` | `50` | `PUSH EAX` |
| `1001fa60` | `e8 2b 1f ff ff` | `CALL 0x10011990` |
| `1001fa65` | `59` | `POP ECX` |
| `1001fa66` | `59` | `POP ECX` |
| `1001fa67` | `eb 41` | `JMP 0x1001faaa` |
| `1001fa69` | `0f b6 d1` | `MOVZX EDX,CL` |
| `1001fa6c` | `f6 44 32 1d 04` | `TEST byte ptr [EDX + ESI*0x1 + 0x1d],0x4` |
| `1001fa71` | `74 1a` | `JZ 0x1001fa8d` |
| `1001fa73` | `40` | `INC EAX` |
| `1001fa74` | `8a 10` | `MOV DL,byte ptr [EAX]` |
| `1001fa76` | `3a d3` | `CMP DL,BL` |
| `1001fa78` | `74 3e` | `JZ 0x1001fab8` |
| `1001fa7a` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001fa7d` | `0f b6 d2` | `MOVZX EDX,DL` |
| `1001fa80` | `c1 e1 08` | `SHL ECX,0x8` |
| `1001fa83` | `0b ca` | `OR ECX,EDX` |
| `1001fa85` | `39 4d 0c` | `CMP dword ptr [EBP + 0xc],ECX` |
| `1001fa88` | `75 0b` | `JNZ 0x1001fa95` |
| `1001fa8a` | `48` | `DEC EAX` |
| `1001fa8b` | `eb 1d` | `JMP 0x1001faaa` |
| `1001fa8d` | `0f b7 d1` | `MOVZX EDX,CX` |
| `1001fa90` | `39 55 0c` | `CMP dword ptr [EBP + 0xc],EDX` |
| `1001fa93` | `74 0d` | `JZ 0x1001faa2` |
| `1001fa95` | `40` | `INC EAX` |
| `1001fa96` | `66 0f b6 08` | `MOVZX CX,byte ptr [EAX]` |
| `1001fa9a` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001fa9d` | `66 3b cb` | `CMP CX,BX` |
| `1001faa0` | `75 c7` | `JNZ 0x1001fa69` |
| `1001faa2` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1001faa5` | `39 4d 0c` | `CMP dword ptr [EBP + 0xc],ECX` |
| `1001faa8` | `75 0e` | `JNZ 0x1001fab8` |
| `1001faaa` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001faad` | `74 17` | `JZ 0x1001fac6` |
| `1001faaf` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001fab2` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001fab6` | `eb 0e` | `JMP 0x1001fac6` |
| `1001fab8` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001fabb` | `74 07` | `JZ 0x1001fac4` |
| `1001fabd` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001fac0` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001fac4` | `33 c0` | `XOR EAX,EAX` |
| `1001fac6` | `5e` | `POP ESI` |
| `1001fac7` | `5b` | `POP EBX` |
| `1001fac8` | `c9` | `LEAVE` |
| `1001fac9` | `c3` | `RET` |
