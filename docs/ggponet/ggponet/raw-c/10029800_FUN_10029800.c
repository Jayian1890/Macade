
undefined4 FUN_10029800(int param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  int local_14;
  
  if (*(char *)(in_ECX + 0x22f8) != '\0') {
    switch(param_1) {
    case 6000:
      *(undefined1 *)(in_ECX + 0x22f9) = 1;
      *(undefined4 *)(in_ECX + 0x2304) = 0;
      *(undefined4 *)(in_ECX + 0x2308) = 0xffffffff;
      FUN_10001720();
      if (*(int *)(in_ECX + 0x22fc) != 0) {
        _free(*(void **)(in_ECX + 0x22fc));
        *(undefined4 *)(in_ECX + 0x22fc) = 0;
        *(undefined4 *)(in_ECX + 0x2300) = 0;
      }
      _memset((void *)(in_ECX + 0x2314),0,8);
      _memset((void *)(in_ECX + 0x230c),0,8);
      break;
    case 0x1772:
    case 0x1773:
    case 0x1774:
    case 0x1775:
      *(int **)(in_ECX + -0x3ab4 + param_1 * 4) = param_2;
      break;
    case 0x1776:
    case 0x1777:
    case 0x1778:
    case 0x1779:
      *(int **)(in_ECX + -0x3acc + param_1 * 4) = param_2;
      break;
    case 0x177a:
      *(int **)(in_ECX + 0x2308) = param_2;
      break;
    case 0x177b:
      if (param_2 == (int *)0x0) {
        local_14 = 0;
      }
      else {
        local_14 = *param_2;
      }
      if ((*(char *)(in_ECX + 0x22f9) != '\0') && (iVar1 = FUN_10001680(), iVar1 != 0)) {
        FUN_10029160();
        *(undefined1 *)(in_ECX + 0x22f9) = 0;
      }
      if (local_14 != 0) {
        FUN_10025320();
      }
    }
  }
  return 1;
}
