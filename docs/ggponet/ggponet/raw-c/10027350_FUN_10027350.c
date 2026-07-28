
undefined4 * FUN_10027350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = TimeSync::vftable;
  _memset(in_ECX + 1,0,0xa0);
  _memset(in_ECX + 0x29,0,0xa0);
  in_ECX[0x97] = 0x78;
  return in_ECX;
}
