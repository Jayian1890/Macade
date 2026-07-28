
void __thiscall FUN_100099f0(void *this,undefined4 param_1)

{
  void *pvVar1;
  
  if ((*(void **)this == (void *)0x0) || ((*(byte *)((int)this + 4) & 0x1f) == 0)) {
    pvVar1 = realloc(*(void **)this,*(int *)((int)this + 4) * 4 + 0x80);
    *(void **)this = pvVar1;
  }
  *(undefined4 *)(*(int *)this + *(int *)((int)this + 4) * 4) = param_1;
  *(int *)((int)this + 4) = *(int *)((int)this + 4) + 1;
  return;
}
