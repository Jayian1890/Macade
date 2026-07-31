
void FUN_10028330(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  char local_40c [1028];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 4) < 0x3f) {
    *(undefined4 *)(in_ECX + 8 + *(int *)(in_ECX + 4) * 4) = param_2;
    puVar3 = (undefined4 *)FUN_100079f0(param_1,param_3);
    uVar1 = puVar3[1];
    iVar2 = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 0x108 + iVar2 * 8) = *puVar3;
    *(undefined4 *)(in_ECX + 0x10c + iVar2 * 8) = uVar1;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  _sprintf(local_40c,"Assertion: %s @ %s:%d","_handle_count < MAX_POLLABLE_HANDLES - 1",
           "..\\source\\poll.cpp",0x15);
  FUN_10021ff0(&DAT_100316c4,local_40c);
  FUN_10021ff0(&DAT_100316c8);
  FUN_10021ff0(&DAT_100316cc);
  FUN_10021ff0(&DAT_100316d0);
  MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
  _exit(1);
}
