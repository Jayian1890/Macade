
int FUN_10009100(void)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_c = 0;
  }
  else {
    local_c = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc) >> 4;
  }
  return local_c;
}
