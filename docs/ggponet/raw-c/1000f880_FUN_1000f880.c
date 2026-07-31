
void FUN_1000f880(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  int *in_EDX;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  byte *pbVar10;
  uint local_18;
  uint local_10;
  undefined1 *local_c;
  byte *local_8;
  
  local_10 = in_EDX[1];
  local_18 = *(uint *)(in_ECX + 0x20);
  piVar2 = *(int **)(in_ECX + 4);
  pbVar10 = (byte *)*in_EDX;
  uVar9 = *(uint *)(in_ECX + 0x1c);
  puVar8 = *(undefined1 **)(in_ECX + 0x34);
  if (puVar8 < *(undefined1 **)(in_ECX + 0x30)) {
    local_c = *(undefined1 **)(in_ECX + 0x30) + (-1 - (int)puVar8);
  }
  else {
    local_c = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar8);
  }
  do {
    switch(*piVar2) {
    case 0:
      if (((undefined1 *)0x101 < local_c) && (9 < local_10)) {
        *(uint *)(in_ECX + 0x20) = local_18;
        *(uint *)(in_ECX + 0x1c) = uVar9;
        iVar6 = *in_EDX;
        in_EDX[1] = local_10;
        *in_EDX = (int)pbVar10;
        in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
        *(undefined1 **)(in_ECX + 0x34) = puVar8;
        param_1 = FUN_10010880(piVar2[5],piVar2[6],in_ECX,in_EDX);
        local_10 = in_EDX[1];
        local_18 = *(uint *)(in_ECX + 0x20);
        pbVar10 = (byte *)*in_EDX;
        uVar9 = *(uint *)(in_ECX + 0x1c);
        puVar8 = *(undefined1 **)(in_ECX + 0x34);
        if (puVar8 < *(undefined1 **)(in_ECX + 0x30)) {
          local_c = *(undefined1 **)(in_ECX + 0x30) + (-1 - (int)puVar8);
        }
        else {
          local_c = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar8);
        }
        if (param_1 != 0) {
          *piVar2 = (-(uint)(param_1 != 1) & 2) + 7;
          break;
        }
      }
      *piVar2 = 1;
      piVar2[3] = (uint)*(byte *)(piVar2 + 4);
      piVar2[2] = piVar2[5];
    case 1:
      for (; uVar9 < (uint)piVar2[3]; uVar9 = uVar9 + 8) {
        if (local_10 == 0) {
LAB_1000fe1d:
          *(uint *)(in_ECX + 0x1c) = uVar9;
          *(uint *)(in_ECX + 0x20) = local_18;
          iVar6 = *in_EDX;
          in_EDX[1] = 0;
          *in_EDX = (int)pbVar10;
          in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
          *(undefined1 **)(in_ECX + 0x34) = puVar8;
          FUN_10010730(param_1);
          return;
        }
        local_10 = local_10 - 1;
        param_1 = 0;
        local_18 = local_18 | (uint)*pbVar10 << ((byte)uVar9 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10037400 + piVar2[3] * 4) & local_18) * 8);
      local_18 = local_18 >> (local_8[1] & 0x1f);
      uVar9 = uVar9 - local_8[1];
      bVar1 = *local_8;
      uVar5 = (uint)bVar1;
      if (uVar5 == 0) {
        piVar2[2] = *(int *)(local_8 + 4);
        *piVar2 = 6;
      }
      else if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) {
LAB_1000fa4b:
          piVar2[3] = uVar5;
          piVar2[2] = (int)(local_8 + *(int *)(local_8 + 4) * 8);
        }
        else {
          if ((bVar1 & 0x20) == 0) {
            *piVar2 = 9;
            in_EDX[6] = (int)s_invalid_literal_length_code_100361e8;
LAB_1000fe6a:
            *(uint *)(in_ECX + 0x20) = local_18;
            *(uint *)(in_ECX + 0x1c) = uVar9;
            in_EDX[1] = local_10;
            iVar6 = *in_EDX;
            *in_EDX = (int)pbVar10;
            in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
            *(undefined1 **)(in_ECX + 0x34) = puVar8;
            FUN_10010730(0xfffffffd);
            return;
          }
          *piVar2 = 7;
        }
      }
      else {
        piVar2[2] = bVar1 & 0xf;
        iVar6 = *(int *)(local_8 + 4);
        *piVar2 = 2;
        piVar2[1] = iVar6;
      }
      break;
    case 2:
      uVar5 = piVar2[2];
      for (; uVar9 < uVar5; uVar9 = uVar9 + 8) {
        if (local_10 == 0) goto LAB_1000fe1d;
        local_10 = local_10 - 1;
        param_1 = 0;
        local_18 = local_18 | (uint)*pbVar10 << ((byte)uVar9 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      piVar2[1] = piVar2[1] + (*(uint *)(&DAT_10037400 + uVar5 * 4) & local_18);
      local_18 = local_18 >> ((byte)uVar5 & 0x1f);
      uVar9 = uVar9 - uVar5;
      *piVar2 = 3;
      piVar2[3] = (uint)*(byte *)((int)piVar2 + 0x11);
      piVar2[2] = piVar2[6];
    case 3:
      for (; uVar9 < (uint)piVar2[3]; uVar9 = uVar9 + 8) {
        if (local_10 == 0) goto LAB_1000fe1d;
        local_10 = local_10 - 1;
        param_1 = 0;
        local_18 = local_18 | (uint)*pbVar10 << ((byte)uVar9 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      local_8 = (byte *)(piVar2[2] + (*(uint *)(&DAT_10037400 + piVar2[3] * 4) & local_18) * 8);
      local_18 = local_18 >> (local_8[1] & 0x1f);
      uVar9 = uVar9 - local_8[1];
      bVar1 = *local_8;
      uVar5 = (uint)bVar1;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *piVar2 = 9;
          in_EDX[6] = (int)s_invalid_distance_code_100361d0;
          goto LAB_1000fe6a;
        }
        goto LAB_1000fa4b;
      }
      piVar2[2] = bVar1 & 0xf;
      iVar6 = *(int *)(local_8 + 4);
      *piVar2 = 4;
      piVar2[3] = iVar6;
      break;
    case 4:
      uVar5 = piVar2[2];
      for (; uVar9 < uVar5; uVar9 = uVar9 + 8) {
        if (local_10 == 0) goto LAB_1000fe1d;
        local_10 = local_10 - 1;
        param_1 = 0;
        local_18 = local_18 | (uint)*pbVar10 << ((byte)uVar9 & 0x1f);
        pbVar10 = pbVar10 + 1;
      }
      piVar2[3] = piVar2[3] + (*(uint *)(&DAT_10037400 + uVar5 * 4) & local_18);
      local_18 = local_18 >> ((byte)uVar5 & 0x1f);
      uVar9 = uVar9 - uVar5;
      *piVar2 = 5;
    case 5:
      local_8 = puVar8 + -piVar2[3];
      if (local_8 < *(undefined1 **)(in_ECX + 0x28)) {
        do {
          local_8 = local_8 + (*(int *)(in_ECX + 0x2c) - (int)*(undefined1 **)(in_ECX + 0x28));
        } while (local_8 < *(undefined1 **)(in_ECX + 0x28));
      }
      iVar6 = piVar2[1];
      while (iVar6 != 0) {
        puVar7 = puVar8;
        if (local_c == (undefined1 *)0x0) {
          if (puVar8 == *(undefined1 **)(in_ECX + 0x2c)) {
            local_c = *(undefined1 **)(in_ECX + 0x30);
            puVar7 = *(undefined1 **)(in_ECX + 0x28);
            if (local_c != puVar7) {
              if (puVar7 < local_c) {
                local_c = local_c + (-1 - (int)puVar7);
              }
              else {
                local_c = *(undefined1 **)(in_ECX + 0x2c) + -(int)puVar7;
              }
              puVar8 = puVar7;
              if (local_c != (undefined1 *)0x0) goto LAB_1000fd00;
            }
          }
          *(undefined1 **)(in_ECX + 0x34) = puVar8;
          param_1 = FUN_10010730(param_1);
          puVar7 = *(undefined1 **)(in_ECX + 0x34);
          puVar8 = *(undefined1 **)(in_ECX + 0x30);
          if (puVar7 < puVar8) {
            local_c = puVar8 + (-1 - (int)puVar7);
          }
          else {
            local_c = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
          }
          if ((puVar7 == *(undefined1 **)(in_ECX + 0x2c)) &&
             (puVar3 = *(undefined1 **)(in_ECX + 0x28), puVar8 != puVar3)) {
            puVar7 = puVar3;
            if (puVar3 < puVar8) {
              local_c = puVar8 + (-1 - (int)puVar3);
            }
            else {
              local_c = *(undefined1 **)(in_ECX + 0x2c) + -(int)puVar3;
            }
          }
          if (local_c == (undefined1 *)0x0) goto LAB_1000fea3;
        }
LAB_1000fd00:
        puVar8 = puVar7 + 1;
        param_1 = 0;
        *puVar7 = *local_8;
        local_8 = local_8 + 1;
        local_c = local_c + -1;
        if (local_8 == *(undefined1 **)(in_ECX + 0x2c)) {
          local_8 = *(byte **)(in_ECX + 0x28);
        }
        iVar6 = piVar2[1] + -1;
        piVar2[1] = iVar6;
      }
      *piVar2 = 0;
      break;
    case 6:
      puVar7 = puVar8;
      if (local_c == (undefined1 *)0x0) {
        if (puVar8 == *(undefined1 **)(in_ECX + 0x2c)) {
          local_c = *(undefined1 **)(in_ECX + 0x30);
          puVar7 = *(undefined1 **)(in_ECX + 0x28);
          if (local_c != puVar7) {
            if (puVar7 < local_c) {
              local_c = local_c + (-1 - (int)puVar7);
            }
            else {
              local_c = *(undefined1 **)(in_ECX + 0x2c) + -(int)puVar7;
            }
            puVar8 = puVar7;
            if (local_c != (undefined1 *)0x0) goto LAB_1000fdec;
          }
        }
        *(undefined1 **)(in_ECX + 0x34) = puVar8;
        param_1 = FUN_10010730(param_1);
        puVar7 = *(undefined1 **)(in_ECX + 0x34);
        puVar8 = *(undefined1 **)(in_ECX + 0x30);
        if (puVar7 < puVar8) {
          local_c = puVar8 + (-1 - (int)puVar7);
        }
        else {
          local_c = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
        }
        if ((puVar7 == *(undefined1 **)(in_ECX + 0x2c)) &&
           (puVar3 = *(undefined1 **)(in_ECX + 0x28), puVar8 != puVar3)) {
          puVar7 = puVar3;
          if (puVar3 < puVar8) {
            local_c = puVar8 + (-1 - (int)puVar3);
          }
          else {
            local_c = *(undefined1 **)(in_ECX + 0x2c) + -(int)puVar3;
          }
        }
        if (local_c == (undefined1 *)0x0) {
LAB_1000fea3:
          *(uint *)(in_ECX + 0x20) = local_18;
          *(uint *)(in_ECX + 0x1c) = uVar9;
          iVar6 = *in_EDX;
          in_EDX[1] = local_10;
          *in_EDX = (int)pbVar10;
          in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
          *(undefined1 **)(in_ECX + 0x34) = puVar7;
          FUN_10010730(param_1);
          return;
        }
      }
LAB_1000fdec:
      param_1 = 0;
      *puVar7 = (char)piVar2[2];
      puVar8 = puVar7 + 1;
      local_c = local_c + -1;
      *piVar2 = 0;
      break;
    case 7:
      if (7 < uVar9) {
        uVar9 = uVar9 - 8;
        local_10 = local_10 + 1;
        pbVar10 = pbVar10 + -1;
      }
      *(undefined1 **)(in_ECX + 0x34) = puVar8;
      uVar4 = FUN_10010730(param_1);
      puVar8 = *(undefined1 **)(in_ECX + 0x34);
      if (*(undefined1 **)(in_ECX + 0x30) != puVar8) {
        *(uint *)(in_ECX + 0x1c) = uVar9;
        *(uint *)(in_ECX + 0x20) = local_18;
        iVar6 = *in_EDX;
        in_EDX[1] = local_10;
        *in_EDX = (int)pbVar10;
        in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
        *(undefined1 **)(in_ECX + 0x34) = puVar8;
        FUN_10010730(uVar4);
        return;
      }
      *piVar2 = 8;
    case 8:
      goto switchD_1000f8c8_caseD_8;
    case 9:
      *(uint *)(in_ECX + 0x20) = local_18;
      *(uint *)(in_ECX + 0x1c) = uVar9;
      iVar6 = *in_EDX;
      in_EDX[1] = local_10;
      *in_EDX = (int)pbVar10;
      in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
      *(undefined1 **)(in_ECX + 0x34) = puVar8;
      FUN_10010730(0xfffffffd);
      return;
    default:
      *(uint *)(in_ECX + 0x20) = local_18;
      *(uint *)(in_ECX + 0x1c) = uVar9;
      in_EDX[1] = local_10;
      iVar6 = *in_EDX;
      *in_EDX = (int)pbVar10;
      in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
      *(undefined1 **)(in_ECX + 0x34) = puVar8;
      FUN_10010730(0xfffffffe);
      return;
    }
  } while( true );
switchD_1000f8c8_caseD_8:
  *(uint *)(in_ECX + 0x20) = local_18;
  *(uint *)(in_ECX + 0x1c) = uVar9;
  in_EDX[1] = local_10;
  iVar6 = *in_EDX;
  *in_EDX = (int)pbVar10;
  in_EDX[2] = (int)(pbVar10 + (in_EDX[2] - iVar6));
  *(undefined1 **)(in_ECX + 0x34) = puVar8;
  FUN_10010730(1);
  return;
}
