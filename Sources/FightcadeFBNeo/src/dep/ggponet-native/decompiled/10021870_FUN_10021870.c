
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10021870(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char local_1014 [1024];
  char local_c14 [1024];
  char local_814 [1028];
  char *local_410;
  undefined1 local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_410 = "none";
  cVar1 = FUN_1000a890();
  if (cVar1 == '\0') {
    local_410 = "SyncQueue";
    piVar2 = (int *)FUN_10007af0();
    piVar4 = param_2;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    FUN_100016a0();
  }
  else {
    local_410 = "GameQueue";
    cVar1 = FUN_10003e80();
    if (cVar1 == '\0') {
      _sprintf(local_814,"Assertion: %s @ %s:%d","_game_queue.empty()","..\\source\\prediction.cpp",
               0x11d);
      FUN_10021ff0(&DAT_1003151c,local_814);
      FUN_10021ff0(&DAT_10031520);
      FUN_10021ff0(&DAT_10031524);
      FUN_10021ff0(&DAT_10031528);
      MessageBoxA((HWND)0x0,local_814,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    FUN_10020eb0();
    iVar3 = FUN_10008a70();
    if (iVar3 != 1) {
      _sprintf(local_c14,"Assertion: %s @ %s:%d","_game_queue.size() == 1",
               "..\\source\\prediction.cpp",0x11f);
      FUN_10021ff0(&DAT_10031590,local_c14);
      FUN_10021ff0(&DAT_10031594);
      FUN_10021ff0(&DAT_10031598);
      FUN_10021ff0(&DAT_1003159c);
      MessageBoxA((HWND)0x0,local_c14,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    piVar2 = (int *)FUN_10002dc0();
    piVar4 = param_2;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    FUN_10002e00();
  }
  if (*param_2 == param_1) {
    FUN_100226c0(local_40c,1);
    FUN_10021ff0("Returning input %s from %s to emulator.\n",local_40c,local_410);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_1014,"Assertion: %s @ %s:%d","input.frame == frameNumber",
           "..\\source\\prediction.cpp",0x123);
  FUN_10021ff0(&DAT_10031608,local_1014);
  FUN_10021ff0(&DAT_1003160c);
  FUN_10021ff0(&DAT_10031610);
  FUN_10021ff0(&DAT_10031614);
  MessageBoxA((HWND)0x0,local_1014,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
