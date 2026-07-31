
void FUN_10025150(LPCSTR param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_3;
  MultiByteToWideChar(0,0,param_1,-1,(LPWSTR)&DAT_100394e8,0x1000000);
  iVar1 = WideCharToMultiByte(0xfde9,0,(LPCWSTR)&DAT_100394e8,-1,(LPSTR)(param_2 + 4 + iVar1),
                              0x1000000,(LPCSTR)0x0,(LPBOOL)0x0);
  uVar2 = Ordinal_14(iVar1 + -1);
  *(undefined4 *)(param_2 + *param_3) = uVar2;
  *param_3 = iVar1 + 3 + *param_3;
  return;
}
