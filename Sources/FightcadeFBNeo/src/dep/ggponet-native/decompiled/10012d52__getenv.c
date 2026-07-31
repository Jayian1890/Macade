
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _getenv
   
   Library: Visual Studio 2008 Release */

char * __cdecl _getenv(char *_VarName)

{
  int *piVar1;
  size_t sVar2;
  char *pcVar3;
  
  if ((_VarName != (char *)0x0) && (sVar2 = _strnlen(_VarName,0x7fff), sVar2 < 0x7fff)) {
    __lock(7);
    pcVar3 = __getenv_helper_nolock(_VarName);
    FUN_10012dcc();
    return pcVar3;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  return (char *)0x0;
}
