
/* WARNING: Type propagation algorithm not settling */

void FUN_1000da10(int param_1)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 *in_ECX;
  int in_EDX;
  uint uVar3;
  int iVar4;
  short *psVar5;
  short asStack_20 [16];
  
  sVar1 = 0;
  psVar5 = asStack_20;
  iVar4 = 0xf;
  do {
    psVar5 = (short *)((int)psVar5 + 2);
    sVar1 = (*(short *)((param_1 - (int)(asStack_20 + 1)) + (int)psVar5) + sVar1) * 2;
    iVar4 = iVar4 + -1;
    *psVar5 = sVar1;
  } while (iVar4 != 0);
  if (-1 < in_EDX) {
    iVar4 = in_EDX + 1;
    do {
      uVar3 = (uint)(ushort)in_ECX[1];
      if (uVar3 != 0) {
        asStack_20[uVar3] = asStack_20[uVar3] + 1;
        uVar2 = FUN_1000e870();
        *in_ECX = uVar2;
      }
      in_ECX = in_ECX + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}
