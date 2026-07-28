
void __cdecl FUN_10008320(char *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  CHAR local_100 [256];
  
  uVar1 = FUN_10004260(&DAT_1000f188,0,param_1,param_3);
  wsprintfA(local_100,s__i_ms_1000e7a4,param_2);
  FUN_100042c0(&DAT_1000f188,uVar1,1,local_100);
  FUN_100042c0(&DAT_1000f188,uVar1,2,*(char **)(&DAT_1000e2dc + param_4 * 4));
  return;
}
