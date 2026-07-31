
void FUN_10021f70(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  DWORD DVar2;
  
  pcVar1 = _getenv("quark.log");
  if ((pcVar1 != (char *)0x0) && (pcVar1 = _getenv("quark.log.ignore"), pcVar1 == (char *)0x0)) {
    if (DAT_134394e8 == (FILE *)0x0) {
      DVar2 = GetCurrentProcessId();
      _sprintf(&DAT_130394e8,"c:\\users\\ponder\\log-%d.log",DVar2);
      DAT_134394e8 = _fopen(&DAT_130394e8,"w");
    }
    FUN_10021ec0(DAT_134394e8,param_1,param_2);
  }
  return;
}
