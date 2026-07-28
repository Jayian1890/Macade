
void FUN_00551d90(int *param_1,uint param_2)

{
  int *in_EAX;
  int *in_ECX;
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  
  if (param_2 < 2) {
    __wassert(L"count >= 2",L"c:\\source\\main\\ggpofba2\\src\\interface\\scale3x.h",0xaa);
  }
  *in_ECX = *unaff_EBX;
  in_ECX[1] = *unaff_EBX;
  iVar2 = *in_EAX;
  if ((unaff_EBX[1] != iVar2) || (*param_1 == iVar2)) {
    iVar2 = *unaff_EBX;
  }
  in_ECX[2] = iVar2;
  iVar2 = param_2 - 2;
  while( true ) {
    in_ECX = in_ECX + 3;
    param_1 = param_1 + 1;
    in_EAX = in_EAX + 1;
    unaff_EBX = unaff_EBX + 1;
    if (iVar2 == 0) break;
    iVar1 = *in_EAX;
    if (((unaff_EBX[-1] != iVar1) || (*param_1 == iVar1)) || (unaff_EBX[1] == iVar1)) {
      iVar1 = *unaff_EBX;
    }
    *in_ECX = iVar1;
    in_ECX[1] = *unaff_EBX;
    iVar1 = *in_EAX;
    if (((unaff_EBX[1] != iVar1) || (*param_1 == iVar1)) || (unaff_EBX[-1] == iVar1)) {
      iVar1 = *unaff_EBX;
    }
    in_ECX[2] = iVar1;
    iVar2 = iVar2 + -1;
  }
  iVar2 = *in_EAX;
  if ((unaff_EBX[-1] == iVar2) && (*param_1 != iVar2)) {
    *in_ECX = iVar2;
    in_ECX[1] = *unaff_EBX;
    in_ECX[2] = *unaff_EBX;
    return;
  }
  *in_ECX = *unaff_EBX;
  in_ECX[1] = *unaff_EBX;
  in_ECX[2] = *unaff_EBX;
  return;
}
