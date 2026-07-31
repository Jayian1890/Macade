
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _puts
   
   Library: Visual Studio 2008 Release */

int __cdecl _puts(char *_Str)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  size_t _Count;
  int iVar4;
  size_t sVar5;
  undefined *puVar6;
  int local_20;
  
  local_20 = -1;
  if (_Str != (char *)0x0) {
    iVar2 = FUN_10017d4f();
    if ((*(byte *)(iVar2 + 0x2c) & 0x40) != 0) {
LAB_10012357:
      iVar2 = FUN_10017d4f();
      __lock_file2(1,(void *)(iVar2 + 0x20));
      iVar2 = FUN_10017d4f();
      iVar2 = __stbuf((FILE *)(iVar2 + 0x20));
      _Count = _strlen(_Str);
      iVar4 = FUN_10017d4f();
      sVar5 = __fwrite_nolock(_Str,1,_Count,(FILE *)(iVar4 + 0x20));
      if (sVar5 == _Count) {
        iVar4 = FUN_10017d4f();
        piVar1 = (int *)(iVar4 + 0x24);
        *piVar1 = *piVar1 + -1;
        if (*piVar1 < 0) {
          iVar4 = FUN_10017d4f();
          __flsbuf(10,(FILE *)(iVar4 + 0x20));
        }
        else {
          iVar4 = FUN_10017d4f();
          piVar1 = (int *)(iVar4 + 0x20);
          *(undefined1 *)*piVar1 = 10;
          *piVar1 = *piVar1 + 1;
        }
        local_20 = 0;
      }
      iVar4 = FUN_10017d4f();
      __ftbuf(iVar2,(FILE *)(iVar4 + 0x20));
      FUN_100123f9();
      return local_20;
    }
    uVar3 = __fileno((FILE *)(iVar2 + 0x20));
    if ((uVar3 == 0xffffffff) || (uVar3 == 0xfffffffe)) {
      puVar6 = &DAT_10037b80;
    }
    else {
      puVar6 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar3 >> 5]);
    }
    if ((puVar6[0x24] & 0x7f) == 0) {
      if ((uVar3 == 0xffffffff) || (uVar3 == 0xfffffffe)) {
        puVar6 = &DAT_10037b80;
      }
      else {
        puVar6 = (undefined *)((uVar3 & 0x1f) * 0x40 + (&DAT_13439540)[(int)uVar3 >> 5]);
      }
      if ((puVar6[0x24] & 0x80) == 0) goto LAB_10012357;
    }
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  __invalid_parameter(0,0,0,0,0);
  return -1;
}
