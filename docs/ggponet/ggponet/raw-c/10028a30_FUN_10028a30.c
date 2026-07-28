
undefined4 FUN_10028a30(DWORD param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x19c8) == '\0') {
    FUN_10028090(0);
    FUN_10028660();
    *(undefined1 *)(in_ECX + 0x19c8) = 1;
    FUN_10020420(param_1);
    *(undefined1 *)(in_ECX + 0x19c8) = 0;
    uVar1 = FUN_10002810();
    FUN_10022bb0(uVar1);
    if (param_1 != 0) {
      Sleep(param_1);
    }
  }
  return 1;
}
