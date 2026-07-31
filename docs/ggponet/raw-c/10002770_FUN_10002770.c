
exception * FUN_10002770(exception *param_1)

{
  exception *in_ECX;
  
  std::exception::exception(in_ECX,param_1);
  *(undefined ***)in_ECX = std::bad_alloc::vftable;
  return in_ECX;
}
