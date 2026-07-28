
void __fastcall FUN_10001640(int *param_1)

{
  char *_Source;
  int iVar1;
  int iVar2;
  int local_38;
  char local_34 [16];
  undefined1 local_24;
  CHAR local_20 [32];
  
  if ((*param_1 != 0) && (local_38 = 0, 0 < param_1[2])) {
    iVar1 = 0;
    do {
      if (*(int *)((char *)(*param_1 + iVar1) + 0x14) != 0) {
        strncpy(local_34,(char *)(*param_1 + iVar1),0x10);
        local_24 = 0;
        wsprintfA(local_20,&DAT_1000e060,*(undefined4 *)(iVar1 + 0x10 + *param_1));
        WritePrivateProfileStringA((LPCSTR)(param_1 + 0x47),local_34,local_20,(LPCSTR)(param_1 + 6))
        ;
        *(undefined4 *)(iVar1 + 0x14 + *param_1) = 0;
      }
      local_38 = local_38 + 1;
      iVar1 = iVar1 + 0x18;
    } while (local_38 < param_1[2]);
  }
  if ((param_1[1] != 0) && (iVar1 = 0, 0 < param_1[4])) {
    iVar2 = 0;
    do {
      _Source = (char *)(iVar2 + param_1[1]);
      if ((*(int *)(iVar2 + 0x10 + param_1[1]) != 0) && (*(int *)(_Source + 0x14) != 0)) {
        strncpy(local_34,_Source,0x10);
        local_24 = 0;
        WritePrivateProfileStringA
                  ((LPCSTR)(param_1 + 0x47),local_34,*(LPCSTR *)(iVar2 + 0x10 + param_1[1]),
                   (LPCSTR)(param_1 + 6));
        *(undefined4 *)(iVar2 + 0x14 + param_1[1]) = 0;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < param_1[4]);
  }
  return;
}
