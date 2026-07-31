
/* Library Function - Multiple Matches With Same Base Name
    public: __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >(char const *)
    public: __thiscall std::basic_string<unsigned short,struct std::char_traits<unsigned
   short>,class std::allocator<unsigned short> >::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >(unsigned short const *)
    public: __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >(wchar_t const *)
   
   Library: Visual Studio 2003 Debug */

undefined4 basic_string<>(undefined4 param_1)

{
  undefined4 in_ECX;
  undefined4 uVar1;
  
  uVar1 = in_ECX;
  allocator<>();
  _String_val<>(uVar1);
  FUN_100018d0(0,0);
  FID_conflict_assign(param_1);
  return in_ECX;
}
