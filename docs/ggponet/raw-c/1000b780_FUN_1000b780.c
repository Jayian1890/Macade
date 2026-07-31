
uint FUN_1000b780(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  uint uVar4;
  int in_EDX;
  undefined4 *puVar5;
  
  if ((((in_ECX == (int *)0x0) || (puVar1 = (undefined4 *)in_ECX[7], puVar1 == (undefined4 *)0x0))
      || (4 < in_EDX)) || (in_EDX < 0)) {
    return 0xfffffffe;
  }
  if (((in_ECX[3] == 0) || ((*in_ECX == 0 && (in_ECX[1] != 0)))) ||
     ((puVar1[1] == 0x29a && (in_EDX != 4)))) {
    in_ECX[6] = (int)PTR_s_stream_error_1003608c;
    return 0xfffffffe;
  }
  if (in_ECX[4] == 0) {
    in_ECX[6] = (int)PTR_s_buffer_error_10036098;
    return 0xfffffffb;
  }
  iVar2 = puVar1[8];
  *puVar1 = in_ECX;
  puVar1[8] = in_EDX;
  if (puVar1[1] == 0x2a) {
    puVar1[1] = 0x71;
    FUN_1000ba30();
    if (puVar1[0x19] != 0) {
      FUN_1000ba30();
      FUN_1000ba30();
    }
    in_ECX[0xc] = 1;
  }
  if (puVar1[5] == 0) {
    if (((in_ECX[1] == 0) && (in_EDX <= iVar2)) && (in_EDX != 4)) {
      in_ECX[6] = (int)PTR_s_buffer_error_10036098;
      return 0xfffffffb;
    }
  }
  else {
    FUN_1000ba60();
    if (in_ECX[4] == 0) {
      puVar1[8] = 0xffffffff;
      return 0;
    }
  }
  if (puVar1[1] == 0x29a) {
    if (in_ECX[1] != 0) {
      in_ECX[6] = (int)PTR_s_buffer_error_10036098;
      return 0xfffffffb;
    }
LAB_1000b8f0:
    if ((puVar1[0x1b] == 0) && ((in_EDX == 0 || (puVar1[1] == 0x29a)))) goto LAB_1000b9a4;
  }
  else if (in_ECX[1] == 0) goto LAB_1000b8f0;
  iVar2 = (**(code **)(&DAT_1002e240 + puVar1[0x1f] * 0xc))();
  if ((iVar2 == 2) || (iVar2 == 3)) {
    puVar1[1] = 0x29a;
  }
  if ((iVar2 == 0) || (iVar2 == 2)) {
    if (in_ECX[4] == 0) {
      puVar1[8] = 0xffffffff;
    }
    return 0;
  }
  if (iVar2 == 1) {
    if (in_EDX == 1) {
      FUN_1000d0a0();
    }
    else {
      FUN_1000cff0(0,0);
      if (in_EDX == 3) {
        *(undefined2 *)(puVar1[0xf] + -2 + puVar1[0x11] * 2) = 0;
        uVar4 = puVar1[0x11] * 2 - 2;
        puVar5 = (undefined4 *)puVar1[0xf];
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar5 = 0;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
        }
      }
    }
    FUN_1000ba60();
    if (in_ECX[4] == 0) {
      puVar1[8] = 0xffffffff;
      return 0;
    }
  }
LAB_1000b9a4:
  if (in_EDX != 4) {
    return 0;
  }
  if (puVar1[6] == 0) {
    FUN_1000ba30();
    FUN_1000ba30();
    FUN_1000ba60();
    puVar1[6] = 0xffffffff;
    return (uint)(puVar1[5] == 0);
  }
  return 1;
}
