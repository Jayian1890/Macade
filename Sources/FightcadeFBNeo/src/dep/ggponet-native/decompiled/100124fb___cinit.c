
/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2008 Release */

int __cdecl __cinit(int param_1)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR___fpmath_10033470);
  if (BVar1 != 0) {
    __fpmath(param_1);
  }
  __initp_misc_cfltcvt_tab();
  iVar2 = __initterm_e(&DAT_1002e1b0,&DAT_1002e1c4);
  if (iVar2 == 0) {
    _atexit((_func_4879 *)&LAB_1001930b);
    __initterm(&DAT_1002e1ac);
    if ((DAT_1343a69c != (code *)0x0) &&
       (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_1343a69c), BVar1 != 0)) {
      (*DAT_1343a69c)(0,2,0);
    }
    iVar2 = 0;
  }
  return iVar2;
}
