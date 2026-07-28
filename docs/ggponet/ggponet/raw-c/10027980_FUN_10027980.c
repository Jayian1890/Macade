
undefined4 * FUN_10027980(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  void **ppvVar3;
  void *local_34 [10];
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d689;
  local_34[9] = ExceptionList;
  ExceptionList = local_34 + 9;
  FUN_100028c0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  *in_ECX = SyncTestBackend::vftable;
  FUN_100203d0();
  local_8 = 0;
  FUN_10002da0();
  local_8 = CONCAT31(local_8._1_3_,1);
  puVar2 = in_ECX;
  for (iVar1 = 7; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
  }
  in_ECX[0xa5] = param_3;
  in_ECX[0xa6] = 1;
  *(undefined1 *)(in_ECX + 0xa7) = 0;
  *(undefined1 *)((int)in_ECX + 0x29d) = 0;
  in_ECX[0xa8] = 0;
  FUN_10011480(in_ECX + 0xa9,param_2);
  local_34[0] = (void *)0x0;
  local_34[1] = (void *)0x0;
  local_34[2] = (void *)0x0;
  local_34[3] = (void *)0x0;
  local_34[4] = (void *)0x0;
  local_34[5] = (void *)0x0;
  local_34[6] = (void *)0x0;
  ppvVar3 = local_34;
  puVar2 = in_ECX;
  for (iVar1 = 7; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppvVar3 = (void *)*puVar2;
    ppvVar3 = ppvVar3 + 1;
  }
  local_34[7] = (void *)0x1;
  local_34[8] = (void *)0x14;
  FUN_10020350(local_34);
  (*(code *)in_ECX[1])(param_2);
  ExceptionList = local_34[9];
  return in_ECX;
}
