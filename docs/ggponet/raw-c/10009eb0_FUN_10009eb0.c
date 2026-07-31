
void FUN_10009eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint3 in_ECX;
  uint uVar2;
  
  uVar2 = (uint)in_ECX;
  uVar1 = _Char_traits_cat<>(&param_1,&param_1,uVar2);
  FUN_1000a160(param_1,param_2,param_3,param_4,uVar1,uVar2 >> 0x18);
  return;
}
