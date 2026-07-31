
void FUN_10029c30(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_18;
  char *local_14;
  char *local_10;
  int local_c;
  undefined4 *local_8;
  
  local_8 = &local_18;
  do {
    puVar1 = (undefined4 *)FUN_100252c0();
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    switch(*puVar1) {
    case 0:
      uVar2 = FUN_100013c0();
      FUN_10026420(in_ECX + 0x1ad0,uVar2);
      local_18 = 0x1389;
      (**(code **)(in_ECX + 0x20))(local_8);
      break;
    case 1:
    case 10:
      FUN_10021ff0("Got disconnect event from TcpProtocol.\n");
      local_18 = 0x138e;
      (**(code **)(in_ECX + 0x20))(local_8);
      return;
    case 2:
      return;
    case 8:
      FUN_10028ac0(puVar1 + 1,puVar1[0x21],puVar1[0x22] == 0);
      *(bool *)(in_ECX + 0x22d4) = puVar1[0x22] == 0;
      *(bool *)(in_ECX + 0x22f8) = puVar1[0x22] == 0;
      FUN_100263e0(in_ECX + 0x1ad0);
      local_18 = 0x138a;
      (**(code **)(in_ECX + 0x20))(local_8);
      break;
    case 0xb:
      FUN_10011480(in_ECX + 0x1bd0,puVar1 + 1);
      FUN_10011480(in_ECX + 0x1cd0,puVar1 + 0x81);
      FUN_10011480(in_ECX + 0x1ed0,puVar1 + 0x101);
      *(undefined4 *)(in_ECX + 0x22d0) = puVar1[0x181];
      local_18 = 0x138b;
      local_14 = (char *)(in_ECX + 0x1bd0);
      local_10 = (char *)(in_ECX + 0x1cd0);
      local_c = in_ECX + 0x1ed0;
      (**(code **)(in_ECX + 0x20))(local_8);
      local_18 = 0x138c;
      local_14 = *(char **)(in_ECX + 0x22d0);
      (**(code **)(in_ECX + 0x20))(local_8);
      local_18 = 0x138d;
      local_14 = "System";
      local_10 = "Press \'T\' to chat...";
      (**(code **)(in_ECX + 0x20))(local_8);
      break;
    case 0xc:
      iVar3 = _strcmp((char *)(puVar1 + 1),(char *)(in_ECX + 0x1ad0));
      if (iVar3 != 0) {
        return;
      }
      local_18 = 0x138d;
      local_14 = (char *)(puVar1 + 0x21);
      local_10 = (char *)(puVar1 + 0x41);
      (**(code **)(in_ECX + 0x20))(local_8);
      return;
    case 0x10:
      *(undefined4 *)(in_ECX + 0x22d0) = puVar1[1];
      local_18 = 0x138c;
      local_14 = *(char **)(in_ECX + 0x22d0);
      (**(code **)(in_ECX + 0x20))(local_8);
      break;
    case 0x11:
      if (*(char *)(in_ECX + 0x22d4) == '\0') {
        return;
      }
      if (*(int *)(in_ECX + 0x22d8) != 0) {
        return;
      }
      *(undefined4 *)(in_ECX + 0x22d8) = 3;
      return;
    }
    if (puVar1 != (undefined4 *)0x0) {
      FUN_100014d0(1);
    }
  } while( true );
}
