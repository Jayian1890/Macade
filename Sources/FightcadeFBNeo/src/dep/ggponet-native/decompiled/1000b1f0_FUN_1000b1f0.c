
void FUN_1000b1f0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d990;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  while( true ) {
    cVar1 = FUN_10004d20(&stack0x00000014);
    if (cVar1 == '\0') break;
    uVar2 = FUN_10002170();
    FUN_10001a00(param_1,param_2,uVar2);
    FUN_10008630();
  }
  FUN_1000b2c8();
  return;
}
