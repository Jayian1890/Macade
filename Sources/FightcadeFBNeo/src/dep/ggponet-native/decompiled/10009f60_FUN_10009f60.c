
void FUN_10009f60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint3 in_ECX;
  uint uVar4;
  
  uVar4 = (uint)in_ECX;
  uVar1 = _Char_traits_cat<>(&param_3,uVar4);
  puVar2 = (undefined1 *)FUN_10008c10(&stack0xfffffff9,&param_1,&param_3,uVar1,uVar4 >> 0x18);
  uVar3 = FUN_10008b90(&param_2,param_3,*puVar2);
  uVar3 = FUN_10008b90(&param_1,uVar3);
  FUN_1000a2a0(uVar3);
  return;
}
