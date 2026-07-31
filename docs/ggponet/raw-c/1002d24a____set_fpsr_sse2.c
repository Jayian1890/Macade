
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___set_fpsr_sse2
   
   Library: Visual Studio 2008 Release */

void ___set_fpsr_sse2(uint param_1)

{
  if (DAT_1343a684 != 0) {
    if (((param_1 & 0x40) == 0) || (DAT_10038a14 == 0)) {
      MXCSR = param_1 & 0xffffffbf;
    }
    else {
      MXCSR = param_1;
    }
  }
  return;
}
