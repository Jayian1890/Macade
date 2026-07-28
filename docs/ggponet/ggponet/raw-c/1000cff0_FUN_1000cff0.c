
void FUN_1000cff0(undefined4 param_1,int param_2)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 0x16b4);
  if (0xd < iVar1) {
    *(ushort *)(in_ECX + 0x16b0) =
         *(ushort *)(in_ECX + 0x16b0) | (ushort)(param_2 << ((byte)iVar1 & 0x1f));
    *(undefined1 *)(*(int *)(in_ECX + 8) + *(int *)(in_ECX + 0x14)) =
         *(undefined1 *)(in_ECX + 0x16b0);
    iVar1 = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x14) = iVar1;
    *(undefined1 *)(*(int *)(in_ECX + 8) + iVar1) = *(undefined1 *)(in_ECX + 0x16b1);
    iVar1 = *(int *)(in_ECX + 0x16b4);
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    *(int *)(in_ECX + 0x16b4) = iVar1 + -0xd;
    *(ushort *)(in_ECX + 0x16b0) = (ushort)param_2 >> (0x10U - (char)iVar1 & 0x1f);
    FUN_1000e9a0(param_1,1);
    return;
  }
  *(int *)(in_ECX + 0x16b4) = iVar1 + 3;
  *(ushort *)(in_ECX + 0x16b0) =
       *(ushort *)(in_ECX + 0x16b0) | (ushort)(param_2 << ((byte)iVar1 & 0x1f));
  FUN_1000e9a0(param_1,1);
  return;
}
