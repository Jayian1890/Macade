
/* __stdcall kailleraSetInfos,4 */

void kailleraSetInfos(undefined4 *param_1)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
                    /* 0x5be0  7  _kailleraSetInfos@4 */
  if (DAT_1000ef98 != 0) {
    free((void *)DAT_1000ef98);
  }
  DAT_1000ef98 = (int)_strdup((char *)*param_1);
  if (DAT_1000edc0 != (undefined4 *)0x0) {
    free(DAT_1000edc0);
  }
  iVar3 = 0;
  for (pcVar1 = (char *)param_1[1]; (*pcVar1 != '\0' || (pcVar1[1] != '\0')); pcVar1 = pcVar1 + 1) {
    iVar3 = iVar3 + 1;
  }
  uVar4 = iVar3 + 2;
  DAT_1000edc0 = malloc(uVar4);
  puVar5 = (undefined4 *)param_1[1];
  puVar6 = DAT_1000edc0;
  for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  DAT_1000edb8 = param_1[2];
  DAT_1000edb0 = param_1[3];
  DAT_1000edc4 = param_1[4];
  DAT_1000eeec = param_1[5];
  return;
}
