# 1002bc23 `___strgtold12_l`

## Metadata

| Field | Value |
| --- | --- |
| `entry` | 1002bc23 |
| `name` | ___strgtold12_l |
| `namespace` | Global |
| `signature` | uint __cdecl ___strgtold12_l(_LDBL12 * pld12, char * * p_end_ptr, char * str, int mult12, int scale, int decpt, int implicit_E, _locale_t _Locale) |
| `size_bytes` | 1735 |
| `stack_frame_size` | 164 |
| `calling_convention` | __cdecl |
| `source_type` | ANALYSIS |
| `export_names` | ___strgtold12_l |

## Decompiled C

```c

/* Library Function - Single Match
    ___strgtold12_l
   
   Library: Visual Studio 2008 Release */

uint __cdecl
___strgtold12_l(_LDBL12 *pld12,char **p_end_ptr,char *str,int mult12,int scale,int decpt,
               int implicit_E,_locale_t _Locale)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  ushort uVar9;
  char cVar10;
  int *piVar11;
  uint uVar12;
  ushort *puVar13;
  uint uVar14;
  ushort uVar15;
  int iVar16;
  ushort uVar17;
  char *pcVar18;
  undefined4 uVar19;
  ushort uVar20;
  undefined4 uVar21;
  char *pcVar22;
  short *psVar23;
  int local_6c;
  int local_68;
  ushort *local_64;
  ushort *local_60;
  int local_5c;
  char *local_58;
  int local_54;
  uint local_50;
  ushort local_4c;
  undefined4 uStack_4a;
  undefined2 uStack_46;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  byte local_30;
  undefined1 uStack_2f;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  ushort uStack_26;
  char local_24 [23];
  char local_d;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  iVar16 = 0;
  pcVar22 = local_24;
  uVar9 = 0;
  local_6c = 1;
  local_50 = 0;
  bVar6 = false;
  bVar8 = false;
  bVar7 = false;
  local_68 = 0;
  local_54 = 0;
  if (_Locale != (_locale_t)0x0) {
    local_58 = str;
    for (; (((cVar10 = *str, cVar10 == ' ' || (cVar10 == '\t')) || (cVar10 == '\n')) ||
           (cVar10 == '\r')); str = str + 1) {
    }
LAB_1002bcaa:
    cVar10 = *str;
    pcVar18 = str + 1;
    switch(iVar16) {
    case 0:
      if ((byte)(cVar10 - 0x31U) < 9) {
LAB_1002bcc7:
        iVar16 = 3;
        goto LAB_1002bcc9;
      }
      if (cVar10 == **(char **)_Locale->locinfo[1].lc_codepage) {
LAB_1002bcde:
        iVar16 = 5;
        str = pcVar18;
      }
      else if (cVar10 == '+') {
        uVar9 = 0;
        iVar16 = 2;
        str = pcVar18;
      }
      else {
        if (cVar10 != '-') {
          if (cVar10 == '0') goto LAB_1002bcf8;
          goto LAB_1002be83;
        }
        iVar16 = 2;
        uVar9 = 0x8000;
        str = pcVar18;
      }
      goto LAB_1002bcaa;
    case 1:
      bVar6 = true;
      if ((byte)(cVar10 - 0x31U) < 9) goto LAB_1002bcc7;
      if (cVar10 == **(char **)_Locale->locinfo[1].lc_codepage) goto LAB_1002bd2f;
      if ((cVar10 == '+') || (cVar10 == '-')) goto LAB_1002bd5f;
      if (cVar10 == '0') goto LAB_1002bcf8;
      goto LAB_1002bd3f;
    case 2:
      if ((byte)(cVar10 - 0x31U) < 9) goto LAB_1002bcc7;
      if (cVar10 == **(char **)_Locale->locinfo[1].lc_codepage) goto LAB_1002bcde;
      str = local_58;
      if (cVar10 != '0') goto LAB_1002beae;
LAB_1002bcf8:
      iVar16 = 1;
      str = pcVar18;
      goto LAB_1002bcaa;
    case 3:
      while (('/' < cVar10 && (cVar10 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar22 = cVar10 + -0x30;
          pcVar22 = pcVar22 + 1;
        }
        else {
          local_54 = local_54 + 1;
        }
        cVar10 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      }
      if (cVar10 != **(char **)_Locale->locinfo[1].lc_codepage) goto LAB_1002bdd2;
LAB_1002bd2f:
      bVar6 = true;
      iVar16 = 4;
      str = pcVar18;
      goto LAB_1002bcaa;
    case 4:
      bVar8 = true;
      if (local_50 == 0) {
        while (cVar10 == '0') {
          local_54 = local_54 + -1;
          cVar10 = *pcVar18;
          pcVar18 = pcVar18 + 1;
        }
      }
      while (('/' < cVar10 && (cVar10 < ':'))) {
        if (local_50 < 0x19) {
          local_50 = local_50 + 1;
          *pcVar22 = cVar10 + -0x30;
          pcVar22 = pcVar22 + 1;
          local_54 = local_54 + -1;
        }
        cVar10 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      }
LAB_1002bdd2:
      if ((cVar10 == '+') || (cVar10 == '-')) {
LAB_1002bd5f:
        bVar6 = true;
        iVar16 = 0xb;
        str = pcVar18 + -1;
      }
      else {
LAB_1002bd3f:
        bVar6 = true;
        if ((cVar10 < 'D') || (('E' < cVar10 && ((cVar10 < 'd' || ('e' < cVar10))))))
        goto LAB_1002be83;
        iVar16 = 6;
        str = pcVar18;
      }
      goto LAB_1002bcaa;
    case 5:
      bVar8 = true;
      str = local_58;
      if ((byte)(cVar10 - 0x30U) < 10) {
        iVar16 = 4;
        goto LAB_1002bcc9;
      }
      goto LAB_1002beae;
    case 6:
      local_58 = str + -1;
      if (8 < (byte)(cVar10 - 0x31U)) {
        if (cVar10 == '+') goto LAB_1002be6a;
        if (cVar10 == '-') goto LAB_1002be5e;
LAB_1002be51:
        str = local_58;
        if (cVar10 != '0') goto LAB_1002beae;
        iVar16 = 8;
        str = pcVar18;
        goto LAB_1002bcaa;
      }
      break;
    case 7:
      if (8 < (byte)(cVar10 - 0x31U)) goto LAB_1002be51;
      break;
    case 8:
      bVar7 = true;
      while (cVar10 == '0') {
        cVar10 = *pcVar18;
        pcVar18 = pcVar18 + 1;
      }
      if (8 < (byte)(cVar10 - 0x31U)) goto LAB_1002be83;
      break;
    case 9:
      bVar7 = true;
      local_68 = 0;
      goto LAB_1002bf10;
    default:
      goto switchD_1002bcb6_caseD_a;
    case 0xb:
      if (implicit_E != 0) {
        local_58 = str;
        if (cVar10 == '+') {
LAB_1002be6a:
          iVar16 = 7;
          str = pcVar18;
        }
        else {
          if (cVar10 != '-') goto LAB_1002beae;
LAB_1002be5e:
          local_6c = -1;
          iVar16 = 7;
          str = pcVar18;
        }
        goto LAB_1002bcaa;
      }
      iVar16 = 10;
      pcVar18 = str;
switchD_1002bcb6_caseD_a:
      str = pcVar18;
      if (iVar16 != 10) goto LAB_1002bcaa;
      goto LAB_1002beae;
    }
    iVar16 = 9;
LAB_1002bcc9:
    str = pcVar18 + -1;
    goto LAB_1002bcaa;
  }
  piVar11 = __errno();
  *piVar11 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  iVar4 = CONCAT22(local_40._2_2_,(undefined2)local_40);
  uVar2 = CONCAT22(uStack_38._2_2_,(ushort)uStack_38);
  goto LAB_1002c2db;
LAB_1002bf10:
  if ((cVar10 < '0') || ('9' < cVar10)) goto LAB_1002bf2b;
  local_68 = local_68 * 10 + -0x30 + (int)cVar10;
  if (local_68 < 0x1451) {
    cVar10 = *pcVar18;
    pcVar18 = pcVar18 + 1;
    goto LAB_1002bf10;
  }
  local_68 = 0x1451;
LAB_1002bf2b:
  while (('/' < cVar10 && (cVar10 < ':'))) {
    cVar10 = *pcVar18;
    pcVar18 = pcVar18 + 1;
  }
LAB_1002be83:
  str = pcVar18 + -1;
LAB_1002beae:
  *p_end_ptr = str;
  if (bVar6) {
    if (0x18 < local_50) {
      if ('\x04' < local_d) {
        local_d = local_d + '\x01';
      }
      pcVar22 = pcVar22 + -1;
      local_54 = local_54 + 1;
      local_50 = 0x18;
    }
    if (local_50 == 0) goto LAB_1002c2bd;
    while (pcVar22 = pcVar22 + -1, *pcVar22 == '\0') {
      local_50 = local_50 - 1;
      local_54 = local_54 + 1;
    }
    ___mtold12(local_24,local_50,&local_40);
    iVar5 = CONCAT22(local_3c._2_2_,(undefined2)local_3c);
    iVar4 = CONCAT22(local_40._2_2_,(undefined2)local_40);
    iVar3 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
    iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e);
    uVar2 = CONCAT22(uStack_38._2_2_,(ushort)uStack_38);
    uVar14 = CONCAT22(uStack_38._2_2_,(ushort)uStack_38);
    iVar16 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a);
    if (local_6c < 0) {
      local_68 = -local_68;
    }
    local_58 = (char *)(local_68 + local_54);
    if (!bVar7) {
      local_58 = (char *)((int)local_58 + scale);
    }
    if (!bVar8) {
      local_58 = (char *)((int)local_58 - decpt);
    }
    if ((int)local_58 < 0x1451) {
      if ((int)local_58 < -0x1450) goto LAB_1002c2bd;
      pcVar22 = s___AUCallbacks_Udp___100386d4 + 0xc;
      if (local_58 != (char *)0x0) {
        if ((int)local_58 < 0) {
          local_58 = (char *)-(int)local_58;
          pcVar22 = &DAT_10038840;
        }
        if (mult12 == 0) {
          local_40._0_2_ = 0;
        }
        iVar16 = uStack_4a;
        uVar14 = uVar2;
        iVar1 = uStack_2e;
        iVar3 = uStack_2a;
        iVar4 = CONCAT22(local_40._2_2_,(undefined2)local_40);
        iVar5 = local_3c;
joined_r0x1002bfb8:
        if (local_58 != (char *)0x0) {
          uStack_38._2_2_ = (ushort)(uVar14 >> 0x10);
          uVar2 = (int)local_58 >> 3;
          pcVar22 = pcVar22 + 0x54;
          uVar12 = (uint)local_58 & 7;
          local_58 = (char *)uVar2;
          if (uVar12 != 0) {
            puVar13 = (ushort *)(pcVar22 + uVar12 * 0xc);
            if (0x7fff < *puVar13) {
              local_4c = (ushort)*(undefined4 *)puVar13;
              uStack_4a._0_2_ = (undefined2)((uint)*(undefined4 *)puVar13 >> 0x10);
              uStack_4a._2_2_ = (undefined2)*(undefined4 *)(puVar13 + 2);
              uStack_46 = (undefined2)((uint)*(undefined4 *)(puVar13 + 2) >> 0x10);
              local_44 = *(undefined4 *)(puVar13 + 4);
              iVar16 = CONCAT22(uStack_4a._2_2_,(undefined2)uStack_4a) + -1;
              uStack_4a._0_2_ = (undefined2)iVar16;
              uStack_4a._2_2_ = (undefined2)((uint)iVar16 >> 0x10);
              puVar13 = &local_4c;
            }
            local_54 = 0;
            local_30 = 0;
            uStack_2f = 0;
            uStack_2e._0_2_ = 0;
            uStack_2e._2_2_ = 0;
            iVar1 = 0;
            uStack_2a._0_2_ = 0;
            uStack_2a._2_2_ = 0;
            iVar3 = 0;
            uStack_26 = 0;
            uVar15 = puVar13[5] & 0x7fff;
            uVar20 = (puVar13[5] ^ uStack_38._2_2_) & 0x8000;
            uVar17 = uVar15 + (uStack_38._2_2_ & 0x7fff);
            if ((((uStack_38._2_2_ & 0x7fff) < 0x7fff) && (uVar15 < 0x7fff)) && (uVar17 < 0xbffe)) {
              if (0x3fbf < uVar17) {
                if ((((uVar14 & 0x7fff0000) == 0) &&
                    (uVar17 = uVar17 + 1, (uVar14 & 0x7fffffff) == 0)) &&
                   ((iVar5 == 0 && (iVar4 == 0)))) {
                  uStack_38._2_2_ = 0;
                  uVar14 = uVar14 & 0xffff;
                  iVar1 = 0;
                  iVar3 = 0;
                }
                else if (((uVar15 == 0) &&
                         (uVar17 = uVar17 + 1, (*(uint *)(puVar13 + 4) & 0x7fffffff) == 0)) &&
                        ((*(int *)(puVar13 + 2) == 0 && (*(int *)puVar13 == 0)))) {
                  uStack_38._0_2_ = 0;
                  uStack_38._2_2_ = 0;
                  uVar14 = 0;
                  local_3c._0_2_ = 0;
                  local_3c._2_2_ = 0;
                  local_40._0_2_ = 0;
                  local_40._2_2_ = 0;
                  iVar4 = 0;
                  iVar5 = 0;
                }
                else {
                  local_6c = 0;
                  psVar23 = (short *)((int)&uStack_2e + 2);
                  local_5c = 5;
                  do {
                    local_68 = local_5c;
                    if (0 < local_5c) {
                      local_60 = (ushort *)((int)&local_40 + local_6c * 2);
                      local_64 = puVar13 + 4;
                      do {
                        bVar6 = false;
                        uVar14 = *(uint *)(psVar23 + -2) + (uint)*local_64 * (uint)*local_60;
                        if ((uVar14 < *(uint *)(psVar23 + -2)) ||
                           (uVar14 < (uint)*local_64 * (uint)*local_60)) {
                          bVar6 = true;
                        }
                        *(uint *)(psVar23 + -2) = uVar14;
                        if (bVar6) {
                          *psVar23 = *psVar23 + 1;
                        }
                        local_60 = local_60 + 1;
                        local_64 = local_64 + -1;
                        local_68 = local_68 + -1;
                      } while (0 < local_68);
                    }
                    psVar23 = psVar23 + 1;
                    local_6c = local_6c + 1;
                    local_5c = local_5c + -1;
                  } while (0 < local_5c);
                  uVar17 = uVar17 + 0xc002;
                  if ((short)uVar17 < 1) {
LAB_1002c173:
                    uVar17 = uVar17 - 1;
                    if ((short)uVar17 < 0) {
                      uVar14 = (uint)(ushort)-uVar17;
                      uVar17 = 0;
                      do {
                        if ((local_30 & 1) != 0) {
                          local_54 = local_54 + 1;
                        }
                        iVar1 = CONCAT22(uStack_26,uStack_2a._2_2_);
                        uVar2 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_);
                        iVar3 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_);
                        uStack_2a._2_2_ = (ushort)(CONCAT22(uStack_26,uStack_2a._2_2_) >> 1);
                        uStack_26 = uStack_26 >> 1;
                        uStack_2a._0_2_ =
                             (ushort)uStack_2a >> 1 | (ushort)((uint)(iVar1 << 0x1f) >> 0x10);
                        uVar12 = CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) >> 1;
                        uStack_2e._0_2_ =
                             (ushort)uStack_2e >> 1 | (ushort)((uint)(iVar3 << 0x1f) >> 0x10);
                        uVar14 = uVar14 - 1;
                        uStack_2e._2_2_ = (ushort)(uVar2 >> 1);
                        local_30 = (byte)uVar12;
                        uStack_2f = (undefined1)(uVar12 >> 8);
                      } while (uVar14 != 0);
                      if (local_54 != 0) {
                        local_30 = local_30 | 1;
                      }
                    }
                  }
                  else {
                    do {
                      uVar15 = (ushort)uStack_2e;
                      if ((short)uStack_26 < 0) break;
                      iVar3 = CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) << 1;
                      local_30 = (byte)iVar3;
                      uStack_2f = (undefined1)((uint)iVar3 >> 8);
                      uStack_2e._0_2_ = (ushort)((uint)iVar3 >> 0x10);
                      iVar3 = CONCAT22((ushort)uStack_2a,uStack_2e._2_2_) * 2;
                      uStack_2e._2_2_ = (ushort)iVar3 | uVar15 >> 0xf;
                      iVar1 = CONCAT22(uStack_26,uStack_2a._2_2_) * 2;
                      uStack_2a._2_2_ = (ushort)iVar1 | (ushort)uStack_2a >> 0xf;
                      uVar17 = uVar17 - 1;
                      uStack_2a._0_2_ = (ushort)((uint)iVar3 >> 0x10);
                      uStack_26 = (ushort)((uint)iVar1 >> 0x10);
                    } while (0 < (short)uVar17);
                    if ((short)uVar17 < 1) goto LAB_1002c173;
                  }
                  if ((0x8000 < CONCAT11(uStack_2f,local_30)) ||
                     (iVar3 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a),
                     iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e),
                     (CONCAT22((ushort)uStack_2e,CONCAT11(uStack_2f,local_30)) & 0x1ffff) == 0x18000
                     )) {
                    if (CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) == -1) {
                      uStack_2e._0_2_ = 0;
                      uStack_2e._2_2_ = 0;
                      iVar1 = 0;
                      if (CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) == -1) {
                        uStack_2a._0_2_ = 0;
                        uStack_2a._2_2_ = 0;
                        if (uStack_26 == 0xffff) {
                          uStack_26 = 0x8000;
                          uVar17 = uVar17 + 1;
                          iVar3 = 0;
                          iVar1 = 0;
                        }
                        else {
                          uStack_26 = uStack_26 + 1;
                          iVar3 = 0;
                          iVar1 = 0;
                        }
                      }
                      else {
                        iVar3 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a) + 1;
                        uStack_2a._0_2_ = (ushort)iVar3;
                        uStack_2a._2_2_ = (ushort)((uint)iVar3 >> 0x10);
                      }
                    }
                    else {
                      iVar1 = CONCAT22(uStack_2e._2_2_,(ushort)uStack_2e) + 1;
                      uStack_2e._0_2_ = (ushort)iVar1;
                      uStack_2e._2_2_ = (ushort)((uint)iVar1 >> 0x10);
                      iVar3 = CONCAT22(uStack_2a._2_2_,(ushort)uStack_2a);
                    }
                  }
                  if (uVar17 < 0x7fff) {
                    local_40 = iVar1;
                    local_3c = iVar3;
                    uStack_38._0_2_ = uStack_26;
                    uStack_38._2_2_ = uVar17 | uVar20;
                    uVar14 = CONCAT22(uVar17 | uVar20,uStack_26);
                    iVar4 = iVar1;
                    iVar5 = iVar3;
                  }
                  else {
                    local_3c._0_2_ = 0;
                    local_3c._2_2_ = 0;
                    local_40._0_2_ = 0;
                    local_40._2_2_ = 0;
                    uVar14 = ((uVar20 == 0) - 1 & 0x80000000) + 0x7fff8000;
                    uStack_38._0_2_ = (ushort)uVar14;
                    uStack_38._2_2_ = (ushort)(uVar14 >> 0x10);
                    iVar4 = 0;
                    iVar5 = 0;
                  }
                }
                goto joined_r0x1002bfb8;
              }
              uVar14 = 0;
              local_3c._0_2_ = 0;
              local_3c._2_2_ = 0;
              local_40._0_2_ = 0;
              local_40._2_2_ = 0;
            }
            else {
              local_3c._0_2_ = 0;
              local_3c._2_2_ = 0;
              uVar14 = ((uVar20 == 0) - 1 & 0x80000000) + 0x7fff8000;
              local_40._0_2_ = 0;
              local_40._2_2_ = 0;
            }
            uStack_38._0_2_ = (ushort)uVar14;
            uStack_38._2_2_ = (ushort)(uVar14 >> 0x10);
            iVar1 = 0;
            iVar3 = 0;
            iVar4 = 0;
            iVar5 = 0;
          }
          goto joined_r0x1002bfb8;
        }
      }
      local_3c._2_2_ = (undefined2)((uint)iVar5 >> 0x10);
      local_3c._0_2_ = (undefined2)iVar5;
      local_40._2_2_ = (undefined2)((uint)iVar4 >> 0x10);
      local_40._0_2_ = (undefined2)iVar4;
      uStack_38._2_2_ = (ushort)(uVar14 >> 0x10);
      uStack_38._0_2_ = (ushort)uVar14;
      uVar21 = CONCAT22((undefined2)local_3c,local_40._2_2_);
      uVar19 = CONCAT22((ushort)uStack_38,local_3c._2_2_);
      uStack_4a = iVar16;
      uVar2 = uVar14;
      uStack_2e = iVar1;
      uStack_2a = iVar3;
      local_3c = iVar5;
    }
    else {
      uVar21 = 0;
      uStack_38._2_2_ = 0x7fff;
      uVar19 = 0x80000000;
      local_40._0_2_ = 0;
    }
  }
  else {
LAB_1002c2bd:
    iVar4 = CONCAT22(local_40._2_2_,(undefined2)local_40);
    uVar2 = CONCAT22(uStack_38._2_2_,(ushort)uStack_38);
    local_40._0_2_ = 0;
    uStack_38._2_2_ = 0;
    uVar19 = 0;
    uVar21 = 0;
  }
  *(undefined2 *)pld12->ld12 = (undefined2)local_40;
  *(ushort *)(pld12->ld12 + 10) = uStack_38._2_2_ | uVar9;
  *(undefined4 *)(pld12->ld12 + 2) = uVar21;
  *(undefined4 *)(pld12->ld12 + 6) = uVar19;
LAB_1002c2db:
  uStack_38 = uVar2;
  local_40 = iVar4;
  uVar14 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return uVar14;
}
```

## Calls

| From | To | Type | Target | Target Entry |
| --- | --- | --- | --- | --- |
| `1002bc6e` | `10015109` | `UNCONDITIONAL_CALL` | __errno | `10015109` |
| `1002bc7e` | `100116af` | `UNCONDITIONAL_CALL` | __invalid_parameter | `100116af` |
| `1002bf4b` | `1002d07c` | `UNCONDITIONAL_CALL` | ___mtold12 | `1002d07c` |
| `1002c2e3` | `10010ccb` | `UNCONDITIONAL_CALL` | __security_check_cookie | `10010ccb` |

## Callers

| From | Function |
| --- | --- |
| `1002ad06` | FID_conflict:__atoflt_l |
| `1002adae` | FID_conflict:__atoflt_l |

## Referenced Strings

No direct string references identified by Ghidra.

## Referenced Data Symbols

| From | Address | Type | Symbol |
| --- | --- | --- | --- |
| `1002bc2b` | `10037490` | `READ` | DAT_10037490 |
| `1002bcb6` | `1002c2eb` | `READ` | switchD_1002bcb6::switchdataD_1002c2eb |
| `1002bcb6` | `1002c307` | `READ` | PTR_caseD_7_1002c307 |
| `1002bcb6` | `1002c30f` | `READ` | PTR_caseD_9_1002c30f |
| `1002bcb6` | `1002c30b` | `READ` | PTR_caseD_8_1002c30b |
| `1002bcb6` | `1002c2ef` | `READ` | PTR_caseD_1_1002c2ef |
| `1002bcb6` | `1002c2f3` | `READ` | PTR_caseD_2_1002c2f3 |
| `1002bf88` | `10038740` | `DATA` | DAT_10038740 |
| `1002bf9f` | `100388a0` | `DATA` | DAT_100388a0 |
| `1002bfd2` | `10038894` | `DATA` | DAT_10038894 |
| `1002bfd2` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002bfe9` | `10038894` | `DATA` | DAT_10038894 |
| `1002bfe9` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002bff3` | `10038894` | `DATA` | DAT_10038894 |
| `1002bff3` | `100388e8` | `DATA` | DAT_100388e8 |
| `1002bff4` | `10038898` | `DATA` | DAT_10038898 |
| `1002bff4` | `100388ec` | `DATA` | DAT_100388ec |
| `1002bff5` | `1003889c` | `DATA` | DAT_1003889c |
| `1002bffc` | `100388f2` | `DATA` | DAT_100388f2 |

## Disassembly

| Address | Bytes | Instruction |
| --- | --- | --- |
| `1002bc23` | `8b ff` | `MOV EDI,EDI` |
| `1002bc25` | `55` | `PUSH EBP` |
| `1002bc26` | `8b ec` | `MOV EBP,ESP` |
| `1002bc28` | `83 ec 7c` | `SUB ESP,0x7c` |
| `1002bc2b` | `a1 90 74 03 10` | `MOV EAX,[0x10037490]` |
| `1002bc30` | `33 c5` | `XOR EAX,EBP` |
| `1002bc32` | `89 45 fc` | `MOV dword ptr [EBP + -0x4],EAX` |
| `1002bc35` | `8b 45 08` | `MOV EAX,dword ptr [EBP + 0x8]` |
| `1002bc38` | `53` | `PUSH EBX` |
| `1002bc39` | `33 db` | `XOR EBX,EBX` |
| `1002bc3b` | `56` | `PUSH ESI` |
| `1002bc3c` | `33 f6` | `XOR ESI,ESI` |
| `1002bc3e` | `89 45 88` | `MOV dword ptr [EBP + -0x78],EAX` |
| `1002bc41` | `8b 45 0c` | `MOV EAX,dword ptr [EBP + 0xc]` |
| `1002bc44` | `46` | `INC ESI` |
| `1002bc45` | `33 c9` | `XOR ECX,ECX` |
| `1002bc47` | `57` | `PUSH EDI` |
| `1002bc48` | `89 45 90` | `MOV dword ptr [EBP + -0x70],EAX` |
| `1002bc4b` | `8d 7d e0` | `LEA EDI,[EBP + -0x20]` |
| `1002bc4e` | `89 5d 8c` | `MOV dword ptr [EBP + -0x74],EBX` |
| `1002bc51` | `89 75 98` | `MOV dword ptr [EBP + -0x68],ESI` |
| `1002bc54` | `89 5d b4` | `MOV dword ptr [EBP + -0x4c],EBX` |
| `1002bc57` | `89 5d a8` | `MOV dword ptr [EBP + -0x58],EBX` |
| `1002bc5a` | `89 5d a4` | `MOV dword ptr [EBP + -0x5c],EBX` |
| `1002bc5d` | `89 5d a0` | `MOV dword ptr [EBP + -0x60],EBX` |
| `1002bc60` | `89 5d 9c` | `MOV dword ptr [EBP + -0x64],EBX` |
| `1002bc63` | `89 5d b0` | `MOV dword ptr [EBP + -0x50],EBX` |
| `1002bc66` | `89 5d 94` | `MOV dword ptr [EBP + -0x6c],EBX` |
| `1002bc69` | `39 5d 24` | `CMP dword ptr [EBP + 0x24],EBX` |
| `1002bc6c` | `75 1f` | `JNZ 0x1002bc8d` |
| `1002bc6e` | `e8 96 94 fe ff` | `CALL 0x10015109` |
| `1002bc73` | `53` | `PUSH EBX` |
| `1002bc74` | `53` | `PUSH EBX` |
| `1002bc75` | `53` | `PUSH EBX` |
| `1002bc76` | `53` | `PUSH EBX` |
| `1002bc77` | `53` | `PUSH EBX` |
| `1002bc78` | `c7 00 16 00 00 00` | `MOV dword ptr [EAX],0x16` |
| `1002bc7e` | `e8 2c 5a fe ff` | `CALL 0x100116af` |
| `1002bc83` | `83 c4 14` | `ADD ESP,0x14` |
| `1002bc86` | `33 c0` | `XOR EAX,EAX` |
| `1002bc88` | `e9 4e 06 00 00` | `JMP 0x1002c2db` |
| `1002bc8d` | `8b 55 10` | `MOV EDX,dword ptr [EBP + 0x10]` |
| `1002bc90` | `89 55 ac` | `MOV dword ptr [EBP + -0x54],EDX` |
| `1002bc93` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bc95` | `3c 20` | `CMP AL,0x20` |
| `1002bc97` | `74 0c` | `JZ 0x1002bca5` |
| `1002bc99` | `3c 09` | `CMP AL,0x9` |
| `1002bc9b` | `74 08` | `JZ 0x1002bca5` |
| `1002bc9d` | `3c 0a` | `CMP AL,0xa` |
| `1002bc9f` | `74 04` | `JZ 0x1002bca5` |
| `1002bca1` | `3c 0d` | `CMP AL,0xd` |
| `1002bca3` | `75 03` | `JNZ 0x1002bca8` |
| `1002bca5` | `42` | `INC EDX` |
| `1002bca6` | `eb eb` | `JMP 0x1002bc93` |
| `1002bca8` | `b3 30` | `MOV BL,0x30` |
| `1002bcaa` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bcac` | `42` | `INC EDX` |
| `1002bcad` | `83 f9 0b` | `CMP ECX,0xb` |
| `1002bcb0` | `0f 87 2f 02 00 00` | `JA 0x1002bee5` |
| `1002bcb6` | `ff 24 8d eb c2 02 10` | `JMP dword ptr [ECX*0x4 + 0x1002c2eb]` |
| `1002bcbd` | `8a c8` | `MOV CL,AL` |
| `1002bcbf` | `80 e9 31` | `SUB CL,0x31` |
| `1002bcc2` | `80 f9 08` | `CMP CL,0x8` |
| `1002bcc5` | `77 06` | `JA 0x1002bccd` |
| `1002bcc7` | `6a 03` | `PUSH 0x3` |
| `1002bcc9` | `59` | `POP ECX` |
| `1002bcca` | `4a` | `DEC EDX` |
| `1002bccb` | `eb dd` | `JMP 0x1002bcaa` |
| `1002bccd` | `8b 4d 24` | `MOV ECX,dword ptr [EBP + 0x24]` |
| `1002bcd0` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bcd2` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002bcd8` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bcda` | `3a 01` | `CMP AL,byte ptr [ECX]` |
| `1002bcdc` | `75 05` | `JNZ 0x1002bce3` |
| `1002bcde` | `6a 05` | `PUSH 0x5` |
| `1002bce0` | `59` | `POP ECX` |
| `1002bce1` | `eb c7` | `JMP 0x1002bcaa` |
| `1002bce3` | `0f be c0` | `MOVSX EAX,AL` |
| `1002bce6` | `83 e8 2b` | `SUB EAX,0x2b` |
| `1002bce9` | `74 1d` | `JZ 0x1002bd08` |
| `1002bceb` | `48` | `DEC EAX` |
| `1002bcec` | `48` | `DEC EAX` |
| `1002bced` | `74 0d` | `JZ 0x1002bcfc` |
| `1002bcef` | `83 e8 03` | `SUB EAX,0x3` |
| `1002bcf2` | `0f 85 8b 01 00 00` | `JNZ 0x1002be83` |
| `1002bcf8` | `8b ce` | `MOV ECX,ESI` |
| `1002bcfa` | `eb ae` | `JMP 0x1002bcaa` |
| `1002bcfc` | `6a 02` | `PUSH 0x2` |
| `1002bcfe` | `59` | `POP ECX` |
| `1002bcff` | `c7 45 8c 00 80 00 00` | `MOV dword ptr [EBP + -0x74],0x8000` |
| `1002bd06` | `eb a2` | `JMP 0x1002bcaa` |
| `1002bd08` | `83 65 8c 00` | `AND dword ptr [EBP + -0x74],0x0` |
| `1002bd0c` | `6a 02` | `PUSH 0x2` |
| `1002bd0e` | `59` | `POP ECX` |
| `1002bd0f` | `eb 99` | `JMP 0x1002bcaa` |
| `1002bd11` | `8a c8` | `MOV CL,AL` |
| `1002bd13` | `80 e9 31` | `SUB CL,0x31` |
| `1002bd16` | `89 75 a8` | `MOV dword ptr [EBP + -0x58],ESI` |
| `1002bd19` | `80 f9 08` | `CMP CL,0x8` |
| `1002bd1c` | `76 a9` | `JBE 0x1002bcc7` |
| `1002bd1e` | `8b 4d 24` | `MOV ECX,dword ptr [EBP + 0x24]` |
| `1002bd21` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bd23` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002bd29` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bd2b` | `3a 01` | `CMP AL,byte ptr [ECX]` |
| `1002bd2d` | `75 04` | `JNZ 0x1002bd33` |
| `1002bd2f` | `6a 04` | `PUSH 0x4` |
| `1002bd31` | `eb ad` | `JMP 0x1002bce0` |
| `1002bd33` | `3c 2b` | `CMP AL,0x2b` |
| `1002bd35` | `74 28` | `JZ 0x1002bd5f` |
| `1002bd37` | `3c 2d` | `CMP AL,0x2d` |
| `1002bd39` | `74 24` | `JZ 0x1002bd5f` |
| `1002bd3b` | `3a c3` | `CMP AL,BL` |
| `1002bd3d` | `74 b9` | `JZ 0x1002bcf8` |
| `1002bd3f` | `3c 43` | `CMP AL,0x43` |
| `1002bd41` | `0f 8e 3c 01 00 00` | `JLE 0x1002be83` |
| `1002bd47` | `3c 45` | `CMP AL,0x45` |
| `1002bd49` | `7e 10` | `JLE 0x1002bd5b` |
| `1002bd4b` | `3c 63` | `CMP AL,0x63` |
| `1002bd4d` | `0f 8e 30 01 00 00` | `JLE 0x1002be83` |
| `1002bd53` | `3c 65` | `CMP AL,0x65` |
| `1002bd55` | `0f 8f 28 01 00 00` | `JG 0x1002be83` |
| `1002bd5b` | `6a 06` | `PUSH 0x6` |
| `1002bd5d` | `eb 81` | `JMP 0x1002bce0` |
| `1002bd5f` | `4a` | `DEC EDX` |
| `1002bd60` | `6a 0b` | `PUSH 0xb` |
| `1002bd62` | `e9 79 ff ff ff` | `JMP 0x1002bce0` |
| `1002bd67` | `8a c8` | `MOV CL,AL` |
| `1002bd69` | `80 e9 31` | `SUB CL,0x31` |
| `1002bd6c` | `80 f9 08` | `CMP CL,0x8` |
| `1002bd6f` | `0f 86 52 ff ff ff` | `JBE 0x1002bcc7` |
| `1002bd75` | `8b 4d 24` | `MOV ECX,dword ptr [EBP + 0x24]` |
| `1002bd78` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bd7a` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002bd80` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bd82` | `3a 01` | `CMP AL,byte ptr [ECX]` |
| `1002bd84` | `0f 84 54 ff ff ff` | `JZ 0x1002bcde` |
| `1002bd8a` | `3a c3` | `CMP AL,BL` |
| `1002bd8c` | `0f 84 66 ff ff ff` | `JZ 0x1002bcf8` |
| `1002bd92` | `8b 55 ac` | `MOV EDX,dword ptr [EBP + -0x54]` |
| `1002bd95` | `e9 14 01 00 00` | `JMP 0x1002beae` |
| `1002bd9a` | `89 75 a8` | `MOV dword ptr [EBP + -0x58],ESI` |
| `1002bd9d` | `eb 1a` | `JMP 0x1002bdb9` |
| `1002bd9f` | `3c 39` | `CMP AL,0x39` |
| `1002bda1` | `7f 1a` | `JG 0x1002bdbd` |
| `1002bda3` | `83 7d b4 19` | `CMP dword ptr [EBP + -0x4c],0x19` |
| `1002bda7` | `73 0a` | `JNC 0x1002bdb3` |
| `1002bda9` | `ff 45 b4` | `INC dword ptr [EBP + -0x4c]` |
| `1002bdac` | `2a c3` | `SUB AL,BL` |
| `1002bdae` | `88 07` | `MOV byte ptr [EDI],AL` |
| `1002bdb0` | `47` | `INC EDI` |
| `1002bdb1` | `eb 03` | `JMP 0x1002bdb6` |
| `1002bdb3` | `ff 45 b0` | `INC dword ptr [EBP + -0x50]` |
| `1002bdb6` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bdb8` | `42` | `INC EDX` |
| `1002bdb9` | `3a c3` | `CMP AL,BL` |
| `1002bdbb` | `7d e2` | `JGE 0x1002bd9f` |
| `1002bdbd` | `8b 4d 24` | `MOV ECX,dword ptr [EBP + 0x24]` |
| `1002bdc0` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bdc2` | `8b 89 bc 00 00 00` | `MOV ECX,dword ptr [ECX + 0xbc]` |
| `1002bdc8` | `8b 09` | `MOV ECX,dword ptr [ECX]` |
| `1002bdca` | `3a 01` | `CMP AL,byte ptr [ECX]` |
| `1002bdcc` | `0f 84 5d ff ff ff` | `JZ 0x1002bd2f` |
| `1002bdd2` | `3c 2b` | `CMP AL,0x2b` |
| `1002bdd4` | `74 89` | `JZ 0x1002bd5f` |
| `1002bdd6` | `3c 2d` | `CMP AL,0x2d` |
| `1002bdd8` | `74 85` | `JZ 0x1002bd5f` |
| `1002bdda` | `e9 60 ff ff ff` | `JMP 0x1002bd3f` |
| `1002bddf` | `83 7d b4 00` | `CMP dword ptr [EBP + -0x4c],0x0` |
| `1002bde3` | `89 75 a8` | `MOV dword ptr [EBP + -0x58],ESI` |
| `1002bde6` | `89 75 a4` | `MOV dword ptr [EBP + -0x5c],ESI` |
| `1002bde9` | `75 26` | `JNZ 0x1002be11` |
| `1002bdeb` | `eb 06` | `JMP 0x1002bdf3` |
| `1002bded` | `ff 4d b0` | `DEC dword ptr [EBP + -0x50]` |
| `1002bdf0` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bdf2` | `42` | `INC EDX` |
| `1002bdf3` | `3a c3` | `CMP AL,BL` |
| `1002bdf5` | `74 f6` | `JZ 0x1002bded` |
| `1002bdf7` | `eb 18` | `JMP 0x1002be11` |
| `1002bdf9` | `3c 39` | `CMP AL,0x39` |
| `1002bdfb` | `7f d5` | `JG 0x1002bdd2` |
| `1002bdfd` | `83 7d b4 19` | `CMP dword ptr [EBP + -0x4c],0x19` |
| `1002be01` | `73 0b` | `JNC 0x1002be0e` |
| `1002be03` | `ff 45 b4` | `INC dword ptr [EBP + -0x4c]` |
| `1002be06` | `2a c3` | `SUB AL,BL` |
| `1002be08` | `88 07` | `MOV byte ptr [EDI],AL` |
| `1002be0a` | `47` | `INC EDI` |
| `1002be0b` | `ff 4d b0` | `DEC dword ptr [EBP + -0x50]` |
| `1002be0e` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002be10` | `42` | `INC EDX` |
| `1002be11` | `3a c3` | `CMP AL,BL` |
| `1002be13` | `7d e4` | `JGE 0x1002bdf9` |
| `1002be15` | `eb bb` | `JMP 0x1002bdd2` |
| `1002be17` | `2a c3` | `SUB AL,BL` |
| `1002be19` | `89 75 a4` | `MOV dword ptr [EBP + -0x5c],ESI` |
| `1002be1c` | `3c 09` | `CMP AL,0x9` |
| `1002be1e` | `0f 87 6e ff ff ff` | `JA 0x1002bd92` |
| `1002be24` | `6a 04` | `PUSH 0x4` |
| `1002be26` | `e9 9e fe ff ff` | `JMP 0x1002bcc9` |
| `1002be2b` | `8d 4a fe` | `LEA ECX,[EDX + -0x2]` |
| `1002be2e` | `89 4d ac` | `MOV dword ptr [EBP + -0x54],ECX` |
| `1002be31` | `8a c8` | `MOV CL,AL` |
| `1002be33` | `80 e9 31` | `SUB CL,0x31` |
| `1002be36` | `80 f9 08` | `CMP CL,0x8` |
| `1002be39` | `77 07` | `JA 0x1002be42` |
| `1002be3b` | `6a 09` | `PUSH 0x9` |
| `1002be3d` | `e9 87 fe ff ff` | `JMP 0x1002bcc9` |
| `1002be42` | `0f be c0` | `MOVSX EAX,AL` |
| `1002be45` | `83 e8 2b` | `SUB EAX,0x2b` |
| `1002be48` | `74 20` | `JZ 0x1002be6a` |
| `1002be4a` | `48` | `DEC EAX` |
| `1002be4b` | `48` | `DEC EAX` |
| `1002be4c` | `74 10` | `JZ 0x1002be5e` |
| `1002be4e` | `83 e8 03` | `SUB EAX,0x3` |
| `1002be51` | `0f 85 3b ff ff ff` | `JNZ 0x1002bd92` |
| `1002be57` | `6a 08` | `PUSH 0x8` |
| `1002be59` | `e9 82 fe ff ff` | `JMP 0x1002bce0` |
| `1002be5e` | `83 4d 98 ff` | `OR dword ptr [EBP + -0x68],0xffffffff` |
| `1002be62` | `6a 07` | `PUSH 0x7` |
| `1002be64` | `59` | `POP ECX` |
| `1002be65` | `e9 40 fe ff ff` | `JMP 0x1002bcaa` |
| `1002be6a` | `6a 07` | `PUSH 0x7` |
| `1002be6c` | `e9 6f fe ff ff` | `JMP 0x1002bce0` |
| `1002be71` | `89 75 a0` | `MOV dword ptr [EBP + -0x60],ESI` |
| `1002be74` | `eb 03` | `JMP 0x1002be79` |
| `1002be76` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002be78` | `42` | `INC EDX` |
| `1002be79` | `3a c3` | `CMP AL,BL` |
| `1002be7b` | `74 f9` | `JZ 0x1002be76` |
| `1002be7d` | `2c 31` | `SUB AL,0x31` |
| `1002be7f` | `3c 08` | `CMP AL,0x8` |
| `1002be81` | `76 b8` | `JBE 0x1002be3b` |
| `1002be83` | `4a` | `DEC EDX` |
| `1002be84` | `eb 28` | `JMP 0x1002beae` |
| `1002be86` | `8a c8` | `MOV CL,AL` |
| `1002be88` | `80 e9 31` | `SUB CL,0x31` |
| `1002be8b` | `80 f9 08` | `CMP CL,0x8` |
| `1002be8e` | `76 ab` | `JBE 0x1002be3b` |
| `1002be90` | `3a c3` | `CMP AL,BL` |
| `1002be92` | `eb bd` | `JMP 0x1002be51` |
| `1002be94` | `83 7d 20 00` | `CMP dword ptr [EBP + 0x20],0x0` |
| `1002be98` | `74 47` | `JZ 0x1002bee1` |
| `1002be9a` | `0f be c0` | `MOVSX EAX,AL` |
| `1002be9d` | `83 e8 2b` | `SUB EAX,0x2b` |
| `1002bea0` | `8d 4a ff` | `LEA ECX,[EDX + -0x1]` |
| `1002bea3` | `89 4d ac` | `MOV dword ptr [EBP + -0x54],ECX` |
| `1002bea6` | `74 c2` | `JZ 0x1002be6a` |
| `1002bea8` | `48` | `DEC EAX` |
| `1002bea9` | `48` | `DEC EAX` |
| `1002beaa` | `74 b2` | `JZ 0x1002be5e` |
| `1002beac` | `8b d1` | `MOV EDX,ECX` |
| `1002beae` | `83 7d a8 00` | `CMP dword ptr [EBP + -0x58],0x0` |
| `1002beb2` | `8b 45 90` | `MOV EAX,dword ptr [EBP + -0x70]` |
| `1002beb5` | `89 10` | `MOV dword ptr [EAX],EDX` |
| `1002beb7` | `0f 84 d9 03 00 00` | `JZ 0x1002c296` |
| `1002bebd` | `6a 18` | `PUSH 0x18` |
| `1002bebf` | `58` | `POP EAX` |
| `1002bec0` | `39 45 b4` | `CMP dword ptr [EBP + -0x4c],EAX` |
| `1002bec3` | `76 10` | `JBE 0x1002bed5` |
| `1002bec5` | `80 7d f7 05` | `CMP byte ptr [EBP + -0x9],0x5` |
| `1002bec9` | `7c 03` | `JL 0x1002bece` |
| `1002becb` | `fe 45 f7` | `INC byte ptr [EBP + -0x9]` |
| `1002bece` | `4f` | `DEC EDI` |
| `1002becf` | `ff 45 b0` | `INC dword ptr [EBP + -0x50]` |
| `1002bed2` | `89 45 b4` | `MOV dword ptr [EBP + -0x4c],EAX` |
| `1002bed5` | `83 7d b4 00` | `CMP dword ptr [EBP + -0x4c],0x0` |
| `1002bed9` | `0f 86 de 03 00 00` | `JBE 0x1002c2bd` |
| `1002bedf` | `eb 59` | `JMP 0x1002bf3a` |
| `1002bee1` | `6a 0a` | `PUSH 0xa` |
| `1002bee3` | `59` | `POP ECX` |
| `1002bee4` | `4a` | `DEC EDX` |
| `1002bee5` | `83 f9 0a` | `CMP ECX,0xa` |
| `1002bee8` | `0f 85 bc fd ff ff` | `JNZ 0x1002bcaa` |
| `1002beee` | `eb be` | `JMP 0x1002beae` |
| `1002bef0` | `89 75 a0` | `MOV dword ptr [EBP + -0x60],ESI` |
| `1002bef3` | `33 c9` | `XOR ECX,ECX` |
| `1002bef5` | `eb 19` | `JMP 0x1002bf10` |
| `1002bef7` | `3c 39` | `CMP AL,0x39` |
| `1002bef9` | `7f 20` | `JG 0x1002bf1b` |
| `1002befb` | `6b c9 0a` | `IMUL ECX,ECX,0xa` |
| `1002befe` | `0f be f0` | `MOVSX ESI,AL` |
| `1002bf01` | `8d 4c 31 d0` | `LEA ECX,[ECX + ESI*0x1 + -0x30]` |
| `1002bf05` | `81 f9 50 14 00 00` | `CMP ECX,0x1450` |
| `1002bf0b` | `7f 09` | `JG 0x1002bf16` |
| `1002bf0d` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bf0f` | `42` | `INC EDX` |
| `1002bf10` | `3a c3` | `CMP AL,BL` |
| `1002bf12` | `7d e3` | `JGE 0x1002bef7` |
| `1002bf14` | `eb 05` | `JMP 0x1002bf1b` |
| `1002bf16` | `b9 51 14 00 00` | `MOV ECX,0x1451` |
| `1002bf1b` | `89 4d 9c` | `MOV dword ptr [EBP + -0x64],ECX` |
| `1002bf1e` | `eb 0b` | `JMP 0x1002bf2b` |
| `1002bf20` | `3c 39` | `CMP AL,0x39` |
| `1002bf22` | `0f 8f 5b ff ff ff` | `JG 0x1002be83` |
| `1002bf28` | `8a 02` | `MOV AL,byte ptr [EDX]` |
| `1002bf2a` | `42` | `INC EDX` |
| `1002bf2b` | `3a c3` | `CMP AL,BL` |
| `1002bf2d` | `7d f1` | `JGE 0x1002bf20` |
| `1002bf2f` | `e9 4f ff ff ff` | `JMP 0x1002be83` |
| `1002bf34` | `ff 4d b4` | `DEC dword ptr [EBP + -0x4c]` |
| `1002bf37` | `ff 45 b0` | `INC dword ptr [EBP + -0x50]` |
| `1002bf3a` | `4f` | `DEC EDI` |
| `1002bf3b` | `80 3f 00` | `CMP byte ptr [EDI],0x0` |
| `1002bf3e` | `74 f4` | `JZ 0x1002bf34` |
| `1002bf40` | `8d 45 c4` | `LEA EAX,[EBP + -0x3c]` |
| `1002bf43` | `50` | `PUSH EAX` |
| `1002bf44` | `ff 75 b4` | `PUSH dword ptr [EBP + -0x4c]` |
| `1002bf47` | `8d 45 e0` | `LEA EAX,[EBP + -0x20]` |
| `1002bf4a` | `50` | `PUSH EAX` |
| `1002bf4b` | `e8 2c 11 00 00` | `CALL 0x1002d07c` |
| `1002bf50` | `8b 45 9c` | `MOV EAX,dword ptr [EBP + -0x64]` |
| `1002bf53` | `33 d2` | `XOR EDX,EDX` |
| `1002bf55` | `83 c4 0c` | `ADD ESP,0xc` |
| `1002bf58` | `39 55 98` | `CMP dword ptr [EBP + -0x68],EDX` |
| `1002bf5b` | `7d 02` | `JGE 0x1002bf5f` |
| `1002bf5d` | `f7 d8` | `NEG EAX` |
| `1002bf5f` | `03 45 b0` | `ADD EAX,dword ptr [EBP + -0x50]` |
| `1002bf62` | `39 55 a0` | `CMP dword ptr [EBP + -0x60],EDX` |
| `1002bf65` | `75 03` | `JNZ 0x1002bf6a` |
| `1002bf67` | `03 45 18` | `ADD EAX,dword ptr [EBP + 0x18]` |
| `1002bf6a` | `39 55 a4` | `CMP dword ptr [EBP + -0x5c],EDX` |
| `1002bf6d` | `75 03` | `JNZ 0x1002bf72` |
| `1002bf6f` | `2b 45 1c` | `SUB EAX,dword ptr [EBP + 0x1c]` |
| `1002bf72` | `3d 50 14 00 00` | `CMP EAX,0x1450` |
| `1002bf77` | `0f 8f 22 03 00 00` | `JG 0x1002c29f` |
| `1002bf7d` | `3d b0 eb ff ff` | `CMP EAX,0xffffebb0` |
| `1002bf82` | `0f 8c 2e 03 00 00` | `JL 0x1002c2b6` |
| `1002bf88` | `b9 40 87 03 10` | `MOV ECX,0x10038740` |
| `1002bf8d` | `83 e9 60` | `SUB ECX,0x60` |
| `1002bf90` | `89 45 ac` | `MOV dword ptr [EBP + -0x54],EAX` |
| `1002bf93` | `3b c2` | `CMP EAX,EDX` |
| `1002bf95` | `0f 84 e9 02 00 00` | `JZ 0x1002c284` |
| `1002bf9b` | `7d 0d` | `JGE 0x1002bfaa` |
| `1002bf9d` | `f7 d8` | `NEG EAX` |
| `1002bf9f` | `b9 a0 88 03 10` | `MOV ECX,0x100388a0` |
| `1002bfa4` | `89 45 ac` | `MOV dword ptr [EBP + -0x54],EAX` |
| `1002bfa7` | `83 e9 60` | `SUB ECX,0x60` |
| `1002bfaa` | `39 55 14` | `CMP dword ptr [EBP + 0x14],EDX` |
| `1002bfad` | `75 06` | `JNZ 0x1002bfb5` |
| `1002bfaf` | `33 c0` | `XOR EAX,EAX` |
| `1002bfb1` | `66 89 45 c4` | `MOV word ptr [EBP + -0x3c],AX` |
| `1002bfb5` | `39 55 ac` | `CMP dword ptr [EBP + -0x54],EDX` |
| `1002bfb8` | `0f 84 c6 02 00 00` | `JZ 0x1002c284` |
| `1002bfbe` | `eb 05` | `JMP 0x1002bfc5` |
| `1002bfc0` | `8b 4d 84` | `MOV ECX,dword ptr [EBP + -0x7c]` |
| `1002bfc3` | `33 d2` | `XOR EDX,EDX` |
| `1002bfc5` | `8b 45 ac` | `MOV EAX,dword ptr [EBP + -0x54]` |
| `1002bfc8` | `c1 7d ac 03` | `SAR dword ptr [EBP + -0x54],0x3` |
| `1002bfcc` | `83 c1 54` | `ADD ECX,0x54` |
| `1002bfcf` | `83 e0 07` | `AND EAX,0x7` |
| `1002bfd2` | `89 4d 84` | `MOV dword ptr [EBP + -0x7c],ECX` |
| `1002bfd5` | `3b c2` | `CMP EAX,EDX` |
| `1002bfd7` | `0f 84 9d 02 00 00` | `JZ 0x1002c27a` |
| `1002bfdd` | `6b c0 0c` | `IMUL EAX,EAX,0xc` |
| `1002bfe0` | `03 c1` | `ADD EAX,ECX` |
| `1002bfe2` | `8b d8` | `MOV EBX,EAX` |
| `1002bfe4` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002bfe9` | `66 39 03` | `CMP word ptr [EBX],AX` |
| `1002bfec` | `72 0e` | `JC 0x1002bffc` |
| `1002bfee` | `8b f3` | `MOV ESI,EBX` |
| `1002bff0` | `8d 7d b8` | `LEA EDI,[EBP + -0x48]` |
| `1002bff3` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002bff4` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002bff5` | `a5` | `MOVSD ES:EDI,ESI` |
| `1002bff6` | `ff 4d ba` | `DEC dword ptr [EBP + -0x46]` |
| `1002bff9` | `8d 5d b8` | `LEA EBX,[EBP + -0x48]` |
| `1002bffc` | `0f b7 4b 0a` | `MOVZX ECX,word ptr [EBX + 0xa]` |
| `1002c000` | `33 c0` | `XOR EAX,EAX` |
| `1002c002` | `89 45 b0` | `MOV dword ptr [EBP + -0x50],EAX` |
| `1002c005` | `89 45 d4` | `MOV dword ptr [EBP + -0x2c],EAX` |
| `1002c008` | `89 45 d8` | `MOV dword ptr [EBP + -0x28],EAX` |
| `1002c00b` | `89 45 dc` | `MOV dword ptr [EBP + -0x24],EAX` |
| `1002c00e` | `8b 45 ce` | `MOV EAX,dword ptr [EBP + -0x32]` |
| `1002c011` | `8b f1` | `MOV ESI,ECX` |
| `1002c013` | `ba ff 7f 00 00` | `MOV EDX,0x7fff` |
| `1002c018` | `33 f0` | `XOR ESI,EAX` |
| `1002c01a` | `23 c2` | `AND EAX,EDX` |
| `1002c01c` | `23 ca` | `AND ECX,EDX` |
| `1002c01e` | `81 e6 00 80 00 00` | `AND ESI,0x8000` |
| `1002c024` | `bf ff 7f 00 00` | `MOV EDI,0x7fff` |
| `1002c029` | `8d 14 01` | `LEA EDX,[ECX + EAX*0x1]` |
| `1002c02c` | `89 75 90` | `MOV dword ptr [EBP + -0x70],ESI` |
| `1002c02f` | `0f b7 d2` | `MOVZX EDX,DX` |
| `1002c032` | `66 3b c7` | `CMP AX,DI` |
| `1002c035` | `0f 83 21 02 00 00` | `JNC 0x1002c25c` |
| `1002c03b` | `66 3b cf` | `CMP CX,DI` |
| `1002c03e` | `0f 83 18 02 00 00` | `JNC 0x1002c25c` |
| `1002c044` | `bf fd bf 00 00` | `MOV EDI,0xbffd` |
| `1002c049` | `66 3b d7` | `CMP DX,DI` |
| `1002c04c` | `0f 87 0a 02 00 00` | `JA 0x1002c25c` |
| `1002c052` | `be bf 3f 00 00` | `MOV ESI,0x3fbf` |
| `1002c057` | `66 3b d6` | `CMP DX,SI` |
| `1002c05a` | `77 0d` | `JA 0x1002c069` |
| `1002c05c` | `33 c0` | `XOR EAX,EAX` |
| `1002c05e` | `89 45 c8` | `MOV dword ptr [EBP + -0x38],EAX` |
| `1002c061` | `89 45 c4` | `MOV dword ptr [EBP + -0x3c],EAX` |
| `1002c064` | `e9 0e 02 00 00` | `JMP 0x1002c277` |
| `1002c069` | `33 f6` | `XOR ESI,ESI` |
| `1002c06b` | `66 3b c6` | `CMP AX,SI` |
| `1002c06e` | `75 1f` | `JNZ 0x1002c08f` |
| `1002c070` | `42` | `INC EDX` |
| `1002c071` | `f7 45 cc ff ff ff 7f` | `TEST dword ptr [EBP + -0x34],0x7fffffff` |
| `1002c078` | `75 15` | `JNZ 0x1002c08f` |
| `1002c07a` | `39 75 c8` | `CMP dword ptr [EBP + -0x38],ESI` |
| `1002c07d` | `75 10` | `JNZ 0x1002c08f` |
| `1002c07f` | `39 75 c4` | `CMP dword ptr [EBP + -0x3c],ESI` |
| `1002c082` | `75 0b` | `JNZ 0x1002c08f` |
| `1002c084` | `33 c0` | `XOR EAX,EAX` |
| `1002c086` | `66 89 45 ce` | `MOV word ptr [EBP + -0x32],AX` |
| `1002c08a` | `e9 eb 01 00 00` | `JMP 0x1002c27a` |
| `1002c08f` | `66 3b ce` | `CMP CX,SI` |
| `1002c092` | `75 21` | `JNZ 0x1002c0b5` |
| `1002c094` | `42` | `INC EDX` |
| `1002c095` | `f7 43 08 ff ff ff 7f` | `TEST dword ptr [EBX + 0x8],0x7fffffff` |
| `1002c09c` | `75 17` | `JNZ 0x1002c0b5` |
| `1002c09e` | `39 73 04` | `CMP dword ptr [EBX + 0x4],ESI` |
| `1002c0a1` | `75 12` | `JNZ 0x1002c0b5` |
| `1002c0a3` | `39 33` | `CMP dword ptr [EBX],ESI` |
| `1002c0a5` | `75 0e` | `JNZ 0x1002c0b5` |
| `1002c0a7` | `89 75 cc` | `MOV dword ptr [EBP + -0x34],ESI` |
| `1002c0aa` | `89 75 c8` | `MOV dword ptr [EBP + -0x38],ESI` |
| `1002c0ad` | `89 75 c4` | `MOV dword ptr [EBP + -0x3c],ESI` |
| `1002c0b0` | `e9 c5 01 00 00` | `JMP 0x1002c27a` |
| `1002c0b5` | `89 75 98` | `MOV dword ptr [EBP + -0x68],ESI` |
| `1002c0b8` | `8d 7d d8` | `LEA EDI,[EBP + -0x28]` |
| `1002c0bb` | `c7 45 a8 05 00 00 00` | `MOV dword ptr [EBP + -0x58],0x5` |
| `1002c0c2` | `8b 45 98` | `MOV EAX,dword ptr [EBP + -0x68]` |
| `1002c0c5` | `8b 4d a8` | `MOV ECX,dword ptr [EBP + -0x58]` |
| `1002c0c8` | `03 c0` | `ADD EAX,EAX` |
| `1002c0ca` | `89 4d 9c` | `MOV dword ptr [EBP + -0x64],ECX` |
| `1002c0cd` | `85 c9` | `TEST ECX,ECX` |
| `1002c0cf` | `7e 52` | `JLE 0x1002c123` |
| `1002c0d1` | `8d 44 05 c4` | `LEA EAX,[EBP + EAX*0x1 + -0x3c]` |
| `1002c0d5` | `89 45 a4` | `MOV dword ptr [EBP + -0x5c],EAX` |
| `1002c0d8` | `8d 43 08` | `LEA EAX,[EBX + 0x8]` |
| `1002c0db` | `89 45 a0` | `MOV dword ptr [EBP + -0x60],EAX` |
| `1002c0de` | `8b 45 a0` | `MOV EAX,dword ptr [EBP + -0x60]` |
| `1002c0e1` | `8b 4d a4` | `MOV ECX,dword ptr [EBP + -0x5c]` |
| `1002c0e4` | `0f b7 09` | `MOVZX ECX,word ptr [ECX]` |
| `1002c0e7` | `0f b7 00` | `MOVZX EAX,word ptr [EAX]` |
| `1002c0ea` | `83 65 b4 00` | `AND dword ptr [EBP + -0x4c],0x0` |
| `1002c0ee` | `0f af c1` | `IMUL EAX,ECX` |
| `1002c0f1` | `8b 4f fc` | `MOV ECX,dword ptr [EDI + -0x4]` |
| `1002c0f4` | `8d 34 01` | `LEA ESI,[ECX + EAX*0x1]` |
| `1002c0f7` | `3b f1` | `CMP ESI,ECX` |
| `1002c0f9` | `72 04` | `JC 0x1002c0ff` |
| `1002c0fb` | `3b f0` | `CMP ESI,EAX` |
| `1002c0fd` | `73 07` | `JNC 0x1002c106` |
| `1002c0ff` | `c7 45 b4 01 00 00 00` | `MOV dword ptr [EBP + -0x4c],0x1` |
| `1002c106` | `83 7d b4 00` | `CMP dword ptr [EBP + -0x4c],0x0` |
| `1002c10a` | `89 77 fc` | `MOV dword ptr [EDI + -0x4],ESI` |
| `1002c10d` | `74 03` | `JZ 0x1002c112` |
| `1002c10f` | `66 ff 07` | `INC word ptr [EDI]` |
| `1002c112` | `83 45 a4 02` | `ADD dword ptr [EBP + -0x5c],0x2` |
| `1002c116` | `83 6d a0 02` | `SUB dword ptr [EBP + -0x60],0x2` |
| `1002c11a` | `ff 4d 9c` | `DEC dword ptr [EBP + -0x64]` |
| `1002c11d` | `83 7d 9c 00` | `CMP dword ptr [EBP + -0x64],0x0` |
| `1002c121` | `7f bb` | `JG 0x1002c0de` |
| `1002c123` | `47` | `INC EDI` |
| `1002c124` | `47` | `INC EDI` |
| `1002c125` | `ff 45 98` | `INC dword ptr [EBP + -0x68]` |
| `1002c128` | `ff 4d a8` | `DEC dword ptr [EBP + -0x58]` |
| `1002c12b` | `83 7d a8 00` | `CMP dword ptr [EBP + -0x58],0x0` |
| `1002c12f` | `7f 91` | `JG 0x1002c0c2` |
| `1002c131` | `81 c2 02 c0 00 00` | `ADD EDX,0xc002` |
| `1002c137` | `66 85 d2` | `TEST DX,DX` |
| `1002c13a` | `7e 37` | `JLE 0x1002c173` |
| `1002c13c` | `8b 7d dc` | `MOV EDI,dword ptr [EBP + -0x24]` |
| `1002c13f` | `85 ff` | `TEST EDI,EDI` |
| `1002c141` | `78 2b` | `JS 0x1002c16e` |
| `1002c143` | `8b 75 d8` | `MOV ESI,dword ptr [EBP + -0x28]` |
| `1002c146` | `8b 45 d4` | `MOV EAX,dword ptr [EBP + -0x2c]` |
| `1002c149` | `d1 65 d4` | `SHL dword ptr [EBP + -0x2c],0x1` |
| `1002c14c` | `c1 e8 1f` | `SHR EAX,0x1f` |
| `1002c14f` | `8b ce` | `MOV ECX,ESI` |
| `1002c151` | `03 f6` | `ADD ESI,ESI` |
| `1002c153` | `0b f0` | `OR ESI,EAX` |
| `1002c155` | `c1 e9 1f` | `SHR ECX,0x1f` |
| `1002c158` | `8d 04 3f` | `LEA EAX,[EDI + EDI*0x1]` |
| `1002c15b` | `0b c1` | `OR EAX,ECX` |
| `1002c15d` | `81 c2 ff ff 00 00` | `ADD EDX,0xffff` |
| `1002c163` | `89 75 d8` | `MOV dword ptr [EBP + -0x28],ESI` |
| `1002c166` | `89 45 dc` | `MOV dword ptr [EBP + -0x24],EAX` |
| `1002c169` | `66 85 d2` | `TEST DX,DX` |
| `1002c16c` | `7f ce` | `JG 0x1002c13c` |
| `1002c16e` | `66 85 d2` | `TEST DX,DX` |
| `1002c171` | `7f 4d` | `JG 0x1002c1c0` |
| `1002c173` | `81 c2 ff ff 00 00` | `ADD EDX,0xffff` |
| `1002c179` | `66 85 d2` | `TEST DX,DX` |
| `1002c17c` | `7d 42` | `JGE 0x1002c1c0` |
| `1002c17e` | `8b c2` | `MOV EAX,EDX` |
| `1002c180` | `f7 d8` | `NEG EAX` |
| `1002c182` | `0f b7 f0` | `MOVZX ESI,AX` |
| `1002c185` | `03 d6` | `ADD EDX,ESI` |
| `1002c187` | `f6 45 d4 01` | `TEST byte ptr [EBP + -0x2c],0x1` |
| `1002c18b` | `74 03` | `JZ 0x1002c190` |
| `1002c18d` | `ff 45 b0` | `INC dword ptr [EBP + -0x50]` |
| `1002c190` | `8b 45 dc` | `MOV EAX,dword ptr [EBP + -0x24]` |
| `1002c193` | `8b 7d d8` | `MOV EDI,dword ptr [EBP + -0x28]` |
| `1002c196` | `8b 4d d8` | `MOV ECX,dword ptr [EBP + -0x28]` |
| `1002c199` | `d1 6d dc` | `SHR dword ptr [EBP + -0x24],0x1` |
| `1002c19c` | `c1 e0 1f` | `SHL EAX,0x1f` |
| `1002c19f` | `d1 ef` | `SHR EDI,0x1` |
| `1002c1a1` | `0b f8` | `OR EDI,EAX` |
| `1002c1a3` | `8b 45 d4` | `MOV EAX,dword ptr [EBP + -0x2c]` |
| `1002c1a6` | `c1 e1 1f` | `SHL ECX,0x1f` |
| `1002c1a9` | `d1 e8` | `SHR EAX,0x1` |
| `1002c1ab` | `0b c1` | `OR EAX,ECX` |
| `1002c1ad` | `4e` | `DEC ESI` |
| `1002c1ae` | `89 7d d8` | `MOV dword ptr [EBP + -0x28],EDI` |
| `1002c1b1` | `89 45 d4` | `MOV dword ptr [EBP + -0x2c],EAX` |
| `1002c1b4` | `75 d1` | `JNZ 0x1002c187` |
| `1002c1b6` | `39 75 b0` | `CMP dword ptr [EBP + -0x50],ESI` |
| `1002c1b9` | `74 05` | `JZ 0x1002c1c0` |
| `1002c1bb` | `66 83 4d d4 01` | `OR word ptr [EBP + -0x2c],0x1` |
| `1002c1c0` | `b8 00 80 00 00` | `MOV EAX,0x8000` |
| `1002c1c5` | `8b c8` | `MOV ECX,EAX` |
| `1002c1c7` | `66 39 4d d4` | `CMP word ptr [EBP + -0x2c],CX` |
| `1002c1cb` | `77 11` | `JA 0x1002c1de` |
| `1002c1cd` | `8b 4d d4` | `MOV ECX,dword ptr [EBP + -0x2c]` |
| `1002c1d0` | `81 e1 ff ff 01 00` | `AND ECX,0x1ffff` |
| `1002c1d6` | `81 f9 00 80 01 00` | `CMP ECX,0x18000` |
| `1002c1dc` | `75 34` | `JNZ 0x1002c212` |
| `1002c1de` | `83 7d d6 ff` | `CMP dword ptr [EBP + -0x2a],-0x1` |
| `1002c1e2` | `75 2b` | `JNZ 0x1002c20f` |
| `1002c1e4` | `83 65 d6 00` | `AND dword ptr [EBP + -0x2a],0x0` |
| `1002c1e8` | `83 7d da ff` | `CMP dword ptr [EBP + -0x26],-0x1` |
| `1002c1ec` | `75 1c` | `JNZ 0x1002c20a` |
| `1002c1ee` | `83 65 da 00` | `AND dword ptr [EBP + -0x26],0x0` |
| `1002c1f2` | `b9 ff ff 00 00` | `MOV ECX,0xffff` |
| `1002c1f7` | `66 39 4d de` | `CMP word ptr [EBP + -0x22],CX` |
| `1002c1fb` | `75 07` | `JNZ 0x1002c204` |
| `1002c1fd` | `66 89 45 de` | `MOV word ptr [EBP + -0x22],AX` |
| `1002c201` | `42` | `INC EDX` |
| `1002c202` | `eb 0e` | `JMP 0x1002c212` |
| `1002c204` | `66 ff 45 de` | `INC word ptr [EBP + -0x22]` |
| `1002c208` | `eb 08` | `JMP 0x1002c212` |
| `1002c20a` | `ff 45 da` | `INC dword ptr [EBP + -0x26]` |
| `1002c20d` | `eb 03` | `JMP 0x1002c212` |
| `1002c20f` | `ff 45 d6` | `INC dword ptr [EBP + -0x2a]` |
| `1002c212` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c217` | `66 3b d0` | `CMP DX,AX` |
| `1002c21a` | `72 23` | `JC 0x1002c23f` |
| `1002c21c` | `33 c0` | `XOR EAX,EAX` |
| `1002c21e` | `33 c9` | `XOR ECX,ECX` |
| `1002c220` | `66 39 45 90` | `CMP word ptr [EBP + -0x70],AX` |
| `1002c224` | `89 45 c8` | `MOV dword ptr [EBP + -0x38],EAX` |
| `1002c227` | `0f 94 c1` | `SETZ CL` |
| `1002c22a` | `89 45 c4` | `MOV dword ptr [EBP + -0x3c],EAX` |
| `1002c22d` | `49` | `DEC ECX` |
| `1002c22e` | `81 e1 00 00 00 80` | `AND ECX,0x80000000` |
| `1002c234` | `81 c1 00 80 ff 7f` | `ADD ECX,0x7fff8000` |
| `1002c23a` | `89 4d cc` | `MOV dword ptr [EBP + -0x34],ECX` |
| `1002c23d` | `eb 3b` | `JMP 0x1002c27a` |
| `1002c23f` | `66 8b 45 d6` | `MOV AX,word ptr [EBP + -0x2a]` |
| `1002c243` | `0b 55 90` | `OR EDX,dword ptr [EBP + -0x70]` |
| `1002c246` | `66 89 45 c4` | `MOV word ptr [EBP + -0x3c],AX` |
| `1002c24a` | `8b 45 d8` | `MOV EAX,dword ptr [EBP + -0x28]` |
| `1002c24d` | `89 45 c6` | `MOV dword ptr [EBP + -0x3a],EAX` |
| `1002c250` | `8b 45 dc` | `MOV EAX,dword ptr [EBP + -0x24]` |
| `1002c253` | `89 45 ca` | `MOV dword ptr [EBP + -0x36],EAX` |
| `1002c256` | `66 89 55 ce` | `MOV word ptr [EBP + -0x32],DX` |
| `1002c25a` | `eb 1e` | `JMP 0x1002c27a` |
| `1002c25c` | `33 c0` | `XOR EAX,EAX` |
| `1002c25e` | `66 85 f6` | `TEST SI,SI` |
| `1002c261` | `0f 94 c0` | `SETZ AL` |
| `1002c264` | `83 65 c8 00` | `AND dword ptr [EBP + -0x38],0x0` |
| `1002c268` | `48` | `DEC EAX` |
| `1002c269` | `25 00 00 00 80` | `AND EAX,0x80000000` |
| `1002c26e` | `05 00 80 ff 7f` | `ADD EAX,0x7fff8000` |
| `1002c273` | `83 65 c4 00` | `AND dword ptr [EBP + -0x3c],0x0` |
| `1002c277` | `89 45 cc` | `MOV dword ptr [EBP + -0x34],EAX` |
| `1002c27a` | `83 7d ac 00` | `CMP dword ptr [EBP + -0x54],0x0` |
| `1002c27e` | `0f 85 3c fd ff ff` | `JNZ 0x1002bfc0` |
| `1002c284` | `8b 45 cc` | `MOV EAX,dword ptr [EBP + -0x34]` |
| `1002c287` | `0f b7 4d c4` | `MOVZX ECX,word ptr [EBP + -0x3c]` |
| `1002c28b` | `8b 75 c6` | `MOV ESI,dword ptr [EBP + -0x3a]` |
| `1002c28e` | `8b 55 ca` | `MOV EDX,dword ptr [EBP + -0x36]` |
| `1002c291` | `c1 e8 10` | `SHR EAX,0x10` |
| `1002c294` | `eb 2f` | `JMP 0x1002c2c5` |
| `1002c296` | `c7 45 94 04 00 00 00` | `MOV dword ptr [EBP + -0x6c],0x4` |
| `1002c29d` | `eb 1e` | `JMP 0x1002c2bd` |
| `1002c29f` | `33 f6` | `XOR ESI,ESI` |
| `1002c2a1` | `b8 ff 7f 00 00` | `MOV EAX,0x7fff` |
| `1002c2a6` | `ba 00 00 00 80` | `MOV EDX,0x80000000` |
| `1002c2ab` | `33 c9` | `XOR ECX,ECX` |
| `1002c2ad` | `c7 45 94 02 00 00 00` | `MOV dword ptr [EBP + -0x6c],0x2` |
| `1002c2b4` | `eb 0f` | `JMP 0x1002c2c5` |
| `1002c2b6` | `c7 45 94 01 00 00 00` | `MOV dword ptr [EBP + -0x6c],0x1` |
| `1002c2bd` | `33 c9` | `XOR ECX,ECX` |
| `1002c2bf` | `33 c0` | `XOR EAX,EAX` |
| `1002c2c1` | `33 d2` | `XOR EDX,EDX` |
| `1002c2c3` | `33 f6` | `XOR ESI,ESI` |
| `1002c2c5` | `8b 7d 88` | `MOV EDI,dword ptr [EBP + -0x78]` |
| `1002c2c8` | `0b 45 8c` | `OR EAX,dword ptr [EBP + -0x74]` |
| `1002c2cb` | `66 89 0f` | `MOV word ptr [EDI],CX` |
| `1002c2ce` | `66 89 47 0a` | `MOV word ptr [EDI + 0xa],AX` |
| `1002c2d2` | `8b 45 94` | `MOV EAX,dword ptr [EBP + -0x6c]` |
| `1002c2d5` | `89 77 02` | `MOV dword ptr [EDI + 0x2],ESI` |
| `1002c2d8` | `89 57 06` | `MOV dword ptr [EDI + 0x6],EDX` |
| `1002c2db` | `8b 4d fc` | `MOV ECX,dword ptr [EBP + -0x4]` |
| `1002c2de` | `5f` | `POP EDI` |
| `1002c2df` | `5e` | `POP ESI` |
| `1002c2e0` | `33 cd` | `XOR ECX,EBP` |
| `1002c2e2` | `5b` | `POP EBX` |
| `1002c2e3` | `e8 e3 49 fe ff` | `CALL 0x10010ccb` |
| `1002c2e8` | `c9` | `LEAVE` |
| `1002c2e9` | `c3` | `RET` |
