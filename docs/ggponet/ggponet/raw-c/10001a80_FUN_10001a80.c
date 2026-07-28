
undefined4 FUN_10001a80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_10 [8];
  _Container_proxy *local_8;
  
  FUN_100021d0(local_10,0);
  local_8 = (_Container_proxy *)FUN_10002210();
  if (local_8 != *(_Container_proxy **)(in_ECX + 0x14)) {
    puVar1 = (undefined4 *)FUN_10007c60(local_8);
    puVar2 = (undefined4 *)FUN_100019c0(local_8);
    puVar2 = (undefined4 *)FUN_10007c60(*puVar2);
    *puVar2 = *puVar1;
    puVar1 = (undefined4 *)FUN_100019c0(local_8);
    puVar2 = (undefined4 *)FUN_10007c60(local_8);
    puVar2 = (undefined4 *)FUN_100019c0(*puVar2);
    *puVar2 = *puVar1;
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 8),local_8);
    FUN_100033b0(local_8,1);
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -1;
  }
  FUN_100080e0(param_1,param_2,param_3);
  return param_1;
}
