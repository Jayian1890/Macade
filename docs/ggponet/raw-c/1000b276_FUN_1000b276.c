
void FUN_1000b276(void)

{
  char cVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  cVar1 = FUN_10004d20(unaff_EBP + 0x10);
  if (cVar1 != '\0') {
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
    puVar2 = (undefined4 *)FUN_1000b2f0();
    FUN_10001a80(unaff_EBP + -0x28,*puVar2,puVar2[1]);
    FUN_1000b26e();
    return;
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}
