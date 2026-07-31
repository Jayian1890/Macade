
/* Library Function - Single Match
    public: __thiscall std::bad_alloc::bad_alloc(char const *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

bad_alloc * __thiscall std::bad_alloc::bad_alloc(bad_alloc *this,char *param_1)

{
  exception::exception((exception *)this,&param_1);
  *(undefined ***)this = vftable;
  return this;
}
