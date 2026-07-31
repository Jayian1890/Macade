
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __freefls@4
   
   Library: Visual Studio 2008 Release */

void __freefls_4(void *param_1)

{
  LONG *lpAddend;
  int *piVar1;
  LONG LVar2;
  
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 0x24) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x24));
    }
    if (*(void **)((int)param_1 + 0x2c) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x2c));
    }
    if (*(void **)((int)param_1 + 0x34) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x34));
    }
    if (*(void **)((int)param_1 + 0x3c) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x3c));
    }
    if (*(void **)((int)param_1 + 0x40) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x40));
    }
    if (*(void **)((int)param_1 + 0x44) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x44));
    }
    if (*(void **)((int)param_1 + 0x48) != (void *)0x0) {
      _free(*(void **)((int)param_1 + 0x48));
    }
    if (*(undefined **)((int)param_1 + 0x5c) != &DAT_1002f750) {
      _free(*(undefined **)((int)param_1 + 0x5c));
    }
    __lock(0xd);
    lpAddend = *(LONG **)((int)param_1 + 0x68);
    if (lpAddend != (LONG *)0x0) {
      LVar2 = InterlockedDecrement(lpAddend);
      if ((LVar2 == 0) && (lpAddend != (LONG *)&DAT_10037c20)) {
        _free(lpAddend);
      }
    }
    FUN_1001750a();
    __lock(0xc);
    piVar1 = *(int **)((int)param_1 + 0x6c);
    if (piVar1 != (int *)0x0) {
      ___removelocaleref(piVar1);
      if (((piVar1 != (int *)PTR_DAT_10038228) && (piVar1 != (int *)&DAT_10038150)) &&
         (*piVar1 == 0)) {
        ___freetlocinfo(piVar1);
      }
    }
    FUN_10017516();
    _free(param_1);
  }
  return;
}
