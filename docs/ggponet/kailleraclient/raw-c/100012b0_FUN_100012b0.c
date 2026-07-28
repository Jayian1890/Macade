
undefined4 FUN_100012b0(void)

{
  int iVar1;
  int *extraout_ECX;
  void *in_stack_00007ff8;
  
  FUN_1000c760();
  iVar1 = (**(code **)(*extraout_ECX + 0x20))();
  if (iVar1 != 0) {
    return 1;
  }
  FUN_10001fe0(in_stack_00007ff8,&stack0xfffffff4,(int)&stack0x00000004);
  return 0;
}
