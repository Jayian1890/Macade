
void FUN_10023960(void)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_18;
  
  DVar1 = timeGetTime();
  *(DWORD *)(in_ECX + 0x1094) = DVar1;
  uVar2 = _rand();
  *(uint *)(in_ECX + 0x109c) = uVar2 & 0xffff;
  iVar3 = FUN_100118ec(0x100c);
  if (iVar3 == 0) {
    local_18 = 0;
  }
  else {
    local_18 = FUN_10008950(1);
  }
  *(undefined4 *)(local_18 + 1) = *(undefined4 *)(in_ECX + 0x109c);
  FUN_10023930(local_18);
  return;
}
