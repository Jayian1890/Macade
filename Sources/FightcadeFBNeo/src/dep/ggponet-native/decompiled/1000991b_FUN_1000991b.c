
void FUN_1000991b(void)

{
  int iVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar1 = FUN_10008eb0();
  *(int *)(unaff_EBP + 0x10) = iVar1 + *(int *)(unaff_EBP + 0x10);
  if (*(int *)(*(int *)(unaff_EBP + -0x48) + 0xc) != 0) {
    FUN_10002c20(*(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 0xc),
                 *(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 0x10));
    FUN_100033b0(*(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 0xc),
                 *(int *)(*(int *)(unaff_EBP + -0x48) + 0x14) -
                 *(int *)(*(int *)(unaff_EBP + -0x48) + 0xc) >> 4);
  }
  *(int *)(*(int *)(unaff_EBP + -0x48) + 0x14) =
       *(int *)(unaff_EBP + -0x14) * 0x10 + *(int *)(unaff_EBP + -0x1c);
  *(int *)(*(int *)(unaff_EBP + -0x48) + 0x10) =
       *(int *)(unaff_EBP + 0x10) * 0x10 + *(int *)(unaff_EBP + -0x1c);
  *(undefined4 *)(*(int *)(unaff_EBP + -0x48) + 0xc) = *(undefined4 *)(unaff_EBP + -0x1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}
