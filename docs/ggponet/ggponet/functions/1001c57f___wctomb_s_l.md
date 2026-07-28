# 1001c57f `__wctomb_s_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c57f |
| `name` | __wctomb_s_l |
| `namespace` | Global |
| `signature` | errno_t __cdecl __wctomb_s_l(int * _SizeConverted, char * _MbCh, size_t _SizeInBytes, wchar_t _WCh, _locale_t _Locale) |
| `size_bytes` | 364 |
| `stack_frame_size` | 44 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __wctomb_s_l |

## Decompiled C

```c

/* Library Function - Single Match
    __wctomb_s_l
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl
__wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale)

{
  char *lpMultiByteStr;
  size_t _Size;
  int iVar1;
  int *piVar2;
  DWORD DVar3;
  int local_14 [2];
  int local_c;
  char local_8;
  
  _Size = _SizeInBytes;
  lpMultiByteStr = _MbCh;
  if ((_MbCh == (char *)0x0) && (_SizeInBytes != 0)) {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = 0;
    }
LAB_1001c5a3:
    iVar1 = 0;
  }
  else {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = -1;
    }
    if (0x7fffffff < _SizeInBytes) {
      piVar2 = __errno();
      *piVar2 = 0x16;
      __invalid_parameter(0,0,0,0,0);
      return 0x16;
    }
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,_Locale);
    if (*(int *)(local_14[0] + 0x14) == 0) {
      if ((ushort)_WCh < 0x100) {
        if (lpMultiByteStr != (char *)0x0) {
          if (_Size == 0) goto LAB_1001c63a;
          *lpMultiByteStr = (char)_WCh;
        }
        if (_SizeConverted != (int *)0x0) {
          *_SizeConverted = 1;
        }
LAB_1001c675:
        if (local_8 != '\0') {
          *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
        }
        goto LAB_1001c5a3;
      }
      if ((lpMultiByteStr != (char *)0x0) && (_Size != 0)) {
        _memset(lpMultiByteStr,0,_Size);
      }
    }
    else {
      _MbCh = (char *)0x0;
      iVar1 = WideCharToMultiByte(*(UINT *)(local_14[0] + 4),0,&_WCh,1,lpMultiByteStr,_Size,
                                  (LPCSTR)0x0,(LPBOOL)&_MbCh);
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        if (DVar3 == 0x7a) {
          if ((lpMultiByteStr != (char *)0x0) && (_Size != 0)) {
            _memset(lpMultiByteStr,0,_Size);
          }
LAB_1001c63a:
          piVar2 = __errno();
          *piVar2 = 0x22;
          __invalid_parameter(0,0,0,0,0);
          if (local_8 == '\0') {
            return 0x22;
          }
          *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
          return 0x22;
        }
      }
      else if (_MbCh == (char *)0x0) {
        if (_SizeConverted != (int *)0x0) {
          *_SizeConverted = iVar1;
        }
        goto LAB_1001c675;
      }
    }
    piVar2 = __errno();
    *piVar2 = 0x2a;
    piVar2 = __errno();
    iVar1 = *piVar2;
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c5bc` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c5cb` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001c5dd` | `100152b6` | `UNCONDITIONAL_CALL` | _LocaleUpdate::_LocaleUpdate | `100152b6` |
| `1001c607` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001c60f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c61a` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c63a` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001c649` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001c69e` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001c6bc` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001c6de` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |

## Callers

| From | Function |
| --- | --- |
| `1001c6fe` | _wctomb_s |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001c69e` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001c6bc` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c57f` | `8b ff` | `MOV EDI,EDI` |
| `1001c581` | `55` | `PUSH EBP` |
| `1001c582` | `8b ec` | `MOV EBP,ESP` |
| `1001c584` | `83 ec 10` | `SUB ESP,0x10` |
| `1001c587` | `53` | `PUSH EBX` |
| `1001c588` | `56` | `PUSH ESI` |
| `1001c589` | `8b 75 0c` | `MOV ESI,dword ptr [EBP + 0xc]` |
| `1001c58c` | `33 db` | `XOR EBX,EBX` |
| `1001c58e` | `57` | `PUSH EDI` |
| `1001c58f` | `8b 7d 10` | `MOV EDI,dword ptr [EBP + 0x10]` |
| `1001c592` | `3b f3` | `CMP ESI,EBX` |
| `1001c594` | `75 14` | `JNZ 0x1001c5aa` |
| `1001c596` | `3b fb` | `CMP EDI,EBX` |
| `1001c598` | `76 10` | `JBE 0x1001c5aa` |
| `1001c59a` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001c59d` | `3b c3` | `CMP EAX,EBX` |
| `1001c59f` | `74 02` | `JZ 0x1001c5a3` |
| `1001c5a1` | `89 18` | `MOV dword ptr [EAX],EBX` |
| `1001c5a3` | `33 c0` | `XOR EAX,EAX` |
| `1001c5a5` | `e9 83 00 00 00` | `JMP 0x1001c62d` |
| `1001c5aa` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001c5ad` | `3b c3` | `CMP EAX,EBX` |
| `1001c5af` | `74 03` | `JZ 0x1001c5b4` |
| `1001c5b1` | `83 08 ff` | `OR dword ptr [EAX],0xffffffff` |
| `1001c5b4` | `81 ff ff ff ff 7f` | `CMP EDI,0x7fffffff` |
| `1001c5ba` | `76 1b` | `JBE 0x1001c5d7` |
| `1001c5bc` | `e8 48 8b ff ff` | `CALL 0x10015109` |
| `1001c5c1` | `6a 16` | `PUSH 0x16` |
| `1001c5c3` | `5e` | `POP ESI` |
| `1001c5c4` | `53` | `PUSH EBX` |
| `1001c5c5` | `53` | `PUSH EBX` |
| `1001c5c6` | `53` | `PUSH EBX` |
| `1001c5c7` | `53` | `PUSH EBX` |
| `1001c5c8` | `53` | `PUSH EBX` |
| `1001c5c9` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001c5cb` | `e8 df 50 ff ff` | `CALL 0x100116af` |
| `1001c5d0` | `83 c4 14` | `ADD ESP,0x14` |
| `1001c5d3` | `8b c6` | `MOV EAX,ESI` |
| `1001c5d5` | `eb 56` | `JMP 0x1001c62d` |
| `1001c5d7` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001c5da` | `8d 4d f0` | `LEA ECX,[EBP + -0x10]` |
| `1001c5dd` | `e8 d4 8c ff ff` | `CALL 0x100152b6` |
| `1001c5e2` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001c5e5` | `39 58 14` | `CMP dword ptr [EAX + 0x14],EBX` |
| `1001c5e8` | `0f 85 9c 00 00 00` | `JNZ 0x1001c68a` |
| `1001c5ee` | `66 8b 45 14` | `MOV AX,word ptr [EBP + 0x14]` |
| `1001c5f2` | `b9 ff 00 00 00` | `MOV ECX,0xff` |
| `1001c5f7` | `66 3b c1` | `CMP AX,CX` |
| `1001c5fa` | `76 36` | `JBE 0x1001c632` |
| `1001c5fc` | `3b f3` | `CMP ESI,EBX` |
| `1001c5fe` | `74 0f` | `JZ 0x1001c60f` |
| `1001c600` | `3b fb` | `CMP EDI,EBX` |
| `1001c602` | `76 0b` | `JBE 0x1001c60f` |
| `1001c604` | `57` | `PUSH EDI` |
| `1001c605` | `53` | `PUSH EBX` |
| `1001c606` | `56` | `PUSH ESI` |
| `1001c607` | `e8 e4 50 ff ff` | `CALL 0x100116f0` |
| `1001c60c` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001c60f` | `e8 f5 8a ff ff` | `CALL 0x10015109` |
| `1001c614` | `c7 00 2a 00 00 00` | `MOV dword ptr [EAX],0x2a` |
| `1001c61a` | `e8 ea 8a ff ff` | `CALL 0x10015109` |
| `1001c61f` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001c621` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001c624` | `74 07` | `JZ 0x1001c62d` |
| `1001c626` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1001c629` | `83 61 70 fd` | `AND dword ptr [ECX + 0x70],0xfffffffd` |
| `1001c62d` | `5f` | `POP EDI` |
| `1001c62e` | `5e` | `POP ESI` |
| `1001c62f` | `5b` | `POP EBX` |
| `1001c630` | `c9` | `LEAVE` |
| `1001c631` | `c3` | `RET` |
| `1001c632` | `3b f3` | `CMP ESI,EBX` |
| `1001c634` | `74 32` | `JZ 0x1001c668` |
| `1001c636` | `3b fb` | `CMP EDI,EBX` |
| `1001c638` | `77 2c` | `JA 0x1001c666` |
| `1001c63a` | `e8 ca 8a ff ff` | `CALL 0x10015109` |
| `1001c63f` | `6a 22` | `PUSH 0x22` |
| `1001c641` | `5e` | `POP ESI` |
| `1001c642` | `53` | `PUSH EBX` |
| `1001c643` | `53` | `PUSH EBX` |
| `1001c644` | `53` | `PUSH EBX` |
| `1001c645` | `53` | `PUSH EBX` |
| `1001c646` | `53` | `PUSH EBX` |
| `1001c647` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001c649` | `e8 61 50 ff ff` | `CALL 0x100116af` |
| `1001c64e` | `83 c4 14` | `ADD ESP,0x14` |
| `1001c651` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001c654` | `0f 84 79 ff ff ff` | `JZ 0x1001c5d3` |
| `1001c65a` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001c65d` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001c661` | `e9 6d ff ff ff` | `JMP 0x1001c5d3` |
| `1001c666` | `88 06` | `MOV byte ptr [ESI],AL` |
| `1001c668` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001c66b` | `3b c3` | `CMP EAX,EBX` |
| `1001c66d` | `74 06` | `JZ 0x1001c675` |
| `1001c66f` | `c7 00 01 00 00 00` | `MOV dword ptr [EAX],0x1` |
| `1001c675` | `38 5d fc` | `CMP byte ptr [EBP + -0x4],BL` |
| `1001c678` | `0f 84 25 ff ff ff` | `JZ 0x1001c5a3` |
| `1001c67e` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001c681` | `83 60 70 fd` | `AND dword ptr [EAX + 0x70],0xfffffffd` |
| `1001c685` | `e9 19 ff ff ff` | `JMP 0x1001c5a3` |
| `1001c68a` | `8d 4d 0c` | `LEA ECX,[EBP + 0xc]` |
| `1001c68d` | `51` | `PUSH ECX` |
| `1001c68e` | `53` | `PUSH EBX` |
| `1001c68f` | `57` | `PUSH EDI` |
| `1001c690` | `56` | `PUSH ESI` |
| `1001c691` | `6a 01` | `PUSH 0x1` |
| `1001c693` | `8d 4d 14` | `LEA ECX,[EBP + 0x14]` |
| `1001c696` | `51` | `PUSH ECX` |
| `1001c697` | `53` | `PUSH EBX` |
| `1001c698` | `89 5d 0c` | `MOV dword ptr [EBP + 0xc],EBX` |
| `1001c69b` | `ff 70 04` | `PUSH dword ptr [EAX + 0x4]` |
| `1001c69e` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `1001c6a4` | `3b c3` | `CMP EAX,EBX` |
| `1001c6a6` | `74 14` | `JZ 0x1001c6bc` |
| `1001c6a8` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1001c6ab` | `0f 85 5e ff ff ff` | `JNZ 0x1001c60f` |
| `1001c6b1` | `8b 4d 08` | `MOV ECX,dword ptr [EBP + 0x8]` |
| `1001c6b4` | `3b cb` | `CMP ECX,EBX` |
| `1001c6b6` | `74 bd` | `JZ 0x1001c675` |
| `1001c6b8` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `1001c6ba` | `eb b9` | `JMP 0x1001c675` |
| `1001c6bc` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001c6c2` | `83 f8 7a` | `CMP EAX,0x7a` |
| `1001c6c5` | `0f 85 44 ff ff ff` | `JNZ 0x1001c60f` |
| `1001c6cb` | `3b f3` | `CMP ESI,EBX` |
| `1001c6cd` | `0f 84 67 ff ff ff` | `JZ 0x1001c63a` |
| `1001c6d3` | `3b fb` | `CMP EDI,EBX` |
| `1001c6d5` | `0f 86 5f ff ff ff` | `JBE 0x1001c63a` |
| `1001c6db` | `57` | `PUSH EDI` |
| `1001c6dc` | `53` | `PUSH EBX` |
| `1001c6dd` | `56` | `PUSH ESI` |
| `1001c6de` | `e8 0d 50 ff ff` | `CALL 0x100116f0` |
| `1001c6e3` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001c6e6` | `e9 4f ff ff ff` | `JMP 0x1001c63a` |
