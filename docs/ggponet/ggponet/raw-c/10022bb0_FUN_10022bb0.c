
void FUN_10022bb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x108c);
  iVar2 = *(int *)(in_ECX + 0x10c8);
  iVar3 = FUN_10022b70(*(undefined4 *)(in_ECX + 0x10c4));
  *(int *)(in_ECX + 0x10a0) = (iVar2 + (iVar1 * 0x3c) / 1000 + iVar3) - param_1;
  return;
}
