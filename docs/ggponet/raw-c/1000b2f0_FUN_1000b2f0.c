
int FUN_1000b2f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  cVar1 = FUN_10001170();
  if (cVar1 == '\0') {
    FUN_100116d5();
  }
  puVar2 = (undefined4 *)FUN_100019c0(*(undefined4 *)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 4) = *puVar2;
  iVar3 = FUN_10001140();
  if (*(int *)(in_ECX + 4) == *(int *)(iVar3 + 0x14)) {
    FUN_100116d5();
  }
  return in_ECX;
}
