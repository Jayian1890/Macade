
void FUN_100010d0(void)

{
  int iVar1;
  int *extraout_ECX;
  void *in_stack_00008004;
  
  FUN_1000c760();
  iVar1 = FUN_10001f60(in_stack_00008004,&stack0x00000000,0x7fff);
  (**(code **)(*extraout_ECX + 0x1c))(&stack0x00000000,iVar1);
  return;
}
