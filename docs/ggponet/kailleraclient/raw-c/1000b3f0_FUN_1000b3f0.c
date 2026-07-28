
void __cdecl FUN_1000b3f0(byte *param_1,char *param_2)

{
  byte bVar1;
  LRESULT LVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  WPARAM wParam;
  bool bVar6;
  undefined1 local_128 [8];
  undefined4 local_120;
  byte *local_114;
  undefined4 local_110;
  byte local_100 [256];
  
  wParam = 0;
  LVar2 = SendMessageA(DAT_1000f218,0x1004,0,0);
  if (0 < LVar2) {
    do {
      local_114 = local_100;
      local_120 = 7;
      local_110 = 0xff;
      SendMessageA(DAT_1000f218,0x102d,wParam,(LPARAM)local_128);
      pbVar5 = local_100;
      pbVar3 = param_1;
      do {
        bVar1 = *pbVar3;
        bVar6 = bVar1 < *pbVar5;
        if (bVar1 != *pbVar5) {
LAB_1000b475:
          iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
          goto LAB_1000b47a;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar6 = bVar1 < pbVar5[1];
        if (bVar1 != pbVar5[1]) goto LAB_1000b475;
        pbVar3 = pbVar3 + 2;
        pbVar5 = pbVar5 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_1000b47a:
      if (iVar4 == 0) {
        FUN_100042c0(&DAT_1000f218,wParam,6,param_2);
        FUN_100044f0(&DAT_1000f218);
      }
      wParam = wParam + 1;
      LVar2 = SendMessageA(DAT_1000f218,0x1004,0,0);
    } while ((int)wParam < LVar2);
  }
  return;
}
