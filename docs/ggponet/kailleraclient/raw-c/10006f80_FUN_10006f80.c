
/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_10006f80(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  DWORD DVar3;
  char *pcVar4;
  int iVar5;
  WPARAM WVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  undefined4 *unaff_FS_OFFSET;
  bool bVar15;
  bool bVar16;
  undefined4 uVar17;
  undefined4 *local_4c0;
  int local_4bc [2];
  char local_4b4 [16];
  undefined4 local_4a4;
  undefined4 local_488;
  uint local_484;
  uint local_480;
  undefined4 local_468;
  undefined4 local_464;
  uint local_460;
  uint local_45c;
  int local_458;
  undefined1 local_454 [44];
  uint local_428;
  int local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  int local_3f4;
  int local_3f0 [5];
  undefined4 local_3dc;
  undefined4 local_3c0;
  uint local_3bc;
  uint local_3b8;
  uint local_3b4;
  int local_370;
  byte local_36c [44];
  char local_340 [128];
  uint local_2c0 [32];
  undefined4 local_240;
  int local_23c [12];
  CHAR local_20c [512];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1000cbee;
  *unaff_FS_OFFSET = &local_c;
  switch(*param_1) {
  case 1:
    FUN_10001c80(&local_370,param_1);
    local_4 = 7;
    local_2c0[0] = FUN_10001f40(&local_370);
    local_2c0[0] = local_2c0[0] & 0xffff;
    FUN_10001e60(&local_370,local_340,0x80);
    local_4 = 8;
    if (DAT_1000ef8c != 0) {
      wsprintfA(local_20c,s____s_left_the_partyline___s___1000e728,param_1 + 1,local_340);
      DAT_1000f1a4 = DAT_1000e504;
      iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
      WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
      SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
      local_3f0[0] = 0x54;
      local_3f0[1] = 0x40000000;
      local_3f0[2] = 0;
      local_3dc = DAT_1000f1a4;
      SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)local_3f0);
      SendMessageA(DAT_1000f1a0,0xc2,0,(LPARAM)local_20c);
      GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
      SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
    }
    FUN_100082b0(local_2c0[0]);
    FUN_10006e20();
    local_4 = 0xffffffff;
    piVar12 = &local_370;
    break;
  case 2:
    FUN_10001c80(local_4bc + 1,param_1);
    local_4 = 5;
    local_488 = FUN_10001f40(local_4bc + 1);
    local_488 = local_488 & 0xffff;
    local_484 = FUN_10001ee0(local_4bc + 1);
    local_480 = FUN_10001f10(local_4bc + 1);
    local_480 = local_480 & 0xff;
    local_4 = 6;
    if (DAT_1000e4f8 == 0xffffffff) {
      DAT_1000e4f8 = local_488;
    }
    FUN_10008200(local_4b4,local_484,1,local_488,local_480);
    FUN_10006e20();
    if (DAT_1000ef8c != 0) {
      wsprintfA(local_20c,s____s_joined_the_partyline__1000e748,local_4b4);
      DAT_1000f1a4 = DAT_1000e504;
      iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
      WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
      SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
      local_3f0[0] = 0x54;
      local_3f0[1] = 0x40000000;
      local_3f0[2] = 0;
      local_3dc = DAT_1000f1a4;
      SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)local_3f0);
      SendMessageA(DAT_1000f1a0,0xc2,0,(LPARAM)local_20c);
      GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
      SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
    }
    local_4 = 0xffffffff;
    piVar12 = local_4bc + 1;
    break;
  default:
    goto switchD_10006fb2_caseD_3;
  case 4:
    FUN_10001c80(local_4bc + 1,param_1);
    local_4 = 9;
    local_488 = FUN_10001ee0(local_4bc + 1);
    local_484 = FUN_10001ee0(local_4bc + 1);
    iVar5 = 0;
    local_4 = 10;
    if (0 < (int)local_488) {
      do {
        FUN_10001e60(local_4bc + 1,(char *)&local_424,0x1f);
        uVar9 = FUN_10001ee0(local_4bc + 1);
        uVar11 = FUN_10001f10(local_4bc + 1);
        uVar10 = FUN_10001f40(local_4bc + 1);
        uVar7 = FUN_10001f10(local_4bc + 1);
        FUN_10008200((char *)&local_424,uVar9,uVar11 & 0xff,uVar10 & 0xffff,uVar7 & 0xff);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)local_488);
    }
    iVar5 = 0;
    if (0 < (int)local_484) {
      do {
        FUN_10001e60(local_4bc + 1,(char *)&local_370,0x7f);
        uVar9 = FUN_10001ee0(local_4bc + 1);
        FUN_10001e60(local_4bc + 1,(char *)local_3f0,0x7f);
        FUN_10001e60(local_4bc + 1,(char *)&local_458,0x1f);
        FUN_10001e60(local_4bc + 1,(char *)&local_424,9);
        uVar11 = FUN_10001f10(local_4bc + 1);
        uVar11 = uVar11 & 0xff;
        uVar17 = 2;
        iVar2 = atoi((char *)&local_424);
        FUN_100084b0((char *)&local_370,uVar9,(char *)local_3f0,(char *)&local_458,iVar2,uVar17,
                     uVar11);
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)local_484);
    }
    local_4 = 0xffffffff;
    piVar12 = local_4bc + 1;
    break;
  case 5:
    FUN_10001c40(local_23c);
    iVar5 = 0;
    local_23c[0] = 6;
    local_4 = 0;
    do {
      FUN_10001ed0(local_23c);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 4);
    local_4 = 1;
    FUN_100010d0();
    local_4 = 0xffffffff;
    piVar12 = local_23c;
    break;
  case 7:
    FUN_10001c80(&local_370,param_1);
    local_4 = 2;
    FUN_10001e60(&local_370,local_340,0x80);
    local_4 = 0xffffffff;
    if (DAT_1000eef4 == 0) {
LAB_100072f4:
      DAT_1000f1a4 = DAT_1000f1f0;
      wsprintfA(local_20c,s_<_s>__s_1000e770,local_36c,local_340);
      iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
      WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
      SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
      local_3f0[0] = 0x54;
      local_3f0[1] = 0x40000000;
      local_3f0[2] = 0;
      local_3dc = DAT_1000f1a4;
      SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)local_3f0);
      SendMessageA(DAT_1000f1a0,0xc2,0,(LPARAM)local_20c);
      GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
      SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
    }
    else {
      pbVar13 = &DAT_1000edc8;
      pbVar8 = local_36c;
      do {
        bVar1 = *pbVar8;
        bVar16 = bVar1 < *pbVar13;
        if (bVar1 != *pbVar13) {
LAB_1000709e:
          iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
          goto LAB_100070a3;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar16 = bVar1 < pbVar13[1];
        if (bVar1 != pbVar13[1]) goto LAB_1000709e;
        pbVar8 = pbVar8 + 2;
        pbVar13 = pbVar13 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_100070a3:
      if (iVar5 == 0) goto LAB_100072f4;
      bVar16 = false;
      local_4c0 = DAT_1000f128;
      iVar5 = 0;
      puVar14 = DAT_1000f128;
      do {
        if ((int)DAT_1000f12c <= iVar5) {
          if (!bVar16) {
            puVar14 = malloc(0x10);
            pcVar4 = _strdup((char *)local_36c);
            *puVar14 = pcVar4;
            puVar14[1] = 1;
            DVar3 = GetTickCount();
            puVar14[2] = DVar3;
            puVar14[3] = 0;
            if ((DAT_1000f128 == (undefined4 *)0x0) || ((DAT_1000f12c & 0x1f) == 0)) {
              DAT_1000f128 = realloc(DAT_1000f128,DAT_1000f12c * 4 + 0x80);
            }
            DAT_1000f128[DAT_1000f12c] = puVar14;
            DAT_1000f12c = DAT_1000f12c + 1;
            goto LAB_100072f4;
          }
          break;
        }
        if ((iVar5 < 0) || ((int)DAT_1000f12c <= iVar5)) {
          puVar14 = (undefined4 *)0x0;
        }
        else {
          puVar14 = (undefined4 *)*local_4c0;
        }
        pbVar13 = (byte *)*puVar14;
        pbVar8 = local_36c;
        do {
          bVar1 = *pbVar8;
          bVar15 = bVar1 < *pbVar13;
          if (bVar1 != *pbVar13) {
LAB_10007110:
            iVar2 = (1 - (uint)bVar15) - (uint)(bVar15 != 0);
            goto LAB_10007115;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar15 = bVar1 < pbVar13[1];
          if (bVar1 != pbVar13[1]) goto LAB_10007110;
          pbVar8 = pbVar8 + 2;
          pbVar13 = pbVar13 + 2;
        } while (bVar1 != 0);
        iVar2 = 0;
LAB_10007115:
        if (iVar2 == 0) {
          bVar16 = true;
        }
        iVar5 = iVar5 + 1;
        local_4c0 = local_4c0 + 1;
      } while (!bVar16);
      if (puVar14[3] == 0) {
        puVar14[1] = puVar14[1] + 1;
        DVar3 = GetTickCount();
        if ((uint)(puVar14[2] + DAT_1000eef8 * 1000) < DVar3) {
          puVar14[1] = 1;
          DVar3 = GetTickCount();
          puVar14[2] = DVar3;
        }
        if (DAT_1000eee8 <= (int)puVar14[1]) {
          puVar14[3] = 1;
          wsprintfA(local_20c,s___Ignoring__s__flood__1000e77c,local_36c);
          DAT_1000f1a4 = DAT_1000e508;
          iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
          WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
          SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
          local_3f0[0] = 0x54;
          local_3f0[1] = 0x40000000;
          local_3f0[2] = 0;
          local_3dc = DAT_1000f1a4;
          SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)local_3f0);
          SendMessageA(DAT_1000f1a0,0xc2,0,(LPARAM)local_20c);
          GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
          SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
          piVar12 = &local_370;
          break;
        }
        goto LAB_100072f4;
      }
    }
    piVar12 = &local_370;
    break;
  case 8:
    FUN_10001c80(&local_370,param_1);
    local_4 = 3;
    FUN_10001e60(&local_370,local_340,0x80);
    local_4 = 0xffffffff;
    wsprintfA(local_20c,s_<_s>__s_1000e770,local_36c,local_340);
    iVar5 = GetWindowTextLengthA(DAT_1000f14c);
    WVar6 = GetWindowTextLengthA(DAT_1000f14c);
    SendMessageA(DAT_1000f14c,0xb1,WVar6,iVar5);
    SendMessageA(DAT_1000f14c,0xc2,0,(LPARAM)local_20c);
    piVar12 = &local_370;
    break;
  case 10:
    FUN_10001c80(&local_370,param_1);
    local_4 = 0xb;
    FUN_10001e60(&local_370,local_340,0x80);
    FUN_10001e60(&local_370,(char *)local_2c0,0x80);
    local_240 = FUN_10001ee0(&local_370);
    local_4 = 0xc;
    FUN_100084b0(local_340,local_240,(char *)local_2c0,(char *)local_36c,1,2,0);
    local_4 = 0xffffffff;
    piVar12 = &local_370;
    break;
  case 0xb:
    if (DAT_1000e4f4 == 0xffffffff) goto switchD_10006fb2_caseD_3;
    FUN_10001c80(&local_458,param_1);
    local_4 = 0x13;
    local_428 = FUN_10001f40(&local_458);
    local_428 = local_428 & 0xffff;
    local_4 = 0x14;
    if (local_428 == DAT_1000e4f8) {
      DAT_1000f1a4 = DAT_1000e508;
      iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
      WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
      SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
      local_3f0[0] = 0x54;
      local_3f0[1] = 0x40000000;
      local_3f0[2] = 0;
      local_3dc = DAT_1000f1a4;
      SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)local_3f0);
      SendMessageA(DAT_1000f1a0,0xc2,0,0x1000e698);
      GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
      SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
      EndDialog(DAT_1000f1d4,0);
      FUN_10008570(1);
      DAT_1000e4f4 = 0xffffffff;
      local_4 = 0xffffffff;
      piVar12 = &local_458;
    }
    else {
      wsprintfA(local_20c,s____s_left_the_game_s_partyline__1000e674,param_1 + 1);
      iVar5 = GetWindowTextLengthA(DAT_1000f14c);
      WVar6 = GetWindowTextLengthA(DAT_1000f14c);
      SendMessageA(DAT_1000f14c,0xb1,WVar6,iVar5);
      SendMessageA(DAT_1000f14c,0xc2,0,(LPARAM)local_20c);
      FUN_10008390(local_428);
      local_4 = 0xffffffff;
      piVar12 = &local_458;
    }
    break;
  case 0xc:
    FUN_10001c80(local_4bc + 1,param_1);
    local_4 = 0xd;
    local_468 = FUN_10001ee0(local_4bc + 1);
    FUN_10001e60(local_4bc + 1,(char *)&local_488,0x20);
    local_464 = FUN_10001ee0(local_4bc + 1);
    local_460 = FUN_10001f40(local_4bc + 1);
    local_460 = local_460 & 0xffff;
    local_45c = FUN_10001f10(local_4bc + 1);
    local_45c = local_45c & 0xff;
    local_4 = 0xe;
    FUN_10008320((char *)&local_488,local_464,local_460,local_45c);
    wsprintfA(local_20c,s____s_joined_the_game_s_partyline_1000e704,&local_488);
    iVar5 = GetWindowTextLengthA(DAT_1000f14c);
    WVar6 = GetWindowTextLengthA(DAT_1000f14c);
    SendMessageA(DAT_1000f14c,0xb1,WVar6,iVar5);
    SendMessageA(DAT_1000f14c,0xc2,0,(LPARAM)local_20c);
    pbVar13 = &DAT_1000edc8;
    pbVar8 = (byte *)&local_488;
    do {
      bVar1 = *pbVar8;
      bVar16 = bVar1 < *pbVar13;
      if (bVar1 != *pbVar13) {
LAB_10007bfd:
        iVar5 = (1 - (uint)bVar16) - (uint)(bVar16 != 0);
        goto LAB_10007c02;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar8[1];
      bVar16 = bVar1 < pbVar13[1];
      if (bVar1 != pbVar13[1]) goto LAB_10007bfd;
      pbVar8 = pbVar8 + 2;
      pbVar13 = pbVar13 + 2;
    } while (bVar1 != 0);
    iVar5 = 0;
LAB_10007c02:
    if (iVar5 != 0) {
      if (DAT_1000ef80 != 0) {
        PlaySoundA(s_join_wav_1000e6f8,(HMODULE)0x0,0x20000);
      }
      if (DAT_1000eef0 != (code *)0x0) {
        local_424 = 0x14;
        local_420 = DAT_1000f09c;
        local_41c = 0xe;
        local_418 = 999;
        local_414 = 0;
        (*DAT_1000eef0)(&local_424);
      }
    }
    local_4 = 0xffffffff;
    piVar12 = local_4bc + 1;
    break;
  case 0xd:
    FUN_10001c80(&local_424,param_1);
    local_4 = 0xf;
    local_3f4 = FUN_10001ee0(&local_424);
    iVar5 = 0;
    local_4 = 0x10;
    if (0 < local_3f4) {
      do {
        FUN_10001e60(&local_424,(char *)&local_458,0x1f);
        uVar9 = FUN_10001ee0(&local_424);
        uVar11 = FUN_10001f40(&local_424);
        uVar10 = FUN_10001f10(&local_424);
        FUN_10008320((char *)&local_458,uVar9,uVar11 & 0xffff,uVar10 & 0xff);
        iVar5 = iVar5 + 1;
      } while (iVar5 < local_3f4);
    }
    local_4 = 0xffffffff;
    piVar12 = &local_424;
    break;
  case 0xe:
    FUN_10001c80(local_3f0,param_1);
    local_4 = 0x18;
    local_3c0 = FUN_10001ee0(local_3f0);
    local_3bc = FUN_10001f10(local_3f0);
    local_3bc = local_3bc & 0xff;
    local_3b8 = FUN_10001f10(local_3f0);
    local_3b8 = local_3b8 & 0xff;
    local_3b4 = FUN_10001f10(local_3f0);
    local_3b4 = local_3b4 & 0xff;
    local_4 = 0x19;
    FUN_10008400(local_3c0,local_3bc,local_3b8,local_3b4);
    local_4 = 0xffffffff;
    piVar12 = local_3f0;
    break;
  case 0x10:
    FUN_10001c80(&local_458,param_1);
    local_4 = 0x15;
    local_428 = FUN_10001ee0(&local_458);
    local_4 = 0x16;
    FUN_10008510(local_428);
    if (local_428 == DAT_1000e4f4) {
      EndDialog(DAT_1000f1d4,0);
      FUN_10008570(1);
      DAT_1000e4f4 = 0xffffffff;
    }
    local_4 = 0xffffffff;
    piVar12 = &local_458;
    break;
  case 0x11:
    FUN_10001c80(local_4bc + 1,param_1);
    local_4 = 0x17;
    local_488 = FUN_10001f40(local_4bc + 1);
    local_488 = local_488 & 0xffff;
    local_484 = FUN_10001f10(local_4bc + 1);
    local_484 = local_484 & 0xff;
    uVar11 = FUN_10001f10(local_4bc + 1);
    DAT_1000f1e0 = local_488;
    DAT_1000f1b8 = uVar11 & 0xff;
    local_4 = 0xffffffff;
    DAT_1000e4fc = local_484;
    local_480 = DAT_1000f1b8;
    PostMessageA(DAT_1000f120,0x523,0,0);
    piVar12 = local_4bc + 1;
    break;
  case 0x14:
    FUN_10001c80(&local_458,param_1);
    local_4 = 0x11;
    local_428 = FUN_10001f10(&local_458);
    local_428 = local_428 & 0xff;
    local_4 = 0x12;
    wsprintfA(local_20c,s___Player__i___s__dropped_from_th_1000e6c4,local_428,local_454);
    iVar5 = GetWindowTextLengthA(DAT_1000f14c);
    WVar6 = GetWindowTextLengthA(DAT_1000f14c);
    SendMessageA(DAT_1000f14c,0xb1,WVar6,iVar5);
    SendMessageA(DAT_1000f14c,0xc2,0,(LPARAM)local_20c);
    if ((DAT_1000f1dc != 0) && (DAT_1000edc4 != (code *)0x0)) {
      (*DAT_1000edc4)(local_454,local_428);
    }
    local_4 = 0xffffffff;
    piVar12 = &local_458;
    break;
  case 0x17:
    FUN_10001c80(&local_370,param_1);
    local_4 = 4;
    FUN_10001e60(&local_370,local_340,0x80);
    local_4 = 0xffffffff;
    DAT_1000f1a4 = DAT_1000e50c;
    wsprintfA(local_20c,s____s_1000e768,local_340);
    iVar5 = GetWindowTextLengthA(DAT_1000f1a0);
    WVar6 = GetWindowTextLengthA(DAT_1000f1a0);
    SendMessageA(DAT_1000f1a0,0xb1,WVar6,iVar5);
    local_4bc[1] = 0x54;
    local_4b4[0] = '\0';
    local_4b4[1] = '\0';
    local_4b4[2] = '\0';
    local_4b4[3] = '@';
    local_4b4[4] = '\0';
    local_4b4[5] = '\0';
    local_4b4[6] = '\0';
    local_4b4[7] = '\0';
    local_4a4 = DAT_1000f1a4;
    SendMessageA(DAT_1000f1a0,0x444,1,(LPARAM)(local_4bc + 1));
    SendMessageA(DAT_1000f1a0,0xc2,0,(LPARAM)local_20c);
    GetScrollRange(DAT_1000f1a0,1,local_4bc,(LPINT)&local_4c0);
    SendMessageA(DAT_1000f1a0,0x115,(int)local_4c0 * 0x10000 + 4,0);
    piVar12 = &local_370;
  }
  FUN_10001c70((int)piVar12);
switchD_10006fb2_caseD_3:
  *unaff_FS_OFFSET = local_c;
  return;
}
