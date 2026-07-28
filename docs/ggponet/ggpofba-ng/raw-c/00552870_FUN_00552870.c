
void FUN_00552870(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined2 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined4 *local_c;
  int local_4;
  
  iVar7 = param_2;
  local_c = DAT_00b19978;
  switch(DAT_00b19990) {
  case 0:
    param_2 = 0;
    if (DAT_00b19860 == 2) {
      puVar10 = DAT_00b19978;
      if (0 < DAT_00b19980) {
        do {
          puVar3 = (undefined4 *)(DAT_00b19984 + (int)puVar10);
          puVar2 = (undefined2 *)(iVar7 + (int)param_1);
          puVar4 = param_1;
          do {
            *(undefined2 *)puVar4 = *(undefined2 *)puVar10;
            *(undefined2 *)((int)puVar4 + 2) = *(undefined2 *)puVar10;
            *puVar2 = *(undefined2 *)puVar10;
            puVar2[1] = *(undefined2 *)puVar10;
            puVar10 = (undefined4 *)((int)puVar10 + 2);
            puVar4 = puVar4 + 1;
            puVar2 = puVar2 + 2;
          } while (puVar10 < puVar3);
          param_2 = param_2 + 1;
          param_1 = (undefined4 *)((int)param_1 + iVar7 * 2);
          puVar10 = puVar3;
        } while (param_2 < DAT_00b19980);
        return;
      }
    }
    else if (DAT_00b19860 == 4) {
      puVar10 = DAT_00b19978;
      if (0 < DAT_00b19980) {
        do {
          puVar3 = (undefined4 *)(DAT_00b19984 + (int)puVar10);
          puVar4 = (undefined4 *)(iVar7 + (int)param_1);
          puVar1 = param_1;
          do {
            *puVar1 = *puVar10;
            puVar1[1] = *puVar10;
            *puVar4 = *puVar10;
            puVar4[1] = *puVar10;
            puVar10 = puVar10 + 1;
            puVar1 = puVar1 + 2;
            puVar4 = puVar4 + 2;
          } while (puVar10 < puVar3);
          param_2 = param_2 + 1;
          param_1 = (undefined4 *)((int)param_1 + iVar7 * 2);
          puVar10 = puVar3;
        } while (param_2 < DAT_00b19980);
        return;
      }
    }
    else {
      puVar10 = DAT_00b19978;
      if (0 < DAT_00b19980) {
        do {
          puVar4 = (undefined4 *)(DAT_00b19984 + (int)puVar10);
          puVar9 = (undefined1 *)(iVar7 + 5 + (int)param_1);
          puVar3 = param_1 + 1;
          puVar2 = (undefined2 *)((int)puVar10 + 2);
          do {
            *(undefined1 *)(puVar3 + -1) = *(undefined1 *)(puVar2 + -1);
            *(undefined1 *)((int)puVar3 + -1) = *(undefined1 *)(puVar2 + -1);
            *(undefined1 *)((int)puVar3 + iVar7 + -4) = *(undefined1 *)(puVar2 + -1);
            *(undefined1 *)(iVar7 + -1 + (int)puVar3) = *(undefined1 *)(puVar2 + -1);
            *(undefined1 *)((int)puVar3 + -3) = *(undefined1 *)((int)puVar2 + -1);
            *(undefined1 *)puVar3 = *(undefined1 *)((int)puVar2 + -1);
            *(undefined1 *)((int)puVar3 + iVar7 + -3) = *(undefined1 *)((int)puVar2 + -1);
            *(undefined1 *)((int)puVar3 + iVar7) = *(undefined1 *)((int)puVar2 + -1);
            *(undefined1 *)((int)puVar3 + -2) = *(undefined1 *)puVar2;
            *(undefined1 *)((int)puVar3 + 1) = *(undefined1 *)puVar2;
            *(undefined1 *)((int)puVar3 + iVar7 + -2) = *(undefined1 *)puVar2;
            *puVar9 = *(undefined1 *)puVar2;
            puVar10 = (undefined4 *)((int)puVar2 + 1);
            puVar3 = (undefined4 *)((int)puVar3 + 3);
            puVar9 = puVar9 + 3;
            puVar2 = (undefined2 *)((int)puVar2 + 3);
          } while (puVar10 < puVar4);
          param_2 = param_2 + 1;
          param_1 = (undefined4 *)((int)param_1 + iVar7 * 2);
          puVar10 = puVar4;
        } while (param_2 < DAT_00b19980);
        return;
      }
    }
    break;
  case 1:
    puVar9 = (undefined1 *)((int)DAT_00b19978 + DAT_00b19984);
    if (DAT_00b19860 == 2) {
      FUN_00551c40(param_1,param_2 + (int)param_1);
    }
    else {
      FUN_00551c70(param_1,param_2 + (int)param_1);
    }
    iVar7 = (int)local_c - DAT_00b19984;
    local_4 = 2;
    puVar10 = param_1;
    if (DAT_00b19860 == 2) {
      if (2 < DAT_00b19980) {
        do {
          iVar6 = DAT_00b1997c;
          param_1 = (undefined4 *)((int)param_1 + param_2 * 2);
          iVar7 = iVar7 + DAT_00b19984;
          local_c = (undefined4 *)((int)local_c + DAT_00b19984);
          puVar9 = puVar9 + DAT_00b19984;
          FUN_00551880(param_1,iVar7,local_c,puVar9,DAT_00b1997c);
          FUN_00551880(param_2 + (int)param_1,puVar9,local_c,iVar7,iVar6);
          local_4 = local_4 + 1;
          puVar10 = param_1;
        } while (local_4 < DAT_00b19980);
      }
    }
    else if (2 < DAT_00b19980) {
      do {
        iVar6 = DAT_00b1997c;
        param_1 = (undefined4 *)((int)param_1 + param_2 * 2);
        iVar7 = iVar7 + DAT_00b19984;
        local_c = (undefined4 *)((int)local_c + DAT_00b19984);
        puVar9 = puVar9 + DAT_00b19984;
        FUN_00551a60(param_1,iVar7,local_c,puVar9,DAT_00b1997c);
        FUN_00551a60(param_2 + (int)param_1,puVar9,local_c,iVar7,iVar6);
        local_4 = local_4 + 1;
        puVar10 = param_1;
      } while (local_4 < DAT_00b19980);
    }
    param_1 = (undefined4 *)iVar7;
    iVar7 = DAT_00b1997c;
    iVar6 = (int)param_1 + DAT_00b19984;
    puVar5 = (undefined1 *)((int)local_c + DAT_00b19984);
    puVar2 = (undefined2 *)((int)puVar10 + param_2 * 2);
    if (DAT_00b19860 == 2) {
      FUN_00551880(puVar2,iVar6,puVar5,puVar9,DAT_00b1997c);
      FUN_00551880((int)puVar2 + param_2,puVar9,puVar5,iVar6,iVar7);
    }
    else {
      FUN_00551a60(puVar2,iVar6,puVar5,puVar9,DAT_00b1997c);
      FUN_00551a60((int)puVar2 + param_2,puVar9,puVar5,iVar6,iVar7);
    }
    return;
  case 2:
    puVar2 = (undefined2 *)((int)param_1 + param_2 * 2);
    puVar10 = (undefined4 *)((int)DAT_00b19978 + DAT_00b19984);
    if (DAT_00b19860 == 2) {
      FUN_00551e70(param_1,param_2 + (int)param_1,puVar2,DAT_00b19978);
    }
    else {
      FUN_00551ef0(param_1,param_2 + (int)param_1,puVar2,DAT_00b19978);
    }
    param_2 = 2;
    if (DAT_00b19860 == 2) {
      puVar3 = local_c;
      if (2 < DAT_00b19980) {
        do {
          local_c = puVar10;
          param_1 = (undefined4 *)((int)param_1 + iVar7 * 3);
          puVar10 = (undefined4 *)((int)local_c + DAT_00b19984);
          FUN_00551e70(param_1,iVar7 + (int)param_1,(undefined2 *)((int)param_1 + iVar7 * 2),puVar3)
          ;
          param_2 = param_2 + 1;
          puVar3 = local_c;
        } while (param_2 < DAT_00b19980);
      }
    }
    else {
      puVar3 = local_c;
      if (2 < DAT_00b19980) {
        do {
          local_c = puVar10;
          param_1 = (undefined4 *)((int)param_1 + iVar7 * 3);
          puVar10 = (undefined4 *)((int)local_c + DAT_00b19984);
          FUN_00551ef0(param_1,iVar7 + (int)param_1,(undefined2 *)((int)param_1 + iVar7 * 2),puVar3)
          ;
          param_2 = param_2 + 1;
          puVar3 = local_c;
        } while (param_2 < DAT_00b19980);
      }
    }
    iVar6 = iVar7 * 3 + (int)param_1;
    iVar8 = iVar6 + iVar7 * 2;
    if (DAT_00b19860 != 2) {
      FUN_00551ef0(iVar6,iVar6 + iVar7,iVar8,local_c);
      return;
    }
    FUN_00551e70(iVar6,iVar6 + iVar7,iVar8,local_c);
    return;
  case 3:
    iVar6 = DAT_00b1997c * 2;
    FUN_0067eb50(DAT_00b19978,DAT_00b19978,iVar6,param_1,param_1);
    iVar8 = 0;
    iVar7 = param_2 + -2 + (int)param_1;
    if (0 < DAT_00b19980) {
      do {
        FUN_0067eb50(local_c,(undefined1 *)(DAT_00b19984 + (int)local_c),iVar6,iVar7,param_2 + iVar7
                    );
        iVar8 = iVar8 + 1;
        local_c = (undefined4 *)((int)local_c + DAT_00b19984);
        iVar7 = iVar7 + param_2 * 2;
      } while (iVar8 < DAT_00b19980);
    }
    return;
  case 4:
    iVar6 = DAT_00b19988 + DAT_00b19984;
    FUN_0067f518(DAT_00b19978,iVar6,DAT_00b19984,DAT_00b1997c + -1,param_1,param_2,0);
    iVar8 = (int)param_1 + param_2;
    param_2 = 0;
    if (0 < DAT_00b19980) {
      do {
        FUN_0067f518(local_c,iVar6,DAT_00b19984,DAT_00b1997c + -1,iVar8,iVar7,0);
        iVar8 = iVar8 + iVar7 * 2;
        param_2 = param_2 + 1;
        local_c = (undefined4 *)((int)local_c + DAT_00b19984);
        iVar6 = iVar6 + DAT_00b19984;
      } while (param_2 < DAT_00b19980);
      return;
    }
    break;
  case 5:
    iVar6 = DAT_00b19988 + DAT_00b19984;
    FUN_0067fb26(DAT_00b19978,iVar6,DAT_00b19984,DAT_00b1997c + -1,param_1,param_2,0);
    iVar8 = (int)param_1 + param_2;
    param_2 = 0;
    if (0 < DAT_00b19980) {
      do {
        FUN_0067fb26(local_c,iVar6,DAT_00b19984,DAT_00b1997c + -1,iVar8,iVar7,0);
        iVar8 = iVar8 + iVar7 * 2;
        param_2 = param_2 + 1;
        local_c = (undefined4 *)((int)local_c + DAT_00b19984);
        iVar6 = iVar6 + DAT_00b19984;
      } while (param_2 < DAT_00b19980);
      return;
    }
    break;
  case 6:
    iVar6 = DAT_00b19988 + DAT_00b19984;
    FUN_0067ee10(DAT_00b19978,iVar6,DAT_00b19984,DAT_00b1997c + -1,param_1,param_2,0);
    iVar8 = (int)param_1 + param_2;
    param_2 = 0;
    if (0 < DAT_00b19980) {
      do {
        FUN_0067ee10(local_c,iVar6,DAT_00b19984,DAT_00b1997c + -1,iVar8,iVar7,0);
        iVar8 = iVar8 + iVar7 * 2;
        param_2 = param_2 + 1;
        local_c = (undefined4 *)((int)local_c + DAT_00b19984);
        iVar6 = iVar6 + DAT_00b19984;
      } while (param_2 < DAT_00b19980);
      return;
    }
    break;
  case 7:
    FUN_006801a0(DAT_00b19978,param_1,DAT_00b1997c,DAT_00b19980,param_2);
    return;
  case 8:
    FUN_00689150(DAT_00b19978,param_1,DAT_00b1997c,DAT_00b19980,param_2);
    return;
  case 9:
    FUN_00694a80(DAT_00b19978,param_1,DAT_00b1997c,DAT_00b19980,param_2);
  }
  return;
}
