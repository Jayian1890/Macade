
void FUN_100245b0(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  uint local_8;
  
  local_8 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  bVar1 = false;
  *(undefined1 *)(in_ECX + 0x35) = 0;
  uVar2 = Ordinal_23(2,2,0);
  *(undefined4 *)(in_ECX + 4) = uVar2;
  local_18 = 2;
  local_14 = Ordinal_8(0);
  local_1c = *(uint *)(in_ECX + 8);
  do {
    if (*(int *)(in_ECX + 8) + param_1 < (int)local_1c) {
LAB_1002467d:
      if (bVar1) {
        if (*(int *)(in_ECX + 0x24) != 0) {
          FUN_10024520(in_ECX,"Re-priming socket for port %d.\n",*(undefined4 *)(in_ECX + 8));
          SetEvent(*(HANDLE *)(in_ECX + 0x1c));
        }
      }
      else {
        Ordinal_3(*(undefined4 *)(in_ECX + 4));
        *(undefined4 *)(in_ECX + 4) = 0xffffffff;
      }
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_16 = Ordinal_9(local_1c & 0xffff);
    iVar3 = Ordinal_2(*(undefined4 *)(in_ECX + 4),&local_18,0x10);
    if (iVar3 != -1) {
      *(uint *)(in_ECX + 8) = local_1c;
      bVar1 = true;
      FUN_10024520(in_ECX,"Udp bound to port: %d.\n",*(undefined4 *)(in_ECX + 8));
      goto LAB_1002467d;
    }
    FUN_10024520(in_ECX,"Could not bind to port %d.  Retrying.\n",local_1c);
    local_1c = local_1c + 1;
  } while( true );
}
