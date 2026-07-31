
/* Library Function - Single Match
    _isdigit
   
   Library: Visual Studio 2008 Release */

int __cdecl _isdigit(int _C)

{
  int iVar1;
  
  if (DAT_100393a0 == 0) {
    return *(ushort *)(PTR_DAT_10038218 + _C * 2) & 4;
  }
  iVar1 = __isdigit_l(_C,(_locale_t)0x0);
  return iVar1;
}
