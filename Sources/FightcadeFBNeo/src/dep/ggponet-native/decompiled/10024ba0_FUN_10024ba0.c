
undefined4 FUN_10024ba0(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  undefined1 local_34 [16];
  double local_24;
  double local_1c;
  int local_10;
  double local_c;
  
  cVar1 = FUN_1000a890();
  if (cVar1 == '\0') {
    while( true ) {
      iVar2 = FUN_10007af0();
      iVar3 = FUN_10007b10();
      if (*(int *)(iVar3 + 4) + -3000 <= *(int *)(iVar2 + 4)) break;
      FUN_100016a0();
    }
    local_10 = 0;
    *(undefined4 *)(in_ECX + 0x105c) = 0;
    FUN_10007ac0();
    while( true ) {
      FUN_100019d0();
      cVar1 = FUN_10004d20();
      if (cVar1 == '\0') break;
      piVar4 = (int *)FUN_10004d00();
      local_10 = local_10 + 0x2a + *piVar4;
      *(int *)(in_ECX + 0x105c) = *(int *)(in_ECX + 0x105c) + 1;
      FUN_10007c00(local_34,0);
    }
    iVar2 = FUN_10007b10();
    iVar3 = FUN_10007af0();
    local_24 = (double)(*(int *)(iVar2 + 4) - *(int *)(iVar3 + 4)) / 1000.0;
    local_1c = (double)local_10 / local_24;
    local_c = (double)(((float)(*(int *)(in_ECX + 0x105c) * 0x2a) * 100.0) / (float)local_10);
    *(float *)(in_ECX + 0x1060) = (float)(((float10)8.0 * (float10)local_1c) / (float10)1024.0);
    FUN_10024520(in_ECX,
                 "Network Stats -- Bandwidth: %.2f KBps   Packets Sent: %5d (%.2f pps)   KB Sent: %.2f   Overhead: %.2f %%.\n"
                 ,(double)*(float *)(in_ECX + 0x1060),*(undefined4 *)(in_ECX + 0x105c),
                 ((double)*(int *)(in_ECX + 0x105c) * 1000.0) / 3000.0,(double)local_10 / 1024.0,
                 local_c);
  }
  return 1;
}
