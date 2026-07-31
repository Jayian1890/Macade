
undefined4 FUN_10024390(void)

{
  int iVar1;
  DWORD DVar2;
  int in_ECX;
  uint uVar3;
  int local_1c;
  
  if (*(int *)(in_ECX + 0x1090) == 0) {
    uVar3 = *(int *)(in_ECX + 0x1094) + DAT_10038538;
    DVar2 = timeGetTime();
    if (uVar3 < DVar2) {
      FUN_10022c50(in_ECX,"No luck after %d ms... Re-queueing sync packet.\n",DAT_10038538);
      FUN_10023960();
    }
  }
  else if (*(int *)(in_ECX + 0x1090) == 2) {
    if (((-1 < *(int *)(in_ECX + 0x10c8)) &&
        (*(int *)(in_ECX + 0x1094) == *(int *)(in_ECX + 0x10c8))) &&
       (*(int *)(in_ECX + 0x1098) == *(int *)(in_ECX + 0x10e4))) {
      FUN_10022c50();
      FUN_100239f0();
    }
    *(undefined4 *)(in_ECX + 0x1098) = *(undefined4 *)(in_ECX + 0x10e4);
    *(undefined4 *)(in_ECX + 0x1094) = *(undefined4 *)(in_ECX + 0x10c8);
    iVar1 = FUN_100118ec(0x100c);
    if (iVar1 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = FUN_10008950(4);
    }
    DVar2 = timeGetTime();
    *(DWORD *)(local_1c + 2) = DVar2;
    *(undefined1 *)(local_1c + 1) = *(undefined1 *)(in_ECX + 0x10a0);
    FUN_10023930(local_1c);
  }
  return 1;
}
