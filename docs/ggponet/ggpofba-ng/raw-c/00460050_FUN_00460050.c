
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT FUN_00460050(HWND param_1,uint param_2,uint param_3,HMENU param_4)

{
  LRESULT LVar1;
  short sVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_c;
  
  sVar2 = (short)((uint)param_4 >> 0x10);
  if (param_2 < 0x112) {
    if (param_2 == 0x111) {
      if (DAT_00b1ad0c == '\0') {
        FUN_004608e0(param_3 & 0xffff,param_3 >> 0x10);
      }
      return 0;
    }
    switch(param_2) {
    case 1:
      return 0;
    case 2:
      FUN_00551170();
      DAT_00ad7508 = (HWND)0x0;
      return 0;
    case 5:
      if (param_3 != 1) {
        FUN_00462ce0(param_3,(int)sVar2);
        return 0;
      }
      DAT_009e6c76 = 0;
      return 0;
    case 0xf:
      if (param_1 == DAT_00ad7508) {
        FUN_004608a0();
      }
      break;
    case 0x10:
      PostQuitMessage(0);
      return 0;
    case 0x1c:
      FUN_004607c0(param_1);
      return 0;
    case 0x4e:
      LVar1 = FUN_00463af0();
      return LVar1;
    case 0x7e:
      if (DAT_00b19814 != 0) {
        return 0;
      }
      goto LAB_0046025d;
    }
    goto switchD_0046008f_caseD_3;
  }
  if (0x211 < param_2) {
    if (param_2 == 0x212) {
      if (DAT_00ad7517 == '\0') {
        FUN_004798e0();
      }
    }
    else {
      if (param_2 == 0x231) {
        FUN_00462db0();
        return 0;
      }
      if (param_2 == 0x232) {
        FUN_00462e00();
        return 0;
      }
    }
    goto switchD_0046008f_caseD_3;
  }
  if (param_2 == 0x211) {
    FUN_00462ef0();
    return 0;
  }
  switch(param_2) {
  case 0x112:
    if (param_3 - 0xf090 < 0xe1) {
      uVar4 = FUN_00462bb0();
      param_1 = (HWND)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 != 0) {
        return 0;
      }
    }
    break;
  case 0x117:
    if ((uint)param_4 >> 0x10 == 0) {
      FUN_00463b90(param_3);
    }
    break;
  case 0x11f:
    local_c = param_3 >> 0x10;
    if ((short)(param_3 >> 0x10) == -1) {
      local_c = 0xffffffff;
    }
    uVar3 = param_3 >> 0x10 & 0x10;
    if (uVar3 != 0) {
      GetSubMenu(param_4,param_3 & 0xffff);
    }
    if ((short)uVar3 == 0) {
      _DAT_009e6d98 = param_3 & 0xffff;
      _DAT_009e6d90 = local_c;
      return 0;
    }
    _DAT_009e6d98 = 0;
    _DAT_009e6d90 = local_c;
    return 0;
  case 0x121:
    FUN_00462eb0();
    return 0;
  case 0x125:
    if (1 < DAT_00899744) {
      DAT_00899744 = DAT_00899744 + -1;
      return 0;
    }
    FUN_00463be0();
    return 0;
  case 0x200:
    FUN_004605f0(param_1,(int)(short)param_4,(int)sVar2,param_3);
    return 0;
  case 0x201:
    if (param_1 == DAT_00ad7508) {
      FUN_00460580((int)(short)param_4,(int)sVar2);
    }
    return 0;
  case 0x202:
    FUN_00460720();
    return 0;
  case 0x204:
    if (param_1 != DAT_00ad7508) {
      return 0;
    }
    if (DAT_00b19814 != 0) {
      return 0;
    }
    DAT_0087726b = DAT_0087726b == '\0';
    goto LAB_0046025d;
  case 0x206:
    if (param_1 != DAT_00ad7508) {
      return 0;
    }
    if (DAT_00ad74c4 == 0) {
      return 0;
    }
    DAT_00b19814 = (uint)(DAT_00b19814 == 0);
LAB_0046025d:
    PostMessageA((HWND)0x0,0x8000,0,0);
    return 0;
  }
switchD_0046008f_caseD_3:
  LVar1 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
  return LVar1;
}
