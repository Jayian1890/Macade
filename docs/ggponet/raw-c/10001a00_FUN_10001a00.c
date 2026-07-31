
void FUN_10001a00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_10002210();
  puVar2 = (undefined4 *)FUN_100019c0(uVar1,param_3);
  uVar3 = FUN_10001f30(uVar1,*puVar2);
  FUN_10002070(1);
  puVar2 = (undefined4 *)FUN_100019c0(uVar1);
  *puVar2 = uVar3;
  puVar2 = (undefined4 *)FUN_100019c0(uVar3);
  puVar2 = (undefined4 *)FUN_10007c60(*puVar2);
  *puVar2 = uVar3;
  return;
}
