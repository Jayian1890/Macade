
undefined4 FUN_10005cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined1 local_24 [8];
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  uVar2 = FUN_10005ab0(local_c);
  cVar1 = FUN_10005710(uVar2);
  if (cVar1 != '\0') {
    uVar2 = FUN_10004c30(local_14);
    cVar1 = FUN_10005710(uVar2);
    if (cVar1 != '\0') {
      FUN_10006c90();
      FUN_10005ab0(param_1);
      return param_1;
    }
  }
  while (cVar1 = FUN_10004d50(&stack0x00000010), cVar1 != '\0') {
    puVar3 = (undefined4 *)FUN_10007240(local_1c,0);
    FUN_100064b0(local_24,*puVar3,puVar3[1]);
  }
  FUN_10006460(param_1,param_2,param_3);
  return param_1;
}
