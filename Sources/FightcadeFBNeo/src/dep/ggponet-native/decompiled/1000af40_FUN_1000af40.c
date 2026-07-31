
undefined4 FUN_1000af40(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint local_8;
  
  local_8 = *(uint *)(in_ECX + 4);
  cVar1 = FUN_10001170();
  if (cVar1 == '\0') {
    FUN_100116d5();
  }
  iVar2 = FUN_10001140();
  iVar3 = FUN_10001140();
  if ((uint)(*(int *)(iVar2 + 0x18) + *(int *)(iVar3 + 0x1c)) <= *(uint *)(in_ECX + 4)) {
    FUN_100116d5();
  }
  iVar2 = FUN_10001140();
  if (*(uint *)(iVar2 + 0x14) <= local_8) {
    iVar2 = FUN_10001140();
    local_8 = local_8 - *(int *)(iVar2 + 0x14);
  }
  iVar2 = FUN_10001140();
  return *(undefined4 *)(*(int *)(iVar2 + 0x10) + local_8 * 4);
}
