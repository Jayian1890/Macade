
void FUN_0062ded0(char *param_1)

{
  char local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00871720 ^ (uint)local_404;
  _vsprintf(local_404,param_1,&stack0x00000008);
  ggpo_logv(DAT_00b1a804,param_1,&stack0x00000008);
  __security_check_cookie(local_4 ^ (uint)local_404);
  return;
}
