
void __thiscall FUN_10001d30(void *this,char *param_1)

{
  char cVar1;
  uint uVar2;
  size_t _Count;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (~uVar2 - 1 < 0x1f) {
    uVar2 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    _Count = ~uVar2 - 1;
  }
  else {
    _Count = 0x1f;
  }
  strncpy((char *)((int)this + 4),param_1,_Count);
  *(undefined1 *)(_Count + 4 + (int)this) = 0;
  return;
}
