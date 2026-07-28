
undefined4 FUN_0062df40(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  bool bVar5;
  
  ggpo_advance_frame(DAT_00b1a804);
  if (DAT_00b18d63 == '\0') {
    FUN_0062ebb0();
  }
  if (DAT_00b1a90c != 0) {
    pbVar4 = &DAT_00803700;
    pbVar2 = &DAT_00b1a930;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0062df94:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0062df99;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0062df94;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0062df99:
    if (iVar3 == 0) {
      FUN_0062eee0();
      DAT_00b1a90c = 0;
      return 1;
    }
    pbVar4 = &DAT_00802d10;
    pbVar2 = &DAT_00b1a930;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0062dfe0:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0062dfe5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0062dfe0;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0062dfe5:
    if (iVar3 == 0) {
      FUN_0062e620();
      DAT_00b1a90c = 0;
      return 1;
    }
    pbVar4 = &DAT_008041c0;
    pbVar2 = &DAT_00b1a930;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0062e026:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0062e02b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0062e026;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0062e02b:
    if (iVar3 == 0) {
      FUN_0062f180();
      DAT_00b1a90c = 0;
      return 1;
    }
    pbVar4 = &DAT_00806510;
    pbVar2 = &DAT_00b1a930;
    do {
      bVar1 = *pbVar2;
      bVar5 = bVar1 < *pbVar4;
      if (bVar1 != *pbVar4) {
LAB_0062e070:
        iVar3 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
        goto LAB_0062e075;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar5 = bVar1 < pbVar4[1];
      if (bVar1 != pbVar4[1]) goto LAB_0062e070;
      pbVar2 = pbVar2 + 2;
      pbVar4 = pbVar4 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_0062e075:
    if (iVar3 == 0) {
      FUN_0062e3c0();
    }
    DAT_00b1a90c = 0;
  }
  return 1;
}
