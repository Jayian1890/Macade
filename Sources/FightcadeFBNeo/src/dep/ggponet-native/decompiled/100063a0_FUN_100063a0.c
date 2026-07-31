
void FUN_100063a0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  cVar1 = FUN_10001170();
  if (cVar1 == '\0') {
    FUN_100116d5();
  }
  iVar2 = FUN_10001140();
  if (*(int *)(in_ECX + 4) == *(int *)(iVar2 + 0x18)) {
    FUN_100116d5();
  }
  FUN_10005aa0(*(undefined4 *)(in_ECX + 4));
  return;
}
