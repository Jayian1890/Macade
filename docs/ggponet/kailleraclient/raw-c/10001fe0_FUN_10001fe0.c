
void __thiscall FUN_10001fe0(void *this,char *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar5 = param_1 + 1;
  *(int *)this = (int)*param_1;
  iVar2 = 0;
  cVar1 = *pcVar5;
  while (cVar1 != '\0') {
    pcVar5 = pcVar5 + 1;
    *(char *)((int)this + iVar2 + 4) = cVar1;
    iVar2 = iVar2 + 1;
    cVar1 = *pcVar5;
  }
  *(undefined1 *)(iVar2 + 4 + (int)this) = 0;
  uVar4 = (param_2 - iVar2) - 2;
  FUN_10001cf0(this,uVar4);
  pcVar5 = pcVar5 + 1;
  pcVar6 = *(char **)((int)this + 0x24);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar6 = pcVar6 + 4;
  }
  for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar6 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar6 = pcVar6 + 1;
  }
  *(uint *)((int)this + 0x2c) = uVar4;
  return;
}
