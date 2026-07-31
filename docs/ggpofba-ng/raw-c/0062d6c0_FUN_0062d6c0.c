
void FUN_0062d6c0(byte *param_1)

{
  byte bVar1;
  HANDLE pvVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 auStack_25c [4];
  _WIN32_FIND_DATAA local_258;
  char local_118 [268];
  uint local_c;
  
  local_c = DAT_00871720 ^ (uint)auStack_25c;
  DAT_00b189ca = 1;
  _sprintf(local_118,"savestates\\%s_ggpo.fs",param_1);
  pvVar2 = FindFirstFileA(local_118,&local_258);
  if (pvVar2 == (HANDLE)0xffffffff) {
    uVar5 = 0;
    if (DAT_00b196f8 != 0) {
      do {
        DAT_00877258 = uVar5;
        pbVar3 = (byte *)FUN_0052d560(0);
        pbVar6 = param_1;
        do {
          bVar1 = *pbVar3;
          bVar7 = bVar1 < *pbVar6;
          if (bVar1 != *pbVar6) {
LAB_0062d786:
            iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
            goto LAB_0062d78b;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar3[1];
          bVar7 = bVar1 < pbVar6[1];
          if (bVar1 != pbVar6[1]) goto LAB_0062d786;
          pbVar3 = pbVar3 + 2;
          pbVar6 = pbVar6 + 2;
        } while (bVar1 != 0);
        iVar4 = 0;
LAB_0062d78b:
        if (iVar4 == 0) {
          FUN_0045cc40();
          FUN_0045cf70(uVar5,1);
          __security_check_cookie(local_c ^ (uint)auStack_25c);
          return;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < DAT_00b196f8);
    }
  }
  else {
    FUN_00474e10(1);
  }
  _sprintf(&DAT_00b1a930,(char *)param_1);
  __security_check_cookie(local_c ^ (uint)auStack_25c);
  return;
}
