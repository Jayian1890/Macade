
/* Library Function - Single Match
    ___free_lconv_num
   
   Library: Visual Studio 2008 Release */

void ___free_lconv_num(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_10038328) {
      _free((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_1003832c) {
      _free((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_10038330) {
      _free((undefined *)param_1[2]);
    }
  }
  return;
}
