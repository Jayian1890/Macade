
void FUN_1001ac47(byte param_1)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::bad_exception::vftable;
  exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_100117f8();
  }
  return;
}
