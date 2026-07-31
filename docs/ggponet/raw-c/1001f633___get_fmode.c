
/* Library Function - Single Match
    __get_fmode
   
   Library: Visual Studio 2008 Release */

errno_t __cdecl __get_fmode(int *_PMode)

{
  int *piVar1;
  errno_t eVar2;
  
  if (_PMode == (int *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    eVar2 = 0x16;
  }
  else {
    *_PMode = DAT_100394e0;
    eVar2 = 0;
  }
  return eVar2;
}
