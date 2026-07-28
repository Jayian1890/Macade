
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004608e0(int param_1,int param_2)

{
  HMODULE pHVar1;
  char *pcVar2;
  ushort *puVar3;
  HANDLE pvVar4;
  int iVar5;
  FILE *_File;
  HRSRC pHVar6;
  HGLOBAL pvVar7;
  LPCWSTR pWVar8;
  int iVar9;
  LPCWSTR pWVar10;
  uint uVar11;
  double local_314;
  char local_30c [256];
  char local_20c [256];
  char local_10c [260];
  uint local_8;
  
  pHVar1 = DAT_00ad6f40;
  local_8 = DAT_00871720 ^ (uint)&local_314;
  if (0x283c < param_1) {
    if (param_1 < 0x296f) {
      if (param_1 == 0x296e) {
        FUN_0055f450();
        FUN_004682e0();
      }
      else {
        switch(param_1) {
        case 0x283d:
          DAT_00ad735d = DAT_00ad735d == '\0';
          break;
        case 0x283e:
          DAT_00875810 = (uint)(DAT_00875810 == 0);
          FUN_005514e0();
          break;
        case 0x283f:
          DAT_00ad7517 = DAT_00ad7517 == '\0';
          PostMessageA((HWND)0x0,0x8000,0,0);
          break;
        case 0x2842:
          FUN_00560270();
          FUN_0046b760();
          break;
        case 0x2843:
          if (DAT_00b19814 == 0) {
            FUN_00472050();
            PostMessageA((HWND)0x0,0x8000,0,0);
          }
          break;
        case 0x2844:
          if (DAT_00b19814 == 0) {
            FUN_004720c0();
          }
          break;
        case 0x2846:
          iVar9 = 0xf;
          DAT_00ad6f44 = 0xf;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x2847:
          iVar9 = 2;
          DAT_00ad6f44 = 2;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x2848:
          iVar9 = 1;
          DAT_00ad6f44 = 1;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x2849:
          iVar9 = 0;
          DAT_00ad6f44 = 0;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x284a:
          iVar9 = -1;
          DAT_00ad6f44 = 0xffffffff;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x284b:
          iVar9 = -2;
          DAT_00ad6f44 = 0xfffffffe;
          pvVar4 = GetCurrentThread();
          SetThreadPriority(pvVar4,iVar9);
          break;
        case 0x284d:
          if (DAT_00b19814 == 0) {
            FUN_00560270();
            FUN_0046c950();
          }
          break;
        case 0x284e:
          if (DAT_00ad74c4 != 0) {
            iVar9 = FUN_00475640();
            pHVar1 = DAT_00ad6f40;
            if (iVar9 == 0) {
              if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x1364) == 0)) {
                pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x27,(LPCSTR)0x6);
                pvVar7 = LoadResource(pHVar1,pHVar6);
                pWVar8 = LockResource(pvVar7);
                pWVar10 = (LPCWSTR)0x0;
                if (pWVar8 != (LPCWSTR)0x0) {
                  iVar9 = 0xc;
                  pWVar10 = pWVar8;
                  do {
                    iVar9 = iVar9 + -1;
                    pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
                  } while (iVar9 != 0);
                }
                pWVar8 = pWVar10 + 1;
                if (*pWVar10 == L'\0') {
                  pWVar8 = pWVar10;
                }
                iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                            (LPCSTR)0x0,(LPBOOL)0x0);
                if (iVar9 != 0) {
                  (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
                  FUN_005553d0(0,5);
                  break;
                }
              }
              goto LAB_00461034;
            }
            if ((DAT_00b181e9 == '\0') ||
               (pcVar2 = *(char **)(DAT_00b1820c + 0x136c), pcVar2 == (char *)0x0)) {
              pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x27,(LPCSTR)0x6);
              pvVar7 = LoadResource(pHVar1,pHVar6);
              pWVar8 = LockResource(pvVar7);
              pWVar10 = (LPCWSTR)0x0;
              if (pWVar8 != (LPCWSTR)0x0) {
                iVar5 = 0xd;
                pWVar10 = pWVar8;
                do {
                  iVar5 = iVar5 + -1;
                  pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
                } while (iVar5 != 0);
              }
              pWVar8 = pWVar10 + 1;
              if (*pWVar10 == L'\0') {
                pWVar8 = pWVar10;
              }
              iVar5 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                          (LPCSTR)0x0,(LPBOOL)0x0);
              if (iVar5 == 0) {
                pcVar2 = (char *)0x0;
              }
              else {
                (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
                pcVar2 = &DAT_00b1b920;
              }
            }
            __snprintf(local_10c,0x100,pcVar2,iVar9);
            FUN_005553d0(0,5);
          }
          break;
        case 0x2850:
          if (DAT_00b19814 == 0) {
            FUN_0045fd80(0);
          }
          break;
        case 0x2851:
          if (DAT_00b19814 == 0) {
            FUN_0045fd80(1);
          }
          break;
        case 0x285a:
          FUN_0045a220(1);
          break;
        case 0x285b:
          FUN_0045a220(0);
          break;
        case 0x285c:
          FUN_00476ae0(1);
          break;
        case 0x285d:
          DAT_0087726a = DAT_0087726a == '\0';
          break;
        case 0x285e:
          FUN_0046f780();
          break;
        case 0x285f:
          FUN_0046ea20();
          PostMessageA((HWND)0x0,0x8000,0,0);
          break;
        case 0x2898:
          if (DAT_00b19814 == 0) {
            FUN_00560270();
            PostMessageA((HWND)0x0,0x8000,0,0);
          }
          break;
        case 0x2899:
          DAT_00874f76 = DAT_00874f76 == '\0';
          break;
        case 0x2905:
          if (DAT_00b19814 == 0) {
            FUN_00560270();
            FUN_0055f450();
            FUN_00457950();
            FUN_004798e0();
          }
          break;
        case 0x2906:
          if (DAT_00b19814 == 0) {
            FUN_00560270();
            FUN_0055f450();
            FUN_00459f80();
            FUN_004798e0();
          }
          break;
        case 0x2907:
          if ((DAT_00b19814 == 0) && (_File = _fopen("readme.txt","r"), _File != (FILE *)0x0)) {
            _fclose(_File);
            ShellExecuteA((HWND)0x0,"open","readme.txt",(LPCSTR)0x0,(LPCSTR)0x0,1);
          }
          break;
        case 0x2908:
          if (DAT_00b19814 == 0) {
            ShellExecuteA((HWND)0x0,"open","http://fba.emuunlim.com/",(LPCSTR)0x0,(LPCSTR)0x0,1);
          }
          break;
        case 0x2909:
          if (DAT_00b19814 == 0) {
            ShellExecuteA((HWND)0x0,"open","http://fba.emuunlim.com/forums",(LPCSTR)0x0,(LPCSTR)0x0,
                          1);
          }
        }
      }
    }
    else if (param_1 == 0x296f) {
      FUN_0055f450();
      FUN_004683e0();
    }
    goto switchD_00460934_caseD_271d;
  }
  if (param_1 == 0x283c) {
    DAT_0089aba4 = (uint)(DAT_0089aba4 == 0);
    goto switchD_00460934_caseD_271d;
  }
  switch(param_1) {
  case 0x2711:
    if (((DAT_00ad74dc == 0) && (DAT_00b19814 == 0)) && (DAT_00b1ad0c == '\0')) {
      FUN_004573d0(1);
      FUN_00466ab0();
      FUN_00560270();
      DAT_00b1ad0c = 1;
      FUN_0055f4b0();
      iVar9 = FUN_0045cb90();
      if (iVar9 < 0) {
        FUN_004798e0();
        FUN_0055f480();
        DAT_00b1ad0c = '\0';
      }
      else {
        FUN_0045cf70(iVar9,1);
        FUN_00465610();
        DAT_00ad74d0 = 0;
        FUN_0055f480();
        DAT_00b1ad0c = '\0';
      }
    }
    break;
  case 0x2712:
    if (DAT_00ad74dc == 0) {
      FUN_00560270();
      FUN_0055f450();
      FUN_004573d0(1);
      FUN_00466ab0();
      FUN_0045d0e0();
      FUN_0045fcc0();
      FUN_00465610();
      FUN_00560270();
    }
    break;
  case 0x2713:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0055f4b0();
      FUN_004573d0(1);
      FUN_00466ab0();
      FUN_004665d0(0);
      FUN_004798e0();
      FUN_0055f480();
    }
    break;
  case 0x2714:
    if ((DAT_00b19814 == 0) && (DAT_00ad7554 != 1)) {
      FUN_00560270();
      FUN_0055f450();
      FUN_00466ab0();
      FUN_00466290();
      FUN_004798e0();
    }
    break;
  case 0x2715:
    FUN_00466ab0();
    break;
  case 0x2716:
    FUN_0055f450();
    if (DAT_00b19814 != 0) {
      DAT_00b19814 = 0;
      FUN_00551170();
    }
    if (DAT_00ad74c4 != 0) {
      FUN_00466ab0();
      FUN_0045d0e0();
      if (DAT_00ad74dc != 0) {
        DAT_00ad74dc = 0;
        kailleraEndGame();
        FUN_0045f6e0();
        PostQuitMessage(0);
      }
      DAT_009eb0ee = 1;
      FUN_00462fe0();
      FUN_00463490();
      FUN_00465610();
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x2717:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0046a4c0();
    }
    break;
  case 0x2718:
    if ((DAT_00ad74c4 == 0) || (DAT_00ad74dc != 0)) {
      DAT_00ad74cc = 0;
      DAT_00ad74d0 = 0;
      FUN_004798e0();
    }
    else {
      FUN_0045f580();
    }
    break;
  case 0x2719:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0046c300();
    }
    break;
  case 0x271a:
    FUN_0055f450();
    FUN_0046e770();
    FUN_00465610();
    FUN_004798e0();
    break;
  case 0x271b:
    DAT_00877260 = 0x100;
    FUN_00465610();
    break;
  case 0x271c:
    FUN_00466ab0();
    if (DAT_00ad74dc != 0) {
      DAT_00ad74dc = 0;
      kailleraEndGame();
      FUN_0045f6e0();
    }
    PostQuitMessage(0);
    goto LAB_0046257c;
  case 0x2724:
    if (((DAT_00ad74c4 != 0) && (DAT_00b19814 == 0)) &&
       ((DAT_00ad74dc == 0 &&
        ((*(uint *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x38) & 0xffff0000) == 0x5010000)))) {
      FUN_00560270();
      FUN_0055f450();
      FUN_00467fe0();
      FUN_00467900();
      FUN_00467f60();
      FUN_004798e0();
    }
    break;
  case 0x2725:
    if ((((DAT_00ad74c4 != 0) && (DAT_00b19814 == 0)) && (DAT_00ad74dc == 0)) &&
       ((*(uint *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x38) & 0xffff0000) == 0x5010000)) {
      FUN_00560270();
      FUN_0055f450();
      FUN_00467fe0();
      FUN_00467b90();
      FUN_00467f60();
      FUN_004798e0();
    }
    break;
  case 0x2726:
    if ((DAT_00ad74dc == 0) &&
       ((*(uint *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x38) & 0xffff0000) == 0x5010000)) {
LAB_00460ce9:
      FUN_00467f60();
    }
    break;
  case 0x2727:
    if ((DAT_00ad74dc == 0) &&
       ((*(uint *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x38) & 0xffff0000) == 0x5010000)) {
      FUN_00467fe0();
    }
    break;
  case 0x2728:
    if ((((DAT_00ad74c4 != 0) && (DAT_00ad74dc == 0)) &&
        ((*(uint *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x38) & 0xffff0000) == 0x5010000)) &&
       ((DAT_00b1819c & 1) != 0)) {
      if ((DAT_00b1819c & 2) == 0) goto LAB_00460ce9;
      FUN_00467fe0();
    }
    break;
  case 0x272e:
    if ((DAT_00b19814 == 0) && (DAT_00ad74dc == 0)) {
      FUN_00560270();
      FUN_0055f4b0();
      FUN_004573d0(1);
      FUN_0046cbd0();
      FUN_004798e0();
      FUN_0055f480();
    }
    break;
  case 0x272f:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0055f450();
      FUN_0046ce10();
      FUN_004798e0();
    }
    goto LAB_0046257c;
  case 0x2730:
    if ((DAT_00ad74c4 != 0) && (DAT_00ad74dc == 0)) {
      iVar9 = FUN_0046cbd0();
      pHVar1 = DAT_00ad6f40;
      if (iVar9 == 0) {
        if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x128c) == 0)) {
          pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
          pvVar7 = LoadResource(pHVar1,pHVar6);
          puVar3 = LockResource(pvVar7);
          pWVar10 = (LPCWSTR)0x0;
          if (puVar3 != (ushort *)0x0) {
            pWVar10 = (LPCWSTR)(puVar3 + *puVar3 + 1);
          }
          pWVar8 = pWVar10 + 1;
          if (*pWVar10 == L'\0') {
            pWVar8 = pWVar10;
          }
          iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                      (LPCSTR)0x0,(LPBOOL)0x0);
          if (iVar9 != 0) {
            (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
            FUN_005553d0(0,5);
            break;
          }
        }
LAB_00461034:
        FUN_005553d0(0,5);
      }
      else {
        if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x1294) == 0)) {
          pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
          pvVar7 = LoadResource(pHVar1,pHVar6);
          pWVar8 = LockResource(pvVar7);
          pWVar10 = (LPCWSTR)0x0;
          if (pWVar8 != (LPCWSTR)0x0) {
            iVar9 = 2;
            pWVar10 = pWVar8;
            do {
              iVar9 = iVar9 + -1;
              pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
            } while (iVar9 != 0);
          }
          pWVar8 = pWVar10 + 1;
          if (*pWVar10 == L'\0') {
            pWVar8 = pWVar10;
          }
          iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                      (LPCSTR)0x0,(LPBOOL)0x0);
          if (iVar9 != 0) {
            (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
            FUN_005553d0(0,5);
            break;
          }
        }
        FUN_005553d0(0,5);
      }
    }
    break;
  case 0x2731:
    if (DAT_00ad74c4 != 0) {
      iVar9 = FUN_0046ce10();
      pHVar1 = DAT_00ad6f40;
      if (iVar9 == 0) {
        if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x129c) == 0)) {
          pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
          pvVar7 = LoadResource(pHVar1,pHVar6);
          pWVar8 = LockResource(pvVar7);
          pWVar10 = (LPCWSTR)0x0;
          if (pWVar8 != (LPCWSTR)0x0) {
            iVar9 = 3;
            pWVar10 = pWVar8;
            do {
              iVar9 = iVar9 + -1;
              pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
            } while (iVar9 != 0);
          }
          pWVar8 = pWVar10 + 1;
          if (*pWVar10 == L'\0') {
            pWVar8 = pWVar10;
          }
          iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                      (LPCSTR)0x0,(LPBOOL)0x0);
          if (iVar9 != 0) {
            (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
            FUN_005553d0(0,5);
            break;
          }
        }
        goto LAB_00461034;
      }
      if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x12a4) == 0)) {
        pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
        pvVar7 = LoadResource(pHVar1,pHVar6);
        pWVar8 = LockResource(pvVar7);
        pWVar10 = (LPCWSTR)0x0;
        if (pWVar8 != (LPCWSTR)0x0) {
          iVar9 = 4;
          pWVar10 = pWVar8;
          do {
            iVar9 = iVar9 + -1;
            pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
          } while (iVar9 != 0);
        }
        pWVar8 = pWVar10 + 1;
        if (*pWVar10 == L'\0') {
          pWVar8 = pWVar10;
        }
        iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar9 != 0) {
          (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
        }
      }
      FUN_005553d0(0,5);
      FUN_0045f580();
    }
    break;
  case 0x2732:
    DAT_0089cbe4 = DAT_0089cbe4 + -1;
    if (DAT_0089cbe4 < 1) {
      DAT_0089cbe4 = 1;
    }
    if ((DAT_00b181e9 == '\0') ||
       (pcVar2 = *(char **)(DAT_00b1820c + 0x1284), pcVar2 == (char *)0x0)) {
      pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
      pvVar7 = LoadResource(pHVar1,pHVar6);
      pWVar8 = LockResource(pvVar7);
      pWVar10 = pWVar8 + 1;
      if (*pWVar8 == L'\0') {
        pWVar10 = pWVar8;
      }
      iVar9 = WideCharToMultiByte(0,0,pWVar10,(uint)(ushort)*pWVar8,&DAT_00b1b920,0x1400,(LPCSTR)0x0
                                  ,(LPBOOL)0x0);
      if (iVar9 == 0) {
        pcVar2 = (char *)0x0;
      }
      else {
        (&DAT_00b1b920)[(ushort)*pWVar8] = 0;
        pcVar2 = &DAT_00b1b920;
      }
    }
    __snprintf(local_30c,0x100,pcVar2,DAT_0089cbe4);
    FUN_005553d0(0,5);
    break;
  case 0x2733:
    DAT_0089cbe4 = DAT_0089cbe4 + 1;
    if (8 < DAT_0089cbe4) {
      DAT_0089cbe4 = 8;
    }
    if ((DAT_00b181e9 == '\0') ||
       (pcVar2 = *(char **)(DAT_00b1820c + 0x1284), pcVar2 == (char *)0x0)) {
      pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x26,(LPCSTR)0x6);
      pvVar7 = LoadResource(pHVar1,pHVar6);
      pWVar8 = LockResource(pvVar7);
      pWVar10 = pWVar8 + 1;
      if (*pWVar8 == L'\0') {
        pWVar10 = pWVar8;
      }
      iVar9 = WideCharToMultiByte(0,0,pWVar10,(uint)(ushort)*pWVar8,&DAT_00b1b920,0x1400,(LPCSTR)0x0
                                  ,(LPBOOL)0x0);
      if (iVar9 == 0) {
        pcVar2 = (char *)0x0;
      }
      else {
        (&DAT_00b1b920)[(ushort)*pWVar8] = 0;
        pcVar2 = &DAT_00b1b920;
      }
    }
    __snprintf(local_20c,0x100,pcVar2,DAT_0089cbe4);
    FUN_005553d0(0,5);
    break;
  case 0x2734:
    DAT_00b18204 = (uint)(DAT_00b18204 == 0);
    break;
  case 0x2774:
    DAT_00b19820 = (uint)(DAT_00b19820 == 0);
    break;
  case 0x2776:
    if ((DAT_00ad74c4 != 0) || (DAT_00b19814 != 0)) {
      DAT_00b19814 = (uint)(DAT_00b19814 == 0);
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    goto LAB_0046257c;
  case 0x277e:
    DAT_008758b0 = 0;
    goto LAB_00461261;
  case 0x277f:
    DAT_00b19818 = 1;
    DAT_008758b0 = 0;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x2780:
    DAT_008758b0 = 1;
LAB_00461261:
    DAT_00b19818 = 0;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x2789:
    DAT_00b19804 = 0;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x278a:
    DAT_00b19804 = 1;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x278b:
    DAT_00b19804 = 2;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x278c:
    DAT_00b19804 = 3;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x2792:
    DAT_00ad7550 = 0;
    DAT_00b19830 = (uint)(DAT_00b19830 == 0);
    break;
  case 0x2793:
    DAT_0087581c = DAT_009965b0;
    DAT_008758a8 = DAT_009965b4;
    goto LAB_0046138a;
  case 0x2794:
    DAT_0087581c = DAT_009965b8;
    DAT_008758a8 = DAT_009965bc;
    DAT_00b19830 = 0;
    DAT_00ad7550 = 0;
    break;
  case 0x2795:
    DAT_0087581c = DAT_009965c0;
    DAT_008758a8 = DAT_009965c4;
    DAT_00b19830 = 0;
    DAT_00ad7550 = 0;
    break;
  case 0x2796:
    DAT_0087581c = DAT_009965c8;
    DAT_008758a8 = DAT_009965cc;
LAB_0046138a:
    DAT_00b19830 = 0;
    DAT_00ad7550 = 0;
    break;
  case 0x2797:
    DAT_00b19830 = 0;
    DAT_00ad7550 = 0;
    FUN_0055f450();
    FUN_00560270();
    FUN_0046e9c0();
    FUN_004798e0();
    break;
  case 0x2798:
    DAT_00ad7550 = 1;
    DAT_00b19830 = 0;
    break;
  case 0x2799:
    DAT_00ad7550 = 2;
    DAT_00b19830 = 0;
    break;
  case 0x279a:
    DAT_00ad7550 = 3;
    DAT_00b19830 = 0;
    break;
  case 0x279b:
    DAT_00ad7550 = 4;
    DAT_00b19830 = 0;
    break;
  case 0x279d:
    DAT_008758ac = 0x10;
    break;
  case 0x279e:
    DAT_008758ac = 0x18;
    break;
  case 0x279f:
    DAT_008758ac = 0x20;
    break;
  case 0x27a6:
    DAT_00b18330 = (uint)(DAT_00b18330 == 0);
    if (DAT_00ad74c4 == 0) break;
    goto LAB_00461481;
  case 0x27a7:
    _DAT_009965a8 = 1.25;
    goto LAB_004614a9;
  case 0x27a8:
    _DAT_009965a8 = 0.8;
LAB_004614a9:
    FUN_00473190();
    DAT_00b18330 = 1;
    if (DAT_00ad74c4 != 0) {
LAB_00461481:
      if (DAT_00b19804 == 1) {
        FUN_00550e90();
      }
      FUN_00473300();
LAB_0046148d:
      if (DAT_00ad74cc != 0) {
        FUN_00551490();
      }
    }
    break;
  case 0x27a9:
    if (DAT_00b19814 == 0) {
      local_314 = _DAT_009965a8;
      DAT_00b18330 = 1;
      if (DAT_00ad74c4 != 0) {
        if (DAT_00b19804 == 1) {
          FUN_00550e90();
        }
        FUN_00473300();
      }
      FUN_00560270();
      FUN_0055f450();
      FUN_0046d4a0();
      if ((_DAT_009965a8 <= 0.999) || (1.001 <= _DAT_009965a8)) {
        DAT_00b18330 = 1;
        FUN_00473190();
      }
      else {
        DAT_00b18330 = 0;
        _DAT_009965a8 = local_314;
        if (DAT_00b19804 == 1) {
          FUN_00550e90();
        }
        FUN_00473300();
      }
      if (DAT_00ad74c4 != 0) {
        FUN_005514b0();
      }
      FUN_004798e0();
    }
    break;
  case 0x27aa:
    DAT_008758cc = 1;
    DAT_00898794 = 0;
    if (DAT_00ad74c4 == 0) break;
    if (DAT_00b19804 == 1) {
      FUN_00550e90();
    }
    FUN_00473300();
    FUN_005514b0();
    goto LAB_0046148d;
  case 0x27ab:
    DAT_008758cc = 1;
    DAT_00898794 = 1;
    if (DAT_00ad74c4 != 0) {
      if (DAT_00b19804 == 1) {
        FUN_00550e90();
      }
      FUN_00473300();
      FUN_005514b0();
      goto LAB_0046148d;
    }
    break;
  case 0x27ac:
    DAT_008758cc = 0;
    DAT_00898794 = 0;
    if (DAT_00ad74c4 != 0) {
      if (DAT_00b19804 == 1) {
        FUN_00550e90();
      }
      FUN_00473300();
      FUN_005514b0();
      goto LAB_0046148d;
    }
    break;
  case 0x27b0:
    DAT_008758d4 = 0xffffffff;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27b1:
    DAT_008758d4 = 0;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27b2:
    DAT_008758d4 = 1;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27ba:
    if (DAT_00ad754c != 0) {
      DAT_00ad754c = 0;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27bb:
    iVar9 = 1;
    goto LAB_004616e0;
  case 0x27bc:
    iVar9 = 2;
    goto LAB_004616e0;
  case 0x27bd:
    if (DAT_00ad754c != 3) {
      DAT_00ad754c = 3;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27be:
    iVar9 = 4;
LAB_004616e0:
    if (DAT_00ad754c != iVar9) {
      DAT_00ad754c = iVar9;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27bf:
    if (DAT_00ad754c < 5) {
      DAT_00ad754c = 9999;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27c0:
    if (DAT_00ad74dc == 0) {
      DAT_00b189ca = DAT_00b189ca == '\0';
    }
    break;
  case 0x27c1:
    DAT_00ad74d4 = (uint)(DAT_00ad74d4 == 0);
    break;
  case 0x27c5:
    DAT_00b19834 = DAT_00b19834 ^ 1;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27c6:
    DAT_0087399e = DAT_0087399e == '\0';
    if (DAT_00ad74c4 == 0) {
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27ce:
    DAT_008758e8 = 4;
    DAT_008758ec = 3;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27cf:
    DAT_008758e8 = 5;
    DAT_008758ec = 4;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27d0:
    DAT_008758e8 = 0x10;
    DAT_008758ec = 9;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27d1:
    DAT_008758e8 = 0x10;
    DAT_008758ec = 10;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27d2:
    DAT_00b19834 = DAT_00b19834 ^ 2;
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x27d8:
    if ((DAT_00b19814 == 0) && (DAT_00ad74c4 == 0)) {
      FUN_0046d080();
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27d9:
    DAT_00b19fa4 = (uint)(DAT_00b19fa4 == 0);
    break;
  case 0x27ec:
    if (DAT_00ad74c4 == 0) {
      DAT_00875704 = 0;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27ed:
    if (DAT_00ad74c4 == 0) {
      DAT_00875704 = 0x2b11;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27ee:
    if (DAT_00ad74c4 == 0) {
      DAT_00875704 = 0x5622;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27ef:
    if (DAT_00ad74c4 == 0) {
      DAT_00875704 = 0xac44;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27f0:
    if (DAT_00ad74c4 == 0) {
      DAT_00875704 = 48000;
      PostMessageA((HWND)0x0,0x8000,0,0);
    }
    break;
  case 0x27f6:
    DAT_00877264 = 0;
    break;
  case 0x27f7:
    DAT_00877264 = 1;
    break;
  case 0x27f9:
    DAT_00877264 = 3;
    break;
  case 0x2800:
    DAT_00b19710 = 0;
    break;
  case 0x2801:
    DAT_00b19710 = 1;
    break;
  case 0x2803:
    DAT_00b19710 = 3;
  }
switchD_00460934_caseD_271d:
  iVar9 = DAT_00b19804;
  switch(DAT_00b19804) {
  case 0:
    switch(param_1) {
    case 0x2af9:
      DAT_00b19824 = 0;
      break;
    case 0x2afa:
      DAT_00b19824 = 1;
      DAT_008758c4 = 0;
      break;
    case 0x2afb:
      DAT_00b19824 = 1;
      DAT_008758c4 = 1;
      break;
    default:
      goto switchD_00461ea0_default;
    case 0x2b62:
switchD_00461f45_caseD_2b62:
      DAT_008758b8 = (uint)(DAT_008758b8 == 0);
    }
    goto switchD_00462312_caseD_2c38;
  case 1:
    if (0x2c1a < param_1) goto switchD_00461ea0_default;
    if (param_1 == 0x2c1a) {
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] ^ 0x4000000;
      goto switchD_00462312_caseD_2c38;
    }
    break;
  case 2:
    switch(param_1) {
    case 0x2bc1:
    case 0x2bc2:
    case 0x2bc3:
    case 0x2bc4:
    case 0x2bc5:
    case 0x2bc6:
    case 0x2bc7:
    case 0x2bc8:
    case 0x2bc9:
    case 0x2bca:
      *(undefined1 *)(&DAT_00b197e8 + DAT_00b19804) = 0;
      (&DAT_00b197e8)[iVar9] = (&DAT_00b197e8)[iVar9] | param_1 - 0x2bc1U;
      break;
    default:
      goto switchD_00461ea0_default;
    case 0x2c1a:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] ^ 0x100;
      break;
    case 0x2c1b:
switchD_00462312_caseD_2c39:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] ^ 0x200;
    }
    goto switchD_00462312_caseD_2c38;
  case 3:
    if (param_1 < 0x2b66) {
      if (param_1 == 0x2b65) {
        if (DAT_00b19814 == 0) {
          FUN_00560270();
          FUN_0055f450();
          if (DAT_00b19824 == 0) {
            DAT_00b19824 = 1;
            FUN_00462fe0();
            FUN_00550e90();
            FUN_00551490();
          }
          FUN_0046d810();
          FUN_004798e0();
        }
      }
      else if (param_1 == 0x2afa) {
        DAT_00b19824 = (uint)(DAT_00b19824 == 0);
        goto switchD_00462312_caseD_2c38;
      }
      goto switchD_00461ea0_default;
    }
    switch(param_1) {
    case 0x2c25:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfcffffff;
      break;
    case 0x2c26:
      uVar11 = (&DAT_00b197e8)[DAT_00b19804] & 0xfdffffff | 0x1000000;
      goto LAB_00462463;
    case 0x2c27:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfeffffff | 0x2000000;
      break;
    default:
      goto switchD_00461ea0_default;
    case 0x2c2e:
      _DAT_008758e0 = 0;
      _DAT_00b19838 = _DAT_008758e0;
      goto LAB_0046236c;
    case 0x2c2f:
      _DAT_00b19838 = 0x3ff0000000000000;
      _DAT_008758e0 = 0;
      FUN_00551490();
      goto switchD_00461ea0_default;
    case 0x2c30:
      _DAT_00b19838 = 0x3ff8000000000000;
      _DAT_008758e0 = 0xbfd0000000000000;
      FUN_00551490();
      goto switchD_00461ea0_default;
    case 0x2c31:
      _DAT_008758e0 = 0x3fd5555555555555;
      _DAT_00b19838 = _DAT_008758e0;
      goto LAB_0046236c;
    case 0x2c32:
      _DAT_00b19838 = 0;
      _DAT_008758e0 = 0x3fe0000000000000;
      FUN_00551490();
      goto switchD_00461ea0_default;
    case 0x2c33:
      _DAT_00b19838 = 0;
      _DAT_008758e0 = 0x3ff0000000000000;
      FUN_00551490();
      goto switchD_00461ea0_default;
    case 0x2c38:
      break;
    case 0x2c39:
      goto switchD_00462312_caseD_2c39;
    case 0x2c3a:
      uVar11 = (&DAT_00b197e8)[DAT_00b19804] & 0x8fffffff | 0x300;
      goto LAB_00462463;
    case 0x2c3b:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0x9fffffff | 0x10000300;
      break;
    case 0x2c3c:
      uVar11 = (&DAT_00b197e8)[DAT_00b19804] & 0xafffffff | 0x20000300;
      goto LAB_00462463;
    case 0x2c3d:
      (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xbfffffff | 0x30000300;
      break;
    case 0x2c3e:
      uVar11 = (&DAT_00b197e8)[DAT_00b19804] & 0xcffffcff | 0x40000000;
LAB_00462463:
      (&DAT_00b197e8)[DAT_00b19804] = uVar11;
    }
    goto switchD_00462312_caseD_2c38;
  default:
    goto switchD_00461ea0_default;
  }
  switch(param_1) {
  case 0x2af9:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xffeeffff;
    goto switchD_00462312_caseD_2c38;
  case 0x2afa:
    DAT_00b19824 = (uint)(DAT_00b19824 == 0);
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfffeffff;
    goto switchD_00462312_caseD_2c38;
  case 0x2b5d:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xf40200ff;
    DAT_008758b4 = 0;
    DAT_00b19824 = 0;
    goto switchD_00462312_caseD_2c38;
  case 0x2b5e:
    DAT_008758b4 = (uint)(DAT_008758b4 == 0);
    goto LAB_004621ee;
  case 0x2b5f:
    DAT_00b19828 = (uint)(DAT_00b19828 == 0);
    break;
  case 0x2b60:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xffefffff | 0x10000;
    DAT_00b19824 = 0;
    FUN_00462fe0();
    FUN_00550e90();
    if (DAT_00b19824 != 0) {
      FUN_00462fe0();
      goto LAB_004621e9;
    }
    goto LAB_004621ee;
  case 0x2b61:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfffeffff | 0x100000;
    goto switchD_00462312_caseD_2c38;
  case 0x2b62:
    goto switchD_00461f45_caseD_2b62;
  case 0x2b63:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] ^ 0x1000000;
    goto switchD_00462312_caseD_2c38;
  case 0x2b64:
    (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] ^ 0x2000000 | 0x1000000;
switchD_00462312_caseD_2c38:
    PostMessageA((HWND)0x0,0x8000,0,0);
    break;
  case 0x2b65:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0055f450();
      if (DAT_00b19824 == 0) {
        DAT_00b19824 = 1;
        FUN_00462fe0();
        FUN_00550e90();
        FUN_00551490();
      }
      if (((&DAT_00b197e8)[DAT_00b19804] & 0x10000) != 0) {
        (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfffeffff;
        FUN_00462fe0();
        FUN_00550e90();
        FUN_00551490();
      }
      FUN_0046d810();
      FUN_004798e0();
    }
    break;
  case 0x2b66:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0055f450();
      FUN_0046dd30();
      DAT_00b19828 = 1;
    }
    break;
  case 0x2b67:
    if (DAT_00b19814 == 0) {
      FUN_00560270();
      FUN_0055f450();
      if (((&DAT_00b197e8)[DAT_00b19804] & 0x100000) == 0) {
        (&DAT_00b197e8)[DAT_00b19804] = (&DAT_00b197e8)[DAT_00b19804] & 0xfffeffff | 0x100000;
        FUN_00462fe0();
        FUN_00550e90();
        FUN_00551490();
      }
      FUN_0046e350();
      if (DAT_00ad74cc == 0) {
        FUN_004798e0();
      }
    }
    break;
  case 0x2b71:
    uVar11 = (&DAT_00b197e8)[DAT_00b19804] & 0xfeffffff | 0x30000;
    goto LAB_00462034;
  case 0x2b72:
  case 0x2b73:
  case 0x2b74:
  case 0x2b75:
  case 0x2b76:
  case 0x2b77:
  case 0x2b78:
  case 0x2b79:
  case 0x2b7a:
  case 0x2b7b:
  case 0x2b7c:
  case 0x2b7d:
  case 0x2b7e:
  case 0x2b7f:
  case 0x2b80:
  case 0x2b8b:
    uVar11 = param_1 + 0xd496U | (&DAT_00b197e8)[DAT_00b19804] & 0xffecff00;
LAB_00462034:
    (&DAT_00b197e8)[DAT_00b19804] = uVar11;
    PostMessageA((HWND)0x0,0x8000,0,0);
    goto LAB_004621ee;
  case 0x2b85:
    DAT_008758d0 = (uint)(DAT_008758d0 == 0);
    goto LAB_004621e9;
  case 0x2b86:
    DAT_008758d4 = (uint)(DAT_008758d4 == 0);
LAB_004621e9:
    FUN_00550e90();
LAB_004621ee:
    if (DAT_00b189ce != '\0') {
      if (DAT_00ad74cc == 0) {
        if (DAT_00ad74c4 == 0) {
          FUN_00551490();
        }
      }
      else {
LAB_0046236c:
        FUN_00551490();
      }
    }
    break;
  case 0x2bc1:
  case 0x2bc2:
  case 0x2bc3:
  case 0x2bc4:
  case 0x2bc5:
  case 0x2bc6:
  case 0x2bc7:
  case 0x2bc8:
  case 0x2bc9:
  case 0x2bca:
    uVar11 = param_1 * 0x10000000 + 0xf3000000U | (&DAT_00b197e8)[DAT_00b19804] & 0xfffffff;
    goto LAB_00462463;
  }
switchD_00461ea0_default:
  pHVar1 = DAT_00ad6f40;
  if (DAT_00ad7510 != (HWND)0x0) {
    if (param_2 == 0x200) {
      SetFocus(DAT_00ad7510);
    }
    else if (param_2 == 0x300) {
      DAT_00b189db = 1;
      SendMessageA(DAT_00ad7510,0xd,0x81,0xb19e08);
    }
    else if (param_2 == 0x501) {
      if ((DAT_00b181e9 == '\0') || (*(int *)(DAT_00b1820c + 0x1334) == 0)) {
        pHVar6 = FindResourceA(DAT_00ad6f40,(LPCSTR)0x27,(LPCSTR)0x6);
        pvVar7 = LoadResource(pHVar1,pHVar6);
        pWVar8 = LockResource(pvVar7);
        pWVar10 = (LPCWSTR)0x0;
        if (pWVar8 != (LPCWSTR)0x0) {
          iVar9 = 6;
          pWVar10 = pWVar8;
          do {
            iVar9 = iVar9 + -1;
            pWVar10 = pWVar10 + (ushort)*pWVar10 + 1;
          } while (iVar9 != 0);
        }
        pWVar8 = pWVar10 + 1;
        if (*pWVar10 == L'\0') {
          pWVar8 = pWVar10;
        }
        iVar9 = WideCharToMultiByte(0,0,pWVar8,(uint)(ushort)*pWVar10,&DAT_00b1b920,0x1400,
                                    (LPCSTR)0x0,(LPBOOL)0x0);
        if (iVar9 != 0) {
          (&DAT_00b1b920)[(ushort)*pWVar10] = 0;
          FUN_005553d0(0,5);
          goto LAB_00462577;
        }
      }
      FUN_005553d0(0,5);
    }
  }
LAB_00462577:
  FUN_00464a90();
LAB_0046257c:
  __security_check_cookie(local_8 ^ (uint)&local_314);
  return;
}
