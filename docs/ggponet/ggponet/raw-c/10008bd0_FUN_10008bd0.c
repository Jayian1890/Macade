
void FUN_10008bd0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint3 in_ECX;
  undefined4 uStack_8;
  
  uStack_8 = (uint)in_ECX;
  puVar1 = (undefined1 *)FUN_10008c10((int)&uStack_8 + 2,&param_1,0);
  FUN_10008c20(param_1,param_2,param_3,*puVar1);
  return;
}
