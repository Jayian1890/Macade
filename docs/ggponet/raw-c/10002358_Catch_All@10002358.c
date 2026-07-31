
void Catch_All_10002358(void)

{
  char *pcVar1;
  int unaff_EBP;
  
  *(BADSPACEBASE **)(unaff_EBP + -0x10) = register0x00000010;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  pcVar1 = std::allocator<char>::allocate
                     (*(allocator<char> **)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x18) + 1);
  *(char **)(unaff_EBP + -0x24) = pcVar1;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x24);
  FUN_100023a1();
  return;
}
