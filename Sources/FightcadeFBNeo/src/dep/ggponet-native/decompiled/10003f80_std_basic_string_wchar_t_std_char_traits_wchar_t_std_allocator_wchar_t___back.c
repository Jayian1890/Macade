
/* Library Function - Single Match
    public: wchar_t & __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::back(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

wchar_t * __thiscall
std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_>::back
          (basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>_> *this)

{
  wchar_t *pwVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  uVar3 = 1;
  puVar2 = local_14;
  FUN_100041f0(local_c);
  FUN_10004560(puVar2,uVar3);
  pwVar1 = (wchar_t *)FUN_10004540(this);
  return pwVar1;
}
