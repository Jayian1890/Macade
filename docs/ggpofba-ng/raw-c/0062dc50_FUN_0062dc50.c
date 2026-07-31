
void FUN_0062dc50(void)

{
  HANDLE pvVar1;
  BOOL BVar2;
  char *in_ECX;
  DWORD dwPriorityClass;
  int iVar3;
  undefined4 local_230;
  undefined4 local_22c;
  int local_228;
  code *local_224;
  code *local_220;
  code *local_21c;
  code *local_218;
  undefined1 *local_214;
  undefined1 *local_210;
  undefined1 *local_20c;
  undefined4 local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00871720 ^ (uint)&local_230;
  local_220 = (code *)0x0;
  local_21c = (code *)0x0;
  local_218 = (code *)0x0;
  local_214 = (undefined1 *)0x0;
  local_210 = (undefined1 *)0x0;
  local_20c = (undefined1 *)0x0;
  dwPriorityClass = 0x80;
  local_224 = (code *)0x0;
  local_22c = DAT_00873998;
  DAT_00ad74dc = 1;
  pvVar1 = GetCurrentProcess();
  BVar2 = SetPriorityClass(pvVar1,dwPriorityClass);
  if (BVar2 == 0) {
    iVar3 = 1;
    pvVar1 = GetCurrentThread();
    SetThreadPriority(pvVar1,iVar3);
  }
  local_224 = FUN_0062d6c0;
  local_21c = FUN_0062da50;
  local_220 = FUN_0062d900;
  local_218 = FUN_0062db30;
  local_214 = &LAB_0062dc40;
  local_210 = &LAB_0062d7c0;
  local_20c = &LAB_0062d540;
  iVar3 = _strncmp(in_ECX,"quark:served",0xc);
  if (iVar3 == 0) {
    FID_conflict__sscanf
              (in_ECX,"quark:served,%[^,],%[^,],%d,%d",local_104,local_204,&local_228,&local_22c);
    DAT_00b1a804 = ggpo_client_connect(&local_224,local_104,local_204,local_228);
  }
  else {
    iVar3 = _strncmp(in_ECX,"quark:direct",0xc);
    if (iVar3 == 0) {
      local_228 = iVar3;
      FID_conflict__sscanf
                (in_ECX,"quark:direct,%[^,],%d,%[^,],%d,%d,%d",local_204,&local_230,local_104,
                 &local_208,&local_228,&local_22c);
      DAT_00b1a804 = ggpo_start_session(&local_224,local_204,local_230,local_104,local_208,local_228
                                       );
    }
    else {
      iVar3 = _strncmp(in_ECX,"quark:synctest",0xe);
      if (iVar3 == 0) {
        FID_conflict__sscanf(in_ECX,"quark:synctest,%[^,],%d",local_204,&local_230);
        DAT_00b1a804 = ggpo_start_synctest(&local_224,local_204,local_230);
      }
      else {
        iVar3 = _strncmp(in_ECX,"quark:stream",0xc);
        if (iVar3 == 0) {
          FID_conflict__sscanf(in_ECX,"quark:stream,%[^,],%[^,],%d",local_104,local_204,&local_230);
          DAT_00b1a804 = ggpo_start_streaming(&local_224,local_104,local_204,local_230);
        }
        else {
          iVar3 = _strncmp(in_ECX,"quark:replay",0xc);
          if (iVar3 == 0) {
            DAT_00b1a804 = ggpo_start_replay(&local_224,in_ECX + 0xd);
          }
        }
      }
    }
  }
  FUN_0062ded0("Setting smoothing to %d.\n",local_22c);
  ggpo_set_frame_delay(DAT_00b1a804,local_22c);
  DAT_00b189d6 = 1;
  DAT_00b189d3 = 1;
  __security_check_cookie(local_4 ^ (uint)&local_230);
  return;
}
