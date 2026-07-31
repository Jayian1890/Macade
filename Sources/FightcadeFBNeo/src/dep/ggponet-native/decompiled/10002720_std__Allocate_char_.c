
/* Library Function - Single Match
    char * __cdecl std::_Allocate<char>(unsigned int,char *)
   
   Libraries: Visual Studio 2005 Debug, Visual Studio 2008 Debug */

char * __cdecl std::_Allocate<char>(uint param_1,char *param_2)

{
  char *pcVar1;
  bad_alloc local_10 [12];
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if ((int)(0xffffffff / (ulonglong)param_1) == 0) {
    bad_alloc::bad_alloc(local_10,(char *)0x0);
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_10,&DAT_10034374);
  }
  pcVar1 = (char *)FUN_100118ec(param_1);
  return pcVar1;
}
