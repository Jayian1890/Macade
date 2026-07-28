
void FUN_10005a60(void)

{
  UINT UVar1;
  undefined4 *puVar2;
  char *pcVar3;
  UINT UVar4;
  int iVar5;
  CHAR local_80 [128];
  
  UVar1 = FUN_100019d0(DAT_1000ef90,s_nbfav_1000e4ec,0);
  iVar5 = 0;
  if (0 < (int)UVar1) {
    do {
      puVar2 = malloc(0x10);
      wsprintfA(local_80,s_fav_i_name_1000e4e0,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      *puVar2 = pcVar3;
      wsprintfA(local_80,s_fav_i_loc_1000e4d4,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      puVar2[1] = pcVar3;
      wsprintfA(local_80,s_fav_i_ip_1000e4c8,iVar5);
      pcVar3 = (char *)FUN_10001ba0(DAT_1000ef90,local_80,&DAT_1000ec9c);
      pcVar3 = _strdup(pcVar3);
      puVar2[2] = pcVar3;
      wsprintfA(local_80,s_fav_i_times_1000e4bc,iVar5);
      UVar4 = FUN_100019d0(DAT_1000ef90,local_80,1);
      puVar2[3] = UVar4;
      if ((DAT_1000f288 == 0) || ((DAT_1000f28c & 0x1f) == 0)) {
        DAT_1000f288 = (int)realloc((void *)DAT_1000f288,DAT_1000f28c * 4 + 0x80);
      }
      *(undefined4 **)(DAT_1000f288 + DAT_1000f28c * 4) = puVar2;
      DAT_1000f28c = DAT_1000f28c + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)UVar1);
  }
  return;
}
