
void FUN_10024050(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(in_ECX + 0x1090) == 0) {
    if (*(int *)(param_1 + 1) == *(int *)(in_ECX + 0x109c)) {
      *(int *)(in_ECX + 0x1098) = *(int *)(in_ECX + 0x1098) + -1;
      if (*(int *)(in_ECX + 0x1098) == 0) {
        FUN_10022c50();
        iVar1 = FUN_100118ec(0x20);
        if (iVar1 == 0) {
          local_20 = 0;
        }
        else {
          local_20 = FUN_10003e40(2);
        }
        FUN_10023320(local_20);
        *(undefined4 *)(in_ECX + 0x1090) = 2;
        *(undefined4 *)(in_ECX + 0x10c8) = 0xffffffff;
      }
      else {
        iVar1 = FUN_100118ec(0x20);
        if (iVar1 == 0) {
          local_24 = 0;
        }
        else {
          local_24 = FUN_10003e40(1);
        }
        *(int *)(local_24 + 4) = DAT_10038528;
        *(int *)(local_24 + 8) = DAT_10038528 - *(int *)(in_ECX + 0x1098);
        FUN_10023320(local_24);
        FUN_10023960();
      }
    }
    else {
      FUN_10022c50();
    }
  }
  else {
    FUN_10022c50();
  }
  return;
}
