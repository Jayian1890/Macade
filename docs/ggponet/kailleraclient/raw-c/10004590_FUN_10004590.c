
void __fastcall FUN_10004590(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (0 < *(int *)(param_1 + 8)) {
    if (*(int *)(param_1 + 8) < 1) {
      pvVar3 = (void *)0x0;
      goto LAB_100045b0;
    }
    do {
      pvVar3 = (void *)**(undefined4 **)(param_1 + 4);
LAB_100045b0:
      free(pvVar3);
      puVar5 = *(undefined4 **)(param_1 + 4);
      if ((puVar5 != (undefined4 *)0x0) && (0 < *(int *)(param_1 + 8))) {
        iVar4 = *(int *)(param_1 + 8) + -1;
        *(int *)(param_1 + 8) = iVar4;
        puVar2 = puVar5;
        if (iVar4 != 0) {
          for (; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = puVar2[1];
            puVar5 = puVar5 + 1;
            puVar2 = puVar2 + 1;
          }
        }
        uVar1 = *(uint *)(param_1 + 8);
        if (((uVar1 & 0x1f) == 0) && (uVar1 != 0)) {
          pvVar3 = realloc(*(void **)(param_1 + 4),uVar1 * 4);
          *(void **)(param_1 + 4) = pvVar3;
        }
      }
    } while (0 < *(int *)(param_1 + 8));
  }
  iVar4 = *(int *)(param_1 + 0x10);
  while (0 < iVar4) {
    puVar5 = *(undefined4 **)(param_1 + 0xc);
    if ((puVar5 != (undefined4 *)0x0) && (0 < *(int *)(param_1 + 0x10))) {
      iVar4 = *(int *)(param_1 + 0x10) + -1;
      *(int *)(param_1 + 0x10) = iVar4;
      puVar2 = puVar5;
      if (iVar4 != 0) {
        for (; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar5 = puVar2[1];
          puVar5 = puVar5 + 1;
          puVar2 = puVar2 + 1;
        }
      }
      uVar1 = *(uint *)(param_1 + 0x10);
      if (((uVar1 & 0x1f) == 0) && (uVar1 != 0)) {
        pvVar3 = realloc(*(void **)(param_1 + 0xc),uVar1 << 2);
        *(void **)(param_1 + 0xc) = pvVar3;
      }
    }
    iVar4 = *(int *)(param_1 + 0x10);
  }
  return;
}
