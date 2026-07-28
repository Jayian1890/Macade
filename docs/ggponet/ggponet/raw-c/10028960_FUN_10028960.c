
void FUN_10028960(undefined4 *param_1)

{
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  switch(*param_1) {
  case 0:
    local_10 = 1000;
    (**(code **)(in_ECX + 0x20))(&local_10);
    break;
  case 1:
    local_10 = 0x3e9;
    local_c = param_1[2];
    local_8 = param_1[1];
    (**(code **)(in_ECX + 0x20))(&local_10);
    break;
  case 2:
    local_10 = 0x3ea;
    (**(code **)(in_ECX + 0x20))(&local_10);
    *(undefined1 *)(in_ECX + 0x19c9) = 0;
    break;
  case 3:
    FUN_10020460(param_1 + 1);
    break;
  case 4:
    local_10 = 0x3eb;
    (**(code **)(in_ECX + 0x20))(&local_10);
  }
  return;
}
