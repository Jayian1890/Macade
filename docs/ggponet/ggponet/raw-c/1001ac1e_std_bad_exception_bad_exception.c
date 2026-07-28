
/* Library Function - Single Match
    public: __thiscall std::bad_exception::bad_exception(char const *)
   
   Library: Visual Studio 2008 Release */

bad_exception * __thiscall std::bad_exception::bad_exception(bad_exception *this,char *param_1)

{
  exception::exception((exception *)this,&param_1);
  *(undefined ***)this = vftable;
  return this;
}
