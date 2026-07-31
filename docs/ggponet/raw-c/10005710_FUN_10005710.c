
undefined4 FUN_10005710(int param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_10001170();
  if ((cVar1 == '\0') || (cVar1 = FUN_10004930(param_1), cVar1 == '\0')) {
    FUN_100116d5();
  }
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(int *)(in_ECX + 4) == *(int *)(param_1 + 4));
}
