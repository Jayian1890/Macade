
undefined4 FUN_10010880(int param_1,int param_2,int param_3,int *param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int in_EDX;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  uint local_1c;
  byte *local_18;
  byte *local_10;
  uint local_c;
  
  pbVar9 = (byte *)*param_4;
  local_1c = param_4[1];
  pbVar12 = *(byte **)(param_3 + 0x34);
  uVar13 = *(uint *)(param_3 + 0x20);
  uVar3 = *(uint *)(param_3 + 0x1c);
  if (pbVar12 < *(byte **)(param_3 + 0x30)) {
    local_18 = *(byte **)(param_3 + 0x30) + (-1 - (int)pbVar12);
  }
  else {
    local_18 = (byte *)(*(int *)(param_3 + 0x2c) - (int)pbVar12);
  }
  uVar7 = *(uint *)(&DAT_10037400 + in_EDX * 4);
  uVar2 = *(uint *)(&DAT_10037400 + in_ECX * 4);
  local_10 = pbVar9;
  do {
    for (; uVar3 < 0x14; uVar3 = uVar3 + 8) {
      local_1c = local_1c - 1;
      uVar13 = uVar13 | (uint)*pbVar9 << ((byte)uVar3 & 0x1f);
      pbVar9 = pbVar9 + 1;
      local_10 = pbVar9;
    }
    pbVar6 = (byte *)(param_1 + (uVar2 & uVar13) * 8);
    bVar1 = *pbVar6;
    uVar8 = (uint)bVar1;
    if (uVar8 == 0) {
LAB_10010ad7:
      uVar13 = uVar13 >> (pbVar6[1] & 0x1f);
      uVar3 = uVar3 - pbVar6[1];
      *pbVar12 = pbVar6[4];
      pbVar12 = pbVar12 + 1;
      local_18 = local_18 + -1;
    }
    else {
      uVar13 = uVar13 >> (pbVar6[1] & 0x1f);
      uVar3 = uVar3 - pbVar6[1];
      while ((bVar1 & 0x10) == 0) {
        if ((uVar8 & 0x40) != 0) {
          if ((uVar8 & 0x20) != 0) {
            uVar7 = param_4[1] - local_1c;
            if (uVar3 >> 3 < param_4[1] - local_1c) {
              uVar7 = uVar3 >> 3;
            }
            *(uint *)(param_3 + 0x20) = uVar13;
            *(uint *)(param_3 + 0x1c) = uVar3 + uVar7 * -8;
            iVar5 = *param_4;
            param_4[1] = uVar7 + local_1c;
            *param_4 = (int)pbVar9 - uVar7;
            param_4[2] = param_4[2] + (((int)pbVar9 - uVar7) - iVar5);
            *(byte **)(param_3 + 0x34) = pbVar12;
            return 1;
          }
          param_4[6] = (int)s_invalid_literal_length_code_100361e8;
          local_c = uVar3 >> 3;
          uVar7 = param_4[1] - local_1c;
          if (param_4[1] - local_1c <= local_c) goto LAB_10010c0b;
          goto LAB_10010c0f;
        }
        pbVar6 = pbVar6 + ((*(uint *)(&DAT_10037400 + uVar8 * 4) & uVar13) + *(int *)(pbVar6 + 4)) *
                          8;
        bVar1 = *pbVar6;
        uVar8 = (uint)bVar1;
        if (uVar8 == 0) goto LAB_10010ad7;
        uVar13 = uVar13 >> (pbVar6[1] & 0x1f);
        uVar3 = uVar3 - pbVar6[1];
      }
      uVar8 = uVar8 & 0xf;
      uVar4 = (*(uint *)(&DAT_10037400 + uVar8 * 4) & uVar13) + *(int *)(pbVar6 + 4);
      uVar13 = uVar13 >> (sbyte)uVar8;
      for (uVar3 = uVar3 - uVar8; uVar3 < 0xf; uVar3 = uVar3 + 8) {
        local_1c = local_1c - 1;
        uVar13 = uVar13 | (uint)*pbVar9 << ((byte)uVar3 & 0x1f);
        pbVar9 = pbVar9 + 1;
        local_10 = pbVar9;
      }
      pbVar6 = (byte *)(param_2 + (uVar7 & uVar13) * 8);
      uVar13 = uVar13 >> (pbVar6[1] & 0x1f);
      uVar3 = uVar3 - pbVar6[1];
      bVar1 = *pbVar6;
      while ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          param_4[6] = (int)s_invalid_distance_code_100361d0;
          local_c = uVar3 >> 3;
          uVar7 = param_4[1] - local_1c;
          if (param_4[1] - local_1c <= local_c) {
LAB_10010c0b:
            local_c = uVar7;
          }
LAB_10010c0f:
          *(uint *)(param_3 + 0x20) = uVar13;
          *(uint *)(param_3 + 0x1c) = uVar3 + local_c * -8;
          iVar5 = *param_4;
          param_4[1] = local_c + local_1c;
          *param_4 = (int)pbVar9 - local_c;
          param_4[2] = param_4[2] + (((int)pbVar9 - local_c) - iVar5);
          *(byte **)(param_3 + 0x34) = pbVar12;
          return 0xfffffffd;
        }
        iVar5 = (*(uint *)(&DAT_10037400 + (uint)bVar1 * 4) & uVar13) + *(int *)(pbVar6 + 4);
        pbVar10 = pbVar6 + iVar5 * 8;
        pbVar6 = pbVar6 + iVar5 * 8;
        uVar13 = uVar13 >> (pbVar6[1] & 0x1f);
        uVar3 = uVar3 - pbVar6[1];
        bVar1 = *pbVar10;
      }
      uVar8 = bVar1 & 0xf;
      pbVar10 = pbVar9;
      pbVar9 = local_10;
      for (; uVar3 < uVar8; uVar3 = uVar3 + 8) {
        local_1c = local_1c - 1;
        uVar13 = uVar13 | (uint)*pbVar10 << ((byte)uVar3 & 0x1f);
        pbVar10 = pbVar9 + 1;
        pbVar9 = pbVar10;
      }
      uVar11 = *(uint *)(&DAT_10037400 + uVar8 * 4) & uVar13;
      uVar13 = uVar13 >> (sbyte)uVar8;
      uVar3 = uVar3 - uVar8;
      local_18 = local_18 + -uVar4;
      pbVar10 = pbVar12 + -(uVar11 + *(int *)(pbVar6 + 4));
      pbVar6 = *(byte **)(param_3 + 0x28);
      local_10 = pbVar9;
      if (pbVar10 < pbVar6) {
        do {
          pbVar10 = pbVar10 + (*(int *)(param_3 + 0x2c) - (int)pbVar6);
        } while (pbVar10 < pbVar6);
        uVar8 = *(int *)(param_3 + 0x2c) - (int)pbVar10;
        if (uVar8 < uVar4) {
          iVar5 = uVar4 - uVar8;
          do {
            *pbVar12 = *pbVar10;
            pbVar12 = pbVar12 + 1;
            pbVar10 = pbVar10 + 1;
            uVar8 = uVar8 - 1;
          } while (uVar8 != 0);
          pbVar6 = *(byte **)(param_3 + 0x28);
          do {
            *pbVar12 = *pbVar6;
            pbVar12 = pbVar12 + 1;
            pbVar6 = pbVar6 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        else {
          *pbVar12 = *pbVar10;
          pbVar12[1] = pbVar10[1];
          pbVar12 = pbVar12 + 2;
          pbVar10 = pbVar10 + 2;
          iVar5 = uVar4 - 2;
          do {
            *pbVar12 = *pbVar10;
            pbVar12 = pbVar12 + 1;
            pbVar10 = pbVar10 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      else {
        *pbVar12 = *pbVar10;
        pbVar12[1] = pbVar10[1];
        pbVar12 = pbVar12 + 2;
        pbVar10 = pbVar10 + 2;
        iVar5 = uVar4 - 2;
        do {
          *pbVar12 = *pbVar10;
          pbVar12 = pbVar12 + 1;
          pbVar10 = pbVar10 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
    if ((local_18 < (byte *)0x102) || (local_1c < 10)) {
      uVar7 = param_4[1] - local_1c;
      if (uVar3 >> 3 < param_4[1] - local_1c) {
        uVar7 = uVar3 >> 3;
      }
      *(uint *)(param_3 + 0x20) = uVar13;
      *(uint *)(param_3 + 0x1c) = uVar3 + uVar7 * -8;
      iVar5 = *param_4;
      param_4[1] = uVar7 + local_1c;
      *param_4 = (int)pbVar9 - uVar7;
      param_4[2] = param_4[2] + (((int)pbVar9 - uVar7) - iVar5);
      *(byte **)(param_3 + 0x34) = pbVar12;
      return 0;
    }
  } while( true );
}
