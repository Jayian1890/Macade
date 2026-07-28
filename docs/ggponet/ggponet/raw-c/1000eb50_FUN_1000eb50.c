
void FUN_1000eb50(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  int iVar5;
  uint *in_ECX;
  undefined4 uVar6;
  int *in_EDX;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  byte *local_38;
  byte *local_34;
  byte *local_30;
  uint local_2c;
  byte *local_24;
  byte *pbStack_20;
  undefined4 uStack_1c;
  undefined4 auStack_18 [3];
  uint uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_38 = (byte *)*in_EDX;
  local_34 = (byte *)in_EDX[1];
  local_2c = in_ECX[8];
  local_30 = (byte *)in_ECX[0xd];
  pbVar7 = (byte *)in_ECX[7];
  if (local_30 < (byte *)in_ECX[0xc]) {
    local_24 = (byte *)in_ECX[0xc] + (-1 - (int)local_30);
  }
  else {
    local_24 = (byte *)(in_ECX[0xb] - (int)local_30);
  }
switchD_1000ebff_default:
  uVar10 = local_2c;
  switch(*in_ECX) {
  case 0:
    goto switchD_1000eb9b_caseD_0;
  case 1:
    for (; pbVar7 < (byte *)0x20; pbVar7 = pbVar7 + 8) {
      if (local_34 == (byte *)0x0) {
        in_ECX[8] = local_2c;
        in_ECX[7] = (uint)pbVar7;
        iVar5 = *in_EDX;
        in_EDX[1] = 0;
        *in_EDX = (int)local_38;
        in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
        in_ECX[0xd] = (uint)local_30;
        FUN_10010730(param_1);
        return;
      }
      param_1 = 0;
      local_34 = local_34 + -1;
      local_2c = local_2c | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
      local_38 = local_38 + 1;
    }
    uVar10 = local_2c & 0xffff;
    if (~local_2c >> 0x10 != uVar10) {
      *in_ECX = 9;
      in_EDX[6] = (int)s_invalid_stored_block_lengths_1003619c;
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      in_EDX[1] = (int)local_34;
      goto LAB_1000f769;
    }
    pbVar7 = (byte *)0x0;
    in_ECX[1] = uVar10;
    local_2c = 0;
    if (uVar10 != 0) {
      *in_ECX = 2;
      goto switchD_1000ebff_default;
    }
    break;
  case 2:
    if (local_34 == (byte *)0x0) {
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      iVar5 = *in_EDX;
      *in_EDX = (int)local_38;
      in_EDX[1] = 0;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(param_1);
      return;
    }
    if (local_24 == (byte *)0x0) {
      if (local_30 == (byte *)in_ECX[0xb]) {
        pbVar3 = (byte *)in_ECX[0xc];
        pbVar8 = (byte *)in_ECX[10];
        if (pbVar3 != pbVar8) {
          if (pbVar8 < pbVar3) {
            local_24 = pbVar3 + (-1 - (int)pbVar8);
          }
          else {
            local_24 = (byte *)in_ECX[0xb] + -(int)pbVar8;
          }
          local_30 = pbVar8;
          if (local_24 != (byte *)0x0) goto LAB_1000edba;
        }
      }
      in_ECX[0xd] = (uint)local_30;
      uVar6 = FUN_10010730(param_1);
      local_30 = (byte *)in_ECX[0xd];
      pbVar3 = (byte *)in_ECX[0xc];
      if (local_30 < pbVar3) {
        local_24 = pbVar3 + (-1 - (int)local_30);
      }
      else {
        local_24 = (byte *)(in_ECX[0xb] - (int)local_30);
      }
      pbStack_20 = (byte *)in_ECX[0xb];
      if ((local_30 == pbStack_20) && (pbVar8 = (byte *)in_ECX[10], pbVar3 != pbVar8)) {
        local_30 = pbVar8;
        if (pbVar8 < pbVar3) {
          local_24 = pbVar3 + (-1 - (int)pbVar8);
        }
        else {
          local_24 = pbStack_20 + -(int)pbVar8;
        }
      }
      if (local_24 == (byte *)0x0) {
        in_ECX[8] = local_2c;
        in_ECX[7] = (uint)pbVar7;
        iVar5 = *in_EDX;
        in_EDX[1] = (int)local_34;
        *in_EDX = (int)local_38;
        in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
        in_ECX[0xd] = (uint)local_30;
        FUN_10010730(uVar6);
        return;
      }
    }
LAB_1000edba:
    param_1 = 0;
    pbVar3 = (byte *)in_ECX[1];
    if (local_34 < (byte *)in_ECX[1]) {
      pbVar3 = local_34;
    }
    if (local_24 < pbVar3) {
      pbVar3 = local_24;
    }
    pbVar8 = local_38;
    pbVar9 = local_30;
    for (uVar10 = (uint)pbVar3 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pbVar9 = *(undefined4 *)pbVar8;
      pbVar8 = pbVar8 + 4;
      pbVar9 = pbVar9 + 4;
    }
    local_24 = local_24 + -(int)pbVar3;
    for (uVar10 = (uint)pbVar3 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pbVar9 = *pbVar8;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    }
    local_38 = local_38 + (int)pbVar3;
    uVar10 = in_ECX[1];
    local_34 = local_34 + -(int)pbVar3;
    local_30 = local_30 + (int)pbVar3;
    in_ECX[1] = uVar10 - (int)pbVar3;
    if (uVar10 - (int)pbVar3 != 0) goto switchD_1000ebff_default;
    break;
  case 3:
    for (; pbVar7 < (byte *)0xe; pbVar7 = pbVar7 + 8) {
      if (local_34 == (byte *)0x0) {
        in_ECX[8] = local_2c;
        in_ECX[7] = (uint)pbVar7;
        iVar5 = *in_EDX;
        *in_EDX = (int)local_38;
        in_EDX[1] = 0;
        in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
        in_ECX[0xd] = (uint)local_30;
        FUN_10010730(param_1);
        return;
      }
      local_34 = local_34 + -1;
      param_1 = 0;
      local_2c = local_2c | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
      local_38 = local_38 + 1;
    }
    in_ECX[1] = local_2c & 0x3fff;
    if ((0x1d < (local_2c & 0x1f)) || (0x3a0 < (local_2c & 0x3e0))) {
      *in_ECX = 9;
      in_EDX[6] = (int)s_too_many_length_or_distance_symb_10036178;
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      goto LAB_1000f762;
    }
    uVar10 = (*(code *)in_EDX[8])(4);
    in_ECX[3] = uVar10;
    if (uVar10 == 0) {
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      iVar5 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(0xfffffffc);
      return;
    }
    local_2c = local_2c >> 0xe;
    pbVar7 = pbVar7 + -0xe;
    in_ECX[2] = 0;
    *in_ECX = 4;
    goto LAB_1000eedc;
  case 4:
LAB_1000eedc:
    if (in_ECX[2] < (in_ECX[1] >> 10) + 4) {
      do {
        for (; pbVar7 < (byte *)0x3; pbVar7 = pbVar7 + 8) {
          if (local_34 == (byte *)0x0) {
            in_ECX[8] = local_2c;
            in_ECX[7] = (uint)pbVar7;
            iVar5 = *in_EDX;
            *in_EDX = (int)local_38;
            in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
            in_EDX[1] = 0;
            in_ECX[0xd] = (uint)local_30;
            FUN_10010730(param_1);
            return;
          }
          local_34 = local_34 + -1;
          param_1 = 0;
          local_2c = local_2c | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
          local_38 = local_38 + 1;
        }
        uVar10 = local_2c & 7;
        pbVar7 = pbVar7 + -3;
        local_2c = local_2c >> 3;
        *(uint *)(in_ECX[3] + *(int *)(&DAT_1002ece4 + in_ECX[2] * 4) * 4) = uVar10;
        uVar10 = in_ECX[2];
        in_ECX[2] = uVar10 + 1;
      } while (uVar10 + 1 < (in_ECX[1] >> 10) + 4);
    }
    uVar10 = in_ECX[2];
    while (uVar10 < 0x13) {
      *(undefined4 *)(in_ECX[3] + *(int *)(&DAT_1002ece4 + in_ECX[2] * 4) * 4) = 0;
      uVar10 = in_ECX[2] + 1;
      in_ECX[2] = uVar10;
    }
    in_ECX[4] = 7;
    iVar5 = FUN_10010040(in_ECX + 5,in_ECX[9],in_EDX);
    if (iVar5 != 0) {
      if (iVar5 == -3) {
        (*(code *)in_EDX[9])();
        *in_ECX = 9;
      }
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      iVar2 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar2));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(iVar5);
      return;
    }
    in_ECX[2] = 0;
    *in_ECX = 5;
    uVar10 = local_2c;
LAB_1000efc0:
    if (in_ECX[2] < (in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f)) {
      do {
        for (; pbVar7 < (byte *)in_ECX[4]; pbVar7 = pbVar7 + 8) {
          if (local_34 == (byte *)0x0) goto LAB_1000f576;
          local_34 = local_34 + -1;
          param_1 = 0;
          uVar10 = uVar10 | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
          local_38 = local_38 + 1;
        }
        bVar1 = *(byte *)(in_ECX[5] + 1 +
                         (*(uint *)(&DAT_10037400 + (int)in_ECX[4] * 4) & uVar10) * 8);
        uVar4 = (uint)bVar1;
        uStack_c = *(uint *)(in_ECX[5] +
                             (*(uint *)(&DAT_10037400 + (int)in_ECX[4] * 4) & uVar10) * 8 + 4);
        if (uStack_c < 0x10) {
          pbVar7 = pbVar7 + -uVar4;
          uVar10 = uVar10 >> (bVar1 & 0x1f);
          *(uint *)(in_ECX[3] + in_ECX[2] * 4) = uStack_c;
          pbVar3 = (byte *)(in_ECX[2] + 1);
        }
        else {
          local_24 = (byte *)0x7;
          if (uStack_c != 0x12) {
            local_24 = (byte *)(uStack_c - 0xe);
          }
          pbStack_20 = local_24 + uVar4;
          for (; pbVar7 < pbStack_20; pbVar7 = pbVar7 + 8) {
            if (local_34 == (byte *)0x0) {
LAB_1000f576:
              in_ECX[8] = uVar10;
              in_ECX[7] = (uint)pbVar7;
              iVar5 = *in_EDX;
              *in_EDX = (int)local_38;
              in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
              in_EDX[1] = 0;
              in_ECX[0xd] = (uint)local_30;
              FUN_10010730(param_1);
              return;
            }
            local_34 = local_34 + -1;
            param_1 = 0;
            uVar10 = uVar10 | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
            local_38 = local_38 + 1;
          }
          uVar10 = uVar10 >> (bVar1 & 0x1f);
          local_2c = (-(uint)(uStack_c != 0x12) & 0xfffffff8) + 0xb +
                     (*(uint *)(&DAT_10037400 + (int)local_24 * 4) & uVar10);
          uVar10 = uVar10 >> ((byte)local_24 & 0x1f);
          pbVar7 = pbVar7 + -(int)(local_24 + uVar4);
          local_24 = (byte *)in_ECX[2];
          if ((byte *)((in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f)) < local_24 + local_2c)
          {
LAB_1000f5b6:
            (*(code *)in_EDX[9])();
            *in_ECX = 9;
            in_EDX[6] = (int)s_invalid_bit_length_repeat_1003615c;
            in_ECX[8] = uVar10;
            in_ECX[7] = (uint)pbVar7;
            iVar5 = *in_EDX;
            in_EDX[1] = (int)local_34;
            *in_EDX = (int)local_38;
            in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
            in_ECX[0xd] = (uint)local_30;
            FUN_10010730(0xfffffffd);
            return;
          }
          pbVar3 = local_24;
          if (uStack_c == 0x10) {
            if (local_24 == (byte *)0x0) goto LAB_1000f5b6;
            uVar6 = *(undefined4 *)((in_ECX[3] - 4) + (int)local_24 * 4);
          }
          else {
            uVar6 = 0;
          }
          do {
            pbVar3 = pbVar3 + 1;
            *(undefined4 *)((in_ECX[3] - 4) + (int)pbVar3 * 4) = uVar6;
            local_2c = local_2c + -1;
          } while (local_2c != 0);
        }
        in_ECX[2] = (uint)pbVar3;
      } while (in_ECX[2] < (in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f));
    }
    in_ECX[5] = 0;
    pbStack_20 = (byte *)0x9;
    local_24 = (byte *)0x6;
    iVar5 = FUN_100105a0(in_ECX[3],&pbStack_20,&local_24,&uStack_4,&uStack_8,in_ECX[9],in_EDX);
    if (iVar5 != 0) {
      if (iVar5 == -3) {
        (*(code *)in_EDX[9])();
        *in_ECX = 9;
      }
      in_ECX[8] = uVar10;
      in_ECX[7] = (uint)pbVar7;
      iVar2 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar2));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(iVar5);
      return;
    }
    uVar4 = FUN_1000f840(uStack_4,uStack_8,in_EDX);
    if (uVar4 == 0) {
      in_ECX[8] = uVar10;
      in_ECX[7] = (uint)pbVar7;
      iVar5 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(0xfffffffc);
      return;
    }
    in_ECX[1] = uVar4;
    (*(code *)in_EDX[9])();
    *in_ECX = 6;
LAB_1000f201:
    in_ECX[8] = uVar10;
    in_ECX[7] = (uint)pbVar7;
    iVar5 = *in_EDX;
    in_EDX[1] = (int)local_34;
    *in_EDX = (int)local_38;
    in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
    in_ECX[0xd] = (uint)local_30;
    iVar5 = FUN_1000f880(param_1);
    if (iVar5 == 1) {
      param_1 = 0;
      FUN_10010030();
      local_34 = (byte *)in_EDX[1];
      local_38 = (byte *)*in_EDX;
      local_2c = in_ECX[8];
      pbVar7 = (byte *)in_ECX[7];
      local_30 = (byte *)in_ECX[0xd];
      if (local_30 < (byte *)in_ECX[0xc]) {
        local_24 = (byte *)in_ECX[0xc] + (-1 - (int)local_30);
      }
      else {
        local_24 = (byte *)(in_ECX[0xb] - (int)local_30);
      }
      if (in_ECX[6] == 0) {
        *in_ECX = 0;
        goto switchD_1000ebff_default;
      }
      *in_ECX = 7;
LAB_1000f6b0:
      in_ECX[0xd] = (uint)local_30;
      iVar5 = FUN_10010730(param_1);
      local_30 = (byte *)in_ECX[0xd];
      if ((byte *)in_ECX[0xc] == local_30) {
        *in_ECX = 8;
LAB_1000f717:
        in_ECX[8] = local_2c;
        in_ECX[7] = (uint)pbVar7;
        iVar5 = *in_EDX;
        in_EDX[1] = (int)local_34;
        *in_EDX = (int)local_38;
        in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
        in_ECX[0xd] = (uint)local_30;
        FUN_10010730(1);
        return;
      }
      in_ECX[7] = (uint)pbVar7;
      in_ECX[8] = local_2c;
      iVar2 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar2));
      in_ECX[0xd] = (uint)local_30;
    }
    FUN_10010730(iVar5);
    return;
  case 5:
    goto LAB_1000efc0;
  case 6:
    goto LAB_1000f201;
  case 7:
    goto LAB_1000f6b0;
  case 8:
    goto LAB_1000f717;
  case 9:
    in_ECX[8] = local_2c;
    in_ECX[7] = (uint)pbVar7;
LAB_1000f762:
    in_EDX[1] = (int)local_34;
LAB_1000f769:
    iVar5 = *in_EDX;
    *in_EDX = (int)local_38;
    in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
    in_ECX[0xd] = (uint)local_30;
    FUN_10010730(0xfffffffd);
    return;
  default:
    in_ECX[8] = local_2c;
    in_ECX[7] = (uint)pbVar7;
    iVar5 = *in_EDX;
    in_EDX[1] = (int)local_34;
    *in_EDX = (int)local_38;
    in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
    in_ECX[0xd] = (uint)local_30;
    FUN_10010730(0xfffffffe);
    return;
  }
  *in_ECX = -(uint)(in_ECX[6] != 0) & 7;
  goto switchD_1000ebff_default;
switchD_1000eb9b_caseD_0:
  for (; pbVar7 < (byte *)0x3; pbVar7 = pbVar7 + 8) {
    if (local_34 == (byte *)0x0) {
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      iVar5 = *in_EDX;
      in_EDX[1] = 0;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(param_1);
      return;
    }
    local_34 = local_34 + -1;
    param_1 = 0;
    local_2c = local_2c | (uint)*local_38 << ((byte)pbVar7 & 0x1f);
    local_38 = local_38 + 1;
  }
  in_ECX[6] = local_2c & 1;
  switch((local_2c & 7) >> 1) {
  case 0:
    *in_ECX = 1;
    uVar10 = (uint)(pbVar7 + -3) & 7;
    local_2c = (local_2c >> 3) >> (sbyte)uVar10;
    pbVar7 = pbVar7 + -3 + -uVar10;
    break;
  case 1:
    FUN_10010700(auStack_18,&uStack_1c,in_EDX);
    uVar10 = FUN_1000f840(auStack_18[0],uStack_1c,in_EDX);
    in_ECX[1] = uVar10;
    if (uVar10 == 0) {
      in_ECX[8] = local_2c;
      in_ECX[7] = (uint)pbVar7;
      iVar5 = *in_EDX;
      in_EDX[1] = (int)local_34;
      *in_EDX = (int)local_38;
      in_EDX[2] = (int)(local_38 + (in_EDX[2] - iVar5));
      in_ECX[0xd] = (uint)local_30;
      FUN_10010730(0xfffffffc);
      return;
    }
    local_2c = local_2c >> 3;
    pbVar7 = pbVar7 + -3;
    *in_ECX = 6;
    break;
  case 2:
    local_2c = local_2c >> 3;
    pbVar7 = pbVar7 + -3;
    *in_ECX = 3;
    break;
  case 3:
    *in_ECX = 9;
    in_EDX[6] = (int)s_invalid_block_type_100361bc;
    in_ECX[8] = local_2c >> 3;
    in_ECX[7] = (uint)(pbVar7 + -3);
    in_EDX[1] = (int)local_34;
    in_EDX[2] = (int)(local_38 + (in_EDX[2] - *in_EDX));
    *in_EDX = (int)local_38;
    in_ECX[0xd] = (uint)local_30;
    FUN_10010730(0xfffffffd);
    return;
  }
  goto switchD_1000ebff_default;
}
