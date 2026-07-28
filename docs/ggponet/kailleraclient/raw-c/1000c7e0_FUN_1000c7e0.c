
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000c7e0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  
  if (param_2 == 0) {
    if (0 < DAT_1000f440) {
      DAT_1000f440 = DAT_1000f440 + -1;
      goto LAB_1000c7f6;
    }
LAB_1000c81e:
    uVar1 = 0;
  }
  else {
LAB_1000c7f6:
    _DAT_1000f444 = *(undefined4 *)_adjust_fdiv_exref;
    if (param_2 == 1) {
      DAT_1000f450 = malloc(0x80);
      if (DAT_1000f450 == (undefined4 *)0x0) goto LAB_1000c81e;
      *DAT_1000f450 = 0;
      DAT_1000f44c = DAT_1000f450;
      initterm(&DAT_1000e000,&DAT_1000e054);
      DAT_1000f440 = DAT_1000f440 + 1;
    }
    else if ((param_2 == 0) &&
            (_Memory = DAT_1000f450, puVar2 = DAT_1000f44c, DAT_1000f450 != (undefined4 *)0x0)) {
      while (puVar2 = puVar2 + -1, _Memory <= puVar2) {
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)();
          _Memory = DAT_1000f450;
        }
      }
      free(_Memory);
      DAT_1000f450 = (undefined4 *)0x0;
    }
    uVar1 = 1;
  }
  return uVar1;
}
