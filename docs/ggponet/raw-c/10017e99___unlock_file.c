
/* Library Function - Single Match
    __unlock_file
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)((int)&DAT_100377fc + 3U) < _File) && (_File < (FILE *)0x10037a61)) {
    _File->_flag = _File->_flag & 0xffff7fff;
    FUN_10016129(((int)(_File + -0x801bc0) >> 5) + 0x10);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}
