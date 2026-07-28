
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall ATL::CAtlWinModule::~CAtlWinModule(void)
    public: __thiscall CPaneContainerGC::~CPaneContainerGC(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2010 Debug */

void FID_conflict__CAtlWinModule(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_1002d908;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_10005580(DAT_10037490 ^ (uint)&stack0xfffffffc);
  local_8 = 0xffffffff;
  FUN_10004d80();
  ExceptionList = local_10;
  return;
}
