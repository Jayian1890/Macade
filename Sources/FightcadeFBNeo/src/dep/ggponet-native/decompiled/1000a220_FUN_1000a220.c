
void FUN_1000a220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint3 in_ECX;
  uint uVar3;
  
  uVar3 = (uint)in_ECX;
  uVar1 = _Char_traits_cat<>(&param_3,uVar3);
  uVar2 = FUN_10008b90(&param_2,param_3,param_4,uVar1,uVar3 >> 0x18);
  uVar2 = FUN_10008b90(&param_1,uVar2);
  FUN_1000a3f0(uVar2);
  return;
}
