
void FUN_10027730(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  size_t _Size;
  int local_68 [2];
  void *local_60;
  int local_3c;
  int local_38;
  undefined4 local_34;
  void *local_30;
  size_t local_2c;
  undefined4 local_28 [7];
  uint local_c;
  int local_8;
  
  local_c = DAT_10037490 ^ (uint)&stack0xfffffffc;
  FUN_100202e0();
  uVar2 = FUN_10002810();
  FUN_10021ff0("End of frame(%d)...\n",uVar2);
  FUN_100273b0();
  if (*(char *)(in_ECX + 0x29d) == '\0') {
    iVar3 = FUN_10002810();
    local_8 = iVar3;
    if (iVar3 != 1) {
      puVar4 = (undefined4 *)(in_ECX + 0x324);
      puVar7 = local_28;
      for (iVar6 = 7; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      }
      local_38 = iVar3;
      iVar3 = FUN_1001fce0();
      local_2c = *(size_t *)(iVar3 + 4);
      local_30 = _malloc(local_2c);
      _Size = local_2c;
      puVar4 = (undefined4 *)FUN_1001fce0();
      _memcpy(local_30,(void *)*puVar4,_Size);
      iVar3 = FUN_1001fce0();
      local_34 = *(undefined4 *)(iVar3 + 0xc);
      FUN_100035c0(&local_38);
    }
    if (local_8 - *(int *)(in_ECX + 0x298) == *(int *)(in_ECX + 0x294)) {
      FUN_1001fef0(*(int *)(in_ECX + 0x298) + -1);
      *(undefined1 *)(in_ECX + 0x29d) = 1;
      while (cVar1 = FUN_10003e80(), cVar1 == '\0') {
        (**(code **)(in_ECX + 0x18))(0);
        piVar5 = (int *)FUN_100035a0();
        piVar8 = local_68;
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar8 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar8 = piVar8 + 1;
        }
        FUN_100035e0();
        if (local_68[0] != local_8) {
          FUN_10027440(in_ECX,"Frame number %d does not match saved frame number %d",local_68[0],
                       local_8);
        }
        iVar3 = FUN_1001fce0();
        local_3c = *(int *)(iVar3 + 0xc);
        if (local_68[1] != local_3c) {
          FUN_100274b0(local_68);
          FUN_10027440(in_ECX,"Checksum for frame %d does not match saved (%d != %d)",local_8,
                       local_3c,local_68[1]);
        }
        _printf("Checksum %08d for frame %d matches.\n",local_3c,local_68[0]);
        _free(local_60);
      }
      *(int *)(in_ECX + 0x298) = local_8;
      *(undefined1 *)(in_ECX + 0x29d) = 0;
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}
