
/* Library Function - Single Match
    ___sbh_alloc_new_region
   
   Library: Visual Studio 2008 Release */

undefined4 * ___sbh_alloc_new_region(void)

{
  LPVOID pvVar1;
  undefined4 *puVar2;
  
  if (DAT_1343a668 == DAT_1343a678) {
    pvVar1 = HeapReAlloc(DAT_10038dac,0,DAT_1343a66c,(DAT_1343a678 + 0x10) * 0x14);
    if (pvVar1 == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    DAT_1343a678 = DAT_1343a678 + 0x10;
    DAT_1343a66c = pvVar1;
  }
  puVar2 = (undefined4 *)(DAT_1343a668 * 0x14 + (int)DAT_1343a66c);
  pvVar1 = HeapAlloc(DAT_10038dac,8,0x41c4);
  puVar2[4] = pvVar1;
  if (pvVar1 != (LPVOID)0x0) {
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    puVar2[3] = pvVar1;
    if (pvVar1 != (LPVOID)0x0) {
      puVar2[2] = 0xffffffff;
      *puVar2 = 0;
      puVar2[1] = 0;
      DAT_1343a668 = DAT_1343a668 + 1;
      *(undefined4 *)puVar2[4] = 0xffffffff;
      return puVar2;
    }
    HeapFree(DAT_10038dac,0,(LPVOID)puVar2[4]);
  }
  return (undefined4 *)0x0;
}
