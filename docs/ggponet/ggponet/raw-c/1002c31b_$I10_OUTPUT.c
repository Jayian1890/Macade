
/* WARNING: Removing unreachable block (ram,0x1002c856) */
/* WARNING: Removing unreachable block (ram,0x1002c860) */
/* WARNING: Removing unreachable block (ram,0x1002c865) */
/* Library Function - Single Match
    _$I10_OUTPUT
   
   Library: Visual Studio 2008 Release */

void __cdecl
_I10_OUTPUT(int param_1,uint param_2,ushort param_3,int param_4,byte param_5,short *param_6)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  bool bVar4;
  errno_t eVar5;
  uint uVar6;
  ushort uVar7;
  ushort uVar8;
  uint uVar9;
  ushort *puVar10;
  uint uVar11;
  ushort uVar12;
  uint uVar13;
  char cVar14;
  uint uVar15;
  uint uVar16;
  short *psVar17;
  short *psVar18;
  ushort uVar19;
  ushort uVar20;
  short *psVar21;
  int iVar22;
  uint uVar23;
  char *pcVar24;
  ushort *local_70;
  ushort *local_6c;
  char *local_68;
  int local_5c;
  int local_58;
  int local_54;
  short local_50;
  ushort *local_4c;
  int local_48;
  int local_44;
  ushort local_40;
  undefined4 uStack_3e;
  ushort uStack_3a;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined4 local_24;
  undefined4 uStack_20;
  ushort uStack_1c;
  undefined1 local_1a;
  byte bStack_19;
  byte local_14;
  undefined1 uStack_13;
  undefined4 uStack_12;
  undefined4 uStack_e;
  ushort uStack_a;
  uint local_8;
  
  uVar16 = CONCAT22(uStack_20._2_2_,(undefined2)uStack_20);
  uVar6 = CONCAT22(local_24._2_2_,(ushort)local_24);
  iVar22 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
  iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = (byte)param_1;
  uStack_13 = (undefined1)((uint)param_1 >> 8);
  uStack_12._0_2_ = (ushort)((uint)param_1 >> 0x10);
  uStack_12._2_2_ = (ushort)param_2;
  uVar23 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12);
  uStack_e._0_2_ = (ushort)(param_2 >> 0x10);
  uStack_e._2_2_ = param_3;
  uVar9 = CONCAT22(param_3,(ushort)uStack_e);
  uVar11 = CONCAT22(param_3,(ushort)uStack_e);
  uVar7 = param_3 & 0x8000;
  uVar13 = param_3 & 0x7fff;
  local_34 = 0xcccccccc;
  local_30 = 0xcccccccc;
  local_2c._0_1_ = 0xcc;
  local_2c._1_1_ = 0xcc;
  uStack_2a = 0xfb;
  uStack_29 = 0x3f;
  if (uVar7 == 0) {
    *(undefined1 *)(param_6 + 1) = 0x20;
  }
  else {
    *(undefined1 *)(param_6 + 1) = 0x2d;
  }
  if ((((short)uVar13 == 0) && (param_2 == 0)) && (param_1 == 0)) {
    *param_6 = 0;
    *(byte *)(param_6 + 1) = ((uVar7 != 0x8000) - 1U & 0xd) + 0x20;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
    iVar1 = iVar22;
    goto LAB_1002cbf3;
  }
  if ((short)uVar13 == 0x7fff) {
    *param_6 = 1;
    if (((param_2 == 0x80000000) && (param_1 == 0)) || ((param_2 & 0x40000000) != 0)) {
      if ((uVar7 == 0) || (param_2 != 0xc0000000)) {
        if ((param_2 != 0x80000000) || (param_1 != 0)) goto LAB_1002c451;
        pcVar24 = "1#INF";
      }
      else {
        if (param_1 != 0) {
LAB_1002c451:
          pcVar24 = "1#QNAN";
          goto LAB_1002c456;
        }
        pcVar24 = "1#IND";
      }
      eVar5 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar24);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(undefined1 *)((int)param_6 + 3) = 5;
    }
    else {
      pcVar24 = "1#SNAN";
LAB_1002c456:
      eVar5 = _strcpy_s((char *)(param_6 + 2),0x16,pcVar24);
      if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(undefined1 *)((int)param_6 + 3) = 6;
    }
    uVar9 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
    uVar16 = CONCAT22(uStack_20._2_2_,(undefined2)uStack_20);
    uVar6 = CONCAT22(local_24._2_2_,(ushort)local_24);
    iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e);
    goto LAB_1002cbf3;
  }
  local_50 = (short)(((uVar13 >> 8) + (param_2 >> 0x18) * 2) * 0x4d + -0x134312f4 + uVar13 * 0x4d10
                    >> 0x10);
  local_24._0_2_ = 0;
  uVar15 = -(int)local_50;
  local_1a = (undefined1)uVar13;
  bStack_19 = (byte)(uVar13 >> 8);
  uStack_20._2_2_ = uStack_12._2_2_;
  uVar16 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12);
  uStack_1c = (ushort)uStack_e;
  local_24._2_2_ = (ushort)param_1;
  uVar6 = param_1 << 0x10;
  local_68 = s___AUCallbacks_Udp___100386d4 + 0xc;
  if (uVar15 != 0) {
    iVar1 = iVar22;
    uVar23 = uStack_12;
    uVar11 = uVar9;
    uVar6 = param_1 << 0x10;
    uVar16 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12);
    if ((int)uVar15 < 0) {
      local_68 = &DAT_10038840;
      uVar15 = (int)local_50;
    }
joined_r0x1002c4e4:
    if (uVar15 != 0) {
      local_68 = local_68 + 0x54;
      uVar9 = uVar15 & 7;
      uVar15 = (int)uVar15 >> 3;
      if (uVar9 != 0) {
        puVar10 = (ushort *)(local_68 + uVar9 * 0xc);
        if (0x7fff < *puVar10) {
          local_40 = (ushort)*(undefined4 *)puVar10;
          uStack_3e._0_2_ = (undefined2)((uint)*(undefined4 *)puVar10 >> 0x10);
          puVar2 = puVar10 + 4;
          uStack_3e._2_2_ = (undefined2)*(undefined4 *)(puVar10 + 2);
          uStack_3a = (ushort)((uint)*(undefined4 *)(puVar10 + 2) >> 0x10);
          puVar10 = &local_40;
          local_38 = *(int *)puVar2;
          iVar1 = CONCAT22(uStack_3e._2_2_,(undefined2)uStack_3e) + -1;
          uStack_3e._0_2_ = (undefined2)iVar1;
          uStack_3e._2_2_ = (undefined2)((uint)iVar1 >> 0x10);
        }
        local_58 = 0;
        local_14 = 0;
        uStack_13 = 0;
        uStack_12._0_2_ = 0;
        uStack_12._2_2_ = 0;
        uVar23 = 0;
        uStack_e._0_2_ = 0;
        uStack_e._2_2_ = 0;
        uVar11 = 0;
        uStack_a = 0;
        uVar19 = (puVar10[5] ^ CONCAT11(bStack_19,local_1a)) & 0x8000;
        uVar8 = CONCAT11(bStack_19,local_1a) & 0x7fff;
        uVar12 = puVar10[5] & 0x7fff;
        uVar20 = uVar12 + uVar8;
        if (((uVar8 < 0x7fff) && (uVar12 < 0x7fff)) && (uVar20 < 0xbffe)) {
          if (0x3fbf < uVar20) {
            if (((uVar8 == 0) &&
                (uVar20 = uVar20 + 1,
                (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) & 0x7fffffff) == 0)) &&
               ((uVar16 == 0 && (uVar6 == 0)))) {
              local_1a = 0;
              bStack_19 = 0;
              goto joined_r0x1002c4e4;
            }
            if ((((uVar12 != 0) || (uVar20 = uVar20 + 1, (*(uint *)(puVar10 + 4) & 0x7fffffff) != 0)
                 ) || (*(int *)(puVar10 + 2) != 0)) || (*(int *)puVar10 != 0)) {
              local_5c = 0;
              psVar21 = (short *)((int)&uStack_12 + 2);
              local_44 = 5;
              do {
                local_54 = local_44;
                if (0 < local_44) {
                  local_70 = (ushort *)((int)&local_24 + local_5c * 2);
                  local_6c = puVar10 + 4;
                  do {
                    bVar4 = false;
                    uVar11 = *(uint *)(psVar21 + -2) + (uint)*local_70 * (uint)*local_6c;
                    if ((uVar11 < *(uint *)(psVar21 + -2)) ||
                       (uVar11 < (uint)*local_70 * (uint)*local_6c)) {
                      bVar4 = true;
                    }
                    *(uint *)(psVar21 + -2) = uVar11;
                    if (bVar4) {
                      *psVar21 = *psVar21 + 1;
                    }
                    local_70 = local_70 + 1;
                    local_6c = local_6c + -1;
                    local_54 = local_54 + -1;
                  } while (0 < local_54);
                }
                psVar21 = psVar21 + 1;
                local_5c = local_5c + 1;
                local_44 = local_44 + -1;
              } while (0 < local_44);
              uVar20 = uVar20 + 0xc002;
              if ((short)uVar20 < 1) {
LAB_1002c697:
                uVar20 = uVar20 - 1;
                if ((short)uVar20 < 0) {
                  uVar11 = (uint)(ushort)-uVar20;
                  uVar20 = 0;
                  do {
                    if ((local_14 & 1) != 0) {
                      local_58 = local_58 + 1;
                    }
                    iVar3 = CONCAT22(uStack_a,uStack_e._2_2_);
                    uVar23 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                    iVar22 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
                    uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
                    uStack_a = uStack_a >> 1;
                    uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uint)(iVar3 << 0x1f) >> 0x10)
                    ;
                    uVar6 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
                    uStack_12._0_2_ =
                         (ushort)uStack_12 >> 1 | (ushort)((uint)(iVar22 << 0x1f) >> 0x10);
                    uVar11 = uVar11 - 1;
                    uStack_12._2_2_ = (ushort)(uVar23 >> 1);
                    local_14 = (byte)uVar6;
                    uStack_13 = (undefined1)(uVar6 >> 8);
                  } while (uVar11 != 0);
                  if (local_58 != 0) {
                    local_14 = local_14 | 1;
                  }
                }
              }
              else {
                do {
                  uVar12 = (ushort)uStack_e;
                  uVar8 = (ushort)uStack_12;
                  if ((uStack_a & 0x8000) != 0) break;
                  iVar22 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) << 1;
                  local_14 = (byte)iVar22;
                  uStack_13 = (undefined1)((uint)iVar22 >> 8);
                  uStack_12._0_2_ = (ushort)((uint)iVar22 >> 0x10);
                  iVar22 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
                  uStack_12._2_2_ = (ushort)iVar22 | uVar8 >> 0xf;
                  uStack_e._0_2_ = (ushort)((uint)iVar22 >> 0x10);
                  iVar22 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
                  uStack_e._2_2_ = (ushort)iVar22 | uVar12 >> 0xf;
                  uVar20 = uVar20 - 1;
                  uStack_a = (ushort)((uint)iVar22 >> 0x10);
                } while (0 < (short)uVar20);
                if ((short)uVar20 < 1) goto LAB_1002c697;
              }
              if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
                 (uVar11 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e),
                 uVar23 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12),
                 (CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
                if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
                  uStack_12._0_2_ = 0;
                  uStack_12._2_2_ = 0;
                  uVar23 = 0;
                  if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
                    uStack_e._0_2_ = 0;
                    uStack_e._2_2_ = 0;
                    if (uStack_a == 0xffff) {
                      uStack_a = 0x8000;
                      uVar20 = uVar20 + 1;
                      uVar11 = 0;
                      uVar23 = 0;
                    }
                    else {
                      uStack_a = uStack_a + 1;
                      uVar11 = 0;
                      uVar23 = 0;
                    }
                  }
                  else {
                    uVar11 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
                    uStack_e._0_2_ = (ushort)uVar11;
                    uStack_e._2_2_ = (ushort)(uVar11 >> 0x10);
                  }
                }
                else {
                  uVar23 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
                  uStack_12._0_2_ = (ushort)uVar23;
                  uStack_12._2_2_ = (ushort)(uVar23 >> 0x10);
                  uVar11 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
                }
              }
              if (uVar20 < 0x7fff) {
                bStack_19 = (byte)(uVar20 >> 8) | (byte)(uVar19 >> 8);
                local_24 = uVar23;
                uStack_20 = uVar11;
                uStack_1c = uStack_a;
                local_1a = (undefined1)uVar20;
                uVar6 = uVar23;
                uVar16 = uVar11;
              }
              else {
                uStack_20._0_2_ = 0;
                uStack_20._2_2_ = 0;
                local_24._0_2_ = 0;
                local_24._2_2_ = 0;
                iVar22 = ((uVar19 == 0) - 1 & 0x80000000) + 0x7fff8000;
                uStack_1c = (ushort)iVar22;
                local_1a = (undefined1)((uint)iVar22 >> 0x10);
                bStack_19 = (byte)((uint)iVar22 >> 0x18);
                uVar6 = 0;
                uVar16 = 0;
              }
              goto joined_r0x1002c4e4;
            }
          }
          uStack_1c = 0;
          local_1a = 0;
          bStack_19 = 0;
        }
        else {
          iVar22 = ((uVar19 == 0) - 1 & 0x80000000) + 0x7fff8000;
          uStack_1c = (ushort)iVar22;
          local_1a = (undefined1)((uint)iVar22 >> 0x10);
          bStack_19 = (byte)((uint)iVar22 >> 0x18);
        }
        uStack_20._0_2_ = 0;
        uStack_20._2_2_ = 0;
        local_24._0_2_ = 0;
        local_24._2_2_ = 0;
        uVar23 = 0;
        uVar11 = 0;
        uVar6 = 0;
        uVar16 = 0;
      }
      goto joined_r0x1002c4e4;
    }
  }
  uVar13 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
  uStack_12 = uVar23;
  uVar9 = uVar11;
  if (0x3ffe < (ushort)(uVar13 >> 0x10)) {
    local_50 = local_50 + 1;
    local_54 = 0;
    local_14 = 0;
    uStack_13 = 0;
    uStack_12._0_2_ = 0;
    uStack_12._2_2_ = 0;
    uStack_12 = 0;
    uStack_e._0_2_ = 0;
    uStack_e._2_2_ = 0;
    uVar9 = 0;
    uStack_a = 0;
    uVar11 = uVar13 >> 0x10 & 0x7fff;
    iVar22 = uVar11 + 0x3ffb;
    if (((ushort)uVar11 < 0x7fff) && ((ushort)iVar22 < 0xbffe)) {
      if (0x3fbf < (ushort)iVar22) {
        if (((((ushort)uVar11 == 0) &&
             (iVar22 = uVar11 + 0x3ffc,
             (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) & 0x7fffffff) == 0)) && (uVar16 == 0)
            ) && (uVar6 == 0)) {
          local_1a = 0;
          bStack_19 = 0;
          goto LAB_1002ca2b;
        }
        local_5c = 0;
        psVar21 = (short *)((int)&uStack_12 + 2);
        local_44 = 5;
        do {
          local_58 = local_44;
          if (0 < local_44) {
            local_4c = &local_2c;
            puVar10 = (ushort *)((int)&local_24 + local_5c * 2);
            do {
              bVar4 = false;
              uVar11 = *(uint *)(psVar21 + -2) + (uint)*local_4c * (uint)*puVar10;
              if ((uVar11 < *(uint *)(psVar21 + -2)) || (uVar11 < (uint)*local_4c * (uint)*puVar10))
              {
                bVar4 = true;
              }
              *(uint *)(psVar21 + -2) = uVar11;
              if (bVar4) {
                *psVar21 = *psVar21 + 1;
              }
              local_4c = local_4c + -1;
              puVar10 = puVar10 + 1;
              local_58 = local_58 + -1;
            } while (0 < local_58);
          }
          psVar21 = psVar21 + 1;
          local_5c = local_5c + 1;
          local_44 = local_44 + -1;
        } while (0 < local_44);
        iVar22 = iVar22 + 0xc002;
        if ((short)iVar22 < 1) {
LAB_1002c924:
          uVar20 = (ushort)(iVar22 + 0xffff);
          if ((short)uVar20 < 0) {
            uVar11 = -(iVar22 + 0xffff);
            uVar23 = uVar11 & 0xffff;
            uVar20 = uVar20 + (short)uVar11;
            do {
              if ((local_14 & 1) != 0) {
                local_54 = local_54 + 1;
              }
              iVar3 = CONCAT22(uStack_a,uStack_e._2_2_);
              uVar11 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              iVar22 = CONCAT22((ushort)uStack_e,uStack_12._2_2_);
              uStack_e._2_2_ = (ushort)(CONCAT22(uStack_a,uStack_e._2_2_) >> 1);
              uStack_a = uStack_a >> 1;
              uStack_e._0_2_ = (ushort)uStack_e >> 1 | (ushort)((uint)(iVar3 << 0x1f) >> 0x10);
              uVar6 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) >> 1;
              uStack_12._0_2_ = (ushort)uStack_12 >> 1 | (ushort)((uint)(iVar22 << 0x1f) >> 0x10);
              uVar23 = uVar23 - 1;
              uStack_12._2_2_ = (ushort)(uVar11 >> 1);
              local_14 = (byte)uVar6;
              uStack_13 = (undefined1)(uVar6 >> 8);
            } while (uVar23 != 0);
            if (local_54 != 0) {
              local_14 = local_14 | 1;
            }
          }
        }
        else {
          do {
            uVar8 = (ushort)uStack_e;
            uVar20 = (ushort)uStack_12;
            if ((short)uStack_a < 0) break;
            iVar3 = CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) << 1;
            local_14 = (byte)iVar3;
            uStack_13 = (undefined1)((uint)iVar3 >> 8);
            uStack_12._0_2_ = (ushort)((uint)iVar3 >> 0x10);
            iVar3 = CONCAT22((ushort)uStack_e,uStack_12._2_2_) * 2;
            uStack_12._2_2_ = (ushort)iVar3 | uVar20 >> 0xf;
            uStack_e._0_2_ = (ushort)((uint)iVar3 >> 0x10);
            iVar3 = CONCAT22(uStack_a,uStack_e._2_2_) * 2;
            uStack_e._2_2_ = (ushort)iVar3 | uVar8 >> 0xf;
            iVar22 = iVar22 + 0xffff;
            uStack_a = (ushort)((uint)iVar3 >> 0x10);
          } while (0 < (short)iVar22);
          uVar20 = (ushort)iVar22;
          if ((short)uVar20 < 1) goto LAB_1002c924;
        }
        if ((0x8000 < CONCAT11(uStack_13,local_14)) ||
           (uVar9 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e),
           uStack_12 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12),
           (CONCAT22((ushort)uStack_12,CONCAT11(uStack_13,local_14)) & 0x1ffff) == 0x18000)) {
          if (CONCAT22(uStack_12._2_2_,(ushort)uStack_12) == -1) {
            uStack_12 = 0;
            if (CONCAT22(uStack_e._2_2_,(ushort)uStack_e) == -1) {
              if (uStack_a == 0xffff) {
                uStack_a = 0x8000;
                uVar20 = uVar20 + 1;
                uVar9 = 0;
                uStack_12 = 0;
              }
              else {
                uStack_a = uStack_a + 1;
                uVar9 = 0;
                uStack_12 = 0;
              }
            }
            else {
              uVar9 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e) + 1;
            }
          }
          else {
            uStack_12 = CONCAT22(uStack_12._2_2_,(ushort)uStack_12) + 1;
            uVar9 = CONCAT22(uStack_e._2_2_,(ushort)uStack_e);
          }
        }
        if (uVar20 < 0x7fff) {
          bStack_19 = (byte)(uVar20 >> 8) | bStack_19 & 0x80;
          uStack_1c = uStack_a;
          local_1a = (undefined1)uVar20;
          uVar6 = uStack_12;
          uVar16 = uVar9;
        }
        else {
          iVar22 = (((bStack_19 & 0x80) == 0) - 1 & 0x80000000) + 0x7fff8000;
          uStack_1c = (ushort)iVar22;
          local_1a = (undefined1)((uint)iVar22 >> 0x10);
          bStack_19 = (byte)((uint)iVar22 >> 0x18);
          uVar6 = 0;
          uVar16 = 0;
        }
        goto LAB_1002ca2b;
      }
      iVar22 = 0;
    }
    else {
      iVar22 = (((bStack_19 & 0x80) == 0) - 1 & 0x80000000) + 0x7fff8000;
    }
    uStack_1c = (ushort)iVar22;
    local_1a = (undefined1)((uint)iVar22 >> 0x10);
    bStack_19 = (byte)((uint)iVar22 >> 0x18);
    uStack_12 = 0;
    uVar9 = 0;
    uVar6 = 0;
    uVar16 = 0;
  }
LAB_1002ca2b:
  *param_6 = local_50;
  if (((param_5 & 1) == 0) || (param_4 = param_4 + local_50, 0 < param_4)) {
    if (0x15 < param_4) {
      param_4 = 0x15;
    }
    iVar22 = (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) >> 0x10) - 0x3ffe;
    local_1a = 0;
    bStack_19 = 0;
    local_48 = 8;
    uVar11 = uVar6;
    uVar23 = uVar16;
    do {
      uVar6 = uVar11 << 1;
      uVar16 = uVar23 * 2 | uVar11 >> 0x1f;
      iVar3 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) * 2;
      uStack_1c = (ushort)iVar3 | (ushort)(uVar23 >> 0x1f);
      local_48 = local_48 + -1;
      uStack_20._0_2_ = (undefined2)uVar16;
      uStack_20._2_2_ = (ushort)(uVar23 * 2 >> 0x10);
      local_1a = (undefined1)((uint)iVar3 >> 0x10);
      bStack_19 = (byte)((uint)iVar3 >> 0x18);
      uVar11 = uVar6;
      uVar23 = uVar16;
    } while (local_48 != 0);
    if ((iVar22 < 0) && (uVar23 = -iVar22 & 0xff, uVar23 != 0)) {
      do {
        iVar22 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
        uVar6 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) >> 1;
        uStack_1c = (ushort)uVar6;
        local_1a = (undefined1)(uVar6 >> 0x10);
        bStack_19 = bStack_19 >> 1;
        uVar13 = CONCAT22(uStack_20._2_2_,(undefined2)uStack_20) >> 1;
        uVar16 = uVar13 | iVar22 << 0x1f;
        uVar6 = uVar11 >> 1 | CONCAT22(uStack_20._2_2_,(undefined2)uStack_20) << 0x1f;
        uVar23 = uVar23 - 1;
        uStack_20._0_2_ = (undefined2)uVar13;
        uStack_20._2_2_ = (ushort)(uVar16 >> 0x10);
        local_24._0_2_ = (ushort)(uVar11 >> 1);
        local_24._2_2_ = (ushort)(uVar6 >> 0x10);
        uVar11 = CONCAT22(local_24._2_2_,(ushort)local_24);
      } while (0 < (int)uVar23);
    }
    psVar21 = param_6 + 2;
    psVar17 = psVar21;
    for (param_4 = param_4 + 1; 0 < param_4; param_4 = param_4 + -1) {
      uStack_20._2_2_ = (ushort)(uVar16 >> 0x10);
      uStack_20._0_2_ = (undefined2)uVar16;
      local_24._2_2_ = (ushort)(uVar6 >> 0x10);
      local_24._0_2_ = (ushort)uVar6;
      iVar1 = CONCAT22((undefined2)uStack_20,local_24._2_2_);
      local_38 = CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c));
      uVar23 = (CONCAT13(bStack_19,CONCAT12(local_1a,uStack_1c)) * 2 |
               (uint)(uStack_20._2_2_ >> 0xf)) * 2 | (uVar16 & 0x7fffffff) >> 0x1e;
      uVar13 = (uVar16 * 2 | (uint)(local_24._2_2_ >> 0xf)) * 2 | (uVar6 & 0x7fffffff) >> 0x1e;
      uVar11 = uVar6 * 5;
      if ((uVar11 < uVar6 * 4) || (uVar15 = uVar13, uVar11 < uVar6)) {
        uVar15 = uVar13 + 1;
        bVar4 = false;
        if ((uVar15 < uVar13) || (uVar15 == 0)) {
          bVar4 = true;
        }
        if (bVar4) {
          uVar23 = uVar23 + 1;
        }
      }
      uVar13 = uVar16 + uVar15;
      if ((uVar13 < uVar15) || (uVar13 < uVar16)) {
        uVar23 = uVar23 + 1;
      }
      iVar22 = (uVar23 + local_38) * 2;
      uStack_1c = (ushort)iVar22 | (ushort)(uVar13 >> 0x1f);
      uVar6 = uVar6 * 10;
      local_1a = (undefined1)((uint)iVar22 >> 0x10);
      uVar16 = uVar13 * 2 | uVar11 >> 0x1f;
      *(char *)psVar17 = (char)((uint)iVar22 >> 0x18) + '0';
      psVar17 = (short *)((int)psVar17 + 1);
      bStack_19 = 0;
      local_40 = (ushort)local_24;
      uStack_3a = uStack_20._2_2_;
    }
    psVar18 = psVar17 + -1;
    if (*(char *)((int)psVar17 + -1) < '5') {
      for (; (psVar21 <= psVar18 && ((char)*psVar18 == '0')); psVar18 = (short *)((int)psVar18 + -1)
          ) {
      }
      if (psVar18 < psVar21) {
        *param_6 = 0;
        *(undefined1 *)((int)param_6 + 3) = 1;
        *(byte *)(param_6 + 1) = ((uVar7 != 0x8000) - 1U & 0xd) + 0x20;
        *(char *)psVar21 = '0';
        *(undefined1 *)((int)param_6 + 5) = 0;
        goto LAB_1002cbf3;
      }
    }
    else {
      for (; (psVar21 <= psVar18 && ((char)*psVar18 == '9')); psVar18 = (short *)((int)psVar18 + -1)
          ) {
        *(char *)psVar18 = '0';
      }
      if (psVar18 < psVar21) {
        psVar18 = (short *)((int)psVar18 + 1);
        *param_6 = *param_6 + 1;
      }
      *(char *)psVar18 = (char)*psVar18 + '\x01';
    }
    cVar14 = ((char)psVar18 - (char)param_6) + -3;
    *(char *)((int)param_6 + 3) = cVar14;
    *(undefined1 *)(cVar14 + 4 + (int)param_6) = 0;
  }
  else {
    *param_6 = 0;
    *(undefined1 *)((int)param_6 + 3) = 1;
    *(byte *)(param_6 + 1) = ((uVar7 != 0x8000) - 1U & 0xd) + 0x20;
    *(undefined1 *)(param_6 + 2) = 0x30;
    *(undefined1 *)((int)param_6 + 5) = 0;
  }
LAB_1002cbf3:
  uStack_3e = iVar1;
  local_24 = uVar6;
  uStack_20 = uVar16;
  uStack_e = uVar9;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
