
void FUN_10028b30(void *param_1,int param_2,int param_3)

{
  char cVar1;
  int in_ECX;
  int local_40;
  int local_3c;
  undefined4 local_34;
  int local_30;
  int local_28;
  undefined1 local_24 [8];
  undefined1 local_1c [20];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(char *)(in_ECX + 0x19c9) == '\0') {
    if (param_3 < 3) {
      local_3c = param_3;
    }
    else {
      local_3c = 2;
    }
    FUN_100224a0(0xffffffff,param_1,param_2,local_3c,*(char *)(in_ECX + 0x19d4) != '\0');
    if (*(char *)(in_ECX + 0x19c8) == '\0') {
      cVar1 = FUN_10020480(local_24);
      if (cVar1 == '\0') goto LAB_10028c80;
      local_28 = FUN_10027280(local_24,*(undefined4 *)(in_ECX + 0x19cc),
                              *(undefined4 *)(in_ECX + 0x19d0));
      if (0 < local_28) {
        local_34 = 0x3ec;
        local_30 = local_28;
        (**(code **)(in_ECX + 0x20))(&local_34);
      }
      FUN_10023eb0(local_24);
    }
    *(undefined1 *)(in_ECX + 0x19d5) = 1;
    FUN_100204f0(local_24);
    _memset(param_1,0,param_2 * param_3);
    if (param_3 < 2) {
      local_40 = param_3;
    }
    else {
      local_40 = 2;
    }
    _memcpy(param_1,local_1c,param_2 * local_40);
  }
LAB_10028c80:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
