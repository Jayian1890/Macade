
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::logic_error::logic_error(class std::logic_error const &)
    public: __thiscall std::runtime_error::runtime_error(class std::runtime_error const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

exception * FID_conflict_runtime_error(exception *param_1)

{
  exception *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d808;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  std::exception::exception(in_ECX,param_1);
  local_8 = 0;
  *(undefined ***)in_ECX = std::logic_error::vftable;
  FUN_10001540(param_1 + 0xc);
  ExceptionList = local_10;
  return in_ECX;
}
