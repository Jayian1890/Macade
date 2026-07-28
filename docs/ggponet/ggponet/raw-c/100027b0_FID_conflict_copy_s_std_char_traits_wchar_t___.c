
/* Library Function - Multiple Matches With Different Base Names
    unsigned short * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<unsigned short>
   >(unsigned short *,unsigned int,unsigned short const *,unsigned int,struct
   std::_Secure_char_traits_tag)
    wchar_t * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<wchar_t> >(wchar_t
   *,unsigned int,wchar_t const *,unsigned int,struct std::_Secure_char_traits_tag)
    char * __cdecl std::_Traits_helper::move_s<struct std::char_traits<char> >(char *,unsigned
   int,char const *,unsigned int,struct std::_Secure_char_traits_tag)
    unsigned short * __cdecl std::_Traits_helper::move_s<struct std::char_traits<unsigned short>
   >(unsigned short *,unsigned int,unsigned short const *,unsigned int,struct
   std::_Secure_char_traits_tag)
     5 names - too many to list
   
   Library: Visual Studio 2008 Debug */

void FID_conflict_copy_s<std::char_traits<wchar_t>_>
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FID_conflict__Move_s(param_1,param_2,param_3,param_4);
  return;
}
