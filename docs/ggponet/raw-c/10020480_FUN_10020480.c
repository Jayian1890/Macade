
bool FUN_10020480(undefined4 *param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_10020570();
  if (cVar1 != '\0') {
    *param_1 = *(undefined4 *)(in_ECX + 0x10c);
    FUN_10021ff0("SyncInput: Sending frame %d to synchronization layer.\n",*param_1);
    FUN_10021340(param_1);
  }
  else {
    FUN_10021ff0("Rejecting input from emualtor: reached prediction barrier.\n");
  }
  return cVar1 != '\0';
}
