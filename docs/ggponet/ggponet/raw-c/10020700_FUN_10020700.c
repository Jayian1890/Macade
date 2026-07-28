
void FUN_10020700(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 local_840 [7];
  undefined1 local_824 [1024];
  undefined1 local_424 [1024];
  int local_24 [7];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  *param_1 = -1;
  while (((*param_1 < 0 && (cVar1 = FUN_10003e80(), cVar1 == '\0')) &&
         (cVar1 = FUN_1000a890(), cVar1 == '\0'))) {
    piVar2 = (int *)FUN_10002dc0();
    piVar5 = local_24;
    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar5 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar5 = piVar5 + 1;
    }
    *(int *)(in_ECX + 0xac) = local_24[1];
    *(int *)(in_ECX + 0xa8) = local_24[0];
    cVar1 = FUN_10022020(in_ECX + 0xa8,0);
    if (cVar1 == '\0') {
      *param_1 = local_24[0];
      FUN_100226c0(local_424,1);
      FUN_100226c0(local_824,1);
      FUN_10021ff0("Frame p(%s) != r(%s)\n",local_424,local_824);
    }
    else {
      FUN_10022860("Predicted remote frame is correct.",1);
      puVar3 = (undefined4 *)FUN_10007af0();
      puVar6 = local_840;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar6 = puVar6 + 1;
      }
      FUN_100221f0(local_24);
      FUN_100206b0(local_840);
      FUN_10002e00();
      FUN_100016a0();
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
