
void FUN_10025810(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *local_1c;
  undefined4 *local_c;
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
    iVar1 = FUN_100118ec(0x1104);
    if (iVar1 == 0) {
      local_1c = (undefined4 *)0x0;
    }
    else {
      local_1c = (undefined4 *)FUN_10004a40();
    }
    local_c = local_1c;
    FUN_10025240(local_1c + 1,param_2,&local_8);
    FUN_10025240(local_c + 0x81,param_2,&local_8);
    FUN_10025240(local_c + 0x101,param_2,&local_8);
    uVar2 = FUN_10025210(param_2,&local_8);
    local_c[0x181] = uVar2;
    *local_c = 0xb;
    FUN_10004ac0(&local_c);
  }
  return;
}
