
void FUN_10028ac0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_1;
  local_8 = param_2;
  FUN_10023fa0(&local_c,in_ECX + 0x24);
  *(undefined1 *)(in_ECX + 0x19c8) = 0;
  *(undefined1 *)(in_ECX + 0x19c9) = 1;
  *(undefined1 *)(in_ECX + 0x19d4) = param_3;
  FUN_10024210();
  return;
}
