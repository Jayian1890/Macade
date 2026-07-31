
/* Library Function - Multiple Matches With Different Base Names
    public: virtual __thiscall std::logic_error::~logic_error(void)
    public: virtual __thiscall std::runtime_error::~runtime_error(void)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

void FID_conflict__logic_error(void)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::logic_error::vftable;
  FUN_10001580();
  exception::~exception(in_ECX);
  return;
}
