
bool FUN_100228f0(int param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + ((int)(*param_2 + ((int)*param_2 >> 0x1f & 7U)) >> 3));
  uVar2 = *param_2 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  *param_2 = *param_2 + 1;
  return ((uint)bVar1 & 1 << ((byte)uVar2 & 0x1f)) != 0;
}
