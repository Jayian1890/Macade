
void FUN_10008f00(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = FUN_10008eb0();
  uVar2 = FUN_10009100();
  if (uVar1 < uVar2) {
    uVar3 = FUN_10009270(*(undefined4 *)(in_ECX + 0x10),1,param_1);
    *(undefined4 *)(in_ECX + 0x10) = uVar3;
  }
  else {
    puVar4 = (undefined4 *)FUN_10009140(local_14);
    local_c = *puVar4;
    local_8 = puVar4[1];
    FUN_10009170(local_1c,local_c,local_8,param_1);
  }
  return;
}
