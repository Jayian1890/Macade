
void __cdecl FUN_10008e90(char *param_1)

{
  int iVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_bc [44];
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = DAT_1000e4f4;
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_1000ccc6;
  *unaff_FS_OFFSET = &local_c;
  if (iVar1 != -1) {
    FUN_10001c40(local_bc);
    local_4 = 0;
    local_bc[0] = 8;
    FUN_10001e30(local_bc,param_1);
    local_4 = 1;
    FUN_100010d0();
    local_4 = 0xffffffff;
    FUN_10001c70((int)local_bc);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}
