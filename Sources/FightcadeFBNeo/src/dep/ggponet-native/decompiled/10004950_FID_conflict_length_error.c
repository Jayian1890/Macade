
/* Library Function - Multiple Matches With Different Base Names
    public: __thiscall std::ios_base::failure::failure(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::invalid_argument::invalid_argument(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::length_error::length_error(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
    public: __thiscall std::out_of_range::out_of_range(class std::basic_string<char,struct
   std::char_traits<char>,class std::allocator<char> > const &)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

undefined4 * FID_conflict_length_error(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FID_conflict_runtime_error(param_1);
  *in_ECX = std::out_of_range::vftable;
  return in_ECX;
}
