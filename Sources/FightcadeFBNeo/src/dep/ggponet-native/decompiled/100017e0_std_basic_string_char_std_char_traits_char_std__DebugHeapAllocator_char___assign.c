
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(class
   std::basic_string<char,struct std::char_traits<char>,class std::_DebugHeapAllocator<char> > const
   &,unsigned int,unsigned int)
   
   Library: Visual Studio 2005 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
          *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint local_8;
  
  uVar2 = FUN_100015c0();
  if (uVar2 < param_2) {
    FUN_10010c88();
  }
  iVar3 = FUN_100015c0();
  local_8 = iVar3 - param_2;
  if (param_3 < local_8) {
    local_8 = param_3;
  }
  if (this == (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)param_1)
  {
    erase(this,param_2 + local_8,0xffffffff);
    erase(this,0,param_2);
  }
  else {
    bVar1 = _Grow(this,local_8,false);
    if (bVar1) {
      uVar6 = local_8;
      iVar3 = FID_conflict__Myptr();
      pcVar4 = (char *)(iVar3 + param_2);
      uVar2 = *(uint *)(this + 0x18);
      pcVar5 = (char *)FID_conflict__Myptr();
      _Traits_helper::copy_s<std::char_traits<char>_>(pcVar5,uVar2,pcVar4,uVar6);
      _Eos(this,local_8);
    }
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
