
int FUN_1000b460(void)

{
  int iVar1;
  int iVar2;
  undefined4 *in_EDX;
  undefined4 local_24;
  
  iVar1 = FUN_1000c950(0x38);
  if (iVar1 == 0) {
    iVar2 = FUN_1000c970();
    if (iVar2 == 1) {
      *in_EDX = local_24;
      iVar1 = FUN_1000c7f0();
    }
    else {
      FUN_1000c7f0();
      iVar1 = -5;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  return iVar1;
}
