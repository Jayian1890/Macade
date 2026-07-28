
int FUN_10008630(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  cVar1 = FUN_10001170();
  if (cVar1 == '\0') {
    FUN_100116d5();
  }
  iVar2 = FUN_10001140();
  if (*(int *)(in_ECX + 4) == *(int *)(iVar2 + 0x14)) {
    FUN_100116d5();
  }
  puVar3 = (undefined4 *)FUN_10007c60(*(undefined4 *)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 4) = *puVar3;
  return in_ECX;
}
