
int FUN_10008f80(void)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_c = 0;
  }
  else {
    local_c = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc) >> 3;
  }
  return local_c;
}
