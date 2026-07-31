
void FUN_100013f0(void)

{
  int *in_ECX;
  
  if (*in_ECX == 0xf) {
    _free((void *)in_ECX[1]);
  }
  return;
}
