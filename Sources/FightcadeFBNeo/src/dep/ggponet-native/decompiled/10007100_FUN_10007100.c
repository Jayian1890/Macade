
void FUN_10007100(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d380;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10007620(1);
  local_8 = 0;
  iVar2 = FUN_10001080(0x18,uVar1);
  if (iVar2 != 0) {
    FUN_100076d0(param_1,param_2,param_3,param_4,param_5);
  }
  FUN_100071b5();
  return;
}
