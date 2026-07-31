
/* Library Function - Single Match
    public: char * __thiscall std::allocator<char>::allocate(unsigned int)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

char * __thiscall std::allocator<char>::allocate(allocator<char> *this,uint param_1)

{
  char *pcVar1;
  
  pcVar1 = _Allocate<char>(param_1,(char *)0x0);
  return pcVar1;
}
