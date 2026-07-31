
int FUN_10004640(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  uint local_8;
  
  local_8 = *(uint *)(in_ECX + 4) >> 2;
  uVar1 = *(uint *)(in_ECX + 4);
  cVar2 = FUN_10001170();
  if (cVar2 == '\0') {
    FUN_100116d5();
  }
  iVar3 = FUN_10001140();
  iVar4 = FUN_10001140();
  if ((uint)(*(int *)(iVar3 + 0x18) + *(int *)(iVar4 + 0x1c)) <= *(uint *)(in_ECX + 4)) {
    FUN_100116d5();
  }
  iVar3 = FUN_10001140();
  if (*(uint *)(iVar3 + 0x14) <= local_8) {
    iVar3 = FUN_10001140();
    local_8 = local_8 - *(int *)(iVar3 + 0x14);
  }
  iVar3 = FUN_10001140();
  return *(int *)(*(int *)(iVar3 + 0x10) + local_8 * 4) + (uVar1 & 3) * 4;
}
