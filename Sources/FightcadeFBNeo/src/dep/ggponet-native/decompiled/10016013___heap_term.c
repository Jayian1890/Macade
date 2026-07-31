
/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 2008 Release */

void __cdecl __heap_term(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_1343a680 == 3) {
    iVar1 = 0;
    if (0 < DAT_1343a668) {
      puVar2 = (undefined4 *)((int)DAT_1343a66c + 0x10);
      do {
        VirtualFree((LPVOID)puVar2[-1],0,0x8000);
        HeapFree(DAT_10038dac,0,(LPVOID)*puVar2);
        puVar2 = puVar2 + 5;
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_1343a668);
    }
    HeapFree(DAT_10038dac,0,DAT_1343a66c);
  }
  HeapDestroy(DAT_10038dac);
  DAT_10038dac = (HANDLE)0x0;
  return;
}
