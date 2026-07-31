
void FUN_10026a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = Tcp::vftable;
  if (in_ECX[5] != -1) {
    FUN_10021ff0("Closing TCP socket.");
    Ordinal_22(in_ECX[5],2);
    Ordinal_3(in_ECX[5]);
  }
  if (in_ECX[0xb] != 0) {
    CloseHandle((HANDLE)in_ECX[0xb]);
  }
  if (in_ECX[0x10] != 0) {
    CloseHandle((HANDLE)in_ECX[0x10]);
  }
  FUN_10003e60();
  FUN_10002980();
  return;
}
