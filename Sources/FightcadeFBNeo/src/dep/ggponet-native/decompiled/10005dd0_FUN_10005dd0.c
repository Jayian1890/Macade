
undefined4 FUN_10005dd0(undefined4 param_1,char param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *puVar7;
  int in_ECX;
  undefined1 local_5c [28];
  undefined1 local_40 [40];
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_1002d8d8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_10006490(DAT_10037490 ^ (uint)&stack0xfffffffc);
  if (*(uint *)(in_ECX + 0x1c) < iVar2 - 1U) {
    local_14 = FUN_10007100(*(undefined4 *)(in_ECX + 0x18),param_3,*(undefined4 *)(in_ECX + 0x18),
                            param_4,0);
    *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
    if (param_3 == *(int *)(in_ECX + 0x18)) {
      piVar3 = (int *)FUN_10006e40();
      *piVar3 = local_14;
      piVar3 = (int *)FUN_10006cf0();
      *piVar3 = local_14;
      piVar3 = (int *)FUN_100062e0();
      *piVar3 = local_14;
    }
    else if (param_2 == '\0') {
      piVar3 = (int *)FUN_100086e0(param_3);
      *piVar3 = local_14;
      piVar3 = (int *)FUN_100062e0();
      if (param_3 == *piVar3) {
        piVar3 = (int *)FUN_100062e0();
        *piVar3 = local_14;
      }
    }
    else {
      piVar3 = (int *)FUN_10007c60(param_3);
      *piVar3 = local_14;
      piVar3 = (int *)FUN_10006cf0();
      if (param_3 == *piVar3) {
        piVar3 = (int *)FUN_10006cf0();
        *piVar3 = local_14;
      }
    }
    local_18 = local_14;
    while( true ) {
      puVar4 = (undefined4 *)FUN_100019c0(local_18);
      pcVar5 = (char *)FUN_10006450(*puVar4);
      if (*pcVar5 != '\0') break;
      piVar3 = (int *)FUN_100019c0(local_18);
      puVar4 = (undefined4 *)FUN_100019c0(local_18);
      puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
      piVar6 = (int *)FUN_10007c60(*puVar4);
      if (*piVar3 == *piVar6) {
        puVar4 = (undefined4 *)FUN_100019c0(local_18);
        puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
        puVar4 = (undefined4 *)FUN_100086e0(*puVar4);
        uVar1 = *puVar4;
        pcVar5 = (char *)FUN_10006450(uVar1);
        if (*pcVar5 == '\0') {
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 1;
          puVar7 = (undefined1 *)FUN_10006450(uVar1);
          *puVar7 = 1;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 0;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          piVar3 = (int *)FUN_100019c0(*puVar4);
          local_18 = *piVar3;
        }
        else {
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          piVar3 = (int *)FUN_100086e0(*puVar4);
          if (local_18 == *piVar3) {
            piVar3 = (int *)FUN_100019c0(local_18);
            local_18 = *piVar3;
            FUN_10006d10(local_18);
          }
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 1;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 0;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          FUN_10006e60(*puVar4);
        }
      }
      else {
        puVar4 = (undefined4 *)FUN_100019c0(local_18);
        puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
        puVar4 = (undefined4 *)FUN_10007c60(*puVar4);
        uVar1 = *puVar4;
        pcVar5 = (char *)FUN_10006450(uVar1);
        if (*pcVar5 == '\0') {
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 1;
          puVar7 = (undefined1 *)FUN_10006450(uVar1);
          *puVar7 = 1;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 0;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          piVar3 = (int *)FUN_100019c0(*puVar4);
          local_18 = *piVar3;
        }
        else {
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          piVar3 = (int *)FUN_10007c60(*puVar4);
          if (local_18 == *piVar3) {
            piVar3 = (int *)FUN_100019c0(local_18);
            local_18 = *piVar3;
            FUN_10006e60(local_18);
          }
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 1;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          puVar7 = (undefined1 *)FUN_10006450(*puVar4);
          *puVar7 = 0;
          puVar4 = (undefined4 *)FUN_100019c0(local_18);
          puVar4 = (undefined4 *)FUN_100019c0(*puVar4);
          FUN_10006d10(*puVar4);
        }
      }
    }
    puVar4 = (undefined4 *)FUN_10006e40();
    puVar7 = (undefined1 *)FUN_10006450(*puVar4);
    *puVar7 = 1;
    _Vector_iterator<>(local_14,in_ECX);
    ExceptionList = local_10;
    return param_1;
  }
  basic_string<>("map/set<T> too long");
  local_8 = 0;
  FID_conflict_length_error(local_5c);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_40,&DAT_1003433c);
}
