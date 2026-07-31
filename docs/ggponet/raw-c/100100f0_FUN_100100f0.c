
undefined4
FUN_100100f0(uint param_1,int param_2,int param_3,uint *param_4,uint *param_5,int param_6,
            uint *param_7,uint *param_8)

{
  undefined4 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int *in_ECX;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint in_EDX;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint local_104;
  uint local_100;
  int local_fc;
  uint *local_f8;
  int local_f4;
  uint local_f0;
  uint *local_e8;
  undefined4 local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_bc [47];
  
  local_bc[0] = 0;
  local_bc[1] = 0;
  local_bc[2] = 0;
  local_bc[3] = 0;
  local_bc[4] = 0;
  local_bc[5] = 0;
  local_bc[6] = 0;
  local_bc[7] = 0;
  local_bc[8] = 0;
  local_bc[9] = 0;
  local_bc[10] = 0;
  local_bc[0xb] = 0;
  local_bc[0xc] = 0;
  local_bc[0xd] = 0;
  local_bc[0xe] = 0;
  local_bc[0xf] = 0;
  piVar8 = in_ECX;
  uVar15 = in_EDX;
  do {
    iVar17 = *piVar8;
    piVar8 = piVar8 + 1;
    uVar15 = uVar15 - 1;
    local_bc[iVar17] = local_bc[iVar17] + 1;
  } while (uVar15 != 0);
  if (local_bc[0] == in_EDX) {
    *param_4 = 0;
    *param_5 = 0;
  }
  else {
    local_100 = 1;
    puVar7 = local_bc;
    do {
      puVar7 = puVar7 + 1;
      if (*puVar7 != 0) break;
      local_100 = local_100 + 1;
    } while (local_100 < 0x10);
    local_104 = *param_5;
    if (*param_5 < local_100) {
      local_104 = local_100;
    }
    uVar15 = 0xf;
    puVar7 = local_bc + 0xf;
    do {
      if (*puVar7 != 0) break;
      uVar15 = uVar15 - 1;
      puVar7 = puVar7 + -1;
    } while (uVar15 != 0);
    if (uVar15 < local_104) {
      local_104 = uVar15;
    }
    *param_5 = local_104;
    iVar17 = 1 << ((byte)local_100 & 0x1f);
    if (local_100 < uVar15) {
      puVar7 = local_bc + local_100;
      uVar9 = local_100;
      do {
        uVar18 = *puVar7;
        if ((int)(iVar17 - uVar18) < 0) {
          return 0xfffffffd;
        }
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 1;
        iVar17 = (iVar17 - uVar18) * 2;
      } while (uVar9 < uVar15);
    }
    iVar17 = iVar17 - local_bc[uVar15];
    if (iVar17 < 0) {
      return 0xfffffffd;
    }
    local_bc[0x11] = 0;
    local_bc[uVar15] = local_bc[uVar15] + iVar17;
    iVar10 = 0;
    iVar16 = uVar15 - 1;
    if (iVar16 != 0) {
      iVar4 = 0;
      do {
        iVar10 = iVar10 + *(int *)((int)local_bc + iVar4 + 4);
        iVar16 = iVar16 + -1;
        *(int *)((int)local_bc + iVar4 + 0x48) = iVar10;
        iVar4 = iVar4 + 4;
      } while (iVar16 != 0);
    }
    uVar9 = 0;
    do {
      iVar10 = *in_ECX;
      in_ECX = in_ECX + 1;
      if (iVar10 != 0) {
        uVar18 = local_bc[iVar10 + 0x10];
        param_8[uVar18] = uVar9;
        local_bc[iVar10 + 0x10] = uVar18 + 1;
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < in_EDX);
    uVar18 = 0;
    local_fc = -1;
    uVar9 = local_bc[uVar15 + 0x10];
    local_f0 = 0;
    local_f8 = param_8;
    iVar10 = -local_104;
    local_bc[0x10] = 0;
    local_bc[0x20] = 0;
    local_d4 = 0;
    local_d8 = 0;
    if ((int)local_100 <= (int)uVar15) {
      local_f4 = local_100 - 1;
      local_e8 = local_bc + local_100;
      do {
        uVar6 = *local_e8;
        uVar1 = local_e0;
        while (uVar6 != 0) {
          uVar13 = uVar6 - 1;
          local_e0._2_2_ = (undefined2)((uint)uVar1 >> 0x10);
          uVar2 = local_e0._2_2_;
          iVar16 = iVar10;
          while (local_e0 = uVar1, iVar16 = iVar16 + local_104, iVar16 < (int)local_100) {
            iVar10 = iVar10 + local_104;
            uVar18 = uVar15 - iVar10;
            if (local_104 < uVar15 - iVar10) {
              uVar18 = local_104;
            }
            uVar11 = local_100 - iVar10;
            uVar3 = 1 << ((byte)uVar11 & 0x1f);
            if ((uVar6 < uVar3) &&
               (iVar4 = uVar3 + (-1 - uVar13), puVar7 = local_e8, uVar11 < uVar18)) {
              while (uVar11 = uVar11 + 1, uVar11 < uVar18) {
                uVar3 = puVar7[1];
                uVar5 = iVar4 * 2;
                if (uVar5 < uVar3 || uVar5 - uVar3 == 0) break;
                iVar4 = uVar5 - uVar3;
                puVar7 = puVar7 + 1;
              }
            }
            local_d8 = 1 << ((byte)uVar11 & 0x1f);
            uVar18 = *param_7;
            uVar3 = local_d8 + uVar18;
            if (0x5a0 < uVar3) {
              return 0xfffffffd;
            }
            *param_7 = uVar3;
            local_d4 = param_6 + uVar18 * 8;
            local_bc[local_fc + 0x21] = local_d4;
            if (local_fc + 1 == 0) {
              *param_4 = local_d4;
            }
            else {
              local_bc[local_fc + 0x11] = local_f0;
              local_e0._2_2_ = (undefined2)((uint)local_e0 >> 0x10);
              local_e0._0_2_ = CONCAT11((char)local_104,(byte)uVar11);
              uVar11 = local_f0 >> ((char)iVar10 - (char)local_104 & 0x1fU);
              uVar18 = local_bc[local_fc + 0x20];
              local_dc = ((int)(local_d4 - uVar18) >> 3) - uVar11;
              *(undefined4 *)(uVar18 + uVar11 * 8) = local_e0;
              *(uint *)(uVar18 + 4 + uVar11 * 8) = local_dc;
            }
            uVar18 = local_f0;
            local_fc = local_fc + 1;
            uVar1 = local_e0;
            uVar2 = local_e0._2_2_;
          }
          bVar14 = (byte)iVar10;
          if (local_f8 < param_8 + uVar9) {
            local_dc = *local_f8;
            if (local_dc < param_1) {
              local_e0._0_1_ = (-(local_dc < 0x100) & 0xa0U) + 0x60;
            }
            else {
              iVar16 = (local_dc - param_1) * 4;
              local_e0._0_1_ = *(char *)(iVar16 + param_3) + 'P';
              local_dc = *(uint *)(iVar16 + param_2);
            }
            local_f8 = local_f8 + 1;
          }
          else {
            local_e0._0_1_ = -0x40;
          }
          local_e0 = CONCAT31(CONCAT21(uVar2,(char)local_100 - bVar14),(char)local_e0);
          iVar16 = 1 << ((char)local_100 - bVar14 & 0x1f);
          uVar6 = uVar18 >> (bVar14 & 0x1f);
          if (uVar6 < local_d8) {
            puVar12 = (undefined4 *)(local_d4 + uVar6 * 8);
            do {
              uVar6 = uVar6 + iVar16;
              *puVar12 = local_e0;
              puVar12[1] = local_dc;
              puVar12 = puVar12 + iVar16 * 2;
            } while (uVar6 < local_d8);
          }
          uVar11 = 1 << ((byte)local_f4 & 0x1f);
          uVar6 = uVar18 & uVar11;
          while (uVar6 != 0) {
            uVar18 = uVar18 ^ uVar11;
            uVar11 = uVar11 >> 1;
            uVar6 = uVar18 & uVar11;
          }
          uVar18 = uVar18 ^ uVar11;
          puVar7 = local_bc + local_fc + 0x10;
          uVar6 = uVar13;
          local_f0 = uVar18;
          uVar1 = local_e0;
          if (((1 << (bVar14 & 0x1f)) - 1U & uVar18) != local_bc[local_fc + 0x10]) {
            do {
              local_fc = local_fc + -1;
              iVar10 = iVar10 - local_104;
              puVar7 = puVar7 + -1;
            } while (((1 << ((byte)iVar10 & 0x1f)) - 1U & uVar18) != *puVar7);
          }
        }
        local_e8 = local_e8 + 1;
        local_100 = local_100 + 1;
        local_f4 = local_f4 + 1;
        local_e0 = uVar1;
      } while ((int)local_100 <= (int)uVar15);
    }
    if ((iVar17 != 0) && (uVar15 != 1)) {
      return 0xfffffffb;
    }
  }
  return 0;
}
