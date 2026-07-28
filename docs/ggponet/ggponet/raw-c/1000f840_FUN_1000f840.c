
void FUN_1000f840(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 in_DL;
  undefined1 unaff_BL;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(param_3 + 0x20))(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 4) = unaff_BL;
    *puVar1 = 0;
    *(undefined1 *)((int)puVar1 + 0x11) = in_DL;
    puVar1[5] = unaff_retaddr;
    puVar1[6] = param_1;
  }
  return;
}
