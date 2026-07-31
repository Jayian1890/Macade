
int FUN_10001cc0(void)

{
  int in_ECX;
  
  std::allocator<char>::allocator<char>
            ((allocator<char> *)&stack0xfffffff0,(allocator<char> *)&stack0x00000004);
  FUN_10002110();
  std::allocator<char>::allocator<char>
            ((allocator<char> *)(in_ECX + 0x10),(allocator<char> *)&stack0x00000004);
  return in_ECX;
}
