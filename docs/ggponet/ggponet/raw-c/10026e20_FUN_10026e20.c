
void FUN_10026e20(void *param_1,size_t param_2)

{
  char cVar1;
  int in_ECX;
  size_t local_24;
  void *local_1c;
  undefined4 local_18;
  size_t local_14;
  size_t local_10;
  int *local_c;
  char local_5;
  
  local_5 = '\0';
  cVar1 = FUN_10003e80();
  if (cVar1 == '\0') {
    local_c = (int *)FUN_10003ec0();
    if ((int)(local_c[2] + param_2) < local_c[3]) {
      FUN_10021ff0("Pushing current data to last entry of send queue...(old:%d new:%d offset:%d max:%d)\n"
                   ,local_c[2],local_c[2] + param_2,local_c[1],local_c[3]);
      _memcpy((void *)(*local_c + local_c[2]),param_1,param_2);
      local_c[2] = local_c[2] + param_2;
      local_5 = '\x01';
    }
  }
  if (local_5 == '\0') {
    FUN_10021ff0("Adding new entry to send queue (len:%d)...\n",param_2);
    if ((int)param_2 < 0x4b0) {
      local_24 = 0x4b0;
    }
    else {
      local_24 = param_2;
    }
    local_10 = local_24;
    local_14 = param_2;
    local_18 = 0;
    local_1c = _malloc(local_24);
    _memcpy(local_1c,param_1,param_2);
    FUN_10003ee0(&local_1c);
    if (*(int *)(in_ECX + 0x60) == 0) {
      FUN_10026830();
    }
  }
  return;
}
