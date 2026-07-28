
void __cdecl FUN_10008400(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  LRESULT LVar1;
  char *pcVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  CHAR local_20 [32];
  
  local_30 = param_1;
  local_2c = 0;
  local_28 = 0;
  local_38 = 1;
  local_34 = 0;
  local_24 = 0;
  LVar1 = SendMessageA(DAT_1000f138,0x100d,0xffffffff,(LPARAM)&local_38);
  if (LVar1 != -1) {
    pcVar2 = s_Waiting_1000e5f8;
    if (param_2 != 0) {
      pcVar2 = s_Playing_1000e794;
    }
    FUN_100042c0(&DAT_1000f138,LVar1,3,pcVar2);
    wsprintfA(local_20,s__i__i_1000e7ac,param_3,param_4);
    FUN_100042c0(&DAT_1000f138,LVar1,4,local_20);
    FUN_100044f0(&DAT_1000f138);
  }
  return;
}
