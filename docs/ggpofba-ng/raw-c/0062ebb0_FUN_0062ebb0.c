
void FUN_0062ebb0(void)

{
  double dVar1;
  uint uVar2;
  DWORD DVar3;
  HWND pHVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined4 local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  int local_29c;
  int local_298;
  uint local_294;
  uint local_290;
  char local_28c [128];
  char local_20c [128];
  char local_18c [128];
  char local_10c [128];
  char local_8c [132];
  uint local_8;
  
  local_8 = DAT_00871720 ^ (uint)&local_2a8;
  ggpo_get_stats(DAT_00b1a804);
  if ((int)DAT_00b1a9e4 < 0x1000) {
    uVar5 = DAT_00b1a9e4;
    uVar2 = DAT_00b1a9e0;
    DAT_00b1a9e4 = DAT_00b1a9e4 + 1;
  }
  else {
    uVar2 = DAT_00b1a9e0 + 1 & 0x80000fff;
    uVar5 = DAT_00b1a9e0;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
    }
  }
  DAT_00b1a9e0 = uVar2;
  *(undefined4 *)(&DAT_00abade0 + uVar5 * 4) = local_2a8;
  *(undefined4 *)(&DAT_00ac2de0 + uVar5 * 4) = local_2a0;
  *(undefined4 *)(&DAT_00ac6de8 + uVar5 * 4) = local_2a4;
  *(int *)(&DAT_00ad2df0 + uVar5 * 4) = local_29c;
  *(uint *)(&DAT_00acedf0 + uVar5 * 4) = local_294;
  *(uint *)(&DAT_00acade8 + uVar5 * 4) = local_290;
  uVar2 = (int)local_290 >> 0x1f;
  uVar6 = (int)local_294 >> 0x1f;
  if (((int)local_294 < 0) && ((int)local_290 < 0)) {
    uVar2 = ((local_294 ^ uVar6) - uVar6) - ((local_290 ^ uVar2) - uVar2);
    uVar6 = (int)uVar2 >> 0x1f;
    *(uint *)(&DAT_00abede0 + uVar5 * 4) = (uVar2 ^ uVar6) - uVar6;
  }
  else if (((int)local_294 < 1) || ((int)local_290 < 1)) {
    *(uint *)(&DAT_00abede0 + uVar5 * 4) =
         ((local_290 ^ uVar2) - uVar2) + ((local_294 ^ uVar6) - uVar6);
  }
  else {
    *(undefined4 *)(&DAT_00abede0 + uVar5 * 4) = 0;
  }
  DVar3 = timeGetTime();
  if (DAT_00b1a9d4 != (HWND)0x0) {
    uVar7 = 0;
    pHVar4 = GetDlgItem(DAT_00b1a9d4,0x6b);
    InvalidateRect(pHVar4,(RECT *)uVar7,(BOOL)((ulonglong)uVar7 >> 0x20));
    uVar7 = 0;
    pHVar4 = GetDlgItem(DAT_00b1a9d4,0x6a);
    InvalidateRect(pHVar4,(RECT *)uVar7,(BOOL)((ulonglong)uVar7 >> 0x20));
    if ((int)(DAT_00b1a9dc + 500) < (int)DVar3) {
      _sprintf(local_10c,"%d ms");
      if (local_29c == 0) {
        dVar1 = 0.0;
      }
      else {
        dVar1 = ((double)local_29c * 60.0) / 1000.0;
      }
      _sprintf(local_28c,"%.1f frames",dVar1);
      _sprintf(local_20c,"%.2f kilobytes/sec",(double)local_298 * 0.125);
      _sprintf(local_18c,"%d frames",local_294);
      _sprintf(local_8c,"%d frames",local_290);
      pcVar8 = local_10c;
      pHVar4 = GetDlgItem(DAT_00b1a9d4,0x6f);
      SetWindowTextA(pHVar4,pcVar8);
      pcVar8 = local_28c;
      pHVar4 = GetDlgItem(DAT_00b1a9d4,0x67);
      SetWindowTextA(pHVar4,pcVar8);
      pcVar8 = local_20c;
      pHVar4 = GetDlgItem(DAT_00b1a9d4,0x70);
      SetWindowTextA(pHVar4,pcVar8);
      pcVar8 = local_18c;
      pHVar4 = GetDlgItem(DAT_00b1a9d4,0x68);
      SetWindowTextA(pHVar4,pcVar8);
      pcVar8 = local_8c;
      pHVar4 = GetDlgItem(DAT_00b1a9d4,0x69);
      SetWindowTextA(pHVar4,pcVar8);
      DAT_00b1a9dc = DVar3;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&local_2a8);
  return;
}
