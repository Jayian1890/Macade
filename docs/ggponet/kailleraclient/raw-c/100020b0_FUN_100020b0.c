
undefined4 * __thiscall FUN_100020b0(void *this,byte param_1)

{
  FUN_100020d0(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
