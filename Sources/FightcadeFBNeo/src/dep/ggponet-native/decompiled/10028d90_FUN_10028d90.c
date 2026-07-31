
undefined4 *
FUN_10028d90(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_1c;
  char *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d6cb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028c0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  FUN_100028e0();
  *in_ECX = SpectatorBackend::vftable;
  in_ECX[1] = SpectatorBackend::vftable;
  FUN_10025bc0();
  local_8 = 0;
  FUN_100284c0();
  local_8._0_1_ = 1;
  FUN_10002da0();
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = 0;
  local_18 = (char *)0x0;
  local_14 = 0;
  _memset(in_ECX + 0x11b,0,0x704);
  FUN_10011480(in_ECX + 0x11b,param_3);
  local_1c = 0x1774;
  local_18 = "ggpo.fightcade.com";
  local_14 = param_4;
  FUN_10025b90(&local_1c,in_ECX + 0x47);
  FUN_10026140();
  puVar2 = in_ECX + 2;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  (*(code *)in_ECX[2])(param_2);
  ExceptionList = local_10;
  return in_ECX;
}
