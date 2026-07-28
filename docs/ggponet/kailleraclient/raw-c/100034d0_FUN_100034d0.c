
void __fastcall FUN_100034d0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    FUN_10002c20(piVar1);
    operator_delete(piVar1);
  }
  free(*(void **)(param_1 + 0x34));
  free(*(void **)(param_1 + 0x14));
  free(*(void **)(param_1 + 0x18));
  free(*(void **)(param_1 + 0x1c));
  free(*(void **)(param_1 + 0x20));
  free(*(void **)(param_1 + 0x40));
  free(*(void **)(param_1 + 0x3c));
  FUN_100034a0(param_1);
  return;
}
