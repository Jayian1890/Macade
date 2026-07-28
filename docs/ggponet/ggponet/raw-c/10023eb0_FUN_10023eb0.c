
void FUN_10023eb0(int *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  FUN_100016e0(param_1);
  cVar1 = FUN_10022020(param_1,1);
  if (cVar1 == '\0') {
    *(undefined4 *)(in_ECX + 0x1138) = 0;
  }
  else {
    *(int *)(in_ECX + 0x1138) = *(int *)(in_ECX + 0x1138) + 1;
  }
  piVar3 = param_1;
  piVar4 = (int *)(in_ECX + 0x111c);
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  if (((*param_1 < DAT_1003852c) || (*(int *)(in_ECX + 0x1138) < *(int *)(in_ECX + 0x1140))) ||
     (*param_1 % *(int *)(in_ECX + 0x113c) == 0)) {
    FUN_10022c50(in_ECX,"Sending frame %d (not idle)\n",*param_1);
    FUN_100239f0();
  }
  else {
    FUN_10022c50(in_ECX,"Skipping frame %d (idle)\n",*param_1);
  }
  return;
}
