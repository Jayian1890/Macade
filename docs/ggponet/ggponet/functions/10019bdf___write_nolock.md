# 10019bdf `__write_nolock`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 10019bdf |
| `name` | __write_nolock |
| `namespace` | Global |
| `signature` | int __cdecl __write_nolock(int _FileHandle, void * _Buf, uint _MaxCharCount) |
| `size_bytes` | 1843 |
| `stack_frame_size` | 6904 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | __write_nolock |

## Decompiled C

```c

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Type propagation algorithm not settling */
/* Library Function - Single Match
    __write_nolock
   
   Library: Visual Studio 2008 Release */

int __cdecl __write_nolock(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  WCHAR WVar1;
  wchar_t wVar2;
  ulong *puVar3;
  int *piVar4;
  int iVar5;
  _ptiddata p_Var6;
  BOOL BVar7;
  DWORD nNumberOfBytesToWrite;
  int iVar8;
  uint uVar9;
  char cVar10;
  WCHAR *pWVar11;
  char *pcVar12;
  int unaff_EDI;
  WCHAR *pWVar13;
  ushort uVar14;
  UINT local_1ae8;
  uint local_1ae4;
  char local_1add;
  int *local_1adc;
  char *local_1ad8;
  int local_1ad4;
  WCHAR *local_1ad0;
  char *local_1acc;
  WCHAR *local_1ac8;
  DWORD local_1ac4;
  WCHAR *local_1ac0;
  WCHAR local_1abc [852];
  CHAR local_1414 [3416];
  WCHAR local_6bc [854];
  undefined2 local_10;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_1ad0 = _Buf;
  local_1acc = (char *)0x0;
  local_1ad4 = 0;
  if (_MaxCharCount == 0) goto LAB_1001a305;
  if (_Buf == (void *)0x0) {
    puVar3 = ___doserrno();
    *puVar3 = 0;
    piVar4 = __errno();
    *piVar4 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    goto LAB_1001a305;
  }
  piVar4 = &DAT_13439540 + (_FileHandle >> 5);
  iVar8 = (_FileHandle & 0x1fU) * 0x40;
  cVar10 = (char)(*(char *)(*piVar4 + iVar8 + 0x24) * '\x02') >> 1;
  local_1add = cVar10;
  local_1adc = piVar4;
  if (((cVar10 == '\x02') || (cVar10 == '\x01')) && ((~_MaxCharCount & 1) == 0)) {
    puVar3 = ___doserrno();
    *puVar3 = 0;
    piVar4 = __errno();
    *piVar4 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    goto LAB_1001a305;
  }
  if ((*(byte *)(*piVar4 + iVar8 + 4) & 0x20) != 0) {
    __lseeki64_nolock(_FileHandle,0x200000000,unaff_EDI);
  }
  iVar5 = __isatty(_FileHandle);
  if ((iVar5 == 0) || ((*(byte *)(iVar8 + 4 + *piVar4) & 0x80) == 0)) {
LAB_10019f76:
    if ((*(byte *)((undefined4 *)(*piVar4 + iVar8) + 1) & 0x80) == 0) {
      BVar7 = WriteFile(*(HANDLE *)(*piVar4 + iVar8),local_1ad0,_MaxCharCount,(LPDWORD)&local_1ad8,
                        (LPOVERLAPPED)0x0);
      if (BVar7 == 0) {
LAB_1001a276:
        local_1ac4 = GetLastError();
      }
      else {
        local_1ac4 = 0;
        local_1acc = local_1ad8;
      }
LAB_1001a282:
      if (local_1acc != (char *)0x0) goto LAB_1001a305;
      goto LAB_1001a28b;
    }
    local_1ac4 = 0;
    if (cVar10 == '\0') {
      local_1ac8 = local_1ad0;
      if (_MaxCharCount == 0) goto LAB_1001a2c7;
      do {
        local_1ac0 = (WCHAR *)0x0;
        uVar9 = (int)local_1ac8 - (int)local_1ad0;
        pWVar11 = local_1abc;
        do {
          if (_MaxCharCount <= uVar9) break;
          pWVar13 = (WCHAR *)((int)local_1ac8 + 1);
          WVar1 = *local_1ac8;
          uVar9 = uVar9 + 1;
          if ((char)WVar1 == '\n') {
            local_1ad4 = local_1ad4 + 1;
            *(char *)pWVar11 = '\r';
            pWVar11 = (WCHAR *)((int)pWVar11 + 1);
            local_1ac0 = (WCHAR *)((int)local_1ac0 + 1);
          }
          *(char *)pWVar11 = (char)WVar1;
          pWVar11 = (WCHAR *)((int)pWVar11 + 1);
          local_1ac0 = (WCHAR *)((int)local_1ac0 + 1);
          local_1ac8 = pWVar13;
        } while (local_1ac0 < (WCHAR *)0x13ff);
        BVar7 = WriteFile(*(HANDLE *)(iVar8 + *piVar4),local_1abc,(int)pWVar11 - (int)local_1abc,
                          (LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
        if (BVar7 == 0) goto LAB_1001a276;
        local_1acc = local_1acc + (int)local_1ad8;
      } while (((int)pWVar11 - (int)local_1abc <= (int)local_1ad8) &&
              (piVar4 = local_1adc, (uint)((int)local_1ac8 - (int)local_1ad0) < _MaxCharCount));
      goto LAB_1001a282;
    }
    local_1ac0 = local_1ad0;
    if (cVar10 == '\x02') {
      if (_MaxCharCount != 0) {
        do {
          local_1ac8 = (WCHAR *)0x0;
          uVar9 = (int)local_1ac0 - (int)local_1ad0;
          pWVar11 = local_1abc;
          do {
            if (_MaxCharCount <= uVar9) break;
            pWVar13 = local_1ac0 + 1;
            WVar1 = *local_1ac0;
            uVar9 = uVar9 + 2;
            if (WVar1 == L'\n') {
              local_1ad4 = local_1ad4 + 2;
              *pWVar11 = L'\r';
              pWVar11 = pWVar11 + 1;
              local_1ac8 = local_1ac8 + 1;
            }
            local_1ac8 = local_1ac8 + 1;
            *pWVar11 = WVar1;
            pWVar11 = pWVar11 + 1;
            local_1ac0 = pWVar13;
          } while (local_1ac8 < (WCHAR *)0x13fe);
          BVar7 = WriteFile(*(HANDLE *)(iVar8 + *piVar4),local_1abc,(int)pWVar11 - (int)local_1abc,
                            (LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
          if (BVar7 == 0) goto LAB_1001a276;
          local_1acc = local_1acc + (int)local_1ad8;
        } while (((int)pWVar11 - (int)local_1abc <= (int)local_1ad8) &&
                (piVar4 = local_1adc, (uint)((int)local_1ac0 - (int)local_1ad0) < _MaxCharCount));
        goto LAB_1001a282;
      }
    }
    else if (_MaxCharCount != 0) {
      do {
        local_1ac8 = (WCHAR *)0x0;
        uVar9 = (int)local_1ac0 - (int)local_1ad0;
        pWVar11 = local_6bc;
        do {
          if (_MaxCharCount <= uVar9) break;
          WVar1 = *local_1ac0;
          local_1ac0 = local_1ac0 + 1;
          uVar9 = uVar9 + 2;
          if (WVar1 == L'\n') {
            *pWVar11 = L'\r';
            pWVar11 = pWVar11 + 1;
            local_1ac8 = local_1ac8 + 1;
          }
          local_1ac8 = local_1ac8 + 1;
          *pWVar11 = WVar1;
          pWVar11 = pWVar11 + 1;
        } while (local_1ac8 < (WCHAR *)0x6a8);
        pcVar12 = (char *)0x0;
        iVar5 = WideCharToMultiByte(0xfde9,0,local_6bc,((int)pWVar11 - (int)local_6bc) / 2,
                                    local_1414,0xd55,(LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar5 == 0) goto LAB_1001a276;
        do {
          BVar7 = WriteFile(*(HANDLE *)(iVar8 + *local_1adc),local_1414 + (int)pcVar12,
                            iVar5 - (int)pcVar12,(LPDWORD)&local_1ad8,(LPOVERLAPPED)0x0);
          if (BVar7 == 0) {
            local_1ac4 = GetLastError();
            break;
          }
          pcVar12 = pcVar12 + (int)local_1ad8;
        } while ((int)pcVar12 < iVar5);
      } while ((iVar5 <= (int)pcVar12) &&
              (local_1acc = (char *)((int)local_1ac0 - (int)local_1ad0), local_1acc < _MaxCharCount)
              );
      goto LAB_1001a282;
    }
  }
  else {
    p_Var6 = __getptd();
    local_1ae4 = (uint)(p_Var6->ptlocinfo->lc_category[0].wlocale == (wchar_t *)0x0);
    BVar7 = GetConsoleMode(*(HANDLE *)(iVar8 + *piVar4),&local_1ae8);
    if ((BVar7 == 0) || ((local_1ae4 != 0 && (cVar10 == '\0')))) goto LAB_10019f76;
    local_1ae8 = GetConsoleCP();
    local_1ac8 = (WCHAR *)0x0;
    if (_MaxCharCount != 0) {
      local_1ac0 = (WCHAR *)0x0;
      pWVar11 = local_1ad0;
      do {
        piVar4 = local_1adc;
        if (local_1add == '\0') {
          cVar10 = (char)*pWVar11;
          local_1ae4 = (uint)(cVar10 == '\n');
          iVar5 = *local_1adc + iVar8;
          if (*(int *)(iVar5 + 0x38) == 0) {
            iVar5 = _isleadbyte(CONCAT22(cVar10 >> 7,(short)cVar10));
            if (iVar5 == 0) {
              uVar14 = 1;
              pWVar13 = pWVar11;
              goto LAB_10019ddd;
            }
            if ((char *)((int)local_1ad0 + (_MaxCharCount - (int)pWVar11)) < (char *)0x2) {
              local_1acc = local_1acc + 1;
              *(char *)(iVar8 + 0x34 + *piVar4) = (char)*pWVar11;
              *(undefined4 *)(iVar8 + 0x38 + *piVar4) = 1;
              break;
            }
            iVar5 = _mbtowc((wchar_t *)&local_1ac4,(char *)pWVar11,2);
            if (iVar5 == -1) break;
            pWVar11 = (WCHAR *)((int)pWVar11 + 1);
            local_1ac0 = (WCHAR *)((int)local_1ac0 + 1);
          }
          else {
            local_10._0_1_ = *(CHAR *)(iVar5 + 0x34);
            *(undefined4 *)(iVar5 + 0x38) = 0;
            uVar14 = 2;
            pWVar13 = &local_10;
            local_10._1_1_ = cVar10;
LAB_10019ddd:
            iVar5 = _mbtowc((wchar_t *)&local_1ac4,(char *)pWVar13,(uint)uVar14);
            if (iVar5 == -1) break;
          }
          pWVar11 = (WCHAR *)((int)pWVar11 + 1);
          local_1ac0 = (WCHAR *)((int)local_1ac0 + 1);
          nNumberOfBytesToWrite =
               WideCharToMultiByte(local_1ae8,0,(LPCWSTR)&local_1ac4,1,(LPSTR)&local_10,5,
                                   (LPCSTR)0x0,(LPBOOL)0x0);
          if (nNumberOfBytesToWrite == 0) break;
          BVar7 = WriteFile(*(HANDLE *)(iVar8 + *local_1adc),&local_10,nNumberOfBytesToWrite,
                            (LPDWORD)&local_1ac8,(LPOVERLAPPED)0x0);
          if (BVar7 == 0) goto LAB_1001a276;
          local_1acc = (char *)((int)local_1ac0 + local_1ad4);
          if ((int)local_1ac8 < (int)nNumberOfBytesToWrite) break;
          if (local_1ae4 != 0) {
            local_10._0_1_ = '\r';
            BVar7 = WriteFile(*(HANDLE *)(iVar8 + *local_1adc),&local_10,1,(LPDWORD)&local_1ac8,
                              (LPOVERLAPPED)0x0);
            if (BVar7 == 0) goto LAB_1001a276;
            if ((int)local_1ac8 < 1) break;
            local_1ad4 = local_1ad4 + 1;
            local_1acc = local_1acc + 1;
          }
        }
        else {
          if ((local_1add == '\x01') || (local_1add == '\x02')) {
            local_1ac4 = (DWORD)(ushort)*pWVar11;
            local_1ae4 = (uint)(*pWVar11 == L'\n');
            pWVar11 = pWVar11 + 1;
            local_1ac0 = local_1ac0 + 1;
          }
          if ((local_1add == '\x01') || (local_1add == '\x02')) {
            wVar2 = __putwch_nolock((wchar_t)local_1ac4);
            if (wVar2 != (wchar_t)local_1ac4) goto LAB_1001a276;
            local_1acc = local_1acc + 2;
            if (local_1ae4 != 0) {
              local_1ac4 = 0xd;
              wVar2 = __putwch_nolock(L'\r');
              if (wVar2 != (wchar_t)local_1ac4) goto LAB_1001a276;
              local_1acc = local_1acc + 1;
              local_1ad4 = local_1ad4 + 1;
            }
          }
        }
      } while (local_1ac0 < _MaxCharCount);
      goto LAB_1001a282;
    }
LAB_1001a28b:
    piVar4 = local_1adc;
    if (local_1ac4 != 0) {
      if (local_1ac4 == 5) {
        piVar4 = __errno();
        *piVar4 = 9;
        puVar3 = ___doserrno();
        *puVar3 = 5;
      }
      else {
        __dosmaperr(local_1ac4);
      }
      goto LAB_1001a305;
    }
  }
LAB_1001a2c7:
  if (((*(byte *)(iVar8 + 4 + *piVar4) & 0x40) == 0) || ((char)*local_1ad0 != '\x1a')) {
    piVar4 = __errno();
    *piVar4 = 0x1c;
    puVar3 = ___doserrno();
    *puVar3 = 0;
  }
LAB_1001a305:
  iVar8 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar8;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `10019be9` | `1001e850` | `UNCONDITIONAL_CALL` | __alloca_probe | `1001e850` |
| `10019c20` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `10019c27` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10019c37` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019c89` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `10019c92` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `10019ca2` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `10019cbe` | `1001b92c` | `UNCONDITIONAL_CALL` | __lseeki64_nolock | `1001b92c` |
| `10019cc9` | `1001bb13` | `UNCONDITIONAL_CALL` | __isatty | `1001bb13` |
| `10019ce4` | `100173d6` | `UNCONDITIONAL_CALL` | __getptd | `100173d6` |
| `10019d06` | `EXTERNAL:00000056` | `COMPUTED_CALL` | KERNEL32.DLL::GetConsoleMode | `` |
| `10019d26` | `EXTERNAL:00000055` | `COMPUTED_CALL` | KERNEL32.DLL::GetConsoleCP | `` |
| `10019d96` | `1001c740` | `UNCONDITIONAL_CALL` | _isleadbyte | `1001c740` |
| `10019dc0` | `1001e834` | `UNCONDITIONAL_CALL` | _mbtowc | `1001e834` |
| `10019de4` | `1001e834` | `UNCONDITIONAL_CALL` | _mbtowc | `1001e834` |
| `10019e16` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `10019e3f` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `10019e98` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `10019efb` | `1001e658` | `UNCONDITIONAL_CALL` | __putwch_nolock | `1001e658` |
| `10019f28` | `1001e658` | `UNCONDITIONAL_CALL` | __putwch_nolock | `1001e658` |
| `1001a026` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `1001a106` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `1001a1cf` | `EXTERNAL:00000029` | `COMPUTED_CALL` | KERNEL32.DLL::WideCharToMultiByte | `` |
| `1001a200` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `1001a216` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001a257` | `EXTERNAL:00000012` | `COMPUTED_CALL` | KERNEL32.DLL::WriteFile | `` |
| `1001a276` | `EXTERNAL:00000026` | `COMPUTED_CALL` | KERNEL32.DLL::GetLastError | `` |
| `1001a29f` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001a2aa` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001a2b9` | `1001512f` | `UNCONDITIONAL_CALL` | __dosmaperr | `1001512f` |
| `1001a2df` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1001a2ea` | `1001511c` | `UNCONDITIONAL_CALL` | ___doserrno | `1001511c` |
| `1001a30b` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1001a3ac` | __write |
| `1001f409` | __chsize_nolock |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `10019bee` | `10037490` | `READ` | DAT_10037490 |
| `10019c51` | `13439540` | `DATA` | DAT_13439540 |
| `10019c58` | `13439540` | `DATA` | DAT_13439540 |
| `10019cd7` | `13439540` | `DATA` | DAT_13439540 |
| `10019cfb` | `13439540` | `DATA` | DAT_13439540 |
| `10019d06` | `1002e110` | `READ` | PTR_GetConsoleMode_1002e110 |
| `10019d26` | `1002e10c` | `READ` | PTR_GetConsoleCP_1002e10c |
| `10019d73` | `13439540` | `DATA` | DAT_13439540 |
| `10019e16` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `10019e3a` | `13439540` | `DATA` | DAT_13439540 |
| `10019e3f` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `10019e8f` | `13439540` | `DATA` | DAT_13439540 |
| `10019e98` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `10019f5b` | `13439540` | `DATA` | DAT_13439540 |
| `10019f69` | `13439540` | `DATA` | DAT_13439540 |
| `10019f76` | `13439540` | `DATA` | DAT_13439540 |
| `1001a021` | `13439540` | `DATA` | DAT_13439540 |
| `1001a026` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `1001a101` | `13439540` | `DATA` | DAT_13439540 |
| `1001a106` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `1001a1cf` | `1002e05c` | `READ` | PTR_WideCharToMultiByte_1002e05c |
| `1001a1fb` | `13439540` | `DATA` | DAT_13439540 |
| `1001a200` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `1001a216` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001a257` | `1002e000` | `READ` | PTR_WriteFile_1002e000 |
| `1001a276` | `1002e050` | `READ` | PTR_GetLastError_1002e050 |
| `1001a2c7` | `13439540` | `DATA` | DAT_13439540 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `10019bdf` | `8b ff` | `MOV EDI,EDI` |
| `10019be1` | `55` | `PUSH EBP` |
| `10019be2` | `8b ec` | `MOV EBP,ESP` |
| `10019be4` | `b8 e4 1a 00 00` | `MOV EAX,0x1ae4` |
| `10019be9` | `e8 62 4c 00 00` | `CALL 0x1001e850` |
| `10019bee` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `10019bf3` | `33 c5` | `XOR EAX,EBP` |
| `10019bf5` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `10019bf8` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `10019bfb` | `56` | `PUSH ESI` |
| `10019bfc` | `33 f6` | `XOR ESI,ESI` |
| `10019bfe` | `89 85 34 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe534],EAX` |
| `10019c04` | `89 b5 38 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe538],ESI` |
| `10019c0a` | `89 b5 30 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe530],ESI` |
| `10019c10` | `39 75 10` | `CMP dword ptr [EBP + 0x10],ESI` |
| `10019c13` | `75 07` | `JNZ 0x10019c1c` |
| `10019c15` | `33 c0` | `XOR EAX,EAX` |
| `10019c17` | `e9 e9 06 00 00` | `JMP 0x1001a305` |
| `10019c1c` | `3b c6` | `CMP EAX,ESI` |
| `10019c1e` | `75 27` | `JNZ 0x10019c47` |
| `10019c20` | `e8 f7 b4 ff ff` | `CALL 0x1001511c` |
| `10019c25` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10019c27` | `e8 dd b4 ff ff` | `CALL 0x10015109` |
| `10019c2c` | `56` | `PUSH ESI` |
| `10019c2d` | `56` | `PUSH ESI` |
| `10019c2e` | `56` | `PUSH ESI` |
| `10019c2f` | `56` | `PUSH ESI` |
| `10019c30` | `56` | `PUSH ESI` |
| `10019c31` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10019c37` | `e8 73 7a ff ff` | `CALL 0x100116af` |
| `10019c3c` | `83 c4 14` | `ADD ESP,0x14` |
| `10019c3f` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `10019c42` | `e9 be 06 00 00` | `JMP 0x1001a305` |
| `10019c47` | `53` | `PUSH EBX` |
| `10019c48` | `57` | `PUSH EDI` |
| `10019c49` | `8b 7d 08` | `MOV EDI,dword ptr [EBP + 0x8]` |
| `10019c4c` | `8b c7` | `MOV EAX,EDI` |
| `10019c4e` | `c1 f8 05` | `SAR EAX,0x5` |
| `10019c51` | `8d 34 85 40 95 43 13` | `LEA ESI,[EAX*0x4 + 0x13439540]` |
| `10019c58` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019c5a` | `83 e7 1f` | `AND EDI,0x1f` |
| `10019c5d` | `c1 e7 06` | `SHL EDI,0x6` |
| `10019c60` | `03 c7` | `ADD EAX,EDI` |
| `10019c62` | `8a 58 24` | `MOV BL,byte ptr [EAX + 0x24]` |
| `10019c65` | `02 db` | `ADD BL,BL` |
| `10019c67` | `d0 fb` | `SAR BL,0x1` |
| `10019c69` | `89 b5 28 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe528],ESI` |
| `10019c6f` | `88 9d 27 e5 ff ff` | `MOV byte ptr [EBP + 0xffffe527],BL` |
| `10019c75` | `80 fb 02` | `CMP BL,0x2` |
| `10019c78` | `74 05` | `JZ 0x10019c7f` |
| `10019c7a` | `80 fb 01` | `CMP BL,0x1` |
| `10019c7d` | `75 30` | `JNZ 0x10019caf` |
| `10019c7f` | `8b 4d 10` | `MOV ECX,dword ptr [EBP + 0x10]` |
| `10019c82` | `f7 d1` | `NOT ECX` |
| `10019c84` | `f6 c1 01` | `TEST CL,0x1` |
| `10019c87` | `75 26` | `JNZ 0x10019caf` |
| `10019c89` | `e8 8e b4 ff ff` | `CALL 0x1001511c` |
| `10019c8e` | `33 f6` | `XOR ESI,ESI` |
| `10019c90` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `10019c92` | `e8 72 b4 ff ff` | `CALL 0x10015109` |
| `10019c97` | `56` | `PUSH ESI` |
| `10019c98` | `56` | `PUSH ESI` |
| `10019c99` | `56` | `PUSH ESI` |
| `10019c9a` | `56` | `PUSH ESI` |
| `10019c9b` | `56` | `PUSH ESI` |
| `10019c9c` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `10019ca2` | `e8 08 7a ff ff` | `CALL 0x100116af` |
| `10019ca7` | `83 c4 14` | `ADD ESP,0x14` |
| `10019caa` | `e9 43 06 00 00` | `JMP 0x1001a2f2` |
| `10019caf` | `f6 40 04 20` | `TEST byte ptr [EAX + 0x4],0x20` |
| `10019cb3` | `74 11` | `JZ 0x10019cc6` |
| `10019cb5` | `6a 02` | `PUSH 0x2` |
| `10019cb7` | `6a 00` | `PUSH 0x0` |
| `10019cb9` | `6a 00` | `PUSH 0x0` |
| `10019cbb` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019cbe` | `e8 69 1c 00 00` | `CALL 0x1001b92c` |
| `10019cc3` | `83 c4 10` | `ADD ESP,0x10` |
| `10019cc6` | `ff 75 08` | `PUSH dword ptr [EBP + 0x8]` |
| `10019cc9` | `e8 45 1e 00 00` | `CALL 0x1001bb13` |
| `10019cce` | `59` | `POP ECX` |
| `10019ccf` | `85 c0` | `TEST EAX,EAX` |
| `10019cd1` | `0f 84 9d 02 00 00` | `JZ 0x10019f74` |
| `10019cd7` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019cd9` | `f6 44 07 04 80` | `TEST byte ptr [EDI + EAX*0x1 + 0x4],0x80` |
| `10019cde` | `0f 84 90 02 00 00` | `JZ 0x10019f74` |
| `10019ce4` | `e8 ed d6 ff ff` | `CALL 0x100173d6` |
| `10019ce9` | `8b 40 6c` | `MOV EAX,dword ptr [EAX + 0x6c]` |
| `10019cec` | `33 c9` | `XOR ECX,ECX` |
| `10019cee` | `39 48 14` | `CMP dword ptr [EAX + 0x14],ECX` |
| `10019cf1` | `8d 85 1c e5 ff ff` | `LEA EAX,[EBP + 0xffffe51c]` |
| `10019cf7` | `0f 94 c1` | `SETZ CL` |
| `10019cfa` | `50` | `PUSH EAX` |
| `10019cfb` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019cfd` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `10019d00` | `89 8d 20 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe520],ECX` |
| `10019d06` | `ff 15 10 e1 02 10` | `CALL dword ptr [0x1002e110]` |
| `10019d0c` | `85 c0` | `TEST EAX,EAX` |
| `10019d0e` | `0f 84 60 02 00 00` | `JZ 0x10019f74` |
| `10019d14` | `33 c9` | `XOR ECX,ECX` |
| `10019d16` | `39 8d 20 e5 ff ff` | `CMP dword ptr [EBP + 0xffffe520],ECX` |
| `10019d1c` | `74 08` | `JZ 0x10019d26` |
| `10019d1e` | `84 db` | `TEST BL,BL` |
| `10019d20` | `0f 84 50 02 00 00` | `JZ 0x10019f76` |
| `10019d26` | `ff 15 0c e1 02 10` | `CALL dword ptr [0x1002e10c]` |
| `10019d2c` | `8b 9d 34 e5 ff ff` | `MOV EBX,dword ptr [EBP + 0xffffe534]` |
| `10019d32` | `89 85 1c e5 ff ff` | `MOV dword ptr [EBP + 0xffffe51c],EAX` |
| `10019d38` | `33 c0` | `XOR EAX,EAX` |
| `10019d3a` | `89 85 3c e5 ff ff` | `MOV dword ptr [EBP + 0xffffe53c],EAX` |
| `10019d40` | `39 45 10` | `CMP dword ptr [EBP + 0x10],EAX` |
| `10019d43` | `0f 86 42 05 00 00` | `JBE 0x1001a28b` |
| `10019d49` | `89 85 44 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe544],EAX` |
| `10019d4f` | `8a 85 27 e5 ff ff` | `MOV AL,byte ptr [EBP + 0xffffe527]` |
| `10019d55` | `84 c0` | `TEST AL,AL` |
| `10019d57` | `0f 85 67 01 00 00` | `JNZ 0x10019ec4` |
| `10019d5d` | `8a 0b` | `MOV CL,byte ptr [EBX]` |
| `10019d5f` | `8b b5 28 e5 ff ff` | `MOV ESI,dword ptr [EBP + 0xffffe528]` |
| `10019d65` | `33 c0` | `XOR EAX,EAX` |
| `10019d67` | `80 f9 0a` | `CMP CL,0xa` |
| `10019d6a` | `0f 94 c0` | `SETZ AL` |
| `10019d6d` | `89 85 20 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe520],EAX` |
| `10019d73` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019d75` | `03 c7` | `ADD EAX,EDI` |
| `10019d77` | `83 78 38 00` | `CMP dword ptr [EAX + 0x38],0x0` |
| `10019d7b` | `74 15` | `JZ 0x10019d92` |
| `10019d7d` | `8a 50 34` | `MOV DL,byte ptr [EAX + 0x34]` |
| `10019d80` | `88 55 f4` | `MOV byte ptr [EBP + -0xc],DL` |
| `10019d83` | `88 4d f5` | `MOV byte ptr [EBP + -0xb],CL` |
| `10019d86` | `83 60 38 00` | `AND dword ptr [EAX + 0x38],0x0` |
| `10019d8a` | `6a 02` | `PUSH 0x2` |
| `10019d8c` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10019d8f` | `50` | `PUSH EAX` |
| `10019d90` | `eb 4b` | `JMP 0x10019ddd` |
| `10019d92` | `0f be c1` | `MOVSX EAX,CL` |
| `10019d95` | `50` | `PUSH EAX` |
| `10019d96` | `e8 a5 29 00 00` | `CALL 0x1001c740` |
| `10019d9b` | `59` | `POP ECX` |
| `10019d9c` | `85 c0` | `TEST EAX,EAX` |
| `10019d9e` | `74 3a` | `JZ 0x10019dda` |
| `10019da0` | `8b 8d 34 e5 ff ff` | `MOV ECX,dword ptr [EBP + 0xffffe534]` |
| `10019da6` | `2b cb` | `SUB ECX,EBX` |
| `10019da8` | `03 4d 10` | `ADD ECX,dword ptr [EBP + 0x10]` |
| `10019dab` | `33 c0` | `XOR EAX,EAX` |
| `10019dad` | `40` | `INC EAX` |
| `10019dae` | `3b c8` | `CMP ECX,EAX` |
| `10019db0` | `0f 86 a5 01 00 00` | `JBE 0x10019f5b` |
| `10019db6` | `6a 02` | `PUSH 0x2` |
| `10019db8` | `8d 85 40 e5 ff ff` | `LEA EAX,[EBP + 0xffffe540]` |
| `10019dbe` | `53` | `PUSH EBX` |
| `10019dbf` | `50` | `PUSH EAX` |
| `10019dc0` | `e8 6f 4a 00 00` | `CALL 0x1001e834` |
| `10019dc5` | `83 c4 0c` | `ADD ESP,0xc` |
| `10019dc8` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10019dcb` | `0f 84 b1 04 00 00` | `JZ 0x1001a282` |
| `10019dd1` | `43` | `INC EBX` |
| `10019dd2` | `ff 85 44 e5 ff ff` | `INC dword ptr [EBP + 0xffffe544]` |
| `10019dd8` | `eb 1b` | `JMP 0x10019df5` |
| `10019dda` | `6a 01` | `PUSH 0x1` |
| `10019ddc` | `53` | `PUSH EBX` |
| `10019ddd` | `8d 85 40 e5 ff ff` | `LEA EAX,[EBP + 0xffffe540]` |
| `10019de3` | `50` | `PUSH EAX` |
| `10019de4` | `e8 4b 4a 00 00` | `CALL 0x1001e834` |
| `10019de9` | `83 c4 0c` | `ADD ESP,0xc` |
| `10019dec` | `83 f8 ff` | `CMP EAX,-0x1` |
| `10019def` | `0f 84 8d 04 00 00` | `JZ 0x1001a282` |
| `10019df5` | `33 c0` | `XOR EAX,EAX` |
| `10019df7` | `50` | `PUSH EAX` |
| `10019df8` | `50` | `PUSH EAX` |
| `10019df9` | `6a 05` | `PUSH 0x5` |
| `10019dfb` | `8d 4d f4` | `LEA ECX,[EBP + -0xc]` |
| `10019dfe` | `51` | `PUSH ECX` |
| `10019dff` | `6a 01` | `PUSH 0x1` |
| `10019e01` | `8d 8d 40 e5 ff ff` | `LEA ECX,[EBP + 0xffffe540]` |
| `10019e07` | `51` | `PUSH ECX` |
| `10019e08` | `50` | `PUSH EAX` |
| `10019e09` | `ff b5 1c e5 ff ff` | `PUSH dword ptr [EBP + 0xffffe51c]` |
| `10019e0f` | `43` | `INC EBX` |
| `10019e10` | `ff 85 44 e5 ff ff` | `INC dword ptr [EBP + 0xffffe544]` |
| `10019e16` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `10019e1c` | `8b f0` | `MOV ESI,EAX` |
| `10019e1e` | `85 f6` | `TEST ESI,ESI` |
| `10019e20` | `0f 84 5c 04 00 00` | `JZ 0x1001a282` |
| `10019e26` | `6a 00` | `PUSH 0x0` |
| `10019e28` | `8d 85 3c e5 ff ff` | `LEA EAX,[EBP + 0xffffe53c]` |
| `10019e2e` | `50` | `PUSH EAX` |
| `10019e2f` | `56` | `PUSH ESI` |
| `10019e30` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10019e33` | `50` | `PUSH EAX` |
| `10019e34` | `8b 85 28 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe528]` |
| `10019e3a` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `10019e3c` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `10019e3f` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `10019e45` | `85 c0` | `TEST EAX,EAX` |
| `10019e47` | `0f 84 29 04 00 00` | `JZ 0x1001a276` |
| `10019e4d` | `8b 85 44 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe544]` |
| `10019e53` | `8b 8d 30 e5 ff ff` | `MOV ECX,dword ptr [EBP + 0xffffe530]` |
| `10019e59` | `03 c1` | `ADD EAX,ECX` |
| `10019e5b` | `39 b5 3c e5 ff ff` | `CMP dword ptr [EBP + 0xffffe53c],ESI` |
| `10019e61` | `89 85 38 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe538],EAX` |
| `10019e67` | `0f 8c 15 04 00 00` | `JL 0x1001a282` |
| `10019e6d` | `83 bd 20 e5 ff ff 00` | `CMP dword ptr [EBP + 0xffffe520],0x0` |
| `10019e74` | `0f 84 cd 00 00 00` | `JZ 0x10019f47` |
| `10019e7a` | `6a 00` | `PUSH 0x0` |
| `10019e7c` | `8d 85 3c e5 ff ff` | `LEA EAX,[EBP + 0xffffe53c]` |
| `10019e82` | `50` | `PUSH EAX` |
| `10019e83` | `6a 01` | `PUSH 0x1` |
| `10019e85` | `8d 45 f4` | `LEA EAX,[EBP + -0xc]` |
| `10019e88` | `50` | `PUSH EAX` |
| `10019e89` | `8b 85 28 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe528]` |
| `10019e8f` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `10019e91` | `c6 45 f4 0d` | `MOV byte ptr [EBP + -0xc],0xd` |
| `10019e95` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `10019e98` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `10019e9e` | `85 c0` | `TEST EAX,EAX` |
| `10019ea0` | `0f 84 d0 03 00 00` | `JZ 0x1001a276` |
| `10019ea6` | `83 bd 3c e5 ff ff 01` | `CMP dword ptr [EBP + 0xffffe53c],0x1` |
| `10019ead` | `0f 8c cf 03 00 00` | `JL 0x1001a282` |
| `10019eb3` | `ff 85 30 e5 ff ff` | `INC dword ptr [EBP + 0xffffe530]` |
| `10019eb9` | `ff 85 38 e5 ff ff` | `INC dword ptr [EBP + 0xffffe538]` |
| `10019ebf` | `e9 83 00 00 00` | `JMP 0x10019f47` |
| `10019ec4` | `3c 01` | `CMP AL,0x1` |
| `10019ec6` | `74 04` | `JZ 0x10019ecc` |
| `10019ec8` | `3c 02` | `CMP AL,0x2` |
| `10019eca` | `75 21` | `JNZ 0x10019eed` |
| `10019ecc` | `0f b7 33` | `MOVZX ESI,word ptr [EBX]` |
| `10019ecf` | `33 c9` | `XOR ECX,ECX` |
| `10019ed1` | `66 83 fe 0a` | `CMP SI,0xa` |
| `10019ed5` | `0f 94 c1` | `SETZ CL` |
| `10019ed8` | `43` | `INC EBX` |
| `10019ed9` | `43` | `INC EBX` |
| `10019eda` | `83 85 44 e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe544],0x2` |
| `10019ee1` | `89 b5 40 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe540],ESI` |
| `10019ee7` | `89 8d 20 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe520],ECX` |
| `10019eed` | `3c 01` | `CMP AL,0x1` |
| `10019eef` | `74 04` | `JZ 0x10019ef5` |
| `10019ef1` | `3c 02` | `CMP AL,0x2` |
| `10019ef3` | `75 52` | `JNZ 0x10019f47` |
| `10019ef5` | `ff b5 40 e5 ff ff` | `PUSH dword ptr [EBP + 0xffffe540]` |
| `10019efb` | `e8 58 47 00 00` | `CALL 0x1001e658` |
| `10019f00` | `59` | `POP ECX` |
| `10019f01` | `66 3b 85 40 e5 ff ff` | `CMP AX,word ptr [EBP + 0xffffe540]` |
| `10019f08` | `0f 85 68 03 00 00` | `JNZ 0x1001a276` |
| `10019f0e` | `83 85 38 e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe538],0x2` |
| `10019f15` | `83 bd 20 e5 ff ff 00` | `CMP dword ptr [EBP + 0xffffe520],0x0` |
| `10019f1c` | `74 29` | `JZ 0x10019f47` |
| `10019f1e` | `6a 0d` | `PUSH 0xd` |
| `10019f20` | `58` | `POP EAX` |
| `10019f21` | `50` | `PUSH EAX` |
| `10019f22` | `89 85 40 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe540],EAX` |
| `10019f28` | `e8 2b 47 00 00` | `CALL 0x1001e658` |
| `10019f2d` | `59` | `POP ECX` |
| `10019f2e` | `66 3b 85 40 e5 ff ff` | `CMP AX,word ptr [EBP + 0xffffe540]` |
| `10019f35` | `0f 85 3b 03 00 00` | `JNZ 0x1001a276` |
| `10019f3b` | `ff 85 38 e5 ff ff` | `INC dword ptr [EBP + 0xffffe538]` |
| `10019f41` | `ff 85 30 e5 ff ff` | `INC dword ptr [EBP + 0xffffe530]` |
| `10019f47` | `8b 45 10` | `MOV EAX,dword ptr [EBP + 0x10]` |
| `10019f4a` | `39 85 44 e5 ff ff` | `CMP dword ptr [EBP + 0xffffe544],EAX` |
| `10019f50` | `0f 82 f9 fd ff ff` | `JC 0x10019d4f` |
| `10019f56` | `e9 27 03 00 00` | `JMP 0x1001a282` |
| `10019f5b` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `10019f5d` | `8a 13` | `MOV DL,byte ptr [EBX]` |
| `10019f5f` | `ff 85 38 e5 ff ff` | `INC dword ptr [EBP + 0xffffe538]` |
| `10019f65` | `88 54 0f 34` | `MOV byte ptr [EDI + ECX*0x1 + 0x34],DL` |
| `10019f69` | `8b 0e` | `MOV ECX,dword ptr [ESI]` |
| `10019f6b` | `89 44 0f 38` | `MOV dword ptr [EDI + ECX*0x1 + 0x38],EAX` |
| `10019f6f` | `e9 0e 03 00 00` | `JMP 0x1001a282` |
| `10019f74` | `33 c9` | `XOR ECX,ECX` |
| `10019f76` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `10019f78` | `03 c7` | `ADD EAX,EDI` |
| `10019f7a` | `f6 40 04 80` | `TEST byte ptr [EAX + 0x4],0x80` |
| `10019f7e` | `0f 84 bf 02 00 00` | `JZ 0x1001a243` |
| `10019f84` | `8b 85 34 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe534]` |
| `10019f8a` | `89 8d 40 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe540],ECX` |
| `10019f90` | `84 db` | `TEST BL,BL` |
| `10019f92` | `0f 85 ca 00 00 00` | `JNZ 0x1001a062` |
| `10019f98` | `89 85 3c e5 ff ff` | `MOV dword ptr [EBP + 0xffffe53c],EAX` |
| `10019f9e` | `39 4d 10` | `CMP dword ptr [EBP + 0x10],ECX` |
| `10019fa1` | `0f 86 20 03 00 00` | `JBE 0x1001a2c7` |
| `10019fa7` | `eb 06` | `JMP 0x10019faf` |
| `10019fa9` | `8b b5 28 e5 ff ff` | `MOV ESI,dword ptr [EBP + 0xffffe528]` |
| `10019faf` | `8b 8d 3c e5 ff ff` | `MOV ECX,dword ptr [EBP + 0xffffe53c]` |
| `10019fb5` | `83 a5 44 e5 ff ff 00` | `AND dword ptr [EBP + 0xffffe544],0x0` |
| `10019fbc` | `2b 8d 34 e5 ff ff` | `SUB ECX,dword ptr [EBP + 0xffffe534]` |
| `10019fc2` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `10019fc8` | `3b 4d 10` | `CMP ECX,dword ptr [EBP + 0x10]` |
| `10019fcb` | `73 39` | `JNC 0x1001a006` |
| `10019fcd` | `8b 95 3c e5 ff ff` | `MOV EDX,dword ptr [EBP + 0xffffe53c]` |
| `10019fd3` | `ff 85 3c e5 ff ff` | `INC dword ptr [EBP + 0xffffe53c]` |
| `10019fd9` | `8a 12` | `MOV DL,byte ptr [EDX]` |
| `10019fdb` | `41` | `INC ECX` |
| `10019fdc` | `80 fa 0a` | `CMP DL,0xa` |
| `10019fdf` | `75 10` | `JNZ 0x10019ff1` |
| `10019fe1` | `ff 85 30 e5 ff ff` | `INC dword ptr [EBP + 0xffffe530]` |
| `10019fe7` | `c6 00 0d` | `MOV byte ptr [EAX],0xd` |
| `10019fea` | `40` | `INC EAX` |
| `10019feb` | `ff 85 44 e5 ff ff` | `INC dword ptr [EBP + 0xffffe544]` |
| `10019ff1` | `88 10` | `MOV byte ptr [EAX],DL` |
| `10019ff3` | `40` | `INC EAX` |
| `10019ff4` | `ff 85 44 e5 ff ff` | `INC dword ptr [EBP + 0xffffe544]` |
| `10019ffa` | `81 bd 44 e5 ff ff ff 13 00 00` | `CMP dword ptr [EBP + 0xffffe544],0x13ff` |
| `1001a004` | `72 c2` | `JC 0x10019fc8` |
| `1001a006` | `8b d8` | `MOV EBX,EAX` |
| `1001a008` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `1001a00e` | `2b d8` | `SUB EBX,EAX` |
| `1001a010` | `6a 00` | `PUSH 0x0` |
| `1001a012` | `8d 85 2c e5 ff ff` | `LEA EAX,[EBP + 0xffffe52c]` |
| `1001a018` | `50` | `PUSH EAX` |
| `1001a019` | `53` | `PUSH EBX` |
| `1001a01a` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `1001a020` | `50` | `PUSH EAX` |
| `1001a021` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001a023` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `1001a026` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `1001a02c` | `85 c0` | `TEST EAX,EAX` |
| `1001a02e` | `0f 84 42 02 00 00` | `JZ 0x1001a276` |
| `1001a034` | `8b 85 2c e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe52c]` |
| `1001a03a` | `01 85 38 e5 ff ff` | `ADD dword ptr [EBP + 0xffffe538],EAX` |
| `1001a040` | `3b c3` | `CMP EAX,EBX` |
| `1001a042` | `0f 8c 3a 02 00 00` | `JL 0x1001a282` |
| `1001a048` | `8b 85 3c e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe53c]` |
| `1001a04e` | `2b 85 34 e5 ff ff` | `SUB EAX,dword ptr [EBP + 0xffffe534]` |
| `1001a054` | `3b 45 10` | `CMP EAX,dword ptr [EBP + 0x10]` |
| `1001a057` | `0f 82 4c ff ff ff` | `JC 0x10019fa9` |
| `1001a05d` | `e9 20 02 00 00` | `JMP 0x1001a282` |
| `1001a062` | `89 85 44 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe544],EAX` |
| `1001a068` | `80 fb 02` | `CMP BL,0x2` |
| `1001a06b` | `0f 85 d1 00 00 00` | `JNZ 0x1001a142` |
| `1001a071` | `39 4d 10` | `CMP dword ptr [EBP + 0x10],ECX` |
| `1001a074` | `0f 86 4d 02 00 00` | `JBE 0x1001a2c7` |
| `1001a07a` | `eb 06` | `JMP 0x1001a082` |
| `1001a07c` | `8b b5 28 e5 ff ff` | `MOV ESI,dword ptr [EBP + 0xffffe528]` |
| `1001a082` | `8b 8d 44 e5 ff ff` | `MOV ECX,dword ptr [EBP + 0xffffe544]` |
| `1001a088` | `83 a5 3c e5 ff ff 00` | `AND dword ptr [EBP + 0xffffe53c],0x0` |
| `1001a08f` | `2b 8d 34 e5 ff ff` | `SUB ECX,dword ptr [EBP + 0xffffe534]` |
| `1001a095` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `1001a09b` | `3b 4d 10` | `CMP ECX,dword ptr [EBP + 0x10]` |
| `1001a09e` | `73 46` | `JNC 0x1001a0e6` |
| `1001a0a0` | `8b 95 44 e5 ff ff` | `MOV EDX,dword ptr [EBP + 0xffffe544]` |
| `1001a0a6` | `83 85 44 e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe544],0x2` |
| `1001a0ad` | `0f b7 12` | `MOVZX EDX,word ptr [EDX]` |
| `1001a0b0` | `41` | `INC ECX` |
| `1001a0b1` | `41` | `INC ECX` |
| `1001a0b2` | `66 83 fa 0a` | `CMP DX,0xa` |
| `1001a0b6` | `75 16` | `JNZ 0x1001a0ce` |
| `1001a0b8` | `83 85 30 e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe530],0x2` |
| `1001a0bf` | `6a 0d` | `PUSH 0xd` |
| `1001a0c1` | `5b` | `POP EBX` |
| `1001a0c2` | `66 89 18` | `MOV word ptr [EAX],BX` |
| `1001a0c5` | `40` | `INC EAX` |
| `1001a0c6` | `40` | `INC EAX` |
| `1001a0c7` | `83 85 3c e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe53c],0x2` |
| `1001a0ce` | `83 85 3c e5 ff ff 02` | `ADD dword ptr [EBP + 0xffffe53c],0x2` |
| `1001a0d5` | `66 89 10` | `MOV word ptr [EAX],DX` |
| `1001a0d8` | `40` | `INC EAX` |
| `1001a0d9` | `40` | `INC EAX` |
| `1001a0da` | `81 bd 3c e5 ff ff fe 13 00 00` | `CMP dword ptr [EBP + 0xffffe53c],0x13fe` |
| `1001a0e4` | `72 b5` | `JC 0x1001a09b` |
| `1001a0e6` | `8b d8` | `MOV EBX,EAX` |
| `1001a0e8` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `1001a0ee` | `2b d8` | `SUB EBX,EAX` |
| `1001a0f0` | `6a 00` | `PUSH 0x0` |
| `1001a0f2` | `8d 85 2c e5 ff ff` | `LEA EAX,[EBP + 0xffffe52c]` |
| `1001a0f8` | `50` | `PUSH EAX` |
| `1001a0f9` | `53` | `PUSH EBX` |
| `1001a0fa` | `8d 85 48 e5 ff ff` | `LEA EAX,[EBP + 0xffffe548]` |
| `1001a100` | `50` | `PUSH EAX` |
| `1001a101` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001a103` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `1001a106` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `1001a10c` | `85 c0` | `TEST EAX,EAX` |
| `1001a10e` | `0f 84 62 01 00 00` | `JZ 0x1001a276` |
| `1001a114` | `8b 85 2c e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe52c]` |
| `1001a11a` | `01 85 38 e5 ff ff` | `ADD dword ptr [EBP + 0xffffe538],EAX` |
| `1001a120` | `3b c3` | `CMP EAX,EBX` |
| `1001a122` | `0f 8c 5a 01 00 00` | `JL 0x1001a282` |
| `1001a128` | `8b 85 44 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe544]` |
| `1001a12e` | `2b 85 34 e5 ff ff` | `SUB EAX,dword ptr [EBP + 0xffffe534]` |
| `1001a134` | `3b 45 10` | `CMP EAX,dword ptr [EBP + 0x10]` |
| `1001a137` | `0f 82 3f ff ff ff` | `JC 0x1001a07c` |
| `1001a13d` | `e9 40 01 00 00` | `JMP 0x1001a282` |
| `1001a142` | `39 4d 10` | `CMP dword ptr [EBP + 0x10],ECX` |
| `1001a145` | `0f 86 7c 01 00 00` | `JBE 0x1001a2c7` |
| `1001a14b` | `8b 8d 44 e5 ff ff` | `MOV ECX,dword ptr [EBP + 0xffffe544]` |
| `1001a151` | `83 a5 3c e5 ff ff 00` | `AND dword ptr [EBP + 0xffffe53c],0x0` |
| `1001a158` | `2b 8d 34 e5 ff ff` | `SUB ECX,dword ptr [EBP + 0xffffe534]` |
| `1001a15e` | `6a 02` | `PUSH 0x2` |
| `1001a160` | `8d 85 48 f9 ff ff` | `LEA EAX,[EBP + 0xfffff948]` |
| `1001a166` | `5e` | `POP ESI` |
| `1001a167` | `3b 4d 10` | `CMP ECX,dword ptr [EBP + 0x10]` |
| `1001a16a` | `73 3c` | `JNC 0x1001a1a8` |
| `1001a16c` | `8b 95 44 e5 ff ff` | `MOV EDX,dword ptr [EBP + 0xffffe544]` |
| `1001a172` | `0f b7 12` | `MOVZX EDX,word ptr [EDX]` |
| `1001a175` | `01 b5 44 e5 ff ff` | `ADD dword ptr [EBP + 0xffffe544],ESI` |
| `1001a17b` | `03 ce` | `ADD ECX,ESI` |
| `1001a17d` | `66 83 fa 0a` | `CMP DX,0xa` |
| `1001a181` | `75 0e` | `JNZ 0x1001a191` |
| `1001a183` | `6a 0d` | `PUSH 0xd` |
| `1001a185` | `5b` | `POP EBX` |
| `1001a186` | `66 89 18` | `MOV word ptr [EAX],BX` |
| `1001a189` | `03 c6` | `ADD EAX,ESI` |
| `1001a18b` | `01 b5 3c e5 ff ff` | `ADD dword ptr [EBP + 0xffffe53c],ESI` |
| `1001a191` | `01 b5 3c e5 ff ff` | `ADD dword ptr [EBP + 0xffffe53c],ESI` |
| `1001a197` | `66 89 10` | `MOV word ptr [EAX],DX` |
| `1001a19a` | `03 c6` | `ADD EAX,ESI` |
| `1001a19c` | `81 bd 3c e5 ff ff a8 06 00 00` | `CMP dword ptr [EBP + 0xffffe53c],0x6a8` |
| `1001a1a6` | `72 bf` | `JC 0x1001a167` |
| `1001a1a8` | `33 f6` | `XOR ESI,ESI` |
| `1001a1aa` | `56` | `PUSH ESI` |
| `1001a1ab` | `56` | `PUSH ESI` |
| `1001a1ac` | `68 55 0d 00 00` | `PUSH 0xd55` |
| `1001a1b1` | `8d 8d f0 eb ff ff` | `LEA ECX,[EBP + 0xffffebf0]` |
| `1001a1b7` | `51` | `PUSH ECX` |
| `1001a1b8` | `8d 8d 48 f9 ff ff` | `LEA ECX,[EBP + 0xfffff948]` |
| `1001a1be` | `2b c1` | `SUB EAX,ECX` |
| `1001a1c0` | `99` | `CDQ` |
| `1001a1c1` | `2b c2` | `SUB EAX,EDX` |
| `1001a1c3` | `d1 f8` | `SAR EAX,0x1` |
| `1001a1c5` | `50` | `PUSH EAX` |
| `1001a1c6` | `8b c1` | `MOV EAX,ECX` |
| `1001a1c8` | `50` | `PUSH EAX` |
| `1001a1c9` | `56` | `PUSH ESI` |
| `1001a1ca` | `68 e9 fd 00 00` | `PUSH 0xfde9` |
| `1001a1cf` | `ff 15 5c e0 02 10` | `CALL dword ptr [0x1002e05c]` |
| `1001a1d5` | `8b d8` | `MOV EBX,EAX` |
| `1001a1d7` | `3b de` | `CMP EBX,ESI` |
| `1001a1d9` | `0f 84 97 00 00 00` | `JZ 0x1001a276` |
| `1001a1df` | `6a 00` | `PUSH 0x0` |
| `1001a1e1` | `8d 85 2c e5 ff ff` | `LEA EAX,[EBP + 0xffffe52c]` |
| `1001a1e7` | `50` | `PUSH EAX` |
| `1001a1e8` | `8b c3` | `MOV EAX,EBX` |
| `1001a1ea` | `2b c6` | `SUB EAX,ESI` |
| `1001a1ec` | `50` | `PUSH EAX` |
| `1001a1ed` | `8d 84 35 f0 eb ff ff` | `LEA EAX,[EBP + ESI*0x1 + 0xffffebf0]` |
| `1001a1f4` | `50` | `PUSH EAX` |
| `1001a1f5` | `8b 85 28 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe528]` |
| `1001a1fb` | `8b 00` | `MOV EAX,dword ptr [EAX]` |
| `1001a1fd` | `ff 34 07` | `PUSH dword ptr [EDI + EAX*0x1]` |
| `1001a200` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `1001a206` | `85 c0` | `TEST EAX,EAX` |
| `1001a208` | `74 0c` | `JZ 0x1001a216` |
| `1001a20a` | `03 b5 2c e5 ff ff` | `ADD ESI,dword ptr [EBP + 0xffffe52c]` |
| `1001a210` | `3b de` | `CMP EBX,ESI` |
| `1001a212` | `7f cb` | `JG 0x1001a1df` |
| `1001a214` | `eb 0c` | `JMP 0x1001a222` |
| `1001a216` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001a21c` | `89 85 40 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe540],EAX` |
| `1001a222` | `3b de` | `CMP EBX,ESI` |
| `1001a224` | `7f 5c` | `JG 0x1001a282` |
| `1001a226` | `8b 85 44 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe544]` |
| `1001a22c` | `2b 85 34 e5 ff ff` | `SUB EAX,dword ptr [EBP + 0xffffe534]` |
| `1001a232` | `89 85 38 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe538],EAX` |
| `1001a238` | `3b 45 10` | `CMP EAX,dword ptr [EBP + 0x10]` |
| `1001a23b` | `0f 82 0a ff ff ff` | `JC 0x1001a14b` |
| `1001a241` | `eb 3f` | `JMP 0x1001a282` |
| `1001a243` | `6a 00` | `PUSH 0x0` |
| `1001a245` | `8d 8d 2c e5 ff ff` | `LEA ECX,[EBP + 0xffffe52c]` |
| `1001a24b` | `51` | `PUSH ECX` |
| `1001a24c` | `ff 75 10` | `PUSH dword ptr [EBP + 0x10]` |
| `1001a24f` | `ff b5 34 e5 ff ff` | `PUSH dword ptr [EBP + 0xffffe534]` |
| `1001a255` | `ff 30` | `PUSH dword ptr [EAX]` |
| `1001a257` | `ff 15 00 e0 02 10` | `CALL dword ptr [0x1002e000]` |
| `1001a25d` | `85 c0` | `TEST EAX,EAX` |
| `1001a25f` | `74 15` | `JZ 0x1001a276` |
| `1001a261` | `8b 85 2c e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe52c]` |
| `1001a267` | `83 a5 40 e5 ff ff 00` | `AND dword ptr [EBP + 0xffffe540],0x0` |
| `1001a26e` | `89 85 38 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe538],EAX` |
| `1001a274` | `eb 0c` | `JMP 0x1001a282` |
| `1001a276` | `ff 15 50 e0 02 10` | `CALL dword ptr [0x1002e050]` |
| `1001a27c` | `89 85 40 e5 ff ff` | `MOV dword ptr [EBP + 0xffffe540],EAX` |
| `1001a282` | `83 bd 38 e5 ff ff 00` | `CMP dword ptr [EBP + 0xffffe538],0x0` |
| `1001a289` | `75 6c` | `JNZ 0x1001a2f7` |
| `1001a28b` | `83 bd 40 e5 ff ff 00` | `CMP dword ptr [EBP + 0xffffe540],0x0` |
| `1001a292` | `74 2d` | `JZ 0x1001a2c1` |
| `1001a294` | `6a 05` | `PUSH 0x5` |
| `1001a296` | `5e` | `POP ESI` |
| `1001a297` | `39 b5 40 e5 ff ff` | `CMP dword ptr [EBP + 0xffffe540],ESI` |
| `1001a29d` | `75 14` | `JNZ 0x1001a2b3` |
| `1001a29f` | `e8 65 ae ff ff` | `CALL 0x10015109` |
| `1001a2a4` | `c7 00 09 00 00 00` | `MOV dword ptr [EAX],0x9` |
| `1001a2aa` | `e8 6d ae ff ff` | `CALL 0x1001511c` |
| `1001a2af` | `89 30` | `MOV dword ptr [EAX],ESI` |
| `1001a2b1` | `eb 3f` | `JMP 0x1001a2f2` |
| `1001a2b3` | `ff b5 40 e5 ff ff` | `PUSH dword ptr [EBP + 0xffffe540]` |
| `1001a2b9` | `e8 71 ae ff ff` | `CALL 0x1001512f` |
| `1001a2be` | `59` | `POP ECX` |
| `1001a2bf` | `eb 31` | `JMP 0x1001a2f2` |
| `1001a2c1` | `8b b5 28 e5 ff ff` | `MOV ESI,dword ptr [EBP + 0xffffe528]` |
| `1001a2c7` | `8b 06` | `MOV EAX,dword ptr [ESI]` |
| `1001a2c9` | `f6 44 07 04 40` | `TEST byte ptr [EDI + EAX*0x1 + 0x4],0x40` |
| `1001a2ce` | `74 0f` | `JZ 0x1001a2df` |
| `1001a2d0` | `8b 85 34 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe534]` |
| `1001a2d6` | `80 38 1a` | `CMP byte ptr [EAX],0x1a` |
| `1001a2d9` | `75 04` | `JNZ 0x1001a2df` |
| `1001a2db` | `33 c0` | `XOR EAX,EAX` |
| `1001a2dd` | `eb 24` | `JMP 0x1001a303` |
| `1001a2df` | `e8 25 ae ff ff` | `CALL 0x10015109` |
| `1001a2e4` | `c7 00 1c 00 00 00` | `MOV dword ptr [EAX],0x1c` |
| `1001a2ea` | `e8 2d ae ff ff` | `CALL 0x1001511c` |
| `1001a2ef` | `83 20 00` | `AND dword ptr [EAX],0x0` |
| `1001a2f2` | `83 c8 ff` | `OR EAX,0xffffffff` |
| `1001a2f5` | `eb 0c` | `JMP 0x1001a303` |
| `1001a2f7` | `8b 85 38 e5 ff ff` | `MOV EAX,dword ptr [EBP + 0xffffe538]` |
| `1001a2fd` | `2b 85 30 e5 ff ff` | `SUB EAX,dword ptr [EBP + 0xffffe530]` |
| `1001a303` | `5f` | `POP EDI` |
| `1001a304` | `5b` | `POP EBX` |
| `1001a305` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1001a308` | `33 cd` | `XOR ECX,EBP` |
| `1001a30a` | `5e` | `POP ESI` |
| `1001a30b` | `e8 bb 69 ff ff` | `CALL 0x10010ccb` |
| `1001a310` | `c9` | `LEAVE` |
| `1001a311` | `c3` | `RET` |
