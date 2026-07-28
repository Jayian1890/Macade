
uint FUN_1000bc00(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *in_ECX;
  int in_EDX;
  uint uVar5;
  
  uVar5 = 0xffff;
  if (in_ECX[3] - 5U < 0xffff) {
    uVar5 = in_ECX[3] - 5U;
  }
  do {
    uVar4 = in_ECX[0x1b];
    if (uVar4 < 2) {
      FUN_1000bd50();
      uVar4 = in_ECX[0x1b];
      if (uVar4 == 0) {
        if (in_EDX == 0) {
          return 0;
        }
        FUN_1000d2f0(in_ECX[0x19] - in_ECX[0x15],in_EDX == 4);
        in_ECX[0x15] = in_ECX[0x19];
        FUN_1000ba60();
        if (*(int *)(*in_ECX + 0x10) == 0) {
          return (in_EDX != 4) - 1 & 2;
        }
        return (-(uint)(in_EDX != 4) & 0xfffffffe) + 3;
      }
    }
    iVar2 = in_ECX[0x19];
    in_ECX[0x1b] = 0;
    in_ECX[0x19] = iVar2 + uVar4;
    uVar3 = in_ECX[0x19];
    uVar1 = in_ECX[0x15] + uVar5;
    if ((iVar2 + uVar4 == 0) || (uVar1 <= uVar3)) {
      in_ECX[0x19] = uVar1;
      in_ECX[0x1b] = uVar3 - uVar1;
      FUN_1000d2f0(uVar1 - in_ECX[0x15],0);
      in_ECX[0x15] = in_ECX[0x19];
      FUN_1000ba60();
      if (*(int *)(*in_ECX + 0x10) == 0) {
        return 0;
      }
    }
    if (in_ECX[9] - 0x106U <= (uint)(in_ECX[0x19] - in_ECX[0x15])) {
      FUN_1000d2f0(in_ECX[0x19] - in_ECX[0x15],0);
      in_ECX[0x15] = in_ECX[0x19];
      FUN_1000ba60();
      if (*(int *)(*in_ECX + 0x10) == 0) {
        return 0;
      }
    }
  } while( true );
}
