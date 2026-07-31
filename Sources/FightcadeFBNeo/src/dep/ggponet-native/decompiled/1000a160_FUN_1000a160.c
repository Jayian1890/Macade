
void FUN_1000a160(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d300;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_100044e0(param_1,param_3);
    param_1 = param_1 + 0x10;
  }
  FUN_1000a1fc();
  return;
}
