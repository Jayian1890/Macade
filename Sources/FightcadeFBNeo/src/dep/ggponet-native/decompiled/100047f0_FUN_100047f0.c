
int FUN_100047f0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  cVar2 = FUN_10001170();
  if (cVar2 == '\0') {
    FUN_100116d5();
  }
  iVar1 = *(int *)(in_ECX + 4);
  iVar3 = FUN_10001140();
  iVar4 = FUN_10001140();
  if (((uint)(*(int *)(iVar3 + 0x18) + *(int *)(iVar4 + 0x1c)) < (uint)(iVar1 + param_1)) ||
     (iVar1 = *(int *)(in_ECX + 4), iVar3 = FUN_10001140(),
     (uint)(iVar1 + param_1) < *(uint *)(iVar3 + 0x18))) {
    FUN_100116d5();
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + param_1;
  return in_ECX;
}
