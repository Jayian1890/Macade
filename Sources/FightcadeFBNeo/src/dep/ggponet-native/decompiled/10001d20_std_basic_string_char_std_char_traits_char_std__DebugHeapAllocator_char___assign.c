
/* Library Function - Single Match
    public: class std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> > & __thiscall std::basic_string<char,struct
   std::char_traits<char>,class std::_DebugHeapAllocator<char> >::assign(char const *,unsigned int)
   
   Library: Visual Studio 2005 Debug */

basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> * __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::assign
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          char *param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  
  cVar1 = FID_conflict__Inside(param_1);
  if (cVar1 == '\0') {
    bVar2 = _Grow(this,param_2,false);
    if (bVar2) {
      uVar5 = *(uint *)(this + 0x18);
      uVar6 = param_2;
      pcVar4 = (char *)FID_conflict__Myptr();
      _Traits_helper::copy_s<std::char_traits<char>_>(pcVar4,uVar5,param_1,uVar6);
      _Eos(this,param_2);
    }
  }
  else {
    iVar3 = FID_conflict__Myptr();
    this = (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
           assign(this,(basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_>
                        *)this,(int)param_1 - iVar3,param_2);
  }
  return (basic_string<char,struct_std::char_traits<char>,class_std::_DebugHeapAllocator<char>_> *)
         this;
}
