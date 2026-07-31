
undefined4 *
FUN_10029a40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 local_2c [4];
  undefined4 local_1c;
  char *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d78b;
  local_10 = ExceptionList;
  uVar1 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_100287f0(param_1,param_2,6000);
  local_8 = 0;
  *in_ECX = GGPOBackend::vftable;
  in_ECX[1] = GGPOBackend::vftable;
  FUN_10025bc0(uVar1);
  local_8._0_1_ = 1;
  FUN_10001450();
  local_8._0_1_ = 2;
  FUN_10001490();
  local_8 = CONCAT31(local_8._1_3_,3);
  *(undefined1 *)(in_ECX + 0x8be) = 0;
  *(undefined1 *)((int)in_ECX + 0x22f9) = 0;
  in_ECX[0x8bf] = 0;
  in_ECX[0x8c0] = 0;
  in_ECX[0x8c1] = 0;
  in_ECX[0x8c2] = 0xffffffff;
  _memset(in_ECX + 0x8c5,0,8);
  _memset(in_ECX + 0x8c3,0,8);
  *(undefined1 *)(in_ECX + 0x8b5) = 0;
  in_ECX[0x8b6] = 0;
  *(undefined1 *)(in_ECX + 0x7b4) = 0;
  *(undefined1 *)(in_ECX + 0x6f4) = 0;
  *(undefined1 *)(in_ECX + 0x734) = 0;
  in_ECX[0x8b4] = 0;
  FUN_10011480(in_ECX + 0x774,param_2);
  FUN_10011480(in_ECX + 0x6b4,param_3);
  local_1c = 0x1774;
  local_18 = "ggpo.fightcade.com";
  local_14 = param_4;
  FUN_10025b90(&local_1c,in_ECX + 9);
  FUN_10026140();
  local_2c[0] = 5000;
  (*(code *)in_ECX[8])(local_2c);
  ExceptionList = local_10;
  return in_ECX;
}
