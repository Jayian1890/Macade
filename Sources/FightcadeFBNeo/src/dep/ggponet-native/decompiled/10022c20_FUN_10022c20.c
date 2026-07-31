
void FUN_10022c20(int param_1)

{
  DWORD DVar1;
  int in_ECX;
  
  DVar1 = timeGetTime();
  *(DWORD *)(in_ECX + 0x108c) = DVar1 - *(int *)(param_1 + 1);
  return;
}
