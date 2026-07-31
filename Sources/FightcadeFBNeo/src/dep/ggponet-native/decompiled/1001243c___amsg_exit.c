
/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2008 Release */

void __cdecl __amsg_exit(int param_1)

{
  code *pcVar1;
  
  __FF_MSGBANNER();
  __NMSG_WRITE(param_1);
  pcVar1 = (code *)__decode_pointer(PTR___exit_10037480);
  (*pcVar1)(0xff);
  return;
}
