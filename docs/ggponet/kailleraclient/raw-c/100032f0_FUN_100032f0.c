
int __fastcall FUN_100032f0(void *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar1 = FUN_10003200((int)param_1);
  iVar3 = 0;
  local_4 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = FUN_100032a0(param_1,iVar3,0);
      if (iVar2 == -1) {
        return local_4;
      }
      if (((iVar2 == 0xd) || (iVar2 == 10)) &&
         (((iVar4 != 0xd && (iVar4 != 10)) || (iVar4 == iVar2)))) {
        local_4 = local_4 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar2;
    } while (iVar3 < iVar1);
  }
  return local_4;
}
