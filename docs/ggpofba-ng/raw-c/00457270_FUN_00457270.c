
undefined4 FUN_00457270(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  INITCOMMONCONTROLSEX local_10;
  
  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)&LAB_00459eb0);
  DAT_00ad6f40 = param_1;
  if ((DAT_008761ec & 0xff) == 0) {
    _sprintf(&DAT_00ad734c,"%x.%x.%x",(int)DAT_008761ec >> 0x14,(int)DAT_008761ec._2_2_ & 0xfU,
             (int)DAT_008761ec >> 8 & 0xff);
  }
  else {
    _sprintf(&DAT_00ad734c,"%x.%x.%x.%x",(int)DAT_008761ec >> 0x14,(int)DAT_008761ec._2_2_ & 0xfU,
             (int)DAT_008761ec >> 8 & 0xff,DAT_008761ec & 0xff);
  }
  DAT_009e6cbc = param_4;
  FUN_00459ff0();
  CreateDirectoryA("config",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("config\\games",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("config\\localisation",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("config\\presets",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("savestates",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("cheats",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("flyers",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("previews",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("recordings",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("ROMs",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("screenshots",(LPSECURITY_ATTRIBUTES)0x0);
  CreateDirectoryA("titles",(LPSECURITY_ATTRIBUTES)0x0);
  local_10.dwSize = 8;
  local_10.dwICC = 0x427;
  InitCommonControlsEx(&local_10);
  if (param_3 != (char *)0x0) {
    iVar2 = (int)&DAT_00ad6f48 - (int)param_3;
    do {
      cVar1 = *param_3;
      param_3[iVar2] = cVar1;
      param_3 = param_3 + 1;
    } while (cVar1 != '\0');
  }
  iVar2 = FUN_00456b20();
  if (iVar2 == 0) {
    iVar2 = FUN_00456d80();
    if (iVar2 == 0) {
      FUN_0045cc40();
      FUN_0045d960();
    }
  }
  FUN_00456c40();
  FUN_0046f780();
  return 0;
}
