
void FUN_1000aa50(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 local_c;
  
  if (*(uint *)(in_ECX + 0x14) <= *(int *)(in_ECX + 0x1c) + 1U) {
    FUN_1000ac90(1);
  }
  local_c = *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c);
  if (*(uint *)(in_ECX + 0x14) <= local_c) {
    local_c = local_c - *(int *)(in_ECX + 0x14);
  }
  if (*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) == 0) {
    uVar1 = FUN_1000aec0(1);
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4) = uVar1;
  }
  FUN_1000aee0(*(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4),param_1);
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
  return;
}
