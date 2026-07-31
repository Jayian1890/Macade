
void FUN_10008240(uint param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 local_54 [28];
  undefined1 local_38 [40];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d968;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_100086f0(DAT_10037490 ^ (uint)&stack0xfffffffc);
  if ((uint)(iVar1 - *(int *)(in_ECX + 0x18)) < param_1) {
    basic_string<>("list<T> too long");
    local_8 = 0;
    FID_conflict_length_error(local_54);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_38,&DAT_1003433c);
  }
  *(uint *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + param_1;
  ExceptionList = local_10;
  return;
}
