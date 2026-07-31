
void FUN_10022950(int param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = *param_2 & 0x80000007;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffff8) + 1;
  }
  *(byte *)(param_1 + ((int)(*param_2 + ((int)*param_2 >> 0x1f & 7U)) >> 3)) =
       *(byte *)(param_1 + ((int)(*param_2 + ((int)*param_2 >> 0x1f & 7U)) >> 3)) &
       ~(byte)(1 << ((byte)uVar1 & 0x1f));
  *param_2 = *param_2 + 1;
  return;
}
