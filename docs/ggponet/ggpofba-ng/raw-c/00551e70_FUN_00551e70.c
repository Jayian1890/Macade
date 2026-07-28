
void FUN_00551e70(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined2 *in_EAX;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 unaff_EDI;
  
  uVar1 = DAT_00b1997c;
  if (DAT_00b1997c < 2) {
    __wassert(L"count >= 2",L"c:\\source\\main\\ggpofba2\\src\\interface\\scale3x.h",0x108);
  }
  FUN_00551ca0(unaff_EDI,uVar1);
  if (uVar1 != 0) {
    puVar2 = (undefined2 *)(param_2 + 4);
    uVar3 = uVar1;
    do {
      puVar2[-2] = *in_EAX;
      puVar2[-1] = *in_EAX;
      *puVar2 = *in_EAX;
      in_EAX = in_EAX + 1;
      puVar2 = puVar2 + 3;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  FUN_00551ca0(param_4,uVar1);
  return;
}
