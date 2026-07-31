
/* Library Function - Single Match
    protected: void __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Eos(unsigned int)
   
   Library: Visual Studio 2005 Debug */

void __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1)

{
  int iVar1;
  undefined1 local_5;
  
  local_5 = 0;
  *(uint *)(this + 0x14) = param_1;
  iVar1 = FID_conflict__Myptr(&local_5);
  FUN_10001090(iVar1 + param_1);
  return;
}
