
void Catch_All_1000705a(void)

{
  _Container_proxy *p_Var1;
  int unaff_EBP;
  
  if (1 < *(int *)(unaff_EBP + -0x14)) {
    p_Var1 = (_Container_proxy *)FUN_100019c0(*(undefined4 *)(unaff_EBP + -0x18));
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(*(int *)(unaff_EBP + -0x28) + 0x10),p_Var1);
  }
  if (0 < *(int *)(unaff_EBP + -0x14)) {
    p_Var1 = (_Container_proxy *)FUN_10007c60(*(undefined4 *)(unaff_EBP + -0x18));
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(*(int *)(unaff_EBP + -0x28) + 0x10),p_Var1);
  }
  FUN_100033b0(*(undefined4 *)(unaff_EBP + -0x18),1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
