
undefined4 FUN_10005000(void)

{
  char cVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar9;
  undefined4 local_2f8;
  undefined4 *local_2f4;
  int aiStack_2f0 [12];
  tagMSG tStack_2c0;
  undefined4 auStack_2a4 [9];
  CHAR aCStack_280 [12];
  undefined4 auStack_274 [45];
  undefined1 auStack_1c0 [48];
  char acStack_190 [128];
  uint uStack_110;
  char local_10c [9];
  char acStack_103 [247];
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  iVar2 = DAT_1000e24c;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &DAT_1000ca09;
  *unaff_FS_OFFSET = &local_c;
  if (iVar2 == 0) {
    FUN_10005560(s_Connecting____1000e260);
    pcVar9 = &DAT_1000eca8;
    cVar1 = DAT_1000eca8;
    while ((cVar1 != '\0' && (cVar1 != ':'))) {
      pcVar8 = pcVar9 + 1;
      pcVar9 = pcVar9 + 1;
      cVar1 = *pcVar8;
    }
    if (*pcVar9 != ':') goto LAB_1000553f;
    *pcVar9 = '\0';
    local_2f4 = operator_new(0x20);
    local_4 = 0;
    if (local_2f4 == (undefined4 *)0x0) {
      DAT_1000eda8 = (int *)0x0;
    }
    else {
      DAT_1000eda8 = FUN_10002040(local_2f4);
    }
    local_4 = 0xffffffff;
    (**(code **)(*DAT_1000eda8 + 8))(0);
    iVar2 = *DAT_1000eda8;
    iVar4 = atoi(pcVar9 + 1);
    (**(code **)(iVar2 + 0x14))(&DAT_1000eca8,iVar4);
    wsprintfA(aCStack_280,s_HELLO_s_1000e250,&DAT_1000e258);
    uVar6 = 0xffffffff;
    pcVar9 = aCStack_280;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    (**(code **)(*DAT_1000eda8 + 0x1c))(aCStack_280,~uVar6);
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 == 2) {
        local_2f8 = 0x100;
        (**(code **)(*DAT_1000eda8 + 0x20))(local_10c,&local_2f8,0,0);
        iVar2 = strncmp(local_10c,&DAT_1000e2dc,3);
        if (iVar2 == 0) {
          pcVar9 = s_Can_t_connect__Version_mismatch_1000e2bc;
        }
        else {
          iVar2 = strncmp(local_10c,&DAT_1000e2b8,3);
          if (iVar2 != 0) {
            iVar2 = strncmp(local_10c,s_HELLOD00D_1000e28c,9);
            if (iVar2 == 0) {
              FUN_10005560(s_Connected__Logging_in____1000e270);
              uVar6 = 0xffffffff;
              pcVar9 = &DAT_1000eca8;
              do {
                pcVar8 = pcVar9;
                if (uVar6 == 0) break;
                uVar6 = uVar6 - 1;
                pcVar8 = pcVar9 + 1;
                cVar1 = *pcVar9;
                pcVar9 = pcVar8;
              } while (cVar1 != '\0');
              uVar6 = ~uVar6;
              pcVar9 = pcVar8 + -uVar6;
              pcVar8 = (char *)&DAT_1000ef9c;
              for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
                pcVar9 = pcVar9 + 4;
                pcVar8 = pcVar8 + 4;
              }
              for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar8 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                pcVar8 = pcVar8 + 1;
              }
              DAT_1000ef84 = atoi(acStack_103);
              if (DAT_1000eda8 != (int *)0x0) {
                (**(code **)*DAT_1000eda8)(1);
              }
              DAT_1000eda8 = (int *)0x0;
              local_2f4 = operator_new(0x1030);
              local_4 = 1;
              if (local_2f4 == (undefined4 *)0x0) {
                DAT_1000ef88 = (int *)0x0;
              }
              else {
                DAT_1000ef88 = FUN_10001000(local_2f4);
              }
              local_4 = 0xffffffff;
              (**(code **)(*DAT_1000ef88 + 8))(0);
              (**(code **)(*DAT_1000ef88 + 0x14))(&DAT_1000ef9c,DAT_1000ef84);
              pcVar9 = DAT_1000ef98;
              FUN_10001c40(auStack_274);
              local_4 = 2;
              auStack_274[0] = 3;
              FUN_10001e30(auStack_274,pcVar9);
              FUN_10001d30(auStack_274,&DAT_1000edc8);
              FUN_10001f00(auStack_274);
              local_4 = 3;
              FUN_100010d0();
              local_4 = 0xffffffff;
              FUN_10001c70((int)auStack_274);
              KillTimer(DAT_1000eca0,0xdeadc0de);
              while (DAT_1000edac == 0) {
                do {
                  BVar3 = PeekMessageA(&tStack_2c0,(HWND)0x0,0,0,1);
                  if (BVar3 != 0) {
                    TranslateMessage(&tStack_2c0);
                    DispatchMessageA(&tStack_2c0);
                  }
                  if (DAT_1000edac != 0) goto LAB_1000553f;
                } while (DAT_1000ef88 == (int *)0x0);
                FUN_10002560(0,10);
                iVar2 = (**(code **)(*DAT_1000ef88 + 0x24))();
                if (iVar2 != 0) {
                  FUN_10001c40(aiStack_2f0);
                  local_4 = 4;
                  iVar2 = FUN_100012b0();
                  if (iVar2 == 0) {
                    if (aiStack_2f0[0] == 4) {
                      DAT_1000e24c = -1;
                      local_4 = 0xffffffff;
                      FUN_10001c70((int)aiStack_2f0);
                      uVar5 = 1;
                      goto LAB_10005541;
                    }
                    if (aiStack_2f0[0] == 5) {
                      FUN_100012b0();
                      FUN_10001c40(auStack_2a4);
                      local_4._0_1_ = 5;
                      auStack_2a4[0] = 6;
                      iVar2 = 0;
                      do {
                        FUN_10001ed0(auStack_2a4);
                        iVar2 = iVar2 + 1;
                      } while (iVar2 < 4);
                      local_4._0_1_ = 6;
                      FUN_100010d0();
                      local_4 = CONCAT31(local_4._1_3_,4);
                      FUN_10001c70((int)auStack_2a4);
                    }
                    else {
                      if (aiStack_2f0[0] == 0x16) {
                        FUN_10001c80(auStack_1c0,aiStack_2f0);
                        local_4._0_1_ = 7;
                        uStack_110 = FUN_10001f40(auStack_1c0);
                        uStack_110 = uStack_110 & 0xffff;
                        FUN_10001e60(auStack_1c0,acStack_190,0x80);
                        local_4._0_1_ = 8;
                        FUN_10005560(acStack_190);
                        local_4 = CONCAT31(local_4._1_3_,4);
                        FUN_10001c70((int)auStack_1c0);
                        DAT_1000e24c = -1;
                        local_4 = 0xffffffff;
                        FUN_10001c70((int)aiStack_2f0);
                        break;
                      }
                      FUN_100012b0();
                    }
                  }
                  local_4 = 0xffffffff;
                  FUN_10001c70((int)aiStack_2f0);
                }
              }
            }
            else {
              DAT_1000e24c = 1;
            }
            goto LAB_1000553f;
          }
          pcVar9 = s_Can_t_connect__Too_many_users_1000e298;
        }
        FUN_10005560(pcVar9);
        DAT_1000e24c = -1;
      }
      goto LAB_1000553f;
    }
    FUN_10002560(0,0);
    iVar2 = (**(code **)(*DAT_1000eda8 + 0x24))();
    if (iVar2 == 0) goto LAB_1000553f;
  }
  DAT_1000e24c = DAT_1000e24c + 1;
LAB_1000553f:
  uVar5 = 0;
LAB_10005541:
  *unaff_FS_OFFSET = local_c;
  return uVar5;
}
