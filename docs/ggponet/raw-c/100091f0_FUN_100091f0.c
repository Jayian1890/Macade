
undefined4 FUN_100091f0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = FUN_10009730();
    if (uVar1 < param_1) {
      FUN_10009680();
    }
    else {
      uVar2 = FUN_100082e0(param_1);
      *(undefined4 *)(in_ECX + 0xc) = uVar2;
      *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0xc);
      *(uint *)(in_ECX + 0x14) = param_1 * 0x10 + *(int *)(in_ECX + 0xc);
    }
    uVar2 = 1;
  }
  return uVar2;
}
