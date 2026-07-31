
void FUN_10026480(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x58) != 0) {
    if (*(int *)(in_ECX + 0x14) != -1) {
      FUN_10021ff0("Closing TCP socket.");
      Ordinal_22(*(undefined4 *)(in_ECX + 0x14),2);
      Ordinal_3(*(undefined4 *)(in_ECX + 0x14));
      *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
    }
    *(undefined4 *)(in_ECX + 0x58) = 0;
  }
  return;
}
