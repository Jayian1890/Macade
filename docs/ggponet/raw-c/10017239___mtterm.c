
/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 2008 Release */

void __cdecl __mtterm(void)

{
  code *pcVar1;
  
  if (DAT_100377f0 != -1) {
    pcVar1 = (code *)__decode_pointer(DAT_10039230,DAT_100377f0);
    (*pcVar1)();
    DAT_100377f0 = -1;
  }
  if (DAT_100377f4 != 0xffffffff) {
    TlsFree(DAT_100377f4);
    DAT_100377f4 = 0xffffffff;
  }
  __mtdeletelocks();
  return;
}
