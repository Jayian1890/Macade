
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x0077c383) */
/* Library Function - Single Match
    ___tmainCRTStartup
   
   Library: Visual Studio 2008 Release */

int ___tmainCRTStartup(void)

{
  int iVar1;
  undefined4 uVar2;
  _STARTUPINFOA local_6c;
  int local_24;
  int local_20;
  undefined4 uStack_c;
  undefined4 local_8;
  
  uStack_c = 0x77c328;
  local_8 = 0;
  GetStartupInfoA(&local_6c);
  local_8 = 0xfffffffe;
  local_20 = 0;
  iVar1 = __heap_init();
  if (iVar1 == 0) {
    fast_error_exit(0x1c);
  }
  iVar1 = __mtinit();
  if (iVar1 == 0) {
    fast_error_exit(0x10);
  }
  __RTC_Initialize();
  local_8 = 1;
  iVar1 = __ioinit();
  if (iVar1 < 0) {
    __amsg_exit(0x1b);
  }
  DAT_00b1d010 = GetCommandLineA();
  DAT_009aa818 = ___crtGetEnvironmentStringsA();
  iVar1 = __setargv();
  if (iVar1 < 0) {
    __amsg_exit(8);
  }
  iVar1 = __setenvp();
  if (iVar1 < 0) {
    __amsg_exit(9);
  }
  iVar1 = __cinit(1);
  if (iVar1 != 0) {
    __amsg_exit(iVar1);
  }
  uVar2 = __wincmdln();
  if (((byte)local_6c.dwFlags & 1) == 0) {
    local_6c.wShowWindow = 10;
  }
  local_24 = FUN_00457270(0x400000,0,uVar2,local_6c.wShowWindow);
  if (local_20 != 0) {
    __cexit();
    return local_24;
  }
                    /* WARNING: Subroutine does not return */
  _exit(local_24);
}
