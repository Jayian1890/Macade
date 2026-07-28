
/* WARNING: Removing unreachable block (ram,0x10023c25) */

void FUN_100239f0(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  size_t *psVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  size_t *psVar8;
  int *piVar9;
  code *local_c90;
  int local_c8c;
  undefined1 local_c84 [8];
  undefined1 local_c7c [8];
  int local_c74;
  int local_c70;
  undefined1 local_c6c [8];
  undefined1 local_c64 [8];
  char local_c5c [2048];
  char local_45c [1024];
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined1 local_4c [8];
  int local_44 [2];
  undefined1 local_3c [20];
  size_t local_28 [2];
  undefined1 local_20 [20];
  uint local_c;
  undefined4 local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  uVar3 = FUN_100019d0(local_c6c);
  FUN_10007ac0(local_c64);
  cVar1 = FUN_10005670(uVar3);
  if (cVar1 == '\0') {
    local_c74 = FUN_100118ec(0x100c);
    if (local_c74 == 0) {
      local_c8c = 0;
    }
    else {
      local_c8c = FUN_10008950(3);
    }
    local_c70 = local_c8c;
    local_5c = local_c8c;
    local_58 = 0;
    FUN_10007ac0(local_4c);
    local_8 = FUN_10001d00();
    piVar7 = (int *)(in_ECX + 0x1100);
    piVar9 = local_44;
    for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar9 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar9 = piVar9 + 1;
    }
    local_54 = local_5c + 0xc;
    puVar4 = (undefined4 *)FUN_10004d00();
    *(undefined4 *)(local_5c + 1) = *puVar4;
    iVar6 = FUN_10004d00();
    *(undefined1 *)(local_5c + 0xb) = *(undefined1 *)(iVar6 + 4);
    if ((local_44[0] != -1) && (local_44[0] + 1 != *(int *)(local_5c + 1))) {
      _sprintf(local_45c,"Assertion: %s @ %s:%d",
               "last.frame == -1 || last.frame + 1 == msg->u.input.start_frame",
               "..\\source\\network\\udp_proto.cpp",0x6d);
      FUN_10022c50(in_ECX,&DAT_10031d10,local_45c);
      FUN_10022c50(in_ECX,&DAT_10031d14);
      FUN_10022c50(in_ECX,&DAT_10031d18);
      FUN_10022c50(in_ECX,&DAT_10031d1c);
      MessageBoxA((HWND)0x0,local_45c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    while( true ) {
      uVar3 = FUN_100019d0(local_c7c);
      cVar1 = FUN_10004d20(uVar3);
      if (cVar1 == '\0') break;
      psVar5 = (size_t *)FUN_10001d00();
      psVar8 = local_28;
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *psVar8 = *psVar5;
        psVar5 = psVar5 + 1;
        psVar8 = psVar8 + 1;
      }
      iVar6 = _memcmp(local_20,local_3c,local_28[1]);
      if (iVar6 != 0) {
        for (local_50 = 0; local_50 < (int)(local_28[1] * 8); local_50 = local_50 + 1) {
          if (0xff < local_50) {
            _sprintf(local_c5c,"Assertion: %s @ %s:%d","i < (1 << BITVECTOR_NIBBLE_SIZE)",
                     "..\\source\\network\\udp_proto.cpp",0x73);
            FUN_10022c50(in_ECX,&DAT_10031e48,local_c5c);
            FUN_10022c50(in_ECX,&DAT_10031e4c);
            FUN_10022c50(in_ECX,&DAT_10031e50);
            FUN_10022c50(in_ECX,&DAT_10031e54);
            MessageBoxA((HWND)0x0,local_c5c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
            _exit(1);
          }
          cVar1 = FUN_10008970(local_50);
          cVar2 = FUN_10008970(local_50);
          if (cVar1 != cVar2) {
            FUN_100229b0(local_5c + 0xc,&local_58);
            cVar1 = FUN_10008970(local_50);
            if (cVar1 == '\0') {
              local_c90 = FUN_10022950;
            }
            else {
              local_c90 = FUN_100229b0;
            }
            (*local_c90)(local_54,&local_58);
            FUN_10022a60(local_54,local_50,&local_58);
          }
        }
      }
      FUN_10022950(local_5c + 0xc,&local_58);
      psVar5 = local_28;
      psVar8 = (size_t *)(in_ECX + 0x10e4);
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *psVar8 = *psVar5;
        psVar5 = psVar5 + 1;
        psVar8 = psVar8 + 1;
      }
      piVar7 = (int *)(in_ECX + 0x10e4);
      piVar9 = local_44;
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      FUN_10007c00(local_c84,0);
    }
    *(undefined4 *)(local_5c + 5) = *(undefined4 *)(in_ECX + 0x10c8);
    *(undefined2 *)(local_5c + 9) = (undefined2)local_58;
    FUN_10024d60(local_5c);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
