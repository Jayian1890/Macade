
void FUN_1000a740(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d430;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_1 != param_2; param_1 = param_1 + 0x10) {
    FUN_100044e0(param_3,param_1);
    param_3 = param_3 + 0x10;
  }
  FUN_1000a7de();
  return;
}
