
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _V6_HeapAlloc
   
   Library: Visual Studio 2008 Release */

undefined4 _V6_HeapAlloc(uint param_1)

{
  undefined4 local_20;
  
  local_20 = 0;
  if (param_1 <= DAT_1343a670) {
    __lock(4);
    local_20 = ___sbh_alloc_block(param_1);
    FUN_10011315();
  }
  return local_20;
}
