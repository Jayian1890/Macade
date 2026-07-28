
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall kailleraInit,0 */

void kailleraInit(void)

{
  char cVar1;
  void *this;
  char *pcVar2;
  HMODULE hModule;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
                    /* 0x5830  4  _kailleraInit@0 */
  DAT_1000ef88 = 0;
  this = operator_new(0x13c);
  if (this == (void *)0x0) {
    DAT_1000ef90 = (undefined4 *)0x0;
  }
  else {
    DAT_1000ef90 = FUN_100017a0(this,s_kaillera_ini_1000e49c,s_KailleraClient_1000e4ac);
  }
  DAT_1000ef98 = 0;
  pcVar2 = (char *)FUN_10001ba0(DAT_1000ef90,s_username_1000e490,&DAT_1000ec9c);
  uVar3 = 0xffffffff;
  do {
    pcVar5 = pcVar2;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = pcVar2 + 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar2 = pcVar5 + -uVar3;
  pcVar5 = &DAT_1000edc8;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar5 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar5 = pcVar5 + 1;
  }
  DAT_1000edc0 = 0;
  _DAT_1000edbc = 0x6cee;
  DAT_1000eefc = FUN_100019d0(DAT_1000ef90,s_conntype_1000e484,3);
  FUN_10004140();
  Ordinal_17();
  hModule = LoadLibraryA(s_USER32_DLL_1000e478);
  DAT_1000eef0 = GetProcAddress(hModule,s_FlashWindowEx_1000e468);
  FreeLibrary(hModule);
  DAT_1000ef94 = LoadLibraryA(s_RICHED32_DLL_1000e458);
  FUN_10005920();
  FUN_10005a60();
  FUN_10005690();
  return;
}
