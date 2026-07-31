
void FUN_10002c50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  
  uVar1 = _Char_traits_cat<>(&param_1,&param_2);
  _Destroy_range<>(param_1,param_2,param_3,uVar1);
  return;
}
