
/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2008 Release */

void * __cdecl _malloc(size_t _Size)

{
  LPVOID pvVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint dwBytes;
  
  if (_Size < 0xffffffe1) {
    do {
      if (DAT_10038dac == (HANDLE)0x0) {
        __FF_MSGBANNER();
        __NMSG_WRITE(0x1e);
        ___crtExitProcess(0xff);
      }
      if (DAT_1343a680 == 1) {
        dwBytes = _Size;
        if (_Size == 0) {
          dwBytes = 1;
        }
LAB_1001138d:
        pvVar1 = HeapAlloc(DAT_10038dac,0,dwBytes);
      }
      else if ((DAT_1343a680 != 3) || (pvVar1 = (LPVOID)_V6_HeapAlloc(_Size), pvVar1 == (LPVOID)0x0)
              ) {
        sVar4 = _Size;
        if (_Size == 0) {
          sVar4 = 1;
        }
        dwBytes = sVar4 + 0xf & 0xfffffff0;
        goto LAB_1001138d;
      }
      if (pvVar1 != (LPVOID)0x0) {
        return pvVar1;
      }
      if (DAT_10039220 == 0) {
        piVar3 = __errno();
        *piVar3 = 0xc;
        break;
      }
      iVar2 = __callnewh(_Size);
    } while (iVar2 != 0);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  else {
    __callnewh(_Size);
    piVar3 = __errno();
    *piVar3 = 0xc;
  }
  return (void *)0x0;
}
