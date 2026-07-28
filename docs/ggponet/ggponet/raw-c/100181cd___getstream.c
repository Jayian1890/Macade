
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __getstream
   
   Library: Visual Studio 2008 Release */

FILE * __cdecl __getstream(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  FILE *pFVar6;
  FILE *_File;
  
  pFVar6 = (FILE *)0x0;
  __lock(1);
  iVar5 = 0;
  do {
    _File = pFVar6;
    if (DAT_1343a660 <= iVar5) {
LAB_100182cb:
      if (_File != (FILE *)0x0) {
        _File->_flag = _File->_flag & 0x8000;
        _File->_cnt = 0;
        _File->_base = (char *)0x0;
        _File->_ptr = (char *)0x0;
        _File->_tmpfname = (char *)0x0;
        _File->_file = -1;
      }
      FUN_100182fc();
      return _File;
    }
    piVar1 = (int *)(DAT_13439640 + iVar5 * 4);
    if (*piVar1 == 0) {
      iVar5 = iVar5 * 4;
      pvVar4 = __malloc_crt(0x38);
      *(void **)(iVar5 + DAT_13439640) = pvVar4;
      if (*(int *)(DAT_13439640 + iVar5) != 0) {
        iVar3 = ___crtInitCritSecAndSpinCount(*(int *)(DAT_13439640 + iVar5) + 0x20,4000);
        if (iVar3 == 0) {
          _free(*(void **)(iVar5 + DAT_13439640));
          *(undefined4 *)(iVar5 + DAT_13439640) = 0;
        }
        else {
          EnterCriticalSection((LPCRITICAL_SECTION)(*(int *)(iVar5 + DAT_13439640) + 0x20));
          _File = *(FILE **)(iVar5 + DAT_13439640);
          _File->_flag = 0;
        }
      }
      goto LAB_100182cb;
    }
    uVar2 = *(uint *)(*piVar1 + 0xc);
    if (((uVar2 & 0x83) == 0) && ((uVar2 & 0x8000) == 0)) {
      if ((iVar5 - 3U < 0x11) && (iVar3 = __mtinitlocknum(iVar5 + 0x10), iVar3 == 0))
      goto LAB_100182cb;
      __lock_file2(iVar5,*(void **)(DAT_13439640 + iVar5 * 4));
      _File = *(FILE **)(DAT_13439640 + iVar5 * 4);
      if ((_File->_flag & 0x83) == 0) goto LAB_100182cb;
      __unlock_file2(iVar5,_File);
    }
    iVar5 = iVar5 + 1;
  } while( true );
}
