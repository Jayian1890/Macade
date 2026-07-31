
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x10014836) */
/* WARNING: Removing unreachable block (ram,0x100147e3) */
/* WARNING: Removing unreachable block (ram,0x10014863) */
/* Library Function - Single Match
    ___DllMainCRTStartup
   
   Library: Visual Studio 2008 Release */

int ___DllMainCRTStartup(undefined4 param_1)

{
  int iVar1;
  undefined4 in_ECX;
  int in_EDX;
  int local_20;
  
  if (((in_EDX == 0) && (DAT_10038a70 == 0)) ||
     (((in_EDX == 1 || (in_EDX == 2)) && (iVar1 = __CRT_INIT_12(param_1,in_EDX,in_ECX), iVar1 == 0))
     )) {
    local_20 = 0;
  }
  else {
    local_20 = FUN_10021cf0(param_1,in_EDX,in_ECX);
    if ((in_EDX == 1) && (local_20 == 0)) {
      FUN_10021cf0(param_1,0,in_ECX);
      __CRT_INIT_12(param_1,0,in_ECX);
    }
    if (((in_EDX == 0) || (in_EDX == 3)) &&
       (iVar1 = __CRT_INIT_12(param_1,in_EDX,in_ECX), iVar1 == 0)) {
      local_20 = 0;
    }
  }
  return local_20;
}
