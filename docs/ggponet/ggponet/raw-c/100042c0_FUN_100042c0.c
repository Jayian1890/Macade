
void FUN_100042c0(uint param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = FUN_100045a0();
  if ((uint)(iVar1 - *(int *)(in_ECX + 0x14)) < param_1) {
    FUN_100045c0();
  }
  local_c = *(uint *)(in_ECX + 0x14) >> 1;
  if (local_c < 8) {
    local_c = 8;
  }
  if (param_1 < local_c) {
    iVar1 = FUN_100045a0();
    if (*(uint *)(in_ECX + 0x14) <= iVar1 - local_c) {
      param_1 = local_c;
    }
  }
  local_8 = *(uint *)(in_ECX + 0x18);
  local_14 = FUN_10003bc0(*(int *)(in_ECX + 0x14) + param_1);
  local_10 = local_14 + local_8 * 4;
  local_10 = FUN_1000b050(*(int *)(in_ECX + 0x10) + local_8 * 4,
                          *(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x14) * 4,local_10,in_ECX + 8)
  ;
  if (param_1 < local_8) {
    FUN_1000b050(*(undefined4 *)(in_ECX + 0x10),*(int *)(in_ECX + 0x10) + param_1 * 4,local_10,
                 in_ECX + 8);
    local_10 = FUN_1000b050(*(int *)(in_ECX + 0x10) + param_1 * 4,
                            *(int *)(in_ECX + 0x10) + local_8 * 4,local_14,in_ECX + 8);
    local_20 = 0;
    FUN_10003cb0(local_10,param_1,&local_20,in_ECX + 8);
  }
  else {
    local_10 = FUN_1000b050(*(undefined4 *)(in_ECX + 0x10),*(int *)(in_ECX + 0x10) + local_8 * 4,
                            local_10,in_ECX + 8);
    local_18 = 0;
    FUN_10003cb0(local_10,param_1 - local_8,&local_18,in_ECX + 8);
    local_1c = 0;
    FUN_10003cb0(local_14,local_8,&local_1c,in_ECX + 8);
  }
  FUN_10004890(*(int *)(in_ECX + 0x10) + local_8 * 4,
               *(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x14) * 4,in_ECX + 8);
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_100033b0(*(undefined4 *)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 0x14));
  }
  *(int *)(in_ECX + 0x10) = local_14;
  *(uint *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + param_1;
  return;
}
