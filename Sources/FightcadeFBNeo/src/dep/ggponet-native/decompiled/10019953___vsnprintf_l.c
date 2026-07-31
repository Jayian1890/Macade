
/* Library Function - Single Match
    __vsnprintf_l
   
   Library: Visual Studio 2008 Release */

int __cdecl
__vsnprintf_l(char *_DstBuf,size_t _MaxCount,char *_Format,_locale_t _Locale,va_list _ArgList)

{
  int *piVar1;
  int iVar2;
  FILE local_24;
  
  if (_Format == (char *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  else if ((_MaxCount == 0) || (_DstBuf != (char *)0x0)) {
    local_24._cnt = 0x7fffffff;
    if (_MaxCount < 0x80000000) {
      local_24._cnt = _MaxCount;
    }
    local_24._flag = 0x42;
    local_24._base = _DstBuf;
    local_24._ptr = _DstBuf;
    iVar2 = __output_l(&local_24,_Format,_Locale,_ArgList);
    if (_DstBuf != (char *)0x0) {
      local_24._cnt = local_24._cnt - 1;
      if (local_24._cnt < 0) {
        __flsbuf(0,&local_24);
      }
      else {
        *local_24._ptr = '\0';
      }
    }
  }
  else {
    piVar1 = __errno();
    *piVar1 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    iVar2 = -1;
  }
  return iVar2;
}
