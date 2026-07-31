
int FUN_10027280(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int local_8;
  
  local_8 = 0;
  puVar2 = param_1;
  puVar3 = (uint *)(in_ECX + 0x144 + (*param_1 % 10) * 0x1c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 4 + (*param_1 % 0x28) * 4) = param_2;
  *(undefined4 *)(in_ECX + 0xa4 + (*param_1 % 0x28) * 4) = param_3;
  if (*(int *)(in_ECX + 0x25c) <= (int)*param_1) {
    local_8 = FUN_10027120();
    if (0 < local_8) {
      *(uint *)(in_ECX + 0x25c) = *param_1 + 0xf0;
    }
  }
  return local_8;
}
