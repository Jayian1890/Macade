
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x1001269d) */
/* Library Function - Single Match
    _doexit
   
   Library: Visual Studio 2008 Release */

void __cdecl doexit(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  int *local_2c;
  int *local_24;
  int *local_20;
  
  __lock(8);
  if (DAT_10038a6c != 1) {
    DAT_10038a68 = 1;
    DAT_10038a64 = (undefined1)param_3;
    if (param_2 == 0) {
      piVar1 = (int *)__decode_pointer(DAT_1343a694);
      if (piVar1 != (int *)0x0) {
        piVar2 = (int *)__decode_pointer(DAT_1343a690);
        local_2c = piVar1;
        local_24 = piVar2;
        local_20 = piVar1;
        while (piVar2 = piVar2 + -1, piVar1 <= piVar2) {
          iVar3 = __encoded_null();
          if (*piVar2 != iVar3) {
            if (piVar2 < piVar1) break;
            pcVar4 = (code *)__decode_pointer(*piVar2);
            iVar3 = __encoded_null();
            *piVar2 = iVar3;
            (*pcVar4)();
            piVar5 = (int *)__decode_pointer(DAT_1343a694);
            piVar6 = (int *)__decode_pointer(DAT_1343a690);
            if ((local_20 != piVar5) || (piVar1 = local_2c, local_24 != piVar6)) {
              piVar2 = piVar6;
              piVar1 = piVar5;
              local_2c = piVar5;
              local_24 = piVar6;
              local_20 = piVar5;
            }
          }
        }
      }
      __initterm(&DAT_1002e1d4);
    }
    __initterm(&DAT_1002e1dc);
  }
  FUN_10012697();
  if (param_3 == 0) {
    DAT_10038a6c = 1;
    FUN_10016129(8);
    ___crtExitProcess(param_1);
    return;
  }
  return;
}
