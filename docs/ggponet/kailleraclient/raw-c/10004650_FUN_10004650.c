
void __thiscall
FUN_10004650(void *this,HWND param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  byte *pbVar7;
  bool bVar8;
  tagRECT local_110;
  byte local_100 [256];
  
  puVar2 = malloc(0x2c);
  puVar2[1] = param_2;
  puVar2[6] = param_3;
  *puVar2 = param_1;
  puVar2[7] = param_4;
  puVar2[8] = param_5;
  puVar2[9] = param_6;
  if (param_1 == (HWND)0x0) {
    puVar2[10] = 0;
    puVar2[5] = 0;
    puVar2[4] = 0;
    puVar2[3] = 0;
    puVar2[2] = 0;
  }
  else {
    GetWindowRect(param_1,&local_110);
    puVar2[2] = local_110.left;
    puVar2[3] = local_110.top;
    puVar2[4] = local_110.right - local_110.left;
    puVar2[5] = local_110.bottom - local_110.top;
    GetClassNameA(param_1,(LPSTR)local_100,0xff);
    pcVar6 = s_SysListView32_1000e21c;
    pbVar3 = local_100;
    do {
      bVar1 = *pbVar3;
      bVar8 = bVar1 < (byte)*pcVar6;
      if (bVar1 != *pcVar6) {
LAB_10004718:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_1000471d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar8 = bVar1 < (byte)pcVar6[1];
      if (bVar1 != pcVar6[1]) goto LAB_10004718;
      pbVar3 = pbVar3 + 2;
      pcVar6 = pcVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_1000471d:
    if (iVar4 != 0) {
      pbVar7 = &DAT_1000e214;
      pbVar3 = local_100;
      do {
        bVar1 = *pbVar3;
        bVar8 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_1000474e:
          iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
          goto LAB_10004753;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar8 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_1000474e;
        pbVar3 = pbVar3 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_10004753:
      if (iVar4 != 0) {
        puVar2[10] = 0;
        goto LAB_10004774;
      }
    }
    puVar2[10] = 1;
  }
LAB_10004774:
  if ((*(void **)((int)this + 4) == (void *)0x0) || ((*(byte *)((int)this + 8) & 0x1f) == 0)) {
    pvVar5 = realloc(*(void **)((int)this + 4),*(int *)((int)this + 8) * 4 + 0x80);
    *(void **)((int)this + 4) = pvVar5;
  }
  *(undefined4 **)(*(int *)((int)this + 4) + *(int *)((int)this + 8) * 4) = puVar2;
  *(int *)((int)this + 8) = *(int *)((int)this + 8) + 1;
  return;
}
