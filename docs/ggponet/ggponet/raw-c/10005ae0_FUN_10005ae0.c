
/* WARNING: Removing unreachable block (ram,0x10005b7c) */

undefined4 FUN_10005ae0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 *puVar6;
  undefined4 local_50;
  undefined1 local_45;
  undefined1 local_44 [11];
  undefined1 local_39;
  undefined1 local_38 [11];
  undefined1 local_2d;
  undefined1 local_2c [20];
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  char local_5;
  
  puVar2 = (undefined4 *)FUN_10006e40();
  local_10 = *puVar2;
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_5 = '\x01';
  while (pcVar3 = (char *)FUN_10005a90(local_10), *pcVar3 == '\0') {
    local_c = local_10;
    uVar4 = FUN_10004ea0(local_10);
    uVar5 = FUN_10007c60(param_2,uVar4);
    local_5 = FUN_10005650(uVar5,uVar4);
    if (local_5 == '\0') {
      puVar2 = (undefined4 *)FUN_100086e0(local_10);
      local_50 = *puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_10007c60(local_10);
      local_50 = *puVar2;
    }
    local_10 = local_50;
  }
  _Vector_iterator<>(local_c,in_ECX);
  if (local_5 != '\0') {
    uVar4 = FUN_10005ab0(local_2c);
    cVar1 = FUN_10005710(uVar4);
    if (cVar1 != '\0') {
      local_2d = 1;
      puVar6 = &local_2d;
      uVar4 = FUN_10005dd0(local_38,1,local_c,param_2);
      FUN_100074b0(uVar4,puVar6);
      return param_1;
    }
    FUN_10007220();
  }
  uVar4 = FUN_10007c60(param_2);
  uVar5 = FUN_10002210(uVar4);
  uVar5 = FUN_10004ea0(uVar5);
  cVar1 = FUN_10005650(uVar5,uVar4);
  if (cVar1 == '\0') {
    local_45 = 0;
    FUN_100074b0(local_18,&local_45);
  }
  else {
    local_39 = 1;
    puVar6 = &local_39;
    uVar4 = FUN_10005dd0(local_44,local_5,local_c,param_2);
    FUN_100074b0(uVar4,puVar6);
  }
  return param_1;
}
