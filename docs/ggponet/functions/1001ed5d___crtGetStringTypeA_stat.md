# 1001ed5d `__crtGetStringTypeA_stat`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1001ed5d |
| `name` | __crtGetStringTypeA_stat |
| `namespace` | Global |
| `signature` | int __cdecl __crtGetStringTypeA_stat(localeinfo_struct * param_1, ulong param_2, char * param_3, int param_4, ushort * param_5, int param_6, int param_7, int param_8) |
| `size_bytes` | 442 |
| `stack_frame_size` | 60 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ?__crtGetStringTypeA_stat@@YAHPAUlocaleinfo_struct@@KPBDHPAGHHH@Z, __crtGetStringTypeA_stat |

## Decompiled C

```c

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* Library Function - Single Match
    int __cdecl __crtGetStringTypeA_stat(struct localeinfo_struct *,unsigned long,char const
   *,int,unsigned short *,int,int,int)
   
   Library: Visual Studio 2008 Release */

int __cdecl
__crtGetStringTypeA_stat
          (localeinfo_struct *param_1,ulong param_2,char *param_3,int param_4,ushort *param_5,
          int param_6,int param_7,int param_8)

{
  uint _Size;
  BOOL BVar1;
  DWORD DVar2;
  uint cchWideChar;
  undefined4 *puVar3;
  int iVar4;
  ushort *puVar5;
  int *in_ECX;
  LPCWSTR lpWideCharStr;
  void *_Memory;
  int *local_c;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  lpWideCharStr = (LPCWSTR)0x0;
  local_c = in_ECX;
  if (DAT_10039420 == 0) {
    BVar1 = GetStringTypeW(1,L"",1,(LPWORD)&local_c);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      if (DVar2 == 0x78) {
        DAT_10039420 = 2;
      }
      goto LAB_1001edb8;
    }
    DAT_10039420 = 1;
  }
  else {
LAB_1001edb8:
    if ((DAT_10039420 == 2) || (DAT_10039420 == 0)) {
      _Memory = (void *)0x0;
      if (param_6 == 0) {
        param_6 = *(int *)(*in_ECX + 0x14);
      }
      if (param_5 == (ushort *)0x0) {
        param_5 = *(ushort **)(*in_ECX + 4);
      }
      puVar5 = (ushort *)___ansicp(param_6);
      if ((puVar5 != (ushort *)0xffffffff) &&
         (((puVar5 == param_5 ||
           (_Memory = (void *)___convertcp(param_5,puVar5,param_2,&param_3,0,0),
           param_2 = (ulong)_Memory, _Memory != (void *)0x0)) &&
          (GetStringTypeA(param_6,(DWORD)param_1,(LPCSTR)param_2,(int)param_3,(LPWORD)param_4),
          _Memory != (void *)0x0)))) {
        _free(_Memory);
      }
      goto LAB_1001ef05;
    }
    if (DAT_10039420 != 1) goto LAB_1001ef05;
  }
  local_c = (int *)0x0;
  if (param_5 == (ushort *)0x0) {
    param_5 = *(ushort **)(*in_ECX + 4);
  }
  cchWideChar = MultiByteToWideChar((UINT)param_5,(uint)(param_7 != 0) * 8 + 1,(LPCSTR)param_2,
                                    (int)param_3,(LPWSTR)0x0,0);
  if (cchWideChar == 0) goto LAB_1001ef05;
  if ((0 < (int)cchWideChar) && (cchWideChar < 0x7ffffff1)) {
    _Size = cchWideChar * 2 + 8;
    if (_Size < 0x401) {
      puVar3 = (undefined4 *)&stack0xffffffe8;
      lpWideCharStr = (LPCWSTR)&stack0xffffffe8;
      if (&stack0x00000000 != (undefined1 *)0x18) {
LAB_1001ee48:
        lpWideCharStr = (LPCWSTR)(puVar3 + 2);
      }
    }
    else {
      puVar3 = _malloc(_Size);
      lpWideCharStr = (LPCWSTR)0x0;
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = 0xdddd;
        goto LAB_1001ee48;
      }
    }
  }
  if (lpWideCharStr != (LPCWSTR)0x0) {
    _memset(lpWideCharStr,0,cchWideChar * 2);
    iVar4 = MultiByteToWideChar((UINT)param_5,1,(LPCSTR)param_2,(int)param_3,lpWideCharStr,
                                cchWideChar);
    if (iVar4 != 0) {
      local_c = (int *)GetStringTypeW((DWORD)param_1,lpWideCharStr,iVar4,(LPWORD)param_4);
    }
    __freea(lpWideCharStr);
  }
LAB_1001ef05:
  iVar4 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar4;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1001ed8c` | `EXTERNAL:00000015` | `COMPUTED_CALL` | KERNEL32.DLL::GetStringTypeW | `` |
| `1001ed9e` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001ee03` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001ee24` | `1001f320` | `UNCONDITIONAL_CALL` | __alloca_probe_16 | `1001f320` |
| `1001ee38` | `1001131e` | `UNCONDITIONAL_CALL` | _malloc | `1001131e` |
| `1001ee58` | `100116f0` | `UNCONDITIONAL_CALL` | _memset | `100116f0` |
| `1001ee6d` | `EXTERNAL:0000002a` | `COMPUTED_CALL` | KERNEL32.DLL::MultiByteToWideChar | `` |
| `1001ee7b` | `EXTERNAL:00000015` | `COMPUTED_CALL` | KERNEL32.DLL::GetStringTypeW | `` |
| `1001ee85` | `1001cbf4` | `UNCONDITIONAL_CALL` | __freea | `1001cbf4` |
| `1001eeaf` | `1001f7bc` | `UNCONDITIONAL_CALL` | ___ansicp | `1001f7bc` |
| `1001eed0` | `1001f805` | `UNCONDITIONAL_CALL` | ___convertcp | `1001f805` |
| `1001eef0` | `EXTERNAL:00000016` | `COMPUTED_CALL` | KERNEL32.DLL::GetStringTypeA | `` |
| `1001eefd` | `10011241` | `UNCONDITIONAL_CALL` | _free | `10011241` |
| `1001ef10` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001ef42` | ___crtGetStringTypeA |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1001ed64` | `10037490` | `READ` | DAT_10037490 |
| `1001ed6e` | `10039420` | `READ` | DAT_10039420 |
| `1001ed86` | `1002fff8` | `DATA` | DAT_1002fff8 |
| `1001ed8c` | `1002e00c` | `READ` | PTR_GetStringTypeW_1002e00c |
| `1001ed96` | `10039420` | `WRITE` | DAT_10039420 |
| `1001ed9e` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001edac` | `10039420` | `WRITE` | DAT_10039420 |
| `1001edb3` | `10039420` | `READ` | DAT_10039420 |
| `1001ede2` | `1002e060` | `READ` | PTR_MultiByteToWideChar_1002e060 |
| `1001ee7b` | `1002e00c` | `READ` | PTR_GetStringTypeW_1002e00c |
| `1001eef0` | `1002e010` | `READ` | PTR_GetStringTypeA_1002e010 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1001ed5d` | `8b ff` | `MOV EDI,EDI` |
| `1001ed5f` | `55` | `PUSH EBP` |
| `1001ed60` | `8b ec` | `MOV EBP,ESP` |
| `1001ed62` | `51` | `PUSH ECX` |
| `1001ed63` | `51` | `PUSH ECX` |
| `1001ed64` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1001ed69` | `33 c5` | `XOR EAX,EBP` |
| `1001ed6b` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1001ed6e` | `a1 20 94 03 10` | `MOV EAX,[0x10039420]` |
| `1001ed73` | `53` | `PUSH EBX` |
| `1001ed74` | `56` | `PUSH ESI` |
| `1001ed75` | `33 db` | `XOR EBX,EBX` |
| `1001ed77` | `57` | `PUSH EDI` |
| `1001ed78` | `8b f9` | `MOV EDI,ECX` |
| `1001ed7a` | `3b c3` | `CMP EAX,EBX` |
| `1001ed7c` | `75 3a` | `JNZ 0x1001edb8` |
| `1001ed7e` | `8d 45 f8` | `LEA EAX,[EBP + -0x8]` |
| `1001ed81` | `50` | `PUSH EAX` |
| `1001ed82` | `33 f6` | `XOR ESI,ESI` |
| `1001ed84` | `46` | `INC ESI` |
| `1001ed85` | `56` | `PUSH ESI` |
| `1001ed86` | `68 f8 ff 02 10` | `PUSH 0x1002fff8` |
| `1001ed8b` | `56` | `PUSH ESI` |
| `1001ed8c` | `ff 15 0c e0 02 10` | `CALL dword ptr [0x1002e00c]` |
| `1001ed92` | `85 c0` | `TEST EAX,EAX` |
| `1001ed94` | `74 08` | `JZ 0x1001ed9e` |
| `1001ed96` | `89 35 20 94 03 10` | `MOV dword ptr [0x10039420],ESI` |
| `1001ed9c` | `eb 34` | `JMP 0x1001edd2` |
| `1001ed9e` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001eda4` | `83 f8 78` | `CMP EAX,0x78` |
| `1001eda7` | `75 0a` | `JNZ 0x1001edb3` |
| `1001eda9` | `6a 02` | `PUSH 0x2` |
| `1001edab` | `58` | `POP EAX` |
| `1001edac` | `a3 20 94 03 10` | `MOV [0x10039420],EAX` |
| `1001edb1` | `eb 05` | `JMP 0x1001edb8` |
| `1001edb3` | `a1 20 94 03 10` | `MOV EAX,[0x10039420]` |
| `1001edb8` | `83 f8 02` | `CMP EAX,0x2` |
| `1001edbb` | `0f 84 cf 00 00 00` | `JZ 0x1001ee90` |
| `1001edc1` | `3b c3` | `CMP EAX,EBX` |
| `1001edc3` | `0f 84 c7 00 00 00` | `JZ 0x1001ee90` |
| `1001edc9` | `83 f8 01` | `CMP EAX,0x1` |
| `1001edcc` | `0f 85 e8 00 00 00` | `JNZ 0x1001eeba` |
| `1001edd2` | `89 5d f8` | `MOV dword ptr [EBP + -0x8],EBX` |
| `1001edd5` | `39 5d 18` | `CMP dword ptr [EBP + 0x18],EBX` |
| `1001edd8` | `75 08` | `JNZ 0x1001ede2` |
| `1001edda` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001eddc` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001eddf` | `89 45 18` | `MOV dword ptr [EBP + 0x18],EAX` |
| `1001ede2` | `8b 35 60 e0 02 10` | `MOV ESI,dword ptr [0x1002e060]` |
| `1001ede8` | `33 c0` | `XOR EAX,EAX` |
| `1001edea` | `39 5d 20` | `CMP dword ptr [EBP + 0x20],EBX` |
| `1001eded` | `53` | `PUSH EBX` |
| `1001edee` | `53` | `PUSH EBX` |
| `1001edef` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001edf2` | `0f 95 c0` | `SETNZ AL` |
| `1001edf5` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001edf8` | `8d 04 c5 01 00 00 00` | `LEA EAX,[EAX*0x8 + 0x1]` |
| `1001edff` | `50` | `PUSH EAX` |
| `1001ee00` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001ee03` | `ff d6` | `CALL ESI` |
| `1001ee05` | `8b f8` | `MOV EDI,EAX` |
| `1001ee07` | `3b fb` | `CMP EDI,EBX` |
| `1001ee09` | `0f 84 ab 00 00 00` | `JZ 0x1001eeba` |
| `1001ee0f` | `7e 3c` | `JLE 0x1001ee4d` |
| `1001ee11` | `81 ff f0 ff ff 7f` | `CMP EDI,0x7ffffff0` |
| `1001ee17` | `77 34` | `JA 0x1001ee4d` |
| `1001ee19` | `8d 44 3f 08` | `LEA EAX,[EDI + EDI*0x1 + 0x8]` |
| `1001ee1d` | `3d 00 04 00 00` | `CMP EAX,0x400` |
| `1001ee22` | `77 13` | `JA 0x1001ee37` |
| `1001ee24` | `e8 f7 04 00 00` | `CALL 0x1001f320` |
| `1001ee29` | `8b c4` | `MOV EAX,ESP` |
| `1001ee2b` | `3b c3` | `CMP EAX,EBX` |
| `1001ee2d` | `74 1c` | `JZ 0x1001ee4b` |
| `1001ee2f` | `c7 00 cc cc 00 00` | `MOV dword ptr [EAX],0xcccc` |
| `1001ee35` | `eb 11` | `JMP 0x1001ee48` |
| `1001ee37` | `50` | `PUSH EAX` |
| `1001ee38` | `e8 e1 24 ff ff` | `CALL 0x1001131e` |
| `1001ee3d` | `59` | `POP ECX` |
| `1001ee3e` | `3b c3` | `CMP EAX,EBX` |
| `1001ee40` | `74 09` | `JZ 0x1001ee4b` |
| `1001ee42` | `c7 00 dd dd 00 00` | `MOV dword ptr [EAX],0xdddd` |
| `1001ee48` | `83 c0 08` | `ADD EAX,0x8` |
| `1001ee4b` | `8b d8` | `MOV EBX,EAX` |
| `1001ee4d` | `85 db` | `TEST EBX,EBX` |
| `1001ee4f` | `74 69` | `JZ 0x1001eeba` |
| `1001ee51` | `8d 04 3f` | `LEA EAX,[EDI + EDI*0x1]` |
| `1001ee54` | `50` | `PUSH EAX` |
| `1001ee55` | `6a 00` | `PUSH 0x0` |
| `1001ee57` | `53` | `PUSH EBX` |
| `1001ee58` | `e8 93 28 ff ff` | `CALL 0x100116f0` |
| `1001ee5d` | `83 c4 0c` | `ADD ESP,0xc` |
| `1001ee60` | `57` | `PUSH EDI` |
| `1001ee61` | `53` | `PUSH EBX` |
| `1001ee62` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001ee65` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001ee68` | `6a 01` | `PUSH 0x1` |
| `1001ee6a` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001ee6d` | `ff d6` | `CALL ESI` |
| `1001ee6f` | `85 c0` | `TEST EAX,EAX` |
| `1001ee71` | `74 11` | `JZ 0x1001ee84` |
| `1001ee73` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001ee76` | `50` | `PUSH EAX` |
| `1001ee77` | `53` | `PUSH EBX` |
| `1001ee78` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001ee7b` | `ff 15 0c e0 02 10` | `CALL dword ptr [0x1002e00c]` |
| `1001ee81` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1001ee84` | `53` | `PUSH EBX` |
| `1001ee85` | `e8 6a dd ff ff` | `CALL 0x1001cbf4` |
| `1001ee8a` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1001ee8d` | `59` | `POP ECX` |
| `1001ee8e` | `eb 75` | `JMP 0x1001ef05` |
| `1001ee90` | `33 f6` | `XOR ESI,ESI` |
| `1001ee92` | `39 5d 1c` | `CMP dword ptr [EBP + 0x1c],EBX` |
| `1001ee95` | `75 08` | `JNZ 0x1001ee9f` |
| `1001ee97` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001ee99` | `8b 40 14` | `MOV EAX,dword ptr [EAX + 0x14]` |
| `1001ee9c` | `89 45 1c` | `MOV dword ptr [EBP + 0x1c],EAX` |
| `1001ee9f` | `39 5d 18` | `CMP dword ptr [EBP + 0x18],EBX` |
| `1001eea2` | `75 08` | `JNZ 0x1001eeac` |
| `1001eea4` | `8b 07` | `MOV EAX,dword ptr [EDI]` |
| `1001eea6` | `8b 40 04` | `MOV EAX,dword ptr [EAX + 0x4]` |
| `1001eea9` | `89 45 18` | `MOV dword ptr [EBP + 0x18],EAX` |
| `1001eeac` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001eeaf` | `e8 08 09 00 00` | `CALL 0x1001f7bc` |
| `1001eeb4` | `59` | `POP ECX` |
| `1001eeb5` | `83 f8 ff` | `CMP EAX,-0x1` |
| `1001eeb8` | `75 04` | `JNZ 0x1001eebe` |
| `1001eeba` | `33 c0` | `XOR EAX,EAX` |
| `1001eebc` | `eb 47` | `JMP 0x1001ef05` |
| `1001eebe` | `3b 45 18` | `CMP EAX,dword ptr [EBP + 0x18]` |
| `1001eec1` | `74 1e` | `JZ 0x1001eee1` |
| `1001eec3` | `53` | `PUSH EBX` |
| `1001eec4` | `53` | `PUSH EBX` |
| `1001eec5` | `8d 4d 10` | `LEA ECX,[EBP + 0x10]` |
| `1001eec8` | `51` | `PUSH ECX` |
| `1001eec9` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001eecc` | `50` | `PUSH EAX` |
| `1001eecd` | `ff 75 18` | `PUSH dword ptr [EBP + 0x18]` |
| `1001eed0` | `e8 30 09 00 00` | `CALL 0x1001f805` |
| `1001eed5` | `8b f0` | `MOV ESI,EAX` |
| `1001eed7` | `83 c4 18` | `ADD ESP,0x18` |
| `1001eeda` | `3b f3` | `CMP ESI,EBX` |
| `1001eedc` | `74 dc` | `JZ 0x1001eeba` |
| `1001eede` | `89 75 0c` | `MOV dword ptr [EBP + 0xc],ESI` |
| `1001eee1` | `ff 75 14` | `PUSH dword ptr [EBP + 0x14]` |
| `1001eee4` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001eee7` | `ff 75 0c` | `PUSH dword ptr [EBP + 0xc]` |
| `1001eeea` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `1001eeed` | `ff 75 1c` | `PUSH dword ptr [EBP + 0x1c]` |
| `1001eef0` | `ff 15 10 e0 02 10` | `CALL dword ptr [0x1002e010]` |
| `1001eef6` | `8b f8` | `MOV EDI,EAX` |
| `1001eef8` | `3b f3` | `CMP ESI,EBX` |
| `1001eefa` | `74 07` | `JZ 0x1001ef03` |
| `1001eefc` | `56` | `PUSH ESI` |
| `1001eefd` | `e8 3f 23 ff ff` | `CALL 0x10011241` |
| `1001ef02` | `59` | `POP ECX` |
| `1001ef03` | `8b c7` | `MOV EAX,EDI` |
| `1001ef05` | `8d 65 ec` | `LEA ESP,[EBP + -0x14]` |
| `1001ef08` | `5f` | `POP EDI` |
| `1001ef09` | `5e` | `POP ESI` |
| `1001ef0a` | `5b` | `POP EBX` |
| `1001ef0b` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001ef0e` | `33 cd` | `XOR ECX,EBP` |
| `1001ef10` | `e8 b6 1d ff ff` | `CALL 0x10010ccb` |
| `1001ef15` | `c9` | `LEAVE` |
| `1001ef16` | `c3` | `RET` |
