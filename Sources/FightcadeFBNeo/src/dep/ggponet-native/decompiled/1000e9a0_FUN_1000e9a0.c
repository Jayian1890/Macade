
void FUN_1000e9a0(int param_1,int param_2)

{
  byte bVar1;
  int in_ECX;
  undefined1 *in_EDX;
  int iVar2;
  
  FUN_1000e920();
  *(undefined4 *)(in_ECX + 0x16ac) = 8;
  if (param_2 != 0) {
    *(byte *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) = (byte)param_1;
    iVar2 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar2;
    bVar1 = (byte)((uint)param_1 >> 8);
    *(byte *)(iVar2 + *(int *)(in_ECX + 8)) = bVar1;
    iVar2 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar2;
    *(byte *)(iVar2 + *(int *)(in_ECX + 8)) = ~(byte)param_1;
    iVar2 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar2;
    *(byte *)(*(int *)(in_ECX + 8) + iVar2) = ~bVar1;
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  }
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *(undefined1 *)(*(int *)(in_ECX + 0x14) + *(int *)(in_ECX + 8)) = *in_EDX;
    in_EDX = in_EDX + 1;
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  }
  return;
}
