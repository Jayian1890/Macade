
int FUN_10022b70(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  DVar1 = timeGetTime();
  if (param_1 < (int)DVar1) {
    iVar2 = (int)((DVar1 - param_1) * 0x3c) / 1000;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}
