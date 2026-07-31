
void FUN_10021340(int *param_1)

{
  char cVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int *piVar4;
  char local_c2c [1028];
  int local_828 [7];
  char local_80c [1024];
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  cVar1 = FUN_10020570();
  if (cVar1 == '\0') {
    _sprintf(local_40c,"Assertion: %s @ %s:%d","ReadyForLocalInput()","..\\source\\prediction.cpp",
             0x43);
    FUN_10021ff0(&DAT_10030e20,local_40c);
    FUN_10021ff0(&DAT_10030e24);
    FUN_10021ff0(&DAT_10030e28);
    FUN_10021ff0(&DAT_10030e2c);
    MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  cVar1 = FUN_1000a890();
  if (cVar1 != '\0') {
    *param_1 = *param_1 + *(int *)(in_ECX + 8);
    if (*param_1 == 0) {
      FUN_10021ff0("Clearing all inputs for first frame in prediction layer.\n");
      FUN_1000a800();
    }
    if (*param_1 < *(int *)(in_ECX + 0xc)) {
      FUN_10021ff0("Tossing new frame %d (before expected frame %d).\n",*param_1,
                   *(undefined4 *)(in_ECX + 0xc));
    }
    if (*(int *)(in_ECX + 0xc) < *param_1) {
      piVar3 = param_1;
      piVar4 = local_828;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      for (local_828[0] = *(int *)(in_ECX + 0xc); local_828[0] < *param_1;
          local_828[0] = local_828[0] + 1) {
        FUN_10021ff0("Padding local input queue with new frame (%d < %d).\n",local_828[0],
                     *(undefined4 *)(in_ECX + 0xc));
        FUN_10002de0(local_828);
        *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
      }
    }
    if (*param_1 == *(int *)(in_ECX + 0xc)) {
      FUN_10022860("Adding new game input to LocalQueue",1);
      FUN_10002de0(param_1);
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    _sprintf(local_c2c,"Assertion: %s @ %s:%d","i.frame == _next_expected_frame",
             "..\\source\\prediction.cpp",0x6b);
    FUN_10021ff0(&DAT_10030fbc,local_c2c);
    FUN_10021ff0(&DAT_10030fc0);
    FUN_10021ff0(&DAT_10030fc4);
    FUN_10021ff0(&DAT_10030fc8);
    MessageBoxA((HWND)0x0,local_c2c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  _sprintf(local_80c,"Assertion: %s @ %s:%d","_sync_game_queue.empty()","..\\source\\prediction.cpp"
           ,0x44);
  FUN_10021ff0(&DAT_10030e98,local_80c);
  FUN_10021ff0(&DAT_10030e9c);
  FUN_10021ff0(&DAT_10030ea0);
  FUN_10021ff0(&DAT_10030ea4);
  MessageBoxA((HWND)0x0,local_80c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
