
void FUN_1001b7d4(exception *param_1)

{
  exception *in_ECX;
  
  std::exception::exception(in_ECX,param_1);
  *(undefined ***)in_ECX = std::bad_exception::vftable;
  return;
}
