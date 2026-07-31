
void Catch_All_10001be0(void)

{
  _Container_proxy *p_Var1;
  int unaff_EBP;
  
  if (0 < *(int *)(unaff_EBP + -0x14)) {
    p_Var1 = (_Container_proxy *)FUN_10007c60(*(undefined4 *)(unaff_EBP + -0x18));
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(*(int *)(unaff_EBP + -0x1c) + 0xc),p_Var1);
  }
  FUN_100033b0(*(undefined4 *)(unaff_EBP + -0x18),1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
