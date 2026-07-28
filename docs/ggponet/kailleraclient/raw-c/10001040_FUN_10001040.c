
undefined4 * __thiscall FUN_10001040(void *this,byte param_1)

{
  FUN_10001060(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
