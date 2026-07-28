
void __thiscall FUN_10004bf0(void *this,HDC param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)((int)this + 8)) {
    do {
      if ((iVar2 < 0) || (*(int *)((int)this + 8) <= iVar2)) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = *(int **)(*(int *)((int)this + 4) + iVar2 * 4);
      }
      if (*piVar1 != 0) {
        ExcludeClipRect(param_1,piVar1[2],piVar1[3],piVar1[4] + piVar1[2],piVar1[5] + piVar1[3]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)((int)this + 8));
  }
  return;
}
