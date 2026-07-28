
void FUN_10020940(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined1 local_ce4 [8];
  undefined1 local_cdc [8];
  undefined1 local_cd4 [8];
  undefined1 local_ccc [8];
  undefined1 local_cc4 [8];
  undefined1 local_cbc [8];
  undefined1 local_cb4 [36];
  undefined4 local_c90;
  undefined4 local_c8c;
  undefined4 local_c88;
  undefined4 local_c84;
  undefined4 local_c80;
  int local_c7c;
  undefined4 local_c78;
  undefined4 local_c74;
  undefined4 local_c70;
  int local_c6c;
  undefined4 local_c68;
  undefined4 local_c64;
  char local_c60 [1028];
  int local_85c [7];
  int *local_840;
  undefined4 local_83c;
  undefined4 local_838;
  int local_834;
  undefined4 local_830;
  undefined4 local_82c;
  char local_828 [1024];
  char local_428 [1028];
  uint local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [8];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d614;
  local_10 = ExceptionList;
  local_24 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_20 = 0;
  cVar1 = FUN_10003e80(local_24);
  if (cVar1 != '\0') {
    _sprintf(local_428,"Assertion: %s @ %s:%d","!_remote_queue.empty()","..\\source\\prediction.cpp"
             ,0xdf);
    FUN_10021ff0(&DAT_1003134c,local_428);
    FUN_10021ff0(&DAT_10031350);
    FUN_10021ff0(&DAT_10031354);
    FUN_10021ff0(&DAT_10031358);
    MessageBoxA((HWND)0x0,local_428,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  cVar1 = FUN_1000a890();
  if (cVar1 != '\0') {
    uVar2 = FUN_100015e0();
    local_8 = 0;
    FUN_1000a840(uVar2);
    local_8 = 0xffffffff;
    FUN_10001660();
    local_834 = in_ECX + 0x70;
    puVar3 = (undefined4 *)FUN_100019d0(local_cb4);
    local_830 = *puVar3;
    local_82c = puVar3[1];
    puVar3 = (undefined4 *)FUN_10007ac0(local_cbc);
    local_83c = *puVar3;
    local_838 = puVar3[1];
    while( true ) {
      cVar1 = FUN_10004d20(&local_830);
      if (cVar1 == '\0') {
        FUN_10021ff0("Requeuing %d.\n",param_1);
        local_c6c = in_ECX + 0x8c;
        puVar3 = (undefined4 *)FUN_100019d0(local_cc4);
        local_c68 = *puVar3;
        local_c64 = puVar3[1];
        puVar3 = (undefined4 *)FUN_10007ac0(local_ccc);
        local_c74 = *puVar3;
        local_c70 = puVar3[1];
        while (cVar1 = FUN_10004d20(&local_c68), cVar1 != '\0') {
          local_c78 = FUN_10002170();
          FUN_10022860("   frame ",1);
          FUN_10008630();
        }
        FUN_10007ac0(local_18);
        for (local_1c = 0; local_1c < local_20; local_1c = local_1c + 1) {
          FUN_10007c00(local_cd4,0);
          uVar2 = FUN_10001d00();
          FUN_100206b0(uVar2);
          FUN_100016a0();
        }
        FUN_10021ff0("Predict queue is now:\n");
        local_c7c = in_ECX + 0x70;
        puVar3 = (undefined4 *)FUN_100019d0(local_cdc);
        local_c84 = *puVar3;
        local_c80 = puVar3[1];
        puVar3 = (undefined4 *)FUN_10007ac0(local_ce4);
        local_c8c = *puVar3;
        local_c88 = puVar3[1];
        while (cVar1 = FUN_10004d20(&local_c84), cVar1 != '\0') {
          local_c90 = FUN_10002170();
          FUN_10022860("   frame ",1);
          FUN_10008630();
        }
        ExceptionList = local_10;
        __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
        return;
      }
      local_840 = (int *)FUN_10002170();
      cVar1 = FUN_10003e80();
      if (cVar1 == '\0') {
        puVar3 = (undefined4 *)FUN_10002dc0();
        puVar6 = (undefined4 *)(in_ECX + 0xa8);
        for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar6 = puVar6 + 1;
        }
        FUN_10002e00();
        local_20 = local_20 + 1;
      }
      if (*local_840 < *(int *)(in_ECX + 0xa8)) break;
      piVar5 = local_840;
      piVar7 = local_85c;
      for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar7 = piVar7 + 1;
      }
      FUN_100221f0(in_ECX + 0xa8);
      FUN_100016e0(local_85c);
      FUN_10008630();
    }
    _sprintf(local_c60,"Assertion: %s @ %s:%d","_last_remote_input.frame <= predict.frame",
             "..\\source\\prediction.cpp",0xed);
    FUN_10021ff0(&DAT_1003144c,local_c60);
    FUN_10021ff0(&DAT_10031450);
    FUN_10021ff0(&DAT_10031454);
    FUN_10021ff0(&DAT_10031458);
    MessageBoxA((HWND)0x0,local_c60,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  _sprintf(local_828,"Assertion: %s @ %s:%d","_sync_game_queue.empty()","..\\source\\prediction.cpp"
           ,0xe0);
  FUN_10021ff0(&DAT_100313c4,local_828);
  FUN_10021ff0(&DAT_100313c8);
  FUN_10021ff0(&DAT_100313cc);
  FUN_10021ff0(&DAT_100313d0);
  MessageBoxA((HWND)0x0,local_828,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
