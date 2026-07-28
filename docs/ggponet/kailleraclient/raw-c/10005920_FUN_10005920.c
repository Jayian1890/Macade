
void FUN_10005920(void)

{
  UINT UVar1;
  undefined4 *puVar2;
  char *pcVar3;
  UINT UVar4;
  int iVar5;
  CHAR local_80 [128];
  
  UVar1 = FUN_100019d0(DAT_1000ef90,s_nbrecents_1000e3d0,0);
  iVar5 = 0;
  if (0 < (int)UVar1) {
    do {
      puVar2 = malloc(0x10);
      wsprintfA(local_80,s_recent_i_name_1000e3c0,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      *puVar2 = pcVar3;
      wsprintfA(local_80,s_recent_i_loc_1000e3b0,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      puVar2[1] = pcVar3;
      wsprintfA(local_80,s_recent_i_ip_1000e3a4,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      puVar2[2] = pcVar3;
      wsprintfA(local_80,s_recent_i_times_1000e394,iVar5);
      UVar4 = FUN_100019d0(DAT_1000ef90,local_80,1);
      puVar2[3] = UVar4;
      if ((DAT_1000f3c8 == 0) || ((DAT_1000f3cc & 0x1f) == 0)) {
        DAT_1000f3c8 = (int)realloc((void *)DAT_1000f3c8,DAT_1000f3cc * 4 + 0x80);
      }
      *(undefined4 **)(DAT_1000f3c8 + DAT_1000f3cc * 4) = puVar2;
      DAT_1000f3cc = DAT_1000f3cc + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)UVar1);
  }
  return;
}
