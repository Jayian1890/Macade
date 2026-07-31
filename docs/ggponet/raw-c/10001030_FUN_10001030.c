
void FUN_10001030(void)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::bad_alloc::vftable;
  exception::~exception(in_ECX);
  return;
}
