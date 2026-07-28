
void FUN_10003560(char *param_1,undefined1 *param_2)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  char local_44 [68];
  
  pcVar3 = s_ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef_1000e110;
  pcVar5 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar5 = pcVar5 + 4;
  }
  *pcVar5 = *pcVar3;
  iVar1 = 0;
  uVar4 = 0;
  cVar2 = *param_1;
  if (cVar2 != '\0') {
    if (cVar2 == '\0') goto joined_r0x1000359b;
    do {
      iVar1 = iVar1 + 8;
      uVar4 = uVar4 << 8 | (int)cVar2;
      param_1 = param_1 + 1;
joined_r0x1000359b:
      while (5 < iVar1) {
        iVar1 = iVar1 + -6;
        *param_2 = local_44[(int)uVar4 >> ((byte)iVar1 & 0x1f) & 0x3f];
        param_2 = param_2 + 1;
      }
      cVar2 = *param_1;
    } while (cVar2 != '\0');
    if (iVar1 == 4) {
      *param_2 = local_44[(uVar4 & 0xf) * 4];
      param_2[1] = '=';
      param_2[2] = '\0';
      return;
    }
    if (iVar1 == 2) {
      *param_2 = local_44[(uVar4 & 3) * 0x10];
      param_2[1] = '=';
      param_2[2] = '=';
      param_2[3] = '\0';
      return;
    }
  }
  *param_2 = '\0';
  return;
}
