
/* Library Function - Multiple Matches With Same Base Name
    protected: __thiscall std::_String_val<char,class std::allocator<char> >::_String_val<char,class
   std::allocator<char> >(class std::allocator<char>)
    protected: __thiscall std::_String_val<unsigned short,class std::allocator<unsigned short>
   >::_String_val<unsigned short,class std::allocator<unsigned short> >(class
   std::allocator<unsigned short>)
    protected: __thiscall std::_String_val<wchar_t,class std::allocator<wchar_t>
   >::_String_val<wchar_t,class std::allocator<wchar_t> >(class std::allocator<wchar_t>)
   
   Library: Visual Studio 2003 Debug */

allocator<char> * _String_val<>(void)

{
  allocator<char> *in_ECX;
  
  std::allocator<char>::allocator<char>(in_ECX,(allocator<char> *)&stack0x00000004);
  return in_ECX;
}
