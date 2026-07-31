
undefined4 FUN_10006250(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = (undefined4 *)FUN_10006e40();
  local_c = *puVar2;
  local_8 = *(undefined4 *)(in_ECX + 0x18);
  while (pcVar3 = (char *)FUN_10005a90(local_c), *pcVar3 == '\0') {
    uVar5 = param_1;
    uVar4 = FUN_10004ea0(local_c,param_1);
    cVar1 = FUN_10005650(uVar4,uVar5);
    if (cVar1 == '\0') {
      local_8 = local_c;
      puVar2 = (undefined4 *)FUN_10007c60(local_c);
      local_c = *puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_100086e0(local_c);
      local_c = *puVar2;
    }
  }
  return local_8;
}
