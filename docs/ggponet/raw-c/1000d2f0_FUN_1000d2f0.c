
void FUN_1000d2f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  int in_ECX;
  uint uVar4;
  int in_EDX;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  
  iVar2 = 0;
  if (*(int *)(in_ECX + 0x7c) < 1) {
    uVar4 = param_1 + 5;
  }
  else {
    if (*(char *)(in_ECX + 0x1c) == '\x02') {
      FUN_1000e800();
    }
    FUN_1000d4e0();
    FUN_1000d4e0();
    iVar2 = FUN_1000da80();
    uVar5 = *(int *)(in_ECX + 0x16a0) + 10U >> 3;
    uVar4 = *(int *)(in_ECX + 0x16a4) + 10U >> 3;
    if (uVar5 < uVar4) goto LAB_1000d356;
  }
  uVar5 = uVar4;
LAB_1000d356:
  if ((uVar5 < param_1 + 4U) || (in_EDX == 0)) {
    iVar6 = *(int *)(in_ECX + 0x16b4);
    bVar3 = (byte)iVar6;
    if (uVar4 == uVar5) {
      iVar2 = param_2 + 2;
      if (iVar6 < 0xe) {
        puVar7 = &DAT_1002e880;
        *(ushort *)(in_ECX + 0x16b0) =
             *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar2 << (bVar3 & 0x1f));
        *(int *)(in_ECX + 0x16b4) = iVar6 + 3;
      }
      else {
        puVar7 = &DAT_1002e880;
        *(ushort *)(in_ECX + 0x16b0) =
             *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar2 << (bVar3 & 0x1f));
        *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
             *(undefined1 *)(in_ECX + 0x16b0);
        iVar6 = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x14) = iVar6;
        *(undefined1 *)(*(int *)(in_ECX + 8) + iVar6) = *(undefined1 *)(in_ECX + 0x16b1);
        iVar6 = *(int *)(in_ECX + 0x16b4);
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x16b4) = iVar6 + -0xd;
        *(ushort *)(in_ECX + 0x16b0) = (ushort)iVar2 >> (0x10U - (char)iVar6 & 0x1f);
      }
    }
    else {
      iVar1 = param_2 + 4;
      if (iVar6 < 0xe) {
        *(ushort *)(in_ECX + 0x16b0) =
             *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar1 << (bVar3 & 0x1f));
        *(int *)(in_ECX + 0x16b4) = iVar6 + 3;
      }
      else {
        *(ushort *)(in_ECX + 0x16b0) =
             *(ushort *)(in_ECX + 0x16b0) | (ushort)(iVar1 << (bVar3 & 0x1f));
        *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) =
             *(undefined1 *)(in_ECX + 0x16b0);
        iVar6 = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x14) = iVar6;
        *(undefined1 *)(iVar6 + *(int *)(in_ECX + 8)) = *(undefined1 *)(in_ECX + 0x16b1);
        iVar6 = *(int *)(in_ECX + 0x16b4);
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
        *(int *)(in_ECX + 0x16b4) = iVar6 + -0xd;
        *(ushort *)(in_ECX + 0x16b0) = (ushort)iVar1 >> (0x10U - (char)iVar6 & 0x1f);
      }
      FUN_1000dbd0(*(int *)(in_ECX + 0xb20) + 1,iVar2 + 1);
      puVar7 = (undefined *)(in_ECX + 0x980);
    }
    FUN_1000e3c0(puVar7);
  }
  else {
    FUN_1000cff0(param_1,param_2);
  }
  FUN_1000cf80();
  if (param_2 != 0) {
    FUN_1000e920();
  }
  return;
}
