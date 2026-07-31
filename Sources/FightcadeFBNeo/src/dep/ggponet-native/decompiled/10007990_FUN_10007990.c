
undefined4 * FUN_10007990(undefined4 param_1)

{
  DWORD DVar1;
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  DVar1 = timeGetTime();
  in_ECX[1] = DVar1;
  return in_ECX;
}
