
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d960(void)

{
  HMODULE pHVar1;
  char cVar2;
  SHORT SVar3;
  SHORT SVar4;
  int iVar5;
  BOOL BVar6;
  HRSRC pHVar7;
  HGLOBAL pvVar8;
  LPCWSTR pWVar9;
  int iVar10;
  clock_t cVar11;
  DWORD DVar12;
  char *pcVar13;
  LPCWSTR pWVar14;
  tagMSG local_4c;
  int local_30;
  char acStack_2c [16];
  char acStack_1c [16];
  uint local_c;
  
  local_c = DAT_00871720 ^ (uint)&local_4c;
LAB_0045d97f:
  local_30 = 0;
  iVar5 = PeekMessageA(&local_4c,(HWND)0x0,0x8000,0x8000,0);
  while (iVar5 != 0) {
    if (local_4c.message != 0x12) {
      PeekMessageA(&local_4c,(HWND)0x0,0x8000,0x8000,1);
    }
    iVar5 = PeekMessageA(&local_4c,(HWND)0x0,0x8000,0x8000,0);
  }
  FUN_0045d8e0();
  ShowWindow(DAT_00ad7508,DAT_009e6cbc);
  DAT_009e6cbc = 1;
  SetForegroundWindow(DAT_00ad7508);
  FUN_00479880();
  FUN_004798e0();
switchD_0045daf7_caseD_12:
  do {
    while( true ) {
      if ((DAT_00b19810 != (HWND)0x0) && (BVar6 = IsWindow(DAT_00b19810), BVar6 == 0))
      goto LAB_0045e187;
      BVar6 = PeekMessageA(&local_4c,(HWND)0x0,0,0,1);
      if (BVar6 != 0) break;
      if ((DAT_00ad7468 != (HANDLE)0x0) &&
         (cVar11 = _clock(), DAT_009e6d18 <= cVar11 - DAT_0089e21c)) {
        PostThreadMessageA(DAT_00ad746c,0x8000,0,0);
        DVar12 = WaitForSingleObject(DAT_00ad7468,10000);
        if (DVar12 != 0) {
          TerminateThread(DAT_00ad7468,1);
        }
        _DAT_00ad7464 = 0;
        CloseHandle(DAT_00ad7468);
        DAT_00ad7468 = (HANDLE)0x0;
        DAT_00ad746c = 0;
      }
      FUN_0045d7c0();
    }
    if (local_4c.message == 0x12) goto LAB_0045e187;
    if (local_4c.message == 0x8000) break;
    if (((DAT_0087726b == '\0') || (DAT_00b19814 != 0)) || (cVar2 = FUN_00463c30(), cVar2 == '\0'))
    {
      if ((local_4c.message == 0x104) || (local_4c.message == 0x100)) {
        if ((local_4c.lParam & 0x20000000U) == 0) {
          switch(local_4c.wParam) {
          case 8:
            if (DAT_00ad7510 == (HWND)0x0) {
              DAT_00ad74c9 = DAT_00ad74c9 == '\0';
              if ((bool)DAT_00ad74c9) {
                FUN_0045d3d0();
              }
              else {
                DAT_00b19dd4 = 0;
              }
            }
            break;
          case 0xd:
            if (DAT_00ad7510 == (HWND)0x0) {
              SVar3 = GetAsyncKeyState(0x11);
              if (SVar3 < 0) {
                DAT_0087726b = DAT_0087726b == '\0';
                PostMessageA((HWND)0x0,0x8000,0,0);
              }
            }
            else {
              iVar5 = 0;
              if (DAT_00b19e08 != '\0') {
                do {
                  iVar10 = iVar5 + 1;
                  if ((&DAT_00b19e08)[iVar5] != ' ') break;
                  pcVar13 = &DAT_00b19e09 + iVar5;
                  iVar5 = iVar10;
                } while (*pcVar13 != '\0');
                if (iVar10 != 0) {
                  ggpo_client_chat(DAT_00b1a804,&DAT_00b19e08);
                }
              }
              DAT_00b189da = 0;
              DestroyWindow(DAT_00ad7510);
              DAT_00ad7510 = (HWND)0x0;
            }
            break;
          case 0x1b:
            if (DAT_00ad7510 == (HWND)0x0) {
              if (DAT_00ad735c == '\0') {
                if (DAT_00b19814 != 0) {
                  DAT_00b19814 = 0;
                  PostMessageA((HWND)0x0,0x8000,0,0);
                }
              }
              else {
                PostQuitMessage(0);
              }
            }
            else {
              DAT_00b189da = 0;
              DestroyWindow(DAT_00ad7510);
              DAT_00ad7510 = (HWND)0x0;
            }
            break;
          case 0x54:
            if (((DAT_00ad74dc != 0) && (DAT_00ad7510 == (HWND)0x0)) &&
               (iVar5 = FUN_00456d20(), iVar5 != 0)) {
              FUN_0045f700();
            }
            break;
          case 0x70:
            if (DAT_00ad74dc == 0) {
              SVar3 = GetAsyncKeyState(0x10);
              SVar4 = GetAsyncKeyState(0x11);
              if (SVar4 == 0 && ((int)SVar3 & 0x80000000U) == 0) {
                if (DAT_00ad74cc == 0) {
                  DAT_00ad74cb = 1;
                }
                else {
                  DAT_00ad74ca = 1;
                }
              }
            }
          }
        }
        else {
          switch(local_4c.wParam) {
          case 0x12:
            goto switchD_0045daf7_caseD_12;
          case 0x53:
            if (DAT_00ad74dc != 0) {
              if (DAT_00b1adc4 == '\0') {
                FUN_0062ead0();
              }
              FUN_0062eb50();
            }
            break;
          case 0xbb:
            DAT_00875708 = DAT_00875708 + 100;
            SVar3 = GetAsyncKeyState(0x11);
            if (SVar3 < 0) {
              DAT_00875708 = DAT_00875708 + 900;
            }
            if (10000 < DAT_00875708) {
              DAT_00875708 = 10000;
            }
            if (((DAT_00b189fe == '\0') || (DAT_00b19fac != 0)) ||
               (iVar5 = (**(code **)(PTR_PTR_00875710 + 0x1c))(), pHVar1 = DAT_00ad6f40, iVar5 != 0)
               ) {
              pHVar1 = DAT_00ad6f40;
              if ((DAT_00b181e9 == '\0') ||
                 (pcVar13 = *(char **)(DAT_00b1820c + 0x13bc), pcVar13 == (char *)0x0)) {
                pHVar7 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x28,(LPCSTR)0x6);
                pvVar8 = LoadResource(pHVar1,pHVar7);
                pWVar9 = LockResource(pvVar8);
                pWVar14 = (LPCWSTR)0x0;
                if (pWVar9 != (LPCWSTR)0x0) {
                  iVar5 = 7;
                  pWVar14 = pWVar9;
                  do {
                    iVar5 = iVar5 + -1;
                    pWVar14 = pWVar14 + (ushort)*pWVar14 + 1;
                  } while (iVar5 != 0);
                }
                pWVar9 = pWVar14 + 1;
                if (*pWVar14 == L'\0') {
                  pWVar9 = pWVar14;
                }
                iVar5 = WideCharToMultiByte(0,0,pWVar9,(uint)(ushort)*pWVar14,&DAT_00b1b920,0x1400,
                                            (LPCSTR)0x0,(LPBOOL)0x0);
                if (iVar5 == 0) {
                  pcVar13 = (char *)0x0;
                }
                else {
                  (&DAT_00b1b920)[(ushort)*pWVar14] = 0;
                  pcVar13 = &DAT_00b1b920;
                }
              }
              _sprintf(acStack_2c,pcVar13,DAT_00875708 / 100);
              FUN_005553d0(0,5);
            }
            else {
              if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x13b4) == 0)) {
                pHVar7 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x28,(LPCSTR)0x6);
                pvVar8 = LoadResource(pHVar1,pHVar7);
                pWVar9 = LockResource(pvVar8);
                pWVar14 = (LPCWSTR)0x0;
                if (pWVar9 != (LPCWSTR)0x0) {
                  iVar5 = 6;
                  pWVar14 = pWVar9;
                  do {
                    iVar5 = iVar5 + -1;
                    pWVar14 = pWVar14 + (ushort)*pWVar14 + 1;
                  } while (iVar5 != 0);
                }
                pWVar9 = pWVar14 + 1;
                if (*pWVar14 == L'\0') {
                  pWVar9 = pWVar14;
                }
                iVar5 = WideCharToMultiByte(0,0,pWVar9,(uint)(ushort)*pWVar14,&DAT_00b1b920,0x1400,
                                            (LPCSTR)0x0,(LPBOOL)0x0);
                if (iVar5 != 0) {
                  (&DAT_00b1b920)[(ushort)*pWVar14] = 0;
                  FUN_005553d0(0,5);
                  break;
                }
              }
LAB_0045dbf5:
              FUN_005553d0(0,5);
            }
            break;
          case 0xbd:
            DAT_00875708 = DAT_00875708 + -100;
            SVar3 = GetAsyncKeyState(0x11);
            if (SVar3 < 0) {
              DAT_00875708 = DAT_00875708 + -900;
            }
            if (DAT_00875708 < 0) {
              DAT_00875708 = 0;
            }
            if (((DAT_00b189fe != '\0') && (DAT_00b19fac == 0)) &&
               (iVar5 = (**(code **)(PTR_PTR_00875710 + 0x1c))(), pHVar1 = DAT_00ad6f40, iVar5 == 0)
               ) {
              if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x13b4) == 0)) {
                pHVar7 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x28,(LPCSTR)0x6);
                pvVar8 = LoadResource(pHVar1,pHVar7);
                pWVar9 = LockResource(pvVar8);
                pWVar14 = (LPCWSTR)0x0;
                if (pWVar9 != (LPCWSTR)0x0) {
                  iVar5 = 6;
                  pWVar14 = pWVar9;
                  do {
                    iVar5 = iVar5 + -1;
                    pWVar14 = pWVar14 + (ushort)*pWVar14 + 1;
                  } while (iVar5 != 0);
                }
                pWVar9 = pWVar14 + 1;
                if (*pWVar14 == L'\0') {
                  pWVar9 = pWVar14;
                }
                iVar5 = WideCharToMultiByte(0,0,pWVar9,(uint)(ushort)*pWVar14,&DAT_00b1b920,0x1400,
                                            (LPCSTR)0x0,(LPBOOL)0x0);
                if (iVar5 != 0) {
                  (&DAT_00b1b920)[(ushort)*pWVar14] = 0;
                  FUN_005553d0(0,5);
                  break;
                }
              }
              goto LAB_0045dbf5;
            }
            pHVar1 = DAT_00ad6f40;
            if ((DAT_00b181e9 == '\0') ||
               (pcVar13 = *(char **)(DAT_00b1820c + 0x13bc), pcVar13 == (char *)0x0)) {
              pHVar7 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x28,(LPCSTR)0x6);
              pvVar8 = LoadResource(pHVar1,pHVar7);
              pWVar9 = LockResource(pvVar8);
              pWVar14 = (LPCWSTR)0x0;
              if (pWVar9 != (LPCWSTR)0x0) {
                iVar5 = 7;
                pWVar14 = pWVar9;
                do {
                  iVar5 = iVar5 + -1;
                  pWVar14 = pWVar14 + (ushort)*pWVar14 + 1;
                } while (iVar5 != 0);
              }
              pWVar9 = pWVar14 + 1;
              if (*pWVar14 == L'\0') {
                pWVar9 = pWVar14;
              }
              iVar5 = WideCharToMultiByte(0,0,pWVar9,(uint)(ushort)*pWVar14,&DAT_00b1b920,0x1400,
                                          (LPCSTR)0x0,(LPBOOL)0x0);
              if (iVar5 == 0) {
                pcVar13 = (char *)0x0;
              }
              else {
                (&DAT_00b1b920)[(ushort)*pWVar14] = 0;
                pcVar13 = &DAT_00b1b920;
              }
            }
            _sprintf(acStack_1c,pcVar13,DAT_00875708 / 100);
            FUN_005553d0(0,5);
          }
        }
      }
      else if ((local_4c.message == 0x105) || (local_4c.message == 0x101)) {
        if (local_4c.wParam == 0x12) goto switchD_0045daf7_caseD_12;
        if (local_4c.wParam == 0x70) {
          DAT_00ad74cb = 0;
        }
      }
      BVar6 = IsDialogMessageA(DAT_00b181b4,&local_4c);
      if (((((BVar6 == 0) && (BVar6 = IsDialogMessageA(DAT_00b181ec,&local_4c), BVar6 == 0)) &&
           (BVar6 = IsDialogMessageA(DAT_00b181f8,&local_4c), BVar6 == 0)) &&
          ((BVar6 = IsDialogMessageA(DAT_00ad747c,&local_4c), BVar6 == 0 &&
           (BVar6 = IsDialogMessageA(DAT_00b181d0,&local_4c), BVar6 == 0)))) &&
         ((BVar6 = IsDialogMessageA(DAT_00b181a4,&local_4c), BVar6 == 0 &&
          (iVar5 = TranslateAcceleratorA(DAT_00ad7508,DAT_00ad7348,&local_4c), iVar5 == 0)))) {
        if (DAT_00ad7510 != (HWND)0x0) {
          TranslateMessage(&local_4c);
        }
        DispatchMessageA(&local_4c);
      }
    }
  } while( true );
  local_30 = 1;
LAB_0045e187:
  _DAT_00ad74e0 = 0;
  if (DAT_00b19fac == 0) {
    (**(code **)(PTR_PTR_00875710 + 0x14))();
  }
  FUN_0045cdc0();
  if (local_30 == 0) {
    __security_check_cookie(local_c ^ (uint)&local_4c);
    return;
  }
  FUN_0045cc40();
  goto LAB_0045d97f;
}
