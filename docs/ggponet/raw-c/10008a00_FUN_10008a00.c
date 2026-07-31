
void FUN_10008a00(uint param_1)

{
  int in_ECX;
  uint uVar1;
  
  uVar1 = param_1 & 0x80000007;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;
  }
  *(byte *)(in_ECX + 8 + ((int)(param_1 + ((int)param_1 >> 0x1f & 7U)) >> 3)) =
       *(byte *)(in_ECX + 8 + ((int)(param_1 + ((int)param_1 >> 0x1f & 7U)) >> 3)) &
       ~(byte)(1 << ((byte)uVar1 & 0x1f));
  return;
}
