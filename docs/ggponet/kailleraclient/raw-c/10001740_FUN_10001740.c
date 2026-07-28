
void __fastcall FUN_10001740(int *param_1)

{
  void *_Memory;
  int iVar1;
  int iVar2;
  
  FUN_10001640(param_1);
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  if (param_1[1] != 0) {
    iVar1 = 0;
    if (0 < param_1[4]) {
      iVar2 = 0;
      do {
        _Memory = *(void **)(param_1[1] + 0x10 + iVar2);
        if (_Memory != (void *)0x0) {
          free(_Memory);
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x18;
      } while (iVar1 < param_1[4]);
    }
    free((void *)param_1[1]);
  }
  return;
}
