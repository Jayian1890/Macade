
void FUN_1000d4e0(void)

{
  byte bVar1;
  short *psVar2;
  byte bVar3;
  int iVar4;
  int in_ECX;
  undefined4 *in_EDX;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short *local_c;
  int local_8;
  
  psVar2 = (short *)*in_EDX;
  iVar6 = *(int *)in_EDX[2];
  local_8 = ((int *)in_EDX[2])[3];
  iVar7 = -1;
  iVar4 = 0;
  *(undefined4 *)(in_ECX + 0x1448) = 0;
  *(undefined4 *)(in_ECX + 0x144c) = 0x23d;
  psVar5 = psVar2;
  if (0 < local_8) {
    do {
      if (*psVar5 == 0) {
        psVar5[1] = 0;
      }
      else {
        iVar7 = *(int *)(in_ECX + 0x1448) + 1;
        *(int *)(in_ECX + 0x1448) = iVar7;
        *(int *)(in_ECX + 0xb54 + iVar7 * 4) = iVar4;
        *(undefined1 *)(iVar4 + 0x1450 + in_ECX) = 0;
        iVar7 = iVar4;
      }
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 2;
    } while (iVar4 < local_8);
  }
  iVar4 = *(int *)(in_ECX + 0x1448);
  while (iVar4 < 2) {
    if (iVar7 < 2) {
      iVar8 = iVar7 + 1;
      iVar7 = iVar8;
    }
    else {
      iVar8 = 0;
    }
    *(int *)(in_ECX + 0x1448) = iVar4 + 1;
    *(int *)(in_ECX + 0xb54 + (iVar4 + 1) * 4) = iVar8;
    psVar2[iVar8 * 2] = 1;
    *(undefined1 *)(in_ECX + 0x1450 + iVar8) = 0;
    *(int *)(in_ECX + 0x16a0) = *(int *)(in_ECX + 0x16a0) + -1;
    if (iVar6 != 0) {
      *(uint *)(in_ECX + 0x16a4) =
           *(int *)(in_ECX + 0x16a4) - (uint)*(ushort *)(iVar6 + 2 + iVar8 * 4);
    }
    iVar4 = *(int *)(in_ECX + 0x1448);
  }
  in_EDX[1] = iVar7;
  for (iVar6 = *(int *)(in_ECX + 0x1448) / 2; 0 < iVar6; iVar6 = iVar6 + -1) {
    FUN_1000d710(iVar6);
  }
  local_c = psVar2 + local_8 * 2;
  do {
    iVar6 = *(int *)(in_ECX + 0xb58);
    *(undefined4 *)(in_ECX + 0xb58) =
         *(undefined4 *)(in_ECX + 0xb54 + *(int *)(in_ECX + 0x1448) * 4);
    *(int *)(in_ECX + 0x1448) = *(int *)(in_ECX + 0x1448) + -1;
    FUN_1000d710(1);
    iVar7 = *(int *)(in_ECX + 0xb58);
    iVar4 = *(int *)(in_ECX + 0x144c) + -1;
    *(int *)(in_ECX + 0x144c) = iVar4;
    *(int *)(in_ECX + 0xb54 + iVar4 * 4) = iVar6;
    iVar4 = *(int *)(in_ECX + 0x144c) + -1;
    *(int *)(in_ECX + 0x144c) = iVar4;
    *(int *)(in_ECX + 0xb54 + iVar4 * 4) = iVar7;
    *local_c = psVar2[iVar7 * 2] + psVar2[iVar6 * 2];
    bVar1 = *(byte *)(in_ECX + 0x1450 + iVar6);
    bVar3 = *(byte *)(in_ECX + 0x1450 + iVar7);
    if (bVar3 <= bVar1) {
      bVar3 = bVar1;
    }
    local_c = local_c + 2;
    *(byte *)(in_ECX + 0x1450 + local_8) = bVar3 + 1;
    psVar2[iVar7 * 2 + 1] = (short)local_8;
    psVar2[iVar6 * 2 + 1] = (short)local_8;
    *(int *)(in_ECX + 0xb58) = local_8;
    local_8 = local_8 + 1;
    FUN_1000d710(1);
  } while (1 < *(int *)(in_ECX + 0x1448));
  iVar6 = *(int *)(in_ECX + 0x144c) + -1;
  *(int *)(in_ECX + 0x144c) = iVar6;
  *(undefined4 *)(in_ECX + 0xb54 + iVar6 * 4) = *(undefined4 *)(in_ECX + 0xb58);
  FUN_1000d7f0();
  FUN_1000da10(in_ECX + 0xb34);
  return;
}
