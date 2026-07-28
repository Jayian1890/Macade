
void __fastcall FUN_10001060(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_1 = &PTR_FUN_1000d1d0;
  if (0 < (int)param_1[0x40a]) {
    puVar1 = param_1 + 0x20b;
    do {
      free((void *)*puVar1);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
    } while (iVar2 < (int)param_1[0x40a]);
  }
  iVar2 = 0;
  if (0 < (int)param_1[0x209]) {
    puVar1 = param_1 + 10;
    do {
      free((void *)*puVar1);
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
    } while (iVar2 < (int)param_1[0x209]);
  }
  FUN_100020d0(param_1);
  return;
}
