
/* WARNING: Removing unreachable block (ram,0x100094b1) */
/* WARNING: Removing unreachable block (ram,0x100094c7) */

uint __cdecl FUN_10008f30(char *param_1,uint param_2)

{
  DWORD DVar1;
  int iVar2;
  DWORD DVar3;
  HWND pHVar4;
  undefined4 *puVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  char *pcVar12;
  undefined4 *unaff_FS_OFFSET;
  bool bVar13;
  char *pcVar14;
  char *pcVar15;
  UINT UVar16;
  uint local_55c;
  int local_554 [9];
  char *pcStack_530;
  uint uStack_524;
  int aiStack_520 [12];
  int aiStack_4f0 [12];
  uint uStack_4c0;
  int iStack_4bc;
  undefined1 auStack_4b8 [44];
  char acStack_48c [128];
  char acStack_40c [1024];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1000cd70;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_55c = 0;
  if (DAT_1000f1dc == 0) {
    local_55c = 0xffffffff;
    iVar11 = DAT_1000f1e4;
  }
  else {
    if (DAT_1000f1ec == 0) {
      FUN_10001c40(local_554);
      local_554[0] = 0x15;
      iVar11 = 0;
      local_4 = 0;
      FUN_100010d0();
      local_4 = 0xffffffff;
      FUN_10001c70((int)local_554);
      FUN_10009800();
      DVar1 = GetTickCount();
      bVar13 = false;
      while (DAT_1000f1b4 == 0) {
        FUN_10002560(0,10);
        iVar2 = (**(code **)(*DAT_1000ef88 + 0x24))();
        if (iVar2 != 0) {
          FUN_10001c40(local_554);
          local_4 = 1;
          iVar2 = FUN_100012b0();
          if (iVar2 == 0) {
            if (local_554[0] == 0x15) {
              bVar13 = true;
            }
            else {
              FUN_10006f80(local_554);
            }
          }
          local_4 = 0xffffffff;
          FUN_10001c70((int)local_554);
          if (bVar13) break;
        }
        DVar3 = GetTickCount();
        if (DVar1 + 10000 < DVar3) {
          FUN_10001630(1);
          DVar1 = GetTickCount();
          iVar11 = iVar11 + 1;
          if (iVar11 == 0xc) {
            DAT_1000f1dc = 0;
            FUN_100099b0();
            UVar16 = 0;
            pcVar15 = s_Error_1000e7d0;
            pcVar14 = s_Timeout_while_waiting_for_initia_1000e80c;
            pHVar4 = GetForegroundWindow();
            MessageBoxA(pHVar4,pcVar14,pcVar15,UVar16);
            local_55c = 0xffffffff;
            iVar11 = DAT_1000f1e4;
            goto LAB_100091c8;
          }
        }
        FUN_10008e30();
      }
      FUN_100099b0();
      if (DAT_1000f1b4 != 0) {
        DAT_1000f1dc = 0;
        local_55c = 0xffffffff;
        iVar11 = DAT_1000f1e4;
        goto LAB_100091c8;
      }
      DAT_1000f1ec = 1;
    }
    if (0 < (int)param_2) {
      if (DAT_1000f160 == (char *)0x0) {
        DAT_1000f168 = param_2 << 4;
        DAT_1000f160 = malloc(DAT_1000f168);
      }
      else if (DAT_1000f168 < (int)(DAT_1000f164 + param_2)) {
        do {
          DAT_1000f168 = DAT_1000f168 * 2;
        } while (DAT_1000f168 < (int)(DAT_1000f164 + param_2));
        DAT_1000f160 = realloc(DAT_1000f160,DAT_1000f168);
      }
      pcVar14 = param_1;
      pcVar15 = DAT_1000f160 + DAT_1000f164;
      for (uVar7 = param_2 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
        pcVar14 = pcVar14 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar7 = param_2 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar15 = *pcVar14;
        pcVar14 = pcVar14 + 1;
        pcVar15 = pcVar15 + 1;
      }
      DAT_1000f164 = DAT_1000f164 + param_2;
    }
    uVar7 = DAT_1000f164;
    pcVar14 = DAT_1000f160;
    DAT_1000f1b0 = DAT_1000f1b0 + 1;
    if (DAT_1000f1b0 == DAT_1000eefc) {
      iVar11 = 0;
      DAT_1000f1b0 = 0;
      if (0 < DAT_1000f1cc) {
        do {
          if ((iVar11 < 0) || (DAT_1000f1cc <= iVar11)) {
            pvVar6 = (void *)0x0;
          }
          else {
            pvVar6 = (void *)DAT_1000f1c8[iVar11];
          }
          FUN_10009b30(pvVar6,(undefined4 *)acStack_40c,uVar7);
          bVar13 = true;
          uVar8 = uVar7;
          pcVar15 = acStack_40c;
          pcVar12 = pcVar14;
          do {
            if (uVar8 == 0) break;
            uVar8 = uVar8 - 1;
            bVar13 = *pcVar15 == *pcVar12;
            pcVar15 = pcVar15 + 1;
            pcVar12 = pcVar12 + 1;
          } while (bVar13);
          if (bVar13) {
            if (iVar11 != -1) {
              FUN_10001c40(local_554);
              local_4 = 2;
              local_554[0] = 0x13;
              FUN_10001f00(local_554);
              local_4 = 3;
              FUN_100010d0();
              local_4 = 0xffffffff;
              FUN_10001c70((int)local_554);
              goto LAB_10009379;
            }
            break;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < DAT_1000f1cc);
      }
      FUN_10001c40(local_554);
      local_4 = 4;
      local_554[0] = 0x12;
      FUN_10001f30(local_554);
      FUN_10001d80(local_554,(undefined4 *)pcVar14,uVar7);
      local_4 = 5;
      FUN_100010d0();
      local_4 = 0xffffffff;
      FUN_10001c70((int)local_554);
      if (DAT_1000f1cc == 0x100) {
        if ((void *)*DAT_1000f1c8 != (void *)0x0) {
          FUN_10009c40((void *)*DAT_1000f1c8,1);
        }
        FUN_10009a30(&DAT_1000f1c8,0);
      }
      puVar5 = operator_new(0xc);
      local_4 = 6;
      if (puVar5 == (undefined4 *)0x0) {
        pvVar6 = (void *)0x0;
      }
      else {
        pvVar6 = (void *)FUN_10009aa0(puVar5);
      }
      local_4 = 0xffffffff;
      FUN_10009ab0(pvVar6,(undefined4 *)pcVar14,uVar7);
      FUN_100099f0(&DAT_1000f1c8,pvVar6);
LAB_10009379:
      DAT_1000f164 = 0;
      iVar11 = DAT_1000f1e4 + 1;
      if (DAT_1000f1e0 + 1 <= DAT_1000f1e4 + 1) {
        do {
          bVar13 = false;
          FUN_10001c40(aiStack_520);
          local_4 = 7;
          iVar11 = 0;
          DVar1 = GetTickCount();
          while( true ) {
            FUN_10002560(0,10);
            iVar2 = (**(code **)(*DAT_1000ef88 + 0x24))();
            if ((iVar2 != 0) && (iVar2 = FUN_100012b0(), iVar2 == 0)) break;
            DVar3 = GetTickCount();
            if (DVar1 + 2000 < DVar3) {
              FUN_10001630(DAT_1000f1e0 + 4);
              DVar1 = GetTickCount();
              iVar11 = iVar11 + 1;
              if (iVar11 == 3) {
                UVar16 = 0;
                pcVar15 = s_Error_1000e7d0;
                pcVar14 = s_Lost_connection____1000e7f8;
                DAT_1000f1dc = 0;
                pHVar4 = GetForegroundWindow();
                MessageBoxA(pHVar4,pcVar14,pcVar15,UVar16);
                local_4 = 0xffffffff;
                FUN_10001c70((int)aiStack_520);
                local_55c = 0xffffffff;
                iVar11 = DAT_1000f1e4;
                goto LAB_100091c8;
              }
            }
            FUN_10008e30();
          }
          if (aiStack_520[0] == 8) {
            FUN_10001c80(&iStack_4bc,aiStack_520);
            local_4._0_1_ = 0xc;
            FUN_10001e60(&iStack_4bc,acStack_48c,0x80);
            local_4._0_1_ = 0xd;
            if (DAT_1000edb0 != (code *)0x0) {
              (*DAT_1000edb0)(auStack_4b8,acStack_48c);
            }
            FUN_10006f80(aiStack_520);
            bVar13 = true;
            local_4 = CONCAT31(local_4._1_3_,7);
            piVar10 = &iStack_4bc;
LAB_1000979b:
            FUN_10001c70((int)piVar10);
          }
          else {
            if (aiStack_520[0] == 0x12) {
              FUN_10001c80(local_554,aiStack_520);
              local_4._0_1_ = 8;
              uVar7 = FUN_10001f40(local_554);
              pcVar14 = pcStack_530;
              uVar8 = uVar7 & 0xffff;
              local_4._0_1_ = 9;
              uStack_524 = uVar8;
              if (DAT_1000f1ac == 0x100) {
                if ((void *)*DAT_1000f1a8 != (void *)0x0) {
                  FUN_10009c40((void *)*DAT_1000f1a8,1);
                }
                FUN_10009a30(&DAT_1000f1a8,0);
              }
              puVar5 = operator_new(0xc);
              local_4._0_1_ = 10;
              if (puVar5 == (undefined4 *)0x0) {
                pvVar6 = (void *)0x0;
              }
              else {
                pvVar6 = (void *)FUN_10009aa0(puVar5);
              }
              local_4 = CONCAT31(local_4._1_3_,9);
              FUN_10009ab0(pvVar6,(undefined4 *)pcVar14,uVar8);
              FUN_100099f0(&DAT_1000f1a8,pvVar6);
              if (uVar8 != 0) {
                if (DAT_1000f150 == (char *)0x0) {
                  DAT_1000f158 = uVar8 << 4;
                  DAT_1000f150 = malloc(DAT_1000f158);
                }
                else if (DAT_1000f158 < (int)(DAT_1000f154 + uVar8)) {
                  do {
                    DAT_1000f158 = DAT_1000f158 * 2;
                  } while (DAT_1000f158 < (int)(DAT_1000f154 + uVar8));
                  DAT_1000f150 = realloc(DAT_1000f150,DAT_1000f158);
                }
                pcVar15 = DAT_1000f150 + DAT_1000f154;
                for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
                DAT_1000f154 = DAT_1000f154 + uVar8;
              }
              local_55c = (uint)((longlong)(ulonglong)uVar8 / (longlong)DAT_1000eefc);
              uVar7 = local_55c;
              if ((int)DAT_1000f154 < (int)local_55c) {
                uVar7 = DAT_1000f154;
              }
              if (0 < (int)uVar7) {
                pcVar14 = DAT_1000f150;
                pcVar15 = param_1;
                for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
                uVar9 = DAT_1000f154 - uVar7;
                pcVar14 = DAT_1000f150 + uVar7;
                pcVar15 = DAT_1000f150;
                DAT_1000f154 = uVar9;
                for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
              }
              local_4 = CONCAT31(local_4._1_3_,7);
              piVar10 = local_554;
              goto LAB_1000979b;
            }
            if (aiStack_520[0] == 0x13) {
              FUN_10001c80(aiStack_4f0,aiStack_520);
              local_4._0_1_ = 0xb;
              uStack_4c0 = FUN_10001f10(aiStack_4f0);
              uStack_4c0 = uStack_4c0 & 0xff;
              local_4 = CONCAT31(local_4._1_3_,7);
              if ((int)uStack_4c0 < DAT_1000f1ac) {
                local_55c = *(uint *)(DAT_1000f1a8[uStack_4c0] + 4);
                pcVar14 = *(char **)DAT_1000f1a8[uStack_4c0];
              }
              else {
                local_55c = 0;
                pcVar14 = (char *)0x0;
              }
              if (0 < (int)local_55c) {
                if (DAT_1000f150 == (char *)0x0) {
                  DAT_1000f158 = local_55c << 4;
                  DAT_1000f150 = malloc(DAT_1000f158);
                }
                else if (DAT_1000f158 < (int)(DAT_1000f154 + local_55c)) {
                  do {
                    DAT_1000f158 = DAT_1000f158 * 2;
                  } while (DAT_1000f158 < (int)(DAT_1000f154 + local_55c));
                  DAT_1000f150 = realloc(DAT_1000f150,DAT_1000f158);
                }
                pcVar15 = DAT_1000f150 + DAT_1000f154;
                for (uVar7 = local_55c >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar7 = local_55c & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
                DAT_1000f154 = DAT_1000f154 + local_55c;
              }
              local_55c = (int)local_55c / DAT_1000eefc;
              uVar7 = local_55c;
              if ((int)DAT_1000f154 < (int)local_55c) {
                uVar7 = DAT_1000f154;
              }
              if (0 < (int)uVar7) {
                pcVar14 = DAT_1000f150;
                pcVar15 = param_1;
                for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
                uVar9 = DAT_1000f154 - uVar7;
                pcVar14 = DAT_1000f150 + uVar7;
                pcVar15 = DAT_1000f150;
                DAT_1000f154 = uVar9;
                for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                  *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
                  pcVar14 = pcVar14 + 4;
                  pcVar15 = pcVar15 + 4;
                }
                for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                  *pcVar15 = *pcVar14;
                  pcVar14 = pcVar14 + 1;
                  pcVar15 = pcVar15 + 1;
                }
              }
              piVar10 = aiStack_4f0;
              goto LAB_1000979b;
            }
            FUN_10006f80(aiStack_520);
            bVar13 = true;
          }
          local_4 = 0xffffffff;
          FUN_10001c70((int)aiStack_520);
          iVar11 = DAT_1000f1e4;
        } while (bVar13);
      }
    }
    else {
      iVar11 = DAT_1000f1e4;
      if (DAT_1000f154 != 0) {
        local_55c = (int)DAT_1000f154 / (DAT_1000eefc - DAT_1000f1b0);
        uVar7 = local_55c;
        if ((int)DAT_1000f154 < (int)local_55c) {
          uVar7 = DAT_1000f154;
        }
        if (0 < (int)uVar7) {
          pcVar14 = DAT_1000f150;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)param_1 = *(undefined4 *)pcVar14;
            pcVar14 = pcVar14 + 4;
            param_1 = param_1 + 4;
          }
          for (uVar8 = uVar7 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *param_1 = *pcVar14;
            pcVar14 = pcVar14 + 1;
            param_1 = param_1 + 1;
          }
          uVar9 = DAT_1000f154 - uVar7;
          pcVar14 = DAT_1000f150 + uVar7;
          pcVar15 = DAT_1000f150;
          DAT_1000f154 = uVar9;
          for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar14;
            pcVar14 = pcVar14 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar9 = uVar9 & 3; iVar11 = DAT_1000f1e4, uVar9 != 0; uVar9 = uVar9 - 1) {
            *pcVar15 = *pcVar14;
            pcVar14 = pcVar14 + 1;
            pcVar15 = pcVar15 + 1;
          }
        }
      }
    }
  }
LAB_100091c8:
  DAT_1000f1e4 = iVar11;
  *unaff_FS_OFFSET = local_c;
  return local_55c;
}
