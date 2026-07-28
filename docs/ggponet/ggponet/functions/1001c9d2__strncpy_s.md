# 1001c9d2 `_strncpy_s`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001c9d2 |
| `name` | _strncpy_s |
| `namespace` | Global |
| `signature` | errno_t __cdecl _strncpy_s(char * _Dst, rsize_t _SizeInBytes, char * _Src, rsize_t _MaxCount) |
| `size_bytes` | 181 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | _strncpy_s |

## Decompiled C

```c

/* Library Function - Single Match
    _strncpy_s
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl _strncpy_s(char *_Dst,rsize_t _SizeInBytes,char *_Src,rsize_t _MaxCount)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  rsize_t rVar4;
  errno_t eVar5;
  
  if (_MaxCount == 0) {
    if (_Dst == (char *)0x0) {
      if (_SizeInBytes == 0) {
        return 0;
      }
    }
    else {
LAB_1001c9f8:
      if (_SizeInBytes != 0) {
        if (_MaxCount == 0) {
          *_Dst = '\0';
          return 0;
        }
        if (_Src != (char *)0x0) {
          pcVar3 = _Dst;
          rVar4 = _SizeInBytes;
          if (_MaxCount == 0xffffffff) {
            do {
              cVar1 = *_Src;
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              _Src = _Src + 1;
              if (cVar1 == '\0') break;
              rVar4 = rVar4 - 1;
            } while (rVar4 != 0);
          }
          else {
            do {
              cVar1 = *_Src;
              *pcVar3 = cVar1;
              pcVar3 = pcVar3 + 1;
              _Src = _Src + 1;
              if ((cVar1 == '\0') || (rVar4 = rVar4 - 1, rVar4 == 0)) break;
              _MaxCount = _MaxCount - 1;
            } while (_MaxCount != 0);
            if (_MaxCount == 0) {
              *pcVar3 = '\0';
            }
          }
          if (rVar4 != 0) {
            return 0;
          }
          if (_MaxCount == 0xffffffff) {
            _Dst[_SizeInBytes - 1] = '\0';
            return 0x50;
          }
          *_Dst = '\0';
          piVar2 = __errno();
          eVar5 = 0x22;
          *piVar2 = 0x22;
          goto LAB_1001ca09;
        }
        *_Dst = '\0';
      }
    }
  }
  else if (_Dst != (char *)0x0) goto LAB_1001c9f8;
  piVar2 = __errno();
  eVar5 = 0x16;
  *piVar2 = 0x16;
LAB_1001ca09:
  __invalid_parameter(0,0,0,0,0);
  return eVar5;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001c9ff` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001ca0e` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001ca79` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |

## Callers

| From | Function |
| --- | --- |
| `10016fe7` | __NMSG_WRITE |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001c9d2` | `8b ff` | `MOV EDI,EDI` |
| `1001c9d4` | `55` | `PUSH EBP` |
| `1001c9d5` | `8b ec` | `MOV EBP,ESP` |
| `1001c9d7` | `53` | `PUSH EBX` |
| `1001c9d8` | `56` | `PUSH ESI` |
| `1001c9d9` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001c9dc` | `33 db` | `XOR EBX,EBX` |
| `1001c9de` | `57` | `PUSH EDI` |
| `1001c9df` | `39 5d 14` | `CMP dword ptr [EBP + 0x14],EBX` |
| `1001c9e2` | `75 10` | `JNZ 0x1001c9f4` |
| `1001c9e4` | `3b f3` | `CMP ESI,EBX` |
| `1001c9e6` | `75 10` | `JNZ 0x1001c9f8` |
| `1001c9e8` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `1001c9eb` | `75 12` | `JNZ 0x1001c9ff` |
| `1001c9ed` | `33 c0` | `XOR EAX,EAX` |
| `1001c9ef` | `5f` | `POP EDI` |
| `1001c9f0` | `5e` | `POP ESI` |
| `1001c9f1` | `5b` | `POP EBX` |
| `1001c9f2` | `5d` | `POP EBP` |
| `1001c9f3` | `c3` | `RET` |
| `1001c9f4` | `3b f3` | `CMP ESI,EBX` |
| `1001c9f6` | `74 07` | `JZ 0x1001c9ff` |
| `1001c9f8` | `8b 7d 0c` | `MOV EDI,dword ptr [EBP + 0xc]` |
| `1001c9fb` | `3b fb` | `CMP EDI,EBX` |
| `1001c9fd` | `77 1b` | `JA 0x1001ca1a` |
| `1001c9ff` | `e8 05 87 ff ff` | `CALL 0x10015109` |
| `1001ca04` | `6a 16` | `PUSH 0x16` |
| `1001ca06` | `5e` | `POP ESI` |
| `1001ca07` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001ca09` | `53` | `PUSH EBX` |
| `1001ca0a` | `53` | `PUSH EBX` |
| `1001ca0b` | `53` | `PUSH EBX` |
| `1001ca0c` | `53` | `PUSH EBX` |
| `1001ca0d` | `53` | `PUSH EBX` |
| `1001ca0e` | `e8 9c 4c ff ff` | `CALL 0x100116af` |
| `1001ca13` | `83 c4 14` | `ADD ESP,0x14` |
| `1001ca16` | `8b c6` | `MOV EAX,ESI` |
| `1001ca18` | `eb d5` | `JMP 0x1001c9ef` |
| `1001ca1a` | `39 5d 14` | `CMP dword ptr [EBP + 0x14],EBX` |
| `1001ca1d` | `75 04` | `JNZ 0x1001ca23` |
| `1001ca1f` | `88 1e` | `MOV byte ptr [ESI],BL` |
| `1001ca21` | `eb ca` | `JMP 0x1001c9ed` |
| `1001ca23` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `1001ca26` | `3b d3` | `CMP EDX,EBX` |
| `1001ca28` | `75 04` | `JNZ 0x1001ca2e` |
| `1001ca2a` | `88 1e` | `MOV byte ptr [ESI],BL` |
| `1001ca2c` | `eb d1` | `JMP 0x1001c9ff` |
| `1001ca2e` | `83 7d 14 ff` | `CMP dword ptr [EBP + 0x14],-0x1` |
| `1001ca32` | `8b c6` | `MOV EAX,ESI` |
| `1001ca34` | `75 0f` | `JNZ 0x1001ca45` |
| `1001ca36` | `8a 0a` | `MOV CL,byte ptr [EDX]` |
| `1001ca38` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1001ca3a` | `40` | `INC EAX` |
| `1001ca3b` | `42` | `INC EDX` |
| `1001ca3c` | `3a cb` | `CMP CL,BL` |
| `1001ca3e` | `74 1e` | `JZ 0x1001ca5e` |
| `1001ca40` | `4f` | `DEC EDI` |
| `1001ca41` | `75 f3` | `JNZ 0x1001ca36` |
| `1001ca43` | `eb 19` | `JMP 0x1001ca5e` |
| `1001ca45` | `8a 0a` | `MOV CL,byte ptr [EDX]` |
| `1001ca47` | `88 08` | `MOV byte ptr [EAX],CL` |
| `1001ca49` | `40` | `INC EAX` |
| `1001ca4a` | `42` | `INC EDX` |
| `1001ca4b` | `3a cb` | `CMP CL,BL` |
| `1001ca4d` | `74 08` | `JZ 0x1001ca57` |
| `1001ca4f` | `4f` | `DEC EDI` |
| `1001ca50` | `74 05` | `JZ 0x1001ca57` |
| `1001ca52` | `ff 4d 14` | `DEC dword ptr [EBP + 0x14]` |
| `1001ca55` | `75 ee` | `JNZ 0x1001ca45` |
| `1001ca57` | `39 5d 14` | `CMP dword ptr [EBP + 0x14],EBX` |
| `1001ca5a` | `75 02` | `JNZ 0x1001ca5e` |
| `1001ca5c` | `88 18` | `MOV byte ptr [EAX],BL` |
| `1001ca5e` | `3b fb` | `CMP EDI,EBX` |
| `1001ca60` | `75 8b` | `JNZ 0x1001c9ed` |
| `1001ca62` | `83 7d 14 ff` | `CMP dword ptr [EBP + 0x14],-0x1` |
| `1001ca66` | `75 0f` | `JNZ 0x1001ca77` |
| `1001ca68` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1001ca6b` | `6a 50` | `PUSH 0x50` |
| `1001ca6d` | `88 5c 06 ff` | `MOV byte ptr [ESI + EAX*0x1 + -0x1],BL` |
| `1001ca71` | `58` | `POP EAX` |
| `1001ca72` | `e9 78 ff ff ff` | `JMP 0x1001c9ef` |
| `1001ca77` | `88 1e` | `MOV byte ptr [ESI],BL` |
| `1001ca79` | `e8 8b 86 ff ff` | `CALL 0x10015109` |
| `1001ca7e` | `6a 22` | `PUSH 0x22` |
| `1001ca80` | `59` | `POP ECX` |
| `1001ca81` | `89 08` | `MOV dword ptr [EAX],ECX` |
| `1001ca83` | `8b f1` | `MOV ESI,ECX` |
| `1001ca85` | `eb 82` | `JMP 0x1001ca09` |
