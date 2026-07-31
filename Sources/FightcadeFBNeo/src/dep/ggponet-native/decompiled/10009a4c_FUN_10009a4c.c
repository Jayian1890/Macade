
void FUN_10009a4c(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int *)(*(int *)(unaff_EBP + -0x48) + 0x10) =
       *(int *)(unaff_EBP + 0x10) * 0x10 + *(int *)(*(int *)(unaff_EBP + -0x48) + 0x10);
  FUN_1000a000(*(undefined4 *)(unaff_EBP + 0xc),
               *(int *)(*(int *)(unaff_EBP + -0x48) + 0x10) + *(int *)(unaff_EBP + 0x10) * -0x10,
               unaff_EBP + -0x30);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
