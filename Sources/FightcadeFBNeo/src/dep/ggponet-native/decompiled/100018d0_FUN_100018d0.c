
void FUN_100018d0(char param_1,uint param_2)

{
  char *pcVar1;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *in_ECX;
  
  if ((param_1 != '\0') && (0xf < *(uint *)(in_ECX + 0x18))) {
    pcVar1 = *(char **)(in_ECX + 4);
    if (param_2 != 0) {
      std::_Traits_helper::copy_s<std::char_traits<char>_>((char *)(in_ECX + 4),0x10,pcVar1,param_2)
      ;
    }
    FUN_100033b0(pcVar1,*(int *)(in_ECX + 0x18) + 1);
  }
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::_Eos
            (in_ECX,param_2);
  return;
}
