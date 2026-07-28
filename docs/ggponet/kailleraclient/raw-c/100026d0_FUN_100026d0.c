
void __fastcall FUN_100026d0(undefined4 *param_1)

{
  param_1[2] = 1;
  if ((HANDLE)param_1[3] != (HANDLE)0x0) {
    WaitForSingleObject((HANDLE)param_1[3],0xffffffff);
    CloseHandle((HANDLE)param_1[3]);
  }
  free((void *)*param_1);
  return;
}
