
void FUN_10025320(void)

{
  char cVar1;
  
  FUN_10021ff0("Flushing...");
  while( true ) {
    cVar1 = FUN_10004a00();
    if (cVar1 != '\0') break;
    FUN_10026830();
    Sleep(10);
    FUN_10021ff0(&DAT_10032890);
  }
  FUN_10026480();
  return;
}
