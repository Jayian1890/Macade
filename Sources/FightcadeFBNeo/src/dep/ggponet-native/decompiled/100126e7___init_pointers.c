
/* Library Function - Single Match
    __init_pointers
   
   Library: Visual Studio 2008 Release */

void __cdecl __init_pointers(void)

{
  undefined4 uVar1;
  
  uVar1 = __encoded_null();
  FUN_100170d0(uVar1);
  FUN_100198e4(uVar1);
  FUN_10011578(uVar1);
  FUN_10017ae6(uVar1);
  FUN_100198d5(uVar1);
  __initp_misc_winsig(uVar1);
  FUN_10019542(uVar1);
  __initp_eh_hooks(uVar1);
  PTR___exit_10037480 = (undefined *)__encode_pointer(__exit);
  return;
}
