
void Catch_All_100098ac(void)

{
  int unaff_EBP;
  
  if (1 < *(int *)(unaff_EBP + -0x20)) {
    FUN_10002c20(*(undefined4 *)(unaff_EBP + -0x1c),
                 *(int *)(unaff_EBP + -0x18) * 0x10 + *(int *)(unaff_EBP + -0x1c));
  }
  if (0 < *(int *)(unaff_EBP + -0x20)) {
    FUN_10002c20(*(int *)(unaff_EBP + -0x18) * 0x10 + *(int *)(unaff_EBP + -0x1c),
                 *(int *)(unaff_EBP + -0x18) * 0x10 + *(int *)(unaff_EBP + -0x1c) +
                 *(int *)(unaff_EBP + 0x10) * 0x10);
  }
  FUN_100033b0(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x14));
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
