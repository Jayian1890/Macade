
undefined4 FUN_0055fb20(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  bool bVar5;
  uint uVar6;
  uint uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  undefined4 auStack_10 [2];
  undefined4 local_8 [2];
  
  local_14 = 0;
  local_8[0] = 0;
  if (DAT_00b19fcc == (int *)0x0) {
    return 1;
  }
  (**(code **)(*DAT_00b19fcc + 0x10))(DAT_00b19fcc,&local_14,local_8);
  uVar1 = uStack_20 / (uint)(DAT_00b19fa0 * 4);
  if ((int)(DAT_0087570c - 1U) < (int)uVar1) {
    uVar1 = DAT_0087570c - 1U;
  }
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  if (DAT_00b19fd8 != uVar1) {
    uVar6 = DAT_00b19fd8 + 1;
    iVar2 = DAT_00b19fa0;
    if (DAT_0087570c <= (int)uVar6) {
      uVar6 = 0;
    }
    do {
      uStack_1c = 0;
      uStack_18 = 0;
      auStack_10[0] = 0;
      iVar2 = (**(code **)(*DAT_00b19fcc + 0x2c))
                        (DAT_00b19fcc,iVar2 * 4 * DAT_00b19fd8,iVar2 * 4,&stack0xffffffdc,&uStack_18
                         ,&uStack_1c,auStack_10,0);
      if (-1 < iVar2) {
        _memcpy((void *)0x0,DAT_00b19fa8,DAT_00b19fa0 * 4);
        (**(code **)(*DAT_00b19fcc + 0x4c))(DAT_00b19fcc,0,uStack_18,uStack_1c,0);
      }
      if (DAT_00b1a910 == 0) {
        (*DAT_00a7d8c4)();
        pvVar4 = DAT_00b19fa8;
        iVar2 = DAT_00b19fa0;
      }
      else {
        FUN_0062ded0("iter: Writing silence into buffer (frame sleep is %d).\n",DAT_00b1a910);
        pvVar4 = DAT_00b19fa8;
        iVar2 = DAT_00b19fa0;
        if (DAT_00b19fa8 != (void *)0x0) {
          _memset(DAT_00b19fa8,0,DAT_00b19fa0 * 4);
        }
        DAT_00b1a910 = DAT_00b1a910 + -1;
      }
      if (((DAT_00b19fa4 != 0) && (DAT_00b19fbc != 0)) && (DAT_00b19fc0 != 0)) {
        FUN_0055f720(pvVar4);
        FUN_0055f720((int)pvVar4 + 2);
      }
      uVar3 = uVar6 + 1;
      DAT_00b19fd8 = uVar6;
      if (DAT_0087570c <= (int)uVar3) {
        uVar3 = 0;
      }
      bVar5 = uVar6 != uVar1;
      uVar6 = uVar3;
    } while (bVar5);
    return 0;
  }
  if (DAT_00ad74dc == 0) {
    Sleep(2);
    return 0;
  }
  ggpo_idle(DAT_00b1a804);
  return 0;
}
