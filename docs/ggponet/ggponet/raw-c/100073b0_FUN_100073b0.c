
void FUN_100073b0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  
  cVar1 = FUN_10001170();
  if (cVar1 == '\0') {
    FUN_100116d5();
  }
  pcVar2 = (char *)FUN_10005a90(*(undefined4 *)(in_ECX + 4));
  if (*pcVar2 == '\0') {
    puVar3 = (undefined4 *)FUN_100086e0(*(undefined4 *)(in_ECX + 4));
    pcVar2 = (char *)FUN_10005a90(*puVar3);
    if (*pcVar2 == '\0') {
      puVar3 = (undefined4 *)FUN_100086e0(*(undefined4 *)(in_ECX + 4));
      uVar4 = FUN_100075a0(*puVar3);
      *(undefined4 *)(in_ECX + 4) = uVar4;
    }
    else {
      while( true ) {
        puVar3 = (undefined4 *)FUN_100019c0(*(undefined4 *)(in_ECX + 4));
        uVar4 = *puVar3;
        pcVar2 = (char *)FUN_10005a90(uVar4);
        if ((*pcVar2 != '\0') ||
           (piVar5 = (int *)FUN_100086e0(uVar4), *(int *)(in_ECX + 4) != *piVar5)) break;
        *(undefined4 *)(in_ECX + 4) = uVar4;
      }
      *(undefined4 *)(in_ECX + 4) = uVar4;
    }
  }
  else {
    FUN_100116d5();
  }
  return;
}
