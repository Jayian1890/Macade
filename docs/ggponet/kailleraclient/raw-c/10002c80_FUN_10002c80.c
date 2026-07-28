
void __thiscall FUN_10002c80(void *this,int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_314 [62];
  undefined1 auStack_21c [20];
  undefined4 local_208;
  int local_204;
  undefined1 auStack_120 [28];
  undefined4 local_104;
  int local_100;
  
  if (param_1 < 0) {
    param_1 = *(int *)((int)this + 0x14);
  }
  if (param_2 < 0) {
    param_2 = *(int *)((int)this + 0x10);
  }
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  local_314[0] = param_2;
  switch(*(undefined4 *)((int)this + 0x140)) {
  case 2:
    if (*(int *)((int)this + 0x2c) != -1) {
LAB_10002d16:
      iVar2 = Ordinal_4(*(undefined4 *)this,(int)this + 0x28,0x10);
      if (iVar2 == 0) {
        *(undefined4 *)((int)this + 0x140) = 4;
        return;
      }
      iVar2 = Ordinal_111();
      if (iVar2 != 0x2733) {
        *(char **)((int)this + 0x144) = s_connecting_to_host_1000e0e0;
        *(undefined4 *)((int)this + 0x140) = 0;
        return;
      }
      *(undefined4 *)((int)this + 0x140) = 3;
      return;
    }
    if (*(void **)((int)this + 0x138) != (void *)0x0) {
      iVar2 = FUN_10002860(*(void **)((int)this + 0x138),(int *)((int)this + 0x38));
      if (iVar2 == 0) {
        *(undefined4 *)((int)this + 0x140) = 3;
        goto LAB_10002d16;
      }
      if (iVar2 == 1) {
        *(undefined4 *)((int)this + 0x140) = 2;
        return;
      }
    }
    *(char **)((int)this + 0x144) = s_resolving_hostname_1000e0f4;
    *(undefined4 *)((int)this + 0x140) = 0;
    return;
  case 3:
    local_314[3] = *(int *)this;
    local_314[0] = 0;
    local_314[2] = 1;
    local_208 = 1;
    local_104 = 1;
    local_314[1] = 0;
    local_204 = local_314[3];
    local_100 = local_314[3];
    iVar2 = Ordinal_18(local_314[3] + 1,local_314 + 2,&local_208,&local_104,local_314);
    if (iVar2 == -1) {
      *(char **)((int)this + 0x144) = s_connecting_to_host__calling_sele_1000e0b8;
      *(undefined4 *)((int)this + 0x140) = 0;
      return;
    }
    iVar2 = Ordinal_151(*(undefined4 *)this,auStack_21c);
    if (iVar2 != 0) {
      *(undefined4 *)((int)this + 0x140) = 4;
      return;
    }
    iVar2 = Ordinal_151(*(undefined4 *)this,auStack_120);
    if (iVar2 != 0) {
      *(char **)((int)this + 0x144) = s_connecting_to_host_1000e0e0;
      *(undefined4 *)((int)this + 0x140) = 0;
      return;
    }
    break;
  case 4:
  case 5:
    iVar2 = *(int *)((int)this + 0x24);
    if ((0 < iVar2) && (0 < param_1)) {
      iVar1 = *(int *)((int)this + 0x14) - *(int *)((int)this + 0x20);
      if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      if (param_1 < iVar1) {
        iVar1 = param_1;
      }
      if (0 < iVar1) {
        iVar2 = Ordinal_19(*(undefined4 *)this,
                           *(int *)((int)this + 0xc) + *(int *)((int)this + 0x20),iVar1,0);
        if (iVar2 == -1) {
          Ordinal_111();
        }
        else if (0 < iVar2) {
          param_1 = param_1 - iVar2;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + iVar2;
          }
          *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + iVar2;
          *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) - iVar2;
        }
      }
      iVar2 = *(int *)((int)this + 0x14);
      if (iVar2 <= *(int *)((int)this + 0x20)) {
        iVar1 = *(int *)((int)this + 0x24);
        *(undefined4 *)((int)this + 0x20) = 0;
        if (0 < iVar1) {
          if (iVar1 < iVar2) {
            iVar2 = iVar1;
          }
          if (param_1 < iVar2) {
            iVar2 = param_1;
          }
          iVar2 = Ordinal_19(*(undefined4 *)this,*(undefined4 *)((int)this + 0xc),iVar2,0);
          if (iVar2 == -1) {
            Ordinal_111();
          }
          else if (0 < iVar2) {
            if (param_3 != (int *)0x0) {
              *param_3 = *param_3 + iVar2;
            }
            *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + iVar2;
            *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) - iVar2;
          }
        }
      }
    }
    iVar1 = local_314[0];
    iVar2 = *(int *)((int)this + 0x10);
    if (*(int *)((int)this + 0x1c) < iVar2) {
      iVar3 = iVar2 - *(int *)((int)this + 0x18);
      iVar2 = iVar2 - *(int *)((int)this + 0x1c);
      if (iVar2 < iVar3) {
        iVar3 = iVar2;
      }
      if (local_314[0] < iVar3) {
        iVar3 = local_314[0];
      }
      if (iVar3 < 1) {
LAB_10002fe0:
        iVar2 = *(int *)((int)this + 0x10);
        if (iVar2 <= *(int *)((int)this + 0x18)) {
          *(undefined4 *)((int)this + 0x18) = 0;
          if (*(int *)((int)this + 0x1c) < iVar2) {
            iVar2 = iVar2 - *(int *)((int)this + 0x1c);
            if (iVar1 < iVar2) {
              iVar2 = iVar1;
            }
            if (0 < iVar2) {
              iVar2 = Ordinal_16(*(undefined4 *)this,*(undefined4 *)((int)this + 8),iVar2,0);
              if ((iVar2 == 0) || ((iVar2 < 0 && (iVar1 = Ordinal_111(), iVar1 != 0x2733))))
              goto LAB_10003051;
              if (0 < iVar2) {
                if (param_4 != (int *)0x0) {
                  *param_4 = *param_4 + iVar2;
                }
                *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + iVar2;
                *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + iVar2;
              }
            }
          }
        }
        goto LAB_10003042;
      }
      iVar2 = Ordinal_16(*(undefined4 *)this,*(int *)((int)this + 8) + *(int *)((int)this + 0x18),
                         iVar3,0);
      if ((iVar2 != 0) && ((-1 < iVar2 || (iVar3 = Ordinal_111(), iVar3 == 0x2733)))) {
        if (0 < iVar2) {
          iVar1 = iVar1 - iVar2;
          if (param_4 != (int *)0x0) {
            *param_4 = *param_4 + iVar2;
          }
          *(int *)((int)this + 0x18) = *(int *)((int)this + 0x18) + iVar2;
          *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + iVar2;
        }
        goto LAB_10002fe0;
      }
    }
    else {
LAB_10003042:
      if (*(int *)((int)this + 0x140) != 5) {
        return;
      }
      if (0 < *(int *)((int)this + 0x24)) {
        return;
      }
    }
LAB_10003051:
    *(undefined4 *)((int)this + 0x140) = 6;
  }
  return;
}
