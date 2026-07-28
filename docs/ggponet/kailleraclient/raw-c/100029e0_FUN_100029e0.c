
void __fastcall FUN_100029e0(LPVOID param_1)

{
  HANDLE pvVar1;
  LPVOID local_4;
  
  if (*(int *)((int)param_1 + 8) != 0) {
    local_4 = param_1;
    if (*(HANDLE *)((int)param_1 + 0xc) != (HANDLE)0x0) {
      WaitForSingleObject(*(HANDLE *)((int)param_1 + 0xc),0xffffffff);
      CloseHandle(*(HANDLE *)((int)param_1 + 0xc));
    }
    *(undefined4 *)((int)param_1 + 8) = 0;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_10002710,param_1
                          ,0,(LPDWORD)&local_4);
    *(HANDLE *)((int)param_1 + 0xc) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      *(undefined4 *)((int)param_1 + 8) = 1;
    }
  }
  return;
}
