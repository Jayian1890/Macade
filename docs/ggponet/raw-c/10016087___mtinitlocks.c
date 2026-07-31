
/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 2008 Release */

int __cdecl __mtinitlocks(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar3 = &DAT_10038db0;
  do {
    if ((&DAT_1003761c)[iVar2 * 2] == 1) {
      (&DAT_10037618)[iVar2 * 2] = puVar3;
      puVar3 = puVar3 + 0x18;
      iVar1 = ___crtInitCritSecAndSpinCount((&DAT_10037618)[iVar2 * 2],4000);
      if (iVar1 == 0) {
        (&DAT_10037618)[iVar2 * 2] = 0;
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x24);
  return 1;
}
