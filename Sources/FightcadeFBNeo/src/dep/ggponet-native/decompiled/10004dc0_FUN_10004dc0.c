
void FUN_10004dc0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_c;
  
  if (((uint)(*(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c)) % 4 == 0) &&
     (*(uint *)(in_ECX + 0x14) <= *(int *)(in_ECX + 0x1c) + 4U >> 2)) {
    FUN_10005860(1);
  }
  uVar1 = *(int *)(in_ECX + 0x18) + *(int *)(in_ECX + 0x1c);
  local_c = uVar1 >> 2;
  if (*(uint *)(in_ECX + 0x14) <= local_c) {
    local_c = local_c - *(int *)(in_ECX + 0x14);
  }
  if (*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) == 0) {
    uVar2 = FUN_10003bc0(4);
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + local_c * 4) = uVar2;
  }
  FUN_10007640(*(int *)(*(int *)(in_ECX + 0x10) + local_c * 4) + (uVar1 % 4) * 4,param_1);
  *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
  return;
}
