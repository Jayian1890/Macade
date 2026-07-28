
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    private: static void __cdecl type_info::_Type_info_dtor(class type_info *)
   
   Libraries: Visual Studio 2005 Release, Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl type_info::_Type_info_dtor(type_info *param_1)

{
  int *_Memory;
  int *piVar1;
  int *piVar2;
  
  __lock(0xe);
  _Memory = DAT_10039238;
  if (*(int *)(param_1 + 4) != 0) {
    piVar1 = (int *)&DAT_10039234;
    do {
      piVar2 = piVar1;
      if (DAT_10039238 == (int *)0x0) goto LAB_10017844;
      piVar1 = DAT_10039238;
    } while (*DAT_10039238 != *(int *)(param_1 + 4));
    piVar2[1] = DAT_10039238[1];
    _free(_Memory);
LAB_10017844:
    _free(*(void **)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0;
  }
  FUN_10017867();
  return;
}
