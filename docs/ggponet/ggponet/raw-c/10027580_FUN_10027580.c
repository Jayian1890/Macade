
void FUN_10027580(int param_1)

{
  undefined4 uVar1;
  FILE *pFVar2;
  int in_ECX;
  char *pcVar3;
  char *local_11c;
  char local_114 [268];
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  FUN_100273b0();
  CreateDirectoryA("synclogs",(LPSECURITY_ATTRIBUTES)0x0);
  if (*(char *)(in_ECX + 0x29d) == '\0') {
    local_11c = "original";
  }
  else {
    local_11c = "replay";
  }
  if (param_1 == 0) {
    pcVar3 = "log";
  }
  else {
    pcVar3 = "state";
  }
  uVar1 = FUN_10002810(local_11c,pcVar3);
  _sprintf(local_114,"synclogs\\%s-%04d-%s.log",pcVar3,uVar1);
  pFVar2 = _fopen(local_114,"w");
  *(FILE **)(in_ECX + 0x2a0) = pFVar2;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}
