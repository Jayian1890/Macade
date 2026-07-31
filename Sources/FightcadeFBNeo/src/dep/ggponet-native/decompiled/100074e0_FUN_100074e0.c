
void FUN_100074e0(_Container_proxy *param_1)

{
  _Container_proxy *p_Var1;
  char *pcVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  while( true ) {
    pcVar2 = (char *)FUN_10005a90(param_1);
    if (*pcVar2 != '\0') break;
    puVar3 = (undefined4 *)FUN_100086e0(param_1);
    FUN_100074e0(*puVar3);
    puVar3 = (undefined4 *)FUN_10007c60(param_1);
    p_Var1 = (_Container_proxy *)*puVar3;
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),param_1);
    FUN_100033b0(param_1,1);
    param_1 = p_Var1;
  }
  return;
}
