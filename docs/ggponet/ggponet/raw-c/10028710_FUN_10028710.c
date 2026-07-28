
undefined4 FUN_10028710(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar1 = FUN_10002810();
  FUN_10021ff0("End of frame (%d)...\n",uVar1);
  FUN_100202e0();
  (**(code **)*in_ECX)(0);
  FUN_100286c0();
  FUN_10022ce0(local_20);
  in_ECX[0x673] = local_18;
  in_ECX[0x674] = local_1c;
  return 1;
}
