
void __cdecl FUN_10004e60(HWND param_1,char *param_2)

{
  char cVar1;
  HINSTANCE hInstance;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  hInstance = DAT_1000edb4;
  uVar2 = 0xffffffff;
  do {
    pcVar4 = param_2;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = &DAT_1000eca8;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  DialogBoxParamA(hInstance,(LPCSTR)0x67,param_1,(DLGPROC)&LAB_10004eb0,0);
  return;
}
