
void FUN_10026d40(void)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_c = 0;
  do {
    if (4 < local_c) {
LAB_10026dbf:
      if (*(int *)(in_ECX + 0x58) == 0) {
        FUN_10026c00();
      }
      else {
        local_8 = 1;
        iVar1 = Ordinal_10(*(undefined4 *)(in_ECX + 0x14),0x8004667e,&local_8);
        if (iVar1 == -1) {
          uVar3 = Ordinal_111();
          FUN_10021ff0("Failed to make socket non-blocking: 0x%08x.\n",uVar3);
        }
        SetEvent(*(HANDLE *)(in_ECX + 0x2c));
      }
      return;
    }
    FUN_100264e0(local_c * 5 + *(int *)(in_ECX + 4),5);
    iVar1 = Ordinal_4(*(undefined4 *)(in_ECX + 0x14),in_ECX + 0x44,0x10);
    if (iVar1 != -1) {
      *(undefined4 *)(in_ECX + 0x58) = 1;
      FUN_10026c60();
      goto LAB_10026dbf;
    }
    DVar2 = GetLastError();
    FUN_10021ff0("tcp connection failed (%d)!  retrying...\n",DVar2);
    local_c = local_c + 1;
  } while( true );
}
