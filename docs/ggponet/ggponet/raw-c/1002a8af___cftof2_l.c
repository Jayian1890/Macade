
/* Library Function - Single Match
    __cftof2_l
   
   Library: Visual Studio 2008 Release */

undefined4 __cftof2_l(int param_1,size_t param_2,char param_3,localeinfo_struct *param_4)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int *piVar3;
  undefined4 uVar4;
  undefined1 *in_ECX;
  size_t sVar5;
  undefined1 *puVar6;
  int local_14 [2];
  int local_c;
  char local_8;
  
  iVar1 = in_EAX[1];
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)local_14,param_4);
  if ((in_ECX == (undefined1 *)0x0) || (param_1 == 0)) {
    piVar3 = __errno();
    uVar4 = 0x16;
    *piVar3 = 0x16;
    __invalid_parameter(0,0,0,0,0);
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
  }
  else {
    if ((param_3 != '\0') && (iVar1 - 1U == param_2)) {
      iVar2 = *in_EAX;
      in_ECX[(uint)(iVar2 == 0x2d) + (iVar1 - 1U)] = 0x30;
      (in_ECX + (uint)(iVar2 == 0x2d) + (iVar1 - 1U))[1] = 0;
    }
    if (*in_EAX == 0x2d) {
      *in_ECX = 0x2d;
      in_ECX = in_ECX + 1;
    }
    if (in_EAX[1] < 1) {
      __shift();
      *in_ECX = 0x30;
      puVar6 = in_ECX + 1;
    }
    else {
      puVar6 = in_ECX + in_EAX[1];
    }
    if (0 < (int)param_2) {
      __shift();
      *puVar6 = *(undefined1 *)**(undefined4 **)(local_14[0] + 0xbc);
      if (in_EAX[1] < 0) {
        sVar5 = -in_EAX[1];
        if ((param_3 != '\0') || ((int)sVar5 <= (int)param_2)) {
          param_2 = sVar5;
        }
        __shift();
        _memset(puVar6 + 1,0x30,param_2);
      }
    }
    if (local_8 != '\0') {
      *(uint *)(local_c + 0x70) = *(uint *)(local_c + 0x70) & 0xfffffffd;
    }
    uVar4 = 0;
  }
  return uVar4;
}
