
void FUN_10028660(void)

{
  char cVar1;
  int *in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  while( true ) {
    cVar1 = FUN_100230e0(&local_8);
    if (cVar1 == '\0') break;
    (**(code **)(*in_ECX + 0x28))(local_8);
    FUN_100117f8(local_8);
  }
  return;
}
