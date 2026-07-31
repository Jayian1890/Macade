
undefined4 FUN_100070bd(void)

{
  undefined1 *puVar1;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  puVar1 = (undefined1 *)FUN_10006450(*(undefined4 *)(unaff_EBP + -0x18));
  *puVar1 = 1;
  puVar1 = (undefined1 *)FUN_10005a90(*(undefined4 *)(unaff_EBP + -0x18));
  *puVar1 = 0;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x18);
}
