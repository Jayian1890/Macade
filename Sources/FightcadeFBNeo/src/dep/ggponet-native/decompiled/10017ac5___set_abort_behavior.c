
/* Library Function - Single Match
    __set_abort_behavior
   
   Library: Visual Studio 2008 Release */

uint __cdecl __set_abort_behavior(uint _Flags,uint _Mask)

{
  uint uVar1;
  
  uVar1 = DAT_100377fc;
  DAT_100377fc = ~_Mask & DAT_100377fc | _Flags & _Mask;
  return uVar1;
}
