
bool FUN_10028090(DWORD param_1)

{
  char cVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  DWORD *in_ECX;
  bool local_3c;
  bool local_38;
  bool local_34;
  DWORD local_2c;
  bool local_15;
  uint local_10;
  
  local_15 = false;
  if (*in_ECX == 0) {
    DVar2 = timeGetTime();
    *in_ECX = DVar2;
  }
  DVar2 = timeGetTime();
  iVar3 = DVar2 - *in_ECX;
  local_2c = FUN_10027ff0(iVar3);
  if (local_2c != 0xffffffff) {
    if ((int)param_1 < (int)local_2c) {
      local_2c = param_1;
    }
    param_1 = local_2c;
  }
  DVar2 = WaitForMultipleObjects(in_ECX[1],(HANDLE *)(in_ECX + 2),0,param_1);
  if (DVar2 < in_ECX[1]) {
    cVar1 = (*(code *)**(undefined4 **)in_ECX[DVar2 * 2 + 0x42])(in_ECX[DVar2 * 2 + 0x43]);
    local_15 = cVar1 == '\0';
  }
  for (local_10 = 0; uVar4 = FUN_10008d70(), local_10 < uVar4; local_10 = local_10 + 1) {
    puVar5 = (undefined4 *)FUN_10008d90(local_10);
    cVar1 = (**(code **)(*(int *)*puVar5 + 4))(puVar5[1]);
    if ((cVar1 == '\0') || (local_15 != false)) {
      local_34 = true;
    }
    else {
      local_34 = false;
    }
    local_15 = local_34;
  }
  for (local_10 = 0; uVar4 = FUN_10008eb0(), local_10 < uVar4; local_10 = local_10 + 1) {
    puVar5 = (undefined4 *)FUN_10008ed0(local_10);
    if ((int)(puVar5[2] + puVar5[3]) <= iVar3) {
      puVar5[3] = (iVar3 / (int)puVar5[2]) * puVar5[2];
      cVar1 = (**(code **)(*(int *)*puVar5 + 8))(puVar5[1],puVar5[3]);
      if ((cVar1 == '\0') || (local_15 != false)) {
        local_38 = true;
      }
      else {
        local_38 = false;
      }
      local_15 = local_38;
    }
  }
  for (local_10 = 0; uVar4 = FUN_10008d70(), local_10 < uVar4; local_10 = local_10 + 1) {
    puVar5 = (undefined4 *)FUN_10008d90(local_10);
    cVar1 = (**(code **)(*(int *)*puVar5 + 0xc))(puVar5[1]);
    if ((cVar1 == '\0') || (local_15 != false)) {
      local_3c = true;
    }
    else {
      local_3c = false;
    }
    local_15 = local_3c;
  }
  return local_15;
}
