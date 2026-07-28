
uint __fastcall FUN_10001f10(void *param_1)

{
  undefined4 uVar1;
  undefined4 uStack_4;
  
  uStack_4 = (uint)param_1 & 0xffffff;
  uVar1 = FUN_10001dd0(param_1,(undefined4 *)((int)&uStack_4 + 3),1);
  return CONCAT31((int3)((uint)uVar1 >> 8),uStack_4._3_1_);
}
