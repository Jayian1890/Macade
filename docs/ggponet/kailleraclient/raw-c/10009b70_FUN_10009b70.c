
void __fastcall FUN_10009b70(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_1000cd88;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  local_4 = 0;
  if (0 < (int)param_1[1]) {
    if ((int)param_1[1] < 1) goto LAB_10009bc8;
    do {
      puVar5 = *(undefined4 **)*param_1;
      if (puVar5 != (undefined4 *)0x0) {
        if ((void *)*puVar5 != (void *)0x0) {
          free((void *)*puVar5);
        }
        operator_delete(puVar5);
      }
LAB_10009bc8:
      puVar5 = (undefined4 *)*param_1;
      if ((puVar5 != (undefined4 *)0x0) && (0 < (int)param_1[1])) {
        iVar4 = param_1[1] + -1;
        param_1[1] = iVar4;
        puVar2 = puVar5;
        if (iVar4 != 0) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = puVar2[1];
            puVar5 = puVar5 + 1;
            puVar2 = puVar2 + 1;
          }
        }
        uVar1 = param_1[1];
        if (((uVar1 & 0x1f) == 0) && (uVar1 != 0)) {
          pvVar3 = realloc((void *)*param_1,uVar1 * 4);
          *param_1 = pvVar3;
        }
      }
    } while (0 < (int)param_1[1]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    free((void *)*param_1);
  }
  *unaff_FS_OFFSET = local_c;
  return;
}
