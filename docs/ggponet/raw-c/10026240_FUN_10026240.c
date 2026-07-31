
undefined4 FUN_10026240(void)

{
  int iVar1;
  undefined4 *local_28;
  undefined4 *local_c;
  int *local_8;
  
  while (local_8 = (int *)FUN_10026a00(), local_8 != (int *)0x0) {
    iVar1 = *local_8;
    if (iVar1 == 0) {
      iVar1 = FUN_100118ec(0x1104);
      if (iVar1 == 0) {
        local_28 = (undefined4 *)0x0;
      }
      else {
        local_28 = (undefined4 *)FUN_10004a40();
      }
      local_c = local_28;
      *local_28 = 1;
      FUN_10004ac0(&local_c);
    }
    else if (iVar1 == 1) {
      FUN_10021ff0("TcpProtocol got TCP connect event.  Negotiating version...\n");
      FUN_100261e0();
    }
    else if (iVar1 == 2) {
      FUN_10025980(local_8[1],local_8[2]);
      FUN_10012aa5(local_8[1]);
    }
    FUN_100117f8(local_8);
  }
  return 1;
}
