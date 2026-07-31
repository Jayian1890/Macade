
undefined4 FUN_1000b510(int param_1,int param_2,int param_3,int param_4,char *param_5,int param_6)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int in_EDX;
  int iVar4;
  int iVar5;
  int local_4;
  
  if (((param_5 == (char *)0x0) || (*param_5 != *PTR_s_1_1_4_10036008)) || (param_6 != 0x38)) {
    return 0xfffffffa;
  }
  if (in_ECX != 0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    if (*(int *)(in_ECX + 0x20) == 0) {
      *(code **)(in_ECX + 0x20) = FUN_1000cda0;
      *(undefined4 *)(in_ECX + 0x28) = 0;
    }
    if (*(int *)(in_ECX + 0x24) == 0) {
      *(undefined1 **)(in_ECX + 0x24) = &LAB_1000cdc0;
    }
    local_4 = in_EDX;
    if (in_EDX == -1) {
      local_4 = 6;
    }
    iVar4 = param_2;
    if (param_2 < 0) {
      iVar4 = -param_2;
    }
    if (((((0 < param_3) && (param_3 < 10)) && ((param_1 == 8 && ((8 < iVar4 && (iVar4 < 0x10))))))
        && (-1 < local_4)) && (((local_4 < 10 && (-1 < param_4)) && (param_4 < 3)))) {
      piVar2 = (int *)(**(code **)(in_ECX + 0x20))();
      if (piVar2 == (int *)0x0) {
        return 0xfffffffc;
      }
      *(int **)(in_ECX + 0x1c) = piVar2;
      piVar2[6] = (uint)(param_2 < 0);
      iVar5 = 1 << ((byte)iVar4 & 0x1f);
      piVar2[10] = iVar4;
      *piVar2 = in_ECX;
      piVar2[9] = iVar5;
      piVar2[0xb] = iVar5 + -1;
      iVar4 = 1 << ((byte)(param_2 + 7) & 0x1f);
      piVar2[0x12] = param_2 + 7;
      piVar2[0x11] = iVar4;
      piVar2[0x13] = iVar4 + -1;
      piVar2[0x14] = (param_2 + 9U) / 3;
      iVar4 = (**(code **)(in_ECX + 0x20))(2);
      piVar2[0xc] = iVar4;
      iVar4 = (**(code **)(in_ECX + 0x20))(2);
      piVar2[0xe] = iVar4;
      iVar4 = (**(code **)(in_ECX + 0x20))(2);
      piVar2[0xf] = iVar4;
      piVar2[0x5a5] = 1 << ((char)param_2 + 6U & 0x1f);
      iVar4 = (**(code **)(in_ECX + 0x20))(4);
      uVar1 = piVar2[0x5a5];
      piVar2[2] = iVar4;
      piVar2[3] = uVar1 * 4;
      if (((piVar2[0xc] != 0) && (piVar2[0xe] != 0)) && ((piVar2[0xf] != 0 && (iVar4 != 0)))) {
        *(undefined1 *)((int)piVar2 + 0x1d) = 8;
        piVar2[0x5a7] = iVar4 + (uVar1 & 0xfffffffe);
        piVar2[0x5a4] = iVar4 + uVar1 * 3;
        piVar2[0x20] = local_4;
        piVar2[0x1f] = 0x16b8;
        uVar3 = FUN_1000b710();
        return uVar3;
      }
      *(undefined **)(in_ECX + 0x18) = PTR_s_insufficient_memory_10036094;
      FUN_1000bad0();
      return 0xfffffffc;
    }
  }
  return 0xfffffffe;
}
