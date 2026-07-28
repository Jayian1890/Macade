
undefined4 __thiscall FUN_10003350(void *this,undefined1 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)((int)this + 0x1c) < param_2) {
    param_2 = *(int *)((int)this + 0x1c);
  }
  while( true ) {
    if (param_2 == 0) {
      return 1;
    }
    iVar1 = FUN_100032a0(this,0,1);
    if (iVar1 == -1) break;
    if ((iVar1 == 0xd) || (iVar1 == 10)) {
      iVar2 = FUN_100032a0(this,0,0);
      if (((iVar2 == 0xd) || (iVar2 == 10)) && (iVar2 != iVar1)) {
        FUN_100032a0(this,0,1);
      }
      break;
    }
    *param_1 = (char)iVar1;
    param_1 = param_1 + 1;
    param_2 = param_2 + -1;
  }
  *param_1 = 0;
  return 0;
}
