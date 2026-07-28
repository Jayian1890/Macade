
void FUN_10006e70(void)

{
  int iVar1;
  DWORD DVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 auStack_6c [12];
  undefined4 auStack_3c [12];
  undefined4 uStack_c;
  undefined *puStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  puStack_8 = &DAT_1000cac0;
  *unaff_FS_OFFSET = &uStack_c;
  FUN_10002560(0,0);
  iVar1 = (**(code **)(*DAT_1000ef88 + 0x24))();
  if (iVar1 != 0) {
    FUN_10001c40(auStack_6c);
    uStack_4 = 0;
    iVar1 = FUN_100012b0();
    if (iVar1 != 0) {
      uStack_4 = 0xffffffff;
      FUN_10001c70((int)auStack_6c);
      *unaff_FS_OFFSET = uStack_c;
      return;
    }
    FUN_10006f80(auStack_6c);
    uStack_4 = 0xffffffff;
    FUN_10001c70((int)auStack_6c);
  }
  DVar2 = GetTickCount();
  if (DAT_1000f184 + 60000 < DVar2) {
    FUN_10001c40(auStack_3c);
    auStack_3c[0] = 9;
    uStack_4 = 1;
    FUN_100010d0();
    uStack_4 = 0xffffffff;
    FUN_10001c70((int)auStack_3c);
    DAT_1000f184 = GetTickCount();
  }
  *unaff_FS_OFFSET = uStack_c;
  return;
}
