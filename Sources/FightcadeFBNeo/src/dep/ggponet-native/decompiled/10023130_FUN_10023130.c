
undefined4 * FUN_10023130(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d508;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_100028e0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  FUN_10008a50();
  *in_ECX = UdpProtocol::vftable;
  in_ECX[1] = UdpProtocol::vftable;
  FUN_10024aa0();
  local_8 = 0;
  in_ECX[0x428] = 0;
  in_ECX[0x429] = 0;
  FUN_100015e0();
  local_8 = CONCAT31(local_8._1_3_,1);
  in_ECX[0x431] = 0;
  in_ECX[0x44e] = 0;
  FUN_10002da0();
  pcVar1 = _getenv("ggpo.idle.framecount");
  if (pcVar1 == (char *)0x0) {
LAB_10023241:
    in_ECX[0x44f] = DAT_10038530;
  }
  else {
    iVar2 = FUN_10011a64(pcVar1);
    if (iVar2 == 0) goto LAB_10023241;
    iVar2 = FUN_10011a64(pcVar1);
    if (iVar2 < 0xb) {
      local_1c = FUN_10011a64(pcVar1);
    }
    else {
      local_1c = 10;
    }
    in_ECX[0x44f] = local_1c;
  }
  pcVar1 = _getenv("ggpo.idle.frameboost");
  if (pcVar1 != (char *)0x0) {
    iVar2 = FUN_10011a64(pcVar1);
    if (iVar2 != 0) {
      uVar3 = FUN_10011a64(pcVar1);
      in_ECX[0x450] = uVar3;
      goto LAB_1002329a;
    }
  }
  in_ECX[0x450] = DAT_10038534;
LAB_1002329a:
  FUN_10022310(0xffffffff,0,1);
  FUN_10022310(0xffffffff,0,1);
  FUN_10022310(0xffffffff,0,1);
  FUN_10022310(0xffffffff,0,1);
  _memset(in_ECX + 0x425,0,0xc);
  ExceptionList = local_10;
  return in_ECX;
}
