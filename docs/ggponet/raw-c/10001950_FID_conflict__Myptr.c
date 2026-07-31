
/* Library Function - Multiple Matches With Different Base Names
    protected: char * __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Myptr(void)
    protected: char * __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Myptr(void)
   
   Library: Visual Studio 2005 Debug */

int FID_conflict__Myptr(void)

{
  int in_ECX;
  undefined4 local_c;
  
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    local_c = in_ECX + 4;
  }
  else {
    local_c = *(int *)(in_ECX + 4);
  }
  return local_c;
}
