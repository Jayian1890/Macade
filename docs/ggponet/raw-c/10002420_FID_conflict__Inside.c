
/* Library Function - Multiple Matches With Different Base Names
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Inside(char const *)
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> >::_Inside(char const *)
   
   Library: Visual Studio 2008 Debug */

uint FID_conflict__Inside(uint param_1)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  if ((param_1 != 0) && (in_EAX = FID_conflict__Myptr(), in_EAX <= param_1)) {
    iVar1 = FID_conflict__Myptr();
    in_EAX = iVar1 + *(int *)(in_ECX + 0x14);
    if (param_1 < in_EAX) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}
