
int FUN_10009cb0(uint param_1,int param_2)

{
  int in_ECX;
  
  FUN_100086c0();
  if (((param_2 == 0) || (param_1 < *(uint *)(param_2 + 0xc))) ||
     (*(uint *)(param_2 + 0x10) < param_1)) {
    FUN_100116d5();
  }
  FUN_10001120(param_2);
  *(uint *)(in_ECX + 4) = param_1;
  return in_ECX;
}
