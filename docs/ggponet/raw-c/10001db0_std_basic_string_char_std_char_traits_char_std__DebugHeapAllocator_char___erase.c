
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::erase(unsigned int,unsigned int)
   
   Library: Visual Studio 2008 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::erase
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(uint *)(this + 0x14) < param_1) {
    FUN_10010c88();
  }
  if (*(int *)(this + 0x14) - param_1 < param_2) {
    param_2 = *(int *)(this + 0x14) - param_1;
  }
  if (param_2 != 0) {
    uVar4 = (*(int *)(this + 0x14) - param_1) - param_2;
    iVar1 = FID_conflict__Myptr();
    pcVar2 = (char *)(iVar1 + param_1 + param_2);
    uVar3 = *(int *)(this + 0x18) - param_1;
    iVar1 = FID_conflict__Myptr();
    _Traits_helper::move_s<std::char_traits<char>_>((char *)(iVar1 + param_1),uVar3,pcVar2,uVar4);
    _Eos(this,*(int *)(this + 0x14) - param_2);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
