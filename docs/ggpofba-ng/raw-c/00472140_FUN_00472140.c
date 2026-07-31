
undefined4 FUN_00472140(void)

{
  int *piVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 uStack_1c;
  undefined1 uStack_1a;
  char *local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  pcVar3 = _getenv("ggpofba.random.input");
  if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) || (DAT_00b181ea = 1, *pcVar3 == '0')) {
    DAT_00b181ea = 0;
  }
  if (DAT_00b187a8 == 0) {
    return 1;
  }
  local_18 = (char *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  DAT_009e714c = 0;
  uVar2 = 0;
  do {
    uVar6 = uVar2;
    (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
    iVar4 = __strnicmp(local_18,"P1",2);
    if (iVar4 != 0) break;
    uVar2 = uVar6 + 1;
  } while (uVar6 + 1 <= DAT_00b187a8);
  DAT_009e7138 = uVar6 - DAT_009e714c;
  iVar4 = 1;
  do {
    uStack_1a = 0;
    uStack_1c = CONCAT11((char)iVar4 + '1',0x50);
    (&DAT_009e714c)[iVar4] = uVar6;
    iVar5 = __strnicmp(local_18,(char *)&uStack_1c,2);
    for (; (iVar5 == 0 && (uVar6 < DAT_00b187a8)); uVar6 = uVar6 + 1) {
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
      iVar5 = __strnicmp(local_18,(char *)&uStack_1c,2);
    }
    piVar1 = &DAT_009e714c + iVar4;
    iVar4 = iVar4 + 1;
    (&DAT_009e7134)[iVar4] = uVar6 - *piVar1;
    uVar2 = uVar6;
  } while (iVar4 < 4);
  for (; (DAT_009e7134 = uVar2, (local_14 & 8) == 0 && (uVar6 < DAT_00b187a8)); uVar6 = uVar6 + 1) {
    (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x48))();
    uVar2 = DAT_009e7134;
  }
  DAT_009e7130 = uVar6;
  DAT_009e7148 = DAT_00b187a8 - uVar6;
  DAT_009e715c = uVar6 - DAT_009e7134;
  return 0;
}
