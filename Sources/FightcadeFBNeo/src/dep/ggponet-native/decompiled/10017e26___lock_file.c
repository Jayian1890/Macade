
/* Library Function - Single Match
    __lock_file
   
   Library: Visual Studio 2008 Release */

void __cdecl __lock_file(FILE *_File)

{
  if ((_File < &PTR_DAT_10037800) || ((FILE *)&DAT_10037a60 < _File)) {
    EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  }
  else {
    __lock(((int)(_File + -0x801bc0) >> 5) + 0x10);
    _File->_flag = _File->_flag | 0x8000;
  }
  return;
}
