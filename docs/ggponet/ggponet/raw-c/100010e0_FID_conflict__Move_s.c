
/* Library Function - Multiple Matches With Different Base Names
    public: static unsigned short * __cdecl std::char_traits<unsigned short>::_Copy_s(unsigned short
   *,unsigned int,unsigned short const *,unsigned int)
    public: static wchar_t * __cdecl std::char_traits<wchar_t>::_Copy_s(wchar_t *,unsigned
   int,wchar_t const *,unsigned int)
    public: static char * __cdecl std::char_traits<char>::_Move_s(char *,unsigned int,char const
   *,unsigned int)
    public: static unsigned short * __cdecl std::char_traits<unsigned short>::_Move_s(unsigned short
   *,unsigned int,unsigned short const *,unsigned int)
     5 names - too many to list
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

void * FID_conflict__Move_s(void *param_1,rsize_t param_2,void *param_3,rsize_t param_4)

{
  _memmove_s(param_1,param_2,param_3,param_4);
  return param_1;
}
