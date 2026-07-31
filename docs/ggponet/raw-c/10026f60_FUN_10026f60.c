
undefined4 FUN_10026f60(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  undefined4 local_8;
  
  while( true ) {
    if (*(int *)(in_ECX + 0x58) == 0) {
      return 1;
    }
    local_10 = 0;
    local_8 = 0;
    if (*(int *)(in_ECX + 0x5c) == 0) {
      if (*(int *)(in_ECX + 0x54) == 0) {
        uVar1 = FUN_10010cc0(0x400);
        *(undefined4 *)(in_ECX + 0x54) = uVar1;
      }
      local_18 = 0x400;
      local_14 = *(undefined4 *)(in_ECX + 0x54);
      ResetEvent(*(HANDLE *)(in_ECX + 0x2c));
      iVar2 = WSARecv(*(undefined4 *)(in_ECX + 0x14),&local_18,1,&local_10,&local_8,in_ECX + 0x1c,0)
      ;
      local_c = (uint)(iVar2 != -1);
    }
    else {
      local_c = WSAGetOverlappedResult
                          (*(undefined4 *)(in_ECX + 0x14),in_ECX + 0x1c,&local_10,0,&local_8);
    }
    if (local_c == 0) break;
    if (local_10 == 0) {
      FUN_10026c00();
      ResetEvent(*(HANDLE *)(in_ECX + 0x2c));
      *(undefined4 *)(in_ECX + 0x58) = 0;
      return 1;
    }
    FUN_10026cc0(local_10);
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  uVar3 = Ordinal_111();
  if (0x3e3 < uVar3) {
    if (uVar3 < 0x3e6) {
      *(undefined4 *)(in_ECX + 0x5c) = 1;
      return 1;
    }
    if (uVar3 == 0x2746) {
      local_10 = 0;
      FUN_10021ff0("Got WSAECONNRESET in Recv.\n");
      return 1;
    }
  }
  local_10 = 0;
  FUN_10021ff0("Unknown error from WSARecv 0x%08x.\n",uVar3);
  return 1;
}
