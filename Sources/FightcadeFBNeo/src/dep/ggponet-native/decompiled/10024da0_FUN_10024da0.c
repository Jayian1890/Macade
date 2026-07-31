
/* WARNING: Removing unreachable block (ram,0x10024fdd) */
/* WARNING: Removing unreachable block (ram,0x10024fe5) */

void FUN_10024da0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  char local_424 [1024];
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  local_24 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x24) != 0) {
    while( true ) {
      local_14 = 0;
      local_8 = 0;
      if (*(char *)(in_ECX + 0x35) == '\0') {
        local_1c = 0x1000;
        local_18 = in_ECX + 0x36;
        ResetEvent(*(HANDLE *)(in_ECX + 0x1c));
        iVar1 = WSARecv(*(undefined4 *)(in_ECX + 4),&local_1c,1,&local_14,&local_8,in_ECX + 0xc,0);
        local_c = (uint)(iVar1 != -1);
      }
      else {
        local_c = WSAGetOverlappedResult
                            (*(undefined4 *)(in_ECX + 4),in_ECX + 0xc,&local_14,0,&local_8);
      }
      if (local_c == 0) break;
      if (*(char *)(in_ECX + 0x34) == '\0') {
        (**(code **)**(undefined4 **)(in_ECX + 0x30))();
        *(undefined1 *)(in_ECX + 0x34) = 1;
      }
      local_10 = in_ECX + 0x36;
      (**(code **)(**(int **)(in_ECX + 0x30) + 4))(local_10,local_14);
      *(undefined1 *)(in_ECX + 0x35) = 0;
      uVar2 = FUN_10007990(local_14);
      FUN_10007b40(uVar2);
    }
    local_20 = Ordinal_111();
    if (local_20 < 0x3e4) {
code_r0x10024f43:
      _sprintf(local_424,"Assertion: %s @ %s:%d","FALSE && \"Unknown return value from WSARecv\"",
               "..\\source\\network\\udp.cpp",0x94);
      FUN_10024520(in_ECX,&DAT_100324d4,local_424);
      FUN_10024520(in_ECX,&DAT_100324d8);
      FUN_10024520(in_ECX,&DAT_100324dc);
      FUN_10024520(in_ECX,&DAT_100324e0);
      MessageBoxA((HWND)0x0,local_424,"GGPO Assertion Failed",0x1030);
                    /* WARNING: Subroutine does not return */
      _exit(1);
    }
    if (local_20 < 0x3e6) {
      *(undefined1 *)(in_ECX + 0x35) = 1;
    }
    else {
      if (local_20 != 0x2746) goto code_r0x10024f43;
      if (*(char *)(in_ECX + 0x34) != '\0') {
        (**(code **)(**(int **)(in_ECX + 0x30) + 8))();
        *(undefined1 *)(in_ECX + 0x34) = 0;
      }
      FUN_10024520(in_ECX,"Got WSAECONNRESET while polling old port %d.  Reconnecting\n",
                   *(undefined4 *)(in_ECX + 8));
      Ordinal_3(*(undefined4 *)(in_ECX + 4));
      FUN_100245b0(0);
    }
  }
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
  return;
}
