
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0045cf70(int param_1,char param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  FUN_0045d0e0();
  FUN_0045cdc0();
  DAT_00877258 = param_1;
  FUN_0045cc40();
  DAT_009eb5a0 = *(undefined4 *)((&PTR_PTR_008761f0)[DAT_00877258] + 0x34);
  FUN_0047a1d0();
  FUN_00476910(1);
  FUN_005602a0();
  FUN_0047b830();
  if (DAT_00ad74dc != 0) {
    DAT_00877260 = 0x100;
  }
  uVar1 = FUN_0045ce50();
  if (uVar1 != 0) {
    if ((uVar1 & 2) != 0) {
      FUN_0052e230();
      FUN_0052de10();
      DAT_00877260 = 0x100;
      (**(code **)((&PTR_PTR_008761f0)[DAT_00877258] + 0x54))();
      FUN_00463490();
      uVar2 = FUN_0052d560(2);
      FUN_0045f2f0(0x10000,0x2ee,uVar2);
      FUN_0045f500();
    }
    PostMessageA((HWND)0x0,0x8000,0,0);
    return 1;
  }
  DAT_00b1971c = FUN_0045cee0;
  DAT_00ad74c4 = 1;
  DAT_00ad74c8 = 0;
  if (DAT_00ad74dc == 0) {
    if (param_2 != '\0') {
      FUN_0046cb60(0);
      DAT_00ad74c8 = 1;
      FUN_00477210();
    }
  }
  else {
    FUN_00472140();
    FUN_004722f0();
  }
  DAT_00874f77 = 0xff;
  _DAT_00ad74e0 = 0;
  DAT_00ad74e4 = 0;
  DAT_00ad74d8 = 0;
  if (DAT_00b189ff == '\0') {
    _DAT_00ad74e0 = timeGetTime();
  }
  FUN_00551170();
  PostMessageA((HWND)0x0,0x8000,0,0);
  return 0;
}
