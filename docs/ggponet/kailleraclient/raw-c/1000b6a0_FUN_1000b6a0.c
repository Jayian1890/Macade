
void __cdecl FUN_1000b6a0(char *param_1,char *param_2,byte *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  int *local_4;
  
  iVar10 = 0;
  if (0 < (int)DAT_1000f3cc) {
    local_4 = DAT_1000f3c8;
    do {
      if ((iVar10 < 0) || ((int)DAT_1000f3cc <= iVar10)) {
        iVar8 = 0;
      }
      else {
        iVar8 = *local_4;
      }
      pbVar2 = *(byte **)(iVar8 + 8);
      pbVar9 = param_3;
      do {
        bVar1 = *pbVar2;
        bVar11 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_1000b6f7:
          iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_1000b6fc;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar11 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_1000b6f7;
        pbVar2 = pbVar2 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar3 = 0;
LAB_1000b6fc:
      if (iVar3 == 0) {
        *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) + 1;
        uVar7 = DAT_1000f3cc;
        if ((iVar10 < 0) || ((int)DAT_1000f3cc <= iVar10)) goto LAB_1000b7b8;
        iVar8 = DAT_1000f3c8[iVar10];
        if (0 < iVar10) {
          do {
            DAT_1000f3c8[iVar10] = DAT_1000f3c8[iVar10 + -1];
            iVar10 = iVar10 + -1;
          } while (0 < iVar10);
          *DAT_1000f3c8 = iVar8;
          FUN_1000b810();
          FUN_10005580();
          return;
        }
        goto LAB_1000b7b6;
      }
      iVar10 = iVar10 + 1;
      local_4 = local_4 + 1;
    } while (iVar10 < (int)DAT_1000f3cc);
  }
  puVar4 = malloc(0x10);
  pcVar5 = _strdup(param_1);
  *puVar4 = pcVar5;
  pcVar5 = _strdup(param_2);
  puVar4[1] = pcVar5;
  pcVar5 = _strdup((char *)param_3);
  puVar4[2] = pcVar5;
  puVar4[3] = 1;
  if ((DAT_1000f3c8 == (int *)0x0) || ((DAT_1000f3cc & 0x1f) == 0)) {
    DAT_1000f3c8 = realloc(DAT_1000f3c8,DAT_1000f3cc * 4 + 0x80);
  }
  DAT_1000f3c8[DAT_1000f3cc] = (int)puVar4;
  uVar7 = DAT_1000f3cc + 1;
  if ((-1 < (int)DAT_1000f3cc) && ((int)DAT_1000f3cc < (int)uVar7)) {
    iVar8 = DAT_1000f3c8[DAT_1000f3cc];
    for (uVar6 = DAT_1000f3cc; DAT_1000f3cc = uVar7, 0 < (int)uVar6; uVar6 = uVar6 - 1) {
      DAT_1000f3c8[uVar6] = DAT_1000f3c8[uVar6 - 1];
      uVar7 = DAT_1000f3cc;
    }
LAB_1000b7b6:
    *DAT_1000f3c8 = iVar8;
    uVar7 = DAT_1000f3cc;
  }
LAB_1000b7b8:
  DAT_1000f3cc = uVar7;
  FUN_1000b810();
  FUN_10005580();
  return;
}
