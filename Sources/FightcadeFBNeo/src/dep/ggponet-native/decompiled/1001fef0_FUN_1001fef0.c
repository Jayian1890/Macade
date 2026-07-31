
void FUN_1001fef0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  char local_40c [1024];
  uint local_c;
  int *local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (param_1 == *(int *)(in_ECX + 0x10c)) {
    FUN_10021ff0("Skipping NOP.\n");
  }
  else {
    uVar1 = FUN_1001fd20(param_1);
    *(undefined4 *)(in_ECX + 0x270) = uVar1;
    local_8 = (int *)(in_ECX + 0x110 + *(int *)(in_ECX + 0x270) * 0x10);
    FUN_10021ff0("=== Loading frame info %d (size: %d  checksum: %08x).\n",local_8[2],local_8[1],
                 local_8[3]);
    if ((*local_8 == 0) || (local_8[1] == 0)) {
      _sprintf(local_40c,"Assertion: %s @ %s:%d","state->buf && state->cbuf","..\\source\\sync.cpp",
               0x79);
      FUN_10021ff0(&DAT_10030c04,local_40c);
      FUN_10021ff0(&DAT_10030c08);
      FUN_10021ff0(&DAT_10030c0c);
      FUN_10021ff0(&DAT_10030c10);
      MessageBoxA((HWND)0x0,local_40c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    (**(code **)(in_ECX + 0xc))(*local_8,local_8[1]);
    *(int *)(in_ECX + 0x10c) = local_8[2] + 1;
    *(uint *)(in_ECX + 0x270) = (*(int *)(in_ECX + 0x270) + 1U) % 0x16;
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
