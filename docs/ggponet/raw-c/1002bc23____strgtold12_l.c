
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
