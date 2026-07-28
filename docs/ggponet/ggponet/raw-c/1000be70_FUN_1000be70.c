
uint FUN_1000be70(uint param_1)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  undefined4 *in_EDX;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar2 = in_ECX[1];
  uVar3 = uVar2;
  if (param_1 < uVar2) {
    uVar3 = param_1;
  }
  if (uVar3 == 0) {
    return 0;
  }
  in_ECX[1] = uVar2 - uVar3;
  if (*(int *)(in_ECX[7] + 0x18) == 0) {
    iVar1 = FUN_1000cdd0(uVar3);
    in_ECX[0xc] = iVar1;
  }
  puVar4 = (undefined4 *)*in_ECX;
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *in_EDX = *puVar4;
    puVar4 = puVar4 + 1;
    in_EDX = in_EDX + 1;
  }
  for (uVar2 = uVar3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)in_EDX = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    in_EDX = (undefined4 *)((int)in_EDX + 1);
  }
  in_ECX[2] = in_ECX[2] + uVar3;
  *in_ECX = *in_ECX + uVar3;
  return uVar3;
}
