
void FUN_1000ab90(void)

{
  char cVar1;
  void *this;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  char unaff_DI;
  char *pcVar11;
  undefined4 *unaff_FS_OFFSET;
  char *pcVar12;
  char *pcStack_510;
  char cStack_50c;
  char acStack_50b [255];
  CHAR local_40c [512];
  CHAR local_20c [512];
  undefined4 local_c;
  undefined *puStack_8;
  undefined4 local_4;
  
  iVar5 = DAT_1000f234;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &DAT_1000cdbc;
  *unaff_FS_OFFSET = &local_c;
  if (iVar5 < 0xb) {
    if (iVar5 == 10) {
      wsprintfA(local_20c,s_Done__Found__i_online_servers__1000e8e0,DAT_1000f410);
      FUN_1000b390(local_20c);
      DAT_1000f234 = 9999;
    }
    else {
      switch(iVar5) {
      case 0:
        SetWindowTextA(DAT_1000f3e8,&DAT_1000e99c);
        FUN_1000b3b0(s_Requesting_list____1000e988);
        DAT_1000f430 = malloc(0x10000);
        DAT_1000f408 = 0;
        this = operator_new(0x44);
        local_4 = 0;
        if (this == (void *)0x0) {
          DAT_1000f42c = (undefined4 *)0x0;
        }
        else {
          DAT_1000f42c = FUN_100033e0(this,0xffffffff,(void *)0x4000,(char *)0x0);
        }
        local_4 = 0xffffffff;
        FUN_10003610(DAT_1000f42c,s_http___kaillera_com_raw_server_l_1000e94c);
        DAT_1000f234 = DAT_1000f234 + 1;
        break;
      case 1:
        iVar5 = FUN_10003cc0(unaff_DI);
        iVar4 = FUN_100040f0((int)DAT_1000f42c);
        while (iVar4 != 0) {
          iVar4 = FUN_10004110(DAT_1000f42c,(undefined4 *)(DAT_1000f430 + DAT_1000f408),
                               0x10000 - DAT_1000f408);
          DAT_1000f408 = DAT_1000f408 + iVar4;
          iVar4 = FUN_100040f0((int)DAT_1000f42c);
        }
        if (iVar5 == -1) {
          FUN_1000b3b0(s_Error_requesting_server_list__1000e92c);
          DAT_1000f234 = 9999;
        }
        else if (iVar5 == 1) {
          DAT_1000f430[DAT_1000f408] = '\0';
          DAT_1000f234 = DAT_1000f234 + 1;
        }
        break;
      case 2:
        SendMessageA(DAT_1000f270,0x1009,0,0);
        SendMessageA(DAT_1000f218,0x1009,0,0);
        puVar3 = DAT_1000f42c;
        if (DAT_1000f42c != (undefined4 *)0x0) {
          FUN_10003530((int)DAT_1000f42c);
          operator_delete(puVar3);
        }
        DAT_1000f234 = DAT_1000f234 + 1;
        DAT_1000f42c = (undefined4 *)0x0;
        DAT_1000f410 = 0;
        cVar1 = *DAT_1000f430;
        iVar5 = 0;
        pcVar12 = DAT_1000f430;
        while ((cVar1 != '\n' && (pcVar12 < DAT_1000f430 + DAT_1000f408))) {
          cVar1 = *pcVar12;
          pcVar9 = pcVar12;
          while (cVar1 != '|') {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          DAT_1000f230 = pcVar12;
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + 1;
          uVar2 = FUN_10004260(&DAT_1000f218,9999,pcVar12,iVar5);
          cVar1 = *pcVar9;
          pcVar12 = pcVar9;
          while (cVar1 != '|') {
            pcVar10 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar12 = '\0';
          pcVar12 = pcVar12 + 1;
          FUN_100042c0(&DAT_1000f218,uVar2,7,pcVar9);
          cVar1 = *pcVar12;
          pcVar9 = pcVar12;
          while (cVar1 != '|') {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + 1;
          FUN_100042c0(&DAT_1000f218,uVar2,2,pcVar12);
          cVar1 = *pcVar9;
          pcVar12 = pcVar9;
          while (cVar1 != '|') {
            pcVar10 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar12 = '\0';
          pcVar12 = pcVar12 + 1;
          FUN_100042c0(&DAT_1000f218,uVar2,1,pcVar9);
          cVar1 = *pcVar12;
          pcVar9 = pcVar12;
          while (cVar1 != '|') {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + 1;
          FUN_100042c0(&DAT_1000f218,uVar2,5,pcVar12);
          cVar1 = *pcVar9;
          pcVar10 = pcVar9;
          while (cVar1 != '|') {
            pcVar12 = pcVar10 + 1;
            pcVar10 = pcVar10 + 1;
            cVar1 = *pcVar12;
          }
          *pcVar10 = '\0';
          pcVar10 = pcVar10 + 1;
          FUN_100042c0(&DAT_1000f218,uVar2,3,pcVar9);
          cVar1 = *pcVar10;
          pcVar12 = pcVar10;
          while (cVar1 != '|') {
            pcVar9 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar9;
          }
          *pcVar12 = '\0';
          FUN_100042c0(&DAT_1000f218,uVar2,4,pcVar10);
          pcVar12 = pcVar12 + 1;
          iVar5 = iVar5 + 1;
          cVar1 = *pcVar12;
        }
        pcVar12 = pcVar12 + 1;
        DAT_1000f238 = 0;
        DAT_1000f230 = pcVar12;
        if (pcVar12 != (char *)0x0) {
          while (pcVar9 = strstr(pcVar12,&DAT_1000e10c), pcVar9 != (char *)0x0) {
            DAT_1000f238 = DAT_1000f238 + 1;
            pcVar12 = strstr(pcVar12,&DAT_1000e10c);
            if ((pcVar12 == (char *)0x0) || (pcVar12 = pcVar12 + 1, pcVar12 == (char *)0x0)) break;
          }
        }
        DAT_1000f238 = DAT_1000f238 / 2;
        break;
      case 3:
        wsprintfA(local_40c,s_Pinging_servers______i__i__1000e910,DAT_1000f410 + 1,DAT_1000f238);
        FUN_1000b390(local_40c);
        if (DAT_1000f434 != (int *)0x0) {
          (**(code **)*DAT_1000f434)(1);
        }
        pcVar12 = DAT_1000f230;
        DAT_1000f434 = (int *)0x0;
        if (DAT_1000f230 < DAT_1000f430 + DAT_1000f408) {
          cVar1 = *DAT_1000f230;
          pcVar9 = DAT_1000f230;
          while (((cVar1 != '\0' && (cVar1 != '\r')) && (cVar1 != '\n'))) {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar9 = '\0';
          uVar2 = FUN_10004260(&DAT_1000f270,9999,pcVar12,DAT_1000f410);
          do {
            do {
              pcVar9 = pcVar9 + 1;
            } while (*pcVar9 == '\r');
          } while (*pcVar9 == '\n');
          cVar1 = *pcVar9;
          pcVar12 = pcVar9;
          while (((cVar1 != '\0' && (cVar1 != ';')) && ((cVar1 != '\r' && (cVar1 != '\n'))))) {
            pcVar10 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar12 = '\0';
          uVar7 = 0xffffffff;
          pcVar12 = pcVar12 + 1;
          pcStack_510 = &cStack_50c;
          pcVar10 = pcVar9;
          do {
            pcVar11 = pcVar10;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar11 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar11;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar10 = pcVar11 + -uVar7;
          pcVar11 = pcStack_510;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          uVar7 = 0xffffffff;
          pcVar10 = pcVar9;
          do {
            pcVar11 = pcVar10;
            if (uVar7 == 0) break;
            uVar7 = uVar7 - 1;
            pcVar11 = pcVar10 + 1;
            cVar1 = *pcVar10;
            pcVar10 = pcVar11;
          } while (cVar1 != '\0');
          uVar7 = ~uVar7;
          pcVar10 = pcVar11 + -uVar7;
          pcVar11 = (char *)&DAT_1000f2ac;
          for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
            pcVar10 = pcVar10 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *pcVar11 = *pcVar10;
            pcVar10 = pcVar10 + 1;
            pcVar11 = pcVar11 + 1;
          }
          FUN_100042c0(&DAT_1000f270,uVar2,6,pcVar9);
          cVar1 = *pcVar12;
          pcVar9 = pcVar12;
          while (((cVar1 != '\0' && (cVar1 != ';')) && ((cVar1 != '\r' && (cVar1 != '\n'))))) {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + 1;
          FUN_100042c0(&DAT_1000f270,uVar2,4,pcVar12);
          cVar1 = *pcVar9;
          pcVar12 = pcVar9;
          while ((((cVar1 != '\0' && (cVar1 != ';')) && (cVar1 != '\r')) && (cVar1 != '\n'))) {
            pcVar10 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar12 = '\0';
          pcVar12 = pcVar12 + 1;
          FUN_100042c0(&DAT_1000f270,uVar2,5,pcVar9);
          cVar1 = *pcVar12;
          pcVar9 = pcVar12;
          while (((cVar1 != '\0' && (cVar1 != ';')) && ((cVar1 != '\r' && (cVar1 != '\n'))))) {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cVar1 = *pcVar10;
          }
          *pcVar9 = '\0';
          pcVar9 = pcVar9 + 1;
          FUN_100042c0(&DAT_1000f270,uVar2,3,pcVar12);
          cVar1 = *pcVar9;
          pcVar12 = pcVar9;
          while (((cVar1 != '\0' && (cVar1 != ';')) && ((cVar1 != '\r' && (cVar1 != '\n'))))) {
            pcVar10 = pcVar12 + 1;
            pcVar12 = pcVar12 + 1;
            cVar1 = *pcVar10;
          }
          cVar1 = *pcVar12;
          *pcVar12 = '\0';
          pcVar12 = pcVar12 + 1;
          FUN_100042c0(&DAT_1000f270,uVar2,1,pcVar9);
          if (cVar1 == ';') {
            cVar1 = *pcVar12;
            while (((cVar1 != '\r' && (cVar1 != '\n')) && (cVar1 != '\0'))) {
              pcVar9 = pcVar12 + 1;
              pcVar12 = pcVar12 + 1;
              cVar1 = *pcVar9;
            }
            for (; (*pcVar12 == '\r' || (*pcVar12 == '\n')); pcVar12 = pcVar12 + 1) {
            }
          }
          DAT_1000f410 = DAT_1000f410 + 1;
          pcVar9 = &cStack_50c;
          while ((cStack_50c != '\0' && (cStack_50c != ':'))) {
            pcVar10 = pcVar9 + 1;
            pcVar9 = pcVar9 + 1;
            cStack_50c = *pcVar10;
          }
          DAT_1000f230 = pcVar12;
          if (*pcVar9 == ':') {
            *pcVar9 = '\0';
            puVar3 = operator_new(0x20);
            local_4 = 1;
            if (puVar3 == (undefined4 *)0x0) {
              DAT_1000f434 = (int *)0x0;
            }
            else {
              DAT_1000f434 = FUN_10002040(puVar3);
            }
            local_4 = 0xffffffff;
            (**(code **)(*DAT_1000f434 + 8))(0);
            iVar5 = *DAT_1000f434;
            iVar4 = atoi(pcVar9 + 1);
            (**(code **)(iVar5 + 0x14))(&pcStack_510,iVar4);
            (**(code **)(*DAT_1000f434 + 0x1c))(&DAT_1000e908,5);
            DAT_1000f3e4 = uVar2;
            DAT_1000f3d0 = GetTickCount();
            DAT_1000f234 = DAT_1000f234 + 1;
            DAT_1000f438 = 1;
          }
        }
        else {
          DAT_1000f234 = 10;
        }
        break;
      case 4:
        FUN_10002560(0,0);
        iVar5 = (**(code **)(*DAT_1000f434 + 0x24))();
        if (iVar5 == 0) {
          DVar6 = GetTickCount();
          if (DVar6 <= DAT_1000f3d0 + 1000) break;
          FUN_100042c0(&DAT_1000f270,DAT_1000f3e4,2,&DAT_1000e900);
          FUN_100044f0(&DAT_1000f270);
          pcVar12 = &DAT_1000e900;
        }
        else {
          DVar6 = GetTickCount();
          wsprintfA(&cStack_50c,s__i_ms_1000e7a4,DVar6 - DAT_1000f3d0);
          FUN_100042c0(&DAT_1000f270,DAT_1000f3e4,2,&cStack_50c);
          FUN_100044f0(&DAT_1000f270);
          pcVar12 = &cStack_50c;
        }
        FUN_1000b3f0((byte *)&DAT_1000f2ac,pcVar12);
        DAT_1000f234 = 3;
      }
    }
  }
  else if (iVar5 == 9999) {
    SetWindowTextA(DAT_1000f3e8,s_Refresh_list_1000e8d0);
    puVar3 = DAT_1000f42c;
    DAT_1000f438 = 0;
    if (DAT_1000f42c != (undefined4 *)0x0) {
      FUN_10003530((int)DAT_1000f42c);
      operator_delete(puVar3);
    }
    DAT_1000f42c = (undefined4 *)0x0;
    if (DAT_1000f434 != (int *)0x0) {
      (**(code **)*DAT_1000f434)(1);
    }
    DAT_1000f434 = (int *)0x0;
    if (DAT_1000f430 != (char *)0x0) {
      free(DAT_1000f430);
    }
    DAT_1000f430 = (char *)0x0;
    DAT_1000f234 = -1;
  }
  *unaff_FS_OFFSET = local_c;
  return;
}
