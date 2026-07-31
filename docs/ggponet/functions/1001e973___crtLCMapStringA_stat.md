# 1001e973 `__crtLCMapStringA_stat`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001e973 |
| `name` | __crtLCMapStringA_stat |
| `namespace` | Global |
| `signature` | int __cdecl __crtLCMapStringA_stat(localeinfo_struct * param_1, ulong param_2, ulong param_3, char * param_4, int param_5, char * param_6, int param_7, int param_8, int param_9) |
| `size_bytes` | 933 |
| `stack_frame_size` | 76 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?__crtLCMapStringA_stat@@YAHPAUlocaleinfo_struct@@KKPBDHPADHHH@Z, __crtLCMapStringA_stat |

## Decompiled C

```c

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtLCMapStringA_stat(struct localeinfo_struct *,unsigned long,unsigned long,char
   const *,int,char *,int,int,int)
   
   Library: Visual Studio 2008 Release */

int __cdecl
__crtLCMapStringA_stat
          (localeinfo_struct *param_1,ulong param_2,ulong param_3,char *param_4,int param_5,
          char *param_6,int param_7,int param_8,int param_9)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  DWORD DVar4;
  char *pcVar5;
  uint cchWideChar;
  undefined4 *puVar6;
  LPCWSTR lpDestStr;
  LPSTR pCVar7;
  int *in_ECX;
  char *pcVar8;
  void *local_14;
  LPCWSTR local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (DAT_1003941c == 0) {
    iVar3 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x78) {
        DAT_1003941c = 2;
      }
    }
    else {
      DAT_1003941c = 1;
    }
  }
  pcVar5 = (char *)param_3;
  pcVar8 = param_4;
  if (0 < (int)param_4) {
    do {
      pcVar8 = pcVar8 + -1;
      if (*pcVar5 == '\0') goto LAB_1001e9e4;
      pcVar5 = pcVar5 + 1;
    } while (pcVar8 != (char *)0x0);
    pcVar8 = (char *)0xffffffff;
LAB_1001e9e4:
    pcVar5 = param_4 + -(int)pcVar8;
    bVar2 = (int)(pcVar5 + -1) < (int)param_4;
    param_4 = pcVar5 + -1;
    if (bVar2) {
      param_4 = pcVar5;
    }
  }
  if ((DAT_1003941c == 2) || (DAT_1003941c == 0)) {
    local_10 = (LPCWSTR)0x0;
    local_14 = (void *)0x0;
    if (param_1 == (localeinfo_struct *)0x0) {
      param_1 = *(localeinfo_struct **)(*in_ECX + 0x14);
    }
    if (param_7 == 0) {
      param_7 = *(int *)(*in_ECX + 4);
    }
    iVar3 = ___ansicp(param_1);
    if (iVar3 == -1) goto LAB_1001ed06;
    if (iVar3 == param_7) {
      LCMapStringA((LCID)param_1,param_2,(LPCSTR)param_3,(int)param_4,(LPSTR)param_5,(int)param_6);
    }
    else {
      local_10 = (LPCWSTR)___convertcp(param_7,iVar3,param_3,&param_4,0,0);
      if (local_10 == (LPCWSTR)0x0) goto LAB_1001ed06;
      local_c = LCMapStringA((LCID)param_1,param_2,(LPCSTR)local_10,(int)param_4,(LPSTR)0x0,0);
      if (local_c != 0) {
        if (((int)local_c < 1) || (0xffffffe0 < local_c)) {
          pCVar7 = (LPSTR)0x0;
        }
        else if (local_c + 8 < 0x401) {
          if (&stack0x00000000 == (undefined1 *)0x24) goto LAB_1001ece3;
          pCVar7 = &stack0xffffffe4;
        }
        else {
          pCVar7 = _malloc(local_c + 8);
          if (pCVar7 != (LPSTR)0x0) {
            pCVar7[0] = -0x23;
            pCVar7[1] = -0x23;
            pCVar7[2] = '\0';
            pCVar7[3] = '\0';
            pCVar7 = pCVar7 + 8;
          }
        }
        if (pCVar7 != (LPSTR)0x0) {
          _memset(pCVar7,0,local_c);
          local_c = LCMapStringA((LCID)param_1,param_2,(LPCSTR)local_10,(int)param_4,pCVar7,local_c)
          ;
          if (local_c != 0) {
            local_14 = (void *)___convertcp(iVar3,param_7,pCVar7,&local_c,param_5,param_6);
          }
          __freea(pCVar7);
        }
      }
    }
LAB_1001ece3:
    if (local_10 != (LPCWSTR)0x0) {
      _free(local_10);
    }
    if ((local_14 != (void *)0x0) && ((void *)param_5 != local_14)) {
      _free(local_14);
    }
    goto LAB_1001ed06;
  }
  if (DAT_1003941c != 1) goto LAB_1001ed06;
  local_c = 0;
  if (param_7 == 0) {
    param_7 = *(int *)(*in_ECX + 4);
  }
  cchWideChar = MultiByteToWideChar(param_7,(uint)(param_8 != 0) * 8 + 1,(LPCSTR)param_3,
                                    (int)param_4,(LPWSTR)0x0,0);
  if (cchWideChar == 0) goto LAB_1001ed06;
  if (((int)cchWideChar < 1) || (0xffffffe0 / cchWideChar < 2)) {
    local_10 = (LPCWSTR)0x0;
  }
  else {
    uVar1 = cchWideChar * 2 + 8;
    if (uVar1 < 0x401) {
      puVar6 = (undefined4 *)&stack0xffffffdc;
      local_10 = (LPCWSTR)&stack0xffffffdc;
      if (&stack0x00000000 != (undefined1 *)0x24) {
LAB_1001ea8c:
        local_10 = (LPCWSTR)(puVar6 + 2);
      }
    }
    else {
      puVar6 = _malloc(uVar1);
      local_10 = (LPCWSTR)0x0;
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = 0xdddd;
        goto LAB_1001ea8c;
      }
    }
  }
  if (local_10 == (LPCWSTR)0x0) goto LAB_1001ed06;
  iVar3 = MultiByteToWideChar(param_7,1,(LPCSTR)param_3,(int)param_4,local_10,cchWideChar);
  if ((iVar3 != 0) &&
     (local_c = LCMapStringW((LCID)param_1,param_2,local_10,cchWideChar,(LPWSTR)0x0,0), local_c != 0
     )) {
    if ((param_2 & 0x400) == 0) {
      if (((int)local_c < 1) || (0xffffffe0 / local_c < 2)) {
        lpDestStr = (LPCWSTR)0x0;
      }
      else {
        uVar1 = local_c * 2 + 8;
        if (uVar1 < 0x401) {
          if (&stack0x00000000 == (undefined1 *)0x24) goto LAB_1001eb9c;
          lpDestStr = (LPCWSTR)&stack0xffffffe4;
        }
        else {
          lpDestStr = _malloc(uVar1);
          if (lpDestStr != (LPCWSTR)0x0) {
            lpDestStr[0] = L'\xdddd';
            lpDestStr[1] = L'\0';
            lpDestStr = lpDestStr + 4;
          }
        }
      }
      if (lpDestStr != (LPCWSTR)0x0) {
        iVar3 = LCMapStringW((LCID)param_1,param_2,local_10,cchWideChar,lpDestStr,local_c);
        if (iVar3 != 0) {
          pCVar7 = (LPSTR)param_5;
          pcVar5 = param_6;
          if (param_6 == (char *)0x0) {
            pCVar7 = (LPSTR)0x0;
            pcVar5 = (char *)0x0;
          }
          local_c = WideCharToMultiByte(param_7,0,lpDestStr,local_c,pCVar7,(int)pcVar5,(LPCSTR)0x0,
                                        (LPBOOL)0x0);
        }
        __freea(lpDestStr);
      }
    }
    else if ((param_6 != (char *)0x0) && ((int)local_c <= (int)param_6)) {
      LCMapStringW((LCID)param_1,param_2,local_10,cchWideChar,(LPWSTR)param_5,(int)param_6);
    }
  }
LAB_1001eb9c:
  __freea(local_10);
LAB_1001ed06:
  iVar3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar3;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001e9a5` | `EXTERNAL:00000017` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringW | `` |
| `1001e9b7` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001ea43` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001ea68` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001ea7c` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001eaaf` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001eacb` | `EXTERNAL:00000017` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringW | `` |
| `1001eb05` | `EXTERNAL:00000017` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringW | `` |
| `1001eb27` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001eb3e` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001eb69` | `EXTERNAL:00000017` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringW | `` |
| `1001eb8c` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001eb96` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001eb9f` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001ebd0` | `1001f7bc` | `UNCONDITIONAL_CALL` | ___ansicp | `1001f7bc` |
| `1001ebfb` | `1001f805` | `UNCONDITIONAL_CALL` | ___convertcp | `1001f805` |
| `1001ec1c` | `EXTERNAL:00000018` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringA | `` |
| `1001ec3d` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001ec54` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001ec76` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001ec8e` | `EXTERNAL:00000018` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringA | `` |
| `1001ecac` | `1001f805` | `UNCONDITIONAL_CALL` | ___convertcp | `1001f805` |
| `1001ecc1` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001ecdb` | `EXTERNAL:00000018` | `COMPUTED_CALL` | KERNEL32.DLL::LCMapStringA | `` |
| `1001eceb` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001ecfe` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001ed11` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001ed46` | ___crtLCMapStringA |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001e97b` | `10037490` | `READ` | DAT_10037490 |
| `1001e98c` | `1003941c` | `READ` | DAT_1003941c |
| `1001e99a` | `1002fff8` | `DATA` | DAT_1002fff8 |
| `1001e9a5` | `1002e014` | `READ` | PTR_LCMapStringW_1002e014 |
| `1001e9af` | `1003941c` | `WRITE` | DAT_1003941c |
| `1001e9b7` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001e9c2` | `1003941c` | `WRITE` | DAT_1003941c |
| `1001e9f3` | `1003941c` | `READ` | DAT_1003941c |
| `1001ea22` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001eab9` | `1002e014` | `READ` | PTR_LCMapStringW_1002e014 |
| `1001eb69` | `1002e014` | `READ` | PTR_LCMapStringW_1002e014 |
| `1001eb8c` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001ec0a` | `1002e018` | `READ` | PTR_LCMapStringA_1002e018 |
| `1001ecdb` | `1002e018` | `READ` | PTR_LCMapStringA_1002e018 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001e973` | `8b ff` | `MOV EDI,EDI` |
| `1001e975` | `55` | `PUSH EBP` |
| `1001e976` | `8b ec` | `MOV EBP,ESP` |
| `1001e978` | `83 ec 14` | `SUB ESP,0x14` |
| `1001e97b` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001e980` | `33 c5` | `XOR EAX,EBP` |
| `1001e982` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001e985` | `53` | `PUSH EBX` |
| `1001e986` | `56` | `PUSH ESI` |
| `1001e987` | `33 db` | `XOR EBX,EBX` |
| `1001e989` | `57` | `PUSH EDI` |
| `1001e98a` | `8b f1` | `MOV ESI,ECX` |
| `1001e98c` | `39 1d 1c 94 03 10` | `CMP dword ptr [0x1003941c],EBX` |
| `1001e992` | `75 38` | `JNZ 0x1001e9cc` |
| `1001e994` | `53` | `PUSH EBX` |
| `1001e995` | `53` | `PUSH EBX` |
| `1001e996` | `33 ff` | `XOR EDI,EDI` |
| `1001e998` | `47` | `INC EDI` |
| `1001e999` | `57` | `PUSH EDI` |
| `1001e99a` | `68 f8 ff 02 10` | `PUSH 0x1002fff8` |
| `1001e99f` | `68 00 01 00 00` | `PUSH 0x100` |
| `1001e9a4` | `53` | `PUSH EBX` |
| `1001e9a5` | `ff 15 14 e0 02 10` | `CALL dword ptr [0x1002e014]` |
| `1001e9ab` | `85 c0` | `TEST EAX,EAX` |
| `1001e9ad` | `74 08` | `JZ 0x1001e9b7` |
| `1001e9af` | `89 3d 1c 94 03 10` | `MOV dword ptr [0x1003941c],EDI` |
| `1001e9b5` | `eb 15` | `JMP 0x1001e9cc` |
| `1001e9b7` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001e9bd` | `83 f8 78` | `CMP EAX,0x78` |
| `1001e9c0` | `75 0a` | `JNZ 0x1001e9cc` |
| `1001e9c2` | `c7 05 1c 94 03 10 02 00 00 00` | `MOV dword ptr [0x1003941c],0x2` |
| `1001e9cc` | `39 5d 14` | `CMP dword ptr [EBP + 0x14],EBX` |
| `1001e9cf` | `7e 22` | `JLE 0x1001e9f3` |
| `1001e9d1` | `8b 4d 14` | `MOV ECX,dword ptr [EBP + 0x14]` |
| `1001e9d4` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `1001e9d7` | `49` | `DEC ECX` |
| `1001e9d8` | `38 18` | `CMP byte ptr [EAX],BL` |
| `1001e9da` | `74 08` | `JZ 0x1001e9e4` |
| `1001e9dc` | `40` | `INC EAX` |
| `1001e9dd` | `3b cb` | `CMP ECX,EBX` |
| `1001e9df` | `75 f6` | `JNZ 0x1001e9d7` |
| `1001e9e1` | `83 c9 ff` | `OR ECX,0xffffffff` |
| `1001e9e4` | `8b 45 14` | `MOV EAX,dword ptr [EBP + 0x14]` |
| `1001e9e7` | `2b c1` | `SUB EAX,ECX` |
| `1001e9e9` | `48` | `DEC EAX` |
| `1001e9ea` | `3b 45 14` | `CMP EAX,dword ptr [EBP + 0x14]` |
| `1001e9ed` | `7d 01` | `JGE 0x1001e9f0` |
| `1001e9ef` | `40` | `INC EAX` |
| `1001e9f0` | `89 45 14` | `MOV dword ptr [EBP + 0x14],EAX` |
| `1001e9f3` | `a1 1c 94 03 10` | `MOV EAX,[0x1003941c]` |
| `1001e9f8` | `83 f8 02` | `CMP EAX,0x2` |
| `1001e9fb` | `0f 84 ac 01 00 00` | `JZ 0x1001ebad` |
| `1001ea01` | `3b c3` | `CMP EAX,EBX` |
| `1001ea03` | `0f 84 a4 01 00 00` | `JZ 0x1001ebad` |
| `1001ea09` | `83 f8 01` | `CMP EAX,0x1` |
| `1001ea0c` | `0f 85 cc 01 00 00` | `JNZ 0x1001ebde` |
| `1001ea12` | `89 5d f8` | `MOV dword ptr [EBP + -0x8],EBX` |
| `1001ea15` | `39 5d 20` | `CMP dword ptr [EBP + 0x20],EBX` |
| `1001ea18` | `75 08` | `JNZ 0x1001ea22` |
| `1001ea1a` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001ea1c` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001ea1f` | `89 45 20` | `MOV dword ptr [EBP + 0x20],EAX` |
| `1001ea22` | `8b 35 60 e0 02 10` | `MOV ESI,dword ptr [0x1002e060]` |
| `1001ea28` | `33 c0` | `XOR EAX,EAX` |
| `1001ea2a` | `39 5d 24` | `CMP dword ptr [EBP + 0x24],EBX` |
| `1001ea2d` | `53` | `PUSH EBX` |
| `1001ea2e` | `53` | `PUSH EBX` |
| `1001ea2f` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ea32` | `0f 95 c0` | `SETNZ AL` |
| `1001ea35` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ea38` | `8d 04 c5 01 00 00 00` | `LEA EAX,[EAX*0x8 + 0x1]` |
| `1001ea3f` | `50` | `PUSH EAX` |
| `1001ea40` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001ea43` | `ff d6` | `CALL ESI` |
| `1001ea45` | `8b f8` | `MOV EDI,EAX` |
| `1001ea47` | `3b fb` | `CMP EDI,EBX` |
| `1001ea49` | `0f 84 8f 01 00 00` | `JZ 0x1001ebde` |
| `1001ea4f` | `7e 43` | `JLE 0x1001ea94` |
| `1001ea51` | `6a e0` | `PUSH -0x20` |
| `1001ea53` | `33 d2` | `XOR EDX,EDX` |
| `1001ea55` | `58` | `POP EAX` |
| `1001ea56` | `f7 f7` | `DIV EDI` |
| `1001ea58` | `83 f8 02` | `CMP EAX,0x2` |
| `1001ea5b` | `72 37` | `JC 0x1001ea94` |
| `1001ea5d` | `8d 44 3f 08` | `LEA EAX,[EDI + EDI*0x1 + 0x8]` |
| `1001ea61` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1001ea66` | `77 13` | `JA 0x1001ea7b` |
| `1001ea68` | `e8 b3 08 00 00` | `CALL 0x1001f320` |
| `1001ea6d` | `8b c4` | `MOV EAX,ESP` |
| `1001ea6f` | `3b c3` | `CMP EAX,EBX` |
| `1001ea71` | `74 1c` | `JZ 0x1001ea8f` |
| `1001ea73` | `c7 00 cc cc 00 00` | `MOV dword ptr [EAX],0xcccc` |
| `1001ea79` | `eb 11` | `JMP 0x1001ea8c` |
| `1001ea7b` | `50` | `PUSH EAX` |
| `1001ea7c` | `e8 9d 28 ff ff` | `CALL 0x1001131e` |
| `1001ea81` | `59` | `POP ECX` |
| `1001ea82` | `3b c3` | `CMP EAX,EBX` |
| `1001ea84` | `74 09` | `JZ 0x1001ea8f` |
| `1001ea86` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001ea8c` | `83 c0 08` | `ADD EAX,0x8` |
| `1001ea8f` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1001ea92` | `eb 03` | `JMP 0x1001ea97` |
| `1001ea94` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `1001ea97` | `39 5d f4` | `CMP dword ptr [EBP + -0xc],EBX` |
| `1001ea9a` | `0f 84 3e 01 00 00` | `JZ 0x1001ebde` |
| `1001eaa0` | `57` | `PUSH EDI` |
| `1001eaa1` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eaa4` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001eaa7` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001eaaa` | `6a 01` | `PUSH 0x1` |
| `1001eaac` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001eaaf` | `ff d6` | `CALL ESI` |
| `1001eab1` | `85 c0` | `TEST EAX,EAX` |
| `1001eab3` | `0f 84 e3 00 00 00` | `JZ 0x1001eb9c` |
| `1001eab9` | `8b 35 14 e0 02 10` | `MOV ESI,dword ptr [0x1002e014]` |
| `1001eabf` | `53` | `PUSH EBX` |
| `1001eac0` | `53` | `PUSH EBX` |
| `1001eac1` | `57` | `PUSH EDI` |
| `1001eac2` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eac5` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001eac8` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001eacb` | `ff d6` | `CALL ESI` |
| `1001eacd` | `8b c8` | `MOV ECX,EAX` |
| `1001eacf` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1001ead2` | `3b cb` | `CMP ECX,EBX` |
| `1001ead4` | `0f 84 c2 00 00 00` | `JZ 0x1001eb9c` |
| `1001eada` | `f7 45 0c 00 04 00 00` | `TEST dword ptr [EBP + 0xc],0x400` |
| `1001eae1` | `74 29` | `JZ 0x1001eb0c` |
| `1001eae3` | `39 5d 1c` | `CMP dword ptr [EBP + 0x1c],EBX` |
| `1001eae6` | `0f 84 b0 00 00 00` | `JZ 0x1001eb9c` |
| `1001eaec` | `3b 4d 1c` | `CMP ECX,dword ptr [EBP + 0x1c]` |
| `1001eaef` | `0f 8f a7 00 00 00` | `JG 0x1001eb9c` |
| `1001eaf5` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001eaf8` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001eafb` | `57` | `PUSH EDI` |
| `1001eafc` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eaff` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001eb02` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001eb05` | `ff d6` | `CALL ESI` |
| `1001eb07` | `e9 90 00 00 00` | `JMP 0x1001eb9c` |
| `1001eb0c` | `3b cb` | `CMP ECX,EBX` |
| `1001eb0e` | `7e 45` | `JLE 0x1001eb55` |
| `1001eb10` | `6a e0` | `PUSH -0x20` |
| `1001eb12` | `33 d2` | `XOR EDX,EDX` |
| `1001eb14` | `58` | `POP EAX` |
| `1001eb15` | `f7 f1` | `DIV ECX` |
| `1001eb17` | `83 f8 02` | `CMP EAX,0x2` |
| `1001eb1a` | `72 39` | `JC 0x1001eb55` |
| `1001eb1c` | `8d 44 09 08` | `LEA EAX,[ECX + ECX*0x1 + 0x8]` |
| `1001eb20` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1001eb25` | `77 16` | `JA 0x1001eb3d` |
| `1001eb27` | `e8 f4 07 00 00` | `CALL 0x1001f320` |
| `1001eb2c` | `8b f4` | `MOV ESI,ESP` |
| `1001eb2e` | `3b f3` | `CMP ESI,EBX` |
| `1001eb30` | `74 6a` | `JZ 0x1001eb9c` |
| `1001eb32` | `c7 06 cc cc 00 00` | `MOV dword ptr [ESI],0xcccc` |
| `1001eb38` | `83 c6 08` | `ADD ESI,0x8` |
| `1001eb3b` | `eb 1a` | `JMP 0x1001eb57` |
| `1001eb3d` | `50` | `PUSH EAX` |
| `1001eb3e` | `e8 db 27 ff ff` | `CALL 0x1001131e` |
| `1001eb43` | `59` | `POP ECX` |
| `1001eb44` | `3b c3` | `CMP EAX,EBX` |
| `1001eb46` | `74 09` | `JZ 0x1001eb51` |
| `1001eb48` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001eb4e` | `83 c0 08` | `ADD EAX,0x8` |
| `1001eb51` | `8b f0` | `MOV ESI,EAX` |
| `1001eb53` | `eb 02` | `JMP 0x1001eb57` |
| `1001eb55` | `33 f6` | `XOR ESI,ESI` |
| `1001eb57` | `3b f3` | `CMP ESI,EBX` |
| `1001eb59` | `74 41` | `JZ 0x1001eb9c` |
| `1001eb5b` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001eb5e` | `56` | `PUSH ESI` |
| `1001eb5f` | `57` | `PUSH EDI` |
| `1001eb60` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eb63` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001eb66` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001eb69` | `ff 15 14 e0 02 10` | `CALL dword ptr [0x1002e014]` |
| `1001eb6f` | `85 c0` | `TEST EAX,EAX` |
| `1001eb71` | `74 22` | `JZ 0x1001eb95` |
| `1001eb73` | `53` | `PUSH EBX` |
| `1001eb74` | `53` | `PUSH EBX` |
| `1001eb75` | `39 5d 1c` | `CMP dword ptr [EBP + 0x1c],EBX` |
| `1001eb78` | `75 04` | `JNZ 0x1001eb7e` |
| `1001eb7a` | `53` | `PUSH EBX` |
| `1001eb7b` | `53` | `PUSH EBX` |
| `1001eb7c` | `eb 06` | `JMP 0x1001eb84` |
| `1001eb7e` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001eb81` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001eb84` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001eb87` | `56` | `PUSH ESI` |
| `1001eb88` | `53` | `PUSH EBX` |
| `1001eb89` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001eb8c` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `1001eb92` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001eb95` | `56` | `PUSH ESI` |
| `1001eb96` | `e8 59 e0 ff ff` | `CALL 0x1001cbf4` |
| `1001eb9b` | `59` | `POP ECX` |
| `1001eb9c` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eb9f` | `e8 50 e0 ff ff` | `CALL 0x1001cbf4` |
| `1001eba4` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001eba7` | `59` | `POP ECX` |
| `1001eba8` | `e9 59 01 00 00` | `JMP 0x1001ed06` |
| `1001ebad` | `89 5d f4` | `MOV dword ptr [EBP + -0xc],EBX` |
| `1001ebb0` | `89 5d f0` | `MOV dword ptr [EBP + -0x10],EBX` |
| `1001ebb3` | `39 5d 08` | `CMP dword ptr [EBP + 0x8],EBX` |
| `1001ebb6` | `75 08` | `JNZ 0x1001ebc0` |
| `1001ebb8` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001ebba` | `8b 40 14` | `MOV EAX,dword ptr [EAX + 0x14]` |
| `1001ebbd` | `89 45 08` | `MOV dword ptr [EBP + 0x8],EAX` |
| `1001ebc0` | `39 5d 20` | `CMP dword ptr [EBP + 0x20],EBX` |
| `1001ebc3` | `75 08` | `JNZ 0x1001ebcd` |
| `1001ebc5` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001ebc7` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001ebca` | `89 45 20` | `MOV dword ptr [EBP + 0x20],EAX` |
| `1001ebcd` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ebd0` | `e8 e7 0b 00 00` | `CALL 0x1001f7bc` |
| `1001ebd5` | `59` | `POP ECX` |
| `1001ebd6` | `89 45 ec` | `MOV dword ptr [EBP + -0x14],EAX` |
| `1001ebd9` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001ebdc` | `75 07` | `JNZ 0x1001ebe5` |
| `1001ebde` | `33 c0` | `XOR EAX,EAX` |
| `1001ebe0` | `e9 21 01 00 00` | `JMP 0x1001ed06` |
| `1001ebe5` | `3b 45 20` | `CMP EAX,dword ptr [EBP + 0x20]` |
| `1001ebe8` | `0f 84 db 00 00 00` | `JZ 0x1001ecc9` |
| `1001ebee` | `53` | `PUSH EBX` |
| `1001ebef` | `53` | `PUSH EBX` |
| `1001ebf0` | `8d 4d 14` | `LEA ECX,[EBP + 0x14]` |
| `1001ebf3` | `51` | `PUSH ECX` |
| `1001ebf4` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ebf7` | `50` | `PUSH EAX` |
| `1001ebf8` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001ebfb` | `e8 05 0c 00 00` | `CALL 0x1001f805` |
| `1001ec00` | `83 c4 18` | `ADD ESP,0x18` |
| `1001ec03` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1001ec06` | `3b c3` | `CMP EAX,EBX` |
| `1001ec08` | `74 d4` | `JZ 0x1001ebde` |
| `1001ec0a` | `8b 35 18 e0 02 10` | `MOV ESI,dword ptr [0x1002e018]` |
| `1001ec10` | `53` | `PUSH EBX` |
| `1001ec11` | `53` | `PUSH EBX` |
| `1001ec12` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ec15` | `50` | `PUSH EAX` |
| `1001ec16` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ec19` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ec1c` | `ff d6` | `CALL ESI` |
| `1001ec1e` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001ec21` | `3b c3` | `CMP EAX,EBX` |
| `1001ec23` | `75 07` | `JNZ 0x1001ec2c` |
| `1001ec25` | `33 f6` | `XOR ESI,ESI` |
| `1001ec27` | `e9 b7 00 00 00` | `JMP 0x1001ece3` |
| `1001ec2c` | `7e 3d` | `JLE 0x1001ec6b` |
| `1001ec2e` | `83 f8 e0` | `CMP EAX,-0x20` |
| `1001ec31` | `77 38` | `JA 0x1001ec6b` |
| `1001ec33` | `83 c0 08` | `ADD EAX,0x8` |
| `1001ec36` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1001ec3b` | `77 16` | `JA 0x1001ec53` |
| `1001ec3d` | `e8 de 06 00 00` | `CALL 0x1001f320` |
| `1001ec42` | `8b fc` | `MOV EDI,ESP` |
| `1001ec44` | `3b fb` | `CMP EDI,EBX` |
| `1001ec46` | `74 dd` | `JZ 0x1001ec25` |
| `1001ec48` | `c7 07 cc cc 00 00` | `MOV dword ptr [EDI],0xcccc` |
| `1001ec4e` | `83 c7 08` | `ADD EDI,0x8` |
| `1001ec51` | `eb 1a` | `JMP 0x1001ec6d` |
| `1001ec53` | `50` | `PUSH EAX` |
| `1001ec54` | `e8 c5 26 ff ff` | `CALL 0x1001131e` |
| `1001ec59` | `59` | `POP ECX` |
| `1001ec5a` | `3b c3` | `CMP EAX,EBX` |
| `1001ec5c` | `74 09` | `JZ 0x1001ec67` |
| `1001ec5e` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001ec64` | `83 c0 08` | `ADD EAX,0x8` |
| `1001ec67` | `8b f8` | `MOV EDI,EAX` |
| `1001ec69` | `eb 02` | `JMP 0x1001ec6d` |
| `1001ec6b` | `33 ff` | `XOR EDI,EDI` |
| `1001ec6d` | `3b fb` | `CMP EDI,EBX` |
| `1001ec6f` | `74 b4` | `JZ 0x1001ec25` |
| `1001ec71` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001ec74` | `53` | `PUSH EBX` |
| `1001ec75` | `57` | `PUSH EDI` |
| `1001ec76` | `e8 75 2a ff ff` | `CALL 0x100116f0` |
| `1001ec7b` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001ec7e` | `ff 75 f8` | `PUSH dword ptr [EBP + -0x8]` |
| `1001ec81` | `57` | `PUSH EDI` |
| `1001ec82` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ec85` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001ec88` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ec8b` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ec8e` | `ff d6` | `CALL ESI` |
| `1001ec90` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001ec93` | `3b c3` | `CMP EAX,EBX` |
| `1001ec95` | `75 04` | `JNZ 0x1001ec9b` |
| `1001ec97` | `33 f6` | `XOR ESI,ESI` |
| `1001ec99` | `eb 25` | `JMP 0x1001ecc0` |
| `1001ec9b` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001ec9e` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001eca1` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001eca4` | `50` | `PUSH EAX` |
| `1001eca5` | `57` | `PUSH EDI` |
| `1001eca6` | `ff 75 20` | `PUSH dword ptr [EBP + 0x20]` |
| `1001eca9` | `ff 75 ec` | `PUSH dword ptr [EBP + -0x14]` |
| `1001ecac` | `e8 54 0b 00 00` | `CALL 0x1001f805` |
| `1001ecb1` | `8b f0` | `MOV ESI,EAX` |
| `1001ecb3` | `89 75 f0` | `MOV dword ptr [EBP + -0x10],ESI` |
| `1001ecb6` | `83 c4 18` | `ADD ESP,0x18` |
| `1001ecb9` | `f7 de` | `NEG ESI` |
| `1001ecbb` | `1b f6` | `SBB ESI,ESI` |
| `1001ecbd` | `23 75 f8` | `AND ESI,dword ptr [EBP + -0x8]` |
| `1001ecc0` | `57` | `PUSH EDI` |
| `1001ecc1` | `e8 2e df ff ff` | `CALL 0x1001cbf4` |
| `1001ecc6` | `59` | `POP ECX` |
| `1001ecc7` | `eb 1a` | `JMP 0x1001ece3` |
| `1001ecc9` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001eccc` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001eccf` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ecd2` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ecd5` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ecd8` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ecdb` | `ff 15 18 e0 02 10` | `CALL dword ptr [0x1002e018]` |
| `1001ece1` | `8b f0` | `MOV ESI,EAX` |
| `1001ece3` | `39 5d f4` | `CMP dword ptr [EBP + -0xc],EBX` |
| `1001ece6` | `74 09` | `JZ 0x1001ecf1` |
| `1001ece8` | `ff 75 f4` | `PUSH dword ptr [EBP + -0xc]` |
| `1001eceb` | `e8 51 25 ff ff` | `CALL 0x10011241` |
| `1001ecf0` | `59` | `POP ECX` |
| `1001ecf1` | `8b 45 f0` | `MOV EAX,dword ptr [EBP + -0x10]` |
| `1001ecf4` | `3b c3` | `CMP EAX,EBX` |
| `1001ecf6` | `74 0c` | `JZ 0x1001ed04` |
| `1001ecf8` | `39 45 18` | `CMP dword ptr [EBP + 0x18],EAX` |
| `1001ecfb` | `74 07` | `JZ 0x1001ed04` |
| `1001ecfd` | `50` | `PUSH EAX` |
| `1001ecfe` | `e8 3e 25 ff ff` | `CALL 0x10011241` |
| `1001ed03` | `59` | `POP ECX` |
| `1001ed04` | `8b c6` | `MOV EAX,ESI` |
| `1001ed06` | `8d 65 e0` | `LEA ESP,[EBP + -0x20]` |
| `1001ed09` | `5f` | `POP EDI` |
| `1001ed0a` | `5e` | `POP ESI` |
| `1001ed0b` | `5b` | `POP EBX` |
| `1001ed0c` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001ed0f` | `33 cd` | `XOR ECX,EBP` |
| `1001ed11` | `e8 b5 1f ff ff` | `CALL 0x10010ccb` |
| `1001ed16` | `c9` | `LEAVE` |
| `1001ed17` | `c3` | `RET` |
