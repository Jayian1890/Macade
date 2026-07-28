
void __thiscall FUN_10001e60(void *this,char *param_1,size_t param_2)

{
  char cVar1;
  char *_Source;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 *puVar7;
  
  _Source = *(char **)((int)this + 0x24);
  uVar3 = 0xffffffff;
  pcVar6 = _Source;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if ((int)(~uVar3 - 1) < (int)param_2) {
    uVar3 = 0xffffffff;
    pcVar6 = _Source;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    param_2 = ~uVar3 - 1;
  }
  sVar2 = *(int *)((int)this + 0x2c) + 1;
  if ((int)sVar2 <= (int)param_2) {
    param_2 = sVar2;
  }
  strncpy(param_1,_Source,param_2);
  param_1[param_2] = '\0';
  uVar4 = *(int *)((int)this + 0x2c) + (-1 - param_2);
  *(uint *)((int)this + 0x2c) = uVar4;
  puVar5 = (undefined4 *)((int)*(undefined4 **)((int)this + 0x24) + param_2 + 1);
  puVar7 = *(undefined4 **)((int)this + 0x24);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  return;
}
