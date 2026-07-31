
void FUN_100045c0(void)

{
  undefined1 local_54 [28];
  undefined1 local_38 [40];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d938;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  basic_string<>("deque<T> too long");
  local_8 = 0;
  FID_conflict_length_error(local_54);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_38,&DAT_1003433c);
}
