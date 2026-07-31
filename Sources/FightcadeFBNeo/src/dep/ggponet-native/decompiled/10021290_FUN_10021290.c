
void FUN_10021290(int *param_1)

{
  char cVar1;
  int in_ECX;
  int local_24;
  int local_20;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xa8) < 0) {
    cVar1 = FUN_10003e80();
    if (cVar1 != '\0') {
      local_20 = param_1[1];
      FUN_1000a800();
      for (local_24 = 0; local_24 < *param_1; local_24 = local_24 + 1) {
        FUN_10021ff0("Workaround: Adding generated input to front of remote queue (%d).\n",local_24)
        ;
        FUN_10002de0(&local_24);
      }
    }
  }
  FUN_10022860("Adding input to RemoteQueue",1);
  FUN_10002de0(param_1);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
