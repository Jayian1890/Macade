# 1002c31b `$I10_OUTPUT`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002c31b |
| `name` | $I10_OUTPUT |
| `namespace` | Global |
| `signature` | undefined __cdecl $I10_OUTPUT(void) |
| `size_bytes` | 2334 |
| `stack_frame_size` | 124 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | $I10_OUTPUT, _$I10_OUTPUT |

## Decompiled C

```c

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
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002c430` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1002c443` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1002c45c` | `10015f7b` | `UNCONDITIONAL_CALL` | _strcpy_s | `10015f7b` |
| `1002c46f` | `10011587` | `UNCONDITIONAL_CALL` | __invoke_watson | `10011587` |
| `1002cbfb` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002afda` | __fltout2 |

## Referenced Strings

| From | Address | Value |
| --- | --- | --- |
| `1002c3fe` | `100334d8` | `1#SNAN` |
| `1002c416` | `100334d0` | `1#IND` |
| `1002c425` | `100334c8` | `1#INF` |
| `1002c451` | `100334c0` | `1#QNAN` |
| `1002c4c8` | `100386e0` | `.?AUCallbacks@Udp@@` |

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002c323` | `10037490` | `READ` | DAT_10037490 |
| `1002c4b1` | `10038740` | `DATA` | DAT_10038740 |
| `1002c4d5` | `100388a0` | `DATA` | DAT_100388a0 |
| `1002c4df` | `10038840` | `DATA` | DAT_10038840 |
| `1002c4ea` | `10038894` | `DATA` | DAT_10038894 |
| `1002c4ea` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002c4ea` | `10038734` | `DATA` | DAT_10038734 |
| `1002c50e` | `10038894` | `DATA` | DAT_10038894 |
| `1002c50e` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002c50e` | `10038734` | `DATA` | DAT_10038734 |
| `1002c518` | `10038894` | `DATA` | DAT_10038894 |
| `1002c518` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002c519` | `10038898` | `DATA` | DAT_10038898 |
| `1002c519` | `100388ec` | `DATA` | DAT_100388ec |
| `1002c51d` | `1003889c` | `DATA` | DAT_1003889c |
| `1002c524` | `100388f2` | `DATA` | DAT_100388f2 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002c31b` | `8b ff` | `MOV EDI,EDI` |
| `1002c31d` | `55` | `PUSH EBP` |
| `1002c31e` | `8b ec` | `MOV EBP,ESP` |
| `1002c320` | `83 ec 74` | `SUB ESP,0x74` |
| `1002c323` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002c328` | `33 c5` | `XOR EAX,EBP` |
| `1002c32a` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002c32d` | `53` | `PUSH EBX` |
| `1002c32e` | `8b 5d 1c` | `MOV EBX,dword ptr [EBP + 0x1c]` |
| `1002c331` | `56` | `PUSH ESI` |
| `1002c332` | `57` | `PUSH EDI` |
| `1002c333` | `8d 75 08` | `LEA ESI,[EBP + 0x8]` |
| `1002c336` | `8d 7d f0` | `LEA EDI,[EBP + -0x10]` |
| `1002c339` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002c33a` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002c33b` | `66 a5` | `MOVSW ES:EDI,ESI` |
| `1002c33d` | `8b 55 f8` | `MOV EDX,dword ptr [EBP + -0x8]` |
| `1002c340` | `8b ca` | `MOV ECX,EDX` |
| `1002c342` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002c347` | `23 c8` | `AND ECX,EAX` |
| `1002c349` | `81 e2 ff 7f 00 00` | `AND EDX,0x7fff` |
| `1002c34f` | `89 5d a0` | `MOV dword ptr [EBP + -0x60],EBX` |
| `1002c352` | `c6 45 d0 cc` | `MOV byte ptr [EBP + -0x30],0xcc` |
| `1002c356` | `c6 45 d1 cc` | `MOV byte ptr [EBP + -0x2f],0xcc` |
| `1002c35a` | `c6 45 d2 cc` | `MOV byte ptr [EBP + -0x2e],0xcc` |
| `1002c35e` | `c6 45 d3 cc` | `MOV byte ptr [EBP + -0x2d],0xcc` |
| `1002c362` | `c6 45 d4 cc` | `MOV byte ptr [EBP + -0x2c],0xcc` |
| `1002c366` | `c6 45 d5 cc` | `MOV byte ptr [EBP + -0x2b],0xcc` |
| `1002c36a` | `c6 45 d6 cc` | `MOV byte ptr [EBP + -0x2a],0xcc` |
| `1002c36e` | `c6 45 d7 cc` | `MOV byte ptr [EBP + -0x29],0xcc` |
| `1002c372` | `c6 45 d8 cc` | `MOV byte ptr [EBP + -0x28],0xcc` |
| `1002c376` | `c6 45 d9 cc` | `MOV byte ptr [EBP + -0x27],0xcc` |
| `1002c37a` | `c6 45 da fb` | `MOV byte ptr [EBP + -0x26],0xfb` |
| `1002c37e` | `c6 45 db 3f` | `MOV byte ptr [EBP + -0x25],0x3f` |
| `1002c382` | `c7 45 8c 01 00 00 00` | `MOV dword ptr [EBP + -0x74],0x1` |
| `1002c389` | `89 4d 90` | `MOV dword ptr [EBP + -0x70],ECX` |
| `1002c38c` | `66 85 c9` | `TEST CX,CX` |
| `1002c38f` | `74 06` | `JZ 0x1002c397` |
| `1002c391` | `c6 43 02 2d` | `MOV byte ptr [EBX + 0x2],0x2d` |
| `1002c395` | `eb 04` | `JMP 0x1002c39b` |
| `1002c397` | `c6 43 02 20` | `MOV byte ptr [EBX + 0x2],0x20` |
| `1002c39b` | `8b 75 f4` | `MOV ESI,dword ptr [EBP + -0xc]` |
| `1002c39e` | `8b 7d f0` | `MOV EDI,dword ptr [EBP + -0x10]` |
| `1002c3a1` | `66 85 d2` | `TEST DX,DX` |
| `1002c3a4` | `75 2f` | `JNZ 0x1002c3d5` |
| `1002c3a6` | `85 f6` | `TEST ESI,ESI` |
| `1002c3a8` | `75 2b` | `JNZ 0x1002c3d5` |
| `1002c3aa` | `85 ff` | `TEST EDI,EDI` |
| `1002c3ac` | `75 27` | `JNZ 0x1002c3d5` |
| `1002c3ae` | `33 d2` | `XOR EDX,EDX` |
| `1002c3b0` | `66 3b c8` | `CMP CX,AX` |
| `1002c3b3` | `0f 95 c0` | `SETNZ AL` |
| `1002c3b6` | `fe c8` | `DEC AL` |
| `1002c3b8` | `24 0d` | `AND AL,0xd` |
| `1002c3ba` | `04 20` | `ADD AL,0x20` |
| `1002c3bc` | `66 89 13` | `MOV word ptr [EBX],DX` |
| `1002c3bf` | `88 43 02` | `MOV byte ptr [EBX + 0x2],AL` |
| `1002c3c2` | `c6 43 03 01` | `MOV byte ptr [EBX + 0x3],0x1` |
| `1002c3c6` | `c6 43 04 30` | `MOV byte ptr [EBX + 0x4],0x30` |
| `1002c3ca` | `88 53 05` | `MOV byte ptr [EBX + 0x5],DL` |
| `1002c3cd` | `33 c0` | `XOR EAX,EAX` |
| `1002c3cf` | `40` | `INC EAX` |
| `1002c3d0` | `e9 1e 08 00 00` | `JMP 0x1002cbf3` |
| `1002c3d5` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c3da` | `66 3b d0` | `CMP DX,AX` |
| `1002c3dd` | `0f 85 9f 00 00 00` | `JNZ 0x1002c482` |
| `1002c3e3` | `33 c0` | `XOR EAX,EAX` |
| `1002c3e5` | `40` | `INC EAX` |
| `1002c3e6` | `66 89 03` | `MOV word ptr [EBX],AX` |
| `1002c3e9` | `b8 00 00 00 80` | `MOV EAX,0x80000000` |
| `1002c3ee` | `3b f0` | `CMP ESI,EAX` |
| `1002c3f0` | `75 04` | `JNZ 0x1002c3f6` |
| `1002c3f2` | `85 ff` | `TEST EDI,EDI` |
| `1002c3f4` | `74 0f` | `JZ 0x1002c405` |
| `1002c3f6` | `f7 c6 00 00 00 40` | `TEST ESI,0x40000000` |
| `1002c3fc` | `75 07` | `JNZ 0x1002c405` |
| `1002c3fe` | `68 d8 34 03 10` | `PUSH 0x100334d8` |
| `1002c403` | `eb 51` | `JMP 0x1002c456` |
| `1002c405` | `66 85 c9` | `TEST CX,CX` |
| `1002c408` | `74 13` | `JZ 0x1002c41d` |
| `1002c40a` | `81 fe 00 00 00 c0` | `CMP ESI,0xc0000000` |
| `1002c410` | `75 0b` | `JNZ 0x1002c41d` |
| `1002c412` | `85 ff` | `TEST EDI,EDI` |
| `1002c414` | `75 3b` | `JNZ 0x1002c451` |
| `1002c416` | `68 d0 34 03 10` | `PUSH 0x100334d0` |
| `1002c41b` | `eb 0d` | `JMP 0x1002c42a` |
| `1002c41d` | `3b f0` | `CMP ESI,EAX` |
| `1002c41f` | `75 30` | `JNZ 0x1002c451` |
| `1002c421` | `85 ff` | `TEST EDI,EDI` |
| `1002c423` | `75 2c` | `JNZ 0x1002c451` |
| `1002c425` | `68 c8 34 03 10` | `PUSH 0x100334c8` |
| `1002c42a` | `8d 43 04` | `LEA EAX,[EBX + 0x4]` |
| `1002c42d` | `6a 16` | `PUSH 0x16` |
| `1002c42f` | `50` | `PUSH EAX` |
| `1002c430` | `e8 46 9b fe ff` | `CALL 0x10015f7b` |
| `1002c435` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002c438` | `33 f6` | `XOR ESI,ESI` |
| `1002c43a` | `85 c0` | `TEST EAX,EAX` |
| `1002c43c` | `74 0d` | `JZ 0x1002c44b` |
| `1002c43e` | `56` | `PUSH ESI` |
| `1002c43f` | `56` | `PUSH ESI` |
| `1002c440` | `56` | `PUSH ESI` |
| `1002c441` | `56` | `PUSH ESI` |
| `1002c442` | `56` | `PUSH ESI` |
| `1002c443` | `e8 3f 51 fe ff` | `CALL 0x10011587` |
| `1002c44b` | `c6 43 03 05` | `MOV byte ptr [EBX + 0x3],0x5` |
| `1002c44f` | `eb 2a` | `JMP 0x1002c47b` |
| `1002c451` | `68 c0 34 03 10` | `PUSH 0x100334c0` |
| `1002c456` | `8d 43 04` | `LEA EAX,[EBX + 0x4]` |
| `1002c459` | `6a 16` | `PUSH 0x16` |
| `1002c45b` | `50` | `PUSH EAX` |
| `1002c45c` | `e8 1a 9b fe ff` | `CALL 0x10015f7b` |
| `1002c461` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002c464` | `33 f6` | `XOR ESI,ESI` |
| `1002c466` | `85 c0` | `TEST EAX,EAX` |
| `1002c468` | `74 0d` | `JZ 0x1002c477` |
| `1002c46a` | `56` | `PUSH ESI` |
| `1002c46b` | `56` | `PUSH ESI` |
| `1002c46c` | `56` | `PUSH ESI` |
| `1002c46d` | `56` | `PUSH ESI` |
| `1002c46e` | `56` | `PUSH ESI` |
| `1002c46f` | `e8 13 51 fe ff` | `CALL 0x10011587` |
| `1002c477` | `c6 43 03 06` | `MOV byte ptr [EBX + 0x3],0x6` |
| `1002c47b` | `33 c0` | `XOR EAX,EAX` |
| `1002c47d` | `e9 71 07 00 00` | `JMP 0x1002cbf3` |
| `1002c482` | `0f b7 ca` | `MOVZX ECX,DX` |
| `1002c485` | `8b d9` | `MOV EBX,ECX` |
| `1002c487` | `69 c9 10 4d 00 00` | `IMUL ECX,ECX,0x4d10` |
| `1002c48d` | `c1 eb 08` | `SHR EBX,0x8` |
| `1002c490` | `8b c6` | `MOV EAX,ESI` |
| `1002c492` | `c1 e8 18` | `SHR EAX,0x18` |
| `1002c495` | `8d 04 43` | `LEA EAX,[EBX + EAX*0x2]` |
| `1002c498` | `6b c0 4d` | `IMUL EAX,EAX,0x4d` |
| `1002c49b` | `8d 84 08 0c ed bc ec` | `LEA EAX,[EAX + ECX*0x1 + 0xecbced0c]` |
| `1002c4a2` | `c1 f8 10` | `SAR EAX,0x10` |
| `1002c4a5` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1002c4a8` | `33 c9` | `XOR ECX,ECX` |
| `1002c4aa` | `0f bf d8` | `MOVSX EBX,AX` |
| `1002c4ad` | `66 89 4d e0` | `MOV word ptr [EBP + -0x20],CX` |
| `1002c4b1` | `b9 40 87 03 10` | `MOV ECX,0x10038740` |
| `1002c4b6` | `f7 db` | `NEG EBX` |
| `1002c4b8` | `83 e9 60` | `SUB ECX,0x60` |
| `1002c4bb` | `89 45 b4` | `MOV dword ptr [EBP + -0x4c],EAX` |
| `1002c4be` | `66 89 55 ea` | `MOV word ptr [EBP + -0x16],DX` |
| `1002c4c2` | `89 75 e6` | `MOV dword ptr [EBP + -0x1a],ESI` |
| `1002c4c5` | `89 7d e2` | `MOV dword ptr [EBP + -0x1e],EDI` |
| `1002c4c8` | `89 4d 9c` | `MOV dword ptr [EBP + -0x64],ECX` |
| `1002c4cb` | `85 db` | `TEST EBX,EBX` |
| `1002c4cd` | `0f 84 9c 02 00 00` | `JZ 0x1002c76f` |
| `1002c4d3` | `7d 0d` | `JGE 0x1002c4e2` |
| `1002c4d5` | `b8 a0 88 03 10` | `MOV EAX,0x100388a0` |
| `1002c4da` | `f7 db` | `NEG EBX` |
| `1002c4dc` | `83 e8 60` | `SUB EAX,0x60` |
| `1002c4df` | `89 45 9c` | `MOV dword ptr [EBP + -0x64],EAX` |
| `1002c4e2` | `85 db` | `TEST EBX,EBX` |
| `1002c4e4` | `0f 84 85 02 00 00` | `JZ 0x1002c76f` |
| `1002c4ea` | `83 45 9c 54` | `ADD dword ptr [EBP + -0x64],0x54` |
| `1002c4ee` | `8b cb` | `MOV ECX,EBX` |
| `1002c4f0` | `83 e1 07` | `AND ECX,0x7` |
| `1002c4f3` | `c1 fb 03` | `SAR EBX,0x3` |
| `1002c4f6` | `85 c9` | `TEST ECX,ECX` |
| `1002c4f8` | `0f 84 67 02 00 00` | `JZ 0x1002c765` |
| `1002c4fe` | `6b c9 0c` | `IMUL ECX,ECX,0xc` |
| `1002c501` | `03 4d 9c` | `ADD ECX,dword ptr [EBP + -0x64]` |
| `1002c504` | `8b c1` | `MOV EAX,ECX` |
| `1002c506` | `89 4d bc` | `MOV dword ptr [EBP + -0x44],ECX` |
| `1002c509` | `b9 00 80 00 00` | `MOV ECX,0x8000` |
| `1002c50e` | `66 39 08` | `CMP word ptr [EAX],CX` |
| `1002c511` | `72 11` | `JC 0x1002c524` |
| `1002c513` | `8b f0` | `MOV ESI,EAX` |
| `1002c515` | `8d 7d c4` | `LEA EDI,[EBP + -0x3c]` |
| `1002c518` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002c519` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002c51a` | `8d 45 c4` | `LEA EAX,[EBP + -0x3c]` |
| `1002c51d` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002c51e` | `ff 4d c6` | `DEC dword ptr [EBP + -0x3a]` |
| `1002c521` | `89 45 bc` | `MOV dword ptr [EBP + -0x44],EAX` |
| `1002c524` | `0f b7 50 0a` | `MOVZX EDX,word ptr [EAX + 0xa]` |
| `1002c528` | `33 c9` | `XOR ECX,ECX` |
| `1002c52a` | `89 4d ac` | `MOV dword ptr [EBP + -0x54],ECX` |
| `1002c52d` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002c530` | `89 4d f4` | `MOV dword ptr [EBP + -0xc],ECX` |
| `1002c533` | `89 4d f8` | `MOV dword ptr [EBP + -0x8],ECX` |
| `1002c536` | `8b 4d ea` | `MOV ECX,dword ptr [EBP + -0x16]` |
| `1002c539` | `8b f2` | `MOV ESI,EDX` |
| `1002c53b` | `33 f1` | `XOR ESI,ECX` |
| `1002c53d` | `81 e6 00 80 00 00` | `AND ESI,0x8000` |
| `1002c543` | `89 75 b8` | `MOV dword ptr [EBP + -0x48],ESI` |
| `1002c546` | `be ff 7f 00 00` | `MOV ESI,0x7fff` |
| `1002c54b` | `23 ce` | `AND ECX,ESI` |
| `1002c54d` | `23 d6` | `AND EDX,ESI` |
| `1002c54f` | `8d 34 0a` | `LEA ESI,[EDX + ECX*0x1]` |
| `1002c552` | `0f b7 fe` | `MOVZX EDI,SI` |
| `1002c555` | `be ff 7f 00 00` | `MOV ESI,0x7fff` |
| `1002c55a` | `66 3b ce` | `CMP CX,SI` |
| `1002c55d` | `0f 83 ac 02 00 00` | `JNC 0x1002c80f` |
| `1002c563` | `66 3b d6` | `CMP DX,SI` |
| `1002c566` | `0f 83 a3 02 00 00` | `JNC 0x1002c80f` |
| `1002c56c` | `be fd bf 00 00` | `MOV ESI,0xbffd` |
| `1002c571` | `66 3b fe` | `CMP DI,SI` |
| `1002c574` | `0f 87 95 02 00 00` | `JA 0x1002c80f` |
| `1002c57a` | `be bf 3f 00 00` | `MOV ESI,0x3fbf` |
| `1002c57f` | `66 3b fe` | `CMP DI,SI` |
| `1002c582` | `77 10` | `JA 0x1002c594` |
| `1002c584` | `33 f6` | `XOR ESI,ESI` |
| `1002c586` | `89 75 e8` | `MOV dword ptr [EBP + -0x18],ESI` |
| `1002c589` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1002c58c` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `1002c58f` | `e9 d3 01 00 00` | `JMP 0x1002c767` |
| `1002c594` | `33 f6` | `XOR ESI,ESI` |
| `1002c596` | `66 3b ce` | `CMP CX,SI` |
| `1002c599` | `75 1f` | `JNZ 0x1002c5ba` |
| `1002c59b` | `47` | `INC EDI` |
| `1002c59c` | `f7 45 e8 ff ff ff 7f` | `TEST dword ptr [EBP + -0x18],0x7fffffff` |
| `1002c5a3` | `75 15` | `JNZ 0x1002c5ba` |
| `1002c5a5` | `39 75 e4` | `CMP dword ptr [EBP + -0x1c],ESI` |
| `1002c5a8` | `75 10` | `JNZ 0x1002c5ba` |
| `1002c5aa` | `39 75 e0` | `CMP dword ptr [EBP + -0x20],ESI` |
| `1002c5ad` | `75 0b` | `JNZ 0x1002c5ba` |
| `1002c5af` | `33 c0` | `XOR EAX,EAX` |
| `1002c5b1` | `66 89 45 ea` | `MOV word ptr [EBP + -0x16],AX` |
| `1002c5b5` | `e9 ad 01 00 00` | `JMP 0x1002c767` |
| `1002c5ba` | `66 3b d6` | `CMP DX,SI` |
| `1002c5bd` | `75 13` | `JNZ 0x1002c5d2` |
| `1002c5bf` | `47` | `INC EDI` |
| `1002c5c0` | `f7 40 08 ff ff ff 7f` | `TEST dword ptr [EAX + 0x8],0x7fffffff` |
| `1002c5c7` | `75 09` | `JNZ 0x1002c5d2` |
| `1002c5c9` | `39 70 04` | `CMP dword ptr [EAX + 0x4],ESI` |
| `1002c5cc` | `75 04` | `JNZ 0x1002c5d2` |
| `1002c5ce` | `39 30` | `CMP dword ptr [EAX],ESI` |
| `1002c5d0` | `74 b4` | `JZ 0x1002c586` |
| `1002c5d2` | `21 75 a8` | `AND dword ptr [EBP + -0x58],ESI` |
| `1002c5d5` | `8d 75 f4` | `LEA ESI,[EBP + -0xc]` |
| `1002c5d8` | `c7 45 c0 05 00 00 00` | `MOV dword ptr [EBP + -0x40],0x5` |
| `1002c5df` | `8b 4d a8` | `MOV ECX,dword ptr [EBP + -0x58]` |
| `1002c5e2` | `8b 55 c0` | `MOV EDX,dword ptr [EBP + -0x40]` |
| `1002c5e5` | `03 c9` | `ADD ECX,ECX` |
| `1002c5e7` | `89 55 b0` | `MOV dword ptr [EBP + -0x50],EDX` |
| `1002c5ea` | `85 d2` | `TEST EDX,EDX` |
| `1002c5ec` | `7e 55` | `JLE 0x1002c643` |
| `1002c5ee` | `8d 4c 0d e0` | `LEA ECX,[EBP + ECX*0x1 + -0x20]` |
| `1002c5f2` | `83 c0 08` | `ADD EAX,0x8` |
| `1002c5f5` | `89 4d 94` | `MOV dword ptr [EBP + -0x6c],ECX` |
| `1002c5f8` | `89 45 98` | `MOV dword ptr [EBP + -0x68],EAX` |
| `1002c5fb` | `8b 45 94` | `MOV EAX,dword ptr [EBP + -0x6c]` |
| `1002c5fe` | `0f b7 08` | `MOVZX ECX,word ptr [EAX]` |
| `1002c601` | `8b 45 98` | `MOV EAX,dword ptr [EBP + -0x68]` |
| `1002c604` | `0f b7 00` | `MOVZX EAX,word ptr [EAX]` |
| `1002c607` | `8b 56 fc` | `MOV EDX,dword ptr [ESI + -0x4]` |
| `1002c60a` | `0f af c8` | `IMUL ECX,EAX` |
| `1002c60d` | `83 65 a4 00` | `AND dword ptr [EBP + -0x5c],0x0` |
| `1002c611` | `8d 04 0a` | `LEA EAX,[EDX + ECX*0x1]` |
| `1002c614` | `3b c2` | `CMP EAX,EDX` |
| `1002c616` | `72 04` | `JC 0x1002c61c` |
| `1002c618` | `3b c1` | `CMP EAX,ECX` |
| `1002c61a` | `73 07` | `JNC 0x1002c623` |
| `1002c61c` | `c7 45 a4 01 00 00 00` | `MOV dword ptr [EBP + -0x5c],0x1` |
| `1002c623` | `83 7d a4 00` | `CMP dword ptr [EBP + -0x5c],0x0` |
| `1002c627` | `89 46 fc` | `MOV dword ptr [ESI + -0x4],EAX` |
| `1002c62a` | `74 03` | `JZ 0x1002c62f` |
| `1002c62c` | `66 ff 06` | `INC word ptr [ESI]` |
| `1002c62f` | `83 45 94 02` | `ADD dword ptr [EBP + -0x6c],0x2` |
| `1002c633` | `83 6d 98 02` | `SUB dword ptr [EBP + -0x68],0x2` |
| `1002c637` | `ff 4d b0` | `DEC dword ptr [EBP + -0x50]` |
| `1002c63a` | `83 7d b0 00` | `CMP dword ptr [EBP + -0x50],0x0` |
| `1002c63e` | `7f bb` | `JG 0x1002c5fb` |
| `1002c640` | `8b 45 bc` | `MOV EAX,dword ptr [EBP + -0x44]` |
| `1002c643` | `46` | `INC ESI` |
| `1002c644` | `46` | `INC ESI` |
| `1002c645` | `ff 45 a8` | `INC dword ptr [EBP + -0x58]` |
| `1002c648` | `ff 4d c0` | `DEC dword ptr [EBP + -0x40]` |
| `1002c64b` | `83 7d c0 00` | `CMP dword ptr [EBP + -0x40],0x0` |
| `1002c64f` | `7f 8e` | `JG 0x1002c5df` |
| `1002c651` | `81 c7 02 c0 00 00` | `ADD EDI,0xc002` |
| `1002c657` | `66 85 ff` | `TEST DI,DI` |
| `1002c65a` | `7e 3b` | `JLE 0x1002c697` |
| `1002c65c` | `f7 45 f8 00 00 00 80` | `TEST dword ptr [EBP + -0x8],0x80000000` |
| `1002c663` | `75 2d` | `JNZ 0x1002c692` |
| `1002c665` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002c668` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c66b` | `d1 65 f0` | `SHL dword ptr [EBP + -0x10],0x1` |
| `1002c66e` | `8b d0` | `MOV EDX,EAX` |
| `1002c670` | `03 c0` | `ADD EAX,EAX` |
| `1002c672` | `c1 e9 1f` | `SHR ECX,0x1f` |
| `1002c675` | `0b c1` | `OR EAX,ECX` |
| `1002c677` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002c67a` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002c67d` | `c1 ea 1f` | `SHR EDX,0x1f` |
| `1002c680` | `03 c0` | `ADD EAX,EAX` |
| `1002c682` | `0b c2` | `OR EAX,EDX` |
| `1002c684` | `81 c7 ff ff 00 00` | `ADD EDI,0xffff` |
| `1002c68a` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1002c68d` | `66 85 ff` | `TEST DI,DI` |
| `1002c690` | `7f ca` | `JG 0x1002c65c` |
| `1002c692` | `66 85 ff` | `TEST DI,DI` |
| `1002c695` | `7f 4d` | `JG 0x1002c6e4` |
| `1002c697` | `81 c7 ff ff 00 00` | `ADD EDI,0xffff` |
| `1002c69d` | `66 85 ff` | `TEST DI,DI` |
| `1002c6a0` | `7d 42` | `JGE 0x1002c6e4` |
| `1002c6a2` | `8b c7` | `MOV EAX,EDI` |
| `1002c6a4` | `f7 d8` | `NEG EAX` |
| `1002c6a6` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1002c6a9` | `03 f8` | `ADD EDI,EAX` |
| `1002c6ab` | `f6 45 f0 01` | `TEST byte ptr [EBP + -0x10],0x1` |
| `1002c6af` | `74 03` | `JZ 0x1002c6b4` |
| `1002c6b1` | `ff 45 ac` | `INC dword ptr [EBP + -0x54]` |
| `1002c6b4` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002c6b7` | `8b 75 f4` | `MOV ESI,dword ptr [EBP + -0xc]` |
| `1002c6ba` | `8b 55 f4` | `MOV EDX,dword ptr [EBP + -0xc]` |
| `1002c6bd` | `d1 6d f8` | `SHR dword ptr [EBP + -0x8],0x1` |
| `1002c6c0` | `c1 e1 1f` | `SHL ECX,0x1f` |
| `1002c6c3` | `d1 ee` | `SHR ESI,0x1` |
| `1002c6c5` | `0b f1` | `OR ESI,ECX` |
| `1002c6c7` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c6ca` | `c1 e2 1f` | `SHL EDX,0x1f` |
| `1002c6cd` | `d1 e9` | `SHR ECX,0x1` |
| `1002c6cf` | `0b ca` | `OR ECX,EDX` |
| `1002c6d1` | `48` | `DEC EAX` |
| `1002c6d2` | `89 75 f4` | `MOV dword ptr [EBP + -0xc],ESI` |
| `1002c6d5` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002c6d8` | `75 d1` | `JNZ 0x1002c6ab` |
| `1002c6da` | `39 45 ac` | `CMP dword ptr [EBP + -0x54],EAX` |
| `1002c6dd` | `74 05` | `JZ 0x1002c6e4` |
| `1002c6df` | `66 83 4d f0 01` | `OR word ptr [EBP + -0x10],0x1` |
| `1002c6e4` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002c6e9` | `8b c8` | `MOV ECX,EAX` |
| `1002c6eb` | `66 39 4d f0` | `CMP word ptr [EBP + -0x10],CX` |
| `1002c6ef` | `77 11` | `JA 0x1002c702` |
| `1002c6f1` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c6f4` | `81 e1 ff ff 01 00` | `AND ECX,0x1ffff` |
| `1002c6fa` | `81 f9 00 80 01 00` | `CMP ECX,0x18000` |
| `1002c700` | `75 34` | `JNZ 0x1002c736` |
| `1002c702` | `83 7d f2 ff` | `CMP dword ptr [EBP + -0xe],-0x1` |
| `1002c706` | `75 2b` | `JNZ 0x1002c733` |
| `1002c708` | `83 65 f2 00` | `AND dword ptr [EBP + -0xe],0x0` |
| `1002c70c` | `83 7d f6 ff` | `CMP dword ptr [EBP + -0xa],-0x1` |
| `1002c710` | `75 1c` | `JNZ 0x1002c72e` |
| `1002c712` | `83 65 f6 00` | `AND dword ptr [EBP + -0xa],0x0` |
| `1002c716` | `b9 ff ff 00 00` | `MOV ECX,0xffff` |
| `1002c71b` | `66 39 4d fa` | `CMP word ptr [EBP + -0x6],CX` |
| `1002c71f` | `75 07` | `JNZ 0x1002c728` |
| `1002c721` | `66 89 45 fa` | `MOV word ptr [EBP + -0x6],AX` |
| `1002c725` | `47` | `INC EDI` |
| `1002c726` | `eb 0e` | `JMP 0x1002c736` |
| `1002c728` | `66 ff 45 fa` | `INC word ptr [EBP + -0x6]` |
| `1002c72c` | `eb 08` | `JMP 0x1002c736` |
| `1002c72e` | `ff 45 f6` | `INC dword ptr [EBP + -0xa]` |
| `1002c731` | `eb 03` | `JMP 0x1002c736` |
| `1002c733` | `ff 45 f2` | `INC dword ptr [EBP + -0xe]` |
| `1002c736` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c73b` | `66 3b f8` | `CMP DI,AX` |
| `1002c73e` | `0f 82 ab 00 00 00` | `JC 0x1002c7ef` |
| `1002c744` | `33 c0` | `XOR EAX,EAX` |
| `1002c746` | `33 c9` | `XOR ECX,ECX` |
| `1002c748` | `66 39 45 b8` | `CMP word ptr [EBP + -0x48],AX` |
| `1002c74c` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1002c74f` | `0f 94 c1` | `SETZ CL` |
| `1002c752` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1002c755` | `49` | `DEC ECX` |
| `1002c756` | `81 e1 00 00 00 80` | `AND ECX,0x80000000` |
| `1002c75c` | `81 c1 00 80 ff 7f` | `ADD ECX,0x7fff8000` |
| `1002c762` | `89 4d e8` | `MOV dword ptr [EBP + -0x18],ECX` |
| `1002c765` | `33 f6` | `XOR ESI,ESI` |
| `1002c767` | `3b de` | `CMP EBX,ESI` |
| `1002c769` | `0f 85 7b fd ff ff` | `JNZ 0x1002c4ea` |
| `1002c76f` | `8b 4d e8` | `MOV ECX,dword ptr [EBP + -0x18]` |
| `1002c772` | `c1 e9 10` | `SHR ECX,0x10` |
| `1002c775` | `ba ff 3f 00 00` | `MOV EDX,0x3fff` |
| `1002c77a` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c77f` | `66 3b ca` | `CMP CX,DX` |
| `1002c782` | `0f 82 a3 02 00 00` | `JC 0x1002ca2b` |
| `1002c788` | `ff 45 b4` | `INC dword ptr [EBP + -0x4c]` |
| `1002c78b` | `33 d2` | `XOR EDX,EDX` |
| `1002c78d` | `89 55 b0` | `MOV dword ptr [EBP + -0x50],EDX` |
| `1002c790` | `89 55 f0` | `MOV dword ptr [EBP + -0x10],EDX` |
| `1002c793` | `89 55 f4` | `MOV dword ptr [EBP + -0xc],EDX` |
| `1002c796` | `89 55 f8` | `MOV dword ptr [EBP + -0x8],EDX` |
| `1002c799` | `8b 55 da` | `MOV EDX,dword ptr [EBP + -0x26]` |
| `1002c79c` | `0f b7 c9` | `MOVZX ECX,CX` |
| `1002c79f` | `8b da` | `MOV EBX,EDX` |
| `1002c7a1` | `33 d9` | `XOR EBX,ECX` |
| `1002c7a3` | `23 c8` | `AND ECX,EAX` |
| `1002c7a5` | `23 d0` | `AND EDX,EAX` |
| `1002c7a7` | `81 e3 00 80 00 00` | `AND EBX,0x8000` |
| `1002c7ad` | `8b f8` | `MOV EDI,EAX` |
| `1002c7af` | `8d 34 0a` | `LEA ESI,[EDX + ECX*0x1]` |
| `1002c7b2` | `89 5d a4` | `MOV dword ptr [EBP + -0x5c],EBX` |
| `1002c7b5` | `0f b7 f6` | `MOVZX ESI,SI` |
| `1002c7b8` | `66 3b cf` | `CMP CX,DI` |
| `1002c7bb` | `0f 83 4c 02 00 00` | `JNC 0x1002ca0d` |
| `1002c7c1` | `66 3b d0` | `CMP DX,AX` |
| `1002c7c4` | `0f 83 43 02 00 00` | `JNC 0x1002ca0d` |
| `1002c7ca` | `b8 fd bf 00 00` | `MOV EAX,0xbffd` |
| `1002c7cf` | `66 3b f0` | `CMP SI,AX` |
| `1002c7d2` | `0f 87 35 02 00 00` | `JA 0x1002ca0d` |
| `1002c7d8` | `b8 bf 3f 00 00` | `MOV EAX,0x3fbf` |
| `1002c7dd` | `66 3b f0` | `CMP SI,AX` |
| `1002c7e0` | `77 4b` | `JA 0x1002c82d` |
| `1002c7e2` | `33 c0` | `XOR EAX,EAX` |
| `1002c7e4` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1002c7e7` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1002c7ea` | `e9 39 02 00 00` | `JMP 0x1002ca28` |
| `1002c7ef` | `66 8b 45 f2` | `MOV AX,word ptr [EBP + -0xe]` |
| `1002c7f3` | `0b 7d b8` | `OR EDI,dword ptr [EBP + -0x48]` |
| `1002c7f6` | `66 89 45 e0` | `MOV word ptr [EBP + -0x20],AX` |
| `1002c7fa` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002c7fd` | `89 45 e2` | `MOV dword ptr [EBP + -0x1e],EAX` |
| `1002c800` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002c803` | `89 45 e6` | `MOV dword ptr [EBP + -0x1a],EAX` |
| `1002c806` | `66 89 7d ea` | `MOV word ptr [EBP + -0x16],DI` |
| `1002c80a` | `e9 56 ff ff ff` | `JMP 0x1002c765` |
| `1002c80f` | `33 c0` | `XOR EAX,EAX` |
| `1002c811` | `33 f6` | `XOR ESI,ESI` |
| `1002c813` | `66 39 75 b8` | `CMP word ptr [EBP + -0x48],SI` |
| `1002c817` | `0f 94 c0` | `SETZ AL` |
| `1002c81a` | `48` | `DEC EAX` |
| `1002c81b` | `25 00 00 00 80` | `AND EAX,0x80000000` |
| `1002c820` | `05 00 80 ff 7f` | `ADD EAX,0x7fff8000` |
| `1002c825` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1002c828` | `e9 5c fd ff ff` | `JMP 0x1002c589` |
| `1002c82d` | `33 c0` | `XOR EAX,EAX` |
| `1002c82f` | `66 3b c8` | `CMP CX,AX` |
| `1002c832` | `75 1d` | `JNZ 0x1002c851` |
| `1002c834` | `46` | `INC ESI` |
| `1002c835` | `f7 45 e8 ff ff ff 7f` | `TEST dword ptr [EBP + -0x18],0x7fffffff` |
| `1002c83c` | `75 13` | `JNZ 0x1002c851` |
| `1002c83e` | `39 45 e4` | `CMP dword ptr [EBP + -0x1c],EAX` |
| `1002c841` | `75 0e` | `JNZ 0x1002c851` |
| `1002c843` | `39 45 e0` | `CMP dword ptr [EBP + -0x20],EAX` |
| `1002c846` | `75 09` | `JNZ 0x1002c851` |
| `1002c848` | `66 89 45 ea` | `MOV word ptr [EBP + -0x16],AX` |
| `1002c84c` | `e9 da 01 00 00` | `JMP 0x1002ca2b` |
| `1002c851` | `66 3b d0` | `CMP DX,AX` |
| `1002c854` | `75 18` | `JNZ 0x1002c86e` |
| `1002c856` | `46` | `INC ESI` |
| `1002c857` | `f7 45 d8 ff ff ff 7f` | `TEST dword ptr [EBP + -0x28],0x7fffffff` |
| `1002c85e` | `75 0e` | `JNZ 0x1002c86e` |
| `1002c860` | `39 45 d4` | `CMP dword ptr [EBP + -0x2c],EAX` |
| `1002c863` | `75 09` | `JNZ 0x1002c86e` |
| `1002c865` | `39 45 d0` | `CMP dword ptr [EBP + -0x30],EAX` |
| `1002c868` | `0f 84 76 ff ff ff` | `JZ 0x1002c7e4` |
| `1002c86e` | `89 45 a8` | `MOV dword ptr [EBP + -0x58],EAX` |
| `1002c871` | `8d 7d f4` | `LEA EDI,[EBP + -0xc]` |
| `1002c874` | `c7 45 c0 05 00 00 00` | `MOV dword ptr [EBP + -0x40],0x5` |
| `1002c87b` | `8b 45 a8` | `MOV EAX,dword ptr [EBP + -0x58]` |
| `1002c87e` | `8b 4d c0` | `MOV ECX,dword ptr [EBP + -0x40]` |
| `1002c881` | `03 c0` | `ADD EAX,EAX` |
| `1002c883` | `89 4d ac` | `MOV dword ptr [EBP + -0x54],ECX` |
| `1002c886` | `85 c9` | `TEST ECX,ECX` |
| `1002c888` | `7e 4a` | `JLE 0x1002c8d4` |
| `1002c88a` | `8d 4d d8` | `LEA ECX,[EBP + -0x28]` |
| `1002c88d` | `89 4d b8` | `MOV dword ptr [EBP + -0x48],ECX` |
| `1002c890` | `8d 44 05 e0` | `LEA EAX,[EBP + EAX*0x1 + -0x20]` |
| `1002c894` | `8b 4d b8` | `MOV ECX,dword ptr [EBP + -0x48]` |
| `1002c897` | `0f b7 10` | `MOVZX EDX,word ptr [EAX]` |
| `1002c89a` | `0f b7 09` | `MOVZX ECX,word ptr [ECX]` |
| `1002c89d` | `83 65 bc 00` | `AND dword ptr [EBP + -0x44],0x0` |
| `1002c8a1` | `0f af ca` | `IMUL ECX,EDX` |
| `1002c8a4` | `8b 57 fc` | `MOV EDX,dword ptr [EDI + -0x4]` |
| `1002c8a7` | `8d 1c 0a` | `LEA EBX,[EDX + ECX*0x1]` |
| `1002c8aa` | `3b da` | `CMP EBX,EDX` |
| `1002c8ac` | `72 04` | `JC 0x1002c8b2` |
| `1002c8ae` | `3b d9` | `CMP EBX,ECX` |
| `1002c8b0` | `73 07` | `JNC 0x1002c8b9` |
| `1002c8b2` | `c7 45 bc 01 00 00 00` | `MOV dword ptr [EBP + -0x44],0x1` |
| `1002c8b9` | `83 7d bc 00` | `CMP dword ptr [EBP + -0x44],0x0` |
| `1002c8bd` | `89 5f fc` | `MOV dword ptr [EDI + -0x4],EBX` |
| `1002c8c0` | `74 03` | `JZ 0x1002c8c5` |
| `1002c8c2` | `66 ff 07` | `INC word ptr [EDI]` |
| `1002c8c5` | `83 6d b8 02` | `SUB dword ptr [EBP + -0x48],0x2` |
| `1002c8c9` | `40` | `INC EAX` |
| `1002c8ca` | `40` | `INC EAX` |
| `1002c8cb` | `ff 4d ac` | `DEC dword ptr [EBP + -0x54]` |
| `1002c8ce` | `83 7d ac 00` | `CMP dword ptr [EBP + -0x54],0x0` |
| `1002c8d2` | `7f c0` | `JG 0x1002c894` |
| `1002c8d4` | `47` | `INC EDI` |
| `1002c8d5` | `47` | `INC EDI` |
| `1002c8d6` | `ff 45 a8` | `INC dword ptr [EBP + -0x58]` |
| `1002c8d9` | `ff 4d c0` | `DEC dword ptr [EBP + -0x40]` |
| `1002c8dc` | `83 7d c0 00` | `CMP dword ptr [EBP + -0x40],0x0` |
| `1002c8e0` | `7f 99` | `JG 0x1002c87b` |
| `1002c8e2` | `81 c6 02 c0 00 00` | `ADD ESI,0xc002` |
| `1002c8e8` | `66 85 f6` | `TEST SI,SI` |
| `1002c8eb` | `7e 37` | `JLE 0x1002c924` |
| `1002c8ed` | `8b 7d f8` | `MOV EDI,dword ptr [EBP + -0x8]` |
| `1002c8f0` | `85 ff` | `TEST EDI,EDI` |
| `1002c8f2` | `78 2b` | `JS 0x1002c91f` |
| `1002c8f4` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002c8f7` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c8fa` | `d1 65 f0` | `SHL dword ptr [EBP + -0x10],0x1` |
| `1002c8fd` | `8b d0` | `MOV EDX,EAX` |
| `1002c8ff` | `03 c0` | `ADD EAX,EAX` |
| `1002c901` | `c1 e9 1f` | `SHR ECX,0x1f` |
| `1002c904` | `0b c1` | `OR EAX,ECX` |
| `1002c906` | `89 45 f4` | `MOV dword ptr [EBP + -0xc],EAX` |
| `1002c909` | `c1 ea 1f` | `SHR EDX,0x1f` |
| `1002c90c` | `8d 04 3f` | `LEA EAX,[EDI + EDI*0x1]` |
| `1002c90f` | `0b c2` | `OR EAX,EDX` |
| `1002c911` | `81 c6 ff ff 00 00` | `ADD ESI,0xffff` |
| `1002c917` | `89 45 f8` | `MOV dword ptr [EBP + -0x8],EAX` |
| `1002c91a` | `66 85 f6` | `TEST SI,SI` |
| `1002c91d` | `7f ce` | `JG 0x1002c8ed` |
| `1002c91f` | `66 85 f6` | `TEST SI,SI` |
| `1002c922` | `7f 4d` | `JG 0x1002c971` |
| `1002c924` | `81 c6 ff ff 00 00` | `ADD ESI,0xffff` |
| `1002c92a` | `66 85 f6` | `TEST SI,SI` |
| `1002c92d` | `7d 42` | `JGE 0x1002c971` |
| `1002c92f` | `8b c6` | `MOV EAX,ESI` |
| `1002c931` | `f7 d8` | `NEG EAX` |
| `1002c933` | `0f b7 c0` | `MOVZX EAX,AX` |
| `1002c936` | `03 f0` | `ADD ESI,EAX` |
| `1002c938` | `f6 45 f0 01` | `TEST byte ptr [EBP + -0x10],0x1` |
| `1002c93c` | `74 03` | `JZ 0x1002c941` |
| `1002c93e` | `ff 45 b0` | `INC dword ptr [EBP + -0x50]` |
| `1002c941` | `8b 4d f8` | `MOV ECX,dword ptr [EBP + -0x8]` |
| `1002c944` | `8b 7d f4` | `MOV EDI,dword ptr [EBP + -0xc]` |
| `1002c947` | `8b 55 f4` | `MOV EDX,dword ptr [EBP + -0xc]` |
| `1002c94a` | `d1 6d f8` | `SHR dword ptr [EBP + -0x8],0x1` |
| `1002c94d` | `c1 e1 1f` | `SHL ECX,0x1f` |
| `1002c950` | `d1 ef` | `SHR EDI,0x1` |
| `1002c952` | `0b f9` | `OR EDI,ECX` |
| `1002c954` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c957` | `c1 e2 1f` | `SHL EDX,0x1f` |
| `1002c95a` | `d1 e9` | `SHR ECX,0x1` |
| `1002c95c` | `0b ca` | `OR ECX,EDX` |
| `1002c95e` | `48` | `DEC EAX` |
| `1002c95f` | `89 7d f4` | `MOV dword ptr [EBP + -0xc],EDI` |
| `1002c962` | `89 4d f0` | `MOV dword ptr [EBP + -0x10],ECX` |
| `1002c965` | `75 d1` | `JNZ 0x1002c938` |
| `1002c967` | `39 45 b0` | `CMP dword ptr [EBP + -0x50],EAX` |
| `1002c96a` | `74 05` | `JZ 0x1002c971` |
| `1002c96c` | `66 83 4d f0 01` | `OR word ptr [EBP + -0x10],0x1` |
| `1002c971` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002c976` | `8b c8` | `MOV ECX,EAX` |
| `1002c978` | `66 39 4d f0` | `CMP word ptr [EBP + -0x10],CX` |
| `1002c97c` | `77 11` | `JA 0x1002c98f` |
| `1002c97e` | `8b 4d f0` | `MOV ECX,dword ptr [EBP + -0x10]` |
| `1002c981` | `81 e1 ff ff 01 00` | `AND ECX,0x1ffff` |
| `1002c987` | `81 f9 00 80 01 00` | `CMP ECX,0x18000` |
| `1002c98d` | `75 34` | `JNZ 0x1002c9c3` |
| `1002c98f` | `83 7d f2 ff` | `CMP dword ptr [EBP + -0xe],-0x1` |
| `1002c993` | `75 2b` | `JNZ 0x1002c9c0` |
| `1002c995` | `83 65 f2 00` | `AND dword ptr [EBP + -0xe],0x0` |
| `1002c999` | `83 7d f6 ff` | `CMP dword ptr [EBP + -0xa],-0x1` |
| `1002c99d` | `75 1c` | `JNZ 0x1002c9bb` |
| `1002c99f` | `83 65 f6 00` | `AND dword ptr [EBP + -0xa],0x0` |
| `1002c9a3` | `b9 ff ff 00 00` | `MOV ECX,0xffff` |
| `1002c9a8` | `66 39 4d fa` | `CMP word ptr [EBP + -0x6],CX` |
| `1002c9ac` | `75 07` | `JNZ 0x1002c9b5` |
| `1002c9ae` | `66 89 45 fa` | `MOV word ptr [EBP + -0x6],AX` |
| `1002c9b2` | `46` | `INC ESI` |
| `1002c9b3` | `eb 0e` | `JMP 0x1002c9c3` |
| `1002c9b5` | `66 ff 45 fa` | `INC word ptr [EBP + -0x6]` |
| `1002c9b9` | `eb 08` | `JMP 0x1002c9c3` |
| `1002c9bb` | `ff 45 f6` | `INC dword ptr [EBP + -0xa]` |
| `1002c9be` | `eb 03` | `JMP 0x1002c9c3` |
| `1002c9c0` | `ff 45 f2` | `INC dword ptr [EBP + -0xe]` |
| `1002c9c3` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c9c8` | `66 3b f0` | `CMP SI,AX` |
| `1002c9cb` | `72 23` | `JC 0x1002c9f0` |
| `1002c9cd` | `33 c0` | `XOR EAX,EAX` |
| `1002c9cf` | `33 c9` | `XOR ECX,ECX` |
| `1002c9d1` | `66 39 45 a4` | `CMP word ptr [EBP + -0x5c],AX` |
| `1002c9d5` | `89 45 e4` | `MOV dword ptr [EBP + -0x1c],EAX` |
| `1002c9d8` | `0f 94 c1` | `SETZ CL` |
| `1002c9db` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1002c9de` | `49` | `DEC ECX` |
| `1002c9df` | `81 e1 00 00 00 80` | `AND ECX,0x80000000` |
| `1002c9e5` | `81 c1 00 80 ff 7f` | `ADD ECX,0x7fff8000` |
| `1002c9eb` | `89 4d e8` | `MOV dword ptr [EBP + -0x18],ECX` |
| `1002c9ee` | `eb 3b` | `JMP 0x1002ca2b` |
| `1002c9f0` | `66 8b 45 f2` | `MOV AX,word ptr [EBP + -0xe]` |
| `1002c9f4` | `0b 75 a4` | `OR ESI,dword ptr [EBP + -0x5c]` |
| `1002c9f7` | `66 89 45 e0` | `MOV word ptr [EBP + -0x20],AX` |
| `1002c9fb` | `8b 45 f4` | `MOV EAX,dword ptr [EBP + -0xc]` |
| `1002c9fe` | `89 45 e2` | `MOV dword ptr [EBP + -0x1e],EAX` |
| `1002ca01` | `8b 45 f8` | `MOV EAX,dword ptr [EBP + -0x8]` |
| `1002ca04` | `89 45 e6` | `MOV dword ptr [EBP + -0x1a],EAX` |
| `1002ca07` | `66 89 75 ea` | `MOV word ptr [EBP + -0x16],SI` |
| `1002ca0b` | `eb 1e` | `JMP 0x1002ca2b` |
| `1002ca0d` | `33 c0` | `XOR EAX,EAX` |
| `1002ca0f` | `66 85 db` | `TEST BX,BX` |
| `1002ca12` | `0f 94 c0` | `SETZ AL` |
| `1002ca15` | `83 65 e4 00` | `AND dword ptr [EBP + -0x1c],0x0` |
| `1002ca19` | `48` | `DEC EAX` |
| `1002ca1a` | `25 00 00 00 80` | `AND EAX,0x80000000` |
| `1002ca1f` | `05 00 80 ff 7f` | `ADD EAX,0x7fff8000` |
| `1002ca24` | `83 65 e0 00` | `AND dword ptr [EBP + -0x20],0x0` |
| `1002ca28` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1002ca2b` | `f6 45 18 01` | `TEST byte ptr [EBP + 0x18],0x1` |
| `1002ca2f` | `8b 55 a0` | `MOV EDX,dword ptr [EBP + -0x60]` |
| `1002ca32` | `8b 45 b4` | `MOV EAX,dword ptr [EBP + -0x4c]` |
| `1002ca35` | `8b 7d 14` | `MOV EDI,dword ptr [EBP + 0x14]` |
| `1002ca38` | `66 89 02` | `MOV word ptr [EDX],AX` |
| `1002ca3b` | `74 32` | `JZ 0x1002ca6f` |
| `1002ca3d` | `98` | `CWDE` |
| `1002ca3e` | `03 f8` | `ADD EDI,EAX` |
| `1002ca40` | `85 ff` | `TEST EDI,EDI` |
| `1002ca42` | `7f 2b` | `JG 0x1002ca6f` |
| `1002ca44` | `33 c0` | `XOR EAX,EAX` |
| `1002ca46` | `66 89 02` | `MOV word ptr [EDX],AX` |
| `1002ca49` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002ca4e` | `66 39 45 90` | `CMP word ptr [EBP + -0x70],AX` |
| `1002ca52` | `c6 42 03 01` | `MOV byte ptr [EDX + 0x3],0x1` |
| `1002ca56` | `0f 95 c0` | `SETNZ AL` |
| `1002ca59` | `fe c8` | `DEC AL` |
| `1002ca5b` | `24 0d` | `AND AL,0xd` |
| `1002ca5d` | `04 20` | `ADD AL,0x20` |
| `1002ca5f` | `88 42 02` | `MOV byte ptr [EDX + 0x2],AL` |
| `1002ca62` | `c6 42 04 30` | `MOV byte ptr [EDX + 0x4],0x30` |
| `1002ca66` | `c6 42 05 00` | `MOV byte ptr [EDX + 0x5],0x0` |
| `1002ca6a` | `e9 5e f9 ff ff` | `JMP 0x1002c3cd` |
| `1002ca6f` | `83 ff 15` | `CMP EDI,0x15` |
| `1002ca72` | `7e 03` | `JLE 0x1002ca77` |
| `1002ca74` | `6a 15` | `PUSH 0x15` |
| `1002ca76` | `5f` | `POP EDI` |
| `1002ca77` | `8b 75 e8` | `MOV ESI,dword ptr [EBP + -0x18]` |
| `1002ca7a` | `c1 ee 10` | `SHR ESI,0x10` |
| `1002ca7d` | `81 ee fe 3f 00 00` | `SUB ESI,0x3ffe` |
| `1002ca83` | `33 c0` | `XOR EAX,EAX` |
| `1002ca85` | `66 89 45 ea` | `MOV word ptr [EBP + -0x16],AX` |
| `1002ca89` | `c7 45 bc 08 00 00 00` | `MOV dword ptr [EBP + -0x44],0x8` |
| `1002ca90` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1002ca93` | `8b 5d e4` | `MOV EBX,dword ptr [EBP + -0x1c]` |
| `1002ca96` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1002ca99` | `d1 65 e0` | `SHL dword ptr [EBP + -0x20],0x1` |
| `1002ca9c` | `c1 e8 1f` | `SHR EAX,0x1f` |
| `1002ca9f` | `03 db` | `ADD EBX,EBX` |
| `1002caa1` | `0b d8` | `OR EBX,EAX` |
| `1002caa3` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1002caa6` | `c1 e9 1f` | `SHR ECX,0x1f` |
| `1002caa9` | `03 c0` | `ADD EAX,EAX` |
| `1002caab` | `0b c1` | `OR EAX,ECX` |
| `1002caad` | `ff 4d bc` | `DEC dword ptr [EBP + -0x44]` |
| `1002cab0` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1002cab3` | `89 45 e8` | `MOV dword ptr [EBP + -0x18],EAX` |
| `1002cab6` | `75 d8` | `JNZ 0x1002ca90` |
| `1002cab8` | `85 f6` | `TEST ESI,ESI` |
| `1002caba` | `7d 32` | `JGE 0x1002caee` |
| `1002cabc` | `f7 de` | `NEG ESI` |
| `1002cabe` | `81 e6 ff 00 00 00` | `AND ESI,0xff` |
| `1002cac4` | `7e 28` | `JLE 0x1002caee` |
| `1002cac6` | `8b 45 e8` | `MOV EAX,dword ptr [EBP + -0x18]` |
| `1002cac9` | `8b 5d e4` | `MOV EBX,dword ptr [EBP + -0x1c]` |
| `1002cacc` | `8b 4d e4` | `MOV ECX,dword ptr [EBP + -0x1c]` |
| `1002cacf` | `d1 6d e8` | `SHR dword ptr [EBP + -0x18],0x1` |
| `1002cad2` | `c1 e0 1f` | `SHL EAX,0x1f` |
| `1002cad5` | `d1 eb` | `SHR EBX,0x1` |
| `1002cad7` | `0b d8` | `OR EBX,EAX` |
| `1002cad9` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1002cadc` | `c1 e1 1f` | `SHL ECX,0x1f` |
| `1002cadf` | `d1 e8` | `SHR EAX,0x1` |
| `1002cae1` | `0b c1` | `OR EAX,ECX` |
| `1002cae3` | `4e` | `DEC ESI` |
| `1002cae4` | `89 5d e4` | `MOV dword ptr [EBP + -0x1c],EBX` |
| `1002cae7` | `89 45 e0` | `MOV dword ptr [EBP + -0x20],EAX` |
| `1002caea` | `85 f6` | `TEST ESI,ESI` |
| `1002caec` | `7f d8` | `JG 0x1002cac6` |
| `1002caee` | `8d 47 01` | `LEA EAX,[EDI + 0x1]` |
| `1002caf1` | `8d 5a 04` | `LEA EBX,[EDX + 0x4]` |
| `1002caf4` | `89 5d c0` | `MOV dword ptr [EBP + -0x40],EBX` |
| `1002caf7` | `89 45 b4` | `MOV dword ptr [EBP + -0x4c],EAX` |
| `1002cafa` | `85 c0` | `TEST EAX,EAX` |
| `1002cafc` | `0f 8e b5 00 00 00` | `JLE 0x1002cbb7` |
| `1002cb02` | `8b 55 e0` | `MOV EDX,dword ptr [EBP + -0x20]` |
| `1002cb05` | `8b 45 e4` | `MOV EAX,dword ptr [EBP + -0x1c]` |
| `1002cb08` | `8d 75 e0` | `LEA ESI,[EBP + -0x20]` |
| `1002cb0b` | `8d 7d c4` | `LEA EDI,[EBP + -0x3c]` |
| `1002cb0e` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002cb0f` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002cb10` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002cb11` | `d1 65 e0` | `SHL dword ptr [EBP + -0x20],0x1` |
| `1002cb14` | `8b 7d e0` | `MOV EDI,dword ptr [EBP + -0x20]` |
| `1002cb17` | `d1 65 e0` | `SHL dword ptr [EBP + -0x20],0x1` |
| `1002cb1a` | `c1 ea 1f` | `SHR EDX,0x1f` |
| `1002cb1d` | `8d 0c 00` | `LEA ECX,[EAX + EAX*0x1]` |
| `1002cb20` | `0b ca` | `OR ECX,EDX` |
| `1002cb22` | `8b 55 e8` | `MOV EDX,dword ptr [EBP + -0x18]` |
| `1002cb25` | `8b f0` | `MOV ESI,EAX` |
| `1002cb27` | `c1 ee 1f` | `SHR ESI,0x1f` |
| `1002cb2a` | `03 d2` | `ADD EDX,EDX` |
| `1002cb2c` | `0b d6` | `OR EDX,ESI` |
| `1002cb2e` | `8b c1` | `MOV EAX,ECX` |
| `1002cb30` | `8d 34 09` | `LEA ESI,[ECX + ECX*0x1]` |
| `1002cb33` | `c1 e8 1f` | `SHR EAX,0x1f` |
| `1002cb36` | `8d 0c 12` | `LEA ECX,[EDX + EDX*0x1]` |
| `1002cb39` | `8b 55 c4` | `MOV EDX,dword ptr [EBP + -0x3c]` |
| `1002cb3c` | `c1 ef 1f` | `SHR EDI,0x1f` |
| `1002cb3f` | `0b c8` | `OR ECX,EAX` |
| `1002cb41` | `8b 45 e0` | `MOV EAX,dword ptr [EBP + -0x20]` |
| `1002cb44` | `0b f7` | `OR ESI,EDI` |
| `1002cb46` | `8d 3c 02` | `LEA EDI,[EDX + EAX*0x1]` |
| `1002cb49` | `3b f8` | `CMP EDI,EAX` |
| `1002cb4b` | `72 04` | `JC 0x1002cb51` |
| `1002cb4d` | `3b fa` | `CMP EDI,EDX` |
| `1002cb4f` | `73 18` | `JNC 0x1002cb69` |
| `1002cb51` | `8d 46 01` | `LEA EAX,[ESI + 0x1]` |
| `1002cb54` | `33 d2` | `XOR EDX,EDX` |
| `1002cb56` | `3b c6` | `CMP EAX,ESI` |
| `1002cb58` | `72 05` | `JC 0x1002cb5f` |
| `1002cb5a` | `83 f8 01` | `CMP EAX,0x1` |
| `1002cb5d` | `73 03` | `JNC 0x1002cb62` |
| `1002cb5f` | `33 d2` | `XOR EDX,EDX` |
| `1002cb61` | `42` | `INC EDX` |
| `1002cb62` | `8b f0` | `MOV ESI,EAX` |
| `1002cb64` | `85 d2` | `TEST EDX,EDX` |
| `1002cb66` | `74 01` | `JZ 0x1002cb69` |
| `1002cb68` | `41` | `INC ECX` |
| `1002cb69` | `8b 45 c8` | `MOV EAX,dword ptr [EBP + -0x38]` |
| `1002cb6c` | `8d 14 30` | `LEA EDX,[EAX + ESI*0x1]` |
| `1002cb6f` | `89 55 bc` | `MOV dword ptr [EBP + -0x44],EDX` |
| `1002cb72` | `3b d6` | `CMP EDX,ESI` |
| `1002cb74` | `72 04` | `JC 0x1002cb7a` |
| `1002cb76` | `3b d0` | `CMP EDX,EAX` |
| `1002cb78` | `73 01` | `JNC 0x1002cb7b` |
| `1002cb7a` | `41` | `INC ECX` |
| `1002cb7b` | `03 4d cc` | `ADD ECX,dword ptr [EBP + -0x34]` |
| `1002cb7e` | `c1 ea 1f` | `SHR EDX,0x1f` |
| `1002cb81` | `03 c9` | `ADD ECX,ECX` |
| `1002cb83` | `0b ca` | `OR ECX,EDX` |
| `1002cb85` | `8d 34 3f` | `LEA ESI,[EDI + EDI*0x1]` |
| `1002cb88` | `89 75 e0` | `MOV dword ptr [EBP + -0x20],ESI` |
| `1002cb8b` | `8b 75 bc` | `MOV ESI,dword ptr [EBP + -0x44]` |
| `1002cb8e` | `89 4d e8` | `MOV dword ptr [EBP + -0x18],ECX` |
| `1002cb91` | `c1 e9 18` | `SHR ECX,0x18` |
| `1002cb94` | `03 f6` | `ADD ESI,ESI` |
| `1002cb96` | `80 c1 30` | `ADD CL,0x30` |
| `1002cb99` | `8b c7` | `MOV EAX,EDI` |
| `1002cb9b` | `c1 e8 1f` | `SHR EAX,0x1f` |
| `1002cb9e` | `0b f0` | `OR ESI,EAX` |
| `1002cba0` | `88 0b` | `MOV byte ptr [EBX],CL` |
| `1002cba2` | `43` | `INC EBX` |
| `1002cba3` | `ff 4d b4` | `DEC dword ptr [EBP + -0x4c]` |
| `1002cba6` | `83 7d b4 00` | `CMP dword ptr [EBP + -0x4c],0x0` |
| `1002cbaa` | `89 75 e4` | `MOV dword ptr [EBP + -0x1c],ESI` |
| `1002cbad` | `c6 45 eb 00` | `MOV byte ptr [EBP + -0x15],0x0` |
| `1002cbb1` | `0f 8f 4b ff ff ff` | `JG 0x1002cb02` |
| `1002cbb7` | `4b` | `DEC EBX` |
| `1002cbb8` | `8a 03` | `MOV AL,byte ptr [EBX]` |
| `1002cbba` | `4b` | `DEC EBX` |
| `1002cbbb` | `3c 35` | `CMP AL,0x35` |
| `1002cbbd` | `7d 0e` | `JGE 0x1002cbcd` |
| `1002cbbf` | `8b 4d c0` | `MOV ECX,dword ptr [EBP + -0x40]` |
| `1002cbc2` | `eb 44` | `JMP 0x1002cc08` |
| `1002cbc4` | `80 3b 39` | `CMP byte ptr [EBX],0x39` |
| `1002cbc7` | `75 09` | `JNZ 0x1002cbd2` |
| `1002cbc9` | `c6 03 30` | `MOV byte ptr [EBX],0x30` |
| `1002cbcc` | `4b` | `DEC EBX` |
| `1002cbcd` | `3b 5d c0` | `CMP EBX,dword ptr [EBP + -0x40]` |
| `1002cbd0` | `73 f2` | `JNC 0x1002cbc4` |
| `1002cbd2` | `8b 45 a0` | `MOV EAX,dword ptr [EBP + -0x60]` |
| `1002cbd5` | `3b 5d c0` | `CMP EBX,dword ptr [EBP + -0x40]` |
| `1002cbd8` | `73 04` | `JNC 0x1002cbde` |
| `1002cbda` | `43` | `INC EBX` |
| `1002cbdb` | `66 ff 00` | `INC word ptr [EAX]` |
| `1002cbde` | `fe 03` | `INC byte ptr [EBX]` |
| `1002cbe0` | `2a d8` | `SUB BL,AL` |
| `1002cbe2` | `80 eb 03` | `SUB BL,0x3` |
| `1002cbe5` | `0f be cb` | `MOVSX ECX,BL` |
| `1002cbe8` | `88 58 03` | `MOV byte ptr [EAX + 0x3],BL` |
| `1002cbeb` | `c6 44 01 04 00` | `MOV byte ptr [ECX + EAX*0x1 + 0x4],0x0` |
| `1002cbf0` | `8b 45 8c` | `MOV EAX,dword ptr [EBP + -0x74]` |
| `1002cbf3` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002cbf6` | `5f` | `POP EDI` |
| `1002cbf7` | `5e` | `POP ESI` |
| `1002cbf8` | `33 cd` | `XOR ECX,EBP` |
| `1002cbfa` | `5b` | `POP EBX` |
| `1002cbfb` | `e8 cb 40 fe ff` | `CALL 0x10010ccb` |
| `1002cc00` | `c9` | `LEAVE` |
| `1002cc01` | `c3` | `RET` |
| `1002cc02` | `80 3b 30` | `CMP byte ptr [EBX],0x30` |
| `1002cc05` | `75 05` | `JNZ 0x1002cc0c` |
| `1002cc07` | `4b` | `DEC EBX` |
| `1002cc08` | `3b d9` | `CMP EBX,ECX` |
| `1002cc0a` | `73 f6` | `JNC 0x1002cc02` |
| `1002cc0c` | `8b 45 a0` | `MOV EAX,dword ptr [EBP + -0x60]` |
| `1002cc0f` | `3b d9` | `CMP EBX,ECX` |
| `1002cc11` | `73 cd` | `JNC 0x1002cbe0` |
| `1002cc13` | `33 d2` | `XOR EDX,EDX` |
| `1002cc15` | `66 89 10` | `MOV word ptr [EAX],DX` |
| `1002cc18` | `ba 00 80 00 00` | `MOV EDX,0x8000` |
| `1002cc1d` | `66 39 55 90` | `CMP word ptr [EBP + -0x70],DX` |
| `1002cc21` | `c6 40 03 01` | `MOV byte ptr [EAX + 0x3],0x1` |
| `1002cc25` | `0f 95 c2` | `SETNZ DL` |
| `1002cc28` | `fe ca` | `DEC DL` |
| `1002cc2a` | `80 e2 0d` | `AND DL,0xd` |
| `1002cc2d` | `80 c2 20` | `ADD DL,0x20` |
| `1002cc30` | `88 50 02` | `MOV byte ptr [EAX + 0x2],DL` |
| `1002cc33` | `c6 01 30` | `MOV byte ptr [ECX],0x30` |
| `1002cc36` | `c6 40 05 00` | `MOV byte ptr [EAX + 0x5],0x0` |
| `1002cc3a` | `e9 8e f7 ff ff` | `JMP 0x1002c3cd` |
