
/* Library Function - Single Match
    __onexit_nolock
   
   Library: Visual Studio 2008 Release */

undefined4 __onexit_nolock(undefined4 param_1)

{
  undefined4 *_Memory;
  undefined4 *puVar1;
  size_t sVar2;
  size_t sVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  
  _Memory = (undefined4 *)__decode_pointer(DAT_1343a694);
  puVar1 = (undefined4 *)__decode_pointer(DAT_1343a690);
  if ((puVar1 < _Memory) || (iVar6 = (int)puVar1 - (int)_Memory, iVar6 + 4U < 4)) {
    return 0;
  }
  sVar2 = __msize(_Memory);
  if (sVar2 < iVar6 + 4U) {
    sVar3 = 0x800;
    if (sVar2 < 0x800) {
      sVar3 = sVar2;
    }
    if ((sVar3 + sVar2 < sVar2) ||
       (pvVar4 = __realloc_crt(_Memory,sVar3 + sVar2), pvVar4 == (void *)0x0)) {
      if (sVar2 + 0x10 < sVar2) {
        return 0;
      }
      pvVar4 = __realloc_crt(_Memory,sVar2 + 0x10);
      if (pvVar4 == (void *)0x0) {
        return 0;
      }
    }
    puVar1 = (undefined4 *)((int)pvVar4 + (iVar6 >> 2) * 4);
    DAT_1343a694 = __encode_pointer(pvVar4);
  }
  uVar5 = __encode_pointer(param_1);
  *puVar1 = uVar5;
  DAT_1343a690 = __encode_pointer(puVar1 + 1);
  return param_1;
}
