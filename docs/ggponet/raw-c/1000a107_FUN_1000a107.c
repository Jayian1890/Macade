
void FUN_1000a107(void)

{
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
  if (*(int *)(unaff_EBP + -0x14) != *(int *)(unaff_EBP + 8)) {
    std::allocator<std::_Container_proxy>::destroy
              (*(allocator<std::_Container_proxy> **)(unaff_EBP + 0x14),
               *(_Container_proxy **)(unaff_EBP + -0x14));
    FUN_1000a107();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
