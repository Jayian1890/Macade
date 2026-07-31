
/* Library Function - Single Match
    protected: bool __thiscall std::basic_string<char,struct std::char_traits<char>,class
   std::_DebugHeapAllocator<char> >::_Grow(unsigned int,bool)
   
   Library: Visual Studio 2005 Debug */

bool __thiscall
std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Grow
          (basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *this,
          uint param_1,bool param_2)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = FID_conflict_max_size();
  if (uVar1 < param_1) {
    FUN_10010c50();
  }
  if (*(uint *)(this + 0x18) < param_1) {
    FUN_100022a0(param_1,*(undefined4 *)(this + 0x14));
  }
  else if ((param_2) && (param_1 < 0x10)) {
    if (param_1 < *(uint *)(this + 0x14)) {
      local_c = param_1;
    }
    else {
      local_c = *(uint *)(this + 0x14);
    }
    FUN_100018d0(1,local_c);
  }
  else if (param_1 == 0) {
    _Eos(this,0);
  }
  return param_1 != 0;
}
