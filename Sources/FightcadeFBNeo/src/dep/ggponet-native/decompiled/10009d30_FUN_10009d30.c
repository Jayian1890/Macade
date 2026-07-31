
int FUN_10009d30(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  cVar2 = FUN_10001170();
  if (cVar2 == '\0') {
    FUN_100116d5();
  }
  iVar1 = *(int *)(in_ECX + 4);
  iVar3 = FUN_10001140();
  if ((*(uint *)(iVar3 + 0x10) < (uint)(iVar1 + param_1 * 8)) ||
     (iVar1 = *(int *)(in_ECX + 4), iVar3 = FUN_10001140(),
     (uint)(iVar1 + param_1 * 8) < *(uint *)(iVar3 + 0xc))) {
    FUN_100116d5();
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + param_1 * 8;
  return in_ECX;
}
