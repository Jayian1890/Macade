# 1001f502 `__lseek_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f502 |
| `name` | __lseek_nolock |
| `namespace` | Global |
| `signature` | long __cdecl __lseek_nolock(int _FileHandle, long _Offset, int _Origin) |
| `size_bytes` | 117 |
| `stack_frame_size` | 16 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __lseek_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __lseek_nolock
   
   Library: Visual Studio 2008 Release */

long __cdecl __lseek_nolock(int _FileHandle,long _Offset,int _Origin)

{
  byte *pbVar1;
  HANDLE hFile;
  int *piVar2;
  DWORD DVar3;
  ulong uVar4;
  
  hFile = (HANDLE)__get_osfhandle(_FileHandle);
  if (hFile == (HANDLE)0xffffffff) {
    piVar2 = __errno();
    *piVar2 = 9;
    DVar3 = 0xffffffff;
  }
  else {
    DVar3 = SetFilePointer(hFile,_Offset,(PLONG)0x0,_Origin);
    if (DVar3 == 0xffffffff) {
      uVar4 = GetLastError();
    }
    else {
      uVar4 = 0;
    }
    if (uVar4 == 0) {
      pbVar1 = (byte *)((&DAT_13439540)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x40);
      *pbVar1 = *pbVar1 & 0xfd;
    }
    else {
      __dosmaperr(uVar4);
      DVar3 = 0xffffffff;
    }
  }
  return DVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f50c` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `1001f517` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001f531` | `EXTERNAL:0000005f` | `COMPUTED_CALL` | KERNEL32.DLL::SetFilePointer | `` |
| `1001f53e` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001f54d` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |

## Callers

| From | Function |
| --- | --- |
| `1001d11a` | __tsopen_nolock |
| `1001d177` | __tsopen_nolock |
| `1001d365` | __tsopen_nolock |
| `1001d380` | __tsopen_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f531` | `1002e134` | `READ` | PTR_SetFilePointer_1002e134 |
| `1001f53e` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001f55d` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f502` | `8b ff` | `MOV EDI,EDI` |
| `1001f504` | `55` | `PUSH EBP` |
| `1001f505` | `8b ec` | `MOV EBP,ESP` |
| `1001f507` | `56` | `PUSH ESI` |
| `1001f508` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001f50b` | `56` | `PUSH ESI` |
| `1001f50c` | `e8 a5 e6 ff ff` | `CALL 0x1001dbb6` |
| `1001f511` | `59` | `POP ECX` |
| `1001f512` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001f515` | `75 10` | `JNZ 0x1001f527` |
| `1001f517` | `e8 ed 5b ff ff` | `CALL 0x10015109` |
| `1001f51c` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001f522` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001f525` | `eb 4d` | `JMP 0x1001f574` |
| `1001f527` | `57` | `PUSH EDI` |
| `1001f528` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001f52b` | `6a 00` | `PUSH 0x0` |
| `1001f52d` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f530` | `50` | `PUSH EAX` |
| `1001f531` | `ff 15 34 e1 02 10` | `CALL dword ptr [0x1002e134]` |
| `1001f537` | `8b f8` | `MOV EDI,EAX` |
| `1001f539` | `83 ff ff` | `CMP EDI,-0x1` |
| `1001f53c` | `75 08` | `JNZ 0x1001f546` |
| `1001f53e` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001f544` | `eb 02` | `JMP 0x1001f548` |
| `1001f546` | `33 c0` | `XOR EAX,EAX` |
| `1001f548` | `85 c0` | `TEST EAX,EAX` |
| `1001f54a` | `74 0c` | `JZ 0x1001f558` |
| `1001f54c` | `50` | `PUSH EAX` |
| `1001f54d` | `e8 dd 5b ff ff` | `CALL 0x1001512f` |
| `1001f552` | `59` | `POP ECX` |
| `1001f553` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001f556` | `eb 1b` | `JMP 0x1001f573` |
| `1001f558` | `8b c6` | `MOV EAX,ESI` |
| `1001f55a` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001f55d` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001f564` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001f567` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001f56a` | `8d 44 30 04` | `LEA EAX,[EAX + ESI*0x1 + 0x4]` |
| `1001f56e` | `80 20 fd` | `AND byte ptr [EAX],0xfd` |
| `1001f571` | `8b c7` | `MOV EAX,EDI` |
| `1001f573` | `5f` | `POP EDI` |
| `1001f574` | `5e` | `POP ESI` |
| `1001f575` | `5d` | `POP EBP` |
| `1001f576` | `c3` | `RET` |
