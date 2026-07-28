
void __fastcall FUN_10004800(undefined4 *param_1)

{
  int iVar1;
  HRGN hrgnSrc1;
  HDWP hWinPosInfo;
  HRGN hrgnSrc2;
  HRGN hrgnDst;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int x2;
  undefined4 *puVar7;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagPOINT local_18;
  tagRECT local_10;
  
  GetClientRect((HWND)*param_1,&local_10);
  local_18.x = local_10.bottom - local_10.top;
  iVar6 = 0;
  x2 = local_10.right - local_10.left;
  local_28 = 0;
  local_24 = 0;
  local_20 = x2;
  local_2c = local_18.x;
  if (0 < (int)param_1[2]) {
    do {
      if ((iVar6 < 0) || ((int)param_1[2] <= iVar6)) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1[1] + iVar6 * 4);
      }
      iVar1 = *(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x20) + *(int *)(iVar2 + 0x24);
      if ((local_2c < iVar1) && ((*(byte *)(iVar2 + 4) & 2) == 0)) {
        iVar1 = iVar1 - local_2c;
        iVar5 = iVar6;
        do {
          iVar5 = iVar5 + -1;
          if (iVar5 < 0) goto LAB_100048f3;
          if ((iVar5 < 0) || ((int)param_1[2] <= iVar5)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(param_1[1] + iVar5 * 4);
          }
        } while ((*(byte *)(iVar3 + 4) & 2) == 0);
        if (-1 < iVar5) {
          if (iVar5 < (int)param_1[2]) {
            iVar3 = *(int *)(param_1[1] + iVar5 * 4);
          }
          else {
            iVar3 = 0;
          }
          *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) - iVar1;
          while (iVar5 = iVar5 + 1, iVar5 != iVar6) {
            if ((iVar5 < 0) || ((int)param_1[2] <= iVar5)) {
              iVar3 = 0;
            }
            else {
              iVar3 = *(int *)(param_1[1] + iVar5 * 4);
            }
            *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) - iVar1;
          }
          local_2c = local_2c + iVar1;
          local_24 = local_24 - iVar1;
        }
      }
LAB_100048f3:
      iVar1 = *(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x1c);
      if ((local_20 < iVar1) && ((*(byte *)(iVar2 + 4) & 1) == 0)) {
        iVar1 = iVar1 - local_20;
        iVar5 = iVar6;
        do {
          iVar5 = iVar5 + -1;
          if (iVar5 < 0) goto LAB_10004975;
          if ((iVar5 < 0) || ((int)param_1[2] <= iVar5)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(param_1[1] + iVar5 * 4);
          }
        } while ((*(byte *)(iVar3 + 4) & 1) == 0);
        if (-1 < iVar5) {
          if (iVar5 < (int)param_1[2]) {
            iVar3 = *(int *)(param_1[1] + iVar5 * 4);
          }
          else {
            iVar3 = 0;
          }
          *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) - iVar1;
          while (iVar5 = iVar5 + 1, iVar5 != iVar6) {
            if ((iVar5 < 0) || ((int)param_1[2] <= iVar5)) {
              iVar3 = 0;
            }
            else {
              iVar3 = *(int *)(param_1[1] + iVar5 * 4);
            }
            *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) - iVar1;
          }
          local_20 = local_20 + iVar1;
          local_28 = local_28 - iVar1;
        }
      }
LAB_10004975:
      *(int *)(iVar2 + 8) = *(int *)(iVar2 + 0x18) + local_28;
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0x20) + local_24;
      if ((*(byte *)(iVar2 + 4) & 1) != 0) {
        *(int *)(iVar2 + 0x10) = (local_20 - *(int *)(iVar2 + 0x18)) - *(int *)(iVar2 + 0x1c);
      }
      if ((*(byte *)(iVar2 + 4) & 2) != 0) {
        *(int *)(iVar2 + 0x14) = (local_2c - *(int *)(iVar2 + 0x20)) - *(int *)(iVar2 + 0x24);
      }
      if ((*(byte *)(iVar2 + 4) & 4) == 0) {
        iVar2 = *(int *)(iVar2 + 0x10) + *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x1c);
        local_28 = local_28 + iVar2;
        local_20 = local_20 - iVar2;
      }
      else {
        iVar2 = 0;
        local_28 = 0;
        iVar1 = iVar6;
        while (iVar1 = iVar1 + -1, -1 < iVar1) {
          if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(param_1[1] + iVar1 * 4);
          }
          if (*(int *)(iVar5 + 4) == 4) break;
          if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(param_1[1] + iVar1 * 4);
          }
          if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
            iVar3 = 0;
          }
          else {
            iVar3 = *(int *)(param_1[1] + iVar1 * 4);
          }
          if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(param_1[1] + iVar1 * 4);
          }
          if (iVar2 <= *(int *)(iVar4 + 0x24) + *(int *)(iVar3 + 0x20) + *(int *)(iVar5 + 0x14)) {
            if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
              iVar2 = 0;
            }
            else {
              iVar2 = *(int *)(param_1[1] + iVar1 * 4);
            }
            if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
              iVar5 = 0;
            }
            else {
              iVar5 = *(int *)(param_1[1] + iVar1 * 4);
            }
            if ((iVar1 < 0) || ((int)param_1[2] <= iVar1)) {
              iVar3 = 0;
            }
            else {
              iVar3 = *(int *)(param_1[1] + iVar1 * 4);
            }
            iVar2 = *(int *)(iVar3 + 0x24) + *(int *)(iVar5 + 0x20) + *(int *)(iVar2 + 0x14);
          }
        }
        local_24 = local_24 + iVar2;
        local_2c = local_2c - iVar2;
        local_20 = x2;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)param_1[2]);
  }
  hrgnSrc1 = CreateRectRgn(0,0,x2,local_18.x);
  hWinPosInfo = BeginDeferWindowPos(param_1[4] + param_1[2]);
  local_1c = 0;
  if (0 < (int)param_1[2]) {
    do {
      if ((local_1c < 0) || ((int)param_1[2] <= local_1c)) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = *(undefined4 **)(param_1[1] + local_1c * 4);
      }
      if (((HWND)*puVar7 != (HWND)0x0) &&
         (DeferWindowPos(hWinPosInfo,(HWND)*puVar7,(HWND)0x0,puVar7[2],puVar7[3],puVar7[4],puVar7[5]
                         ,4), puVar7[10] != 0)) {
        local_18.x = puVar7[2];
        local_18.y = puVar7[3];
        ScreenToClient((HWND)*param_1,&local_18);
        hrgnSrc2 = CreateRectRgn(local_18.x,local_18.y,puVar7[4],puVar7[5]);
        hrgnDst = CreateRectRgn(0,0,1,1);
        CombineRgn(hrgnDst,hrgnSrc1,(HRGN)0x0,5);
        CombineRgn(hrgnSrc1,hrgnDst,hrgnSrc2,4);
        DeleteObject(hrgnSrc2);
        DeleteObject(hrgnDst);
      }
      local_1c = local_1c + 1;
    } while (local_1c < (int)param_1[2]);
  }
  EndDeferWindowPos(hWinPosInfo);
  InvalidateRgn((HWND)*param_1,hrgnSrc1,1);
  DeleteObject(hrgnSrc1);
  return;
}
