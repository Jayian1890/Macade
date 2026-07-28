# 10011efa `__vsprintf_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10011efa |
| `name` | __vsprintf_l |
| `namespace` | Global |
| `signature` | int __cdecl __vsprintf_l(char * _DstBuf, char * _Format, _locale_t param_3, va_list _ArgList) |
| `size_bytes` | 126 |
| `stack_frame_size` | 56 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __vsprintf_l |

## Decompiled C

```c

/* Library Function - Single Match
    __vsprintf_l
   
   Library: Visual Studio 2008 Release */

int __cdecl __vsprintf_l(char *_DstBuf,char *_Format,_locale_t param_3,va_list _ArgList)

{
  int *piVar1;
  int iVar2;
  FILE local_24;
  
  if ((_Format == (char *)0x0) || (_DstBuf == (char *)0x0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    local_24._base = _DstBuf;
    local_24._ptr = _DstBuf;
    local_24._cnt = 0x7fffffff;
    local_24._flag = 0x42;
    iVar2 = __output_l(&local_24,_Format,param_3,_ArgList);
    local_24._cnt = local_24._cnt + -1;
    if (local_24._cnt < 0) {
      __flsbuf(0,&local_24);
    }
    else {
      *local_24._ptr = '\0';
    }
  }
  return iVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10011f0a` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10011f1a` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10011f50` | `100153e3` | `UNCONDITIONAL_CALL` | __output_l | `100153e3` |
| `10011f6b` | `10015152` | `UNCONDITIONAL_CALL` | __flsbuf | `10015152` |

## Callers

| From | Function |
| --- | --- |
| `10011f88` | _vsprintf |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

No direct named data references identified by Ghidra.

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10011efa` | `8b ff` | `MOV EDI,EDI` |
| `10011efc` | `55` | `PUSH EBP` |
| `10011efd` | `8b ec` | `MOV EBP,ESP` |
| `10011eff` | `83 ec 20` | `SUB ESP,0x20` |
| `10011f02` | `53` | `PUSH EBX` |
| `10011f03` | `33 db` | `XOR EBX,EBX` |
| `10011f05` | `39 5d 0c` | `CMP dword ptr [EBP + 0xc],EBX` |
| `10011f08` | `75 1d` | `JNZ 0x10011f27` |
| `10011f0a` | `e8 fa 31 00 00` | `CALL 0x10015109` |
| `10011f0f` | `53` | `PUSH EBX` |
| `10011f10` | `53` | `PUSH EBX` |
| `10011f11` | `53` | `PUSH EBX` |
| `10011f12` | `53` | `PUSH EBX` |
| `10011f13` | `53` | `PUSH EBX` |
| `10011f14` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10011f1a` | `e8 90 f7 ff ff` | `CALL 0x100116af` |
| `10011f1f` | `83 c4 14` | `ADD ESP,0x14` |
| `10011f22` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10011f25` | `eb 4e` | `JMP 0x10011f75` |
| `10011f27` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `10011f2a` | `3b c3` | `CMP EAX,EBX` |
| `10011f2c` | `74 dc` | `JZ 0x10011f0a` |
| `10011f2e` | `56` | `PUSH ESI` |
| `10011f2f` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `10011f32` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `10011f35` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `10011f38` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `10011f3b` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `10011f3e` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `10011f41` | `50` | `PUSH EAX` |
| `10011f42` | `c7 45 e4 ff ff ff 7f` | `MOV dword ptr [EBP + -0x1c],0x7fffffff` |
| `10011f49` | `c7 45 ec 42 00 00 00` | `MOV dword ptr [EBP + -0x14],0x42` |
| `10011f50` | `e8 8e 34 00 00` | `CALL 0x100153e3` |
| `10011f55` | `83 c4 10` | `ADD ESP,0x10` |
| `10011f58` | `ff 4d e4` | `DEC dword ptr [EBP + -0x1c]` |
| `10011f5b` | `8b f0` | `MOV ESI,EAX` |
| `10011f5d` | `78 07` | `JS 0x10011f66` |
| `10011f5f` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `10011f62` | `88 18` | `MOV byte ptr [EAX],BL` |
| `10011f64` | `eb 0c` | `JMP 0x10011f72` |
| `10011f66` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `10011f69` | `50` | `PUSH EAX` |
| `10011f6a` | `53` | `PUSH EBX` |
| `10011f6b` | `e8 e2 31 00 00` | `CALL 0x10015152` |
| `10011f70` | `59` | `POP ECX` |
| `10011f71` | `59` | `POP ECX` |
| `10011f72` | `8b c6` | `MOV EAX,ESI` |
| `10011f74` | `5e` | `POP ESI` |
| `10011f75` | `5b` | `POP EBX` |
| `10011f76` | `c9` | `LEAVE` |
| `10011f77` | `c3` | `RET` |
