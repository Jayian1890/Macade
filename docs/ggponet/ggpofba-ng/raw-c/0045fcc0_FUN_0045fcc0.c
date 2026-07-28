
void FUN_0045fcc0(void)

{
  void *_Memory;
  undefined1 **ppuStack_b0;
  undefined1 auStack_a8 [4];
  char *local_a4;
  void *local_a0;
  undefined1 *local_9c;
  undefined1 *local_98;
  undefined1 *local_94;
  undefined4 local_90;
  char local_8c [124];
  uint uStack_10;
  uint local_8;
  
  local_8 = DAT_00871720 ^ (uint)auStack_a8;
  if (DAT_00ad74c4 != 0) {
    ppuStack_b0 = (undefined1 **)0x45fce3;
    FUN_0045d0e0();
    ppuStack_b0 = (undefined1 **)0x45fce8;
    FUN_00463490();
  }
  ppuStack_b0 = (undefined1 **)0x45fced;
  FUN_00465610();
  ppuStack_b0 = (undefined1 **)&DAT_00ad734c;
  __snprintf(local_8c,0x80,"FB Alpha v%.20s");
  ppuStack_b0 = (undefined1 **)0x45fd0e;
  _Memory = (void *)FUN_0045f5f0();
  ppuStack_b0 = &local_a4;
  local_a4 = local_8c;
  local_9c = &LAB_0045f7c0;
  local_98 = &LAB_0045fb50;
  local_94 = &LAB_0045fbc0;
  local_90 = 0;
  local_a0 = _Memory;
  kailleraSetInfos();
  kailleraSelectServerDialog(0);
  _free(_Memory);
  PostMessageA((HWND)0x0,0x8000,0,0);
  __security_check_cookie(uStack_10 ^ (uint)&ppuStack_b0);
  return;
}
