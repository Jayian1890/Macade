
undefined4 FUN_10026830(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int local_1c;
  int local_18;
  int *local_14;
  int local_10;
  undefined1 local_c [4];
  int local_8;
  
  FUN_10021ff0("Send event got hot...\n");
  while( true ) {
    if (*(int *)(in_ECX + 0x58) == 0) {
      return 1;
    }
    cVar1 = FUN_10003e80();
    if (cVar1 != '\0') break;
    local_8 = 0;
    local_14 = (int *)FUN_10003ea0();
    uVar2 = FUN_10008a70(local_14[2],local_14[1]);
    FUN_10021ff0("%d items in send queue (first of length %d offset %d)\n",uVar2);
    if (*(int *)(in_ECX + 0x60) == 0) {
      FUN_10021ff0("Sending buffer...\n");
      local_1c = local_14[2] - local_14[1];
      local_18 = *local_14 + local_14[1];
      local_10 = WSASend(*(undefined4 *)(in_ECX + 0x14),&local_1c,1,&local_8,0,in_ECX + 0x30,0);
    }
    else {
      FUN_10021ff0("Checking result...\n");
      local_10 = WSAGetOverlappedResult
                           (*(undefined4 *)(in_ECX + 0x14),in_ECX + 0x30,&local_8,0,local_c);
    }
    if ((local_10 == -1) && (iVar3 = Ordinal_111(), iVar3 == 0x3e5)) {
      FUN_10021ff0("Setting pending...\n");
      *(undefined4 *)(in_ECX + 0x60) = 1;
      return 1;
    }
    ResetEvent(*(HANDLE *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x60) = 0;
    local_14[1] = local_14[1] + local_8;
    FUN_10021ff0("Got %d bytes.  Offset is now %d (of %d).  Result was %d\n",local_8,local_14[1],
                 local_14[2],local_10);
    if (local_14[1] == local_14[2]) {
      FUN_10021ff0("Removing entry...\n");
      _free((void *)*local_14);
      FUN_10003f00();
    }
  }
  return 1;
}
