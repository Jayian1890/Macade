
void FUN_10025980(void *param_1,size_t param_2)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  undefined1 local_2c [8];
  undefined1 local_24 [8];
  uint local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xf0) + param_2;
  if (*(int *)(in_ECX + 0xf4) < local_8) {
    while (*(int *)(in_ECX + 0xf4) < local_8) {
      *(int *)(in_ECX + 0xf4) = *(int *)(in_ECX + 0xf4) << 1;
    }
    pvVar2 = _realloc(*(void **)(in_ECX + 0xec),*(size_t *)(in_ECX + 0xf4));
    *(void **)(in_ECX + 0xec) = pvVar2;
  }
  _memcpy((void *)(*(int *)(in_ECX + 0xec) + *(int *)(in_ECX + 0xf0)),param_1,param_2);
  *(size_t *)(in_ECX + 0xf0) = *(int *)(in_ECX + 0xf0) + param_2;
  while( true ) {
    if (*(int *)(in_ECX + 0xf0) < 4) {
      return;
    }
    local_14 = *(undefined4 **)(in_ECX + 0xec);
    local_10 = Ordinal_8(*local_14);
    if (*(int *)(in_ECX + 0xf0) < local_10) break;
    local_c = Ordinal_8(local_14[1]);
    if (local_c < 0) {
      FUN_10021ff0("Received event %d from server\n",local_c);
      local_1c = -local_c;
      if (local_1c < 0xe) {
        (*(code *)(&PTR_FUN_100332c4)[-local_c])(*(int *)(in_ECX + 0xec) + 8,local_10 + -4);
      }
    }
    else {
      uVar3 = FUN_10004c30(local_2c);
      FUN_10004c60(local_24,&local_c);
      cVar1 = FUN_10004d50(uVar3);
      if (cVar1 != '\0') {
        uVar3 = Ordinal_8(local_14[2]);
        iVar6 = local_10 + -8;
        iVar4 = *(int *)(in_ECX + 0xec) + 0xc;
        local_18 = uVar3;
        puVar5 = (undefined4 *)FUN_10004b10(&local_c);
        (*(code *)*puVar5)(uVar3,iVar4,iVar6);
      }
    }
    _memmove(*(void **)(in_ECX + 0xec),(void *)(*(int *)(in_ECX + 0xec) + 4 + local_10),
             (*(int *)(in_ECX + 0xf0) - local_10) - 4);
    *(int *)(in_ECX + 0xf0) = *(int *)(in_ECX + 0xf0) - (local_10 + 4);
  }
  return;
}
