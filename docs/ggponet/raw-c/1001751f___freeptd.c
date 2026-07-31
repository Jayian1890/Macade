
/* Library Function - Single Match
    __freeptd
   
   Library: Visual Studio 2008 Release */

void __cdecl __freeptd(_ptiddata _Ptd)

{
  LPVOID pvVar1;
  code *pcVar2;
  int iVar3;
  
  if (DAT_100377f0 != -1) {
    if ((_Ptd == (_ptiddata)0x0) && (pvVar1 = TlsGetValue(DAT_100377f4), pvVar1 != (LPVOID)0x0)) {
      iVar3 = DAT_100377f0;
      pcVar2 = TlsGetValue(DAT_100377f4);
      _Ptd = (_ptiddata)(*pcVar2)(iVar3);
    }
    pcVar2 = (code *)__decode_pointer(DAT_1003922c,DAT_100377f0,0);
    (*pcVar2)();
    __freefls_4(_Ptd);
  }
  if (DAT_100377f4 != 0xffffffff) {
    TlsSetValue(DAT_100377f4,(LPVOID)0x0);
  }
  return;
}
