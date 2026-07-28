
uint FUN_1000cdd0(uint param_1)

{
  uint uVar1;
  uint in_ECX;
  uint uVar2;
  byte *in_EDX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  byte *pbVar20;
  
  uVar4 = in_ECX & 0xffff;
  uVar2 = in_ECX >> 0x10;
  if (in_EDX == (byte *)0x0) {
    return 1;
  }
  while (param_1 != 0) {
    uVar1 = param_1;
    if (0x15af < param_1) {
      uVar1 = 0x15b0;
    }
    param_1 = param_1 - uVar1;
    if (0xf < (int)uVar1) {
      uVar3 = uVar1 >> 4;
      uVar1 = uVar1 + uVar3 * -0x10;
      pbVar20 = in_EDX;
      do {
        in_EDX = pbVar20 + 0x10;
        iVar5 = uVar4 + *pbVar20;
        iVar6 = iVar5 + (uint)pbVar20[1];
        iVar7 = iVar6 + (uint)pbVar20[2];
        iVar8 = iVar7 + (uint)pbVar20[3];
        iVar9 = iVar8 + (uint)pbVar20[4];
        iVar10 = iVar9 + (uint)pbVar20[5];
        iVar11 = iVar10 + (uint)pbVar20[6];
        iVar12 = iVar11 + (uint)pbVar20[7];
        iVar13 = iVar12 + (uint)pbVar20[8];
        iVar14 = iVar13 + (uint)pbVar20[9];
        iVar15 = iVar14 + (uint)pbVar20[10];
        iVar16 = iVar15 + (uint)pbVar20[0xb];
        iVar17 = iVar16 + (uint)pbVar20[0xc];
        iVar18 = iVar17 + (uint)pbVar20[0xd];
        iVar19 = iVar18 + (uint)pbVar20[0xe];
        uVar4 = iVar19 + (uint)pbVar20[0xf];
        uVar2 = uVar2 + iVar5 + iVar6 + iVar7 + iVar8 + iVar9 + iVar10 + iVar11 + iVar12 + iVar13 +
                iVar14 + iVar15 + iVar16 + iVar17 + iVar18 + iVar19 + uVar4;
        uVar3 = uVar3 - 1;
        pbVar20 = in_EDX;
      } while (uVar3 != 0);
    }
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uVar4 = uVar4 + *in_EDX;
      in_EDX = in_EDX + 1;
      uVar2 = uVar2 + uVar4;
    }
    uVar4 = uVar4 % 0xfff1;
    uVar2 = uVar2 % 0xfff1;
  }
  return uVar2 << 0x10 | uVar4;
}
