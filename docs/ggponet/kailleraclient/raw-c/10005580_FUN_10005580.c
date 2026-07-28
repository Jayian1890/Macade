
void FUN_10005580(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  CHAR local_80 [128];
  
  iVar1 = DAT_1000f3cc;
  if (0x14 < DAT_1000f3cc) {
    iVar1 = 0x14;
  }
  FUN_10001900(DAT_1000ef90,s_nbrecents_1000e3d0,iVar1,1);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      if ((iVar2 < 0) || (DAT_1000f3cc <= iVar2)) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = *(undefined4 **)(DAT_1000f3c8 + iVar2 * 4);
      }
      wsprintfA(local_80,s_recent_i_name_1000e3c0,iVar2);
      FUN_10001a50(DAT_1000ef90,local_80,(char *)*puVar3,1);
      wsprintfA(local_80,s_recent_i_loc_1000e3b0,iVar2);
      FUN_10001a50(DAT_1000ef90,local_80,(char *)puVar3[1],1);
      wsprintfA(local_80,s_recent_i_ip_1000e3a4,iVar2);
      FUN_10001a50(DAT_1000ef90,local_80,(char *)puVar3[2],1);
      wsprintfA(local_80,s_recent_i_times_1000e394,iVar2);
      FUN_10001900(DAT_1000ef90,local_80,puVar3[3],1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  FUN_10001640(DAT_1000ef90);
  return;
}
