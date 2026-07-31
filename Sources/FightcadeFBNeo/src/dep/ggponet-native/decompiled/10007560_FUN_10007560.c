
undefined4 FUN_10007560(undefined4 param_1)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  while( true ) {
    puVar1 = (undefined4 *)FUN_100086e0(param_1);
    pcVar2 = (char *)FUN_10005a90(*puVar1);
    if (*pcVar2 != '\0') break;
    puVar1 = (undefined4 *)FUN_100086e0(param_1);
    param_1 = *puVar1;
  }
  return param_1;
}
