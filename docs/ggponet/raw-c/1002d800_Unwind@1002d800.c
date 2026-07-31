
void Unwind_1002d800(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}
