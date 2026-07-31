
/* WARNING: Removing unreachable block (ram,0x10004f7b) */
/* WARNING: Removing unreachable block (ram,0x10004ff0) */
/* WARNING: Removing unreachable block (ram,0x10005069) */
/* WARNING: Removing unreachable block (ram,0x1000509e) */
/* WARNING: Removing unreachable block (ram,0x100050e2) */
/* WARNING: Removing unreachable block (ram,0x1000512a) */
/* WARNING: Removing unreachable block (ram,0x10005105) */
/* WARNING: Removing unreachable block (ram,0x10005152) */
/* WARNING: Removing unreachable block (ram,0x10005187) */
/* WARNING: Removing unreachable block (ram,0x100051b6) */
/* WARNING: Removing unreachable block (ram,0x100051e7) */
/* WARNING: Removing unreachable block (ram,0x1000522f) */
/* WARNING: Removing unreachable block (ram,0x1000520a) */
/* WARNING: Removing unreachable block (ram,0x1000500c) */
/* WARNING: Removing unreachable block (ram,0x1000503f) */
/* WARNING: Removing unreachable block (ram,0x10005064) */
/* WARNING: Removing unreachable block (ram,0x10004f97) */
/* WARNING: Removing unreachable block (ram,0x10004fc8) */
/* WARNING: Removing unreachable block (ram,0x10004feb) */
/* WARNING: Removing unreachable block (ram,0x10005252) */

undefined4 *
FUN_10004f30(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined1 local_48 [12];
  undefined1 local_3c [8];
  undefined1 local_34 [8];
  undefined1 local_2c [32];
  undefined4 local_c;
  undefined4 local_8;
  
  _String_const_iterator<>();
  iVar2 = FUN_10003f40();
  if (iVar2 == 0) {
    FUN_10005dd0(param_1,1,*(undefined4 *)(in_ECX + 0x18),param_4);
    return param_1;
  }
  uVar3 = FUN_10005ab0(local_2c);
  cVar1 = FUN_10005710(uVar3);
  if (cVar1 == '\0') {
    uVar3 = FUN_10004c30(local_34);
    cVar1 = FUN_10005710(uVar3);
    if (cVar1 == '\0') {
      uVar3 = FUN_10002210();
      uVar3 = FUN_10004ea0(uVar3);
      uVar4 = FUN_10007c60(param_4,uVar3);
      cVar1 = FUN_10005650(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_c = param_2;
        local_8 = param_3;
        uVar3 = FUN_10007c60(param_4);
        FUN_10006410(uVar3);
        uVar4 = FUN_10002210();
        uVar4 = FUN_10004ea0(uVar4);
        cVar1 = FUN_10005650(uVar4,uVar3);
        if (cVar1 != '\0') {
          uVar3 = FUN_10002210();
          puVar6 = (undefined4 *)FUN_100086e0(uVar3);
          pcVar5 = (char *)FUN_10005a90(*puVar6);
          if (*pcVar5 != '\0') {
            uVar3 = FUN_10002210(param_4);
            FUN_10005dd0(param_1,0,uVar3,param_4);
            return param_1;
          }
          uVar3 = FUN_10002210(param_4);
          FUN_10005dd0(param_1,1,uVar3,param_4);
          return param_1;
        }
      }
      uVar3 = FUN_10007c60(param_4);
      uVar4 = FUN_10002210(uVar3);
      uVar4 = FUN_10004ea0(uVar4);
      cVar1 = FUN_10005650(uVar4,uVar3);
      if (cVar1 != '\0') {
        local_c = param_2;
        local_8 = param_3;
        uVar3 = FUN_10004c30(local_3c);
        FUN_100063f0(uVar3);
        cVar1 = FUN_10005710(uVar3);
        if (cVar1 == '\0') {
          uVar3 = FUN_10002210();
          uVar3 = FUN_10004ea0(uVar3);
          uVar4 = FUN_10007c60(param_4,uVar3);
          cVar1 = FUN_10005650(uVar4,uVar3);
          if (cVar1 == '\0') goto LAB_10005528;
        }
        uVar3 = FUN_10002210();
        puVar6 = (undefined4 *)FUN_100086e0(uVar3);
        pcVar5 = (char *)FUN_10005a90(*puVar6);
        if (*pcVar5 != '\0') {
          uVar3 = FUN_10002210(param_4);
          FUN_10005dd0(param_1,0,uVar3,param_4);
          return param_1;
        }
        uVar3 = FUN_10002210(param_4);
        FUN_10005dd0(param_1,1,uVar3,param_4);
        return param_1;
      }
    }
    else {
      uVar3 = FUN_10007c60(param_4);
      puVar6 = (undefined4 *)FUN_100062e0(uVar3);
      uVar4 = FUN_10004ea0(*puVar6);
      cVar1 = FUN_10005650(uVar4,uVar3);
      if (cVar1 != '\0') {
        puVar6 = (undefined4 *)FUN_100062e0(param_4);
        FUN_10005dd0(param_1,0,*puVar6,param_4);
        return param_1;
      }
    }
  }
  else {
    uVar3 = FUN_10002210();
    uVar3 = FUN_10004ea0(uVar3);
    uVar4 = FUN_10007c60(param_4,uVar3);
    cVar1 = FUN_10005650(uVar4,uVar3);
    if (cVar1 != '\0') {
      uVar3 = FUN_10002210(param_4);
      FUN_10005dd0(param_1,1,uVar3,param_4);
      return param_1;
    }
  }
LAB_10005528:
  puVar6 = (undefined4 *)FUN_10005ae0(local_48,param_4);
  uVar3 = puVar6[1];
  *param_1 = *puVar6;
  param_1[1] = uVar3;
  return param_1;
}
