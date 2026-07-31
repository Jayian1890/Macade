
void FUN_1000d7f0(void)

{
  ushort *puVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  short *psVar12;
  int *in_EDX;
  uint uVar13;
  ushort *puVar14;
  undefined4 *puVar15;
  int iVar16;
  uint uVar17;
  int local_24;
  int *local_20;
  uint local_1c;
  int local_14;
  
  iVar3 = in_EDX[1];
  iVar4 = *in_EDX;
  piVar5 = (int *)in_EDX[2];
  iVar10 = *piVar5;
  iVar6 = piVar5[1];
  uVar17 = piVar5[4];
  iVar7 = piVar5[2];
  puVar15 = (undefined4 *)(in_ECX + 0xb34);
  for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar15 = 0;
    puVar15 = puVar15 + 1;
  }
  local_1c = 0;
  *(undefined2 *)(iVar4 + 2 + *(int *)(in_ECX + 0xb54 + *(int *)(in_ECX + 0x144c) * 4) * 4) = 0;
  iVar11 = *(int *)(in_ECX + 0x144c) + 1;
  if (iVar11 < 0x23d) {
    local_20 = (int *)(in_ECX + 0xb54 + iVar11 * 4);
    local_14 = 0x23d - iVar11;
    iVar11 = iVar11 + local_14;
    do {
      iVar8 = *local_20;
      uVar9 = *(ushort *)(iVar4 + 2 + (uint)*(ushort *)(iVar4 + 2 + iVar8 * 4) * 4) + 1;
      if ((int)uVar17 < (int)uVar9) {
        local_1c = local_1c + 1;
        uVar9 = uVar17;
      }
      *(short *)(iVar4 + 2 + iVar8 * 4) = (short)uVar9;
      if (iVar8 <= iVar3) {
        psVar12 = (short *)(in_ECX + 0xb34 + uVar9 * 2);
        *psVar12 = *psVar12 + 1;
        iVar16 = 0;
        if (iVar7 <= iVar8) {
          iVar16 = *(int *)(iVar6 + (iVar8 - iVar7) * 4);
        }
        uVar13 = (uint)*(ushort *)(iVar4 + iVar8 * 4);
        *(int *)(in_ECX + 0x16a0) = *(int *)(in_ECX + 0x16a0) + (uVar9 + iVar16) * uVar13;
        if (iVar10 != 0) {
          *(uint *)(in_ECX + 0x16a4) =
               *(int *)(in_ECX + 0x16a4) +
               ((uint)*(ushort *)(iVar10 + 2 + iVar8 * 4) + iVar16) * uVar13;
        }
      }
      local_20 = local_20 + 1;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
    if (local_1c != 0) {
      do {
        iVar10 = uVar17 - 1;
        psVar12 = (short *)(in_ECX + 0xb34 + iVar10 * 2);
        sVar2 = *(short *)(in_ECX + 0xb34 + iVar10 * 2);
        while (sVar2 == 0) {
          psVar12 = psVar12 + -1;
          iVar10 = iVar10 + -1;
          sVar2 = *psVar12;
        }
        psVar12 = (short *)(in_ECX + 0xb34 + iVar10 * 2);
        *psVar12 = *psVar12 + -1;
        psVar12 = (short *)(in_ECX + 0xb36 + iVar10 * 2);
        *psVar12 = *psVar12 + 2;
        psVar12 = (short *)(in_ECX + 0xb34 + uVar17 * 2);
        *psVar12 = *psVar12 + -1;
        local_1c = local_1c + -2;
      } while (0 < (int)local_1c);
      if (uVar17 != 0) {
        puVar14 = (ushort *)(in_ECX + 0xb34 + uVar17 * 2);
        local_24 = iVar11;
        do {
          uVar9 = (uint)*puVar14;
          if (uVar9 != 0) {
            iVar10 = in_ECX + 0xb54 + iVar11 * 4;
            local_1c = uVar9;
            do {
              iVar6 = *(int *)(iVar10 + -4);
              iVar11 = local_24 + -1;
              iVar10 = iVar10 + -4;
              if (iVar6 <= iVar3) {
                puVar1 = (ushort *)(iVar4 + 2 + iVar6 * 4);
                uVar9 = (uint)*puVar1;
                if (uVar9 != uVar17) {
                  *(uint *)(in_ECX + 0x16a0) =
                       *(int *)(in_ECX + 0x16a0) +
                       (uVar17 - uVar9) * (uint)*(ushort *)(iVar4 + iVar6 * 4);
                  *puVar1 = (ushort)uVar17;
                }
                uVar9 = local_1c - 1;
                local_1c = uVar9;
              }
              local_24 = iVar11;
            } while (uVar9 != 0);
          }
          uVar17 = uVar17 - 1;
          puVar14 = puVar14 + -1;
        } while (uVar17 != 0);
      }
    }
  }
  return;
}
