
void FUN_100246e0(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int in_ECX;
  undefined4 local_10;
  
  pcVar1 = _getenv("ggpo.network.delay");
  if (pcVar1 == (char *)0x0) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_10011a64(pcVar1);
  }
  *(undefined4 *)(in_ECX + 0x1038) = local_10;
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined4 *)(in_ECX + 0x30) = param_2;
  FUN_100245b0(10);
  return;
}
