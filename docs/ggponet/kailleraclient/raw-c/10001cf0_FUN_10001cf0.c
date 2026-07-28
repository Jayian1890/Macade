
void __thiscall FUN_10001cf0(void *this,int param_1)

{
  size_t _NewSize;
  void *pvVar1;
  
  _NewSize = *(size_t *)((int)this + 0x28);
  if ((int)_NewSize < param_1) {
    do {
      _NewSize = _NewSize * 2;
    } while ((int)_NewSize < param_1);
    *(size_t *)((int)this + 0x28) = _NewSize;
    pvVar1 = realloc(*(void **)((int)this + 0x24),_NewSize);
    *(void **)((int)this + 0x24) = pvVar1;
  }
  return;
}
