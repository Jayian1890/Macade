# 1001d4c2 `__sopen_helper`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001d4c2 |
| `name` | __sopen_helper |
| `namespace` | Global |
| `signature` | errno_t __cdecl __sopen_helper(char * _Filename, int _OFlag, int _ShFlag, int _PMode, int * _PFileHandle, int _BSecure) |
| `size_bytes` | 153 |
| `stack_frame_size` | 64 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __sopen_helper |

## Decompiled C

```c

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __sopen_helper
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl
__sopen_helper(char *_Filename,int _OFlag,int _ShFlag,int _PMode,int *_PFileHandle,int _BSecure)

{
  int *piVar1;
  errno_t eVar2;
  undefined4 local_20 [5];
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_10034270;
  uStack_c = 0x1001d4ce;
  local_20[0] = 0;
  if (((_PFileHandle == (int *)0x0) || (*_PFileHandle = -1, _Filename == (char *)0x0)) ||
     ((_BSecure != 0 && ((_PMode & 0xfffffe7fU) != 0)))) {
    piVar1 = __errno();
    eVar2 = 0x16;
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
  }
  else {
    local_8 = (undefined *)0x0;
    eVar2 = __tsopen_nolock(local_20,_Filename,_OFlag,_ShFlag,_PMode);
    local_8 = (undefined *)0xfffffffe;
    FUN_1001d560();
    if (eVar2 != 0) {
      *_PFileHandle = -1;
    }
  }
  return eVar2;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001d4c9` | `10016cfc` | `UNCONDITIONAL_CALL` | __SEH_prolog4 | `10016cfc` |
| `1001d4e1` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001d4f0` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1001d534` | `1001cda3` | `UNCONDITIONAL_CALL` | __tsopen_nolock | `1001cda3` |
| `1001d546` | `1001d560` | `UNCONDITIONAL_CALL` | FUN_1001d560 | `1001d560` |
| `1001d555` | `10016d41` | `UNCONDITIONAL_CALL` | __SEH_epilog4 | `10016d41` |

## Callers

| From | Function |
| --- | --- |
| `1001d5a4` | __sopen_s |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001d4c4` | `10034270` | `DATA` | DAT_10034270 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001d4c2` | `6a 14` | `PUSH 0x14` |
| `1001d4c4` | `68 70 42 03 10` | `PUSH 0x10034270` |
| `1001d4c9` | `e8 2e 98 ff ff` | `CALL 0x10016cfc` |
| `1001d4ce` | `33 f6` | `XOR ESI,ESI` |
| `1001d4d0` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1001d4d3` | `33 c0` | `XOR EAX,EAX` |
| `1001d4d5` | `8b 7d 18` | `MOV EDI,dword ptr [EBP + 0x18]` |
| `1001d4d8` | `3b fe` | `CMP EDI,ESI` |
| `1001d4da` | `0f 95 c0` | `SETNZ AL` |
| `1001d4dd` | `3b c6` | `CMP EAX,ESI` |
| `1001d4df` | `75 1b` | `JNZ 0x1001d4fc` |
| `1001d4e1` | `e8 23 7c ff ff` | `CALL 0x10015109` |
| `1001d4e6` | `6a 16` | `PUSH 0x16` |
| `1001d4e8` | `5f` | `POP EDI` |
| `1001d4e9` | `89 38` | `MOV dword ptr [EAX],EDI` |
| `1001d4eb` | `56` | `PUSH ESI` |
| `1001d4ec` | `56` | `PUSH ESI` |
| `1001d4ed` | `56` | `PUSH ESI` |
| `1001d4ee` | `56` | `PUSH ESI` |
| `1001d4ef` | `56` | `PUSH ESI` |
| `1001d4f0` | `e8 ba 41 ff ff` | `CALL 0x100116af` |
| `1001d4f5` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d4f8` | `8b c7` | `MOV EAX,EDI` |
| `1001d4fa` | `eb 59` | `JMP 0x1001d555` |
| `1001d4fc` | `83 0f ff` | `OR dword ptr [EDI],0xffffffff` |
| `1001d4ff` | `33 c0` | `XOR EAX,EAX` |
| `1001d501` | `39 75 08` | `CMP dword ptr [EBP + 0x8],ESI` |
| `1001d504` | `0f 95 c0` | `SETNZ AL` |
| `1001d507` | `3b c6` | `CMP EAX,ESI` |
| `1001d509` | `74 d6` | `JZ 0x1001d4e1` |
| `1001d50b` | `39 75 1c` | `CMP dword ptr [EBP + 0x1c],ESI` |
| `1001d50e` | `74 0f` | `JZ 0x1001d51f` |
| `1001d510` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1001d513` | `25 7f fe ff ff` | `AND EAX,0xfffffe7f` |
| `1001d518` | `f7 d8` | `NEG EAX` |
| `1001d51a` | `1b c0` | `SBB EAX,EAX` |
| `1001d51c` | `40` | `INC EAX` |
| `1001d51d` | `74 c2` | `JZ 0x1001d4e1` |
| `1001d51f` | `89 75 fc` | `MOV dword ptr [EBP + -0x4],ESI` |
| `1001d522` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001d525` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001d528` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001d52b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001d52e` | `8d 45 e4` | `LEA EAX,[EBP + -0x1c]` |
| `1001d531` | `50` | `PUSH EAX` |
| `1001d532` | `8b c7` | `MOV EAX,EDI` |
| `1001d534` | `e8 6a f8 ff ff` | `CALL 0x1001cda3` |
| `1001d539` | `83 c4 14` | `ADD ESP,0x14` |
| `1001d53c` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001d53f` | `c7 45 fc fe ff ff ff` | `MOV dword ptr [EBP + -0x4],0xfffffffe` |
| `1001d546` | `e8 15 00 00 00` | `CALL 0x1001d560` |
| `1001d54b` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1001d54e` | `3b c6` | `CMP EAX,ESI` |
| `1001d550` | `74 03` | `JZ 0x1001d555` |
| `1001d552` | `83 0f ff` | `OR dword ptr [EDI],0xffffffff` |
| `1001d555` | `e8 e7 97 ff ff` | `CALL 0x10016d41` |
| `1001d55a` | `c3` | `RET` |
