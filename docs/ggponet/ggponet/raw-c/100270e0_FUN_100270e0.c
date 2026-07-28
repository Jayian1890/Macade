
undefined4 FUN_100270e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == *(int *)(in_ECX + 0x2c)) {
    uVar1 = FUN_10026f60();
  }
  else if (param_1 == *(int *)(in_ECX + 0x40)) {
    uVar1 = FUN_10026830();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
