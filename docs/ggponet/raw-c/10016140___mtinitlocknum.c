
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __mtinitlocknum
   
   Library: Visual Studio 2008 Release */

int __cdecl __mtinitlocknum(int _LockNum)

{
  void *_Memory;
  int *piVar1;
  int iVar2;
  int local_20;
  
  iVar2 = 1;
  local_20 = 1;
  if (DAT_10038dac == 0) {
    __FF_MSGBANNER();
    __NMSG_WRITE(0x1e);
    ___crtExitProcess(0xff);
  }
  piVar1 = &DAT_10037618 + _LockNum * 2;
  if (*piVar1 == 0) {
    _Memory = __malloc_crt(0x18);
    if (_Memory == (void *)0x0) {
      piVar1 = __errno();
      *piVar1 = 0xc;
      iVar2 = 0;
    }
    else {
      __lock(10);
      if (*piVar1 == 0) {
        iVar2 = ___crtInitCritSecAndSpinCount(_Memory,4000);
        if (iVar2 == 0) {
          _free(_Memory);
          piVar1 = __errno();
          *piVar1 = 0xc;
          local_20 = 0;
        }
        else {
          *piVar1 = (int)_Memory;
        }
      }
      else {
        _free(_Memory);
      }
      FUN_100161fa();
      iVar2 = local_20;
    }
  }
  return iVar2;
}
