
bool FUN_100230e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_10008a70();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)FUN_10004aa0();
    *param_1 = *puVar2;
    FUN_10008a90();
  }
  return iVar1 != 0;
}
