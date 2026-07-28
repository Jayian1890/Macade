
undefined4 * __thiscall FUN_10009c40(void *this,byte param_1)

{
  if (*(void **)this != (void *)0x0) {
    free(*(void **)this);
  }
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
