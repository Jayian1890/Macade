
void FUN_10028790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = Peer2PeerBackend::vftable;
  in_ECX[1] = Peer2PeerBackend::vftable;
  FUN_10027330();
  FUN_10002940();
  FUN_100203b0();
  FUN_10002900();
  return;
}
