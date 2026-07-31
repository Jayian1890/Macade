
undefined4 FUN_10027400(char *param_1,va_list param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2a0) != 0) {
    FID_conflict__vfprintf(*(FILE **)(in_ECX + 0x2a0),param_1,param_2);
  }
  return 1;
}
