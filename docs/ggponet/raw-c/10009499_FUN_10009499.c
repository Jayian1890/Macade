
void FUN_10009499(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = FUN_10008d70();
  *(int *)(unaff_EBP + 0x10) = iVar1 + *(int *)(unaff_EBP + 0x10);
  if (*(int *)(*(int *)(unaff_EBP + -0x38) + 0xc) != 0) {
    FUN_10002bf0(*(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0x10));
    FUN_100033b0(*(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc),
                 *(int *)(*(int *)(unaff_EBP + -0x38) + 0x14) -
                 *(int *)(*(int *)(unaff_EBP + -0x38) + 0xc) >> 3);
  }
  *(int *)(*(int *)(unaff_EBP + -0x38) + 0x14) =
       *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + -0x14) * 8;
  *(int *)(*(int *)(unaff_EBP + -0x38) + 0x10) =
       *(int *)(unaff_EBP + -0x1c) + *(int *)(unaff_EBP + 0x10) * 8;
  *(undefined4 *)(*(int *)(unaff_EBP + -0x38) + 0xc) = *(undefined4 *)(unaff_EBP + -0x1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
