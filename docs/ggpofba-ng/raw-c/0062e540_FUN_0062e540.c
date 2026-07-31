
void FUN_0062e540(void)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = DAT_00b1a9bc;
  if (DAT_00b1a9bc == (char *)0x0) {
    pcVar2 = "* Unknown *";
  }
  pcVar1 = DAT_00b1a9b8;
  if (DAT_00b1a9b8 == (char *)0x0) {
    pcVar1 = "* Unknown *";
  }
  _sprintf(&DAT_00b1aed0,"%s | %s",pcVar1,pcVar2);
  pcVar2 = DAT_00b1a9c8;
  if (DAT_00b1a9c8 == (char *)0x0) {
    pcVar2 = "* Unknown *";
  }
  pcVar1 = DAT_00b1a9c4;
  if (DAT_00b1a9c4 == (char *)0x0) {
    pcVar1 = "* Unknown *";
  }
  _sprintf(&DAT_00b1add0,"%s | %s",pcVar1,pcVar2);
  ggpo_client_set_game_event();
  ggpo_client_set_game_event();
  ggpo_client_set_game_event();
  ggpo_client_set_game_event();
  ggpo_client_set_game_event();
  ggpo_client_set_game_event();
  return;
}
