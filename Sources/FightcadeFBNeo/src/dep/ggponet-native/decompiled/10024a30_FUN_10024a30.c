
void FUN_10024a30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = Udp::vftable;
  if (in_ECX[1] != -1) {
    Ordinal_3(in_ECX[1]);
    in_ECX[1] = 0xffffffff;
  }
  if (in_ECX[7] != 0) {
    CloseHandle((HANDLE)in_ECX[7]);
    in_ECX[7] = 0;
  }
  FUN_10007a20();
  FUN_10001660();
  return;
}
