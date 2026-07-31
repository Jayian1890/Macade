
/* Library Function - Multiple Matches With Different Base Names
    public: unsigned int __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<unsigned short,struct
   std::char_traits<unsigned short>,class std::allocator<unsigned short> >::max_size(void)const 
    public: unsigned int __thiscall std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> >::max_size(void)const 
   
   Library: Visual Studio 2003 Debug */

int FID_conflict_max_size(void)

{
  uint uVar1;
  allocator<char> *in_ECX;
  undefined4 local_10;
  
  uVar1 = std::allocator<char>::max_size(in_ECX);
  if (uVar1 < 2) {
    local_10 = 1;
  }
  else {
    local_10 = uVar1 - 1;
  }
  return local_10;
}
