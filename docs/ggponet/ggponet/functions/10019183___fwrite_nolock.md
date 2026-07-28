# 10019183 `__fwrite_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019183 |
| `name` | __fwrite_nolock |
| `namespace` | Global |
| `signature` | size_t __cdecl __fwrite_nolock(void * _DstBuf, size_t _Size, size_t _Count, FILE * _File) |
| `size_bytes` | 354 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __fwrite_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __fwrite_nolock
   
   Library: Visual Studio 2008 Release */

size_t __cdecl __fwrite_nolock(void *_DstBuf,size_t _Size,size_t _Count,FILE *_File)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint _Size_00;
  uint uVar5;
  uint uVar6;
  char *_Buf;
  uint local_c;
  char *local_8;
  
  if ((_Size != 0) && (_Count != 0)) {
    if ((_File != (FILE *)0x0) &&
       ((_DstBuf != (void *)0x0 && (_Count <= (uint)(0xffffffff / (ulonglong)_Size))))) {
      uVar6 = _Size * _Count;
      uVar5 = uVar6;
      if ((_File->_flag & 0x10cU) == 0) {
        local_c = 0x1000;
      }
      else {
        local_c = _File->_bufsiz;
      }
      do {
        while( true ) {
          if (uVar5 == 0) {
            return _Count;
          }
          uVar4 = _File->_flag & 0x108;
          if (uVar4 == 0) break;
          uVar3 = _File->_cnt;
          if (uVar3 == 0) break;
          if ((int)uVar3 < 0) {
            _File->_flag = _File->_flag | 0x20;
            goto LAB_100192d0;
          }
          _Size_00 = uVar5;
          if (uVar3 <= uVar5) {
            _Size_00 = uVar3;
          }
          _memcpy(_File->_ptr,_DstBuf,_Size_00);
          _File->_cnt = _File->_cnt - _Size_00;
          _File->_ptr = _File->_ptr + _Size_00;
          uVar5 = uVar5 - _Size_00;
LAB_1001928c:
          local_8 = (char *)((int)_DstBuf + _Size_00);
          _DstBuf = local_8;
        }
        if (local_c <= uVar5) {
          if ((uVar4 != 0) && (iVar2 = __flush(_File), iVar2 != 0)) goto LAB_100192d0;
          uVar4 = uVar5;
          if (local_c != 0) {
            uVar4 = uVar5 - uVar5 % local_c;
          }
          _Buf = _DstBuf;
          uVar3 = uVar4;
          iVar2 = __fileno(_File);
          uVar3 = __write(iVar2,_Buf,uVar3);
          if (uVar3 != 0xffffffff) {
            _Size_00 = uVar4;
            if (uVar3 <= uVar4) {
              _Size_00 = uVar3;
            }
            uVar5 = uVar5 - _Size_00;
            if (uVar4 <= uVar3) goto LAB_1001928c;
          }
          _File->_flag = _File->_flag | 0x20;
LAB_100192d0:
          return (uVar6 - uVar5) / _Size;
        }
        iVar2 = __flsbuf((int)*(char *)_DstBuf,_File);
        if (iVar2 == -1) goto LAB_100192d0;
        _DstBuf = (void *)((int)_DstBuf + 1);
        local_c = _File->_bufsiz;
        uVar5 = uVar5 - 1;
        if ((int)local_c < 1) {
          local_c = 1;
        }
      } while( true );
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  return 0;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `100191a1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100191b1` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019229` | `10010ce0` | `UNCONDITIONAL_CALL` | _memcpy | `10010ce0` |
| `10019247` | `10014489` | `UNCONDITIONAL_CALL` | __flush | `10014489` |
| `10019267` | `10018c45` | `UNCONDITIONAL_CALL` | __fileno | `10018c45` |
| `1001926e` | `1001a312` | `UNCONDITIONAL_CALL` | __write | `1001a312` |
| `10019299` | `10015152` | `UNCONDITIONAL_CALL` | __flsbuf | `10015152` |

## Callers

| From | Function |
| --- | --- |
| `10012395` | _puts |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019183` | `8b ff` | `MOV EDI,EDI` |
| `10019185` | `55` | `PUSH EBP` |
| `10019186` | `8b ec` | `MOV EBP,ESP` |
| `10019188` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001918b` | `53` | `PUSH EBX` |
| `1001918c` | `56` | `PUSH ESI` |
| `1001918d` | `57` | `PUSH EDI` |
| `1001918e` | `33 ff` | `XOR EDI,EDI` |
| `10019190` | `39 7d 0c` | `CMP dword ptr [EBP + 0xc],EDI` |
| `10019193` | `74 24` | `JZ 0x100191b9` |
| `10019195` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `10019198` | `74 1f` | `JZ 0x100191b9` |
| `1001919a` | `8b 75 14` | `MOV ESI,dword ptr [EBP + 0x14]` |
| `1001919d` | `3b f7` | `CMP ESI,EDI` |
| `1001919f` | `75 1f` | `JNZ 0x100191c0` |
| `100191a1` | `e8 63 bf ff ff` | `CALL 0x10015109` |
| `100191a6` | `57` | `PUSH EDI` |
| `100191a7` | `57` | `PUSH EDI` |
| `100191a8` | `57` | `PUSH EDI` |
| `100191a9` | `57` | `PUSH EDI` |
| `100191aa` | `57` | `PUSH EDI` |
| `100191ab` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `100191b1` | `e8 f9 84 ff ff` | `CALL 0x100116af` |
| `100191b6` | `83 c4 14` | `ADD ESP,0x14` |
| `100191b9` | `33 c0` | `XOR EAX,EAX` |
| `100191bb` | `5f` | `POP EDI` |
| `100191bc` | `5e` | `POP ESI` |
| `100191bd` | `5b` | `POP EBX` |
| `100191be` | `c9` | `LEAVE` |
| `100191bf` | `c3` | `RET` |
| `100191c0` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `100191c3` | `3b cf` | `CMP ECX,EDI` |
| `100191c5` | `74 da` | `JZ 0x100191a1` |
| `100191c7` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100191ca` | `33 d2` | `XOR EDX,EDX` |
| `100191cc` | `f7 75 0c` | `DIV dword ptr [EBP + 0xc]` |
| `100191cf` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `100191d2` | `77 cd` | `JA 0x100191a1` |
| `100191d4` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `100191d7` | `0f af 7d 10` | `IMUL EDI,dword ptr [EBP + 0x10]` |
| `100191db` | `f7 46 0c 0c 01 00 00` | `TEST dword ptr [ESI + 0xc],0x10c` |
| `100191e2` | `89 4d fc` | `MOV dword ptr [EBP + -0x4],ECX` |
| `100191e5` | `89 7d f4` | `MOV dword ptr [EBP + -0xc],EDI` |
| `100191e8` | `8b df` | `MOV EBX,EDI` |
| `100191ea` | `74 08` | `JZ 0x100191f4` |
| `100191ec` | `8b 46 18` | `MOV EAX,dword ptr [ESI + 0x18]` |
| `100191ef` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `100191f2` | `eb 07` | `JMP 0x100191fb` |
| `100191f4` | `c7 45 f8 00 10 00 00` | `MOV dword ptr [EBP + -0x8],0x1000` |
| `100191fb` | `85 ff` | `TEST EDI,EDI` |
| `100191fd` | `0f 84 bf 00 00 00` | `JZ 0x100192c2` |
| `10019203` | `8b 4e 0c` | `MOV ECX,dword ptr [ESI + 0xc]` |
| `10019206` | `81 e1 08 01 00 00` | `AND ECX,0x108` |
| `1001920c` | `74 2f` | `JZ 0x1001923d` |
| `1001920e` | `8b 46 04` | `MOV EAX,dword ptr [ESI + 0x4]` |
| `10019211` | `85 c0` | `TEST EAX,EAX` |
| `10019213` | `74 28` | `JZ 0x1001923d` |
| `10019215` | `0f 8c af 00 00 00` | `JL 0x100192ca` |
| `1001921b` | `8b fb` | `MOV EDI,EBX` |
| `1001921d` | `3b d8` | `CMP EBX,EAX` |
| `1001921f` | `72 02` | `JC 0x10019223` |
| `10019221` | `8b f8` | `MOV EDI,EAX` |
| `10019223` | `57` | `PUSH EDI` |
| `10019224` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10019227` | `ff 36` | `PUSH dword ptr [ESI]` |
| `10019229` | `e8 b2 7a ff ff` | `CALL 0x10010ce0` |
| `1001922e` | `29 7e 04` | `SUB dword ptr [ESI + 0x4],EDI` |
| `10019231` | `01 3e` | `ADD dword ptr [ESI],EDI` |
| `10019233` | `83 c4 0c` | `ADD ESP,0xc` |
| `10019236` | `2b df` | `SUB EBX,EDI` |
| `10019238` | `01 7d fc` | `ADD dword ptr [EBP + -0x4],EDI` |
| `1001923b` | `eb 4f` | `JMP 0x1001928c` |
| `1001923d` | `3b 5d f8` | `CMP EBX,dword ptr [EBP + -0x8]` |
| `10019240` | `72 4f` | `JC 0x10019291` |
| `10019242` | `85 c9` | `TEST ECX,ECX` |
| `10019244` | `74 0b` | `JZ 0x10019251` |
| `10019246` | `56` | `PUSH ESI` |
| `10019247` | `e8 3d b2 ff ff` | `CALL 0x10014489` |
| `1001924c` | `59` | `POP ECX` |
| `1001924d` | `85 c0` | `TEST EAX,EAX` |
| `1001924f` | `75 7d` | `JNZ 0x100192ce` |
| `10019251` | `83 7d f8 00` | `CMP dword ptr [EBP + -0x8],0x0` |
| `10019255` | `8b fb` | `MOV EDI,EBX` |
| `10019257` | `74 09` | `JZ 0x10019262` |
| `10019259` | `33 d2` | `XOR EDX,EDX` |
| `1001925b` | `8b c3` | `MOV EAX,EBX` |
| `1001925d` | `f7 75 f8` | `DIV dword ptr [EBP + -0x8]` |
| `10019260` | `2b fa` | `SUB EDI,EDX` |
| `10019262` | `57` | `PUSH EDI` |
| `10019263` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `10019266` | `56` | `PUSH ESI` |
| `10019267` | `e8 d9 f9 ff ff` | `CALL 0x10018c45` |
| `1001926c` | `59` | `POP ECX` |
| `1001926d` | `50` | `PUSH EAX` |
| `1001926e` | `e8 9f 10 00 00` | `CALL 0x1001a312` |
| `10019273` | `83 c4 0c` | `ADD ESP,0xc` |
| `10019276` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10019279` | `74 61` | `JZ 0x100192dc` |
| `1001927b` | `8b cf` | `MOV ECX,EDI` |
| `1001927d` | `3b c7` | `CMP EAX,EDI` |
| `1001927f` | `77 02` | `JA 0x10019283` |
| `10019281` | `8b c8` | `MOV ECX,EAX` |
| `10019283` | `01 4d fc` | `ADD dword ptr [EBP + -0x4],ECX` |
| `10019286` | `2b d9` | `SUB EBX,ECX` |
| `10019288` | `3b c7` | `CMP EAX,EDI` |
| `1001928a` | `72 50` | `JC 0x100192dc` |
| `1001928c` | `8b 7d f4` | `MOV EDI,dword ptr [EBP + -0xc]` |
| `1001928f` | `eb 29` | `JMP 0x100192ba` |
| `10019291` | `8b 45 fc` | `MOV EAX,dword ptr [EBP + -0x4]` |
| `10019294` | `0f be 00` | `MOVSX EAX,byte ptr [EAX]` |
| `10019297` | `56` | `PUSH ESI` |
| `10019298` | `50` | `PUSH EAX` |
| `10019299` | `e8 b4 be ff ff` | `CALL 0x10015152` |
| `1001929e` | `59` | `POP ECX` |
| `1001929f` | `59` | `POP ECX` |
| `100192a0` | `83 f8 ff` | `CMP EAX,-0x1` |
| `100192a3` | `74 29` | `JZ 0x100192ce` |
| `100192a5` | `ff 45 fc` | `INC dword ptr [EBP + -0x4]` |
| `100192a8` | `8b 46 18` | `MOV EAX,dword ptr [ESI + 0x18]` |
| `100192ab` | `4b` | `DEC EBX` |
| `100192ac` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `100192af` | `85 c0` | `TEST EAX,EAX` |
| `100192b1` | `7f 07` | `JG 0x100192ba` |
| `100192b3` | `c7 45 f8 01 00 00 00` | `MOV dword ptr [EBP + -0x8],0x1` |
| `100192ba` | `85 db` | `TEST EBX,EBX` |
| `100192bc` | `0f 85 41 ff ff ff` | `JNZ 0x10019203` |
| `100192c2` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `100192c5` | `e9 f1 fe ff ff` | `JMP 0x100191bb` |
| `100192ca` | `83 4e 0c 20` | `OR dword ptr [ESI + 0xc],0x20` |
| `100192ce` | `8b c7` | `MOV EAX,EDI` |
| `100192d0` | `2b c3` | `SUB EAX,EBX` |
| `100192d2` | `33 d2` | `XOR EDX,EDX` |
| `100192d4` | `f7 75 0c` | `DIV dword ptr [EBP + 0xc]` |
| `100192d7` | `e9 df fe ff ff` | `JMP 0x100191bb` |
| `100192dc` | `83 4e 0c 20` | `OR dword ptr [ESI + 0xc],0x20` |
| `100192e0` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `100192e3` | `eb eb` | `JMP 0x100192d0` |
