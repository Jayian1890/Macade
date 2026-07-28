
void __thiscall FUN_10004260(void *this,undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_28;
  undefined4 local_24 [4];
  char *local_14;
  int local_10;
  undefined4 local_8;
  
  puVar4 = local_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  local_24[0] = param_1;
  uVar3 = 0xffffffff;
  local_14 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *param_2;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  local_10 = ~uVar3 - 1;
  local_8 = param_3;
  local_28 = 5;
  SendMessageA(*(HWND *)this,0x1007,0,(LPARAM)&local_28);
  return;
}
