
void __cdecl FUN_1000c78f(_onexit_t param_1)

{
  if (DAT_1000f450 == -1) {
    _onexit(param_1);
    return;
  }
  __dllonexit(param_1,&DAT_1000f450,&DAT_1000f44c);
  return;
}
