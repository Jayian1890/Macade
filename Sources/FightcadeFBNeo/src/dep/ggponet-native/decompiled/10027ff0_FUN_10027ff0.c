
int FUN_10027ff0(int param_1)

{
  int *piVar1;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_c = -1;
  local_8 = FUN_10008eb0();
  if (local_8 != 0) {
    for (local_10 = 0; local_10 < local_8; local_10 = local_10 + 1) {
      local_18 = FUN_10008ed0(local_10);
      local_14 = (*(int *)(local_18 + 8) + *(int *)(local_18 + 0xc)) - param_1;
      if ((local_c == -1) || (local_14 < local_c)) {
        local_1c = 0;
        piVar1 = std::_Min_value<int>(&local_14,&local_1c);
        local_c = *piVar1;
      }
    }
  }
  return local_c;
}
