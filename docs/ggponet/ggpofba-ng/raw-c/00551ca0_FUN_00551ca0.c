
void FUN_00551ca0(short *param_1,uint param_2)

{
  short *psVar1;
  short *psVar2;
  short *in_EAX;
  short sVar3;
  short *in_ECX;
  int iVar4;
  short *unaff_EBX;
  
  if (param_2 < 2) {
    __wassert(L"count >= 2",L"c:\\source\\main\\ggpofba2\\src\\interface\\scale3x.h",0x6f);
  }
  *in_ECX = *unaff_EBX;
  in_ECX[1] = *unaff_EBX;
  sVar3 = *in_EAX;
  if ((unaff_EBX[1] != sVar3) || (*param_1 == sVar3)) {
    sVar3 = *unaff_EBX;
  }
  in_ECX[2] = sVar3;
  iVar4 = param_2 - 2;
  while( true ) {
    psVar2 = in_ECX + 3;
    param_1 = param_1 + 1;
    in_EAX = in_EAX + 1;
    psVar1 = unaff_EBX + 1;
    if (iVar4 == 0) break;
    sVar3 = *in_EAX;
    if (((*unaff_EBX != sVar3) || (*param_1 == sVar3)) || (unaff_EBX[2] == sVar3)) {
      sVar3 = *psVar1;
    }
    *psVar2 = sVar3;
    in_ECX[4] = *psVar1;
    sVar3 = *in_EAX;
    if (((unaff_EBX[2] != sVar3) || (*param_1 == sVar3)) || (*unaff_EBX == sVar3)) {
      sVar3 = *psVar1;
    }
    in_ECX[5] = sVar3;
    iVar4 = iVar4 + -1;
    unaff_EBX = psVar1;
    in_ECX = psVar2;
  }
  sVar3 = *in_EAX;
  if ((*unaff_EBX == sVar3) && (*param_1 != sVar3)) {
    *psVar2 = sVar3;
    in_ECX[4] = *psVar1;
    in_ECX[5] = *psVar1;
    return;
  }
  *psVar2 = *psVar1;
  in_ECX[4] = *psVar1;
  in_ECX[5] = *psVar1;
  return;
}
