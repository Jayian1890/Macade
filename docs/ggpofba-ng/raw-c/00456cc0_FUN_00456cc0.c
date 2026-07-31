
void FUN_00456cc0(void)

{
  if (DAT_00ad7554 != 0) {
    if (DAT_00ad7554 == 1) {
      FUN_004669c0();
    }
    else {
      FUN_00466a60();
    }
    DAT_00ad7554 = 0;
    FUN_00465610();
  }
  if (DAT_00b181a0 != (FILE *)0x0) {
    FUN_00468260();
    _fclose(DAT_00b181a0);
    DAT_00b181a0 = (FILE *)0x0;
    FUN_00465610();
  }
  FUN_00456c40();
  return;
}
