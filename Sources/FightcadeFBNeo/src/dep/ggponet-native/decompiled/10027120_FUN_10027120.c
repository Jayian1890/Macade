
int FUN_10027120(void)

{
  float fVar1;
  char cVar2;
  int in_ECX;
  int local_20;
  int local_18;
  uint local_10;
  
  local_18 = 0;
  for (local_10 = 0; local_10 < 0x28; local_10 = local_10 + 1) {
    local_18 = local_18 + *(int *)(in_ECX + 4 + local_10 * 4);
  }
  fVar1 = (float)local_18;
  local_18 = 0;
  for (local_10 = 0; local_10 < 0x28; local_10 = local_10 + 1) {
    local_18 = local_18 + *(int *)(in_ECX + 0xa4 + local_10 * 4);
  }
  DAT_100394e4 = DAT_100394e4 + 1;
  if ((float)local_18 / 40.0 < fVar1 / 40.0 == ((float)local_18 / 40.0 == fVar1 / 40.0)) {
    local_20 = FUN_1002a080();
    FUN_10021ff0("iteration %d:  sleep frames is %d\n",DAT_100394e4,local_20);
    if (local_20 < 3) {
      local_20 = 0;
    }
    else {
      for (local_10 = 1; local_10 < 10; local_10 = local_10 + 1) {
        cVar2 = FUN_10022020(in_ECX + 0x144,1);
        if (cVar2 == '\0') {
          FUN_10021ff0("iteration %d:  rejecting due to input stuff at position %d...!!!\n",
                       DAT_100394e4,local_10);
          return 0;
        }
      }
      if (8 < local_20) {
        local_20 = 9;
      }
    }
  }
  else {
    local_20 = 0;
  }
  return local_20;
}
