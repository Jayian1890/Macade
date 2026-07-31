
/* WARNING: Removing unreachable block (ram,0x100265c7) */
/* WARNING: Removing unreachable block (ram,0x1002673b) */

void FUN_100264e0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int local_824;
  char local_81c [1024];
  char local_41c [1024];
  int local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 uStack_14;
  undefined2 local_12;
  undefined2 uStack_10;
  undefined4 local_e;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_18 = 0;
  local_16 = 0;
  uStack_14 = 0;
  local_12 = 0;
  uStack_10 = 0;
  local_e = 0;
  local_a = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  uVar1 = Ordinal_23(2,1,0);
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  if (*(int *)(in_ECX + 0x14) == -1) {
    _sprintf(local_41c,"Assertion: %s @ %s:%d","false","..\\source\\network\\tcp.cpp",0xd4);
    FUN_10021ff0(&DAT_10032b5c,local_41c);
    FUN_10021ff0(&DAT_10032b60);
    FUN_10021ff0(&DAT_10032b64);
    FUN_10021ff0(&DAT_10032b68);
    MessageBoxA((HWND)0x0,local_41c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  local_18 = 2;
  uVar1 = Ordinal_8(0);
  uStack_14 = (undefined2)uVar1;
  local_12 = (undefined2)((uint)uVar1 >> 0x10);
  local_1c = 0;
  do {
    if (param_2 < local_1c) {
LAB_1002668b:
      if (local_1c <= param_2) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      Ordinal_3(*(undefined4 *)(in_ECX + 0x14));
      *(undefined4 *)(in_ECX + 0x14) = 0xffffffff;
      _sprintf(local_81c,"Assertion: %s @ %s:%d","false","..\\source\\network\\tcp.cpp",0xe9);
      FUN_10021ff0(&DAT_10032c00,local_81c);
      FUN_10021ff0(&DAT_10032c04);
      FUN_10021ff0(&DAT_10032c08);
      FUN_10021ff0(&DAT_10032c0c);
      MessageBoxA((HWND)0x0,local_81c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    if (param_1 != 0) {
      local_16 = Ordinal_9(param_1 + local_1c);
    }
    iVar2 = Ordinal_2(*(undefined4 *)(in_ECX + 0x14),&local_18,0x10);
    if (iVar2 != -1) {
      if (param_1 == 0) {
        local_824 = 0;
      }
      else {
        local_824 = param_1 + local_1c;
      }
      *(int *)(in_ECX + 0x18) = local_824;
      FUN_10021ff0("GGPOSession version 0.9 (fix short)\n");
      FUN_10021ff0("Tcp bound to port: %d.\n",*(undefined4 *)(in_ECX + 0x18));
      goto LAB_1002668b;
    }
    local_1c = local_1c + 1;
  } while( true );
}
