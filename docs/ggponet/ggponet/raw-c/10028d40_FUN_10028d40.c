
void FUN_10028d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = SpectatorBackend::vftable;
  in_ECX[1] = SpectatorBackend::vftable;
  FUN_10002d80();
  FUN_10002900();
  FUN_10026160();
  return;
}
