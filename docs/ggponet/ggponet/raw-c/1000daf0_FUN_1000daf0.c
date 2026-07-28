
void FUN_1000daf0(int param_1)

{
  short *psVar1;
  ushort uVar2;
  int in_ECX;
  int in_EDX;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint local_4;
  
  uVar2 = *(ushort *)(in_EDX + 2);
  iVar5 = 0;
  local_4 = 0xffffffff;
  iVar8 = 7;
  iVar4 = 4;
  if (uVar2 == 0) {
    iVar8 = 0x8a;
    iVar4 = 3;
  }
  *(undefined2 *)(in_EDX + 6 + param_1 * 4) = 0xffff;
  if (-1 < param_1) {
    puVar3 = (ushort *)(in_EDX + 6);
    param_1 = param_1 + 1;
    uVar6 = (uint)uVar2;
    do {
      uVar7 = (uint)*puVar3;
      iVar5 = iVar5 + 1;
      if ((iVar8 <= iVar5) || (uVar6 != uVar7)) {
        if (iVar5 < iVar4) {
          psVar1 = (short *)(in_ECX + 0xa74 + uVar6 * 4);
          *psVar1 = *psVar1 + (short)iVar5;
        }
        else if (uVar6 == 0) {
          if (iVar5 < 0xb) {
            *(short *)(in_ECX + 0xab8) = *(short *)(in_ECX + 0xab8) + 1;
          }
          else {
            *(short *)(in_ECX + 0xabc) = *(short *)(in_ECX + 0xabc) + 1;
          }
        }
        else {
          if (uVar6 != local_4) {
            psVar1 = (short *)(in_ECX + 0xa74 + uVar6 * 4);
            *psVar1 = *psVar1 + 1;
          }
          *(short *)(in_ECX + 0xab4) = *(short *)(in_ECX + 0xab4) + 1;
        }
        iVar5 = 0;
        local_4 = uVar6;
        if (uVar7 == 0) {
          iVar8 = 0x8a;
          iVar4 = 3;
        }
        else if (uVar6 == uVar7) {
          iVar8 = 6;
          iVar4 = 3;
        }
        else {
          iVar8 = 7;
          iVar4 = 4;
        }
      }
      puVar3 = puVar3 + 2;
      param_1 = param_1 + -1;
      uVar6 = uVar7;
    } while (param_1 != 0);
  }
  return;
}
