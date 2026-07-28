
/* Library Function - Single Match
    char * __cdecl std::_Traits_helper::copy_s<struct std::char_traits<char> >(char *,unsigned
   int,char const *,unsigned int)
   
   Library: Visual Studio 2008 Debug */

char * __cdecl
std::_Traits_helper::copy_s<std::char_traits<char>_>
          (char *param_1,uint param_2,char *param_3,uint param_4)

{
  undefined1 uVar1;
  char *pcVar2;
  
  uVar1 = _Char_traits_cat<>();
  pcVar2 = (char *)FID_conflict_copy_s<std::char_traits<wchar_t>_>
                             (param_1,param_2,param_3,param_4,uVar1);
  return pcVar2;
}
