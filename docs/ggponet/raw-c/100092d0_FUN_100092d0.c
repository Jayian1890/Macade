
void FUN_100092d0(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uStack_50;
  uint local_40;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
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
  puStack_c = &LAB_1002d850;
  local_10 = ExceptionList;
  uStack_50 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = (undefined1 *)&uStack_50;
  ExceptionList = &local_10;
  local_18 = FUN_10008f80();
  if (param_3 != 0) {
    iVar1 = FUN_10008d70();
    iVar2 = FUN_100092b0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FUN_10009680();
    }
    else {
      iVar1 = FUN_10008d70();
      if (local_18 < iVar1 + param_3) {
        uVar4 = local_18 >> 1;
        iVar1 = FUN_100092b0();
        if (iVar1 - uVar4 < local_18) {
          local_40 = 0;
        }
        else {
          local_40 = (local_18 >> 1) + local_18;
        }
        local_18 = local_40;
        iVar1 = FUN_10008d70();
        if (local_18 < iVar1 + param_3) {
          iVar1 = FUN_10008d70();
          local_18 = iVar1 + param_3;
        }
        local_20 = FUN_100085c0(local_18);
        local_1c = param_2 - *(int *)(in_ECX + 0xc) >> 3;
        local_24 = 0;
        local_8 = 0;
        FUN_100090c0(local_20 + local_1c * 8,param_3,param_4);
        local_24 = local_24 + 1;
        do_is(*(undefined4 *)(in_ECX + 0xc),param_2,local_20);
        local_24 = local_24 + 1;
        do_is(param_2,*(undefined4 *)(in_ECX + 0x10),local_20 + (local_1c + param_3) * 8);
        FUN_10009499();
        return;
      }
      if ((uint)(*(int *)(in_ECX + 0x10) - param_2 >> 3) < param_3) {
        local_2c = *param_4;
        local_28 = param_4[1];
        do_is(param_2,*(undefined4 *)(in_ECX + 0x10),param_2 + param_3 * 8);
        local_8 = 2;
        FUN_100090c0(*(undefined4 *)(in_ECX + 0x10),
                     param_3 - (*(int *)(in_ECX + 0x10) - param_2 >> 3),&local_2c);
        FUN_100095be();
        return;
      }
      local_38 = *param_4;
      local_34 = param_4[1];
      local_30 = *(int *)(in_ECX + 0x10);
      uVar3 = do_is(local_30 + param_3 * -8,local_30,*(undefined4 *)(in_ECX + 0x10));
      *(undefined4 *)(in_ECX + 0x10) = uVar3;
      FUN_10009f60(param_2,local_30 + param_3 * -8,local_30);
      FUN_10009f30(param_2,param_2 + param_3 * 8,&local_38);
    }
  }
  ExceptionList = local_10;
  return;
}
