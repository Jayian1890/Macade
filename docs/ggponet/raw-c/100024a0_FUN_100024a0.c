
int FUN_100024a0(void)

{
  int in_ECX;
  
  std::allocator<char>::allocator<char>
            ((allocator<char> *)&stack0xfffffff0,(allocator<char> *)&stack0x00000004);
  FUN_10002530();
  std::allocator<char>::allocator<char>
            ((allocator<char> *)(in_ECX + 8),(allocator<char> *)&stack0x00000004);
  return in_ECX;
}
