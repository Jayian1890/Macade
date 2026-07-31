# 1001f805 `___convertcp`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001f805 |
| `name` | ___convertcp |
| `namespace` | Global |
| `signature` | undefined ___convertcp(void) |
| `size_bytes` | 436 |
| `stack_frame_size` | 72 |
| `calling_convention` | unknown |
| `source_type` | ANALYSIS |
| `export_names` | ___convertcp |

## Decompiled C

```c

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    ___convertcp
   
   Library: Visual Studio 2008 Release */

void ___convertcp(UINT param_1,UINT param_2,char *param_3,uint *param_4,LPSTR param_5,int param_6)

{
  uint _Size;
  uint cbMultiByte;
  bool bVar1;
  BOOL BVar2;
  size_t sVar3;
  undefined4 *puVar4;
  int iVar5;
  LPSTR lpMultiByteStr;
  uint uVar6;
  bool bVar7;
  LPCWSTR local_20;
  _cpinfo local_1c;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  cbMultiByte = *param_4;
  bVar1 = false;
  if (param_1 == param_2) goto LAB_1001f9a7;
  BVar2 = GetCPInfo(param_1,&local_1c);
  if ((((BVar2 == 0) || (local_1c.MaxCharSize != 1)) ||
      (BVar2 = GetCPInfo(param_2,&local_1c), BVar2 == 0)) || (local_1c.MaxCharSize != 1)) {
    uVar6 = MultiByteToWideChar(param_1,1,param_3,cbMultiByte,(LPWSTR)0x0,0);
    bVar7 = false;
    if (uVar6 == 0) goto LAB_1001f9a7;
  }
  else {
    bVar1 = true;
    uVar6 = cbMultiByte;
    if (cbMultiByte == 0xffffffff) {
      sVar3 = _strlen(param_3);
      uVar6 = sVar3 + 1;
    }
    bVar7 = uVar6 == 0;
  }
  if ((bVar7 || (int)uVar6 < 0) || (0x7ffffff0 < uVar6)) {
    local_20 = (LPCWSTR)0x0;
  }
  else {
    _Size = uVar6 * 2 + 8;
    if (_Size < 0x401) {
      puVar4 = (undefined4 *)&stack0xffffffbc;
      local_20 = (LPCWSTR)&stack0xffffffbc;
      if (&stack0x00000000 != (undefined1 *)0x44) {
LAB_1001f8e7:
        local_20 = (LPCWSTR)(puVar4 + 2);
      }
    }
    else {
      puVar4 = _malloc(_Size);
      local_20 = (LPCWSTR)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = 0xdddd;
        goto LAB_1001f8e7;
      }
    }
  }
  if (local_20 != (LPCWSTR)0x0) {
    _memset(local_20,0,uVar6 * 2);
    iVar5 = MultiByteToWideChar(param_1,1,param_3,cbMultiByte,local_20,uVar6);
    if (iVar5 != 0) {
      if (param_5 == (LPSTR)0x0) {
        if (((bVar1) ||
            (uVar6 = WideCharToMultiByte(param_2,0,local_20,uVar6,(LPSTR)0x0,0,(LPCSTR)0x0,
                                         (LPBOOL)0x0), uVar6 != 0)) &&
           (lpMultiByteStr = __calloc_crt(1,uVar6), lpMultiByteStr != (LPSTR)0x0)) {
          uVar6 = WideCharToMultiByte(param_2,0,local_20,uVar6,lpMultiByteStr,uVar6,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (uVar6 == 0) {
            _free(lpMultiByteStr);
          }
          else if (cbMultiByte != 0xffffffff) {
            *param_4 = uVar6;
          }
        }
      }
      else {
        WideCharToMultiByte(param_2,0,local_20,uVar6,param_5,param_6,(LPCSTR)0x0,(LPBOOL)0x0);
      }
    }
    __freea(local_20);
  }
LAB_1001f9a7:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001f850` | `EXTERNAL:00000060` | `COMPUTED_CALL` | KERNEL32.DLL::GetCPInfo | `` |
| `1001f869` | `EXTERNAL:00000060` | `COMPUTED_CALL` | KERNEL32.DLL::GetCPInfo | `` |
| `1001f887` | `100113f0` | `UNCONDITIONAL_CALL` | _strlen | `100113f0` |
| `1001f8a7` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001f8c7` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001f8d7` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001f8ff` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001f916` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001f931` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001f957` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001f962` | `1001a514` | `UNCONDITIONAL_CALL` | __calloc_crt | `1001a514` |
| `1001f97c` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001f985` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001f99e` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001f9b2` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001e1a4` | __crtCompareStringA_stat |
| `1001e1c5` | __crtCompareStringA_stat |
| `1001eed0` | __crtGetStringTypeA_stat |
| `1001ebfb` | __crtLCMapStringA_stat |
| `1001ecac` | __crtLCMapStringA_stat |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001f80d` | `10037490` | `READ` | DAT_10037490 |
| `1001f845` | `1002e138` | `READ` | PTR_GetCPInfo_1002e138 |
| `1001f852` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001f931` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001f940` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001f805` | `8b ff` | `MOV EDI,EDI` |
| `1001f807` | `55` | `PUSH EBP` |
| `1001f808` | `8b ec` | `MOV EBP,ESP` |
| `1001f80a` | `83 ec 34` | `SUB ESP,0x34` |
| `1001f80d` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001f812` | `33 c5` | `XOR EAX,EBP` |
| `1001f814` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001f817` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001f81a` | `8b 4d 18` | `MOV ECX,dword ptr [EBP + 0x18]` |
| `1001f81d` | `89 45 d8` | `MOV dword ptr [EBP + -0x28],EAX` |
| `1001f820` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1001f823` | `53` | `PUSH EBX` |
| `1001f824` | `89 45 d0` | `MOV dword ptr [EBP + -0x30],EAX` |
| `1001f827` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001f829` | `56` | `PUSH ESI` |
| `1001f82a` | `89 45 dc` | `MOV dword ptr [EBP + -0x24],EAX` |
| `1001f82d` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1001f830` | `57` | `PUSH EDI` |
| `1001f831` | `33 ff` | `XOR EDI,EDI` |
| `1001f833` | `89 4d cc` | `MOV dword ptr [EBP + -0x34],ECX` |
| `1001f836` | `89 7d e0` | `MOV dword ptr [EBP + -0x20],EDI` |
| `1001f839` | `89 7d d4` | `MOV dword ptr [EBP + -0x2c],EDI` |
| `1001f83c` | `3b 45 0c` | `CMP EAX,dword ptr [EBP + 0xc]` |
| `1001f83f` | `0f 84 5f 01 00 00` | `JZ 0x1001f9a4` |
| `1001f845` | `8b 35 38 e1 02 10` | `MOV ESI,dword ptr [0x1002e138]` |
| `1001f84b` | `8d 4d e8` | `LEA ECX,[EBP + -0x18]` |
| `1001f84e` | `51` | `PUSH ECX` |
| `1001f84f` | `50` | `PUSH EAX` |
| `1001f850` | `ff d6` | `CALL ESI` |
| `1001f852` | `8b 1d 60 e0 02 10` | `MOV EBX,dword ptr [0x1002e060]` |
| `1001f858` | `85 c0` | `TEST EAX,EAX` |
| `1001f85a` | `74 5e` | `JZ 0x1001f8ba` |
| `1001f85c` | `83 7d e8 01` | `CMP dword ptr [EBP + -0x18],0x1` |
| `1001f860` | `75 58` | `JNZ 0x1001f8ba` |
| `1001f862` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001f865` | `50` | `PUSH EAX` |
| `1001f866` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f869` | `ff d6` | `CALL ESI` |
| `1001f86b` | `85 c0` | `TEST EAX,EAX` |
| `1001f86d` | `74 4b` | `JZ 0x1001f8ba` |
| `1001f86f` | `83 7d e8 01` | `CMP dword ptr [EBP + -0x18],0x1` |
| `1001f873` | `75 45` | `JNZ 0x1001f8ba` |
| `1001f875` | `8b 75 dc` | `MOV ESI,dword ptr [EBP + -0x24]` |
| `1001f878` | `c7 45 d4 01 00 00 00` | `MOV dword ptr [EBP + -0x2c],0x1` |
| `1001f87f` | `83 fe ff` | `CMP ESI,-0x1` |
| `1001f882` | `75 0c` | `JNZ 0x1001f890` |
| `1001f884` | `ff 75 d8` | `PUSH dword ptr [EBP + -0x28]` |
| `1001f887` | `e8 64 1b ff ff` | `CALL 0x100113f0` |
| `1001f88c` | `8b f0` | `MOV ESI,EAX` |
| `1001f88e` | `59` | `POP ECX` |
| `1001f88f` | `46` | `INC ESI` |
| `1001f890` | `3b f7` | `CMP ESI,EDI` |
| `1001f892` | `7e 5b` | `JLE 0x1001f8ef` |
| `1001f894` | `81 fe f0 ff ff 7f` | `CMP ESI,0x7ffffff0` |
| `1001f89a` | `77 53` | `JA 0x1001f8ef` |
| `1001f89c` | `8d 44 36 08` | `LEA EAX,[ESI + ESI*0x1 + 0x8]` |
| `1001f8a0` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1001f8a5` | `77 2f` | `JA 0x1001f8d6` |
| `1001f8a7` | `e8 74 fa ff ff` | `CALL 0x1001f320` |
| `1001f8ac` | `8b c4` | `MOV EAX,ESP` |
| `1001f8ae` | `3b c7` | `CMP EAX,EDI` |
| `1001f8b0` | `74 38` | `JZ 0x1001f8ea` |
| `1001f8b2` | `c7 00 cc cc 00 00` | `MOV dword ptr [EAX],0xcccc` |
| `1001f8b8` | `eb 2d` | `JMP 0x1001f8e7` |
| `1001f8ba` | `57` | `PUSH EDI` |
| `1001f8bb` | `57` | `PUSH EDI` |
| `1001f8bc` | `ff 75 dc` | `PUSH dword ptr [EBP + -0x24]` |
| `1001f8bf` | `ff 75 d8` | `PUSH dword ptr [EBP + -0x28]` |
| `1001f8c2` | `6a 01` | `PUSH 0x1` |
| `1001f8c4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f8c7` | `ff d3` | `CALL EBX` |
| `1001f8c9` | `8b f0` | `MOV ESI,EAX` |
| `1001f8cb` | `3b f7` | `CMP ESI,EDI` |
| `1001f8cd` | `75 c3` | `JNZ 0x1001f892` |
| `1001f8cf` | `33 c0` | `XOR EAX,EAX` |
| `1001f8d1` | `e9 d1 00 00 00` | `JMP 0x1001f9a7` |
| `1001f8d6` | `50` | `PUSH EAX` |
| `1001f8d7` | `e8 42 1a ff ff` | `CALL 0x1001131e` |
| `1001f8dc` | `59` | `POP ECX` |
| `1001f8dd` | `3b c7` | `CMP EAX,EDI` |
| `1001f8df` | `74 09` | `JZ 0x1001f8ea` |
| `1001f8e1` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001f8e7` | `83 c0 08` | `ADD EAX,0x8` |
| `1001f8ea` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001f8ed` | `eb 03` | `JMP 0x1001f8f2` |
| `1001f8ef` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `1001f8f2` | `39 7d e4` | `CMP dword ptr [EBP + -0x1c],EDI` |
| `1001f8f5` | `74 d8` | `JZ 0x1001f8cf` |
| `1001f8f7` | `8d 04 36` | `LEA EAX,[ESI + ESI*0x1]` |
| `1001f8fa` | `50` | `PUSH EAX` |
| `1001f8fb` | `57` | `PUSH EDI` |
| `1001f8fc` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f8ff` | `e8 ec 1d ff ff` | `CALL 0x100116f0` |
| `1001f904` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001f907` | `56` | `PUSH ESI` |
| `1001f908` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f90b` | `ff 75 dc` | `PUSH dword ptr [EBP + -0x24]` |
| `1001f90e` | `ff 75 d8` | `PUSH dword ptr [EBP + -0x28]` |
| `1001f911` | `6a 01` | `PUSH 0x1` |
| `1001f913` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001f916` | `ff d3` | `CALL EBX` |
| `1001f918` | `85 c0` | `TEST EAX,EAX` |
| `1001f91a` | `74 7f` | `JZ 0x1001f99b` |
| `1001f91c` | `8b 5d cc` | `MOV EBX,dword ptr [EBP + -0x34]` |
| `1001f91f` | `3b df` | `CMP EBX,EDI` |
| `1001f921` | `74 1d` | `JZ 0x1001f940` |
| `1001f923` | `57` | `PUSH EDI` |
| `1001f924` | `57` | `PUSH EDI` |
| `1001f925` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001f928` | `53` | `PUSH EBX` |
| `1001f929` | `56` | `PUSH ESI` |
| `1001f92a` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f92d` | `57` | `PUSH EDI` |
| `1001f92e` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f931` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `1001f937` | `85 c0` | `TEST EAX,EAX` |
| `1001f939` | `74 60` | `JZ 0x1001f99b` |
| `1001f93b` | `89 5d e0` | `MOV dword ptr [EBP + -0x20],EBX` |
| `1001f93e` | `eb 5b` | `JMP 0x1001f99b` |
| `1001f940` | `8b 1d 5c e0 02 10` | `MOV EBX,dword ptr [0x1002e05c]` |
| `1001f946` | `39 7d d4` | `CMP dword ptr [EBP + -0x2c],EDI` |
| `1001f949` | `75 14` | `JNZ 0x1001f95f` |
| `1001f94b` | `57` | `PUSH EDI` |
| `1001f94c` | `57` | `PUSH EDI` |
| `1001f94d` | `57` | `PUSH EDI` |
| `1001f94e` | `57` | `PUSH EDI` |
| `1001f94f` | `56` | `PUSH ESI` |
| `1001f950` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f953` | `57` | `PUSH EDI` |
| `1001f954` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f957` | `ff d3` | `CALL EBX` |
| `1001f959` | `8b f0` | `MOV ESI,EAX` |
| `1001f95b` | `3b f7` | `CMP ESI,EDI` |
| `1001f95d` | `74 3c` | `JZ 0x1001f99b` |
| `1001f95f` | `56` | `PUSH ESI` |
| `1001f960` | `6a 01` | `PUSH 0x1` |
| `1001f962` | `e8 ad ab ff ff` | `CALL 0x1001a514` |
| `1001f967` | `59` | `POP ECX` |
| `1001f968` | `59` | `POP ECX` |
| `1001f969` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001f96c` | `3b c7` | `CMP EAX,EDI` |
| `1001f96e` | `74 2b` | `JZ 0x1001f99b` |
| `1001f970` | `57` | `PUSH EDI` |
| `1001f971` | `57` | `PUSH EDI` |
| `1001f972` | `56` | `PUSH ESI` |
| `1001f973` | `50` | `PUSH EAX` |
| `1001f974` | `56` | `PUSH ESI` |
| `1001f975` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f978` | `57` | `PUSH EDI` |
| `1001f979` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001f97c` | `ff d3` | `CALL EBX` |
| `1001f97e` | `3b c7` | `CMP EAX,EDI` |
| `1001f980` | `75 0e` | `JNZ 0x1001f990` |
| `1001f982` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001f985` | `e8 b7 18 ff ff` | `CALL 0x10011241` |
| `1001f98a` | `59` | `POP ECX` |
| `1001f98b` | `89 7d e0` | `MOV dword ptr [EBP + -0x20],EDI` |
| `1001f98e` | `eb 0b` | `JMP 0x1001f99b` |
| `1001f990` | `83 7d dc ff` | `CMP dword ptr [EBP + -0x24],-0x1` |
| `1001f994` | `74 05` | `JZ 0x1001f99b` |
| `1001f996` | `8b 4d d0` | `MOV ECX,dword ptr [EBP + -0x30]` |
| `1001f999` | `89 01` | `MOV dword ptr [ECX],EAX` |
| `1001f99b` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001f99e` | `e8 51 d2 ff ff` | `CALL 0x1001cbf4` |
| `1001f9a3` | `59` | `POP ECX` |
| `1001f9a4` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1001f9a7` | `8d 65 c0` | `LEA ESP,[EBP + -0x40]` |
| `1001f9aa` | `5f` | `POP EDI` |
| `1001f9ab` | `5e` | `POP ESI` |
| `1001f9ac` | `5b` | `POP EBX` |
| `1001f9ad` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001f9b0` | `33 cd` | `XOR ECX,EBP` |
| `1001f9b2` | `e8 14 13 ff ff` | `CALL 0x10010ccb` |
| `1001f9b7` | `c9` | `LEAVE` |
| `1001f9b8` | `c3` | `RET` |
