
undefined4 FUN_100064b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _Container_proxy *p_Var1;
  uint uVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int in_ECX;
  _Container_proxy *local_70;
  _Container_proxy *local_6c;
  undefined1 local_64 [28];
  undefined1 local_48 [40];
  _Container_proxy *local_20;
  _Container_proxy *local_1c;
  _Container_proxy *local_18;
  _Container_proxy *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d8a8;
  local_10 = ExceptionList;
  uVar2 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = FUN_10002210(uVar2);
  pcVar4 = (char *)FUN_10005a90(uVar3);
  if (*pcVar4 != '\0') {
    basic_string<>("invalid map/set<T> iterator");
    local_8 = 0;
    FID_conflict_length_error(local_64);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_48,&DAT_100343b0);
  }
  local_14 = (_Container_proxy *)FUN_10002210(uVar2);
  FUN_100063f0();
  local_1c = local_14;
  puVar5 = (undefined4 *)FUN_10007c60(local_14);
  pcVar4 = (char *)FUN_10005a90(*puVar5);
  if (*pcVar4 == '\0') {
    puVar5 = (undefined4 *)FUN_100086e0(local_1c);
    pcVar4 = (char *)FUN_10005a90(*puVar5);
    if (*pcVar4 == '\0') {
      local_1c = (_Container_proxy *)FUN_10002210();
      piVar6 = (int *)FUN_100086e0(local_1c);
      local_18 = (_Container_proxy *)*piVar6;
    }
    else {
      piVar6 = (int *)FUN_10007c60(local_1c);
      local_18 = (_Container_proxy *)*piVar6;
    }
  }
  else {
    piVar6 = (int *)FUN_100086e0(local_1c);
    local_18 = (_Container_proxy *)*piVar6;
  }
  if (local_1c == local_14) {
    piVar6 = (int *)FUN_100019c0(local_14);
    local_20 = (_Container_proxy *)*piVar6;
    pcVar4 = (char *)FUN_10005a90(local_18);
    if (*pcVar4 == '\0') {
      piVar6 = (int *)FUN_100019c0(local_18);
      *piVar6 = (int)local_20;
    }
    piVar6 = (int *)FUN_10006e40();
    if ((_Container_proxy *)*piVar6 == local_14) {
      piVar6 = (int *)FUN_10006e40();
      *piVar6 = (int)local_18;
    }
    else {
      piVar6 = (int *)FUN_10007c60(local_20);
      if ((_Container_proxy *)*piVar6 == local_14) {
        piVar6 = (int *)FUN_10007c60(local_20);
        *piVar6 = (int)local_18;
      }
      else {
        piVar6 = (int *)FUN_100086e0(local_20);
        *piVar6 = (int)local_18;
      }
    }
    piVar6 = (int *)FUN_10006cf0();
    if ((_Container_proxy *)*piVar6 == local_14) {
      pcVar4 = (char *)FUN_10005a90(local_18);
      if (*pcVar4 == '\0') {
        local_6c = (_Container_proxy *)FUN_100075a0(local_18);
      }
      else {
        local_6c = local_20;
      }
      piVar6 = (int *)FUN_10006cf0();
      *piVar6 = (int)local_6c;
    }
    piVar6 = (int *)FUN_100062e0();
    if ((_Container_proxy *)*piVar6 == local_14) {
      pcVar4 = (char *)FUN_10005a90(local_18);
      if (*pcVar4 == '\0') {
        local_70 = (_Container_proxy *)FUN_10007560(local_18);
      }
      else {
        local_70 = local_20;
      }
      piVar6 = (int *)FUN_100062e0();
      *piVar6 = (int)local_70;
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_10007c60(local_14);
    piVar6 = (int *)FUN_100019c0(*puVar5);
    *piVar6 = (int)local_1c;
    puVar5 = (undefined4 *)FUN_10007c60(local_14);
    puVar7 = (undefined4 *)FUN_10007c60(local_1c);
    *puVar7 = *puVar5;
    piVar6 = (int *)FUN_100086e0(local_14);
    if (local_1c == (_Container_proxy *)*piVar6) {
      local_20 = local_1c;
    }
    else {
      piVar6 = (int *)FUN_100019c0(local_1c);
      local_20 = (_Container_proxy *)*piVar6;
      pcVar4 = (char *)FUN_10005a90(local_18);
      if (*pcVar4 == '\0') {
        piVar6 = (int *)FUN_100019c0(local_18);
        *piVar6 = (int)local_20;
      }
      piVar6 = (int *)FUN_10007c60(local_20);
      *piVar6 = (int)local_18;
      puVar5 = (undefined4 *)FUN_100086e0(local_14);
      puVar7 = (undefined4 *)FUN_100086e0(local_1c);
      *puVar7 = *puVar5;
      puVar5 = (undefined4 *)FUN_100086e0(local_14);
      piVar6 = (int *)FUN_100019c0(*puVar5);
      *piVar6 = (int)local_1c;
    }
    piVar6 = (int *)FUN_10006e40();
    if ((_Container_proxy *)*piVar6 == local_14) {
      piVar6 = (int *)FUN_10006e40();
      *piVar6 = (int)local_1c;
    }
    else {
      puVar5 = (undefined4 *)FUN_100019c0(local_14);
      piVar6 = (int *)FUN_10007c60(*puVar5);
      if ((_Container_proxy *)*piVar6 == local_14) {
        puVar5 = (undefined4 *)FUN_100019c0(local_14);
        piVar6 = (int *)FUN_10007c60(*puVar5);
        *piVar6 = (int)local_1c;
      }
      else {
        puVar5 = (undefined4 *)FUN_100019c0(local_14);
        piVar6 = (int *)FUN_100086e0(*puVar5);
        *piVar6 = (int)local_1c;
      }
    }
    puVar5 = (undefined4 *)FUN_100019c0(local_14);
    puVar7 = (undefined4 *)FUN_100019c0(local_1c);
    *puVar7 = *puVar5;
    uVar3 = FUN_10006450(local_14);
    uVar3 = FUN_10006450(local_1c,uVar3);
    FUN_10007750(uVar3);
  }
  pcVar4 = (char *)FUN_10006450(local_14);
  if (*pcVar4 != '\x01') {
LAB_10006c21:
    std::allocator<std::_Container_proxy>::destroy
              ((allocator<std::_Container_proxy> *)(in_ECX + 0xc),local_14);
    FUN_100033b0(local_14,1);
    if (*(int *)(in_ECX + 0x1c) != 0) {
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
    }
    FUN_10006460(param_1,param_2,param_3);
    ExceptionList = local_10;
    return param_1;
  }
LAB_100068a5:
  piVar6 = (int *)FUN_10006e40();
  if ((local_18 == (_Container_proxy *)*piVar6) ||
     (pcVar4 = (char *)FUN_10006450(local_18), *pcVar4 != '\x01')) goto LAB_10006c12;
  piVar6 = (int *)FUN_10007c60(local_20);
  if (local_18 == (_Container_proxy *)*piVar6) {
    piVar6 = (int *)FUN_100086e0(local_20);
    local_1c = (_Container_proxy *)*piVar6;
    pcVar4 = (char *)FUN_10006450(local_1c);
    if (*pcVar4 == '\0') {
      puVar8 = (undefined1 *)FUN_10006450(local_1c);
      *puVar8 = 1;
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      *puVar8 = 0;
      FUN_10006d10(local_20);
      piVar6 = (int *)FUN_100086e0(local_20);
      local_1c = (_Container_proxy *)*piVar6;
    }
    pcVar4 = (char *)FUN_10005a90(local_1c);
    p_Var1 = local_20;
    if (*pcVar4 == '\0') {
      puVar5 = (undefined4 *)FUN_10007c60(local_1c);
      pcVar4 = (char *)FUN_10006450(*puVar5);
      if (*pcVar4 == '\x01') {
        puVar5 = (undefined4 *)FUN_100086e0(local_1c);
        pcVar4 = (char *)FUN_10006450(*puVar5);
        if (*pcVar4 == '\x01') {
          puVar8 = (undefined1 *)FUN_10006450(local_1c);
          *puVar8 = 0;
          p_Var1 = local_20;
          goto LAB_10006894;
        }
      }
      puVar5 = (undefined4 *)FUN_100086e0(local_1c);
      pcVar4 = (char *)FUN_10006450(*puVar5);
      if (*pcVar4 == '\x01') {
        puVar5 = (undefined4 *)FUN_10007c60(local_1c);
        puVar8 = (undefined1 *)FUN_10006450(*puVar5);
        *puVar8 = 1;
        puVar8 = (undefined1 *)FUN_10006450(local_1c);
        *puVar8 = 0;
        FUN_10006e60(local_1c);
        piVar6 = (int *)FUN_100086e0(local_20);
        local_1c = (_Container_proxy *)*piVar6;
      }
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      puVar9 = (undefined1 *)FUN_10006450(local_1c);
      *puVar9 = *puVar8;
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      *puVar8 = 1;
      puVar5 = (undefined4 *)FUN_100086e0(local_1c);
      puVar8 = (undefined1 *)FUN_10006450(*puVar5);
      *puVar8 = 1;
      FUN_10006d10(local_20);
LAB_10006c12:
      puVar8 = (undefined1 *)FUN_10006450(local_18);
      *puVar8 = 1;
      goto LAB_10006c21;
    }
  }
  else {
    piVar6 = (int *)FUN_10007c60(local_20);
    local_1c = (_Container_proxy *)*piVar6;
    pcVar4 = (char *)FUN_10006450(local_1c);
    if (*pcVar4 == '\0') {
      puVar8 = (undefined1 *)FUN_10006450(local_1c);
      *puVar8 = 1;
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      *puVar8 = 0;
      FUN_10006e60(local_20);
      piVar6 = (int *)FUN_10007c60(local_20);
      local_1c = (_Container_proxy *)*piVar6;
    }
    pcVar4 = (char *)FUN_10005a90(local_1c);
    if (*pcVar4 == '\0') {
      puVar5 = (undefined4 *)FUN_100086e0(local_1c);
      pcVar4 = (char *)FUN_10006450(*puVar5);
      if (*pcVar4 == '\x01') {
        puVar5 = (undefined4 *)FUN_10007c60(local_1c);
        pcVar4 = (char *)FUN_10006450(*puVar5);
        if (*pcVar4 == '\x01') {
          puVar8 = (undefined1 *)FUN_10006450(local_1c);
          *puVar8 = 0;
          local_18 = local_20;
          p_Var1 = local_18;
          goto LAB_10006894;
        }
      }
      puVar5 = (undefined4 *)FUN_10007c60(local_1c);
      pcVar4 = (char *)FUN_10006450(*puVar5);
      if (*pcVar4 == '\x01') {
        puVar5 = (undefined4 *)FUN_100086e0(local_1c);
        puVar8 = (undefined1 *)FUN_10006450(*puVar5);
        *puVar8 = 1;
        puVar8 = (undefined1 *)FUN_10006450(local_1c);
        *puVar8 = 0;
        FUN_10006d10(local_1c);
        piVar6 = (int *)FUN_10007c60(local_20);
        local_1c = (_Container_proxy *)*piVar6;
      }
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      puVar9 = (undefined1 *)FUN_10006450(local_1c);
      *puVar9 = *puVar8;
      puVar8 = (undefined1 *)FUN_10006450(local_20);
      *puVar8 = 1;
      puVar5 = (undefined4 *)FUN_10007c60(local_1c);
      puVar8 = (undefined1 *)FUN_10006450(*puVar5);
      *puVar8 = 1;
      FUN_10006e60(local_20);
      goto LAB_10006c12;
    }
    p_Var1 = local_20;
  }
LAB_10006894:
  local_18 = p_Var1;
  local_20 = local_18;
  piVar6 = (int *)FUN_100019c0(local_18);
  local_20 = (_Container_proxy *)*piVar6;
  goto LAB_100068a5;
}
