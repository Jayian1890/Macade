# 10019953 `__vsnprintf_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019953 |
| `name` | __vsnprintf_l |
| `namespace` | Global |
| `signature` | int __cdecl __vsnprintf_l(char * _DstBuf, size_t _MaxCount, char * _Format, _locale_t _Locale, va_list _ArgList) |
| `size_bytes` | 179 |
| `stack_frame_size` | 60 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __vsnprintf_l |

## Decompiled C

```c

/* Library Function - Single Match
    __vsnprintf_l
   
   Library: Visual Studio 2008 Release */

int __cdecl
__vsnprintf_l(char *_DstBuf,size_t _MaxCount,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int *piVar1;
  int iVar2;
  FILE local_24;
  
  if (_Format == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  else if ((_MaxCount == 0) || (_DstBuf != (char *)0x0)) {
    local_24._cnt = 0x7fffffff;
    if (_MaxCount < 0x80000000) {
      local_24._cnt = _MaxCount;
    }
    local_24._flag = 0x42;
    local_24._base = _DstBuf;
    local_24._ptr = _DstBuf;
    iVar2 = __output_l(&local_24,_Format,_Locale,_ArgList);
    if (_DstBuf != (char *)0x0) {
      local_24._cnt = local_24._cnt - 1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = '\0';
      }
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019963` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10019973` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019992` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `100199a2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `100199d9` | `100153e3` | `UNCONDITIONAL_CALL` | __output_l | `100153e3` |
| `100199f8` | `10015152` | `UNCONDITIONAL_CALL` | __flsbuf | `10015152` |

## Callers

| From | Function |
| --- | --- |
| `10019a19` | __vsnprintf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019953` | `8b ff` | `MOV EDI,EDI` |
| `10019955` | `55` | `PUSH EBP` |
| `10019956` | `8b ec` | `MOV EBP,ESP` |
| `10019958` | `83 ec 20` | `SUB ESP,0x20` |
| `1001995b` | `53` | `PUSH EBX` |
| `1001995c` | `33 db` | `XOR EBX,EBX` |
| `1001995e` | `39 5d 10` | `CMP dword ptr [EBP + 0x10],EBX` |
| `10019961` | `75 20` | `JNZ 0x10019983` |
| `10019963` | `e8 a1 b7 ff ff` | `CALL 0x10015109` |
| `10019968` | `53` | `PUSH EBX` |
| `10019969` | `53` | `PUSH EBX` |
| `1001996a` | `53` | `PUSH EBX` |
| `1001996b` | `53` | `PUSH EBX` |
| `1001996c` | `53` | `PUSH EBX` |
| `1001996d` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10019973` | `e8 37 7d ff ff` | `CALL 0x100116af` |
| `10019978` | `83 c4 14` | `ADD ESP,0x14` |
| `1001997b` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001997e` | `e9 80 00 00 00` | `JMP 0x10019a03` |
| `10019983` | `8b 4d 0c` | `MOV ECX,dword ptr [EBP + 0xc]` |
| `10019986` | `56` | `PUSH ESI` |
| `10019987` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001998a` | `3b cb` | `CMP ECX,EBX` |
| `1001998c` | `74 21` | `JZ 0x100199af` |
| `1001998e` | `3b f3` | `CMP ESI,EBX` |
| `10019990` | `75 1d` | `JNZ 0x100199af` |
| `10019992` | `e8 72 b7 ff ff` | `CALL 0x10015109` |
| `10019997` | `53` | `PUSH EBX` |
| `10019998` | `53` | `PUSH EBX` |
| `10019999` | `53` | `PUSH EBX` |
| `1001999a` | `53` | `PUSH EBX` |
| `1001999b` | `53` | `PUSH EBX` |
| `1001999c` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `100199a2` | `e8 08 7d ff ff` | `CALL 0x100116af` |
| `100199a7` | `83 c4 14` | `ADD ESP,0x14` |
| `100199aa` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `100199ad` | `eb 53` | `JMP 0x10019a02` |
| `100199af` | `b8 ff ff ff 7f` | `MOV EAX,0x7fffffff` |
| `100199b4` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `100199b7` | `3b c8` | `CMP ECX,EAX` |
| `100199b9` | `77 03` | `JA 0x100199be` |
| `100199bb` | `89 4d e4` | `MOV dword ptr [EBP + -0x1c],ECX` |
| `100199be` | `57` | `PUSH EDI` |
| `100199bf` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `100199c2` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `100199c5` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `100199c8` | `c7 45 ec 42 00 00 00` | `MOV dword ptr [EBP + -0x14],0x42` |
| `100199cf` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `100199d2` | `89 75 e8` | `MOV dword ptr [EBP + -0x18],ESI` |
| `100199d5` | `50` | `PUSH EAX` |
| `100199d6` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `100199d9` | `e8 05 ba ff ff` | `CALL 0x100153e3` |
| `100199de` | `83 c4 10` | `ADD ESP,0x10` |
| `100199e1` | `8b f8` | `MOV EDI,EAX` |
| `100199e3` | `3b f3` | `CMP ESI,EBX` |
| `100199e5` | `74 1a` | `JZ 0x10019a01` |
| `100199e7` | `ff 4d e4` | `DEC dword ptr [EBP + -0x1c]` |
| `100199ea` | `78 07` | `JS 0x100199f3` |
| `100199ec` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `100199ef` | `88 18` | `MOV byte ptr [EAX],BL` |
| `100199f1` | `eb 0c` | `JMP 0x100199ff` |
| `100199f3` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `100199f6` | `50` | `PUSH EAX` |
| `100199f7` | `53` | `PUSH EBX` |
| `100199f8` | `e8 55 b7 ff ff` | `CALL 0x10015152` |
| `100199fd` | `59` | `POP ECX` |
| `100199fe` | `59` | `POP ECX` |
| `100199ff` | `8b c7` | `MOV EAX,EDI` |
| `10019a01` | `5f` | `POP EDI` |
| `10019a02` | `5e` | `POP ESI` |
| `10019a03` | `5b` | `POP EBX` |
| `10019a04` | `c9` | `LEAVE` |
| `10019a05` | `c3` | `RET` |
