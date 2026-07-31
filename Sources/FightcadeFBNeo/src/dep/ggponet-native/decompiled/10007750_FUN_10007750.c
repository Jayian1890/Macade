
void FUN_10007750(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  
  if (param_1 != param_2) {
    uVar1 = *param_1;
    *param_1 = *param_2;
    *param_2 = uVar1;
  }
  return;
}
