
undefined4 __cdecl FUN_10002560(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_8;
  int local_4;
  
  local_8 = param_1;
  local_4 = param_2 * 1000;
  iVar1 = DAT_1000ec98 + 1;
  puVar4 = &DAT_1000ea88;
  puVar5 = &DAT_1000eb90;
  for (iVar3 = 0x41; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar3 = Ordinal_18(iVar1,&DAT_1000eb90,0,0,&local_8);
  iVar1 = DAT_1000ea84;
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = 0;
  if (0 < DAT_1000ea84) {
    do {
      if ((iVar3 < 0) || (DAT_1000ea84 <= iVar3)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(DAT_1000ea80 + iVar3 * 4);
      }
      iVar2 = Ordinal_151(*(undefined4 *)(iVar6 + 8),&DAT_1000eb90);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar6 + 0xc) = 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 1;
}
