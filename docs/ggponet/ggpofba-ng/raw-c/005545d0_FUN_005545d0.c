
undefined4 FUN_005545d0(void)

{
  int iVar1;
  undefined4 unaff_ESI;
  
  if (((DAT_00b19da0 != 0) && (iVar1 = FUN_005540f0(unaff_ESI), iVar1 == 0)) &&
     (iVar1 = FUN_00553ff0(unaff_ESI), iVar1 == 0)) {
    if (DAT_00ad74dc == 0) {
      return 0;
    }
    iVar1 = FUN_005541f0(unaff_ESI);
    if (((iVar1 == 0) && (iVar1 = FUN_00554420(unaff_ESI), iVar1 == 0)) &&
       (iVar1 = FUN_00555a70(), iVar1 == 0)) {
      return 0;
    }
  }
  return 1;
}
