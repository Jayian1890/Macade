
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_100233f0(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 *local_103c;
  char local_102c [1028];
  undefined4 *local_c28;
  undefined1 local_c24 [1024];
  char local_824 [1024];
  int local_424;
  undefined4 local_420;
  char local_41c [1024];
  uint local_1c;
  char local_15;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = 0x100233fd;
  local_1c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x1090) == 0) {
    FUN_10022c50();
  }
  else {
    local_14 = 0;
    local_10 = param_1 + 0xc;
    local_8 = (uint)*(ushort *)(param_1 + 9);
    local_c = *(int *)(param_1 + 1);
    DVar1 = timeGetTime();
    *(DWORD *)(in_ECX + 0x10c4) = DVar1;
    *(uint *)(in_ECX + 0x10cc) = (uint)*(byte *)(param_1 + 0xb);
    if (*(int *)(in_ECX + 0x10c8) < 0) {
      *(int *)(in_ECX + 0x10c8) = *(int *)(param_1 + 1) + -1;
    }
    while (local_14 < (int)local_8) {
      if (*(int *)(in_ECX + 0x10c8) + 1 < local_c) {
        _sprintf(local_41c,"Assertion: %s @ %s:%d",
                 "currentFrame <= (_last_received_input.frame + 1)",
                 "..\\source\\network\\udp_proto.cpp",0x173);
        FUN_10022c50(in_ECX,&DAT_100321c8,local_41c);
        FUN_10022c50(in_ECX,&DAT_100321cc);
        FUN_10022c50(in_ECX,&DAT_100321d0);
        FUN_10022c50(in_ECX,&DAT_100321d4);
        MessageBoxA((HWND)0x0,local_41c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      local_15 = local_c == *(int *)(in_ECX + 0x10c8) + 1;
      while (iVar2 = FUN_100228f0(local_10,&local_14), iVar2 != 0) {
        local_424 = FUN_100228f0(local_10,&local_14);
        local_420 = FUN_10022a10(local_10,&local_14);
        if (local_15 != '\0') {
          if (local_424 == 0) {
            FUN_10008a00(local_420);
          }
          else {
            FUN_100089b0(local_420);
          }
        }
      }
      if ((int)local_8 < local_14) {
        _sprintf(local_824,"Assertion: %s @ %s:%d","offset <= numBits",
                 "..\\source\\network\\udp_proto.cpp",0x181);
        FUN_10022c50(in_ECX,&DAT_1003223c,local_824);
        FUN_10022c50(in_ECX,&DAT_10032240);
        FUN_10022c50(in_ECX,&DAT_10032244);
        FUN_10022c50(in_ECX,&DAT_10032248);
        MessageBoxA((HWND)0x0,local_824,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
        _exit(1);
      }
      if (local_15 == '\0') {
        FUN_10022c50(in_ECX,"Skipping past frame:(%d) current is %d.\n",local_c,
                     *(undefined4 *)(in_ECX + 0x10c8));
      }
      else {
        if (local_c != *(int *)(in_ECX + 0x10c8) + 1) {
          _sprintf(local_102c,"Assertion: %s @ %s:%d",
                   "currentFrame == _last_received_input.frame + 1",
                   "..\\source\\network\\udp_proto.cpp",0x18c);
          FUN_10022c50(in_ECX,&DAT_100322cc,local_102c);
          FUN_10022c50(in_ECX,&DAT_100322d0);
          FUN_10022c50(in_ECX,&DAT_100322d4);
          FUN_10022c50(in_ECX,&DAT_100322d8);
          MessageBoxA((HWND)0x0,local_102c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
          _exit(1);
        }
        *(int *)(in_ECX + 0x10c8) = local_c;
        iVar2 = FUN_100118ec(0x20);
        if (iVar2 == 0) {
          local_103c = (undefined4 *)0x0;
        }
        else {
          local_103c = (undefined4 *)FUN_10003e40(3);
        }
        local_c28 = local_103c;
        puVar4 = (undefined4 *)(in_ECX + 0x10c8);
        for (iVar2 = 7; local_103c = local_103c + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
          *local_103c = *puVar4;
          puVar4 = puVar4 + 1;
        }
        FUN_100226c0(local_c24,1);
        FUN_10022c50(in_ECX,"Sending frame %d to emu (%s).\n",*(undefined4 *)(in_ECX + 0x10c8),
                     local_c24);
        FUN_10023320(local_c28);
      }
      local_c = local_c + 1;
    }
    while ((iVar2 = FUN_10001680(), iVar2 != 0 &&
           (piVar3 = (int *)FUN_10007af0(), *piVar3 < *(int *)(param_1 + 5)))) {
      puVar4 = (undefined4 *)FUN_10007af0();
      FUN_10022c50(in_ECX,"Throwing away pending output frame %d\n",*puVar4);
      puVar4 = (undefined4 *)FUN_10007af0();
      puVar5 = (undefined4 *)(in_ECX + 0x1100);
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      FUN_100016a0();
    }
  }
  __security_check_cookie(local_1c ^ (uint)&stack0xfffffffc);
  return;
}
