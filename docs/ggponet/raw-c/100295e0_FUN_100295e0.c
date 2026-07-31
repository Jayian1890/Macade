
void FUN_100295e0(int *param_1)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  void *local_1c;
  size_t local_18;
  void *local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  FUN_100013e0(param_1);
  if (*param_1 == 0) {
    if (*(char *)(in_ECX + 0x22d4) != '\0') {
      local_8 = param_1 + 1;
      FUN_100016e0(local_8);
      iVar1 = FUN_10001680();
      if (iVar1 == 0x3c) {
        if (0 < *(int *)(in_ECX + 0x22d0)) {
          FUN_10025e90(in_ECX + 0x1ad0,in_ECX + 0x22dc);
        }
        FUN_10001720();
        if ((*(int *)(in_ECX + 0x22d8) != 0) &&
           (*(int *)(in_ECX + 0x22d8) = *(int *)(in_ECX + 0x22d8) + -1,
           *(int *)(in_ECX + 0x22d8) == 0)) {
          FUN_10020310(*local_8,&local_10,&local_c);
          local_18 = FUN_1002a080();
          local_14 = _malloc(local_18);
          FUN_1000b3c0(local_10,local_c,1);
          FUN_10025da0(in_ECX + 0x1ad0,local_14,local_18,local_c);
          _free(local_14);
        }
      }
    }
    if ((*(char *)(in_ECX + 0x22f8) != '\0') && (*(char *)(in_ECX + 0x22f9) != '\0')) {
      if (*(int *)(in_ECX + 0x2304) == 0) {
        *(int *)(in_ECX + 0x2304) = param_1[1];
        FUN_10020310(*(undefined4 *)(in_ECX + 0x2304),&local_1c,in_ECX + 0x2300);
        pvVar2 = _malloc(*(size_t *)(in_ECX + 0x2300));
        *(void **)(in_ECX + 0x22fc) = pvVar2;
        _memcpy(*(void **)(in_ECX + 0x22fc),local_1c,*(size_t *)(in_ECX + 0x2300));
      }
      FUN_100016e0(param_1 + 1);
    }
  }
  return;
}
