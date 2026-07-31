
void FUN_100095be(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(*(int *)(unaff_EBP + -0x38) + 0x10) =
       *(int *)(*(int *)(unaff_EBP + -0x38) + 0x10) + *(int *)(unaff_EBP + 0x10) * 8;
  FUN_10009f30(*(undefined4 *)(unaff_EBP + 0xc),
               *(int *)(*(int *)(unaff_EBP + -0x38) + 0x10) + *(int *)(unaff_EBP + 0x10) * -8,
               unaff_EBP + -0x28);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
