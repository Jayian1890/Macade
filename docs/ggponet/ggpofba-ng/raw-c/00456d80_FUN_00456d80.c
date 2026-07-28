
void FUN_00456d80(void)

{
  char cVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  BOOL BVar5;
  char *pcVar6;
  byte *pbVar7;
  char *pcVar8;
  char *pcVar9;
  uint uVar10;
  bool bVar11;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  byte abStack_199 [265];
  byte local_90 [140];
  uint local_4;
  
  local_4 = DAT_00871720 ^ (uint)&local_1a8;
  local_1a0 = 0;
  local_1a4 = 0;
  local_1a8 = 0;
  local_90[0] = 0;
  _memset(local_90 + 1,0,0x80);
  pcVar9 = &DAT_00ad6f48;
  if (DAT_00ad6f48 == '\"') {
    do {
      pcVar6 = pcVar9;
      pcVar9 = pcVar6 + 1;
    } while (*pcVar6 != '\0');
    cVar1 = DAT_00ad6f49;
    for (pcVar8 = (char *)0x1; (cVar1 != '\"' && ((int)pcVar8 < (int)(pcVar6 + -0xad6f48)));
        pcVar8 = pcVar8 + 1) {
      cVar1 = pcVar8[0xad6f49];
    }
    if (pcVar8 == pcVar6 + -0xad6f48) {
      abStack_199[1] = 0;
      pcVar9 = pcVar8;
    }
    else {
      pcVar9 = pcVar8 + 1;
      _strncpy((char *)(abStack_199 + 1),&DAT_00ad6f49,(size_t)(pcVar8 + -1));
      (&stack0xfffffe66)[(int)pcVar9] = 0;
    }
  }
  else {
    do {
      pcVar6 = pcVar9;
      pcVar9 = pcVar6 + 1;
    } while (*pcVar6 != '\0');
    cVar1 = DAT_00ad6f48;
    for (pcVar9 = (char *)0x0; (cVar1 != ' ' && ((int)pcVar9 < (int)(pcVar6 + -0xad6f48)));
        pcVar9 = pcVar9 + 1) {
      cVar1 = pcVar9[0xad6f49];
    }
    _strncpy((char *)(abStack_199 + 1),&DAT_00ad6f48,(size_t)pcVar9);
    (abStack_199 + 1)[(int)pcVar9] = 0;
  }
  pbVar3 = abStack_199 + 1;
  do {
    bVar2 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar2 != 0);
  if (pbVar3 != abStack_199 + 2) {
    pcVar6 = "-listinfo";
    pbVar3 = abStack_199 + 1;
    do {
      bVar2 = *pbVar3;
      bVar11 = bVar2 < (byte)*pcVar6;
      if (bVar2 != *pcVar6) {
LAB_00456eb4:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00456eb9;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar11 = bVar2 < (byte)pcVar6[1];
      if (bVar2 != pcVar6[1]) goto LAB_00456eb4;
      pbVar3 = pbVar3 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00456eb9:
    if (iVar4 == 0) {
      iVar4 = FUN_007791dc();
      FUN_00475d80(0,iVar4 + 0x20);
      __security_check_cookie(local_4 ^ (uint)&local_1a8);
      return;
    }
  }
  FID_conflict__sscanf
            (pcVar9 + 0xad6f48,"%128s %i x %i x %i",local_90,&local_1a0,&local_1a4,&local_1a8);
  pbVar3 = abStack_199 + 1;
  do {
    bVar2 = *pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (bVar2 != 0);
  if (pbVar3 == abStack_199 + 2) goto LAB_00457186;
  DAT_00ad735c = 1;
  pbVar7 = &DAT_007f824c;
  pbVar3 = local_90;
  do {
    bVar2 = *pbVar3;
    bVar11 = bVar2 < *pbVar7;
    if (bVar2 != *pbVar7) {
LAB_00456f61:
      iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_00456f66;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar3[1];
    bVar11 = bVar2 < pbVar7[1];
    if (bVar2 != pbVar7[1]) goto LAB_00456f61;
    pbVar3 = pbVar3 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar2 != 0);
  iVar4 = 0;
LAB_00456f66:
  if (iVar4 == 0) {
    if ((local_1a0 != 0) && (local_1a4 != 0)) {
      DAT_0087581c = local_1a0;
      DAT_008758a8 = local_1a4;
    }
    if (local_1a8 != 0) {
      DAT_008758ac = local_1a8;
    }
LAB_00456f92:
    DAT_00b19814 = 1;
  }
  else {
    pbVar7 = &DAT_007f8250;
    pbVar3 = local_90;
    do {
      bVar2 = *pbVar3;
      bVar11 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_00457010:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00457015;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar11 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00457010;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00457015:
    if (iVar4 == 0) {
      DAT_00b19830 = 1;
      goto LAB_00456f92;
    }
    pbVar7 = &DAT_007f8254;
    pbVar3 = local_90;
    do {
      bVar2 = *pbVar3;
      bVar11 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_00457050:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00457055;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar11 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00457050;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00457055:
    if (iVar4 == 0) {
      DAT_00ad735c = 0;
    }
    else {
      iVar4 = _strncmp((char *)local_90,"-e",2);
      if (iVar4 != 0) goto LAB_00456f92;
      DAT_00ad735c = 0;
      DAT_00b189cf = 1;
      DAT_00b19810 = (HWND)_strtol((char *)(local_90 + 2),(char **)0x0,0x10);
      BVar5 = IsWindow(DAT_00b19810);
      if (BVar5 == 0) {
        DAT_00b19810 = (HWND)0x0;
      }
    }
  }
  pbVar3 = abStack_199;
  do {
    pbVar3 = pbVar3 + 1;
  } while (*pbVar3 != 0);
  pbVar7 = &DAT_007f825c;
  pbVar3 = pbVar3 + -3;
  do {
    bVar2 = *pbVar3;
    bVar11 = bVar2 < *pbVar7;
    if (bVar2 != *pbVar7) {
LAB_004570be:
      iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
      goto LAB_004570c3;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar3[1];
    bVar11 = bVar2 < pbVar7[1];
    if (bVar2 != pbVar7[1]) goto LAB_004570be;
    pbVar3 = pbVar3 + 2;
    pbVar7 = pbVar7 + 2;
  } while (bVar2 != 0);
  iVar4 = 0;
LAB_004570c3:
  if (iVar4 == 0) {
    iVar4 = FUN_00474e10(1);
    if (iVar4 != 0) {
      __security_check_cookie(local_4 ^ (uint)&local_1a8);
      return;
    }
  }
  else {
    pbVar3 = abStack_199;
    do {
      pbVar3 = pbVar3 + 1;
    } while (*pbVar3 != 0);
    pbVar7 = &DAT_007f8260;
    pbVar3 = pbVar3 + -3;
    do {
      bVar2 = *pbVar3;
      bVar11 = bVar2 < *pbVar7;
      if (bVar2 != *pbVar7) {
LAB_00457134:
        iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_00457139;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar3[1];
      bVar11 = bVar2 < pbVar7[1];
      if (bVar2 != pbVar7[1]) goto LAB_00457134;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar2 != 0);
    iVar4 = 0;
LAB_00457139:
    if (iVar4 == 0) {
      iVar4 = FUN_004665d0(abStack_199 + 1);
      if (iVar4 != 0) {
        __security_check_cookie(local_4 ^ (uint)&local_1a8);
        return;
      }
    }
    else {
      iVar4 = _strncmp((char *)(abStack_199 + 1),"quark:",6);
      if (iVar4 == 0) {
        FUN_0062dc50();
      }
      else {
        uVar10 = 0;
        bVar11 = DAT_00b196f8 == 0;
        if (DAT_00b196f8 != 0) {
          do {
            pbVar3 = abStack_199 + 1;
            DAT_00877258 = uVar10;
            pbVar7 = (byte *)FUN_0052d560(0);
            do {
              bVar2 = *pbVar7;
              bVar11 = bVar2 < *pbVar3;
              if (bVar2 != *pbVar3) {
LAB_00457201:
                iVar4 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
                goto LAB_00457206;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar7[1];
              bVar11 = bVar2 < pbVar3[1];
              if (bVar2 != pbVar3[1]) goto LAB_00457201;
              pbVar7 = pbVar7 + 2;
              pbVar3 = pbVar3 + 2;
            } while (bVar2 != 0);
            iVar4 = 0;
LAB_00457206:
            if (iVar4 == 0) {
              FUN_0045cc40();
              FUN_0045cf70(uVar10,1);
              break;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < DAT_00b196f8);
          bVar11 = uVar10 == DAT_00b196f8;
        }
        if (bVar11) {
          FUN_0045f2f0(0x10000,800,abStack_199 + 1,"FB Alpha");
          FUN_0045f500();
          __security_check_cookie(local_4 ^ (uint)&local_1a8);
          return;
        }
      }
    }
  }
LAB_00457186:
  PostMessageA((HWND)0x0,0x8000,0,0);
  if (DAT_00b19814 == 0) {
    FUN_00465610();
  }
  __security_check_cookie(local_4 ^ (uint)&local_1a8);
  return;
}
