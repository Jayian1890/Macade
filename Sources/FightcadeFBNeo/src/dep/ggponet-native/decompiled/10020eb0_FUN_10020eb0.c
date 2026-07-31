
void FUN_10020eb0(void)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  char local_c2c [1024];
  char local_82c [1024];
  char local_42c [1028];
  int local_28 [7];
  uint local_c;
  char local_5;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  uVar2 = FUN_10001680();
  uVar2 = FUN_10008a70(uVar2);
  uVar2 = FUN_10008a70(uVar2);
  FUN_10021ff0("MovePredictionForward (l:%d r:%d p:%d)\n",uVar2);
  cVar1 = FUN_10003e80();
  if ((cVar1 == '\0') && (uVar3 = FUN_10001680(), uVar3 < *(uint *)(in_ECX + 4))) {
    piVar4 = (int *)FUN_10002dc0();
    piVar7 = local_28;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar7 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar7 = piVar7 + 1;
    }
    FUN_10002e00();
    local_5 = FUN_10003e80();
    if (local_5 == '\0') {
      puVar5 = (undefined4 *)FUN_10002dc0();
      puVar8 = (undefined4 *)(in_ECX + 0xa8);
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      FUN_10002e00();
      cVar1 = FUN_1000a890();
      if (cVar1 == '\0') {
        _sprintf(local_42c,"Assertion: %s @ %s:%d","_predict_queue.empty()",
                 "..\\source\\prediction.cpp",0x97);
        FUN_10021ff0(&DAT_100310dc,local_42c);
        FUN_10021ff0(&DAT_100310e0);
        FUN_10021ff0(&DAT_100310e4);
        FUN_10021ff0(&DAT_100310e8);
        MessageBoxA((HWND)0x0,local_42c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      if (*(int *)(in_ECX + 0xa8) != local_28[0]) {
        _sprintf(local_82c,"Assertion: %s @ %s:%d","_last_remote_input.frame == local.frame",
                 "..\\source\\prediction.cpp",0x98);
        FUN_10021ff0(&DAT_10031160,local_82c);
        FUN_10021ff0(&DAT_10031164);
        FUN_10021ff0(&DAT_10031168);
        FUN_10021ff0(&DAT_1003116c);
        MessageBoxA((HWND)0x0,local_82c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
    }
    else {
      FUN_100016e0(local_28);
    }
    if (local_28[0] < *(int *)(in_ECX + 0xa8)) {
      _sprintf(local_c2c,"Assertion: %s @ %s:%d","_last_remote_input.frame <= local.frame",
               "..\\source\\prediction.cpp",0xa4);
      FUN_10021ff0(&DAT_100311e4,local_c2c);
      FUN_10021ff0(&DAT_100311e8);
      FUN_10021ff0(&DAT_100311ec);
      FUN_10021ff0(&DAT_100311f0);
      MessageBoxA((HWND)0x0,local_c2c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    FUN_100221f0(in_ECX + 0xa8);
    if (local_5 == '\0') {
      FUN_10022860("Adding confirmed frame to GameQueue",1);
    }
    else {
      FUN_10022860("Adding latency frame to GameQueue",1);
    }
    FUN_10002de0(local_28);
    if (local_5 == '\0') {
      FUN_100206b0(local_28);
    }
  }
  cVar1 = FUN_1000a890();
  if ((cVar1 == '\0') && (cVar1 = FUN_10003e80(), cVar1 == '\0')) {
    FUN_10021ff0("LOGICIAL ERROR!!!  Queues not empty:\n");
    uVar2 = FUN_10008a70();
    FUN_10021ff0("   Local Queue  : %d.\n",uVar2);
    uVar2 = FUN_10008a70();
    FUN_10021ff0("   Remote Queue : %d.\n",uVar2);
    uVar2 = FUN_10001680();
    FUN_10021ff0("   Predict Queue: %d.\n",uVar2);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
