
void FUN_10025240(LPSTR param_1,int param_2,int *param_3)

{
  BOOL local_10;
  int local_c;
  int local_8;
  
  local_c = FUN_10025210(param_2,param_3);
  local_8 = MultiByteToWideChar(0xfde9,0,(LPCSTR)(param_2 + *param_3),local_c,(LPWSTR)&DAT_100394e8,
                                0x1000000);
  WideCharToMultiByte(0,0,(LPCWSTR)&DAT_100394e8,local_8,param_1,0x1000000,"?",&local_10);
  param_1[local_c] = '\0';
  *param_3 = *param_3 + local_c;
  return;
}
