
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _printf
   
   Library: Visual Studio 2008 Release */

int __cdecl _printf(char *_Format,...)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  _locale_t _Locale;
  va_list _ArgList;
  
  if (_Format == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  else {
    iVar3 = FUN_10017d4f();
    __lock_file2(1,(void *)(iVar3 + 0x20));
    iVar3 = FUN_10017d4f();
    iVar3 = __stbuf((FILE *)(iVar3 + 0x20));
    _ArgList = &stack0x00000008;
    _Locale = (_locale_t)0x0;
    iVar4 = FUN_10017d4f();
    iVar2 = __output_l((FILE *)(iVar4 + 0x20),_Format,_Locale,_ArgList);
    iVar4 = FUN_10017d4f();
    __ftbuf(iVar3,(FILE *)(iVar4 + 0x20));
    FUN_1001202e();
  }
  return iVar2;
}
