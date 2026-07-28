# 1001a933 `___crtGetEnvironmentStringsA`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001a933 |
| `name` | ___crtGetEnvironmentStringsA |
| `namespace` | Global |
| `signature` | LPVOID __cdecl ___crtGetEnvironmentStringsA(void) |
| `size_bytes` | 311 |
| `stack_frame_size` | 20 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___crtGetEnvironmentStringsA |

## Decompiled C

```c

/* Library Function - Single Match
    ___crtGetEnvironmentStringsA
   
   Library: Visual Studio 2008 Release */

LPVOID __cdecl ___crtGetEnvironmentStringsA(void)

{
  char cVar1;
  WCHAR WVar2;
  DWORD DVar3;
  WCHAR *pWVar4;
  WCHAR *pWVar5;
  int iVar6;
  size_t _Size;
  LPSTR lpMultiByteStr;
  LPCH _Src;
  char *pcVar7;
  void *_Dst;
  LPWCH lpWideCharStr;
  LPSTR local_8;
  char *pcVar8;
  
  lpWideCharStr = (LPWCH)0x0;
  if (DAT_10039380 == 0) {
    lpWideCharStr = GetEnvironmentStringsW();
    if (lpWideCharStr != (LPWCH)0x0) {
      DAT_10039380 = 1;
      goto LAB_1001a988;
    }
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_10039380 = 2;
    }
  }
  if (DAT_10039380 != 1) {
    if ((DAT_10039380 != 2) && (DAT_10039380 != 0)) {
      return (LPVOID)0x0;
    }
    _Src = GetEnvironmentStrings();
    if (_Src == (LPCH)0x0) {
      return (LPVOID)0x0;
    }
    cVar1 = *_Src;
    pcVar7 = _Src;
    while (cVar1 != '\0') {
      do {
        pcVar8 = pcVar7;
        pcVar7 = pcVar8 + 1;
      } while (*pcVar7 != '\0');
      pcVar7 = pcVar8 + 2;
      cVar1 = *pcVar7;
    }
    _Dst = __malloc_crt((size_t)(pcVar7 + (1 - (int)_Src)));
    if (_Dst == (void *)0x0) {
      FreeEnvironmentStringsA(_Src);
      return (LPVOID)0x0;
    }
    _memcpy(_Dst,_Src,(size_t)(pcVar7 + (1 - (int)_Src)));
    FreeEnvironmentStringsA(_Src);
    return _Dst;
  }
LAB_1001a988:
  if ((lpWideCharStr == (LPWCH)0x0) &&
     (lpWideCharStr = GetEnvironmentStringsW(), lpWideCharStr == (LPWCH)0x0)) {
    return (LPVOID)0x0;
  }
  WVar2 = *lpWideCharStr;
  pWVar5 = lpWideCharStr;
  while (WVar2 != L'\0') {
    do {
      pWVar4 = pWVar5;
      pWVar5 = pWVar4 + 1;
    } while (*pWVar5 != L'\0');
    pWVar5 = pWVar4 + 2;
    WVar2 = *pWVar5;
  }
  iVar6 = ((int)pWVar5 - (int)lpWideCharStr >> 1) + 1;
  _Size = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
  local_8 = (LPSTR)0x0;
  if (((_Size != 0) && (lpMultiByteStr = __malloc_crt(_Size), lpMultiByteStr != (LPSTR)0x0)) &&
     (iVar6 = WideCharToMultiByte(0,0,lpWideCharStr,iVar6,lpMultiByteStr,_Size,(LPCSTR)0x0,
                                  (LPBOOL)0x0), local_8 = lpMultiByteStr, iVar6 == 0)) {
    _free(lpMultiByteStr);
    local_8 = (LPSTR)0x0;
  }
  FreeEnvironmentStringsW(lpWideCharStr);
  return local_8;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001a951` | `EXTERNAL:0000005b` | `COMPUTED_CALL` | KERNEL32.DLL::GetEnvironmentStringsW | `` |
| `1001a965` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001a98c` | `EXTERNAL:0000005b` | `COMPUTED_CALL` | KERNEL32.DLL::GetEnvironmentStringsW | `` |
| `1001a9c6` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001a9d0` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001a9e9` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001a9f2` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001a9ff` | `EXTERNAL:0000005a` | `COMPUTED_CALL` | KERNEL32.DLL::FreeEnvironmentStringsW | `` |
| `1001aa12` | `EXTERNAL:00000059` | `COMPUTED_CALL` | KERNEL32.DLL::GetEnvironmentStrings | `` |
| `1001aa37` | `1001a4cf` | `UNCONDITIONAL_CALL` | __malloc_crt | `1001a4cf` |
| `1001aa44` | `EXTERNAL:00000058` | `COMPUTED_CALL` | KERNEL32.DLL::FreeEnvironmentStringsA | `` |
| `1001aa54` | `10010ce0` | `UNCONDITIONAL_CALL` | _memcpy | `10010ce0` |
| `1001aa5d` | `EXTERNAL:00000058` | `COMPUTED_CALL` | KERNEL32.DLL::FreeEnvironmentStringsA | `` |

## Callers

| From | Function |
| --- | --- |
| `100146b0` | __CRT_INIT@12 |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001a938` | `10039380` | `READ` | DAT_10039380 |
| `1001a942` | `1002e124` | `READ` | PTR_GetEnvironmentStringsW_1002e124 |
| `1001a959` | `10039380` | `WRITE` | DAT_10039380 |
| `1001a965` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001a973` | `10039380` | `WRITE` | DAT_10039380 |
| `1001a97a` | `10039380` | `READ` | DAT_10039380 |
| `1001a9b0` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001a9ff` | `1002e120` | `READ` | PTR_FreeEnvironmentStringsW_1002e120 |
| `1001aa12` | `1002e11c` | `READ` | PTR_GetEnvironmentStrings_1002e11c |
| `1001aa44` | `1002e118` | `READ` | PTR_FreeEnvironmentStringsA_1002e118 |
| `1001aa5d` | `1002e118` | `READ` | PTR_FreeEnvironmentStringsA_1002e118 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001a933` | `8b ff` | `MOV EDI,EDI` |
| `1001a935` | `55` | `PUSH EBP` |
| `1001a936` | `8b ec` | `MOV EBP,ESP` |
| `1001a938` | `a1 80 93 03 10` | `MOV EAX,[0x10039380]` |
| `1001a93d` | `83 ec 0c` | `SUB ESP,0xc` |
| `1001a940` | `53` | `PUSH EBX` |
| `1001a941` | `56` | `PUSH ESI` |
| `1001a942` | `8b 35 24 e1 02 10` | `MOV ESI,dword ptr [0x1002e124]` |
| `1001a948` | `57` | `PUSH EDI` |
| `1001a949` | `33 db` | `XOR EBX,EBX` |
| `1001a94b` | `33 ff` | `XOR EDI,EDI` |
| `1001a94d` | `3b c3` | `CMP EAX,EBX` |
| `1001a94f` | `75 2e` | `JNZ 0x1001a97f` |
| `1001a951` | `ff d6` | `CALL ESI` |
| `1001a953` | `8b f8` | `MOV EDI,EAX` |
| `1001a955` | `3b fb` | `CMP EDI,EBX` |
| `1001a957` | `74 0c` | `JZ 0x1001a965` |
| `1001a959` | `c7 05 80 93 03 10 01 00 00 00` | `MOV dword ptr [0x10039380],0x1` |
| `1001a963` | `eb 23` | `JMP 0x1001a988` |
| `1001a965` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001a96b` | `83 f8 78` | `CMP EAX,0x78` |
| `1001a96e` | `75 0a` | `JNZ 0x1001a97a` |
| `1001a970` | `6a 02` | `PUSH 0x2` |
| `1001a972` | `58` | `POP EAX` |
| `1001a973` | `a3 80 93 03 10` | `MOV [0x10039380],EAX` |
| `1001a978` | `eb 05` | `JMP 0x1001a97f` |
| `1001a97a` | `a1 80 93 03 10` | `MOV EAX,[0x10039380]` |
| `1001a97f` | `83 f8 01` | `CMP EAX,0x1` |
| `1001a982` | `0f 85 81 00 00 00` | `JNZ 0x1001aa09` |
| `1001a988` | `3b fb` | `CMP EDI,EBX` |
| `1001a98a` | `75 0f` | `JNZ 0x1001a99b` |
| `1001a98c` | `ff d6` | `CALL ESI` |
| `1001a98e` | `8b f8` | `MOV EDI,EAX` |
| `1001a990` | `3b fb` | `CMP EDI,EBX` |
| `1001a992` | `75 07` | `JNZ 0x1001a99b` |
| `1001a994` | `33 c0` | `XOR EAX,EAX` |
| `1001a996` | `e9 ca 00 00 00` | `JMP 0x1001aa65` |
| `1001a99b` | `8b c7` | `MOV EAX,EDI` |
| `1001a99d` | `66 39 1f` | `CMP word ptr [EDI],BX` |
| `1001a9a0` | `74 0e` | `JZ 0x1001a9b0` |
| `1001a9a2` | `40` | `INC EAX` |
| `1001a9a3` | `40` | `INC EAX` |
| `1001a9a4` | `66 39 18` | `CMP word ptr [EAX],BX` |
| `1001a9a7` | `75 f9` | `JNZ 0x1001a9a2` |
| `1001a9a9` | `40` | `INC EAX` |
| `1001a9aa` | `40` | `INC EAX` |
| `1001a9ab` | `66 39 18` | `CMP word ptr [EAX],BX` |
| `1001a9ae` | `75 f2` | `JNZ 0x1001a9a2` |
| `1001a9b0` | `8b 35 5c e0 02 10` | `MOV ESI,dword ptr [0x1002e05c]` |
| `1001a9b6` | `53` | `PUSH EBX` |
| `1001a9b7` | `53` | `PUSH EBX` |
| `1001a9b8` | `53` | `PUSH EBX` |
| `1001a9b9` | `2b c7` | `SUB EAX,EDI` |
| `1001a9bb` | `53` | `PUSH EBX` |
| `1001a9bc` | `d1 f8` | `SAR EAX,0x1` |
| `1001a9be` | `40` | `INC EAX` |
| `1001a9bf` | `50` | `PUSH EAX` |
| `1001a9c0` | `57` | `PUSH EDI` |
| `1001a9c1` | `53` | `PUSH EBX` |
| `1001a9c2` | `53` | `PUSH EBX` |
| `1001a9c3` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1001a9c6` | `ff d6` | `CALL ESI` |
| `1001a9c8` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001a9cb` | `3b c3` | `CMP EAX,EBX` |
| `1001a9cd` | `74 2f` | `JZ 0x1001a9fe` |
| `1001a9cf` | `50` | `PUSH EAX` |
| `1001a9d0` | `e8 fa fa ff ff` | `CALL 0x1001a4cf` |
| `1001a9d5` | `59` | `POP ECX` |
| `1001a9d6` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001a9d9` | `3b c3` | `CMP EAX,EBX` |
| `1001a9db` | `74 21` | `JZ 0x1001a9fe` |
| `1001a9dd` | `53` | `PUSH EBX` |
| `1001a9de` | `53` | `PUSH EBX` |
| `1001a9df` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001a9e2` | `50` | `PUSH EAX` |
| `1001a9e3` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001a9e6` | `57` | `PUSH EDI` |
| `1001a9e7` | `53` | `PUSH EBX` |
| `1001a9e8` | `53` | `PUSH EBX` |
| `1001a9e9` | `ff d6` | `CALL ESI` |
| `1001a9eb` | `85 c0` | `TEST EAX,EAX` |
| `1001a9ed` | `75 0c` | `JNZ 0x1001a9fb` |
| `1001a9ef` | `ff 75 fc` | `PUSH dword ptr [EBP + -0x4]` |
| `1001a9f2` | `e8 4a 68 ff ff` | `CALL 0x10011241` |
| `1001a9f7` | `59` | `POP ECX` |
| `1001a9f8` | `89 5d fc` | `MOV dword ptr [EBP + -0x4],EBX` |
| `1001a9fb` | `8b 5d fc` | `MOV EBX,dword ptr [EBP + -0x4]` |
| `1001a9fe` | `57` | `PUSH EDI` |
| `1001a9ff` | `ff 15 20 e1 02 10` | `CALL dword ptr [0x1002e120]` |
| `1001aa05` | `8b c3` | `MOV EAX,EBX` |
| `1001aa07` | `eb 5c` | `JMP 0x1001aa65` |
| `1001aa09` | `83 f8 02` | `CMP EAX,0x2` |
| `1001aa0c` | `74 04` | `JZ 0x1001aa12` |
| `1001aa0e` | `3b c3` | `CMP EAX,EBX` |
| `1001aa10` | `75 82` | `JNZ 0x1001a994` |
| `1001aa12` | `ff 15 1c e1 02 10` | `CALL dword ptr [0x1002e11c]` |
| `1001aa18` | `8b f0` | `MOV ESI,EAX` |
| `1001aa1a` | `3b f3` | `CMP ESI,EBX` |
| `1001aa1c` | `0f 84 72 ff ff ff` | `JZ 0x1001a994` |
| `1001aa22` | `38 1e` | `CMP byte ptr [ESI],BL` |
| `1001aa24` | `74 0a` | `JZ 0x1001aa30` |
| `1001aa26` | `40` | `INC EAX` |
| `1001aa27` | `38 18` | `CMP byte ptr [EAX],BL` |
| `1001aa29` | `75 fb` | `JNZ 0x1001aa26` |
| `1001aa2b` | `40` | `INC EAX` |
| `1001aa2c` | `38 18` | `CMP byte ptr [EAX],BL` |
| `1001aa2e` | `75 f6` | `JNZ 0x1001aa26` |
| `1001aa30` | `2b c6` | `SUB EAX,ESI` |
| `1001aa32` | `40` | `INC EAX` |
| `1001aa33` | `50` | `PUSH EAX` |
| `1001aa34` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001aa37` | `e8 93 fa ff ff` | `CALL 0x1001a4cf` |
| `1001aa3c` | `8b f8` | `MOV EDI,EAX` |
| `1001aa3e` | `59` | `POP ECX` |
| `1001aa3f` | `3b fb` | `CMP EDI,EBX` |
| `1001aa41` | `75 0c` | `JNZ 0x1001aa4f` |
| `1001aa43` | `56` | `PUSH ESI` |
| `1001aa44` | `ff 15 18 e1 02 10` | `CALL dword ptr [0x1002e118]` |
| `1001aa4a` | `e9 45 ff ff ff` | `JMP 0x1001a994` |
| `1001aa4f` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001aa52` | `56` | `PUSH ESI` |
| `1001aa53` | `57` | `PUSH EDI` |
| `1001aa54` | `e8 87 62 ff ff` | `CALL 0x10010ce0` |
| `1001aa59` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001aa5c` | `56` | `PUSH ESI` |
| `1001aa5d` | `ff 15 18 e1 02 10` | `CALL dword ptr [0x1002e118]` |
| `1001aa63` | `8b c7` | `MOV EAX,EDI` |
| `1001aa65` | `5f` | `POP EDI` |
| `1001aa66` | `5e` | `POP ESI` |
| `1001aa67` | `5b` | `POP EBX` |
| `1001aa68` | `c9` | `LEAVE` |
| `1001aa69` | `c3` | `RET` |
