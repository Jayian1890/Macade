
void FUN_1000b810(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  char local_40 [64];
  
  SendMessageA(DAT_1000f240,0x1009,0,0);
  iVar3 = 0;
  if (0 < DAT_1000f3cc) {
    do {
      if ((iVar3 < 0) || (DAT_1000f3cc <= iVar3)) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = *(undefined4 **)(DAT_1000f3c8 + iVar3 * 4);
      }
      iVar3 = iVar3 + 1;
      uVar1 = FUN_10004260(&DAT_1000f240,iVar3,(char *)*puVar2,iVar3);
      FUN_100042c0(&DAT_1000f240,uVar1,1,(char *)puVar2[1]);
      _itoa(puVar2[3],local_40,10);
      FUN_100042c0(&DAT_1000f240,uVar1,2,local_40);
      FUN_100042c0(&DAT_1000f240,uVar1,3,(char *)puVar2[2]);
    } while (iVar3 < DAT_1000f3cc);
  }
  return;
}
