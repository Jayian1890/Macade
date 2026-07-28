
void FUN_100273b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2a0) != 0) {
    _fprintf(*(FILE **)(in_ECX + 0x2a0),"Closing log file.\n");
    _fclose(*(FILE **)(in_ECX + 0x2a0));
    *(undefined4 *)(in_ECX + 0x2a0) = 0;
  }
  return;
}
