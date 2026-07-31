
void FUN_10006d10(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  
  puVar2 = (undefined4 *)FUN_100086e0(param_1);
  uVar1 = *puVar2;
  puVar2 = (undefined4 *)FUN_10007c60(uVar1);
  puVar3 = (undefined4 *)FUN_100086e0(param_1);
  *puVar3 = *puVar2;
  puVar2 = (undefined4 *)FUN_10007c60(uVar1);
  pcVar4 = (char *)FUN_10005a90(*puVar2);
  if (*pcVar4 == '\0') {
    puVar2 = (undefined4 *)FUN_10007c60(uVar1);
    piVar5 = (int *)FUN_100019c0(*puVar2);
    *piVar5 = param_1;
  }
  puVar2 = (undefined4 *)FUN_100019c0(param_1);
  puVar3 = (undefined4 *)FUN_100019c0(uVar1);
  *puVar3 = *puVar2;
  piVar5 = (int *)FUN_10006e40();
  if (param_1 == *piVar5) {
    puVar2 = (undefined4 *)FUN_10006e40();
    *puVar2 = uVar1;
  }
  else {
    puVar2 = (undefined4 *)FUN_100019c0(param_1);
    piVar5 = (int *)FUN_10007c60(*puVar2);
    if (param_1 == *piVar5) {
      puVar2 = (undefined4 *)FUN_100019c0(param_1);
      puVar2 = (undefined4 *)FUN_10007c60(*puVar2);
      *puVar2 = uVar1;
    }
    else {
      puVar2 = (undefined4 *)FUN_100019c0(param_1);
      puVar2 = (undefined4 *)FUN_100086e0(*puVar2);
      *puVar2 = uVar1;
    }
  }
  piVar5 = (int *)FUN_10007c60(uVar1);
  *piVar5 = param_1;
  puVar2 = (undefined4 *)FUN_100019c0(param_1);
  *puVar2 = uVar1;
  return;
}
