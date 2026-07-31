
void FUN_10021660(int *param_1,undefined4 *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  char local_814 [1024];
  char local_414 [1028];
  uint local_10;
  undefined1 local_9;
  int local_8;
  
  local_10 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_9 = 0;
  cVar1 = FUN_1000a890();
  if (cVar1 == '\0') {
    _sprintf(local_414,"Assertion: %s @ %s:%d","_sync_game_queue.empty()",
             "..\\source\\prediction.cpp",0x20);
    FUN_10021ff0(&DAT_10030d20,local_414);
    FUN_10021ff0(&DAT_10030d24);
    FUN_10021ff0(&DAT_10030d28);
    FUN_10021ff0(&DAT_10030d2c);
    MessageBoxA((HWND)0x0,local_414,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  uVar2 = FUN_10008a70();
  *(undefined4 *)(in_ECX + 0xe8) = uVar2;
  uVar2 = FUN_10001680();
  *(undefined4 *)(in_ECX + 0xe4) = uVar2;
  cVar1 = FUN_10020700(&local_8);
  if (cVar1 != '\0') {
    *param_1 = 0;
  }
  else {
    FUN_10020940(local_8);
    *param_1 = local_8 + -1;
    uVar2 = FUN_10001680();
    *param_2 = uVar2;
  }
  local_9 = cVar1 != '\0';
  cVar1 = FUN_1000a890();
  if ((cVar1 == '\0') && (cVar1 = FUN_10003e80(), cVar1 == '\0')) {
    _sprintf(local_814,"Assertion: %s @ %s:%d","_predict_queue.empty() || _remote_queue.empty()",
             "..\\source\\prediction.cpp",0x30);
    FUN_10021ff0(&DAT_10030dac,local_814);
    FUN_10021ff0(&DAT_10030db0);
    FUN_10021ff0(&DAT_10030db4);
    FUN_10021ff0(&DAT_10030db8);
    MessageBoxA((HWND)0x0,local_814,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  __security_check_cookie(local_10 ^ (uint)&stack0xfffffffc);
  return;
}
