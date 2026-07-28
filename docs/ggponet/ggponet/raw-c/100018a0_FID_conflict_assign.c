
/* Library Function - Multiple Matches With Different Base Names
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(char const *)
    public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >
   & __thiscall std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>
   >::assign(char const *)
   
   Library: Visual Studio 2005 Debug */

void FID_conflict_assign(char *param_1)

{
  uint uVar1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *in_ECX;
  
  uVar1 = length(param_1);
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
            (in_ECX,param_1,uVar1);
  return;
}
