
void FUN_10025090(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x20) = 2;
  uVar2 = Ordinal_11(*param_1);
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  uVar1 = Ordinal_9(*(undefined2 *)(param_1 + 1));
  *(undefined2 *)(in_ECX + 0x22) = uVar1;
  FUN_10028330(in_ECX,*(undefined4 *)(in_ECX + 0x1c),0);
  FUN_10028450(in_ECX,1000,0);
  FUN_10028490(in_ECX,0);
  FUN_10024520(in_ECX,"Priming socket for port %d.\n",*(undefined4 *)(in_ECX + 8));
  FUN_10024520(in_ECX,"Remote endpoint is %s:%d.\n",*param_1,param_1[1]);
  SetEvent(*(HANDLE *)(in_ECX + 0x1c));
  return;
}
