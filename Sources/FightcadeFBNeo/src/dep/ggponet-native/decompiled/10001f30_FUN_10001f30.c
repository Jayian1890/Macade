
void FUN_10001f30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d3f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_10002150(1);
  local_8 = 0;
  puVar3 = (undefined1 *)&param_1;
  uVar2 = FUN_10007c60(uVar1,puVar3);
  FUN_10007640(uVar2,puVar3);
  puVar3 = (undefined1 *)&param_2;
  uVar2 = FUN_100019c0(uVar1,puVar3);
  FUN_10007640(uVar2,puVar3);
  uVar2 = param_3;
  uVar1 = FUN_100086e0(uVar1,param_3);
  FUN_10002460(uVar1,uVar2);
  FUN_10002048();
  return;
}
