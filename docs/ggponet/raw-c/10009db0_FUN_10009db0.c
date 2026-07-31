
int FUN_10009db0(int param_1)

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
  if ((*(uint *)(iVar3 + 0x10) < (uint)(param_1 * 0x10 + iVar1)) ||
     (iVar1 = *(int *)(in_ECX + 4), iVar3 = FUN_10001140(),
     (uint)(param_1 * 0x10 + iVar1) < *(uint *)(iVar3 + 0xc))) {
    FUN_100116d5();
  }
  *(int *)(in_ECX + 4) = param_1 * 0x10 + *(int *)(in_ECX + 4);
  return in_ECX;
}
