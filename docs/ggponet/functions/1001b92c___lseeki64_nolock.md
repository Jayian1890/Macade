# 1001b92c `__lseeki64_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001b92c |
| `name` | __lseeki64_nolock |
| `namespace` | Global |
| `signature` | longlong __cdecl __lseeki64_nolock(int _FileHandle, longlong _Offset, int _Origin) |
| `size_bytes` | 133 |
| `stack_frame_size` | 36 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __lseeki64_nolock |

## Decompiled C

```c

/* Library Function - Single Match
    __lseeki64_nolock
   
   Library: Visual Studio 2008 Release */

longlong __cdecl __lseeki64_nolock(int _FileHandle,longlong _Offset,int _Origin)

{
  byte *pbVar1;
  HANDLE hFile;
  int *piVar2;
  DWORD DVar3;
  DWORD DVar4;
  LONG in_stack_00000008;
  LONG local_8;
  
  local_8 = (LONG)_Offset;
  hFile = (HANDLE)__get_osfhandle(_FileHandle);
  if (hFile == (HANDLE)0xffffffff) {
    piVar2 = __errno();
    *piVar2 = 9;
LAB_1001b95d:
    DVar3 = 0xffffffff;
    local_8 = -1;
  }
  else {
    DVar3 = SetFilePointer(hFile,in_stack_00000008,&local_8,_Offset._4_4_);
    if (DVar3 == 0xffffffff) {
      DVar4 = GetLastError();
      if (DVar4 != 0) {
        __dosmaperr(DVar4);
        goto LAB_1001b95d;
      }
    }
    pbVar1 = (byte *)((&DAT_13439540)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x40);
    *pbVar1 = *pbVar1 & 0xfd;
  }
  return CONCAT44(local_8,DVar3);
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001b945` | `1001dbb6` | `UNCONDITIONAL_CALL` | __get_osfhandle | `1001dbb6` |
| `1001b952` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001b96e` | `EXTERNAL:0000005f` | `COMPUTED_CALL` | KERNEL32.DLL::SetFilePointer | `` |
| `1001b97b` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001b986` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |

## Callers

| From | Function |
| --- | --- |
| `10019cbe` | __write_nolock |
| `1001ba7e` | __lseeki64 |
| `1001d284` | __tsopen_nolock |
| `1001d295` | __tsopen_nolock |
| `1001d304` | __tsopen_nolock |
| `1001d319` | __tsopen_nolock |
| `100186e2` | __read_nolock |
| `10018886` | __read_nolock |
| `10018960` | __read_nolock |
| `10018ac4` | __read_nolock |
| `1001f366` | __chsize_nolock |
| `1001f382` | __chsize_nolock |
| `1001f47d` | __chsize_nolock |
| `1001f4e8` | __chsize_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001b96e` | `1002e134` | `READ` | PTR_SetFilePointer_1002e134 |
| `1001b97b` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001b993` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001b92c` | `8b ff` | `MOV EDI,EDI` |
| `1001b92e` | `55` | `PUSH EBP` |
| `1001b92f` | `8b ec` | `MOV EBP,ESP` |
| `1001b931` | `51` | `PUSH ECX` |
| `1001b932` | `51` | `PUSH ECX` |
| `1001b933` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1001b936` | `56` | `PUSH ESI` |
| `1001b937` | `8b 75 08` | `MOV ESI,dword ptr [EBP + 0x8]` |
| `1001b93a` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001b93d` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001b940` | `57` | `PUSH EDI` |
| `1001b941` | `56` | `PUSH ESI` |
| `1001b942` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001b945` | `e8 6c 22 00 00` | `CALL 0x1001dbb6` |
| `1001b94a` | `83 cf ff` | `OR EDI,0xffffffff` |
| `1001b94d` | `59` | `POP ECX` |
| `1001b94e` | `3b c7` | `CMP EAX,EDI` |
| `1001b950` | `75 11` | `JNZ 0x1001b963` |
| `1001b952` | `e8 b2 97 ff ff` | `CALL 0x10015109` |
| `1001b957` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001b95d` | `8b c7` | `MOV EAX,EDI` |
| `1001b95f` | `8b d7` | `MOV EDX,EDI` |
| `1001b961` | `eb 4a` | `JMP 0x1001b9ad` |
| `1001b963` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001b966` | `8d 4d fc` | `LEA ECX,[EBP + -0x4]` |
| `1001b969` | `51` | `PUSH ECX` |
| `1001b96a` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001b96d` | `50` | `PUSH EAX` |
| `1001b96e` | `ff 15 34 e1 02 10` | `CALL dword ptr [0x1002e134]` |
| `1001b974` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001b977` | `3b c7` | `CMP EAX,EDI` |
| `1001b979` | `75 13` | `JNZ 0x1001b98e` |
| `1001b97b` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001b981` | `85 c0` | `TEST EAX,EAX` |
| `1001b983` | `74 09` | `JZ 0x1001b98e` |
| `1001b985` | `50` | `PUSH EAX` |
| `1001b986` | `e8 a4 97 ff ff` | `CALL 0x1001512f` |
| `1001b98b` | `59` | `POP ECX` |
| `1001b98c` | `eb cf` | `JMP 0x1001b95d` |
| `1001b98e` | `8b c6` | `MOV EAX,ESI` |
| `1001b990` | `c1 f8 05` | `SAR EAX,0x5` |
| `1001b993` | `8b 04 85 40 95 43 13` | `MOV EAX,dword ptr [EAX*0x4 + 0x13439540]` |
| `1001b99a` | `83 e6 1f` | `AND ESI,0x1f` |
| `1001b99d` | `c1 e6 06` | `SHL ESI,0x6` |
| `1001b9a0` | `8d 44 30 04` | `LEA EAX,[EAX + ESI*0x1 + 0x4]` |
| `1001b9a4` | `80 20 fd` | `AND byte ptr [EAX],0xfd` |
| `1001b9a7` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001b9aa` | `8b 55 fc` | `MOV EDX,dword ptr [EBP + -0x4]` |
| `1001b9ad` | `5f` | `POP EDI` |
| `1001b9ae` | `5e` | `POP ESI` |
| `1001b9af` | `c9` | `LEAVE` |
| `1001b9b0` | `c3` | `RET` |
