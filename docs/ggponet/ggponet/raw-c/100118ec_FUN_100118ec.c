
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100118ec(size_t param_1)

{
  int iVar1;
  void *pvVar2;
  undefined1 local_10 [12];
  
  do {
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) {
      return;
    }
    iVar1 = __callnewh(param_1);
  } while (iVar1 != 0);
  if ((_DAT_10038a34 & 1) == 0) {
    _DAT_10038a34 = _DAT_10038a34 | 1;
    std::bad_alloc::bad_alloc((bad_alloc *)&DAT_10038a28);
    _atexit((_func_4879 *)&LAB_1002d9ab);
  }
  FUN_10002770(&DAT_10038a28);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_10,&DAT_10034374);
}
