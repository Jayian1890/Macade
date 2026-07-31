
void FUN_100274b0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  char local_114 [268];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_10002810();
  _sprintf(local_114,"synclogs\\state-%04d-original.log",uVar1);
  (**(code **)(in_ECX + 0x10))
            (local_114,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  uVar1 = FUN_10002810();
  _sprintf(local_114,"synclogs\\state-%04d-replay.log",uVar1);
  iVar2 = FUN_1001fce0();
  puVar3 = (undefined4 *)FUN_1001fce0(*(undefined4 *)(iVar2 + 4));
  (**(code **)(in_ECX + 0x10))(local_114,*puVar3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
