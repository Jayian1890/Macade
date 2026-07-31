
/* WARNING: Removing unreachable block (ram,0x10024984) */

void FUN_10024750(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  char local_81c [1024];
  undefined4 local_41c;
  undefined4 local_418;
  char local_414 [1024];
  uint local_14;
  undefined4 local_10;
  int local_c;
  DWORD local_8;
  
  local_14 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = timeGetTime();
  while (cVar1 = FUN_10003e80(), cVar1 == '\0') {
    iVar2 = FUN_10007b80();
    local_10 = *(undefined4 *)(iVar2 + 4);
    if ((*(int *)(in_ECX + 0x1038) != 0) &&
       (piVar3 = (int *)FUN_10007b80(), (int)local_8 < *piVar3 + *(int *)(in_ECX + 0x1038))) break;
    if (*(int *)(in_ECX + 0x24) == 0) {
      _sprintf(local_414,"Assertion: %s @ %s:%d","_peer_addr.sin_addr.s_addr",
               "..\\source\\network\\udp.cpp",0xb8);
      FUN_10024520(in_ECX,&DAT_1003254c,local_414);
      FUN_10024520(in_ECX,&DAT_10032550);
      FUN_10024520(in_ECX,&DAT_10032554);
      FUN_10024520(in_ECX,&DAT_10032558);
      MessageBoxA((HWND)0x0,local_414,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    uVar4 = FUN_10007810(0,in_ECX + 0x20,0x10);
    local_c = Ordinal_20(*(undefined4 *)(in_ECX + 4),local_10,uVar4);
    if (local_c == -1) {
      local_41c = Ordinal_111();
      local_418 = 0x2736;
      _sprintf(local_81c,"Assertion: %s @ %s:%d","FALSE && \"Unknown error in sendto\"",
               "..\\source\\network\\udp.cpp",0xc0);
      FUN_10024520(in_ECX,&DAT_100325cc,local_81c);
      FUN_10024520(in_ECX,&DAT_100325d0);
      FUN_10024520(in_ECX,&DAT_100325d4);
      FUN_10024520(in_ECX,&DAT_100325d8);
      MessageBoxA((HWND)0x0,local_81c,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    *(int *)(in_ECX + 0x105c) = *(int *)(in_ECX + 0x105c) + 1;
    iVar2 = FUN_10007810();
    *(int *)(in_ECX + 0x1058) = iVar2 + *(int *)(in_ECX + 0x1058);
    FUN_10007bc0();
    FUN_100117f8(local_10);
  }
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}
