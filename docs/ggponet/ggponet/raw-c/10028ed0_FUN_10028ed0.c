
undefined4 FUN_10028ed0(DWORD param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  size_t local_10;
  void *local_c;
  undefined4 *local_8;
  
  local_8 = &local_20;
  FUN_10028090(0);
  while (puVar1 = (undefined4 *)FUN_100252c0(), puVar1 != (undefined4 *)0x0) {
    switch(*puVar1) {
    case 0:
      FUN_10021ff0("TcpProtocol connected.\n");
      FUN_10026340(in_ECX + 0x46c);
      FUN_100263e0(in_ECX + 0x46c);
      break;
    case 2:
      return 0;
    case 10:
      local_20 = 0x138e;
      (**(code **)(in_ECX + 0x20))(local_8);
      return 0;
    case 0xb:
      FUN_10011480(in_ECX + 0x56c,puVar1 + 1);
      FUN_10011480(in_ECX + 0x66c,puVar1 + 0x81);
      FUN_10011480(in_ECX + 0x76c,puVar1 + 0x101);
      *(undefined4 *)(in_ECX + 0xb6c) = puVar1[0x181];
      local_20 = 0x138b;
      local_1c = in_ECX + 0x56c;
      local_18 = in_ECX + 0x66c;
      local_14 = in_ECX + 0x76c;
      (**(code **)(in_ECX + 0x20))(local_8);
      local_20 = 0x138c;
      local_1c = *(undefined4 *)(in_ECX + 0xb6c);
      (**(code **)(in_ECX + 0x20))(local_8);
      break;
    case 0xe:
      FUN_10002de0(puVar1 + 1);
      break;
    case 0xf:
      local_10 = puVar1[3];
      local_c = _malloc(local_10);
      FUN_1000b460(puVar1[1],puVar1[2]);
      (**(code **)(in_ECX + 0x10))(local_c,local_10);
      _free(local_c);
      break;
    case 0x10:
      *(undefined4 *)(in_ECX + 0xb6c) = puVar1[1];
      local_20 = 0x138c;
      local_1c = *(undefined4 *)(in_ECX + 0xb6c);
      (**(code **)(in_ECX + 0x20))(local_8);
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100014d0(1);
    }
  }
  Sleep(param_1);
  return 1;
}
