
void Catch_All_1000a7a7(void)

{
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 0x10)) {
    std::allocator<std::_Container_proxy>::destroy
              (*(allocator<std::_Container_proxy> **)(unaff_EBP + 0x14),
               *(_Container_proxy **)(unaff_EBP + -0x14));
    FUN_1000a7a9();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
