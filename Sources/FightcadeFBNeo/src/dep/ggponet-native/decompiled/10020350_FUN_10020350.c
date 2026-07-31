
void FUN_10020350(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = param_1;
  puVar3 = in_ECX;
  for (iVar1 = 7; puVar3 = puVar3 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
  }
  in_ECX[0x43] = 0;
  local_c = param_1[7];
  local_8 = param_1[8];
  FUN_100205a0(&local_c);
  return;
}
