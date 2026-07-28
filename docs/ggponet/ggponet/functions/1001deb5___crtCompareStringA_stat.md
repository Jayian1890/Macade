# 1001deb5 `__crtCompareStringA_stat`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001deb5 |
| `name` | __crtCompareStringA_stat |
| `namespace` | Global |
| `signature` | int __cdecl __crtCompareStringA_stat(localeinfo_struct * param_1, ulong param_2, ulong param_3, char * param_4, int param_5, char * param_6, int param_7, int param_8) |
| `size_bytes` | 880 |
| `stack_frame_size` | 96 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?__crtCompareStringA_stat@@YAHPAUlocaleinfo_struct@@KKPBDH1HH@Z, __crtCompareStringA_stat |

## Decompiled C

```c

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtCompareStringA_stat(struct localeinfo_struct *,unsigned long,unsigned long,char
   const *,int,char const *,int,int)
   
   Library: Visual Studio 2008 Release */

int __cdecl
__crtCompareStringA_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8)

{
  uint _Size;
  char *lpMultiByteStr;
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  BYTE *pBVar4;
  uint cchWideChar;
  undefined4 *puVar5;
  uint uVar6;
  LPWSTR lpWideCharStr;
  char *pcVar7;
  int *in_ECX;
  byte *in_EDX;
  byte *_Memory;
  int unaff_EDI;
  PCNZCH _Memory_00;
  byte *local_28;
  PCNZWCH local_24;
  char *local_20;
  _cpinfo local_1c;
  uint local_8;
  
  lpMultiByteStr = param_4;
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_20 = param_4;
  if (DAT_10039418 == 0) {
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 == 0x78) {
        DAT_10039418 = 2;
      }
    }
    else {
      DAT_10039418 = 1;
    }
  }
  if ((int)param_3 < 1) {
    if ((int)param_3 < -1) goto LAB_1001e213;
  }
  else {
    param_3 = strncnt((char *)param_3,unaff_EDI);
  }
  if (param_5 < 1) {
    if (param_5 < -1) goto LAB_1001e213;
  }
  else {
    param_5 = strncnt((char *)param_5,unaff_EDI);
  }
  if ((DAT_10039418 == 2) || (DAT_10039418 == 0)) {
    _Memory_00 = (PCNZCH)0x0;
    _Memory = (byte *)0x0;
    if (param_1 == (localeinfo_struct *)0x0) {
      param_1 = *(localeinfo_struct **)(*in_ECX + 0x14);
    }
    if (param_6 == (char *)0x0) {
      param_6 = *(char **)(*in_ECX + 4);
    }
    pcVar7 = (char *)___ansicp(param_1);
    if (pcVar7 == (char *)0xffffffff) goto LAB_1001e213;
    local_28 = in_EDX;
    if (pcVar7 != param_6) {
      _Memory = (byte *)___convertcp(param_6,pcVar7,in_EDX,&param_3,0,0);
      if (_Memory == (byte *)0x0) goto LAB_1001e213;
      _Memory_00 = (PCNZCH)___convertcp(param_6,pcVar7,lpMultiByteStr,&param_5,0,0);
      local_28 = _Memory;
      local_20 = _Memory_00;
      if (_Memory_00 == (PCNZCH)0x0) {
        _free(_Memory);
        goto LAB_1001e213;
      }
    }
    CompareStringA((LCID)param_1,param_2,(PCNZCH)local_28,param_3,local_20,param_5);
    if (_Memory != (byte *)0x0) {
      _free(_Memory);
      _free(_Memory_00);
    }
    goto LAB_1001e213;
  }
  if (DAT_10039418 != 1) goto LAB_1001e213;
  if (param_6 == (char *)0x0) {
    param_6 = *(char **)(*in_ECX + 4);
  }
  if ((param_3 == 0) || (param_5 == 0)) {
    if ((param_3 == param_5) ||
       (((1 < param_5 || (1 < (int)param_3)) ||
        (BVar3 = GetCPInfo((UINT)param_6,&local_1c), BVar3 == 0)))) goto LAB_1001e213;
    if (0 < (int)param_3) {
      if (1 < local_1c.MaxCharSize) {
        pBVar4 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar4[1] != 0)) &&
               ((*in_EDX < *pBVar4 || (pBVar4[1] < *in_EDX))))) {
          pBVar4 = pBVar4 + 2;
          local_1c.LeadByte[0] = *pBVar4;
        }
      }
      goto LAB_1001e213;
    }
    if (0 < param_5) {
      if (1 < local_1c.MaxCharSize) {
        pBVar4 = local_1c.LeadByte;
        while (((local_1c.LeadByte[0] != 0 && (pBVar4[1] != 0)) &&
               (((byte)*lpMultiByteStr < *pBVar4 || (pBVar4[1] < (byte)*lpMultiByteStr))))) {
          pBVar4 = pBVar4 + 2;
          local_1c.LeadByte[0] = *pBVar4;
        }
      }
      goto LAB_1001e213;
    }
  }
  cchWideChar = MultiByteToWideChar((UINT)param_6,9,(LPCSTR)in_EDX,param_3,(LPWSTR)0x0,0);
  if (cchWideChar == 0) goto LAB_1001e213;
  if (((int)cchWideChar < 1) || (0xffffffe0 / cchWideChar < 2)) {
    local_24 = (PCNZWCH)0x0;
  }
  else {
    uVar6 = cchWideChar * 2 + 8;
    if (uVar6 < 0x401) {
      puVar5 = (undefined4 *)&stack0xffffffc4;
      local_24 = (PCNZWCH)&stack0xffffffc4;
      if (&stack0x00000000 != (undefined1 *)0x3c) {
LAB_1001e08c:
        local_24 = (PCNZWCH)(puVar5 + 2);
      }
    }
    else {
      puVar5 = _malloc(uVar6);
      local_24 = (PCNZWCH)0x0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = 0xdddd;
        goto LAB_1001e08c;
      }
    }
  }
  if (local_24 == (PCNZWCH)0x0) goto LAB_1001e213;
  iVar1 = MultiByteToWideChar((UINT)param_6,1,(LPCSTR)in_EDX,param_3,local_24,cchWideChar);
  if ((iVar1 != 0) &&
     (uVar6 = MultiByteToWideChar((UINT)param_6,9,lpMultiByteStr,param_5,(LPWSTR)0x0,0), uVar6 != 0)
     ) {
    if (((int)uVar6 < 1) || (0xffffffe0 / uVar6 < 2)) {
      lpWideCharStr = (LPWSTR)0x0;
    }
    else {
      _Size = uVar6 * 2 + 8;
      if (_Size < 0x401) {
        if (&stack0x00000000 == (undefined1 *)0x3c) goto LAB_1001e14d;
        lpWideCharStr = (LPWSTR)&stack0xffffffcc;
      }
      else {
        lpWideCharStr = _malloc(_Size);
        if (lpWideCharStr != (LPWSTR)0x0) {
          lpWideCharStr[0] = L'\xdddd';
          lpWideCharStr[1] = L'\0';
          lpWideCharStr = lpWideCharStr + 4;
        }
      }
    }
    if (lpWideCharStr != (LPWSTR)0x0) {
      iVar1 = MultiByteToWideChar((UINT)param_6,1,lpMultiByteStr,param_5,lpWideCharStr,uVar6);
      if (iVar1 != 0) {
        CompareStringW((LCID)param_1,param_2,local_24,cchWideChar,lpWideCharStr,uVar6);
      }
      __freea(lpWideCharStr);
    }
  }
LAB_1001e14d:
  __freea(local_24);
LAB_1001e213:
  iVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar1;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001deee` | `EXTERNAL:0000001d` | `COMPUTED_CALL` | KERNEL32.DLL::CompareStringW | `` |
| `1001df04` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001df23` | `1001de97` | `UNCONDITIONAL_CALL` | strncnt | `1001de97` |
| `1001df37` | `1001de97` | `UNCONDITIONAL_CALL` | strncnt | `1001de97` |
| `1001dfb6` | `EXTERNAL:00000060` | `COMPUTED_CALL` | KERNEL32.DLL::GetCPInfo | `` |
| `1001e03c` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001e068` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001e07c` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001e0b1` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001e0ca` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001e0e8` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001e0ff` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001e129` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001e13d` | `EXTERNAL:0000001d` | `COMPUTED_CALL` | KERNEL32.DLL::CompareStringW | `` |
| `1001e147` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001e150` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001e17f` | `1001f7bc` | `UNCONDITIONAL_CALL` | ___ansicp | `1001f7bc` |
| `1001e1a4` | `1001f805` | `UNCONDITIONAL_CALL` | ___convertcp | `1001f805` |
| `1001e1c5` | `1001f805` | `UNCONDITIONAL_CALL` | ___convertcp | `1001f805` |
| `1001e1d4` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e1f7` | `EXTERNAL:0000001e` | `COMPUTED_CALL` | KERNEL32.DLL::CompareStringA | `` |
| `1001e204` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e20a` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001e21e` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001e250` | ___crtCompareStringA |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001debd` | `10037490` | `READ` | DAT_10037490 |
| `1001ded9` | `10039418` | `READ` | DAT_10039418 |
| `1001dee3` | `1002fff8` | `DATA` | DAT_1002fff8 |
| `1001dee8` | `1002fff8` | `DATA` | DAT_1002fff8 |
| `1001deeb` | `1002fff8` | `DATA` | DAT_1002fff8 |
| `1001deee` | `1002e02c` | `READ` | PTR_CompareStringW_1002e02c |
| `1001def8` | `10039418` | `WRITE` | DAT_10039418 |
| `1001df04` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001df0f` | `10039418` | `WRITE` | DAT_10039418 |
| `1001df56` | `10039418` | `READ` | DAT_10039418 |
| `1001dfb6` | `1002e138` | `READ` | PTR_GetCPInfo_1002e138 |
| `1001e02b` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001e13d` | `1002e02c` | `READ` | PTR_CompareStringW_1002e02c |
| `1001e1f7` | `1002e030` | `READ` | PTR_CompareStringA_1002e030 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001deb5` | `8b ff` | `MOV EDI,EDI` |
| `1001deb7` | `55` | `PUSH EBP` |
| `1001deb8` | `8b ec` | `MOV EBP,ESP` |
| `1001deba` | `83 ec 2c` | `SUB ESP,0x2c` |
| `1001debd` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001dec2` | `33 c5` | `XOR EAX,EBP` |
| `1001dec4` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001dec7` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1001deca` | `53` | `PUSH EBX` |
| `1001decb` | `56` | `PUSH ESI` |
| `1001decc` | `57` | `PUSH EDI` |
| `1001decd` | `33 ff` | `XOR EDI,EDI` |
| `1001decf` | `8b da` | `MOV EBX,EDX` |
| `1001ded1` | `8b f1` | `MOV ESI,ECX` |
| `1001ded3` | `89 5d dc` | `MOV dword ptr [EBP + -0x24],EBX` |
| `1001ded6` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1001ded9` | `39 3d 18 94 03 10` | `CMP dword ptr [0x10039418],EDI` |
| `1001dedf` | `75 38` | `JNZ 0x1001df19` |
| `1001dee1` | `6a 01` | `PUSH 0x1` |
| `1001dee3` | `b8 f8 ff 02 10` | `MOV EAX,0x1002fff8` |
| `1001dee8` | `50` | `PUSH EAX` |
| `1001dee9` | `6a 01` | `PUSH 0x1` |
| `1001deeb` | `50` | `PUSH EAX` |
| `1001deec` | `57` | `PUSH EDI` |
| `1001deed` | `57` | `PUSH EDI` |
| `1001deee` | `ff 15 2c e0 02 10` | `CALL dword ptr [0x1002e02c]` |
| `1001def4` | `85 c0` | `TEST EAX,EAX` |
| `1001def6` | `74 0c` | `JZ 0x1001df04` |
| `1001def8` | `c7 05 18 94 03 10 01 00 00 00` | `MOV dword ptr [0x10039418],0x1` |
| `1001df02` | `eb 15` | `JMP 0x1001df19` |
| `1001df04` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001df0a` | `83 f8 78` | `CMP EAX,0x78` |
| `1001df0d` | `75 0a` | `JNZ 0x1001df19` |
| `1001df0f` | `c7 05 18 94 03 10 02 00 00 00` | `MOV dword ptr [0x10039418],0x2` |
| `1001df19` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `1001df1c` | `7e 26` | `JLE 0x1001df44` |
| `1001df1e` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001df21` | `8b c3` | `MOV EAX,EBX` |
| `1001df23` | `e8 6f ff ff ff` | `CALL 0x1001de97` |
| `1001df28` | `59` | `POP ECX` |
| `1001df29` | `89 45 10` | `MOV dword ptr [EBP + 0x10],EAX` |
| `1001df2c` | `8b 55 18` | `MOV EDX,dword ptr [EBP + 0x18]` |
| `1001df2f` | `3b d7` | `CMP EDX,EDI` |
| `1001df31` | `7e 1e` | `JLE 0x1001df51` |
| `1001df33` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1001df36` | `52` | `PUSH EDX` |
| `1001df37` | `e8 5b ff ff ff` | `CALL 0x1001de97` |
| `1001df3c` | `8b d0` | `MOV EDX,EAX` |
| `1001df3e` | `59` | `POP ECX` |
| `1001df3f` | `89 55 18` | `MOV dword ptr [EBP + 0x18],EDX` |
| `1001df42` | `eb 12` | `JMP 0x1001df56` |
| `1001df44` | `83 7d 10 ff` | `CMP dword ptr [EBP + 0x10],-0x1` |
| `1001df48` | `7d e2` | `JGE 0x1001df2c` |
| `1001df4a` | `33 c0` | `XOR EAX,EAX` |
| `1001df4c` | `e9 c2 02 00 00` | `JMP 0x1001e213` |
| `1001df51` | `83 fa ff` | `CMP EDX,-0x1` |
| `1001df54` | `7c f4` | `JL 0x1001df4a` |
| `1001df56` | `8b 0d 18 94 03 10` | `MOV ECX,dword ptr [0x10039418]` |
| `1001df5c` | `83 f9 02` | `CMP ECX,0x2` |
| `1001df5f` | `0f 84 f9 01 00 00` | `JZ 0x1001e15e` |
| `1001df65` | `3b cf` | `CMP ECX,EDI` |
| `1001df67` | `0f 84 f1 01 00 00` | `JZ 0x1001e15e` |
| `1001df6d` | `33 c0` | `XOR EAX,EAX` |
| `1001df6f` | `40` | `INC EAX` |
| `1001df70` | `3b c8` | `CMP ECX,EAX` |
| `1001df72` | `75 d6` | `JNZ 0x1001df4a` |
| `1001df74` | `89 7d d8` | `MOV dword ptr [EBP + -0x28],EDI` |
| `1001df77` | `39 7d 1c` | `CMP dword ptr [EBP + 0x1c],EDI` |
| `1001df7a` | `75 08` | `JNZ 0x1001df84` |
| `1001df7c` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `1001df7e` | `8b 49 04` | `MOV ECX,dword ptr [ECX + 0x4]` |
| `1001df81` | `89 4d 1c` | `MOV dword ptr [EBP + 0x1c],ECX` |
| `1001df84` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `1001df87` | `74 08` | `JZ 0x1001df91` |
| `1001df89` | `3b d7` | `CMP EDX,EDI` |
| `1001df8b` | `0f 85 9a 00 00 00` | `JNZ 0x1001e02b` |
| `1001df91` | `39 55 10` | `CMP dword ptr [EBP + 0x10],EDX` |
| `1001df94` | `75 08` | `JNZ 0x1001df9e` |
| `1001df96` | `6a 02` | `PUSH 0x2` |
| `1001df98` | `58` | `POP EAX` |
| `1001df99` | `e9 75 02 00 00` | `JMP 0x1001e213` |
| `1001df9e` | `3b d0` | `CMP EDX,EAX` |
| `1001dfa0` | `0f 8f 6d 02 00 00` | `JG 0x1001e213` |
| `1001dfa6` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `1001dfa9` | `7e 04` | `JLE 0x1001dfaf` |
| `1001dfab` | `6a 03` | `PUSH 0x3` |
| `1001dfad` | `eb e9` | `JMP 0x1001df98` |
| `1001dfaf` | `8d 45 e8` | `LEA EAX,[EBP + -0x18]` |
| `1001dfb2` | `50` | `PUSH EAX` |
| `1001dfb3` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001dfb6` | `ff 15 38 e1 02 10` | `CALL dword ptr [0x1002e138]` |
| `1001dfbc` | `85 c0` | `TEST EAX,EAX` |
| `1001dfbe` | `74 8a` | `JZ 0x1001df4a` |
| `1001dfc0` | `39 7d 10` | `CMP dword ptr [EBP + 0x10],EDI` |
| `1001dfc3` | `7e 29` | `JLE 0x1001dfee` |
| `1001dfc5` | `83 7d e8 02` | `CMP dword ptr [EBP + -0x18],0x2` |
| `1001dfc9` | `72 e0` | `JC 0x1001dfab` |
| `1001dfcb` | `80 7d ee 00` | `CMP byte ptr [EBP + -0x12],0x0` |
| `1001dfcf` | `8d 45 ee` | `LEA EAX,[EBP + -0x12]` |
| `1001dfd2` | `74 d7` | `JZ 0x1001dfab` |
| `1001dfd4` | `8a 50 01` | `MOV DL,byte ptr [EAX + 0x1]` |
| `1001dfd7` | `84 d2` | `TEST DL,DL` |
| `1001dfd9` | `74 d0` | `JZ 0x1001dfab` |
| `1001dfdb` | `8a 0b` | `MOV CL,byte ptr [EBX]` |
| `1001dfdd` | `3a 08` | `CMP CL,byte ptr [EAX]` |
| `1001dfdf` | `72 04` | `JC 0x1001dfe5` |
| `1001dfe1` | `3a ca` | `CMP CL,DL` |
| `1001dfe3` | `76 b1` | `JBE 0x1001df96` |
| `1001dfe5` | `40` | `INC EAX` |
| `1001dfe6` | `40` | `INC EAX` |
| `1001dfe7` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `1001dfea` | `75 e8` | `JNZ 0x1001dfd4` |
| `1001dfec` | `eb bd` | `JMP 0x1001dfab` |
| `1001dfee` | `39 7d 18` | `CMP dword ptr [EBP + 0x18],EDI` |
| `1001dff1` | `7e 38` | `JLE 0x1001e02b` |
| `1001dff3` | `83 7d e8 02` | `CMP dword ptr [EBP + -0x18],0x2` |
| `1001dff7` | `73 08` | `JNC 0x1001e001` |
| `1001dff9` | `33 c0` | `XOR EAX,EAX` |
| `1001dffb` | `40` | `INC EAX` |
| `1001dffc` | `e9 12 02 00 00` | `JMP 0x1001e213` |
| `1001e001` | `80 7d ee 00` | `CMP byte ptr [EBP + -0x12],0x0` |
| `1001e005` | `8d 45 ee` | `LEA EAX,[EBP + -0x12]` |
| `1001e008` | `74 ef` | `JZ 0x1001dff9` |
| `1001e00a` | `8a 50 01` | `MOV DL,byte ptr [EAX + 0x1]` |
| `1001e00d` | `84 d2` | `TEST DL,DL` |
| `1001e00f` | `74 e8` | `JZ 0x1001dff9` |
| `1001e011` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1001e014` | `8a 09` | `MOV CL,byte ptr [ECX]` |
| `1001e016` | `3a 08` | `CMP CL,byte ptr [EAX]` |
| `1001e018` | `72 08` | `JC 0x1001e022` |
| `1001e01a` | `3a ca` | `CMP CL,DL` |
| `1001e01c` | `0f 86 74 ff ff ff` | `JBE 0x1001df96` |
| `1001e022` | `40` | `INC EAX` |
| `1001e023` | `40` | `INC EAX` |
| `1001e024` | `80 38 00` | `CMP byte ptr [EAX],0x0` |
| `1001e027` | `75 e1` | `JNZ 0x1001e00a` |
| `1001e029` | `eb ce` | `JMP 0x1001dff9` |
| `1001e02b` | `8b 35 60 e0 02 10` | `MOV ESI,dword ptr [0x1002e060]` |
| `1001e031` | `57` | `PUSH EDI` |
| `1001e032` | `57` | `PUSH EDI` |
| `1001e033` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001e036` | `53` | `PUSH EBX` |
| `1001e037` | `6a 09` | `PUSH 0x9` |
| `1001e039` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e03c` | `ff d6` | `CALL ESI` |
| `1001e03e` | `8b d8` | `MOV EBX,EAX` |
| `1001e040` | `89 5d d4` | `MOV dword ptr [EBP + -0x2c],EBX` |
| `1001e043` | `3b df` | `CMP EBX,EDI` |
| `1001e045` | `0f 84 ff fe ff ff` | `JZ 0x1001df4a` |
| `1001e04b` | `bf 00 04 00 00` | `MOV EDI,0x400` |
| `1001e050` | `85 db` | `TEST EBX,EBX` |
| `1001e052` | `7e 40` | `JLE 0x1001e094` |
| `1001e054` | `6a e0` | `PUSH -0x20` |
| `1001e056` | `33 d2` | `XOR EDX,EDX` |
| `1001e058` | `58` | `POP EAX` |
| `1001e059` | `f7 f3` | `DIV EBX` |
| `1001e05b` | `83 f8 02` | `CMP EAX,0x2` |
| `1001e05e` | `72 34` | `JC 0x1001e094` |
| `1001e060` | `8d 44 1b 08` | `LEA EAX,[EBX + EBX*0x1 + 0x8]` |
| `1001e064` | `3b c7` | `CMP EAX,EDI` |
| `1001e066` | `77 13` | `JA 0x1001e07b` |
| `1001e068` | `e8 b3 12 00 00` | `CALL 0x1001f320` |
| `1001e06d` | `8b c4` | `MOV EAX,ESP` |
| `1001e06f` | `85 c0` | `TEST EAX,EAX` |
| `1001e071` | `74 1c` | `JZ 0x1001e08f` |
| `1001e073` | `c7 00 cc cc 00 00` | `MOV dword ptr [EAX],0xcccc` |
| `1001e079` | `eb 11` | `JMP 0x1001e08c` |
| `1001e07b` | `50` | `PUSH EAX` |
| `1001e07c` | `e8 9d 32 ff ff` | `CALL 0x1001131e` |
| `1001e081` | `59` | `POP ECX` |
| `1001e082` | `85 c0` | `TEST EAX,EAX` |
| `1001e084` | `74 09` | `JZ 0x1001e08f` |
| `1001e086` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001e08c` | `83 c0 08` | `ADD EAX,0x8` |
| `1001e08f` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1001e092` | `eb 04` | `JMP 0x1001e098` |
| `1001e094` | `83 65 e0 00` | `AND dword ptr [EBP + -0x20],0x0` |
| `1001e098` | `83 7d e0 00` | `CMP dword ptr [EBP + -0x20],0x0` |
| `1001e09c` | `0f 84 a8 fe ff ff` | `JZ 0x1001df4a` |
| `1001e0a2` | `53` | `PUSH EBX` |
| `1001e0a3` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001e0a6` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001e0a9` | `ff 75 dc` | `PUSH dword ptr [EBP + -0x24]` |
| `1001e0ac` | `6a 01` | `PUSH 0x1` |
| `1001e0ae` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e0b1` | `ff d6` | `CALL ESI` |
| `1001e0b3` | `85 c0` | `TEST EAX,EAX` |
| `1001e0b5` | `0f 84 92 00 00 00` | `JZ 0x1001e14d` |
| `1001e0bb` | `6a 00` | `PUSH 0x0` |
| `1001e0bd` | `6a 00` | `PUSH 0x0` |
| `1001e0bf` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001e0c2` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001e0c5` | `6a 09` | `PUSH 0x9` |
| `1001e0c7` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e0ca` | `ff d6` | `CALL ESI` |
| `1001e0cc` | `8b d8` | `MOV EBX,EAX` |
| `1001e0ce` | `85 db` | `TEST EBX,EBX` |
| `1001e0d0` | `74 7b` | `JZ 0x1001e14d` |
| `1001e0d2` | `7e 42` | `JLE 0x1001e116` |
| `1001e0d4` | `6a e0` | `PUSH -0x20` |
| `1001e0d6` | `33 d2` | `XOR EDX,EDX` |
| `1001e0d8` | `58` | `POP EAX` |
| `1001e0d9` | `f7 f3` | `DIV EBX` |
| `1001e0db` | `83 f8 02` | `CMP EAX,0x2` |
| `1001e0de` | `72 36` | `JC 0x1001e116` |
| `1001e0e0` | `8d 44 1b 08` | `LEA EAX,[EBX + EBX*0x1 + 0x8]` |
| `1001e0e4` | `3b c7` | `CMP EAX,EDI` |
| `1001e0e6` | `77 16` | `JA 0x1001e0fe` |
| `1001e0e8` | `e8 33 12 00 00` | `CALL 0x1001f320` |
| `1001e0ed` | `8b fc` | `MOV EDI,ESP` |
| `1001e0ef` | `85 ff` | `TEST EDI,EDI` |
| `1001e0f1` | `74 5a` | `JZ 0x1001e14d` |
| `1001e0f3` | `c7 07 cc cc 00 00` | `MOV dword ptr [EDI],0xcccc` |
| `1001e0f9` | `83 c7 08` | `ADD EDI,0x8` |
| `1001e0fc` | `eb 1a` | `JMP 0x1001e118` |
| `1001e0fe` | `50` | `PUSH EAX` |
| `1001e0ff` | `e8 1a 32 ff ff` | `CALL 0x1001131e` |
| `1001e104` | `59` | `POP ECX` |
| `1001e105` | `85 c0` | `TEST EAX,EAX` |
| `1001e107` | `74 09` | `JZ 0x1001e112` |
| `1001e109` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001e10f` | `83 c0 08` | `ADD EAX,0x8` |
| `1001e112` | `8b f8` | `MOV EDI,EAX` |
| `1001e114` | `eb 02` | `JMP 0x1001e118` |
| `1001e116` | `33 ff` | `XOR EDI,EDI` |
| `1001e118` | `85 ff` | `TEST EDI,EDI` |
| `1001e11a` | `74 31` | `JZ 0x1001e14d` |
| `1001e11c` | `53` | `PUSH EBX` |
| `1001e11d` | `57` | `PUSH EDI` |
| `1001e11e` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001e121` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001e124` | `6a 01` | `PUSH 0x1` |
| `1001e126` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e129` | `ff d6` | `CALL ESI` |
| `1001e12b` | `85 c0` | `TEST EAX,EAX` |
| `1001e12d` | `74 17` | `JZ 0x1001e146` |
| `1001e12f` | `53` | `PUSH EBX` |
| `1001e130` | `57` | `PUSH EDI` |
| `1001e131` | `ff 75 d4` | `PUSH dword ptr [EBP + -0x2c]` |
| `1001e134` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001e137` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001e13a` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e13d` | `ff 15 2c e0 02 10` | `CALL dword ptr [0x1002e02c]` |
| `1001e143` | `89 45 d8` | `MOV dword ptr [EBP + -0x28],EAX` |
| `1001e146` | `57` | `PUSH EDI` |
| `1001e147` | `e8 a8 ea ff ff` | `CALL 0x1001cbf4` |
| `1001e14c` | `59` | `POP ECX` |
| `1001e14d` | `ff 75 e0` | `PUSH dword ptr [EBP + -0x20]` |
| `1001e150` | `e8 9f ea ff ff` | `CALL 0x1001cbf4` |
| `1001e155` | `8b 45 d8` | `MOV EAX,dword ptr [EBP + -0x28]` |
| `1001e158` | `59` | `POP ECX` |
| `1001e159` | `e9 b5 00 00 00` | `JMP 0x1001e213` |
| `1001e15e` | `33 ff` | `XOR EDI,EDI` |
| `1001e160` | `33 db` | `XOR EBX,EBX` |
| `1001e162` | `39 7d 08` | `CMP dword ptr [EBP + 0x8],EDI` |
| `1001e165` | `75 08` | `JNZ 0x1001e16f` |
| `1001e167` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001e169` | `8b 40 14` | `MOV EAX,dword ptr [EAX + 0x14]` |
| `1001e16c` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `1001e16f` | `39 7d 1c` | `CMP dword ptr [EBP + 0x1c],EDI` |
| `1001e172` | `75 08` | `JNZ 0x1001e17c` |
| `1001e174` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001e176` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001e179` | `89 45 1c` | `MOV dword ptr [EBP + 0x1c],EAX` |
| `1001e17c` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e17f` | `e8 38 16 00 00` | `CALL 0x1001f7bc` |
| `1001e184` | `8b f0` | `MOV ESI,EAX` |
| `1001e186` | `59` | `POP ECX` |
| `1001e187` | `83 fe ff` | `CMP ESI,-0x1` |
| `1001e18a` | `0f 84 ba fd ff ff` | `JZ 0x1001df4a` |
| `1001e190` | `3b 75 1c` | `CMP ESI,dword ptr [EBP + 0x1c]` |
| `1001e193` | `74 50` | `JZ 0x1001e1e5` |
| `1001e195` | `6a 00` | `PUSH 0x0` |
| `1001e197` | `6a 00` | `PUSH 0x0` |
| `1001e199` | `8d 45 10` | `LEA EAX,[EBP + 0x10]` |
| `1001e19c` | `50` | `PUSH EAX` |
| `1001e19d` | `ff 75 dc` | `PUSH dword ptr [EBP + -0x24]` |
| `1001e1a0` | `56` | `PUSH ESI` |
| `1001e1a1` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e1a4` | `e8 5c 16 00 00` | `CALL 0x1001f805` |
| `1001e1a9` | `8b d8` | `MOV EBX,EAX` |
| `1001e1ab` | `83 c4 18` | `ADD ESP,0x18` |
| `1001e1ae` | `85 db` | `TEST EBX,EBX` |
| `1001e1b0` | `0f 84 94 fd ff ff` | `JZ 0x1001df4a` |
| `1001e1b6` | `6a 00` | `PUSH 0x0` |
| `1001e1b8` | `6a 00` | `PUSH 0x0` |
| `1001e1ba` | `8d 45 18` | `LEA EAX,[EBP + 0x18]` |
| `1001e1bd` | `50` | `PUSH EAX` |
| `1001e1be` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001e1c1` | `56` | `PUSH ESI` |
| `1001e1c2` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001e1c5` | `e8 3b 16 00 00` | `CALL 0x1001f805` |
| `1001e1ca` | `8b f8` | `MOV EDI,EAX` |
| `1001e1cc` | `83 c4 18` | `ADD ESP,0x18` |
| `1001e1cf` | `85 ff` | `TEST EDI,EDI` |
| `1001e1d1` | `75 0c` | `JNZ 0x1001e1df` |
| `1001e1d3` | `53` | `PUSH EBX` |
| `1001e1d4` | `e8 68 30 ff ff` | `CALL 0x10011241` |
| `1001e1d9` | `59` | `POP ECX` |
| `1001e1da` | `e9 6b fd ff ff` | `JMP 0x1001df4a` |
| `1001e1df` | `89 5d dc` | `MOV dword ptr [EBP + -0x24],EBX` |
| `1001e1e2` | `89 7d e4` | `MOV dword ptr [EBP + -0x1c],EDI` |
| `1001e1e5` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001e1e8` | `ff 75 e4` | `PUSH dword ptr [EBP + -0x1c]` |
| `1001e1eb` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001e1ee` | `ff 75 dc` | `PUSH dword ptr [EBP + -0x24]` |
| `1001e1f1` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001e1f4` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001e1f7` | `ff 15 30 e0 02 10` | `CALL dword ptr [0x1002e030]` |
| `1001e1fd` | `8b f0` | `MOV ESI,EAX` |
| `1001e1ff` | `85 db` | `TEST EBX,EBX` |
| `1001e201` | `74 0e` | `JZ 0x1001e211` |
| `1001e203` | `53` | `PUSH EBX` |
| `1001e204` | `e8 38 30 ff ff` | `CALL 0x10011241` |
| `1001e209` | `57` | `PUSH EDI` |
| `1001e20a` | `e8 32 30 ff ff` | `CALL 0x10011241` |
| `1001e20f` | `59` | `POP ECX` |
| `1001e210` | `59` | `POP ECX` |
| `1001e211` | `8b c6` | `MOV EAX,ESI` |
| `1001e213` | `8d 65 c8` | `LEA ESP,[EBP + -0x38]` |
| `1001e216` | `5f` | `POP EDI` |
| `1001e217` | `5e` | `POP ESI` |
| `1001e218` | `5b` | `POP EBX` |
| `1001e219` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001e21c` | `33 cd` | `XOR ECX,EBP` |
| `1001e21e` | `e8 a8 2a ff ff` | `CALL 0x10010ccb` |
| `1001e223` | `c9` | `LEAVE` |
| `1001e224` | `c3` | `RET` |
