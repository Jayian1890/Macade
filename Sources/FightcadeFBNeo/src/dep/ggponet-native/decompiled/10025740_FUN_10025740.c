
void FUN_10025740(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_1c;
  undefined4 *local_c;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = FUN_100118ec(0x1104);
  if (iVar1 == 0) {
    local_1c = (undefined4 *)0x0;
  }
  else {
    local_1c = (undefined4 *)FUN_10004a40();
  }
  local_c = local_1c;
  *local_1c = 8;
  FUN_10025240(local_1c + 1,param_1,&local_8);
  uVar2 = FUN_10025210(param_1,&local_8);
  local_c[0x21] = uVar2;
  uVar2 = FUN_10025210(param_1,&local_8);
  local_c[0x22] = uVar2;
  FUN_10021ff0("Starting match %s (port %d)\n",local_c + 1,local_c[0x21]);
  FUN_10004ac0(&local_c);
  return;
}
