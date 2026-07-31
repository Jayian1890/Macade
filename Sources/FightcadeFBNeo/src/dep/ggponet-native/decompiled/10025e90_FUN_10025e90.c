
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10025e90(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined1 *puVar5;
  undefined1 local_424 [8];
  undefined1 local_41c [8];
  undefined1 local_414 [1024];
  uint local_14;
  undefined1 local_10 [8];
  int local_8;
  
  local_14 = DAT_10037490 ^ (uint)&stack0xfffffffc;
  local_8 = 0;
  iVar2 = FUN_10001680();
  if (iVar2 != 0) {
    FUN_10007ac0(local_10);
    FUN_100251e0(0,&DAT_120394e8,&local_8);
    uVar3 = *(undefined4 *)(in_ECX + 0xe8);
    *(int *)(in_ECX + 0xe8) = *(int *)(in_ECX + 0xe8) + 1;
    FUN_100251e0(uVar3,&DAT_120394e8,&local_8);
    FUN_100251e0(0x11,&DAT_120394e8,&local_8);
    FUN_10025150(param_1,&DAT_120394e8,&local_8);
    uVar3 = FUN_10001680(&DAT_120394e8,&local_8);
    FUN_100251e0(uVar3);
    iVar2 = FUN_10004d00(&DAT_120394e8,&local_8);
    FUN_100251e0(*(undefined4 *)(iVar2 + 4));
    iVar2 = FUN_10001680();
    iVar4 = FUN_10004d00();
    _DAT_120394e8 = Ordinal_8(local_8 + -4 + iVar2 * *(int *)(iVar4 + 4));
    FUN_10026e20(&DAT_120394e8,local_8);
    while( true ) {
      uVar3 = FUN_100019d0(local_41c);
      cVar1 = FUN_10004d20(uVar3);
      if (cVar1 == '\0') break;
      uVar3 = 1;
      puVar5 = local_414;
      FUN_10004d00(puVar5,1);
      FUN_100226c0(puVar5,uVar3);
      FUN_10021ff0("Sending confirmed frame to server: %s.\n",local_414);
      iVar2 = FUN_10004d00();
      uVar3 = *(undefined4 *)(iVar2 + 4);
      iVar2 = FUN_10004d00(uVar3);
      FUN_10026e20(iVar2 + 8,uVar3);
      FUN_10007c00(local_424,0);
    }
  }
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}
