
/* __stdcall kailleraShutdown,0 */

void kailleraShutdown(void)

{
  int *piVar1;
  
                    /* 0x5ba0  8  _kailleraShutdown@0 */
  Ordinal_116();
  FUN_10001640(DAT_1000ef90);
  piVar1 = DAT_1000ef90;
  if (DAT_1000ef90 != (int *)0x0) {
    FUN_10001740(DAT_1000ef90);
    operator_delete(piVar1);
  }
  FreeLibrary(DAT_1000ef94);
  return;
}
