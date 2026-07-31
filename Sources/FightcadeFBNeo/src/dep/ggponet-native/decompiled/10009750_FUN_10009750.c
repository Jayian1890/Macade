
void FUN_10009750(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uStack_60;
  uint local_50;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d830;
  local_10 = ExceptionList;
  uStack_60 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_60;
  ExceptionList = &local_10;
  local_18 = FUN_10009100();
  if (param_3 != 0) {
    iVar1 = FUN_10008eb0();
    iVar2 = FUN_10009730();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FUN_10009680();
    }
    else {
      iVar1 = FUN_10008eb0();
      if (local_18 < iVar1 + param_3) {
        uVar4 = local_18 >> 1;
        iVar1 = FUN_10009730();
        if (iVar1 - uVar4 < local_18) {
          local_50 = 0;
        }
        else {
          local_50 = (local_18 >> 1) + local_18;
        }
        local_18 = local_50;
        iVar1 = FUN_10008eb0();
        if (local_18 < iVar1 + param_3) {
          iVar1 = FUN_10008eb0();
          local_18 = iVar1 + param_3;
        }
        local_20 = FUN_100082e0(local_18);
        local_1c = param_2 - *(int *)(in_ECX + 0xc) >> 4;
        local_24 = 0;
        local_8 = 0;
        FUN_10009270(local_1c * 0x10 + local_20,param_3,param_4);
        local_24 = local_24 + 1;
        do_is(*(undefined4 *)(in_ECX + 0xc),param_2,local_20);
        local_24 = local_24 + 1;
        do_is(param_2,*(undefined4 *)(in_ECX + 0x10),(local_1c + param_3) * 0x10 + local_20);
        FUN_1000991b();
        return;
      }
      if ((uint)(*(int *)(in_ECX + 0x10) - param_2 >> 4) < param_3) {
        local_34 = *param_4;
        local_30 = param_4[1];
        local_2c = param_4[2];
        local_28 = param_4[3];
        do_is(param_2,*(undefined4 *)(in_ECX + 0x10),param_3 * 0x10 + param_2);
        local_8 = 2;
        FUN_10009270(*(undefined4 *)(in_ECX + 0x10),
                     param_3 - (*(int *)(in_ECX + 0x10) - param_2 >> 4),&local_34);
        FUN_10009a4c();
        return;
      }
      local_48 = *param_4;
      local_44 = param_4[1];
      local_40 = param_4[2];
      local_3c = param_4[3];
      local_38 = *(int *)(in_ECX + 0x10);
      uVar3 = do_is(local_38 + param_3 * -0x10,local_38,*(undefined4 *)(in_ECX + 0x10));
      *(undefined4 *)(in_ECX + 0x10) = uVar3;
      FUN_1000a030(param_2,local_38 + param_3 * -0x10,local_38);
      FUN_1000a000(param_2,param_3 * 0x10 + param_2,&local_48);
    }
  }
  ExceptionList = local_10;
  return;
}
