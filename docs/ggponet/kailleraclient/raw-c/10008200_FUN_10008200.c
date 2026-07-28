
void __cdecl
FUN_10008200(char *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  char *pcVar2;
  CHAR local_200 [512];
  
  uVar1 = FUN_10004260(&DAT_1000f170,0,param_1,param_4);
  wsprintfA(local_200,s__i_ms_1000e7a4,param_2);
  FUN_100042c0(&DAT_1000f170,uVar1,1,local_200);
  FUN_100042c0(&DAT_1000f170,uVar1,2,*(char **)(&DAT_1000e2dc + param_5 * 4));
  pcVar2 = &DAT_1000e79c;
  if (param_3 != 1) {
    pcVar2 = s_Playing_1000e794;
  }
  FUN_100042c0(&DAT_1000f170,uVar1,3,pcVar2);
  FUN_100044f0(&DAT_1000f170);
  DAT_1000f1d0 = DAT_1000f1d0 + 1;
  return;
}
