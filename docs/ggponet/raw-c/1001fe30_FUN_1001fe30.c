
void FUN_1001fe30(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x110 + *(int *)(in_ECX + 0x270) * 0x10);
  if (*piVar1 != 0) {
    (**(code **)(in_ECX + 0x14))(*piVar1);
    *piVar1 = 0;
  }
  piVar1[2] = *(int *)(in_ECX + 0x10c);
  (**(code **)(in_ECX + 8))(piVar1,piVar1 + 1,piVar1 + 3,piVar1[2]);
  FUN_10021ff0("=== Saved frame info %d (size: %d  checksum: %08x).\n",piVar1[2],piVar1[1],piVar1[3]
              );
  *(uint *)(in_ECX + 0x270) = (*(int *)(in_ECX + 0x270) + 1U) % 0x16;
  return;
}
