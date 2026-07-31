
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::logic_error::logic_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::runtime_error::runtime_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 * FID_conflict_runtime_error(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_1001111f(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *in_ECX = std::logic_error::vftable;
  FUN_10001540(param_1);
  ExceptionList = local_10;
  return in_ECX;
}
