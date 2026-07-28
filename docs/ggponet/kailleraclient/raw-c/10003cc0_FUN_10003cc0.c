
undefined4 __cdecl FUN_10003cc0(char param_1)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 *puVar8;
  void *this;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  char *pcVar14;
  undefined4 *puVar15;
  char in_stack_00001004;
  char in_stack_0000100d;
  
  FUN_1000c760();
  uVar4 = 0xffffffff;
  if ((*(int *)((int)this + 0xc) != -1) && (*(void **)((int)this + 4) != (void *)0x0)) {
    FUN_10002c80(*(void **)((int)this + 4),-1,-1,(int *)0x0,(int *)0x0);
    pvVar2 = *(void **)((int)this + 4);
    iVar5 = *(int *)((int)pvVar2 + 0x140);
    iVar3 = 0;
joined_r0x10003cff:
    if (iVar5 == 0) goto LAB_10003ea8;
    if (iVar5 == 6) {
      return 1;
    }
    iVar12 = iVar3;
    if (*(int *)((int)this + 0xc) == 0) {
      iVar5 = FUN_100032f0(pvVar2);
      if (iVar5 < 1) {
        iVar12 = iVar3 + 1;
        if (iVar3 != 0) goto LAB_10003dde;
LAB_10003e87:
        FUN_10002c80(*(void **)((int)this + 4),-1,-1,(int *)0x0,(int *)0x0);
        pvVar2 = *(void **)((int)this + 4);
        iVar5 = *(int *)((int)pvVar2 + 0x140);
        iVar3 = iVar12;
        goto joined_r0x10003cff;
      }
      FUN_10003350(*(void **)((int)this + 4),&param_1,0xfff);
      uVar9 = 0xffffffff;
      pcVar6 = &param_1;
      do {
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      pcVar6 = malloc(~uVar9);
      uVar9 = 0xffffffff;
      pcVar7 = &param_1;
      do {
        pcVar14 = pcVar7;
        if (uVar9 == 0) break;
        uVar9 = uVar9 - 1;
        pcVar14 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar14;
      } while (cVar1 != '\0');
      uVar9 = ~uVar9;
      *(char **)((int)this + 0x3c) = pcVar6;
      pcVar7 = pcVar14 + -uVar9;
      for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *pcVar6 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar6 = pcVar6 + 1;
      }
      pcVar6 = strstr(&param_1,&DAT_1000e210);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = strstr(&param_1,&DAT_1000e20c);
        if ((pcVar6 != (char *)0x0) ||
           (pcVar6 = strstr(&param_1,&DAT_1000e208), pcVar6 != (char *)0x0)) {
          *(undefined4 *)((int)this + 0xc) = 1;
          iVar12 = 0;
          goto LAB_10003dde;
        }
        if (*(void **)((int)this + 0x40) != (void *)0x0) {
          free(*(void **)((int)this + 0x40));
        }
        uVar9 = 0xffffffff;
        pcVar6 = &param_1;
        goto code_r0x10003f33;
      }
      *(undefined4 *)((int)this + 0xc) = 2;
      iVar12 = 0;
    }
LAB_10003dde:
    if (*(int *)((int)this + 0xc) == 1) {
      iVar5 = FUN_100032f0(*(void **)((int)this + 4));
      while (0 < iVar5) {
        FUN_10003350(*(void **)((int)this + 4),&stack0x00001004,0x1000);
        if (in_stack_00001004 == '\0') {
          *(undefined4 *)((int)this + 0xc) = 0xffffffff;
          return 0xffffffff;
        }
        iVar5 = _strnicmp(&stack0x00001004,s_Location__1000e1fc,9);
        if (iVar5 == 0) {
          pcVar6 = &stack0x0000100d;
          cVar1 = in_stack_0000100d;
          while (cVar1 == ' ') {
            pcVar7 = pcVar6 + 1;
            pcVar6 = pcVar6 + 1;
            cVar1 = *pcVar7;
          }
          if (*pcVar6 != '\0') {
            FUN_10003610(this,pcVar6);
            return 0;
          }
        }
        iVar5 = FUN_100032f0(*(void **)((int)this + 4));
      }
    }
    if (*(int *)((int)this + 0xc) == 2) {
      if (iVar12 == 0) {
        iVar5 = FUN_100032f0(*(void **)((int)this + 4));
        iVar12 = 1;
        if (iVar5 < 1) goto LAB_10003e87;
      }
      iVar5 = FUN_100032f0(*(void **)((int)this + 4));
      if (0 < iVar5) {
        while (FUN_10003350(*(void **)((int)this + 4),&param_1,0x1000), param_1 != '\0') {
          if (*(int *)((int)this + 0x34) == 0) {
            uVar9 = 0xffffffff;
            pcVar6 = &param_1;
            do {
              if (uVar9 == 0) break;
              uVar9 = uVar9 - 1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            *(uint *)((int)this + 0x38) = ~uVar9;
            pcVar6 = malloc(~uVar9 + 1);
            *(char **)((int)this + 0x34) = pcVar6;
            if (pcVar6 != (char *)0x0) {
              uVar9 = 0xffffffff;
              pcVar7 = &param_1;
              do {
                pcVar14 = pcVar7;
                if (uVar9 == 0) break;
                uVar9 = uVar9 - 1;
                pcVar14 = pcVar7 + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar14;
              } while (cVar1 != '\0');
              uVar9 = ~uVar9;
              pcVar7 = pcVar14 + -uVar9;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
                pcVar7 = pcVar7 + 4;
                pcVar6 = pcVar6 + 4;
              }
              for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *pcVar6 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                pcVar6 = pcVar6 + 1;
              }
              *(undefined1 *)(*(int *)((int)this + 0x38) + *(int *)((int)this + 0x34)) = 0;
            }
          }
          else {
            uVar9 = *(uint *)((int)this + 0x38);
            uVar10 = 0xffffffff;
            pcVar6 = &param_1;
            do {
              if (uVar10 == 0) break;
              uVar10 = uVar10 - 1;
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            *(uint *)((int)this + 0x38) = uVar9 + ~uVar10;
            puVar8 = malloc(uVar9 + ~uVar10 + 1);
            if (puVar8 != (undefined4 *)0x0) {
              puVar13 = *(undefined4 **)((int)this + 0x34);
              puVar15 = puVar8;
              for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
                *puVar15 = *puVar13;
                puVar13 = puVar13 + 1;
                puVar15 = puVar15 + 1;
              }
              for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *(undefined1 *)puVar15 = *(undefined1 *)puVar13;
                puVar13 = (undefined4 *)((int)puVar13 + 1);
                puVar15 = (undefined4 *)((int)puVar15 + 1);
              }
              uVar10 = 0xffffffff;
              pcVar6 = &param_1;
              do {
                pcVar7 = pcVar6;
                if (uVar10 == 0) break;
                uVar10 = uVar10 - 1;
                pcVar7 = pcVar6 + 1;
                cVar1 = *pcVar6;
                pcVar6 = pcVar7;
              } while (cVar1 != '\0');
              uVar10 = ~uVar10;
              pcVar6 = pcVar7 + -uVar10;
              pcVar7 = (char *)((int)puVar8 + uVar9);
              for (uVar11 = uVar10 >> 2; uVar11 != 0; uVar11 = uVar11 - 1) {
                *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
                pcVar6 = pcVar6 + 4;
                pcVar7 = pcVar7 + 4;
              }
              for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                *pcVar7 = *pcVar6;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
              }
              *(undefined1 *)(*(int *)((int)this + 0x38) + (int)puVar8) = 0;
              free(*(void **)((int)this + 0x34));
              *(undefined4 **)((int)this + 0x34) = puVar8;
            }
          }
          iVar5 = FUN_100032f0(*(void **)((int)this + 4));
          if (iVar5 < 1) {
            return 0;
          }
        }
        *(undefined4 *)((int)this + 0xc) = 3;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
LAB_10003ea8:
  pcVar6 = *(char **)(*(int *)((int)this + 4) + 0x144);
  if (*(void **)((int)this + 0x40) != (void *)0x0) {
    free(*(void **)((int)this + 0x40));
  }
  uVar9 = 0xffffffff;
  pcVar7 = pcVar6;
  do {
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  pcVar7 = malloc(~uVar9);
  uVar9 = 0xffffffff;
  *(char **)((int)this + 0x40) = pcVar7;
  do {
    pcVar14 = pcVar6;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar14 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar14;
  } while (cVar1 != '\0');
  uVar9 = ~uVar9;
  pcVar6 = pcVar14 + -uVar9;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return 0xffffffff;
  while( true ) {
    uVar9 = uVar9 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    if (cVar1 == '\0') break;
code_r0x10003f33:
    if (uVar9 == 0) break;
  }
  pcVar6 = malloc(~uVar9);
  uVar9 = 0xffffffff;
  *(char **)((int)this + 0x40) = pcVar6;
  pcVar7 = &param_1;
  do {
    pcVar14 = pcVar7;
    if (uVar9 == 0) break;
    uVar9 = uVar9 - 1;
    pcVar14 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar14;
  } while (cVar1 != '\0');
  uVar9 = ~uVar9;
  pcVar7 = pcVar14 + -uVar9;
  for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
    *pcVar6 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *(undefined4 *)((int)this + 0xc) = 0xffffffff;
  return 0xffffffff;
}
