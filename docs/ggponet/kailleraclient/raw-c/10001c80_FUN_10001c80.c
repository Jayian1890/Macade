
char * __thiscall FUN_10001c80(void *this,undefined4 *param_1)

{
  char cVar1;
  size_t _Size;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 *puVar6;
  char *pcVar7;
  
  *(undefined4 *)this = *param_1;
  uVar3 = 0xffffffff;
  pcVar7 = (char *)(param_1 + 1);
  do {
    pcVar5 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar7 = this;
  for (uVar4 = uVar3 >> 2; pcVar7 = pcVar7 + 4, uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  _Size = param_1[10];
  *(size_t *)((int)this + 0x28) = _Size;
  puVar2 = malloc(_Size);
  *(undefined4 **)((int)this + 0x24) = puVar2;
  uVar3 = param_1[0xb];
  puVar6 = (undefined4 *)param_1[9];
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar2 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar2 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar2 = (undefined4 *)((int)puVar2 + 1);
  }
  *(undefined4 *)((int)this + 0x2c) = param_1[0xb];
  return this;
}
