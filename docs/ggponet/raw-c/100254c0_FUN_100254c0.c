
void FUN_100254c0(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  size_t _Size;
  undefined4 *local_20;
  undefined4 *local_10;
  int local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = FUN_10025210(param_1,&local_c);
  _Size = param_2 - local_c;
  iVar1 = FUN_100118ec(0x1104);
  if (iVar1 == 0) {
    local_20 = (undefined4 *)0x0;
  }
  else {
    local_20 = (undefined4 *)FUN_10004a40();
  }
  local_10 = local_20;
  *local_20 = 0xf;
  pvVar2 = _malloc(_Size);
  local_10[1] = pvVar2;
  local_10[2] = _Size;
  local_10[3] = local_8;
  _memcpy((void *)local_10[1],(void *)(param_1 + local_c),_Size);
  FUN_10004ac0(&local_10);
  return;
}
