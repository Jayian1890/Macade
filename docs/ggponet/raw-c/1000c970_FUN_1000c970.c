
uint FUN_1000c970(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *in_ECX;
  int in_EDX;
  uint uVar5;
  
  if (((in_ECX == (int *)0x0) || (in_ECX[7] == 0)) || (*in_ECX == 0)) {
switchD_1000c9bb_default:
    return 0xfffffffe;
  }
  uVar5 = (in_EDX != 4) - 1 & 0xfffffffb;
  uVar4 = 0xfffffffb;
  do {
    switch(*(undefined4 *)in_ECX[7]) {
    case 0:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      in_ECX[2] = in_ECX[2] + 1;
      ((undefined4 *)in_ECX[7])[1] = (uint)*(byte *)*in_ECX;
      puVar3 = (undefined4 *)in_ECX[7];
      uVar2 = puVar3[1];
      *in_ECX = *in_ECX + 1;
      if (((byte)uVar2 & 0xf) != 8) {
        *puVar3 = 0xd;
        in_ECX[6] = (int)s_unknown_compression_method_10036060;
        *(undefined4 *)(in_ECX[7] + 4) = 5;
        uVar4 = uVar5;
        break;
      }
      if ((uint)puVar3[4] < ((uint)puVar3[1] >> 4) + 8) {
        *puVar3 = 0xd;
        in_ECX[6] = (int)s_invalid_window_size_1003604c;
        *(undefined4 *)(in_ECX[7] + 4) = 5;
        uVar4 = uVar5;
        break;
      }
      *puVar3 = 1;
      uVar4 = uVar5;
    case 1:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      puVar3 = (undefined4 *)in_ECX[7];
      in_ECX[2] = in_ECX[2] + 1;
      bVar1 = *(byte *)*in_ECX;
      *in_ECX = (int)((byte *)*in_ECX + 1);
      if ((puVar3[1] * 0x100 + (uint)bVar1) % 0x1f == 0) {
        if ((bVar1 & 0x20) != 0) {
          *(undefined4 *)in_ECX[7] = 2;
          uVar4 = uVar5;
          goto switchD_1000c9bb_caseD_2;
        }
        *puVar3 = 7;
        uVar4 = uVar5;
      }
      else {
        *puVar3 = 0xd;
        in_ECX[6] = (int)s_incorrect_header_check_10036034;
        *(undefined4 *)(in_ECX[7] + 4) = 5;
        uVar4 = uVar5;
      }
      break;
    case 2:
switchD_1000c9bb_caseD_2:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[2] = in_ECX[2] + 1;
      in_ECX[1] = in_ECX[1] + -1;
      *(uint *)(in_ECX[7] + 8) = (uint)*(byte *)*in_ECX << 0x18;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 3;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_3:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      in_ECX[2] = in_ECX[2] + 1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX * 0x10000;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 4;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_4:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      in_ECX[2] = in_ECX[2] + 1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX * 0x100;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 5;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_5:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      in_ECX[2] = in_ECX[2] + 1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX;
      *in_ECX = *in_ECX + 1;
      in_ECX[0xc] = ((undefined4 *)in_ECX[7])[2];
      *(undefined4 *)in_ECX[7] = 6;
      return 2;
    case 3:
      goto switchD_1000c9bb_caseD_3;
    case 4:
      goto switchD_1000c9bb_caseD_4;
    case 5:
      goto switchD_1000c9bb_caseD_5;
    case 6:
      *(undefined4 *)in_ECX[7] = 0xd;
      in_ECX[6] = (int)s_need_dictionary_1003600c;
      *(undefined4 *)(in_ECX[7] + 4) = 0;
      return 0xfffffffe;
    case 7:
      uVar4 = FUN_1000eb50(uVar4);
      if (uVar4 == 0xfffffffd) {
        *(undefined4 *)in_ECX[7] = 0xd;
        *(undefined4 *)(in_ECX[7] + 4) = 0;
        uVar4 = 0xfffffffd;
      }
      else {
        if (uVar4 == 0) {
          uVar4 = uVar5;
        }
        if (uVar4 != 1) {
          return uVar4;
        }
        FUN_1000ea40(in_ECX[7] + 4);
        puVar3 = (undefined4 *)in_ECX[7];
        if (puVar3[3] == 0) {
          *puVar3 = 8;
          uVar4 = uVar5;
          goto switchD_1000c9bb_caseD_8;
        }
        *puVar3 = 0xc;
        uVar4 = uVar5;
      }
      break;
    case 8:
switchD_1000c9bb_caseD_8:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[2] = in_ECX[2] + 1;
      in_ECX[1] = in_ECX[1] + -1;
      *(uint *)(in_ECX[7] + 8) = (uint)*(byte *)*in_ECX << 0x18;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 9;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_9:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[2] = in_ECX[2] + 1;
      in_ECX[1] = in_ECX[1] + -1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX * 0x10000;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 10;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_a:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[2] = in_ECX[2] + 1;
      in_ECX[1] = in_ECX[1] + -1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX * 0x100;
      *in_ECX = *in_ECX + 1;
      *(undefined4 *)in_ECX[7] = 0xb;
      uVar4 = uVar5;
switchD_1000c9bb_caseD_b:
      if (in_ECX[1] == 0) {
        return uVar4;
      }
      in_ECX[1] = in_ECX[1] + -1;
      in_ECX[2] = in_ECX[2] + 1;
      *(uint *)(in_ECX[7] + 8) = *(int *)(in_ECX[7] + 8) + (uint)*(byte *)*in_ECX;
      *in_ECX = *in_ECX + 1;
      puVar3 = (undefined4 *)in_ECX[7];
      if (puVar3[1] == puVar3[2]) {
        *(undefined4 *)in_ECX[7] = 0xc;
switchD_1000c9bb_caseD_c:
        return 1;
      }
      *puVar3 = 0xd;
      in_ECX[6] = (int)s_incorrect_data_check_1003601c;
      *(undefined4 *)(in_ECX[7] + 4) = 5;
      uVar4 = uVar5;
      break;
    case 9:
      goto switchD_1000c9bb_caseD_9;
    case 10:
      goto switchD_1000c9bb_caseD_a;
    case 0xb:
      goto switchD_1000c9bb_caseD_b;
    case 0xc:
      goto switchD_1000c9bb_caseD_c;
    case 0xd:
      return 0xfffffffd;
    default:
      goto switchD_1000c9bb_default;
    }
  } while( true );
}
