
void FUN_1000a0a0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d320;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_1000a3d0(param_1,param_3);
    param_1 = param_1 + 8;
  }
  FUN_1000a13c();
  return;
}
