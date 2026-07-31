
undefined4 * FUN_100252c0(void)

{
  int iVar1;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  iVar1 = FUN_10008a70();
  if (iVar1 != 0) {
    local_8 = (undefined4 *)FUN_10004aa0();
    local_8 = (undefined4 *)*local_8;
    FUN_10008a90();
    FUN_10021ff0("TcpProtocol returning event of type %d.\n",*local_8);
  }
  return local_8;
}
