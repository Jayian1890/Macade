
void __thiscall FUN_10002b50(void *this,undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  char *_Source;
  
  FUN_10003080(this,1);
  _Source = (char *)0x1;
  *(short *)((int)this + 4) = (short)param_2;
  iVar2 = Ordinal_23(2,1,0);
  *(int *)this = iVar2;
  if (iVar2 == -1) {
    *(char **)((int)this + 0x144) = s_creating_socket_1000e0a8;
    *(undefined4 *)((int)this + 0x140) = 0;
    return;
  }
  Ordinal_10(iVar2,0x8004667e,&stack0xfffffffc);
  strncpy((char *)((int)this + 0x38),_Source,0xff);
  *(undefined1 *)((int)this + 0x137) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  if (*(char *)((int)this + 0x38) == '\0') {
    *(char **)((int)this + 0x144) = s_empty_hostname_1000e098;
    *(undefined4 *)((int)this + 0x140) = 0;
    return;
  }
  *(undefined4 *)((int)this + 0x140) = 2;
  *(undefined2 *)((int)this + 0x28) = 2;
  uVar1 = Ordinal_9(param_2);
  *(undefined2 *)((int)this + 0x2a) = uVar1;
  uVar3 = Ordinal_11(_Source);
  *(undefined4 *)((int)this + 0x2c) = uVar3;
  return;
}
