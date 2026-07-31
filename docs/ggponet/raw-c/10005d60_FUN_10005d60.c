
void FUN_10005d60(void)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  uVar1 = FUN_10006f90();
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  puVar2 = (undefined1 *)FUN_10005a90(*(undefined4 *)(in_ECX + 0x18));
  *puVar2 = 1;
  puVar3 = (undefined4 *)FUN_10006e40();
  *puVar3 = *(undefined4 *)(in_ECX + 0x18);
  puVar3 = (undefined4 *)FUN_10006cf0();
  *puVar3 = *(undefined4 *)(in_ECX + 0x18);
  puVar3 = (undefined4 *)FUN_100062e0();
  *puVar3 = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}
