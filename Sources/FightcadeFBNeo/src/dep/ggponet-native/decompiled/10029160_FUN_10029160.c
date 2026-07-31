
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10029160(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  int local_1044;
  undefined4 local_1040 [2];
  undefined1 local_1038 [20];
  char local_1024 [4096];
  uint local_24;
  size_t local_20;
  int local_1c;
  void *local_18;
  int local_14;
  size_t local_10;
  void *local_c;
  size_t local_8;
  
  local_8 = 0x1002916d;
  local_24 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_14 = 0;
  iVar1 = FUN_10007af0();
  local_8 = *(size_t *)(iVar1 + 4);
  local_1c = FUN_10001680();
  local_10 = local_1c * local_8 + *(int *)(in_ECX + 0x2300);
  if (*(char *)(in_ECX + 0x1ad0) != '\0') {
    local_18 = _malloc(local_10);
    _memcpy(local_18,*(void **)(in_ECX + 0x22fc),*(size_t *)(in_ECX + 0x2300));
    local_14 = 0;
    while (iVar1 = FUN_10001680(), iVar1 != 0) {
      puVar2 = (undefined4 *)FUN_10007af0();
      puVar3 = local_1040;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      _memcpy((void *)((int)local_18 + local_14 * local_8 + *(int *)(in_ECX + 0x2300)),local_1038,
              local_8);
      local_14 = local_14 + 1;
      FUN_100016a0();
    }
    local_20 = FUN_1002a080();
    local_c = _malloc(local_20);
    FUN_1000b3c0(local_18,local_10,1);
    local_14 = 0;
    iVar1 = _sprintf(local_1024,"GGPOTV\n");
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"version\t0.20\n");
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"game\t%s\n",in_ECX + 0x1dd0);
    local_14 = iVar1 + local_14;
    if (*(char *)(in_ECX + 0x1bd0) != '\0') {
      iVar1 = _sprintf(local_1024 + local_14,"player 1 username\t%s\n",in_ECX + 0x1bd0);
      local_14 = iVar1 + local_14;
    }
    if (*(char *)(in_ECX + 0x1cd0) != '\0') {
      iVar1 = _sprintf(local_1024 + local_14,"player 2 username\t%s\n",in_ECX + 0x1cd0);
      local_14 = iVar1 + local_14;
    }
    for (local_1044 = 0; local_1044 < 2; local_1044 = local_1044 + 1) {
      if (*(int *)(in_ECX + 0x2314 + local_1044 * 4) != 0) {
        iVar1 = _sprintf(local_1024 + local_14,"player %d avatar\t%s\n",local_1044 + 1,
                         *(undefined4 *)(in_ECX + 0x2314 + local_1044 * 4));
        local_14 = iVar1 + local_14;
        iVar1 = _sprintf(local_1024 + local_14,"player %d score\t%d\n",local_1044 + 1,
                         *(undefined4 *)(in_ECX + 0x230c + local_1044 * 4));
        local_14 = iVar1 + local_14;
      }
    }
    iVar1 = _sprintf(local_1024 + local_14,"series\t%s\n",in_ECX + 0x1ad0);
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"winner\t%d\n",*(undefined4 *)(in_ECX + 0x2308));
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"input size\t%d\n",local_8);
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"input count\t%d\n",local_1c);
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"state size\t%d\n",*(undefined4 *)(in_ECX + 0x2300));
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"compressed state size\t%d\n",local_20);
    local_14 = iVar1 + local_14;
    iVar1 = _sprintf(local_1024 + local_14,"payload size\t%d\n",local_10);
    local_14 = iVar1 + local_14 + 1;
    FUN_10025c90(in_ECX + 0x1ad0,local_1024,local_c,local_20);
    _free(local_18);
    _free(local_c);
  }
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffffc);
  return;
}
