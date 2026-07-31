
/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 2008 Release */

int __cdecl __heap_init(void)

{
  int in_stack_00000004;
  
  DAT_10038dac = HeapCreate((uint)(in_stack_00000004 == 0),0x1000,0);
  if (DAT_10038dac == (HANDLE)0x0) {
    return 0;
  }
  DAT_1343a680 = 1;
  return 1;
}
