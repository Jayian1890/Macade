# 1001735d `__getptd_noexit`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001735d |
| `name` | __getptd_noexit |
| `namespace` | Global |
| `signature` | _ptiddata __cdecl __getptd_noexit(void) |
| `size_bytes` | 121 |
| `stack_frame_size` | 4 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __getptd_noexit |

## Decompiled C

```c

/* Library Function - Single Match
    __getptd_noexit
   
   Library: Visual Studio 2008 Release */

_ptiddata __cdecl __getptd_noexit(void)

{
  DWORD dwErrCode;
  code *pcVar1;
  _ptiddata _Ptd;
  int iVar2;
  DWORD DVar3;
  
  dwErrCode = GetLastError();
  pcVar1 = (code *)___set_flsgetvalue(DAT_100377f0);
  _Ptd = (_ptiddata)(*pcVar1)();
  if (_Ptd == (_ptiddata)0x0) {
    _Ptd = __calloc_crt(1,0x214);
    if (_Ptd != (_ptiddata)0x0) {
      pcVar1 = (code *)__decode_pointer(DAT_1003922c,DAT_100377f0,_Ptd);
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        _free(_Ptd);
        _Ptd = (_ptiddata)0x0;
      }
      else {
        __initptd(_Ptd,(pthreadlocinfo)0x0);
        DVar3 = GetCurrentThreadId();
        _Ptd->_thandle = 0xffffffff;
        _Ptd->_tid = DVar3;
      }
    }
  }
  SetLastError(dwErrCode);
  return _Ptd;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10017361` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001736f` | `10017205` | `UNCONDITIONAL_CALL` | ___set_flsgetvalue | `10017205` |
| `10017383` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001739d` | `1001718a` | `UNCONDITIONAL_CALL` | __decode_pointer | `1001718a` |
| `100173ac` | `10017276` | `UNCONDITIONAL_CALL` | __initptd | `10017276` |
| `100173b3` | `EXTERNAL:0000003a` | `COMPUTED_CALL` | KERNEL32.DLL::GetCurrentThreadId | `` |
| `100173c2` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `100173cb` | `EXTERNAL:0000004d` | `COMPUTED_CALL` | KERNEL32.DLL::SetLastError | `` |

## Callers

| From | Function |
| --- | --- |
| `10015109` | __errno |
| `100173d9` | __getptd |
| `1001511c` | ___doserrno |
| `10019758` | _raise |
| `1001954b` | __XcptFilter |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10017361` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `10017367` | `100377f0` | `READ` | DAT_100377f0 |
| `10017391` | `100377f0` | `READ` | DAT_100377f0 |
| `10017397` | `1003922c` | `READ` | DAT_1003922c |
| `100173b3` | `1002e0a0` | `READ` | PTR_GetCurrentThreadId_1002e0a0 |
| `100173cb` | `1002e0ec` | `READ` | PTR_SetLastError_1002e0ec |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001735d` | `8b ff` | `MOV EDI,EDI` |
| `1001735f` | `56` | `PUSH ESI` |
| `10017360` | `57` | `PUSH EDI` |
| `10017361` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `10017367` | `ff 35 f0 77 03 10` | `PUSH dword ptr [0x100377f0]` |
| `1001736d` | `8b f8` | `MOV EDI,EAX` |
| `1001736f` | `e8 91 fe ff ff` | `CALL 0x10017205` |
| `10017374` | `ff d0` | `CALL EAX` |
| `10017376` | `8b f0` | `MOV ESI,EAX` |
| `10017378` | `85 f6` | `TEST ESI,ESI` |
| `1001737a` | `75 4e` | `JNZ 0x100173ca` |
| `1001737c` | `68 14 02 00 00` | `PUSH 0x214` |
| `10017381` | `6a 01` | `PUSH 0x1` |
| `10017383` | `e8 8c 31 00 00` | `CALL 0x1001a514` |
| `10017388` | `8b f0` | `MOV ESI,EAX` |
| `1001738a` | `59` | `POP ECX` |
| `1001738b` | `59` | `POP ECX` |
| `1001738c` | `85 f6` | `TEST ESI,ESI` |
| `1001738e` | `74 3a` | `JZ 0x100173ca` |
| `10017390` | `56` | `PUSH ESI` |
| `10017391` | `ff 35 f0 77 03 10` | `PUSH dword ptr [0x100377f0]` |
| `10017397` | `ff 35 2c 92 03 10` | `PUSH dword ptr [0x1003922c]` |
| `1001739d` | `e8 e8 fd ff ff` | `CALL 0x1001718a` |
| `100173a2` | `59` | `POP ECX` |
| `100173a3` | `ff d0` | `CALL EAX` |
| `100173a5` | `85 c0` | `TEST EAX,EAX` |
| `100173a7` | `74 18` | `JZ 0x100173c1` |
| `100173a9` | `6a 00` | `PUSH 0x0` |
| `100173ab` | `56` | `PUSH ESI` |
| `100173ac` | `e8 c5 fe ff ff` | `CALL 0x10017276` |
| `100173b1` | `59` | `POP ECX` |
| `100173b2` | `59` | `POP ECX` |
| `100173b3` | `ff 15 a0 e0 02 10` | `CALL dword ptr [0x1002e0a0]` |
| `100173b9` | `83 4e 04 ff` | `OR dword ptr [ESI + 0x4],0xffffffff` |
| `100173bd` | `89 06` | `MOV dword ptr [ESI],EAX` |
| `100173bf` | `eb 09` | `JMP 0x100173ca` |
| `100173c1` | `56` | `PUSH ESI` |
| `100173c2` | `e8 7a 9e ff ff` | `CALL 0x10011241` |
| `100173c7` | `59` | `POP ECX` |
| `100173c8` | `33 f6` | `XOR ESI,ESI` |
| `100173ca` | `57` | `PUSH EDI` |
| `100173cb` | `ff 15 ec e0 02 10` | `CALL dword ptr [0x1002e0ec]` |
| `100173d1` | `5f` | `POP EDI` |
| `100173d2` | `8b c6` | `MOV EAX,ESI` |
| `100173d4` | `5e` | `POP ESI` |
| `100173d5` | `c3` | `RET` |
