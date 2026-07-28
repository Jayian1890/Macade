
int FUN_1001fce0(void)

{
  int in_ECX;
  undefined4 local_8;
  
  local_8 = *(int *)(in_ECX + 0x270) + -1;
  if (local_8 < 0) {
    local_8 = 0x15;
  }
  return in_ECX + 0x110 + local_8 * 0x10;
}
