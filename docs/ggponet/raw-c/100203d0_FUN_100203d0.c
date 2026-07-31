
undefined4 * FUN_100203d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = Sync::vftable;
  FUN_100208a0();
  in_ECX[0x43] = 0;
  _memset(in_ECX + 0x44,0,0x164);
  return in_ECX;
}
