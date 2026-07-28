
undefined4 FUN_00456c40(void)

{
  FUN_00456a90(DAT_009e6c75);
  FUN_0045d0e0();
  _free(DAT_00b1831c);
  DAT_00b1831c = (void *)0x0;
  FUN_0045cdc0();
  DAT_00b196f8 = 0;
  kailleraShutdown();
  FUN_00471ef0();
  if (DAT_00ad7348 != (HACCEL)0x0) {
    DestroyAcceleratorTable(DAT_00ad7348);
    DAT_00ad7348 = (HACCEL)0x0;
  }
  FUN_004573d0(1);
  CloseHandle(DAT_009e6cb8);
  return 0;
}
