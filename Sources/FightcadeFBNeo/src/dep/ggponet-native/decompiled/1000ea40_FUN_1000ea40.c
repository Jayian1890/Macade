
void FUN_1000ea40(int *param_1)

{
  int iVar1;
  int *in_ECX;
  int in_EDX;
  
  if (param_1 != (int *)0x0) {
    *param_1 = in_ECX[0xf];
  }
  if ((*in_ECX == 4) || (*in_ECX == 5)) {
    (**(code **)(in_EDX + 0x24))();
  }
  if (*in_ECX == 6) {
    FUN_10010030();
  }
  *in_ECX = 0;
  in_ECX[0xd] = in_ECX[10];
  in_ECX[0xc] = in_ECX[10];
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if ((code *)in_ECX[0xe] != (code *)0x0) {
    iVar1 = (*(code *)in_ECX[0xe])(0);
    in_ECX[0xf] = iVar1;
    *(int *)(in_EDX + 0x30) = iVar1;
  }
  return;
}
