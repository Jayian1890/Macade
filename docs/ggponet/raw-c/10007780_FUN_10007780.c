
void FUN_10007780(uint param_1)

{
  bad_alloc local_10 [12];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if ((uint)(0xffffffff / (ulonglong)param_1) < 0x18) {
    std::bad_alloc::bad_alloc(local_10,(char *)0x0);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_10034374);
  }
  FUN_100118ec(param_1 * 0x18);
  return;
}
