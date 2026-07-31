
void FUN_10021ec0(FILE *param_1,char *param_2,va_list param_3)

{
  char *pcVar1;
  DWORD DVar2;
  int local_8;
  
  pcVar1 = _getenv("quark.log.timestamps");
  if (pcVar1 != (char *)0x0) {
    local_8 = 0;
    if (DAT_1343951c == 0) {
      DAT_1343951c = timeGetTime();
    }
    else {
      DVar2 = timeGetTime();
      local_8 = DVar2 - DAT_1343951c;
    }
    _fprintf(param_1,"%d.%03d : ",local_8 / 1000,local_8 % 1000);
  }
  FID_conflict__vfprintf(param_1,param_2,param_3);
  _fflush(param_1);
  _vsprintf(&DAT_130394e8,param_2,param_3);
  OutputDebugStringA(&DAT_130394e8);
  return;
}
