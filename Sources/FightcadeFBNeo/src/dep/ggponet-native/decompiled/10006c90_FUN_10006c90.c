
void FUN_10006c90(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_10006e40();
  FUN_100074e0(*puVar1);
  puVar1 = (undefined4 *)FUN_10006e40();
  *puVar1 = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  puVar1 = (undefined4 *)FUN_10006cf0();
  *puVar1 = *(undefined4 *)(in_ECX + 0x18);
  puVar1 = (undefined4 *)FUN_100062e0();
  *puVar1 = *(undefined4 *)(in_ECX + 0x18);
  return;
}
